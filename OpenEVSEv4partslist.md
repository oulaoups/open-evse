#Parts list for through-hole Open EVSE V4.

# Open EVSE V4 parts list --- **DEPRECATED** #

If you'd like to built your own EVSE controller board instead of ordering one, here are the parts that you will need.
### Fast BOM upload: Upload [this file](http://code.google.com/p/open-evse/downloads/detail?name=evse-v4diy-BOM2.csv&can=2&q=) to DigiKey for a full pre-built bill of materials. ###
Total cost as of 11 Feb 2013 = $119.77

![http://farm9.staticflickr.com/8453/8041888276_24c025f0b7.jpg](http://farm9.staticflickr.com/8453/8041888276_24c025f0b7.jpg)

| **Mfg.** | **Part Number** | **Type** | **Value** | **Name** | **Qty** | **Price** | **URL** |
|:---------|:----------------|:---------|:----------|:---------|:--------|:----------|:--------|
| Atmel    | ATMEGA328P-PU   | Microprocessor | 328p-pu   | IC1      | 1       | $3.16     | http://www.digikey.com/product-detail/en/ATMEGA328P-PU |
| Analog Devices | ADG419BNZ       | HS-Switch | SPDT      | IC2      | 1       | $3.15     | http://www.digikey.com/product-detail/en/ADG419BNZ/ADG419BNZ-ND/820067 |
| Fairchild Semi | LM358N          | Opamp    | LM358     | IC4      | 1       | $0.46     | http://search.digikey.com/us/en/products/LM358N/LM358NFS-ND/458692 |
| Fairchild Semi | MID400          | Optocoupler| 8-dip     | IC5,IC6  | 2       | $4.06     | http://www.digikey.com/product-detail/en/MID400 |
| Maxim    | MAX5033BUPA+    | Vreg switching| 5V        | IC7      | 1       | $3.76     | http://www.digikey.com/product-detail/en/MAX5033BUPA%2B |
| STMicroelectronics | 2N2222A         | NPN Transistor | 2n2222    | Q2       | 1       | $1.26     | http://search.digikey.com/us/en/products/2N2222A/497-2598-ND/603623 |
| Citizen Finetech| HC49US-16.000MABJ-UB| Crystal  | 16000     | Y1       | 1       | $0.63     | http://www.digikey.com/product-detail/en/HC49US-16.000MABJ-UB/300-8499-ND/862775 |
| Fairchild Semi | 1N4148TA        | Diode    | 1N4148    | D1,D3,D4 | 3       | $0.10     | http://search.digikey.com/us/en/products/1N4148TA/1N4148TACT-ND/1532747 |
| Vishay   | 1N4733A         | Diode Zener| 5.1V 1W   | D5,D6    | 2       | $0.23     | http://www.digikey.com/product-detail/en/1N4733A-TR |
| Micro Comm.| SR202-TP        | Diode Schottky| 2A 20V DO41| D7       | 1       | $0.43     | http://www.digikey.com/product-detail/en/SR202-TP |
| Littelfuse Inc.| P6KE16CA        | TVS Diode 16V| P6KE16CA  | TVS      | 1       | $0.50     | http://search.digikey.com/us/en/products/P6KE16CA/P6KE16CALFCT-ND/407666 |
| Microtron| TR1/MCRW250MA   | Fuse     | 0.25A 250V| F1,F2    | 2       | $0.85     | http://www.digikey.com/product-detail/en/TR1%2FMCRW250MA |
| Recom    | RBM-1212D       | DC-DC    |  12v input| +/-12v42ma DC1| 1       | $6.88     | http://www.digikey.com/product-detail/en/RBM-1212D |
| Bourns Inc.| 8230-72-RC      | Inductor | 150uh     | L1,L2    | 2       | $1.66     | http://www.digikey.com/product-detail/en/8230-72-RC |
| Wurth Electronics| 7447452221      | Inductor | 220uh 1.2A| L3       | 1       | $1.47     | http://www.digikey.com/product-detail/en/7447452221 |
| Any      | Any             | Resistor 5%| 100       | [R18](https://code.google.com/p/open-evse/source/detail?r=18)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 110       | [R24](https://code.google.com/p/open-evse/source/detail?r=24)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 320       | [R2](https://code.google.com/p/open-evse/source/detail?r=2)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 330       | [R11](https://code.google.com/p/open-evse/source/detail?r=11),[R17](https://code.google.com/p/open-evse/source/detail?r=17),[R23](https://code.google.com/p/open-evse/source/detail?r=23)| 3       | $0.09     |
| Vishay Dale (Any)| CMF501K0000FHEB | Resistor 1%| 1K 1%     | [R1](https://code.google.com/p/open-evse/source/detail?r=1)| 1       | $1.04     | http://www.digikey.com/product-detail/en/CMF501K0000FHEB |
| Any      | Any             | Resistor 5%| 1k        | [R20](https://code.google.com/p/open-evse/source/detail?r=20)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 1.2k      | [R9](https://code.google.com/p/open-evse/source/detail?r=9)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 2.8k      | [R3](https://code.google.com/p/open-evse/source/detail?r=3),[R4](https://code.google.com/p/open-evse/source/detail?r=4)| 2       | $0.09     |
| Any      | Any             | Resistor 5%| 10k       | [R10](https://code.google.com/p/open-evse/source/detail?r=10),19,25,27,28,30| 6       | $0.09     |
| Any      | Any             | Resistor 5%| 20k       | [R15](https://code.google.com/p/open-evse/source/detail?r=15)| 1       | $0.09     |
| Vishay BC| MRS25000C2802FRP00| Resistor HV 1%| 28k 0.6w  | [R12](https://code.google.com/p/open-evse/source/detail?r=12),[R13](https://code.google.com/p/open-evse/source/detail?r=13)| 2       | $0.36     | http://www.digikey.com/product-detail/en/MRS25000C2802FRP00/PPC28.0KZCT-ND/594989 |
| Any      | Any             | Resistor 5%| 56k       | [R5](https://code.google.com/p/open-evse/source/detail?r=5)| 1       | $0.09     |
| Any      | Any             | Resistor 5%| 100k      | [R6](https://code.google.com/p/open-evse/source/detail?r=6),14,16| 3       | $0.09     |
| Any      | Any             | Resistor 5%| 200k      | [R7](https://code.google.com/p/open-evse/source/detail?r=7)| 1       | $0.09     |
| Vishay BC| HVR2500002743FR500| Resistor | 274k      | [R22](https://code.google.com/p/open-evse/source/detail?r=22)| 1       | $0.57     | http://www.digikey.com/product-detail/en/HVR2500002743FR500 |
| Vishay BC| HVR2500001004FR500| Resistor | 1.0M      | [R21](https://code.google.com/p/open-evse/source/detail?r=21)| 1       | $0.57     | http://www.digikey.com/product-detail/en/HVR2500001004FR500/PPCQF1.0MCT-ND/719864 |
| Any      | Any             | Cap (ceramic) | 18pf      | C1,C2    | 2       | $0.44     | http://www.digikey.com/product-detail/en/SR151A180JAR |
| Any      | Any             | Cap (ceramic) | 22pf      | C8       | 1       | $0.34     | http://www.digikey.com/product-detail/en/K220J15C0GF5TL2/BC1005CT-ND/286627|
| Any      | Any             | Cap (ceramic) | 0.1uf     | C3,4,10-15,20,21| 10      | $0.20     | http://search.digikey.com/scripts/dksearch/dksus.dll?vendor=0&keywords=+399-4266-ND |
| Any      | Any             | Cap (ceramic) | 0.33uf    | C22      | 1       | $0.46     | http://www.digikey.com/product-detail/en/SR205E334MAR/478-5733-ND/2136293|
| TDK Corp.| FK18X5R1E334K   | Cap (ceramic) | 0.33uf low esr| C6,C7    | 2       | $0.34     | http://www.digikey.com/product-detail/en/FK18X5R1E334K |
| Panasonic| ECE-A1EKS4R7    | Cap (electrolitic) | 4.7uf 25V | C5       | 1       | $0.26     | http://www.digikey.com/product-detail/en/ECE-A1EKS4R7/P974-ND/160554 |
| Panasonic | EEA-FC1E100     | Cap (electrolitic) | 10uf 25V  | C9,C19   | 2       | $0.30     | http://search.digikey.com/us/en/products/EEA-FC1E100/P11212-ND/356116 |
| Vishay Sprague| 199D336X9016D1V1E3| Cap (tantalum)| 33uf 16V  | C16      | 1       | $2.07     | http://www.digikey.com/product-detail/en/199D336X9016D1V1E3 |
| Panasonic ECG| EEU-FM1E101     | Cap (electrolitic) | 100uf 25v | C17      | 1       | $0.32     | http://www.digikey.com/product-detail/en/EEU-FM1E101 |
| FCI      | 609-2845-ND     | Header   | 2x3       | ISP1     | 1       | $0.74     | http://www.digikey.com/product-detail/en/75869-131LF/609-2845-ND/1302569 |
| 3M       | 929400-01-36-RK | Header straight| 0.1sp.    | FTDI,LCD,CT1,I/O| 1       | $1.80     | http://www.digikey.com/product-detail/en/929400-01-36-RK/929400E-01-36-ND/1093569 |
| TE Connectivity | A98036-ND       | Connector| 3.5mm 2P  | Rly1,S1/2,SP| 3       | $0.27     | http://www.digikey.com/product-detail/en/1776275-2/A98036-ND/1826899 |
| On Shore Technlogy | ED2609-ND       | Connector| 5.0mm 2P  | DCIN,PILOT| 2       | $0.35     | http://www.digikey.com/product-detail/en/OSTTC022162/ED2609-ND/614558 |
| TE Connectivity | 1776275-3       | Connector| 3.5mm 3P  | JP1      | 1       | $0.78     | http://www.digikey.com/product-detail/en/1776275-3/A98037-ND/1826900 |
| Circuit board| Open EVSE V4    | Board    | Double sided| B1       | 1       | $14.10    | http://oshpark.com |
| Optional | AE10011-ND      | IC socket| 8 pin     | IC2,4,5,6| 4       | 0.50      |         |
| Optional | ED90054-ND      | IC socket| 28 pin    | IC1      | 1       | 1.68      |         |
|          |                 |          |           |          | **Total**| **$73.16**|
| **External components** |
| Crmagnetics | CR8420-1000-G   | CT       | 1000      | CT1      | 1       | $10.65    | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| TE Connectivity| T92S7D22-12     | Relay    | DPST 30amp| Rly1     | 1       | $13.87    | http://www.digikey.com/product-detail/en/T92S7D22-12 |
| CUI Inc  | FSC-S5-12U      | Power supply| 5W 12V    | DC2      | 1       | $27.32    | http://www.digikey.com/product-detail/en/FSC-S5-12U/102-1573-ND/1699037 |
| Laird    | 28B1250-000     | Ferrite core| 31x19x22mm| L4,L5    | 2       | $2.98     | http://www.digikey.com/product-detail/en/28B1250-000 |
| Littelfuse Inc.| 03540902ZXGY    | Fuse holder| 20amp 300V| FH       | 1       | $3.89     | http://www.digikey.com/product-detail/en/03540902ZXGY |
| Littelfuse Inc.| 0314020.MXP     | Fuse     | 3AG 20amp F| F3,F4    | 2       | $1.38     | http://www.digikey.com/product-detail/en/0314020.MXP |
| Panduit  | LAMA6-14-QY     | Ground lug| 6-14 AWG  | GND      | 1       | $1.50     | http://www.digikey.com/product-detail/en/LAMA6-14-QY |
| Adafruit | 714             | Display  | RGB LCD Rev| DSP(opt) | 1       | $24.95    | http://www.adafruit.com/products/714 |
| Any      | Any             | Enclosure| Case      |          | 1       | varies    | Enclosure to fit selected components (~4x4x4" to 6x8x6") |
| Varies   | Wire,terminals,etc.|          |           |          | 1       | $10.00    | Wire,terminals,fastners,standoffs,connectors,etc. (estimated) |
|          |                 |          |           | **System Total**|         | $164.46   |

ALTERNATIVE 12V Power Supply & ALTERNATIVE 12V 30A relay below (Jameco)

| MeanWell | RS-15-12  | Power Supply | 15.6W 12V | DC2 | 1 | $11.95 | http://www.jameco.com/webapp/wcs/stores/servlet/Product_10001_10001_1919051_-1?CID=GOAW&gclid=CKPiy5PqprMCFQyk4Aod5EkARQ |
|:---------|:----------|:-------------|:----------|:----|:--|:-------|:-------------------------------------------------------------------------------------------------------------------------|
| P&B/Tyco | T92P7D22-12  | Relay        | DPST 30amp | Rly1 | 1 | $8.95  |  https://www.jameco.com/webapp/wcs/stores/servlet/Product_10001_10001_2158346_-1                                         |

# Details #

This file is for those who want to source their own PCB and components to build their own OpenEVSE circuit board. This contains most of the features of the pre-built OpenEVSE board.

Prices subject to change and do not include taxes or shipping.

  * **V4.0** - Added header for spare/unused I/O pins and for charging LED, additional +/- 12 vdc isolated power supply filtering, Added decoupling capacitors for all IC's, changed from op-amp to high speed digital switch for pilot signal.<br>Power monitor circuitry added, Voltage sensing and Current transformer inputs. (software modification required).</li></ul>

<ul><li><b>v3.0</b> - Added onboard L1/L2 sense, changed linear 5Vdc regulator to a high efficiency switching regulator.</li></ul>

<ul><li><b>v2.0</b> - Added connections for logic level L1/L2 voltage sense board inputs and power. <b>Changed</b> DC-DC converter to <i>Murata NKA1212SC</i> with 12Vdc input. Added option for second relay. Added a header for connecting to an Adafruit color LCD shield.</li></ul>

<ul><li><b>v1.1</b> - Added MicroPower Direct D107E DC/DC converter.<br>
Notes:<br>
The board no longer requires a dual voltage +12V and-12V supply, and can be powered by a single voltage +12V supply.<br>
The V2,V3,V4 boards require an external 12Vdc power supply of 5 watts or greater depending on displays, relays, and accessories. They can be programmed using the 5V supply on the FTDI or SPI headers, but require the 12V supply to operate the Pilot circuitry.<br>
On the V4 board SPI header pin 5 (reset) is not connected to pin 1 (reset) of the Atmega328, which may be required for some programers (USBTiny ISP).</li></ul>

<b><i>Optional</i> circuitry on the V4 board:</b>
Power monitor components: C5, C19, <a href='https://code.google.com/p/open-evse/source/detail?r=2'>R2</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=9'>R9</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=24'>R24</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=25'>R25</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=27'>R27</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=28'>R28</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=30'>R30</a>, and JP2<br>
To use the power monitoring circuitry on the v4 board requires modification of the V 1.0.0 firmware.<br>
The power monitor circuit is based on the OpenEnergyMonitor circuitry and software library.<br>
<a href='http://openenergymonitor.org/emon/'>http://openenergymonitor.org/emon/</a>
There are many ways to utilize the power monitor circuitry which will require custom software to be written based on the use.<br>
The board uses ADC0 and ADC2 for the power monitor inputs, and was designed to utilize the Sparkfun SEN-11005 Non-Invasive Current Sensor - 30A, along with a 9 volt output AC to AC transformer for measuring the line voltage.”<br>
<br>
<b>L1/L2 Sense components:</b> JP1, IC5, IC6, <a href='https://code.google.com/p/open-evse/source/detail?r=12'>R12</a>, <a href='https://code.google.com/p/open-evse/source/detail?r=13'>R13</a>, F1, F2, C10, C11<br>
Used to monitor for stuck relay and charging level L1/L2.<br>
<br>
<b>Open EVSE is distributed in the hope that it will be useful,</b>
<b>but WITHOUT ANY WARRANTY; without even the implied warranty of</b>
<b>MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.</b>

This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.<br>
