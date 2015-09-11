#Parts list for through-hole Open EVSE V2.

# Open EVSE V2 parts list --- **DEPRECATED** #

If you'd like to built your own EVSE controller board instead of ordering one, here are the parts that you will need.

| Basic EVSE | Part Number |	Type |	Value | Name | Qty | Price | URL |
|:-----------|:------------|:-----|:------|:-----|:----|:------|:----|
| Atmel      | ATMEGA328P-PU | Microprocessor | 328p-pu | IC1  | 1   | $2.50 | http://www.mouser.com/ProductDetail/Atmel/ATMEGA328P-PU/?qs=K8BHR703ZXguOQv3sKbWcg%3d%3d |
| Fairchild Semi | LF353N      | Opamp |	LF353 | IC2  | 1   | $0.60 | http://search.digikey.com/us/en/products/LF353N/LF353NFS-ND/458668 |
| Fairchild Semi | LN358N      | Opamp |	LN358 | IC4  | 1   | $0.46 | http://search.digikey.com/us/en/products/LM358N/LM358NFS-ND/458692 |
| STMicroelectronics | 2N2222A     | NPN Transistor | 2n2222 |	Q1,Q2 | 2   | $0.96 | http://search.digikey.com/us/en/products/2N2222A/497-2598-ND/603623 |
| Fairchild Semi | KA7805ETU   | Vreg | 5V    | IC3  | 1   | $0.65 | http://search.digikey.com/us/en/products/KA7805ETU/KA7805ETU-ND/965381 |
| Citizen Finetech | HC49US-16.000MABJ-UB |Crystal | 16000 | Y1   | 1   | $0.46 | http://www.digikey.com/product-detail/en/HC49US-16.000MABJ-UB/300-8499-ND/862775 |
| Fairchild Semi | 1N4148TA    | Diode | 1N4148 | D1,D2,D3,D4 | 4   | $0.28 | http://search.digikey.com/us/en/products/1N4148TA/1N4148TACT-ND/1532747 |
| Vishay     | 1N4733A     | Diode Zener | 5.1V 1W | D5,D6 | 2   | $0.84 | http://www.digikey.com/product-detail/en/1N4733A-TR |
| Littelfuse Inc. | P6KE16CA    | TVS Diode 16V | P6KE16CA | TVS  | 1   | $0.55 | http://search.digikey.com/us/en/products/P6KE16CA/P6KE16CALFCT-ND/407666 |
| Murata Power Sol. | NKA1212SC   | DC-DC, 12v input | +/- 12v 42ma | DC1  | 1   | $7.61 | http://www.digikey.com/product-detail/en/NKA1212SC |
| Crmagnetics | CR8420-1000-G | CT   | 1000  | CT1  | 1   | $10.65 | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| Bourns Inc. | 8230-72-RC  | Inductor | 150uh | L1,L2 | 2   | $2.21 | http://www.digikey.com/product-detail/en/8230-72-RC |
| Any        | Any         | Resistor | 150   | `R18` | 1   | $0.09 |
| Any        | Any         | Resistor | 330   | `R2,R11,R17` | 3   | $0.09 |
| Vishay Dale (Any) | CMF501K0000FHEB | Resistor | 1K 1% | `R1` | 1   | $0.31 | http://www.digikey.com/product-detail/en/CMF501K0000FHEB |
| Any        | Any         | Resistor | 1k    | `R20` | 1   | $0.09 |
| Any        | Any         | Resistor | 10k   | `R10,R19` | 2   | $0.09 |
| Any        | Any         | Resistor | 20k   | `R15` | 1   | $0.09 |
| Any        | Any         | Resistor | 56k   | `R5` | 1   | $0.09 |
| Any        | Any         | Resistor | 100k  | `R6,R8,R9,R14,R16` | 5   | $0.09 |
| Any        | Any         | Resistor | 200k  | `R7` | 1   | $0.09 |
| Any        | Any         | Cap (ceramic) | 0.1uf | C3,C4,C8 | 3   | $0.30 | http://search.digikey.com/scripts/dksearch/dksus.dll?vendor=0&keywords=+399-4266-ND |
| Any        | Any         | Cap (ceramic) | 18pf  | C1,C2 | 2   | $0.30 | http://www.digikey.com/product-detail/en/SR151A180JAR |
| TDK Corp.  | FK18X5R1E334K | Cap (ceramic) | 0.33uf low esr | C6,C7 | 2   | $0.49 | http://www.digikey.com/product-detail/en/FK18X5R1E334K |
| Panasonic  | EEA-FC1E100 | Cap (electrolitic) | 10uf  | C5,C9 | 2   | $0.30 | http://search.digikey.com/us/en/products/EEA-FC1E100/P11212-ND/356116 |
| Sparkfun   | PRT-10877   | Header | 2x3   | ISP1 | 1   | $1.50 | http://www.sparkfun.com/products/10877 |
| Sparkfun   | PRT-00116   | Header straight | 0.1" sp | FTDI,LCD,CT1 | 1   | $1.50 | http://www.sparkfun.com/products/116 |
| Sparkfun   | PRT-08084   | Connector | 3.5mm 2P | Rly1,Rly2,S1/2,SP | 4   | $0.95 | http://www.sparkfun.com/products/8084 |
| Sparkfun   | PRT-08432   | Connector | 5.0mm 2P | DCIN,PILOT | 2   | $0.95 | http://www.sparkfun.com/products/8432 |
| Circuit board | Open EVSE V2 | Board | Double sided | B1   | 1   | $9.96 | http://oshpark.com |
| Total      | $45.09      |      |       |      |     |       |     |
| **External components**|             |      |       |      |     |       |     |
| Crmagnetics  | CR8420-1000-G  | CT   | 1000  | CT1  | 1   | $10.65 | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| TE Connectivity | T92S7D22-12 | Relay | DPST 30amp | Rly1,Rly2(opt) | 1   | $13.87 | http://www.digikey.com/product-detail/en/T92S7D22-12 |
| Mean Well  | RS-15-12    | Power supply | 15.6W 12V | DC2  | 1   | $11.95 | http://www.jameco.com/webapp/wcs/stores/servlet/ProductDisplay?storeId=10001&catalogId=10001&pa=1919051&productId=1919051 |
| Laird      | 28B1250-000 | Ferrite core | 31x19x22mm | L3,L4 | 2   | $2.98 | http://www.digikey.com/product-detail/en/28B1250-000 |
| Littelfuse Inc. | 03540902ZXGY | Fuse holder | 20amp 300V | FH   | 1   | $3.89 | http://www.digikey.com/product-detail/en/03540902ZXGY |
| Littelfuse Inc. | 0314020.MXP | Fuse | 3AG 20amp F | F1,F2 | 2   | $1.38 | http://www.digikey.com/product-detail/en/0314020.MXP |
| Panduit    | LAMA6-14-QY | Ground lug | 6-14 AWG | GND  | 1   | $1.50 | http://www.digikey.com/product-detail/en/LAMA6-14-QY |
| Adafruit   | 714         | Display | RGB LCD Rev | DSP(opt) | 1   | $24.95 | http://www.adafruit.com/products/714 |
| Any        | Any         | Enclosure | Case  |      | 1   | varies | Enclosure to fit selected components (~4x4x4 to 6x8x6) |
| Varies     | Wire terminals etc. |      |       |      | 1   | $10.00 | Wire terminals fastners standoffs connectors etc. (estimated) |

| **System Total** | $135.44 |
|:-----------------|:--------|


# Details #

This file is for those who want to source their own PCB and components to build their own OpenEVSE circuit board. This contains most of the features of the pre-built OpenEVSE board.

Prices subject to change and does not include taxes or shipping.

  * **v2.0** - Added connections for logic level L1/L2 voltage sense board inputs and power. **Changed** DC-DC converter to _Murata NKA1212SC_ with 12Vdc input. Added option for second relay. Added a header for connecting to an Adafruit color LCD shield.

  * **v1.1** - Added MicroPower Direct D107E DC/DC converter.
Board no longer requires a dual voltage +12V and-12V supply. Board can be powered by a simple single voltage +12V supply.

**Open EVSE is distributed in the hope that it will be useful,**
**but WITHOUT ANY WARRANTY; without even the implied warranty of**
**MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.**

This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.