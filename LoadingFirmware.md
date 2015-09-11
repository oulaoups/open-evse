# Introduction #

Loading firmware to the <b><font color='teal'> Open</font></b>**EVSE** requires an ISP. There are many AVR/Arduino compatible programmers available from Adafruit, Sparkfun and the <b><font color='teal'> Open</font></b>**EVSE** Store. This wiki is based on the <b><font color='teal'> Open</font></b>**EVSE** AVR ISP found here:
https://openevse-store.myshopify.com/collections/frontpage/products/openevse-programmer

# Firmware #
The latest firmware source code is located in GIThub:
https://github.com/lincomatic/open_evse


## Arduino IDE ##
The Arduino IDE includes an code editor, serial monitor, and will compile and upload your code to the <b><font color='teal'> Open</font></b>**EVSE**.

Download and install the Arduino IDE from here:
http://arduino.cc/en/Main/Software


In the Arduino Software you can simply select the Arduino UNO in the Tools - Boards menu or add a custom entry for <b><font color='teal'> Open</font></b>**EVSE**.

<b><font color='red'>Optional </font></b>- To add a custom board go to your Arduino installation folder, the "boards.txt" is in the sub folder Arduino\hardware\arduino\.

![http://cdn.shopify.com/s/files/1/0249/6207/products/boards_txt_large.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/boards_txt_large.jpg)

```
##############################################################

open_evse.name=OpenEVSE

open_evse.bootloader.low_fuses=0xFF
open_evse.bootloader.high_fuses=0xDA
open_evse.bootloader.extended_fuses=0x05

open_evse.upload.using=avrispmkii
open_evse.upload.maximum_size=32768

open_evse.build.mcu=atmega328p
open_evse.build.f_cpu=16000000L
open_evse.core=arduino
open_evse.build.variant=standard
```

After you do that (and restart Arduino), you'll find a new entry in your Boards menu called "OpenEVSE". Select that when preparing to upload firmware.

See also: http://blog.lincomatic.com/?p=10

### Setting Fuse Bits ###
If you are burning virgin chips, you must set the fuse bits prior to programming. Fuses only need to be set once and will retain the settings unless reset. If you've modified boards.txt as shown above, then select "burn bootloader" from the tools menu to set the fuses as appropriate. This step won't actually load a bootloader. It will simply set the fuses.

See also: https://code.google.com/p/open-evse/wiki/AVRDUDE for how to accomplish this.



### Loading Libraries ###
To finish setting up your Arduino IDE you will need to insure any required libraries, indicated by #include, are copied to the libraries folder of your Arduino installation.

![http://cdn.shopify.com/s/files/1/0249/6207/products/libraries_large.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/libraries_large.jpg)

OpenEVSE has two types of libraries those that will always be required by the core source code and those that are only required if you enable a certain feature.

The libraries below are not included in the basic Arduino installation.

The Time library is required by the core OpenEVSE firmware:

More info on the Time library can be found here: http://arduino.cc/playground/Code/Time

```
#include <EEPROM.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>
#include <pins_arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <FlexiTimer2.h> // Required for RTC and Delay Timer
#include <Time.h>
#if defined(ARDUINO) && (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h" // shouldn't need this but arduino sometimes messes up and puts inside an #ifdef
#endif // ARDUINO
```

Some features if enabled will also require a library, a good example are the RTC and LCDs options.

LCDs require LiquidTWI2 library:
https://github.com/lincomatic/LiquidTWI2/downloads

RTC Requires RTClib and FlexiTimer2:
https://github.com/adafruit/RTClib
https://github.com/wimleers/flexitimer2

```
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
```

The Adafruit RGB or i2c backpack LCD library LiquidTWI2.h can be found here:

https://github.com/lincomatic/LiquidTWI2/downloads

### Enabling features ###
To enable a feature delete the "//" in front of the #define tag. To disable a feature add "//"...

Example to enable the Advanced Power Supply features (ADVPWR) Change the line:

//#define ADVPWR

to

#define ADVPWR


Note: Use Extreme caution with WATCHDOG, if delays were added that exceed the timer the EVSE board will reset in an endless loop. It may be very difficult or impossible to recover.


```
//-- begin features

// enable watchdog timer
//#define WATCHDOG

// GFI support
#define GFI
// for stability testing - shorter timeout/higher retry count
//#define GFI_TESTING


// serial port command line
#define SERIALCLI

//Adafruit RGBLCD
#define RGBLCD 
// Adafruit LCD backpack in I2C mode
//#define I2CLCD 

// Advanced Powersupply... Ground check, stuck relay, L1/L2 detection.
//#define ADVPWR

// single button menus (needs LCD enabled)
// connect an SPST button between BTN_PIN and GND via a 2K resistor
// How to use 1-button menu
// When not in menus, short press instantly stops the EVSE - another short press resumes.  Long press activates menus
// When within menus, short press cycles menu items, long press selects and exits current submenu
//#define BTN_MENU


//-- end features
```