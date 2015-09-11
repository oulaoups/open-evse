# Introduction #
I have another page describing [building an OpenEVSE](EVSE_by_rbeebe.md) for my Ford C-MAX Energi. I recently leased a Smart ED (Electric Drive) and needed a place to plug it in. Since the first OpenEVSE was fun to put together and less expensive than the commercial EVSE's I decided to buy and build another one.

Since this is my second build I felt more comfortable with the process so I opted for an OpenEVSE kit. I'm glad that Chris is now selling the kit with all the ancillary parts to save hunting for them. And I ordered the same 25 foot Leviton cable and J1772 plug. I had a Hammond waterproof box to put it in but before I finished it the OpenEVSE Custom Enclosure became available so I ordered that. The charge station combo kit I list now includes the enclosure and all the other parts you need. That would have saved me some money and some time.

# High Voltage Schematic #
http://open-evse.googlecode.com/files/EVSEwAdvanced_Power_supply.pdf


# Parts List #
| **Part** | **Source** | **Cost** | **Quantity** | **Link** |
|:---------|:-----------|:---------|:-------------|:---------|
| OpenEVSE 30A Charge Station Combo | OpenEVSE   | $212.50  | 1            | http://openevse-store.myshopify.com/collections/frontpage/products/openevse-30a-charge-station-combo |
| J-1772 cable, 30 amps (A3435-PEV) | Leviton    |   $173.36  | 1            | http://store.leviton.com/dp/B00912OT00#.UD18QGjEV68 |
| OpenEVSE Custom Enclosure | OpenEVSE   | $89.50   | 1            | http://openevse-store.myshopify.com/collections/frontpage/products/custom-enclosure |
| Quick-Disconnect Adapter Set "cheaters" | Radio Shack | $2.49    | 2            | http://www.radioshack.com/product/index.jsp?productId=2103503&filterName=Cable+type&filterValue=Quick+disconnects |
| Illuminated Momentary Button | Adafruit   | $4.95    | 1            | http://www.adafruit.com/products/481|
| Inline power connector (female) | Adafruit   | $0.75    | 1            | http://www.adafruit.com/products/318|
| Inline power connector (male) | Adafruit   | $0.75    | 1            | http://www.adafruit.com/products/310|
| 30A 250V twist lock plug | Home Depot | $19.97   | 1            | http://www.homedepot.com/p/Pass-Seymour-30-Amp-250-Volt-Locking-Plug-L630PCCV3/100114938 |
| 10-3 SJOOW rubber cord | Home Depot | $1.82    | 3            | http://www.homedepot.com/p/Southwire-10-3-SJOOW-Black-300V-By-the-Foot-55812599/204633009 |

| Total | | $509.73 |
|:------|:|:--------|

_Notes:_

  * The total is approximate. I haven't added in some tax and shipping.

# Collect the parts #

The first step was gathering all the materials. A Leviton 30-amp charge cable is on the left. Most of the rest of the parts are from the OpenEVSE kit. A fuse holder with fuses, two 30-amp relays, gland nuts, current sensor, the OpenEVSE RGB LCD display and the OpenEVSE kit. On the upper right is a 2 piece power connector from Adafruit. The plans call for soldering the current sensor to the pins on the OpenEVSE but they wires aren't long enough and I wanted to make it removable. Next to the current sensor is an illuminated button from Adafruit.

![http://rick.beebe.org/photo/EVSE2/parts.jpg](http://rick.beebe.org/photo/EVSE2/parts.jpg)

Because Diversified Stage stopped making their OpenEVSE enclosure, Chris decided to source one for the OpenEVSE store. Since he did all the hard work I decided to buy one.

![http://rick.beebe.org/photo/EVSE2/enclosure.jpg](http://rick.beebe.org/photo/EVSE2/enclosure.jpg)

This is what comes with it. There's an optional seal kit if you're going to be mounting it outdoors.

![http://rick.beebe.org/photo/EVSE2/enclosure_kit.jpg](http://rick.beebe.org/photo/EVSE2/enclosure_kit.jpg)

# Assemble the kit #

I elected to get the quickbuild kit which did mean some soldering. It's pretty easy, however, and all the difficult parts are already soldered on the board. Here's what the kit looks like.

![http://rick.beebe.org/photo/EVSE2/openevse.jpg](http://rick.beebe.org/photo/EVSE2/openevse.jpg)

All the parts mount nicely on the back panel of the enclosure. It's made of white plastic and has all the holes pre-drilled. I used different stand-offs to mount the OpenEVSE itself so I had to modify the holes slightly. Otherwise it's plug and play.

![http://rick.beebe.org/photo/EVSE2/enclosure_panel.jpg](http://rick.beebe.org/photo/EVSE2/enclosure_panel.jpg)

The box is considerably smaller than the Diversified Stage one I used before. That makes it nice mounted on the wall but it's a little tight getting all the big fat wires in there. A little patience and they do fit, however.

![http://rick.beebe.org/photo/EVSE2/enclosure_full.jpg](http://rick.beebe.org/photo/EVSE2/enclosure_full.jpg)

Here's the completed unit.

![http://rick.beebe.org/photo/EVSE2/completed.jpg](http://rick.beebe.org/photo/EVSE2/completed.jpg)