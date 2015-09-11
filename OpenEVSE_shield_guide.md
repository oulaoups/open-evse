#Build Guide for DIY OpenEVSE Shield


# OpenEVSE Shield - DIY Kit #


# Reference #


## Schematic, Board files, Gerber files ##
It is a good idea to have the schematic close by for reference.
The schematic is located here:

http://open-evse.googlecode.com/files/DIY_OpenEVSE_shield.zip




## BOM ##
|Part|Value|	Type|	Quantity|	Manufacture|	Part Number| Marking |
|:---|:----|:----|:--------|:-----------|:-----------|:--------|
|Board|	    |	Board|	1       |	GoldPheonix|	Board      |         |
|DCDC|	D107E|	DC/DC converter|	1       |	MicroPowerDirect|	D117E      |         |
|IC2 |	LF353|	Opamp|	1       |	Fairchild Semi|	LF353NFS-ND| LF353   |
|IC4 |	Lm358|	Opamp|	1       |	TI         |	296-1395-5-ND| LM368   |
|C6, C7|	1uf |	Capacitor|	2       |	TDK        |	445-8607-ND| 105     |
|C8  |	.1uf|	Capacitor|	2       |	Kemet      |	399-9872-1-ND| 104     |
|C9  |	10UF|	Capacitor|	1       |	Panasonic  |	P5148-ND   |         |
|TVS |	P6KE16CA|	TVS Diode|	1       |	Littelfuse Inc| 	P6KE16CA  | bi-directional |
|D1, D3, D4|	1N4148|	Diode|	4       |	Diodes Inc |	1N4148DICT-ND|         |
|D5,D6	|1N5231 |Diode|	2       |	           |	1N5231BVSCT-ND|         |
|Q2	 |2n2222|	NPN Transistor|	2       |	STMicroelectronics|	497-2598-ND|         |
|[R1](https://code.google.com/p/open-evse/source/detail?r=1)|	649 |	Resistor|	1       |	vishay     |	PPC649YCT-ND| Blue - Yellow - White - Black|
|[R11](https://code.google.com/p/open-evse/source/detail?r=11), [R17](https://code.google.com/p/open-evse/source/detail?r=17)|	330 |	Resistor|	4       |	Panasonic  |	CF14JT330RCT-ND| Orange - Orange - Brown - Gold|
|[R5](https://code.google.com/p/open-evse/source/detail?r=5)|	56k |	Resistor	|1	       |Panasonic   |	CF14JT56K0CT-ND| Green - Blue - Orange - Gold |
|[R6](https://code.google.com/p/open-evse/source/detail?r=6), [R8](https://code.google.com/p/open-evse/source/detail?r=8), [R9](https://code.google.com/p/open-evse/source/detail?r=9), [R14](https://code.google.com/p/open-evse/source/detail?r=14), [R16](https://code.google.com/p/open-evse/source/detail?r=16)|	100k|	Resistor|	5       |	Panasonic  |	CF14JT100K0CT-ND| Brown - Black - Yellow - Gold |
|[R7](https://code.google.com/p/open-evse/source/detail?r=7)|	200k|	Resistor|	1       |	Panasonic  |	CF14JT200K0CT-ND| Red - Black - Yellow - Gold |
|[R19](https://code.google.com/p/open-evse/source/detail?r=19)|	10k |	Resistor|	2       |	Panasonic  |	CF14JT10K0CT-ND| Brown - Black - Orange - Gold |
|[R15](https://code.google.com/p/open-evse/source/detail?r=15)|	20k |	Resistor|	1       |	Panasonic  |	CF14JT20K0CT-ND| Red - Black - Orange - Gold |
|[R18](https://code.google.com/p/open-evse/source/detail?r=18)|	150 |	Resistor|	1       |	Panasonic  |	CF14JT150RCT-ND| Brown - Green - Brown - Gold|
|[R20](https://code.google.com/p/open-evse/source/detail?r=20)	|1k   |	Resistor|	1       |	Panasonic  |	CF14JT1K00CT-ND| Brown - Black - Red - Gold|
|PILOT |2Pos |	Term Block|	1       |	TE Connectivity|	1776244-2  |         |
|Relay	|2Pos |	Term Block|	1       |	TE Connectivity	|1776275-2   |         |
|.1" |Headers	|		1  |	Misc    |	           |            |         |

## Soldering ##

[![](http://mightyohm.com/blog/wp-content/uploads/2011/04/FullSolderComic_EN_Page_1_resized.png)](http://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf)

## Resistor Code ##

Here is a handy Resistor chart created by Bret Victor.
![http://worrydream.com/ResistorDecoder/resistors.png](http://worrydream.com/ResistorDecoder/resistors.png)
Here is a Printable PDF:
http://worrydream.com/ResistorDecoder/resistors.pdf

# Assembly Guide #

Under construction...

## Resistors ##
Resistors can be installed in either direction. To save time a few resistors can be placed, soldered then leads trimmed.

  * Place the 100k ohm resistors (Brown - Black - Yellow - Gold) in positions [R6](https://code.google.com/p/open-evse/source/detail?r=6), [R8](https://code.google.com/p/open-evse/source/detail?r=8), [R9](https://code.google.com/p/open-evse/source/detail?r=9), [R14](https://code.google.com/p/open-evse/source/detail?r=14), and [R16](https://code.google.com/p/open-evse/source/detail?r=16). Solder then trim the excess lead.
  * Place the 330 ohm resistors (Orange - Orange - Brown - Gold) in positions [R11](https://code.google.com/p/open-evse/source/detail?r=11), [R17](https://code.google.com/p/open-evse/source/detail?r=17). Solder then trim the excess lead.
  * Place the 2.4k ohm resistors (Red - Yellow - Red - Gold) in position [R12](https://code.google.com/p/open-evse/source/detail?r=12) and [R13](https://code.google.com/p/open-evse/source/detail?r=13) and the 10k ohm resistors (Brown - Black - Orange - Gold) in position [R19](https://code.google.com/p/open-evse/source/detail?r=19). Solder then trim the excess lead.
  * Place the 649 ohm resistor (Blue - Yellow - White - Black) in position [R1](https://code.google.com/p/open-evse/source/detail?r=1). Solder then trim the excess lead.
  * Place the remaining resistors 56k (Green - Blue - Orange - Gold) - [R5](https://code.google.com/p/open-evse/source/detail?r=5), 200k ohm (Red - Black - Yellow - Gold) - [R7](https://code.google.com/p/open-evse/source/detail?r=7), 20k (Red - Black - Orange - Gold) - [R15](https://code.google.com/p/open-evse/source/detail?r=15), 150ohm (Brown - Green - Brown - Gold) - [R18](https://code.google.com/p/open-evse/source/detail?r=18), and 1k (Brown - Black - Red - Gold) - [R20](https://code.google.com/p/open-evse/source/detail?r=20). Solder then trim the excess lead.




## Diodes ##
<b><font color='red'>Note: </font></b> All the diodes in this kit except the TVS diode are directional, note the markings on the board and ensure the dark band on the diode matches the marking.

<b><font color='red'>Caution: </font></b> Handle diodes with care, take precautions to prevent Electrostatic Discharge.

![http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png](http://upload.wikimedia.org/wikipedia/commons/thumb/0/06/ESD_%28Susceptible%29.svg/200px-ESD_%28Susceptible%29.svg.png)
  * Place the 1N4148 diodes in positions D1, D3, D4. Note markings and install in the correct direction. Solder then trim the excess lead.
  * Place the 1N5231 diodes in positions D5 and D6. Note markings and install in the correct direction. Solder then trim the excess lead.
  * Place the TVS diode, this part is bi-directional. Solder then trim the excess lead.

## Capacitors ##

## Transistors ##

## Integrated Circuits ##

## Headers - Screw Terminals ##

## Power ##



Follow the Test procedure here: http://code.google.com/p/open-evse/wiki/EVSE_TESTING


This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.
This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.