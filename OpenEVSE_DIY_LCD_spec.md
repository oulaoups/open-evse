#Build Guide for OpenEVSE LCD DIY kit

# OpenEVSE LCD - DIY Kit #
http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9115_1024x1024.jpg?187

<b><font color='teal'> Open</font></b>**EVSE** LCD Boards are designed specifically for <b><font color='teal'> Open</font></b>**EVSE** Charging Stations. They are very compact and easy to interface with 4 wires 5v, GND, i2c SCL i2c SDA. The <b><font color='teal'> Open</font></b>**EVSE** LCD boards support Monochrome (single color) or RGB LCDs (Red - Green - Blue color mixing) and are available with or without a RTC (Real Time Clock)to add EVSE Based timer based functionality. <b><font color='red'>Note </font></b> - Vehicle based timers will work with or without RTC.

The <b><font color='teal'> Open</font></b>**EVSE** RGB LCD uses the [LiquidTWI2](https://github.com/lincomatic/LiquidTWI2) library written by <b><font color='teal'> Open</font></b>**EVSE** firmware guru Lincomatic.

The optional RTC utilizes the DS1307 chip. A CR1220 or CR1225 lithium battery is required but not included due to shipping restrictions.

# Reference #

## Schematic, Board files, Gerber files ##
It is a good idea to print the schematic for reference.
The schematic is located here:

http://open-evse.googlecode.com/files/RGB_i2c_v1plusRTC_TH.zip



## BOM ##
| **Part** | **Value** |	**Type** | **Quantity** |	**Manufacture** |	**Part Number** |
|:---------|:----------|:---------|:-------------|:----------------|:----------------|
|Board     |	          |	Board    |	1            |	<b><font color='teal'> Open</font></b>**EVSE**|	Board           |
| [R1](https://code.google.com/p/open-evse/source/detail?r=1) | 75        |	Resistor | 1            | Stackpole       | CF14JT75R0TR-ND |
| [R2](https://code.google.com/p/open-evse/source/detail?r=2), [R3](https://code.google.com/p/open-evse/source/detail?r=3) | 51        | Resistor | 2            | Stackpole       | CF14JT51R0TR-ND |
| [R4](https://code.google.com/p/open-evse/source/detail?r=4), [R5](https://code.google.com/p/open-evse/source/detail?r=5) | 4.7k      | Resistor | 2            | Stackpole       | CF14JT4K70CT-ND |
| IC1      | MCP23017  | IO expander | 1            | MPC             | MPC23017-E/SP-ND |
| C1       | .1uf      | Capacitor | 1            | Kemet           | 399-9872-1-ND   |
|Contrast  | 10k       | Trimpot  | 1            | Panasonic       | D4AA14-ND       |
| Spacers  | 0.25"     | Spacer   | 4            | Bivar Inc.      | 492-1104-ND     |
| Cable    | 4 pin 0.1" | Cable    | 1            | Pololu          |                 |
|header    | 0.1"      | PC pins  | 25           |  	Nooelec	      |                 |
| LCD      | RGB Common Anaode | Display  | 1            |	Nooelec         |                 |
| **RTC Option** |           |          |              |                 |                 |
|C2        | .1uf      | capacitor | 1            |Kemet            |	399-9872-1-ND   |
|Y1        | 32768     | crystal  | 1            | ECS Inc.        | X1123-ND        |
|IC2       | DS1307    | IC       | 1            | Maxim           | DS1307+-ND      |
| Battery holder | 12mm      | Keystone Electronics | 1            |                 | 3000K-ND        |
| Battery  | CR1220    | Battery  | 1            | Misc            |                 |

## Resistor Code ##
Here is a handy Resistor chart created by Bret Victor.
![http://worrydream.com/ResistorDecoder/resistors.png](http://worrydream.com/ResistorDecoder/resistors.png)
Here is a Printable PDF:
http://worrydream.com/ResistorDecoder/resistors.pdf

## Soldering ##

[![](http://mightyohm.com/blog/wp-content/uploads/2011/04/FullSolderComic_EN_Page_1_resized.png)](http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf)


## Assembly ##
![http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9091_1024x1024.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9091_1024x1024.jpg)

  * Solder the .1" 4-pin header to the i2c connector (If your board has two use the connector on the left).
  * Optional - Solder a 3 pin header on the S - Row for use with a button switch.
  * Flip the board over and trim the excess leads

<b><font color='blue'>Tip </font></b> - Click on Photos in this guide for larger versions.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9092_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9092_1024x1024.jpg)

  * Solder the 2 4.7k resistors in positions [R4](https://code.google.com/p/open-evse/source/detail?r=4) and [R5](https://code.google.com/p/open-evse/source/detail?r=5). Trim excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9093_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9093_1024x1024.jpg)

  * Solder the 0.1uf capacitor in the rectangular box to the right of "CONTRAST" label. Trim Excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9094_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9094_1024x1024.jpg)

  * Solder the 220 Ohm resistor in positions [R1](https://code.google.com/p/open-evse/source/detail?r=1) and the 330 Ohm resistors in [R2](https://code.google.com/p/open-evse/source/detail?r=2) and [R3](https://code.google.com/p/open-evse/source/detail?r=3). Trim the excess lead.

  * Place the MPC23017 Integrated circuit in the position labeled IC1 in the correct orientation. Solder in place.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9095_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9095_1024x1024.jpg)

  * Solder the trim pot in the position labeled "CONTRAST".

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9096_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9096_1024x1024.jpg)


### Real Time Clock RTC (Option) ###

  * If you ordered the RTC option perform the steps below, if not skip the section below.

  * Solder the 0.1uf capacitor in the rectangular box to the left of the "LED1" label. Trim the excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9097_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9097_1024x1024.jpg)

  * Solder the crystal in the position labeled Y1.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9098_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9098_1024x1024.jpg)

  * Place the 1307 Integrated circuit in the position labeled IC2 noting the correct oriantation.
  * Solder in place and trim excess leads.


![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9100_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9100_1024x1024.jpg)

  * Flow solder to form a small bump on the center terminal of the battery holder.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9101_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9101_1024x1024.jpg)

  * Solder the battery holder.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9102_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9102_1024x1024.jpg)

### Liquid Crystal Display LCD ###

  * Solder the 18-pin (for RGB LED) or 16-pin (for Mono LCD) header to logic board Pins extending down.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9103_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9103_1024x1024.jpg)

  * With logic board upside down place the 4 plastic spacers at each corner to ensure proper spacing.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9104_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9104_1024x1024.jpg)

  * Solder the pins the the LCD Module.
  * Trim excess length from header pins


![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9105_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_9105_1024x1024.jpg)

  * Power up your board connected to an OpenEVSE J1772 Controller.
  * <b><font color='red'>Important </font></b>  - Adjust the contrast Labeled **CONTRAST** with a small screw driver until the lettering is bright but the background is still dark.

# Push Button - Optional #
If using the Water resistant push button and 3-pin connector from the OpenEVSE store...

  * Place heat shrink tube over each wire
  * Solder the Red wire on the connector(5v DC) to the terminal lableled "+" on the pushbutton

  * Solder the black wire (GND) to the terminal labeled "-" AND the terminal labeled "C1"

  * Solder the grey wire to the terminal labeled "NO1".
  * <b><font color='red'>Note </font></b>  - The Terminal labeled "NC1" is not connected and can be trimmed off if desired.
  * Carefully shrink the wrap over each solder connection

![http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8220_medium.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8220_medium.jpg)]
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8221_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8221_1024x1024.jpg)
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8222_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8222_1024x1024.jpg)
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8223_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8223_1024x1024.jpg)
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8225_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8225_1024x1024.jpg)
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8226_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8226_1024x1024.jpg)

![http://www.adafruit.com/datasheets/metal16mmbuttons.jpg](http://www.adafruit.com/datasheets/metal16mmbuttons.jpg)


This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.