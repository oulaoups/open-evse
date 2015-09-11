# Introduction #
I bought a Ford C-MAX Energi plug-in hybrid in March. It came with 110v charge cable which worked well for overnight charging, but I wanted the ability to get my range back during quick stops at home during the day. That meant a 240v EVSE. I decided on the OpenEVSE because it was relatively inexpensive and because I enjoy building things. That said, I'm not very confident in my soldering skills so I opted for a fully-built OpenEVSE board with the Real Time Clock (RTC) and LCD display. Most of the builds on this wiki use Nema boxes. I decided to get the Diversified Stage custom enclosure because I liked the look of it and they had already done all the hard work.

# High Voltage Schematic #
http://open-evse.googlecode.com/files/EVSEwAdvanced_Power_supply.pdf


# Parts List #
| **Part** | **Source** | **Cost** | **Quantity** | **Link** |
|:---------|:-----------|:---------|:-------------|:---------|
| Open EVSE Plus Board w/ integrated power supply, LCD and RTC (Built) | Open EVSE  | $225.00  | 1            | https://code.google.com/p/open-evse/wiki/Ordering|
| J-1772 cable, 30 amps (A3435-PEV) | Leviton    |   $184.37 | 1            | http://store.leviton.com/dp/B00912OT00#.UD18QGjEV68 |
| OpenEVSE Indoor Enclosure | Diversified Stage, Inc. | $85      | 1            | http://ssl.diversifiedstage.com/estore/index.php?main_page=product_info&products_id=3 |
| 30A Relay | Digikey    | $13.03   | 1            | http://search.digikey.com/us/en/products/T92P7D22-12/PB486-ND/365921 |
| Current Transformer | Digikey    | $10.65   | 1            | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| Fuse Block | Digikey    | 1.13     | 2            | http://www.digikey.com/product-search/en/circuit-protection/fuseholders/655422?k=F1497-ND <br />**see note below**|
| Fuse 30A | Digikey    | 1.68     | 2            | http://www.digikey.com/product-detail/en/0326030.MXP/F1779-ND/778640 |
| Gland Nut | Digikey    | 3.20     | 2            | http://www.digikey.com/product-detail/en/NG-9513/377-1923-ND/439541 |
| 10-3 rubber cord | The Home Depot | $4.29    | 3            | http://www.homedepot.com/p/t/202316422?productId=202316422&storeId=10051&langId=-1&catalogId=10053&MERCH=REC-_-SearchPLPHorizontal1-3-_-NA-_-202316422-_-N <br /> **price per foot**|
| 30A Twist-Lock Plug | The Home Depot | $19.97   | 1            | http://www.homedepot.com/p/Pass-Seymour-30-Amp-250-Volt-Locking-Plug-L630PCCV3/100114938 |
| Ground Bar Kit | The Home Depot | $4.48    | 1            | http://www.homedepot.com/p/Square-D-by-Schneider-Electric-4-Terminal-Ground-Bar-Kit-PK4GTACP/100207842?N=arcd <br />**see note below** |
| 12-10 AWG Female Spade | The Home Depot | $2.99    | 1            | http://www.homedepot.com/p/Tyco-Electronics-Female-Disconnect-Fully-Insulated-Nylon-12-10-AWG-250-Series-10-Clam-CPGI-4-520448-2-10/202204296 |
| 22-18 AWG Female Spade | The Home Depot | $2.99    | 1            | http://www.homedepot.com/p/Tyco-Electronics-Female-Disconnect-Fully-Insulated-Nylon-22-18-AWG-250-Series-10-Clam-CPGI-2-520264-2-10/202204294?keyword=22-18+female+disconnect |
| Quick-Disconnect Adapter Set "cheaters" | Radio Shack | 2.49     | 2            | http://www.radioshack.com/product/index.jsp?productId=2103503&filterName=Cable+type&filterValue=Quick+disconnects |
| Illuminated Momentary Button | Adafruit   | $5.95    | 1            | http://www.adafruit.com/products/481|

| Total | | $540.32 |
|:------|:|:--------|

_Notes:_

  * The total is approximate. I haven't added in some tax and shipping.
  * I didn't buy any nuts, bolts, screws, small wire, or the brackets I used on the enclosure. My shop is pretty well stocked.
  * Note that the fuse holder and ground bar I bought are not the ones the DS enclosure is designed for. See below for the correct part numbers.
  * I did not include the roughly $120 in materials to install the outlet in the garage.

# Collect the parts #

The first step was gathering all the materials. A Leviton 30-amp charge cable is on the left. Next to it is a 10-gauge rubber cable from Home Depot that I had left over from a home generator project. Inside that coil are 2 gland nuts, 2 fuse holders, a current transformer and a 30-amp relay. Upper right is a 30-amp twist lock plug and an illuminated button from Adafruit.

http://rick.beebe.org/photo/EVSE/IMG_1890.JPG

On the left is a ground bus bar sold for home circuit breaker panels. The two circuit boards on the silver envelopes are what you get when you buy an OpenEVSE "kit". The top one is the smarts of the system. Below it is an optional LCD display. To the right are crimp terminals and some "cheaters" for the relay. The grey panel underneath comes with the Diversified Stage box and is where you mount all the components.

http://rick.beebe.org/photo/EVSE/IMG_1895.JPG

A lot of people install their EVSE inside a standard NEMA box. I decided to try out this new ready-built case from Diversified Stage. It's a bit large but it's very heavy duty and all the holes are already cut. Plus it has that cool OpenEVSE logo silk screened on it. Very official!

http://rick.beebe.org/photo/EVSE/IMG_1896.JPG

I ordered the box at the same time I ordered all the other parts. After I got it and was examining the backing plate I realized I didn't know what the predrilled holes were for. An email to DS and they sent me the link to a schematic: https://code.google.com/p/open-evse/downloads/detail?name=evse_indoor_assembly_drawing.pdf&can=2&q= (original source:  http://client.diversifiedstage.com/files/evse_indoor_assembly_drawing.pdf) (I don't know why they don't put this inside the box when you buy it). The holes are for a specific relay, fuse holder and grounding bar. I lucked out with the relay I bought, but my fuse holders and ground bar are different. Fortunately it was easy to adapt the plate to what I bought but you may want to go right for the "correct" ones when you're ordering parts:

| **Part** | **Manufacturer** | **Part number** |
|:---------|:-----------------|:----------------|
| Fuse Holder | Bussman          | BM6032PQ        |
| Grounding Bus | Eaton            | GBK5            |
| Relay    | Potter & Brumfield | TE92P7D22-12    |

The Diversified Stage box can be hard to find. For example at the time of this writing it's not on their website but IS on their ebay store. So if the link I provided doesn't work, go to ebay and search for "diversifiedstage" (http://myworld.ebay.com/diversifiedstage?_trksid=p2047675.l2559)

They also make an outdoor rated box in case you want your EVSE out in the rain. Right now, that one _is_ on their website.

# Assembly #

Here are the parts mounted on the backing plate. DS included screws and washers for mounting the EVSE and the LCD display but I had to scrounge the rest. You'll need washers for the bolts holding the relay in place.

http://rick.beebe.org/photo/EVSE/IMG_1897.JPG

The OpenEVSE board mounted on its standoffs. There are fiber washers under the screw heads. The lower right one hit the headers so I had to sand a couple flats on it.

http://rick.beebe.org/photo/EVSE/IMG_1900.JPG

The LCD display and illuminated button mounted (this is the back of the front cover). This pic shows off my lousy soldering. I should have put heat shrink on there too. I did protect this before final assembly. I had to enlarge the hole slightly for this particular button. I got the Real-Time Clock (RTC) option so there's a battery that will go in that silver clip to keep the clock running.

http://rick.beebe.org/photo/EVSE/IMG_1902.JPG

The easiest way to get the sense wires and the high voltage wires connected together is to use these "cheaters" on the relay.

http://rick.beebe.org/photo/EVSE/IMG_1903.JPG

This is the wiring that can be done before putting the big cables in. It took a little playing around before I figured out this was the best orientation for the inner panel inside my box. There are two holes in the bottom of the enclosure. If you use the left one for the incoming power you probably want to rotate the backing plate 90 degrees clockwise. In my case it worked better to have the power cord on the right and this orientation worked better.

http://rick.beebe.org/photo/EVSE/IMG_1905.JPG

# Power cables #

Strip about 18" from the J-1772 cable so you have plenty to work with inside the box. Red and black are hot. Green is ground. Orange is the copilot wire that goes to the OpenEVSE board and blue is the proximity sensor which isn't used. I cut it off, folded it over and taped the end. Not all J-1772 cables include the blue wire.

http://rick.beebe.org/photo/EVSE/IMG_1907.JPG

Connectors crimped on the incoming power cable. I stripped about 12" from this cable then cut the two hots to the proper length leaving the green ground wire long for now.

http://rick.beebe.org/photo/EVSE/IMG_1908.JPG

Final wiring after the power cables are put in. Ideally you want to leave extra slack in the ground wires. If something should happen and the power cables get yanked out of the EVSE you'd like the copilot wire to unplug first, followed by the two hots and the ground last. It doesn't look it from this angle but my copilot wire is 1" shorter than the power cables.

![http://rick.beebe.org/photo/EVSE/2013-05-21%2008.30.13.jpg](http://rick.beebe.org/photo/EVSE/2013-05-21%2008.30.13.jpg)

The orange wire is the J1772 copilot wire. The green one next to it is the OpenEVSE ground. This is the proper order for those wires. I point this out because there's a "GND" printed on the board right next to that copilot screw and it confused me as to which was which. The "GND" actually references the nearby header pin and not the screw terminal.

The small back and red wires with the white connector go to the current transformer (next photo). That connector was another hard-to-find item. The build instructions say to solder the wires but you know me and soldering. I ended up using an old CPU fan power connector. I tried several different ones. This one fit perfectly. It also helped that it had wires attached because my CT wires weren't long enough to reach.

![http://rick.beebe.org/photo/EVSE/2013-05-21%2008.30.37.jpg](http://rick.beebe.org/photo/EVSE/2013-05-21%2008.30.37.jpg)

The black disk with the charge cables going through it is the current transformer which detects ground faults.

![http://rick.beebe.org/photo/EVSE/2013-05-21%2008.31.08.jpg](http://rick.beebe.org/photo/EVSE/2013-05-21%2008.31.08.jpg)

# Mounting #

The DS box has holes inside it for screwing it to the wall. Unfortunately that means you have to mount it on the wall before you can put the inner panel in and finish wiring it. I decided to drill and tap some holes in the side to use some brackets I had laying around.

http://rick.beebe.org/photo/EVSE/IMG_1909.JPG

The bracket mounted. These were left over from a network switch but could be easily made from steel or aluminum angle.

http://rick.beebe.org/photo/EVSE/IMG_1911.JPG

Mounted and plugged in. I thought of hard wiring it but the twist-lock plug satisfies the local code which requires a local disconnect.

http://rick.beebe.org/photo/EVSE/IMG_1912.JPG

The display is green when ready, blue when charging, and red if there's an error. The lit button--which looks really cool--is used for programming.

http://rick.beebe.org/photo/EVSE/IMG_1914.JPG

The C-Max gets its first taste of 240-volts.

http://rick.beebe.org/photo/EVSE/IMG_1916.JPG

Final installation: How it looks after clamping the power cable out of the way and installing a couple brackets to hold the charge cord.

http://rick.beebe.org/photo/EVSE/IMG_1918.JPG