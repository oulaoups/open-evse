

// -*- C++ -*-
/*
 * Open EVSE Firmware
 *
 * Copyright (c) 2011-2012 Sam C. Lin <lincomatic@gmail.com> and Chris Howell
 * Maintainers: SCL/CH

 * This file is part of Open EVSE.

 * Open EVSE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.

 * Open EVSE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Open EVSE; see the file COPYING.  If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#include <EEPROM.h>
#include <avr/wdt.h>
#include <pins_arduino.h>
#include <Wire.h>
#include <Time.h>
#if defined(ARDUINO) && (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h" // shouldn't need this but arduino sometimes messes up and puts inside an #ifdef
#endif // ARDUINO

#define VERSTR "0.5.1"

//-- begin features

//#define SERDBG // debugging states via serial
//#define WATCHDOG // enable watchdog timer
#define GFI
//#define GFI_TESTING // for stability testing - shorter timeout/higher retry count
//#define SERIALCLI // serial port command line
//#define RGBLCD //Adafruit RGBLCD
//#define I2CLCD // Adafruit LCD backpack in I2C mode
#define ADVPWR // Advanced Powersupply... Ground check, stuck relay, L1/L2 detection.
//Networking -- Enable one or none, never both
//#define WIFI //Enable Arduino wifi shield
#define ETHERNET //Enable Arduino W5100 ethernet shield
//-- end features

#if defined(RGBLCD) || defined(I2CLCD)
#define LCD16X2
#endif // RGBLCD || I2CLCD

//-- begin Networking config
#if defined(WIFI) && defined(ETHERNET)
#error Both networking options are enabled, please select one or none.
#endif

#if defined(WIFI) || defined(ETHERNET)
#include <SPI.h>
#endif

#if defined(WIFI)
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#endif

#if defined(ETHERNET)
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <UdpBytewise.h>
#include <UdpRaw.h>
#include <UdpString.h>
#include <util.h>
#endif
//-- begin configuration

#define DEFAULT_SERVICE_LEVEL 2 // 1=L1, 2=L2

// current capacity in amps
#define DEFAULT_CURRENT_CAPACITY_L1 12
#define DEFAULT_CURRENT_CAPACITY_L2 20

// minimum allowable current in amps
#define MIN_CURRENT_CAPACITY 6

// maximum allowable current in amps
#define MAX_CURRENT_CAPACITY_L1 20
#define MAX_CURRENT_CAPACITY_L2 32

//J1772EVSEController
#define CURRENT_PIN A0 // analog current reading pin
#define VOLT_PIN A1 // analog voltage reading pin
#define ACLINE1_PIN 3 // TEST PIN 1 for L1/L2, ground and stuck relay
#define ACLINE2_PIN 4 // TEST PIN 2 for L1/L2, ground and stuck relay
#define RED_LED_PIN 5 // Digital pin
#define CHARGING_PIN 8 // digital Charging LED and Relay Trigger pin
#define PILOT_PIN 10 // n.b. PILOT_PIN *MUST* be digial 10 because initWave() assumes it
#define GREEN_LED_PIN 2 // Digital pin

#define SERIAL_BAUD 38400

// EEPROM offsets for settings
#define EOFS_CURRENT_CAPACITY_L1 0 // 1 byte
#define EOFS_CURRENT_CAPACITY_L2 1 // 1 byte

// must stay within thresh for this time in ms before switching states
#define DELAY_STATE_TRANSITION 250
// must transition to state A from contacts closed in < 100ms according to spec
// but Leaf sometimes bounces from 3->1 so we will debounce it a little anyway
#define DELAY_STATE_TRANSITION_A 25

#ifdef GFI
#define GFI_INTERRUPT 0 // interrupt number 0 = D2, 1 = D3

#ifdef GFI_TESTING
#define GFI_TIMEOUT ((unsigned long)(15*1000))
#define GFI_RETRY_COUNT  255
#else // !GFI_TESTING
#define GFI_TIMEOUT ((unsigned long)(15*60000)) // 15*16*1000 doesn't work. go figure
#define GFI_RETRY_COUNT  3
#endif // GFI_TESTING
#endif // GFI

#ifdef RGBLCD //Adafruit RGB LCD
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define BLUE 0x6
#endif //Adafruit RGB LCD

#ifdef I2CLCD
#include <LiquidTWI.h>
#define LCD_I2C_ADDR 0 // for adafruit LCD backpack
#endif // I2CLCD

//-- end configuration

//-- begin class definitions

#ifdef SERIALCLI
#define CLI_BUFLEN 13
class CLI {
  int m_CLIinByte; // CLI byte being read in
  char m_CLIinstr[CLI_BUFLEN]; // CLI byte being read in
  int m_CLIstrCount; //CLI string counter

public:
  CLI();
  void Init();
  void println(char *s) { 
    Serial.println(s); 
  }
  void print(char *s) { 
    Serial.print(s); 
  }
  void flush() { 
    Serial.flush(); 
  }
  void getInput();
  uint8_t getInt();
};
#endif // SERIALCLI

class OnboardDisplay {
public:
  OnboardDisplay() {} 
  void Init();
  void SetGreenLed(uint8_t state);
  void SetRedLed(uint8_t state);
  void Update();
};

#ifdef GFI
class Gfi {
 uint8_t m_GfiFault;
public:
  Gfi() {}
  void Init();
  void Reset();
  void SetFault() { m_GfiFault = 1; }
  uint8_t Fault() { return m_GfiFault; }
  
};
#endif // GFI


typedef enum {
  PILOT_STATE_P12,PILOT_STATE_PWM,PILOT_STATE_N12} 
PILOT_STATE;
class J1772Pilot {
  uint8_t m_bit;
  uint8_t m_port;
  PILOT_STATE m_State;
public:
  J1772Pilot() {
  }
  void Init();
  void SetState(PILOT_STATE pstate); // P12/N12
  PILOT_STATE GetState() { 
    return m_State; 
  }
  int SetPWM(int amps); // 12V 1KHz PWM
};

// EVSE states for m_EvseState
#define EVSE_STATE_UNKNOWN 0x00
#define EVSE_STATE_A       0x01 // vehicle state A 12V - not connected
#define EVSE_STATE_B       0x02 // vehicle state B 9V - connected, ready
#define EVSE_STATE_C       0x03 // vehicle state C 6V - charging
#define EVSE_STATE_D       0x04 // vehicle state D 3V - vent required
#define EVSE_STATE_DIODE_CHK_FAILED 0x05 // diode check failed
#define EVSE_STATE_GFCI_FAULT 0x06       // GFCI fault
#define EVSE_STATE_NO_GROUND 0x07 //bad ground
#define EVSE_STATE_STUCK_RELAY 0x08 //stuck relay

typedef struct threshdata {
  uint16_t m_ThreshAB; // state A -> B
  uint16_t m_ThreshBC; // state B -> C
  uint16_t m_ThreshCD; // state C -> D
  uint16_t m_ThreshD;  // state D
  uint16_t m_ThreshDS; // diode short
} THRESH_DATA,*PTHRESH_DATA;

typedef struct calibdata {
  uint16_t m_pMax;
  uint16_t m_pAvg;
  uint16_t m_pMin;
  uint16_t m_nMax;
  uint16_t m_nAvg;
  uint16_t m_nMin;
} CALIB_DATA,*PCALIB_DATA;



// J1772EVSEController m_wFlags bits
#define ECF_L2                 0x01 // service level 2
#define ECF_CHARGING_ON        0x02 // charging relay is closed
#define ECF_GFI_TRIPPED        0x80 // gfi has tripped at least once
class J1772EVSEController {
  J1772Pilot m_Pilot;
#ifdef GFI
  Gfi m_Gfi;
  unsigned long m_GfiTimeout;
  unsigned long m_GfiRetryCnt;
  uint8_t m_GfiTripCnt;
#endif // GFI
  uint8_t m_bFlags; // ECF_xxx
  THRESH_DATA m_ThreshData;
  uint8_t m_EvseState;
  uint8_t m_PrevEvseState;
  uint8_t m_TmpEvseState;
  unsigned long m_TmpEvseStateStart;
  uint8_t m_CurrentCapacity; // max amps we can output
  time_t m_ChargeStartTime;
  time_t m_ElapsedChargeTime;
  time_t m_ElapsedChargeTimePrev;

  void chargingOn() {  // turn on charging current
    digitalWrite(CHARGING_PIN,HIGH); 
    m_bFlags |= ECF_CHARGING_ON;
  }
  void chargingOff() { // turn off charging current
    digitalWrite(CHARGING_PIN,LOW); 
    m_bFlags &= ~ECF_CHARGING_ON;
  } 
  uint8_t chargingIsOn() { return m_bFlags & ECF_CHARGING_ON; }
  void setFlags(uint8_t flags) { 
    m_bFlags |= flags; 
  }
  void clrFlags(uint8_t flags) { 
    m_bFlags &= ~flags; 
  }

public:
  J1772EVSEController() {
  }
  void Init(char svclvl);
  void Update(); // read sensors
  void LoadThresholds();

  uint8_t GetState() { 
    return m_EvseState; 
  }
  uint8_t GetPrevState() { 
    return m_PrevEvseState; 
  }
  int StateTransition() { 
    return (m_EvseState != m_PrevEvseState) ? 1 : 0; 
  }
  uint8_t GetCurrentCapacity() { 
    return m_CurrentCapacity; 
  }
  int SetCurrentCapacity(uint8_t amps,uint8_t updatepwm=0);
  //int GetCurrentReading() { return m_CurrentReading; }
  //float GetCurrentAmps();
  time_t GetElapsedChargeTime() { 
    return m_ElapsedChargeTime; 
  }
  time_t GetElapsedChargeTimePrev() { 
    return m_ElapsedChargeTimePrev; 
  }
  void Calibrate(PCALIB_DATA pcd);
  uint8_t GetCurLevel() { 
    return (m_bFlags & ECF_L2) ? 2 : 1; 
  }
  PTHRESH_DATA GetThreshData() { 
    return &m_ThreshData; 
  }
#ifdef GFI
  void SetGfiTripped();
  uint8_t GfiTripped() { return m_bFlags & ECF_GFI_TRIPPED; }
#endif // GFI
};

// -- end class definitions
//-- begin global variables

THRESH_DATA g_DefaultThreshData = {875,780,690,0,260};
J1772EVSEController g_EvseController;
OnboardDisplay g_OBD;

#ifdef SERIALCLI
CLI g_CLI;
#endif // SERIALCLI

#ifdef RGBLCD //Adafruit RGB LCD
Adafruit_RGBLCDShield g_Lcd;
#endif //Adafruit RGB LCD

#ifdef I2CLCD
LiquidTWI g_Lcd(LCD_I2C_ADDR); 
#endif // I2CLCD

//-- end global variables

#ifdef RGBLCD
#define lcdSetBacklightColor(c) g_Lcd.setBacklight(c)
#else
#define lcdSetBacklightColor(c)
#endif // RGBLCD

void EvseReset();

void SaveSettings()
{
  // n.b. should we add dirty bits so we only write the changed values? or should we just write them on the fly when necessary?
  EEPROM.write((g_EvseController.GetCurLevel() == 1) ? EOFS_CURRENT_CAPACITY_L1 : EOFS_CURRENT_CAPACITY_L2,(byte)g_EvseController.GetCurrentCapacity());
}

#ifdef SERIALCLI
CLI::CLI()
{
  m_CLIstrCount = 0; 
}

void CLI::Init()
{
  Serial.println("Open EVSE"); // CLI print prompt when serial is ready
  Serial.println("Hardware - Atmel ATMEGA328P-AU"); //CLI Info
  Serial.print("Software - Open EVSE "); //CLI info
  Serial.println(VERSTR);
  Serial.println("");

  g_CLI.println("type ? or help for command list");
  g_CLI.print("Open_EVSE>"); // CLI Prompt
  g_CLI.flush();

}

uint8_t CLI::getInt()
{
  uint8_t c;
  uint8_t num = 0;

  do {
    c = Serial.read(); // read the byte
    if ((c >= '0') && (c <= '9')) {
      num = (num * 10) + c - '0';
    }
  } while (c != 13);
  return num;
}

void CLI::getInput()
{
  int currentreading;
  uint8_t amp;
  if(Serial.available()) { // if byte(s) are available to be read
    m_CLIinByte = Serial.read(); // read the byte
    Serial.print(char(m_CLIinByte));
    if(m_CLIinByte != 13) {
      m_CLIinstr[m_CLIstrCount] = char(m_CLIinByte);
      m_CLIstrCount++;
    }

    if(m_CLIinByte == 13) { // if enter was pressed or max chars reached
      Serial.println(""); // print a newline
      if (strcmp(m_CLIinstr, "show") == 0){ //if match SHOW 

        Serial.println("Open EVSE"); // CLI print prompt when serial is ready
        Serial.println("Hardware - Atmel ATMEGA328P-AU"); //CLI Info
        Serial.print("Software - Open EVSE ");
	Serial.println(VERSTR);
        Serial.println("\nEVSE Settings");
        Serial.print("EVSE current capacity (Amps) = ");
        Serial.println((int)g_EvseController.GetCurrentCapacity()); 
        Serial.print("Min EVSE Current Capacity = ");
        Serial.println(MIN_CURRENT_CAPACITY);
        Serial.print("Max EVSE Current Capacity = ");
        Serial.println(MAX_CURRENT_CAPACITY_L2);
        char s[80];
        int i;
        sscanf(s,"%d",&i);
           
      } 
      else if ((strcmp(m_CLIinstr, "help") == 0) || (strcmp(m_CLIinstr, "?") == 0)){ // string compare
        Serial.println("Help Commands");
        Serial.println("");
        Serial.println("help  --   Display commands"); // print to the terminal
        Serial.println("set   --   Change Settings");
        Serial.println("show  --   Display settings and values");
        Serial.println("save  --   Write settings to EEPROM");
      } 
      else if (strcmp(m_CLIinstr, "set") == 0){ // string compare
        Serial.println("Set Commands - Usage: set amp");
        Serial.println("");
        Serial.println("amp  --  Set the EVSE Current Capacity"); // print to the terminal
       } 
      else if (strcmp(m_CLIinstr, "set amp") == 0){ // string compare
        Serial.println("WARNING - DO NOT SET CURRENT HIGHER THAN 80%");
	Serial.println("OF YOUR CIRCUIT BREAKER OR"); 
        Serial.println("GREATER THAN THE RATED VALUE OF THE EVSE");
        Serial.println("");
        Serial.print("Enter amps (");
        Serial.print(MIN_CURRENT_CAPACITY);
        Serial.print("-");
        Serial.print((g_EvseController.GetCurLevel()  == 1) ? MAX_CURRENT_CAPACITY_L1 : MAX_CURRENT_CAPACITY_L2);
	Serial.print("): ");
	amp = getInt();
	Serial.println((int)amp);
        if(g_EvseController.SetCurrentCapacity(amp,1)) {
	  Serial.println("Invalid Current Capacity");
	}

        Serial.print("\nEVSE Current Capacity now: "); // print to the terminal
        Serial.print((int)g_EvseController.GetCurrentCapacity());
        Serial.print(" Amps");
      } 
      else if (strcmp(m_CLIinstr, "save") == 0){ // string compare
        Serial.println("Saving Settings"); // print to the terminal
        SaveSettings();
      } 
      else { // if the input text doesn't match any defined above
        Serial.println("Unknown Command -- type ? or help for command list"); // echo back to the terminal
      } 
      Serial.println("");
      Serial.println("");
      Serial.print("Open_EVSE>");
      g_CLI.flush();
      m_CLIstrCount = 0; // get ready for new input... reset strCount
      m_CLIinByte = 0; // reset the inByte variable
      for(int i = 0; m_CLIinstr[i] != '\0'; i++) { // while the string does not have null
        m_CLIinstr[i] = '\0'; // fill it with null to erase it
      }
    }
  }
}

#endif // SERIALCLI



void OnboardDisplay::Init()
{
  pinMode (GREEN_LED_PIN, OUTPUT);
  pinMode (RED_LED_PIN, OUTPUT);

  g_OBD.SetGreenLed(LOW);
  g_OBD.SetRedLed(LOW);
}


void OnboardDisplay::SetGreenLed(uint8_t state)
{
  digitalWrite(GREEN_LED_PIN,state);
}

void OnboardDisplay::SetRedLed(uint8_t state)
{
  digitalWrite(RED_LED_PIN,state);
}

void OnboardDisplay::Update()
{
  uint8_t curstate = g_EvseController.GetState();
  int i;

  if (g_EvseController.StateTransition()) {
    switch(curstate) {
    case EVSE_STATE_A: // not connected
      SetGreenLed(HIGH);
      SetRedLed(LOW);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(GREEN);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE Ready   ");
      g_Lcd.setCursor(13,0);
      g_Lcd.print((int)g_EvseController.GetCurrentCapacity());
      g_Lcd.print("A");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("Not Connected  ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
    case EVSE_STATE_B: // connected/not charging
      SetGreenLed(HIGH);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(YELLOW);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE Ready      ");
      g_Lcd.setCursor(13,0);
      g_Lcd.print((int)g_EvseController.GetCurrentCapacity());
      g_Lcd.print("A");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("Waiting for EV   ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
    case EVSE_STATE_C: // charging
      SetGreenLed(LOW);
      SetRedLed(LOW);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(BLUE);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("Charging     ");
      g_Lcd.print((int)g_EvseController.GetCurrentCapacity());
      g_Lcd.print ("A");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is on
      break;
    case EVSE_STATE_D: // vent required
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(RED);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE ERROR      ");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("VENT REQUIRED   ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
    case EVSE_STATE_DIODE_CHK_FAILED:
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(RED);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE ERROR      ");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("DIODE CHK FAILED");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
    case EVSE_STATE_GFCI_FAULT:
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(RED);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE ERROR     ");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("GFCI FAULT      ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
     case EVSE_STATE_NO_GROUND:
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(RED);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE ERROR      ");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("NO GROUND       ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
     case EVSE_STATE_STUCK_RELAY:
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      #ifdef LCD16X2 //Adafruit RGB LCD
      lcdSetBacklightColor(RED);
      g_Lcd.setCursor(0, 0);
      g_Lcd.print("EVSE ERROR      ");
      g_Lcd.setCursor(0, 1);
      g_Lcd.print("STUCK RELAY      ");
      #endif //Adafruit RGB LCD
      // n.b. blue LED is off
      break;
    default:
      SetGreenLed(LOW);
      SetRedLed(HIGH);
      // n.b. blue LED is off
    }
  }
#ifdef LCD16X2
  if (curstate == EVSE_STATE_C) {
    time_t elapsedTime = g_EvseController.GetElapsedChargeTime();
    if (elapsedTime != g_EvseController.GetElapsedChargeTimePrev()) {
      g_Lcd.setCursor(0, 1);      
      int h = hour(elapsedTime);
      int m = minute(elapsedTime);
      int s = second(elapsedTime);
      if (h < 10) {
	g_Lcd.print("0"); 
      } 
      g_Lcd.print(h);
      g_Lcd.print(":");
      if (m < 10) {
	g_Lcd.print("0"); 
      } 
      g_Lcd.print(m);
      g_Lcd.print(":"); 
      if (s < 10) {
	g_Lcd.print("0"); 
      }
      g_Lcd.print(s);
      g_Lcd.print("        "); 
    }
  }
#endif
}


#ifdef GFI

// interrupt service routing
void gfi_isr()
{
  g_EvseController.SetGfiTripped();
}

void Gfi::Init()
{
  m_GfiFault = 0;

  Reset();
}

//RESET GFI LOGIC
void Gfi::Reset()
{
#ifdef WATCHDOG
  wdt_reset(); // pat the dog
#endif // WATCHDOG

  m_GfiFault = 0;
}

#endif // GFI
//-- begin J1772Pilot

void J1772Pilot::Init()
{
  pinMode(PILOT_PIN,OUTPUT);
  m_bit = digitalPinToBitMask(PILOT_PIN);
  m_port = digitalPinToPort(PILOT_PIN);

  SetState(PILOT_STATE_P12); // turns the pilot on 12V steady state
}


// no PWM pilot signal - steady state
// PILOT_STATE_P12 = steady +12V (EVSE_STATE_A - VEHICLE NOT CONNECTED)
// PILOT_STATE_N12 = steady -12V (EVSE_STATE_F - FAULT) 
void J1772Pilot::SetState(PILOT_STATE state)
{
  volatile uint8_t *out = portOutputRegister(m_port);

  uint8_t oldSREG = SREG;
  cli();
  TCCR1A = 0; //disable pwm by turning off COM1A1,COM1A0,COM1B1,COM1B0
  if (state == PILOT_STATE_P12) {
    *out |= m_bit;  // set pin high
  }
  else {
    *out &= ~m_bit;  // set pin low
  }
  SREG = oldSREG;

  m_State = state;
}


// set EVSE current capacity in Amperes
// duty cycle 
// outputting a 1KHz square wave to digital pin 11 via Timer 1
//
int J1772Pilot::SetPWM(int amps)
{
  float duty = 0.0;
  float famps = (float) amps;
  if ((amps >= 6) && (amps < 51)) {
    // duty cycle in %
    duty = famps / 0.6;
  }
  else if ((amps > 51) && (amps < 80)) {
    duty = (famps / 2.5) + 64;
  }
  else if (amps == 80) {
    duty = 96;
  }

  if (duty) {
    // Timer1 initialization:
    // 16MHz / 64 / (OCR1A+1) / 2 on digital 9
    // 16MHz / 64 / (OCR1A+1) on digital 10
    // 1KHz variable duty cycle on digital 10, 500Hz fixed 50% on digital 9
    // pin 10 duty cycle = (OCR1B+1)/(OCR1A+1)
    uint8_t oldSREG = SREG;
    cli();

    TCCR1A = _BV(COM1A0) | _BV(COM1B1) | _BV(WGM11) | _BV(WGM10);
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11) | _BV(CS10);
    OCR1A = 249;

    // 10% = 24 , 96% = 239
    OCR1B = (int)((2.5 * duty) - 1.0);

    SREG = oldSREG;

    m_State = PILOT_STATE_PWM;
    return 0;
  }
  else { // !duty
    // invalid amps
    return 1;
  }
}

//-- end J1772Pilot

//-- begin J1772EVSEController

#ifdef GFI
inline void J1772EVSEController::SetGfiTripped()
{
  m_bFlags |= ECF_GFI_TRIPPED;

  // this is repeated Update(), but we want to keep latency as low as possible
  // for safety so we do it here first anyway
  chargingOff(); // turn off charging current
  // turn off the pilot
  m_Pilot.SetState(PILOT_STATE_N12);

  m_Gfi.SetFault();
  // the rest of the logic will be handled in Update()
}
#endif // GFI

void J1772EVSEController::LoadThresholds()
{
    memcpy(&m_ThreshData,&g_DefaultThreshData,sizeof(m_ThreshData));
}

void J1772EVSEController::Init(char svclvl)
{
  m_bFlags = 0;

#ifdef GFI
  m_GfiRetryCnt = 0;
  m_GfiTripCnt = 0;
#endif // GFI

  pinMode(CHARGING_PIN,OUTPUT);
  chargingOff();

  m_EvseState = EVSE_STATE_UNKNOWN;
  m_PrevEvseState = EVSE_STATE_UNKNOWN;

  if (svclvl == 2) {
    m_bFlags |= ECF_L2; // set to Level 2
  }

  //n.b. we need to have voltage reading so we can select between L1/L2
  uint8_t curlevel = GetCurLevel();
  int ampacity =  EEPROM.read((curlevel == 1) ? EOFS_CURRENT_CAPACITY_L1 : EOFS_CURRENT_CAPACITY_L2);

  if ((ampacity == 255) || (ampacity == 0)) {
    ampacity = (curlevel == 1) ? DEFAULT_CURRENT_CAPACITY_L1 : DEFAULT_CURRENT_CAPACITY_L2;
  }
  
  if (ampacity < MIN_CURRENT_CAPACITY) {
    ampacity = MIN_CURRENT_CAPACITY;
  }
  else {
    if (curlevel == 1) { // L1
      if (ampacity > MAX_CURRENT_CAPACITY_L1) {
        ampacity = MAX_CURRENT_CAPACITY_L1;
      }
    }
    else {
      if (ampacity > MAX_CURRENT_CAPACITY_L2) {
        ampacity = MAX_CURRENT_CAPACITY_L2;
      }
    }
  }

  LoadThresholds();

  SetCurrentCapacity(ampacity);

  m_Pilot.Init(); // init the pilot
#ifdef GFI
  m_Gfi.Init();
#endif // GFI


  g_OBD.SetGreenLed(LOW);
}

//TABLE A1 - PILOT LINE VOLTAGE RANGES (recommended.. adjust as necessary
//                           Minimum Nominal Maximum 
//Positive Voltage, State A  11.40 12.00 12.60 
//Positive Voltage, State B  8.36 9.00 9.56 
//Positive Voltage, State C  5.48 6.00 6.49 
//Positive Voltage, State D  2.62 3.00 3.25 
//Negative Voltage - States B, C, D, and F -11.40 -12.00 -12.60 
void J1772EVSEController::Update()
{
  uint8_t prevevsestate = m_EvseState;
  uint8_t tmpevsestate = EVSE_STATE_UNKNOWN;
  uint8_t nofault = 1;

  int plow;
  int phigh;

#ifdef ADVPWR
  int PS1state = digitalRead(ACLINE1_PIN);
  int PS2state = digitalRead(ACLINE2_PIN);

  if (chargingIsOn()) { // ground check - can only test when relay closed
    
    if ((PS1state == HIGH) && (PS2state == HIGH)) {
      // bad ground
      
      tmpevsestate = EVSE_STATE_NO_GROUND;
      m_EvseState = EVSE_STATE_NO_GROUND;
      
      chargingOff(); // open the relay
      nofault = 0;
    }
  }
  else { // stuck relay check - can test only when relay open
    if ((PS1state == LOW) || (PS2state == LOW)) {
      // stuck relay
      
      tmpevsestate = EVSE_STATE_STUCK_RELAY;
      m_EvseState = EVSE_STATE_STUCK_RELAY;
      
      nofault = 0;
    }
  }
#endif // ADVPWR
   
#ifdef GFI
  if (m_Gfi.Fault()) {
    tmpevsestate = EVSE_STATE_GFCI_FAULT;
    m_EvseState = EVSE_STATE_GFCI_FAULT;

    if (m_GfiRetryCnt < GFI_RETRY_COUNT) {
      if (prevevsestate != EVSE_STATE_GFCI_FAULT) {
	if (m_GfiTripCnt < 255) {
	  m_GfiTripCnt++;
	}
 	m_GfiRetryCnt = 0;
	m_GfiTimeout = millis() + GFI_TIMEOUT;
      }
      else if (millis() >= m_GfiTimeout) {
	m_Gfi.Reset();
	m_GfiRetryCnt++;
	m_GfiTimeout = millis() + GFI_TIMEOUT;
      }
    }

    nofault = 0;
  }
#endif // GFI

  if (nofault) {
    if ((prevevsestate == EVSE_STATE_GFCI_FAULT) ||
	(prevevsestate == EVSE_STATE_NO_GROUND)) {
      // just got out of GFCI fault state - pilot back on
      m_Pilot.SetState(PILOT_STATE_P12);
      prevevsestate = EVSE_STATE_UNKNOWN;
      m_EvseState = EVSE_STATE_UNKNOWN;
    }
    // Begin Sensor readings
    int reading;
    plow = 1023;
    phigh = 0;
    //  digitalWrite(3,HIGH);
    // 1x = 114us 20x = 2.3ms 100x = 11.3ms
    for (int i=0;i < 100;i++) {
      reading = analogRead(VOLT_PIN);  // measures pilot voltage

      if (reading > phigh) {
        phigh = reading;
      }
      else if (reading < plow) {
        plow = reading;
      }
    }
    if ((m_Pilot.GetState() == PILOT_STATE_PWM) && (plow >= m_ThreshData.m_ThreshDS)) {
      // diode check failed
      tmpevsestate = EVSE_STATE_DIODE_CHK_FAILED;
    }
    else if (phigh >= m_ThreshData.m_ThreshAB) {
      // 12V EV not connected
      tmpevsestate = EVSE_STATE_A;
    }
    else if (phigh >= m_ThreshData.m_ThreshBC) {
      // 9V EV connected, waiting for ready to charge
      tmpevsestate = EVSE_STATE_B;
    }
    else if (phigh  >= m_ThreshData.m_ThreshCD) {
      // 6V ready to charge
      tmpevsestate = EVSE_STATE_C;
    }
    else if (phigh > m_ThreshData.m_ThreshD) {
      // 3V ready to charge vent required
      tmpevsestate = EVSE_STATE_D;
    }
    else {
      tmpevsestate = EVSE_STATE_UNKNOWN;
    }

    // debounce state transitions
    if (tmpevsestate != prevevsestate) {
      if (tmpevsestate != m_TmpEvseState) {
        m_TmpEvseStateStart = millis();
      }
      else if ((millis()-m_TmpEvseStateStart) >= ((tmpevsestate == EVSE_STATE_A) ? DELAY_STATE_TRANSITION_A : DELAY_STATE_TRANSITION)) {
        m_EvseState = tmpevsestate;
      }
    }
  }

  m_TmpEvseState = tmpevsestate;
  
  // state transition
  if (m_EvseState != prevevsestate) {
    if (m_EvseState == EVSE_STATE_A) { // connected, not ready to charge
      chargingOff(); // turn off charging current
      m_Pilot.SetState(PILOT_STATE_P12);
    }
    else if (m_EvseState == EVSE_STATE_B) { // connected 
      chargingOff(); // turn off charging current
      m_Pilot.SetPWM(m_CurrentCapacity);
    }
    else if (m_EvseState == EVSE_STATE_C) {
      m_Pilot.SetPWM(m_CurrentCapacity);
      chargingOn(); // turn on charging current
      m_ChargeStartTime = now();
    }
    else if (m_EvseState == EVSE_STATE_D) {
      // vent required not supported
      chargingOff(); // turn off charging current
      m_Pilot.SetState(PILOT_STATE_P12);
    }
    else if (m_EvseState == EVSE_STATE_GFCI_FAULT) {
      // vehicle state F
      chargingOff(); // turn off charging current
      m_Pilot.SetState(PILOT_STATE_N12);
    }
    else if (m_EvseState == EVSE_STATE_DIODE_CHK_FAILED) {
      chargingOff(); // turn off charging current
      // must leave pilot on so we can keep checking
      m_Pilot.SetPWM(m_CurrentCapacity);
    }
    else if (m_EvseState == EVSE_STATE_NO_GROUND) {
      // Ground not detected
      chargingOff(); // turn off charging current
      m_Pilot.SetState(PILOT_STATE_N12);
    }
    else if (m_EvseState == EVSE_STATE_STUCK_RELAY) {
      // Stuck relay detected
      chargingOff(); // turn off charging current
      m_Pilot.SetState(PILOT_STATE_N12);
    }
    else {
      m_Pilot.SetState(PILOT_STATE_P12);
      chargingOff(); // turn off charging current
    }

#ifdef SERDBG
    Serial.print("state: ");
    Serial.print(prevevsestate);
    Serial.print("->");
    Serial.print(m_EvseState);
    Serial.print(" p ");
    Serial.print(plow);
    Serial.print(" ");
    Serial.println(phigh);
#endif // SERDBG
  }

  m_PrevEvseState = prevevsestate;

  // End Sensor Readings

  if (m_EvseState == EVSE_STATE_C) {
    m_ElapsedChargeTimePrev = m_ElapsedChargeTime;
    m_ElapsedChargeTime = now() - m_ChargeStartTime;
  }
}

// read ADC values and get min/max/avg for pilot steady high/low states
void J1772EVSEController::Calibrate(PCALIB_DATA pcd)
{
  uint16_t pmax,pmin,pavg,nmax,nmin,navg;

  for (int l=0;l < 2;l++) {
    int reading;
    uint32_t tot = 0;
    uint16_t plow = 1023;
    uint16_t phigh = 0;
    uint16_t avg = 0;
    m_Pilot.SetState(l ? PILOT_STATE_N12 : PILOT_STATE_P12);

    delay(250); // wait for stabilization

    // 1x = 114us 20x = 2.3ms 100x = 11.3ms
    uint8_t pin = PILOT_PIN;
    int i;
    for (i=0;i < 1000;i++) {
      reading = analogRead(VOLT_PIN);  // measures pilot voltage

      if (reading > phigh) {
        phigh = reading;
      }
      else if (reading < plow) {
        plow = reading;
      }

      tot += reading;
    }
    avg = tot / i;

    if (l) {
      nmax = phigh;
      nmin = plow;
      navg = avg;
    }
    else {
      pmax = phigh;
      pmin = plow;
      pavg = avg;
    }
  }
  pcd->m_pMax = pmax;
  pcd->m_pAvg = pavg;
  pcd->m_pMin = pmin;
  pcd->m_nMax = nmax;
  pcd->m_nAvg = navg;
  pcd->m_nMin = nmin;
}


int J1772EVSEController::SetCurrentCapacity(uint8_t amps,uint8_t updatepwm)
{
  if ((amps >= MIN_CURRENT_CAPACITY) && (amps <= ((GetCurLevel() == 1) ? MAX_CURRENT_CAPACITY_L1 : MAX_CURRENT_CAPACITY_L2))) {
    m_CurrentCapacity = amps;
    if (updatepwm && (m_Pilot.GetState() == PILOT_STATE_PWM)) {
      m_Pilot.SetPWM(amps);
    }
    return 0;
  }
  else {
    return 1;
  }
}


//-- end J1772EVSEController

#ifdef LCD16X2 //Adafruit RGB LCD 
void lcdWelcome()
{
  g_Lcd.begin(16, 2);
  g_Lcd.setCursor(0, 0);
  g_Lcd.print("Open EVSE       ");
  delay(500);
  g_Lcd.setCursor(0, 1);
  g_Lcd.print("Version ");
  g_Lcd.print(VERSTR);
  g_Lcd.print("   ");
  delay(1500);
}
#endif // LCD16X2

#ifdef RGBLCD
void doRgbLcdBtns()
{   
    uint8_t buttons = g_Lcd.readButtons();

  if (buttons) {
    
    if (buttons & BUTTON_UP) {
      
    }
    if (buttons & BUTTON_DOWN) {
      
    }
    if (buttons & BUTTON_LEFT) {
      
    }
    if (buttons & BUTTON_RIGHT) {
      
    }
    if (buttons & BUTTON_SELECT) {
 
    }
  }
}
#endif //Adafruit RGB LCD

#ifdef ADVPWR
char doPost()
{
  char svclvl = 0;

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(PILOT_PIN, OUTPUT);
  pinMode(CHARGING_PIN, OUTPUT);
  pinMode(VOLT_PIN, INPUT);

  digitalWrite(PILOT_PIN, HIGH); //check to see if EV is plugged in write early so it will stabelize before reading.
  digitalWrite(RED_LED_PIN, HIGH); // Red LED on for ADVPWR
  #ifdef LCD16X2 //Adafruit RGB LCD
    g_Lcd.setCursor(0, 0);
    g_Lcd.print("Power On        ");
    delay(100);
    g_Lcd.setCursor(0, 1);
    g_Lcd.print("Self Test       ");
    delay(1500);
  #endif //Adafruit RGB LCD 
  pinMode(ACLINE1_PIN, INPUT);
  pinMode(ACLINE2_PIN, INPUT);
  digitalWrite(ACLINE1_PIN, HIGH);
  digitalWrite(ACLINE2_PIN, HIGH);
  int PS1state = HIGH;
  int PS2state = HIGH;
    
  PS1state = digitalRead(ACLINE1_PIN); //STUCK RELAY test read AC voltage with Relay Open 
  PS2state = digitalRead(ACLINE2_PIN); //STUCK RELAY test read AC voltage with Relay Open
  if ((PS1state == LOW) || (PS2state == LOW)) {   // If AC voltage is present (LOW) than the relay is stuck
    //m_EvseState = EVSE_STATE_STUCK_RELAY;
    digitalWrite(PILOT_PIN, LOW);
    #ifdef LCD16X2 //Adafruit RGB LCD
    lcdSetBacklightColor(RED);
    g_Lcd.setCursor(0, 0);
    g_Lcd.print("--Stuck Relay-- ");
    g_Lcd.setCursor(0, 1);
    g_Lcd.print("Test: Failed    ");
    #endif  //Adafruit RGB LCD
  } 
  else {
    #ifdef LCD16X2 //Adafruit RGB LCD
    g_Lcd.setCursor(0, 0);
    g_Lcd.print("--Stuck Relay-- ");
    g_Lcd.setCursor(0, 1);
    g_Lcd.print("Test: Passed    ");
    delay(1000);
    #endif //Adafruit RGB LCD
    int reading = 1;
    reading = analogRead(VOLT_PIN); //read pilot
    digitalWrite(PILOT_PIN, LOW);
    if (reading > 0) {              // IF no EV is plugged in its Okay to open the relay the do the L1/L2 and ground Check
        digitalWrite(CHARGING_PIN, HIGH);
        delay(500);
        PS1state = digitalRead(ACLINE1_PIN);
        PS2state = digitalRead(ACLINE2_PIN);
        digitalWrite(CHARGING_PIN, LOW);
          if ((PS1state == HIGH) && (PS2state == HIGH)) {     
             // m_EvseState = EVSE_STATE_NO_GROUND;
               #ifdef LCD16X2 //Adafruit RGB LCD
                lcdSetBacklightColor(RED); 
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--Earth Ground--");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Test: Failed    ");
               #endif  //Adafruit RGB LCD
          } 
          else if ((PS1state == LOW) && (PS2state == LOW)) {  //L2   
              #ifdef LCD16X2 //Adafruit RGB LCD
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--Earth Ground--");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Test: Passed    ");
                delay(1000);
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--EVSE Charge-- ");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Rate: L2        ");
                delay(1000);
               #endif //Adafruit RGB LCD

		svclvl = 2; // L2
          }  
          else if ((PS1state == LOW) && (PS2state == HIGH)) {  //L1   
              #ifdef LCD16X2 //Adafruit RGB LCD
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--Earth Ground--");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Test: Passed    ");
                delay(1000);
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--EVSE Charge-- ");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Rate: L1        ");
                delay(1000);
               #endif //Adafruit RGB LCD
          }  
          else if ((PS1state == HIGH) && (PS2state == LOW)) {  //L1   
              #ifdef LCD16X2 //Adafruit RGB LCD
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--Earth Ground--");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Test: Passed    ");
                delay(1000);
                g_Lcd.setCursor(0, 0);
                g_Lcd.print("--EVSE Charge-- ");
                g_Lcd.setCursor(0, 1);
                g_Lcd.print("Rate: L1        ");
                delay(1000);
               #endif //Adafruit RGB LCD

		svclvl = 1; // L1
          }   
     } 
  }
  
  digitalWrite(RED_LED_PIN, LOW); // Red LED off for ADVPWR  

  if (svclvl == 0) {
    while (1); // error, wait forever
  }

  return svclvl;
}
#endif // ADVPWR

void EvseReset()
{
#ifdef LCD16X2 //Adafruit RGB LCD  
  lcdWelcome();
#endif //Adafruit RGB LCD 

  char svclvl = DEFAULT_SERVICE_LEVEL;
#ifdef ADVPWR  // Power on Self Test for Advanced Power Supply
  svclvl = doPost();
#endif // ADVPWR  

  g_EvseController.Init(svclvl);

  g_OBD.Init();


#ifdef SERIALCLI
  g_CLI.Init();
#endif // SERIALCLI

}

void setup()
{
  Serial.begin(SERIAL_BAUD);

#ifdef GFI
  // GFI triggers on rising edge
  attachInterrupt(GFI_INTERRUPT,gfi_isr,RISING);
#endif // GFI

  EvseReset();

#ifdef WATCHDOG
  // WARNING: ALL DELAYS *MUST* BE SHORTER THAN THIS TIMER OR WE WILL GET INTO
  // AN INFINITE RESET LOOP
  wdt_enable(WDTO_1S);   // enable watchdog timer
#endif // WATCHDOG
} 


void loop()
{ 
#ifdef WATCHDOG
  wdt_reset(); // pat the dog
#endif // WATCHDOG

#ifdef SERIALCLI
  g_CLI.getInput();
#endif // SERIALCLI

  g_EvseController.Update();

  g_OBD.Update();
  
#ifdef RGBLCD //Adafruit RGB LCD    
  doRgbLcdBtns();
#endif //Adafruit RGB LCD

}

