# Introduction #

This is an example of a 30A Portable EVSE built with the Open EVSE GFCI board, and Advanced power supply.

This should not be attempted by anyone without the required skills and knowledge to work with high voltage.

Open EVSE is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


# High Voltage Schematic #

http://open-evse.googlecode.com/files/EVSEwAdvanced_Power_supply.pdf

# EVSE Ground #

NOTE: The Open EVSE control Board must be grounded to the EV/Earth Ground for the pilot to operate correctly.

# Circuit #

If using the L6-30 30A cable/outlet/breaker set the EVSE board to a maximum of 24A.

# Parts #

| Part | Source | Cost | Quantity | Link |
|:-----|:-------|:-----|:---------|:-----|
| Open EVSE Plus Board w/ integrated power supply | Open EVSE | $150.00 | 1        | http://code.google.com/p/open-evse/wiki/Ordering |
| 30A Relay | Digikey | $13.03 | 1        | http://search.digikey.com/us/en/products/T92P7D22-12/PB486-ND/365921 |
| Current Transformer | Digikey | $10.65 | 1        | http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174 |
| BOX NEMA ECONOMY 5.9X5.9X3.54 (377-1787-ND) | Digikey | $20.62 | 1        | http://search.digikey.com/scripts/DkSearch/dksus.dll?lang=en&site=us&KeyWords=377-1787-ND&x=0&y=0 |
| PANEL INTERNAL 4.9" X 4.9" (377-1939-ND) | Digikey | $4.80 | 1        | http://search.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&lang=en&site=us&keywords=377-1939-ND&x=0&y=0 |
| FUSEHOLDER 1/4" 30A 250V PNL MNT (283-2850-ND) | Digikey | $3.69 | 2        | http://search.digikey.com/us/en/products/BK%2FHKP-R/283-2850-ND/1024094 |
| FUSE 250V SLO-BLO 3AB 30A (F1779-ND) | Digikey | $1.68 | 2        | http://search.digikey.com/us/en/products/0326030.MXP/F1779-ND/778640 |
| 2" plastic 4-40 M-F standoffs (4813K-ND) | Digikey | $.63 | 8        | http://www.digikey.com/product-detail/en/4813/4813K-ND/255350 |
| J-1772 cable, 30 amps (A3435-PEV) | Leviton |   $133.98 + $12.19 shipping | 1        | http://store.leviton.com/dp/B00912OT00#.UD18QGjEV68 |
| 30A AC Plug L6-30 | Stay Online | $33.00 | 1        | http://www.stayonline.com/detail.aspx?ID=15695 |
| AdaFruit RGB LCD Shield kit | AdaFruit | $24.95 | 1        | http://adafruit.com/products/714 |
| Strain Relief - HUBBELL SHC2041CR 1 Inch Thread Cord Connector | Stayonline | $7.00 | 2        | http://www.stayonline.com/detail.aspx?id=17207 |
| Ground Bar Kit | Home Depot | $4.48 | 1        | http://www.homedepot.com/h_d1/N-5yc1v/R-100207842/h_d2/ProductDisplay?catalogId=10053&langId=-1&keyword=Ground+Bar+Kit |
| Shipping | DigiKey, AdaFruit, StayOnline | $25  | 1        |      |
| Crimp Connectors/PCB connectors | various | $10  | 1        |      |
| Hardware (nuts & bolts) | various | $5   | 1        |      |

| Totals | | $477.48 |
|:-------|:|:--------|

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=PhotoApr2894212AM.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/PhotoApr2894212AM.jpg' alt='Photobucket' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=OpenEVSEassembly11.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/OpenEVSEassembly11.jpg' alt='OpenEVSE completed, completed with AdaFruit RGB LCD display installed' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=OpenEVSEassembly10.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/OpenEVSEassembly10.jpg' alt='OpenEVSE, view of components' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=OpenEVSEassembly5.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/OpenEVSEassembly5.jpg' alt='grounding, grounding conductors from advanced PS, AC power cord, and J-1772 cable' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=OpenEVSEassembly1.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/OpenEVSEassembly1.jpg' alt='OpenEVSE powered up, bench testing before installation' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=OpenEVSEassembly12.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/OpenEVSEassembly12.jpg' alt='OpenEVSE completed, completed with cover closed, and J-1772 and L6-30 seen, 120V adapter installed for testing' border='0'>

16A L2 Pilot signal - waiting for EV<br>
<br>
<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=IMAG001.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/IMAG001.jpg' alt='16A L2 Pilot signal' border='0'>

16A L2 Pilot signal - charging<br>
<br>
<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=IMAG002.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/IMAG002.jpg' alt='Photobucket' border='0'>

<h1>Updated pictures using OpenEVSE V4.0 thruhole PCB</h1>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=3F2B5998-FC3E-477B-B596-5D10880139BC-5177-000002019DCD5835.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/3F2B5998-FC3E-477B-B596-5D10880139BC-5177-000002019DCD5835.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=7DB94CB9-8290-476E-B9C3-A093E28F0ADA-5177-000002019A5A9B83.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/7DB94CB9-8290-476E-B9C3-A093E28F0ADA-5177-000002019A5A9B83.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=099F9571-6A65-44C2-9A1B-2BD704BA8E0E-5177-00000201A1044C2C.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/099F9571-6A65-44C2-9A1B-2BD704BA8E0E-5177-00000201A1044C2C.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=CF0A37A5-8030-4B2A-9ED9-E955E1ABB32F-5177-00000201A417B752.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/CF0A37A5-8030-4B2A-9ED9-E955E1ABB32F-5177-00000201A417B752.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=C875C889-0A25-45D1-BC07-E5EDF73B8016-5177-00000201A7BAE9ED.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/C875C889-0A25-45D1-BC07-E5EDF73B8016-5177-00000201A7BAE9ED.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=3DF25F42-C7B5-447E-9813-A0383A91F469-5177-00000201AB19430E.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/3DF25F42-C7B5-447E-9813-A0383A91F469-5177-00000201AB19430E.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=EA23209D-03B4-4ED4-A939-587E66D93A51-5177-00000201AE5C679B.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/EA23209D-03B4-4ED4-A939-587E66D93A51-5177-00000201AE5C679B.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>