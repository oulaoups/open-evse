# Introduction #

There are many ways to change the maximum current offered to the Electric Vehicle, such as serial, USB, Xbee, Bluetooth, buttons or analog trim pot. This setting is stored in the EVSE as a variable.

```
// current capacity in amps  
#define CURRENT_CAPACITY_L1 12  
#define CURRENT_CAPACITY_L2 30    

// minimum allowable current in amps  
#define MIN_CURRENT_CAPACITY 6    

// maximum allowable current in amps  
#define MAX_CURRENT_CAPACITY_L1 20  
#define MAX_CURRENT_CAPACITY_L2 30  
```

The CURRENT\_CAPACITY sets the default current, setting can be modified when the firmware is loaded or by changing the variable with the FTDI serial port. FTDI to USB or FTDI to Bluetooth adapters are avaliable from Sparkfun.

# Buttons/LCD #
Firmware 1.0 and later includes the option to change current with a LCD display and a button.

![http://farm8.staticflickr.com/7113/7835994328_22d61beca6_n.jpg](http://farm8.staticflickr.com/7113/7835994328_22d61beca6_n.jpg)

![http://farm8.staticflickr.com/7109/7835992090_20145daafd_n.jpg](http://farm8.staticflickr.com/7109/7835992090_20145daafd_n.jpg)

The default current can be set for both L1 and L2. The options can be set at time of compile by editing the following code:

```

uint8_t g_L1MaxAmps[] = {6,10,12,14,15,16,0};
uint8_t g_L2MaxAmps[] = {10,16,20,25,30,35,40,45,50,55,60,65,70,75,80,0};


```

**Button Menu**

The Menu options require an LCD and a button switch. The menu operates on Long press and short press.

Long Press - Press and hold down

Short Press - Press and release
  * To access the menu press the button and hold it down until the menu displays.
  * Scroll through the options with a short press the button.
  * Change the value of an option Press and hold.
  * Scroll through the available values for that particular option short press.
  * Select the desired value Press and hold.

# CLI #

The Command line interface uses a standard terminal such as the one included in the Arduino IDE. The baud rate is 38400.

`typed commands in *Bold*`
## CLI Example ##

Open EVSE

Hardware - Atmel ATMEGA328P-AU

Software - Open EVSE v0.4.0


Open\_EVSE>**set amp**

WARNING - DO NOT SET CURRENT HIGHER THAN 80%
OF YOUR CIRCUIT BREAKER OR GREATER
THAN THE RATED VALUE OF THE EVSE

Enter amps (6-80) : **16**

Current Capacity now: 16




Open\_EVSE>**save**

Saving Settings


# Hardware #
Serial

http://guides.openevse.com