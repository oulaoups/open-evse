# Warnings #
![http://www.mysafetysign.com/img/lg/S/High-Voltage-Danger-Sign-S-2250.gif](http://www.mysafetysign.com/img/lg/S/High-Voltage-Danger-Sign-S-2250.gif)

<b><font color='red'>Warning </font></b>Assembly of a Electric Vehicle charging station requires wiring Alternating Current (AC) components that will be exposed to voltages from 100 to 250v. If you do not have the experience and knowledge required to safely work with AC voltages please consult with an experienced electrician for assistance and inspection of your work.

<b><font color='red'>Note </font></b> Regularly inspect your charging station (OpenEVSE or Commercial). Pay special attention to excess heat, components, handles, and wiring will be warm but they should not be HOT...

<b><font color='red'>Important </font></b> Always Disconnect your charging station from power before performing an inspection and/or maintenance.

<b><font color='red'>Warning </font></b>Do not install OpenEVSE near flammable, explosive, or combustible materials. Do not locate or store flammable, explosive, or combustible materials near the charging station.

<b><font color='red'>Warning </font></b>Do not operate the EVSE with a visibly damaged cable or if the enclosure or connector is broken, open, cracked, or shows any other signs of damage.

<b><font color='red'>Warning </font></b>Adult supervision is required when building, operating, servicing or inspecting.

# Specifications #

| | Built | Quick Kit |
|:|:------|:----------|
| Picture |http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_7674_medium.jpg?186|http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_7705_medium.jpg?186|
| | Built | Quick Kit  |
| Build time (board) | N/A   | 10 - 15 min |
| Current HW version | OpenEVSE Plus v2.5 v3 | OpenEVSE Plus v2.5 v3 |
| Firmware | pre-loaded | pre-loaded |
| Power Supply | Integrated 4W | Integrated 4W |
| Input Voltage | 90 - 264AC @ 50 - 60hz |  90 - 264AC @ 50 - 60hz |
| Split Phase | Yes   | Yes       |
| 3 Phase | Yes   | Yes       |
| GFCI | Yes   | Yes       |
| Diode Check | Yes   | Yes       |
| Ground/Stuck Relay Check | Yes   | Yes       |
| Size | 2.2"x 1.75"x 1" | 2.2"x 1.75"x 1" |
| IO pins | I2C and FTDI | I2C and FTDI |
| Programmer | ISP   | ISP       |
| Serial |  FTDI | FTDI      |

## Power ##

OpenEVSE can be powered by a single phase in the following configurations:

  * 240VAC single-phase: L1, L2, and safety ground

  * 240VAC split-phase: The two phases must both measure 120V AC to ground.
  * 208VAC 3-phase, wye-connected: Any 2 phases and safety ground
  * 230V AC single-phase Line, Neutral, and EARTH
  * 50 or 60Hz

**Note** - OpenEVSE supports 3 phase charging stations, the controller is powered by a single phase and 3 phases are provided to the Electric Vehicle.

# LCD #
## Colors ##
OpenEVSE will display various colors based on state if equipped with a Red - Green - Blue (RGB) Liquid Crystal Display (LCD) or a RGB Light Emitting Diode (LED).

The colors are:
| Color | OpenEVSE State | EV State | J1772 State |
|:------|:---------------|:---------|:------------|
| White | Booting        | N/A      | N/A         |
| Green | Ready          | Not Connected | State A     |
| Yellow | Ready          | Connected | State B     |
| Blue  | Charging       | Charging | State C     |
| Red   | Error          | N/A      | Error       |

## LCD Text ##
The Standard LCD used on OpenEVSE projects has 2 lines and 16 Characters per line.



**Top Line Left Side**
| Ready | OpenEVSE is ready |
|:------|:------------------|
| Charging | OpenEVSE is ready to Charge |
| Error | OpenEVSE has detected an Error |
| Stopped | OpenEVSE has been stopped |
| Waiting | OpenEVSE is waiting for a timer |
| Sleeping | OpenEVSE is sleeping |

**Top Line Right Side**
The Right side displays information about the Service level and Current setting of the Pilot. In the "Ready" States the LCD displays the Service Level L1 - 120V or L2 - 240V and the Maximum current allowed by the Charging Station.

**Bottom Line**
The Bottom line displays information about the state of the Electric Vehicle and the current charging session.

https://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9110_grande.jpg?v=1383890085

| EV Not Connected | OpenEVSE does not detect an EV |
|:-----------------|:-------------------------------|
| EV Connected     | OpenEVSE detected an EV        |

In the Charging state the LCD will display Elapsed time since the Charge session started and the current time reported by the real time clock.

https://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9115_grande.jpg?v=1383890087

**Errors Power on Self Test**
| GFCI Self Test Failed | OpenEVSE did not detect a GFCI Fault during test | Check GFCI CT and Self test coil|
|:----------------------|:-------------------------------------------------|:--------------------------------|
| Earth Ground Test Failed | OpenEVSE could not detect a Ground               | Check Ground Connections and AC\_Test lines |
| Stuck Relay Test Failed | OpenEVSE read AC voltage before Relays were closed | Check Relay and AC\_Test Lines  |

**Errors**
| GFCI Fault | OpenEVSE detected a ground leakage of > 20ma | OpenEVSE will retry charging after 15 minutes up to 4 times |
|:-----------|:---------------------------------------------|:------------------------------------------------------------|
| No Ground  | OpenEVSE lost connection to ground           | Check Grounds and AC\_Test lines                            |
| Vent Required | OpenEVSE read a pilot signal at 3V           | Ventilation required State                                  |
| No Diode   | OpenEVSE did not detect the J1772 Vehicle diode |                                                             |

## Real Time Clock ##
Real Time Clock allows you to set the current time and set up Start and Stop times. These timers are independent to to timers on the vehicle.

Optional Battery - Insert a CR1216 or CR1220 coin cell battery if you wish to keep current time after power failure with the Real Time Clock option.

## Button Menu ##
The Menu options require an LCD and a button switch. The menu operates on Long press and short press.

**Long Press** - Press and hold down

**Short Press** - Press and release

  * To access the menu press the button and hold it down until the menu displays.

  * Scroll through the options with a short press the button.

  * Change the value of an option Press and hold.

  * Scroll through the available values for that particular option short press.

  * Select the desired value Press and hold.

### Button Menu Options ###
**Note** Menu options will not be displayed if the feature is not enabled when the firmware is compiled.

  * LCD Type (Monochrome, RGB)
    * Monochrome - Single Color LCDs
    * RGB - Red, Green, Blue LCDs
  * Service Level (L1, L2, Auto)
    * L1 - Level 1 Charging Only (120v)
    * L2 - Level 2 charging Only (200 - 240v) Recommended for International Users
    * Auto - Auto Detect L1 or L2
  * Default Current (Options based on list in firmware)
  * Vent Required (Enabled, Disabled)
  * Ground Check (Enabled, Disabled)
  * Set Time (Day, Month, Year, Hour, Minute)
  * Start Time (Hour, Minute)
  * Stop Time (Hour, Minute)

# Safety features #

OpenEVSE was designed to comply with safety features required by standards documents for Electric Vehicle Charging from SAE J1772, NEC and UL.

•UL2251 Standard for Plugs, Receptacles and Couplers for Electric Vehicles

•UL2231 Standard for Personnel Protection Systems for Electric Vehicle (EV) Supply Circuits

•SAE J1772™ Electric Vehicle Conductive Charge Coupler Standard

•NEC Article 625 Electric Vehicle Charging System Equipment

Note - OpenEVSE has not been tested or certified by a Nationally Recognized Testing Laboratory.

## Power interlock ##
OpenEVSE includes an interlock that de-energizes the electric vehicle connector and cable whenever the electrical connector is uncoupled from the electric vehicle **(NEC 625.18)**

## Pilot Signal ##
OpenEVSE supports the SAE J1772 pilot signal which provides an automatic means to de-energize the cable conductors and electric vehicle connector upon exposure to strain that could result in either cable rupture or separation of the cable from the electric connector and exposure of live parts **(NEC 625.19) (SAE J1772)**

## Self Check ##
OpenEVSE performs a Self-Testing sequence during start up to ensures unit is working properly and safely upon power-up OpenEVSE checks for:


  * GFCI--Ability to respond to a 20mA ground fault

  * Missing Ground

  * Welded Relay Contact Monitor


## Ground Monitoring ##

OpenEVSE checks ground an power-up and constantly monitors for presence of proper safety ground. **(SAE J1772)**

## Ground Fault Interrupt ##
OpenEVSE includes mandatory Ground Fault Interruption with a 20ma trip in all models available for protection against electric shock of personnel. **(NEC 625.22) (SAE J1772) (UL 2231)**

After each GFCI event OpenEVSE will retry charging up to 4 times after a 15 minute delay per event. **(UL 2231)**

## Stuck Relay detection ##
OpenEVSE checks relay contacts on Power up to ensure relays are functioning properly and providing proper Power interlock.

## Electric Vehicle Identification ##
OpenEVSE verify the pilot signal integrity by checking the Electric Vehicle Diode. The pilot signal must BOTH be at the correct resistance AND pass the "diode check" to activate the circuit. **(SAE J1772)**

**Note** - This safety feature is commonly left out of commercial charging stations

## Ventilation Required ##
OpenEVSE checks for the Ventilation required request from Electric Vehicles. OpenEVSE will deny charging if ventilation is not available or allow if charging station is equipped to activate ventilation. **(SAE J1772)**

**Note** - This safety feature is commonly left out of commercial charging stations or implemented with a warning label only
