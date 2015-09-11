#Build Guide for DIY OpenEVSE PLUS with integrated 30A relays


# OpenEVSE PLUS - DIY 30A Kit #
The DIY <b><font color='teal'> Open</font></b>**EVSE** Plus can be built from a starter kit available at the <b><font color='teal'> Open</font></b>**EVSE** Store.

The kit is available here:
http://openevse-store.myshopify.com/

http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8956_1024x1024.jpg?187

# Reference #


## Schematic, Board files, Gerber files ##
It is a good idea to print the schematic for reference.
The schematic is located here:

https://open-evse.googlecode.com/files/DIY_OpenEVSE_PLUS_30A.zip




## BOM ##
**Included in Starter Kit**
|Part|Value|	Type|	Quantity|	Manufacture|	Part Number| Marking |
|:---|:----|:----|:--------|:-----------|:-----------|:--------|
|Board|	    |	Board|	1       |	GoldPheonix|	Board      |         |
|Power	12V|	    |PS   |	1       |	MicroPowerDirect|	MPM-04D-1205|         |
|DCDC|	D117E|	DC/DC converter|	1       |	MicroPowerDirect|	D117E      |         |
|IC1 |	328p|	Processor|	1       |	Atmel      |	ATMEGA328P-PU-ND| ATMEGA328P-PU |


**Required to Complete**
|Part|Value|	Type|	Quantity|	Manufacture|	Part Number| Marking |
|:---|:----|:----|:--------|:-----------|:-----------|:--------|
|Fuse|	1A  |	Fuse|	2       |	Bel        |	RST 1      |         |
|IC3, IC5|	MID400|	AC detect|	2       |	Fairchild Semi	| MID400     | MID400  |
|IC2 |	LF353|	Opamp|	1       |	Fairchild Semi|	LF353NFS-ND| LF353   |
|IC4 |	Lm358|	Opamp|	1       |	TI         |	296-1395-5-ND| LM368   |
|y1  |	16000|	xtal|	1       |	           |887-1019-ND |         |
|C1, C2|	22pf|	Capacitor|	2       |	Kemet      |	399-9721-ND| 220     |
|C3, C5|	1uf |	Capacitor|	2       |	TDK        |	445-8607-ND| 105     |
|C4, C8|	.1uf|	Capacitor|	2       |	Kemet      |	399-9872-1-ND| 104     |
|C6  |	2.2uf|	Capacitor|	1       |	TDK        |	445-8514-ND| 225     |
|C9  |	10UF|	Capacitor|	1       |	Panasonic  |	P5148-ND   |         |
|TVS |	P6KE16CA|	TVS Diode|	1       |	Littelfuse Inc| 	P6KE16CA  | bi-directional |
|D1, D2, D3, D4|	1N4148|	Diode|	4       |	Diodes Inc |	1N4148DICT-ND|         |
|D5,D6	|1N5231 |Diode|	2       |	           |	1N5231BVSCT-ND|         |
|Q1,Q2	|2n2222|	NPN Transistor|	2       |	STMicroelectronics|	497-2598-ND|         |
|[R1](https://code.google.com/p/open-evse/source/detail?r=1)|	649 |	Resistor|	1       |	vishay     |	PPC649YCT-ND| Blue - Yellow - White - Black|
|[R2](https://code.google.com/p/open-evse/source/detail?r=2), [R3](https://code.google.com/p/open-evse/source/detail?r=3)|	2.4k|	Resistor|	2       |	Panasonic	 |CF14JT2K40CT-ND| Red - Yellow - Red - Gold |
|[R4](https://code.google.com/p/open-evse/source/detail?r=4), [R11](https://code.google.com/p/open-evse/source/detail?r=11), [R12](https://code.google.com/p/open-evse/source/detail?r=12), [R17](https://code.google.com/p/open-evse/source/detail?r=17)|	330 |	Resistor|	4       |	Panasonic  |	CF14JT330RCT-ND| Orange - Orange - Brown - Gold|
|[R5](https://code.google.com/p/open-evse/source/detail?r=5)|	56k |	Resistor	|1	       |Panasonic   |	CF14JT56K0CT-ND| Green - Blue - Orange - Gold |
|[R6](https://code.google.com/p/open-evse/source/detail?r=6), [R8](https://code.google.com/p/open-evse/source/detail?r=8), [R9](https://code.google.com/p/open-evse/source/detail?r=9), [R14](https://code.google.com/p/open-evse/source/detail?r=14), [R16](https://code.google.com/p/open-evse/source/detail?r=16)|	100k|	Resistor|	5       |	Panasonic  |	CF14JT100K0CT-ND| Brown - Black - Yellow - Gold |
|[R7](https://code.google.com/p/open-evse/source/detail?r=7)|	200k|	Resistor|	1       |	Panasonic  |	CF14JT200K0CT-ND| Red - Black - Yellow - Gold |
|[R10](https://code.google.com/p/open-evse/source/detail?r=10), [R19](https://code.google.com/p/open-evse/source/detail?r=19)|	10k |	Resistor|	2       |	Panasonic  |	CF14JT10K0CT-ND| Brown - Black - Orange - Gold |
|[R15](https://code.google.com/p/open-evse/source/detail?r=15)|	20k |	Resistor|	1       |	Panasonic  |	CF14JT20K0CT-ND| Red - Black - Orange - Gold |
|[R18](https://code.google.com/p/open-evse/source/detail?r=18)|	150 |	Resistor|	1       |	Panasonic  |	CF14JT150RCT-ND| Brown - Green - Brown - Gold|
|[R20](https://code.google.com/p/open-evse/source/detail?r=20)	|1k   |	Resistor|	1       |	Panasonic  |	CF14JT1K00CT-ND| Brown - Black - Red - Gold|
|[R21](https://code.google.com/p/open-evse/source/detail?r=21), [R22](https://code.google.com/p/open-evse/source/detail?r=22)|	47k 1w flame|	resistor|	2       |	Panasonic  |	P47KW-1BK-ND| 473J    |
|PILOT |2Pos |	Term Block|	1       |	TE Connectivity|	1776244-2  |         |
| Relay	| SPST-NO |	Relay|	2       |	TE Connectivity	| T9AS1D22-12 |         |
|.1" |Headers	|		1  |	Misc    |	           |            |         |

## Soldering ##

[![](http://mightyohm.com/blog/wp-content/uploads/2011/04/FullSolderComic_EN_Page_1_resized.png)](http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf)

## Resistor Code ##
Here is a handy Resistor chart created by Bret Victor.
![http://worrydream.com/ResistorDecoder/resistors.png](http://worrydream.com/ResistorDecoder/resistors.png)
Here is a Printable PDF:
http://worrydream.com/ResistorDecoder/resistors.pdf

# Assembly Guide #

![http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8958_1024x1024.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8958_1024x1024.jpg)


## Resistors ##
Resistors can be installed in either direction. To save time a few resistors can be placed, soldered then leads trimmed.

  * Place the 100k ohm resistors (Brown - Black - Yellow - Gold) in positions **[R6](https://code.google.com/p/open-evse/source/detail?r=6)**, **[R8](https://code.google.com/p/open-evse/source/detail?r=8)**, **[R9](https://code.google.com/p/open-evse/source/detail?r=9)**, **[R14](https://code.google.com/p/open-evse/source/detail?r=14)**, and **[R16](https://code.google.com/p/open-evse/source/detail?r=16)**. Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8961_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8961_1024x1024.jpg)

  * Place the 330 ohm resistors (Orange - Orange - Brown - Gold) in positions [R4](https://code.google.com/p/open-evse/source/detail?r=4), [R11](https://code.google.com/p/open-evse/source/detail?r=11), [R12](https://code.google.com/p/open-evse/source/detail?r=12), [R17](https://code.google.com/p/open-evse/source/detail?r=17). Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8962_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8962_1024x1024.jpg)

  * Place the 2.4k ohm resistors (Red - Yellow - Red - Gold) in position [R2](https://code.google.com/p/open-evse/source/detail?r=2) and [R3](https://code.google.com/p/open-evse/source/detail?r=3) and the 10k ohm resistors (Brown - Black - Orange - Gold) in position [R10](https://code.google.com/p/open-evse/source/detail?r=10) and [R19](https://code.google.com/p/open-evse/source/detail?r=19). Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8963_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8963_1024x1024.jpg)

  * Place the 47k ohm 1 watt flame proof resistors (Grey in color - marked 473J) in position [R21](https://code.google.com/p/open-evse/source/detail?r=21) and [R22](https://code.google.com/p/open-evse/source/detail?r=22) and the 649 ohm resistor (Blue - Yellow - White - Black) in position [R1](https://code.google.com/p/open-evse/source/detail?r=1). Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8964_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8964_1024x1024.jpg)

  * Place the remaining resistors 56k (Green - Blue - Orange - Gold) - [R5](https://code.google.com/p/open-evse/source/detail?r=5), 200k ohm (Red - Black - Yellow - Gold) - [R7](https://code.google.com/p/open-evse/source/detail?r=7), 20k (Red - Black - Orange - Gold) - [R15](https://code.google.com/p/open-evse/source/detail?r=15), 150ohm (Brown - Green - Brown - Gold) - [R18](https://code.google.com/p/open-evse/source/detail?r=18), and 1k (Brown - Black - Red - Gold) - [R20](https://code.google.com/p/open-evse/source/detail?r=20). Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8965_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8965_1024x1024.jpg)




## Diodes ##
<b><font color='red'>Note: </font></b> All the diodes in this kit except the TVS diode are directional, note the markings on the board and ensure the dark band on the diode matches the marking.

<b><font color='red'>Caution: </font></b> Handle diodes with care, take precautions to prevent Electrostatic Discharge.

![http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png](http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png)
  * Place the 1N4148 diodes in positions D1, D2, D3, D4. Note markings and install in the correct direction. Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8966_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8966_1024x1024.jpg)
  * Place the 1N5231 diodes in positions D5 and D6. Note markings and install in the correct direction. Solder then trim the excess lead.
  * Place the TVS diode, this part is bi-directional. Solder then trim the excess lead.
![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8968_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8968_1024x1024.jpg)

## Capacitors ##
  * Solder the 0.1uf Capacitors (marked 104) in the positions labled C4 and C8. Trim excess lead.
  * Solder the 22pf Capacitors (marked 220) in the position labeled C1 and C2. Trim excess lead.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8969_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8969_1024x1024.jpg)

  * Solder the 2.2uf Capacitor (marked 225) in the position labeled C6. Trim excess lead.
  * Solder the 1uf capacitor (marked 105) in the positions labeled C3 and C5. Trim excess lead.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8970_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8970_1024x1024.jpg)


## Transistors - Crystal ##

  * Solder the 2 2N2222 Transistors in positions Q1 and Q2 in the orientation indicated on the board. Trim excess leads.

  * Solder the 16.000Mhz Crystal in the position labeled Y1.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8971_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8971_1024x1024.jpg)

## Integrated Circuits ##
<b><font color='red'>Caution: </font></b> Handle Integrated Circuits with care, take precautions to prevent Electrostatic Discharge.

![http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png](http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png)

  * Place MID400 Integrated Circuits in positions IC3 and IC5 in the correct orientation. Solder in place and trim excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8972_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8972_1024x1024.jpg)

  * Place LF353 Integrated Circuit in positions IC2 in the correct orientation. Solder in place and trim excess leads.
  * Place LF358 Integrated Circuit in positions IC4 in the correct orientation. Solder in place and trim excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8973_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8973_1024x1024.jpg)
  * <b><font color='red'>Optional: </font></b> Install a socket for the Microprocessor. In the event the chip is "bricked" and unable to be programmed by normal means, a new microprocessor can be installed in the place of the "bricked" one.

  * Place ATMEGA328P Microprocessor in positions IC1 in the correct orientation. Solder in place and trim excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8974_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8974_1024x1024.jpg)

## Headers - Screw Terminals ##

  * Solder the .1" header pins into position for FTDI, ISP, I2c and the CT.
  * Solder the Screw Terminal in the position labeled Pilot.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8975_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8975_1024x1024.jpg)




## Power ##

  * Solder the DC/DC converter labeled D117E into position. Trim excess leads.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8977_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8977_1024x1024.jpg)

  * Solder the AC/DC universal switch-mode power supply into position. Trim excess leads.
  * Solder Relays into Position.

![![](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8978_medium.jpg)](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8978_1024x1024.jpg)

![http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8979_1024x1024.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8979_1024x1024.jpg)


![http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8981_1024x1024.jpg](http://cdn.shopify.com/s/files/1/0249/6207/products/IMG_8981_1024x1024.jpg)






Follow the Test procedure here: http://code.google.com/p/open-evse/wiki/EVSE_TESTING



This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.