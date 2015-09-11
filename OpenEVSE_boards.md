| | Plus v2.5 | Plus v3 |
|:|:----------|:--------|
| Picture |http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_7674_medium.jpg?186|http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_7674_medium.jpg?|
| | Built     | Built   |
| Build time (board) | N/A       | N/A     |
| Current HW version | OpenEVSE Plus v2.5 | OpenEVSE Plus v3 |
| Firmware | pre-loaded | pre-loaded |
| Power Supply | Integrated 4W | Integrated 4W |
| Input Voltage | 90 - 264AC @ 50 - 60hz |  90 - 264AC @ 50 - 60hz |
| Relay coil| 12v DC    | 12vDC or 208-240vAC |
| Split Phase | Yes       | 208-240AC |
| 3 Phase | Yes       | Yes     |
| GFCI | Yes       | Yes     |
| Diode Check | Yes       | Yes     |
| Ground/Stuck Relay Check | 2 Hots    | 1 Hot   |
| Size | 2.2"x 1.75"x 1" | 2.2"x 1.75"x 1" |
| IO pins | I2C and FTDI | I2C and FTDI |
| Programmer | ISP       | ISP     |
| Serial |  FTDI     | FTDI    |
| Suited for | L1 or L2 and International| L2 and International |
| Price | $74       | $74     |

# Safety features #

OpenEVSE was designed to support all the safety features required (and a few more) by standards documents for Electric Vehicle Charging from SAE J1772, NEC and UL. Note OpenEVSE has not been independently tested by SAE, NEC or UL.

•UL2251 Standard for Plugs, Receptacles and Couplers for Electric Vehicles

•UL2231 Standard for Personnel Protection Systems for Electric Vehicle (EV) Supply Circuits

•SAE J1772™ Electric Vehicle Conductive Charge Coupler Standard

•NEC Article 625 Electric Vehicle Charging System Equipment


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
