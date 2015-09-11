# Introduction #
This guide is to show the assembly of my OpenEVSE charger using the official OpenEVSE Enclosure and OpenEVSE Plus v2 board. The board was purchased assembled by Chris with RTC and LCD. I chose OpenEVSE becuase I like projects and also I think it looks better and is cheaper then most alternatives out there.

# High Voltage Schematic #
http://open-evse.googlecode.com/files/EVSEwAdvanced_Power_supply.pdf


# Parts List #
| Part | Source | Cost | Quantity | Link |
|:-----|:-------|:-----|:---------|:-----|
| Open EVSE Plus Board w/ integrated power supply, LCD and RTC (Built) | Open EVSE | $210.00 | 1        | https://code.google.com/p/open-evse/wiki/Ordering|
| J-1772 cable, 30 amps (A3435-PEV) | Leviton |   $173.36 + FS | 1        | http://store.leviton.com/dp/B00912OT00#.UD18QGjEV68 |
| 30A Relay | Digikey | $13.03 | 1        | http://search.digikey.com/us/en/products/T92P7D22-12/PB486-ND/365921 |
| Current Transformer | Digikey | $10.65 | 1        | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| Halex 3/4 in. Strain Relief (2-Pack) | The Home Depot | $6.28 | 1        | http://www.homedepot.com/p/Halex-3-4-in-Strain-Relief-Cord-Connectors-with-Gland-Nut-2-Pack-21694/100126837#.UYEwSaKyD8I |
| Leviton 30 Amp 2-Pole Single Outlet| The Home Depot | $9.49 | 1        | http://www.homedepot.com/p/Leviton-30-Amp-2-Pole-Flush-Mount-Self-Grounding-Single-Outlet-Black-R60-05372-000/202077690#.UYEywaKyD8I |
| Leviton 30A Right Angle Plug | The Home Depot | $14.75 | 1        | http://www.homedepot.com/p/Leviton-30-50-Amp-2-Pole-3-Way-Black-Grounded-Angle-Straight-Blade-Plug-R50-00931-000/202077682#.UYEzt6KyD8I |
| Ground Bar Kit | The Home Depot | $4.67 | 1        | http://www.homedepot.com/p/Blackburn-Aluminum-Ground-Bar-Only-IBT3AB-B1-10/202786635#.UYEzaaKyD8I |
| OpenEVSE Indoor Enclosure | Diversified Stage, Inc. | $58.00 + $16.85 shipping | 1        | http://ssl.diversifiedstage.com/estore/index.php?main_page=product_info&products_id=3&zenid=l3sdq75duj52lm2gjlfuavdl71 |
| 1/2" Mounting screws and nuts | The Home Depot| $1.18 | 1        | http://www.homedepot.com/p/8-32-x-1-2-in-Zinc-Plated-Round-Head-Combo-Drive-Machine-Screw-8-Pieces-27621/202706065#.UYE5CKKyD8I |
| 1" Mounting screws and nuts | The Home Depot| $1.18 | 1        | http://www.homedepot.com/p/8-32-x-1-in-Zinc-Plated-Round-Head-Combo-Drive-Machine-Screw-8-Pieces-27651/202706068?keyword=27651#.UYE486KyD8I |
| 12-10 AWG Female Spade Piggyback | Ebay   | $4.30 | 1        | http://www.ebay.com/itm/130877054917?ssPageName=STRK:MEWNX:IT&_trksid=p3984.m1439.l2649 |
| 22-18 AWG Female Spade | Ebay   | $4.20 | 1        | http://www.ebay.com/itm/140941993829?ssPageName=STRK:MEWNX:IT&_trksid=p3984.m1439.l2649 |
| Illuminated Momentary Button | Ebay   | $8.99 + $4.00 shipping | 1        | http://www.ebay.com/itm/130563267308?ssPageName=STRK:MEWAX:IT&_trksid=p3984.m1423.l2649|
| Shipping | Digikey | $5   | 1        |      |


| Total | | $531.18 |
|:------|:|:--------|


# Build #

The first step was gathering all the materials. After I completed this I moved onto mounting the components to the back panel of the enclosure. I used 1/2" screws for the relay and 1" screws for the grounding bar. The enclosure includes mounting hardware for the OpenEVSE Plus v2 board.

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3299_zps3db77fb2.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3299_zps3db77fb2.jpg)


The next thing I did was solder on the spade connectors onto the incoming 220 line and the outgoing J-1772 cable. I put heat shrink over the connections.

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3281_zps3b4bac53.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3281_zps3b4bac53.jpg)


![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3284_zps5e2f8b5d.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3284_zps5e2f8b5d.jpg)


![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3286_zpsb4cb2e5b.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3286_zpsb4cb2e5b.jpg)

The next step was to mount the LCD and momentary switch. The enclosure comes pre drilled for the switch but the switch I purchased was slightlty bigger then the hole so I had to drill it out slighlty. Once I did that it fit in perfectly.

The next thing I did was solder the switch connections to the LCD board. I picked up power for the illumination of the switch from the 5v pad on the LCD board. I then wired the normally open contact of the switch between GND and S on the LCD board.

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3296_zps444b3ef9.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3296_zps444b3ef9.jpg)

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3293_zpsceecbd79.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3293_zpsceecbd79.jpg)

Once that was completed all the soldering was finished and all that remained was to mount the box and connect everything together.

This is what the box looks like internally once mounted and everything is connected.

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3334_zps219e3549.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3334_zps219e3549.jpg)

And this is the finished product.

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3313_zps2a4b6a99.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3313_zps2a4b6a99.jpg)


![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3327_zps1181c39f.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3327_zps1181c39f.jpg)

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3316_zpsc73a76ef.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3316_zpsc73a76ef.jpg)

![http://i144.photobucket.com/albums/r176/scutzi128/IMG_3319_zpseb9d0840.jpg](http://i144.photobucket.com/albums/r176/scutzi128/IMG_3319_zpseb9d0840.jpg)