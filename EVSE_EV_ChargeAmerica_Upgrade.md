# Parts #
This is a list of parts required to upgrade the EV Charge America EVSE with OpenEVSE components.

| Part | Source | Cost | Quantity | Link |
|:-----|:-------|:-----|:---------|:-----|
| OpenEVSE Board | OpenEVSE | $85  | 1        | http://code.google.com/p/open-evse/wiki/Ordering |
| 12V Advanced Power Supply kit | OpenEVSE | $45  | 1        |  http://code.google.com/p/open-evse/wiki/Ordering |
| 30A Relay | Digikey | $13.03 | 1        | http://search.digikey.com/us/en/products/T92P7D22-12/PB486-ND/365921 |
| Current Transformer | Digikey | $10.65 | 1        | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| PANEL INTERNAL 4.9" X 4.9" (377-1939-ND) | Digikey | $4.80 | 1        | http://search.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&lang=en&site=us&keywords=377-1939-ND&x=0&y=0 |
| FUSEHOLDER 1/4" 30A 250V PNL MNT (283-2850-ND) | Digikey | $4.00 | 2        | http://search.digikey.com/us/en/products/BK%2FHKP-R/283-2850-ND/1024094 |
| AdaFruit RGB LCD Shield kit | AdaFruit | $24.95 | 1        | http://adafruit.com/products/714 |
| Ground Bar Kit | Home Depot | $4.17 | 1        | http://www.homedepot.com/h_d1/N-5yc1v/R-100207842/h_d2/ProductDisplay?catalogId=10053&langId=-1&keyword=Ground+Bar+Kit |
| **Total** |        | **$185** |          |      |


# The Rebuild #

The first step is to remove all the old components and clean the enclosure of debris.

![http://farm9.staticflickr.com/8148/6969859146_186bcf49b8_z.jpg](http://farm9.staticflickr.com/8148/6969859146_186bcf49b8_z.jpg)

Enlarge the holes where the buttons were previously to 1/2" to accommodate the 30A fuse holders and fuses.



![http://farm8.staticflickr.com/7139/7121652095_281cb39e25_z.jpg](http://farm8.staticflickr.com/7139/7121652095_281cb39e25_z.jpg)

Mount the Adafruit RBG LCD to the Enclosure. Use nylon spacers and watch for board flex, Do not over tighten. I used male and femain .1" headers so the LCD and control board can be separated. The two can be soldered together after the LCD is mounted, removal later will be a bit more tricky though.


![http://farm8.staticflickr.com/7060/7121650759_44b63e1722_z.jpg](http://farm8.staticflickr.com/7060/7121650759_44b63e1722_z.jpg)
![http://farm8.staticflickr.com/7108/6975572208_6176bf41e1_z.jpg](http://farm8.staticflickr.com/7108/6975572208_6176bf41e1_z.jpg)


Mount the OpenEVSE/Power Supply stack and Relay to the metal plate and then to the enclosure support with 1/4" nylon spacers for a slight drop to allow for enough space for the AC wiring. Mount the Ground Bar to the Enclosure support.


![http://farm8.staticflickr.com/7204/6975568254_71864eced5_z.jpg](http://farm8.staticflickr.com/7204/6975568254_71864eced5_z.jpg)

Reinstall the assembly into the Enclosure. Cover the LCD wire with Shrink Wrap to prevent the wires from chafing and connect to the OpenEVSE.




![http://farm8.staticflickr.com/7219/6975573990_f9ab02aff3_z.jpg](http://farm8.staticflickr.com/7219/6975573990_f9ab02aff3_z.jpg)

Solder and shrink wrap the AC wires to the center terminals of the fuse holder.

![http://farm9.staticflickr.com/8003/7121657159_1fd9ff6299_z.jpg](http://farm9.staticflickr.com/8003/7121657159_1fd9ff6299_z.jpg)

Solder and shrink wrap wires to the other terminal to go to the relay. You can take 8" or so of wire from the J1772 cable, you already have it, it's the right gauge, flexible and easy to work with.

![http://farm8.staticflickr.com/7128/6975625104_3137bdb990_z.jpg](http://farm8.staticflickr.com/7128/6975625104_3137bdb990_z.jpg)

Crimp and shrink wrap a 1/4" lug connector to the wire from the fuse and a wire to power the OpenEVSE power supply (must be rated above 250V @ 1A).

![http://farm8.staticflickr.com/7049/7123438709_1ace97f5f8_z.jpg](http://farm8.staticflickr.com/7049/7123438709_1ace97f5f8_z.jpg)

Connect Hot, Neutral/Hot and Ground to the OpenEVSE Power Supply.

![http://farm8.staticflickr.com/7240/7124427843_d94d72a564_z.jpg](http://farm8.staticflickr.com/7240/7124427843_d94d72a564_z.jpg)

Install the J1772 cable and slip on the CT coil. Crimp a 1/4" connector to the Hot (black) and Hot/Neutral (White) (ends along with a wire for the Test terminals on the OpenEVSE power supply. Solder the CT leads to the OpenEVSE board. Connect the green wire to the ground block and the pilot wire to the OpenEVSE screw terminal labeled pilot.


![http://farm9.staticflickr.com/8157/6978341332_c28cab19ed_z.jpg](http://farm9.staticflickr.com/8157/6978341332_c28cab19ed_z.jpg)

Test the EVSE before returning to service. http://code.google.com/p/open-evse/wiki/EVSE_TESTING

> ![http://farm9.staticflickr.com/8200/8215283202_eaf4a0135a_n.jpg](http://farm9.staticflickr.com/8200/8215283202_eaf4a0135a_n.jpg)