# Introduction #

This is an example of a 75A EVSE built with the Open EVSE V4.0 DIY PCB (originally built with OpenEVSE Arduino Shield & Arduino).

This should not be attempted by anyone without the required skills and knowledge to work with high voltage.

Open EVSE is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# High Voltage Schematic #
The Open EVSE relay output is 12VDC. To power the Coil of a high current contactor, one 240V AC relay with a 12VDC coil is used to power the 240V AC coil of the contactor.

<a href='http://www.flickr.com/photos/60192309@N05/6550446647/' title='Untitled by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7165/6550446647_14a4dd680b_z.jpg' width='640' height='289'>

<h1>EVSE Ground</h1>

NOTE: The Open EVSE control Board must be grounded to the EV/Earth Ground for the pilot to operate correctly.<br>
<br>
<h1>Notes</h1>

Note: for full 75A Operation, wire this with #3 AWG Copper wire for the (2) hots (I used Red and Black), and a #6 THHN for Ground (I used Green) to a 100A circuit breaker, a good low cost source for #3 THHN is "StayOnline", see this link:<br>
<a href='http://www.stayonline.com/600-volt-thhn.aspx'>http://www.stayonline.com/600-volt-thhn.aspx</a>

The pictures below show the unit using a 14-50 plug on a 10/3 SOOW cable, this was temporary as I tested and debugged the EVSE, I will update the pictures once I have it hard wired to the 100A breaker/wiring.<br>
<br>
Also shown is the OpenEVSE Arduino shield & Ardunio, it has since been replaced with the OpenEVSE V4 thru-hole PCB, as it has much better noise immunity, I have also replaced the wiring between the OpenEVSE and the AdaFruit LCD display with shielded cable, the ground wire has been upsized (from #22 to #16) from the ground buss to the OpenEVSE module, I have installed (4) ferrite cores and an MOV as well.  All of this was needed to get the EVSE reliable, it will be shown on the updated pictures.<br>
<br>
<br>
<h1>Parts</h1>

<table><thead><th> Part </th><th> Source </th><th> Cost </th><th> Quantity </th><th> Link </th></thead><tbody>
<tr><td> Open EVSE Board V4.0 </td><td> Open EVSE </td><td> ~$73.16 </td><td> 1        </td><td> <a href='http://code.google.com/p/open-evse/wiki/OpenEVSEv4partslist'>http://code.google.com/p/open-evse/wiki/OpenEVSEv4partslist</a> </td></tr>
<tr><td> 12V power supply (102-1573-ND) </td><td> DigiKey </td><td> $27.32 </td><td> 1        </td><td>  <a href='http://www.digikey.com/product-search/en?lang=en&site=us&KeyWords=102-1573-ND'>http://www.digikey.com/product-search/en?lang=en&amp;site=us&amp;KeyWords=102-1573-ND</a> </td></tr>
<tr><td> RELAY GEN PURPOSE SPST 30A 12V (Z215-ND) </td><td> Digikey </td><td> $4.63 </td><td> 1        </td><td> <a href='http://www.digikey.com/product-search/en/relays/power-over-2-amps/1049447?k=Z215-ND'>http://www.digikey.com/product-search/en/relays/power-over-2-amps/1049447?k=Z215-ND</a> </td></tr>
<tr><td> Current Transformer (582-1018-ND) </td><td> Digikey </td><td> $10.65 </td><td> 1        </td><td> <a href='http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174'>http://search.digikey.com/us/en/products/CR8420-1000-G/582-1018-ND/1045174</a> </td></tr>
<tr><td> BOX NEMA ABS 15.68X11.73X6.3 IN (377-1147-ND) </td><td> Digikey </td><td> $111.81 </td><td> 1        </td><td> <a href='http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&lang=en&keywords=377-1147-ND&x=0&y=0&cur=USD'>http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&amp;lang=en&amp;keywords=377-1147-ND&amp;x=0&amp;y=0&amp;cur=USD</a> </td></tr>
<tr><td> PANEL PLASTIC 10.4X14.3" FOR NB (377-1675-ND) </td><td> Digikey </td><td> $17.00 </td><td> 1        </td><td> <a href='http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&lang=en&keywords=377-1675-ND&x=0&y=0&cur=USD'>http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&amp;lang=en&amp;keywords=377-1675-ND&amp;x=0&amp;y=0&amp;cur=USD</a> </td></tr>
<tr><td> FUSE BLOCK 3AG 2POS 1/4"QC (F3130-ND) </td><td> Digikey </td><td> $2.17 </td><td> 2        </td><td> <a href='http://www.digikey.com/product-search/en/circuit-protection/fuseholders/655422?k=F3130-ND'>http://www.digikey.com/product-search/en/circuit-protection/fuseholders/655422?k=F3130-ND</a> </td></tr>
<tr><td> FUSE 1A 250V FAST GLASS 3AG (507-1630-ND) </td><td> Digikey </td><td> $.24 </td><td> 2        </td><td> <a href='http://www.digikey.com/product-detail/en/3AG%201-R/507-1630-ND/1009882'>http://www.digikey.com/product-detail/en/3AG%201-R/507-1630-ND/1009882</a> </td></tr>
<tr><td> FUSE SLOW 250VAC 2A 6X32 (507-1528-ND) </td><td> Digikey </td><td> $.36 </td><td> 2        </td><td> <a href='http://www.digikey.com/product-detail/en/3SB%202-R/507-1528-ND/1009751'>http://www.digikey.com/product-detail/en/3SB%202-R/507-1528-ND/1009751</a> </td></tr>
<tr><td> 8910DPA73V09 - Definite Purpose Contactor </td><td> SuperBreakers </td><td> $130.78 </td><td> 1        </td><td> <a href='http://www.superbreakers.net/8910dpa73v09.html?gclid=COrCtO_enbMCFUOK4AodbwUANA'>http://www.superbreakers.net/8910dpa73v09.html?gclid=COrCtO_enbMCFUOK4AodbwUANA</a> </td></tr>
<tr><td> EVC-C-75A-600-20 20' 75A J-1772 cable</td><td> Avnet Express </td><td> $294.10 </td><td> 1        </td><td> <a href='https://avnetexpress.avnet.com/store/em/EMController?action=products&N=0&langId=-1&storeId=500201&catalogId=500201&term=EVC-C-75A-600S-20/'>https://avnetexpress.avnet.com/store/em/EMController?action=products&amp;N=0&amp;langId=-1&amp;storeId=500201&amp;catalogId=500201&amp;term=EVC-C-75A-600S-20/</a> </td></tr>
<tr><td> VARISTOR 250V 72J 14MM CRIMPD LA (F5598CT-ND) </td><td> DigiKey </td><td> $.62 </td><td> 1        </td><td> <a href='http://www.digikey.com/product-detail/en/V250LT20AP/F5598CT-ND/3307079'>http://www.digikey.com/product-detail/en/V250LT20AP/F5598CT-ND/3307079</a> </td></tr>
<tr><td> FERRITE TUBULAR BEAD 19.05MM (240-2119-ND) </td><td> DigiKey </td><td> $1.39 </td><td> 4        </td><td> <a href='http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&lang=en&keywords=240-2119-ND&x=15&y=15&cur=USD'>http://www.digikey.com/scripts/DkSearch/dksus.dll?WT.z_header=search_go&amp;lang=en&amp;keywords=240-2119-ND&amp;x=15&amp;y=15&amp;cur=USD</a> </td></tr>
<tr><td> Waterproof Metal Pushbutton with Blue LED Ring - 16mm Blue Momentary </td><td> AdaFruit </td><td> $5.95 </td><td> 1        </td><td> <a href='https://www.adafruit.com/products/481'>https://www.adafruit.com/products/481</a> </td></tr>
<tr><td> AdaFruit RGB LCD Shield kit </td><td> AdaFruit </td><td> $24.95 </td><td> 1        </td><td> <a href='http://adafruit.com/products/714'>http://adafruit.com/products/714</a> </td></tr>
<tr><td> Strain Relief .875"-1" to 1" NPT (Hubbel SHC2043CR </td><td> StayOnline </td><td> $7.00 </td><td> 1        </td><td> <a href='http://www.stayonline.com/detail.aspx?id=17209'>http://www.stayonline.com/detail.aspx?id=17209</a> </td></tr>
<tr><td> Ground Bar Kit </td><td> Home Depot </td><td> $4.17 </td><td> 1        </td><td> <a href='http://www.homedepot.com/h_d1/N-5yc1v/R-100207842/h_d2/ProductDisplay?catalogId=10053&langId=-1&keyword=Ground+Bar+Kit'>http://www.homedepot.com/h_d1/N-5yc1v/R-100207842/h_d2/ProductDisplay?catalogId=10053&amp;langId=-1&amp;keyword=Ground+Bar+Kit</a> </td></tr></tbody></table>

<table><thead><th> Totals </th><th> + shipping, misc connectors & nuts/bolts </th><th> $723.24 </th></thead><tbody></tbody></table>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=75AOpenEVSEinstalled.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/75AOpenEVSEinstalled.jpg' alt='75A OpenEVSE installed' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=014DD906-AF14-47EE-AB1F-5107EF67BE67-2259-00000143634B3BBD.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/014DD906-AF14-47EE-AB1F-5107EF67BE67-2259-00000143634B3BBD.jpg' alt='75A OpenEVSE powered up &amp;amp; ready, &amp;quot;select&amp;quot; button with green LED as well, Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=null-4.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/null-4.jpg' alt='75A OpenEVSE control circuit fusing - left 2 fuses 2A Slow Blow for 240V contactor coil, right 2 1A fastblow for 12VDC OpenEVSE power supply, bottom 12V relay can be seen controlling the 240V contactor coil, Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=null-6.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/null-6.jpg' alt='AdaFruit RGB LCD display and &amp;quot;select&amp;quot; button mounted on internal aluminum cover in NEMA enclosure, space for a 2nd LCD display planned out as well - dual J-1772 possible someday, Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/OpenEVSE/?action=view&amp;current=null-8.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/OpenEVSE/null-8.jpg' alt='AdaFruit RGB LCD display &amp;amp; select button, Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=26522D07-655F-4C03-87DE-4E36356468F8-11123-00000408D4734485.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/26522D07-655F-4C03-87DE-4E36356468F8-11123-00000408D4734485.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=F7BB4CC4-33C2-455E-AEC2-BB09AE415DE1-11123-00000408D247C7D5.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/F7BB4CC4-33C2-455E-AEC2-BB09AE415DE1-11123-00000408D247C7D5.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=D268F8E7-441F-464C-8A1B-940ADAA73D62-11123-00000408CD725033.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/D268F8E7-441F-464C-8A1B-940ADAA73D62-11123-00000408CD725033.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

<a href='http://s461.photobucket.com/albums/qq333/mitch672/?action=view&amp;current=7830E66F-515B-4D3C-B5AE-CE2AA9C3672F-11123-00000408CA92DB83.jpg'><img src='http://i461.photobucket.com/albums/qq333/mitch672/7830E66F-515B-4D3C-B5AE-CE2AA9C3672F-11123-00000408CA92DB83.jpg' alt='Uploaded from the Photobucket iPhone App' border='0'>

iPhone app picture of my dual charger Model S, 75A OpenEVSE being used:<br>
<br>
<a href='http://s461.beta.photobucket.com/user/mitch672/media/0A3D82E3-4E4F-445F-886E-62B0BA19F123-5613-0000026CB72C81A0_zps6ac994b1.jpg.html'><img src='http://i461.photobucket.com/albums/qq333/mitch672/0A3D82E3-4E4F-445F-886E-62B0BA19F123-5613-0000026CB72C81A0_zps6ac994b1.jpg' alt=' photo 0A3D82E3-4E4F-445F-886E-62B0BA19F123-5613-0000026CB72C81A0_zps6ac994b1.jpg' border='0' />