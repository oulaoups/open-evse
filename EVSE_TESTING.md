# Open EVSE #
Testing should be performed after building an EVSE before placing it into service.

# Recommended Tools #
EV simulator (diode and resistors)

Multimeter w/Frequency (optional)

Occiloscope (optional)

# Advanced Power Supply #
If Advanced Power Supply (ADVPWR) features are enabled, you must have the AC input leads connected to the Relay input and test leads connected to the Relay output. OpenEVSE will not go to State A if the Advanced Power Supply safety checks do not pass.

Normal operation with ADVPWR enabled:

Power Applied to OpenEVSE

Red LED lights to indicate self test

Stuck relay check performed

Blue and Red lights (looks purple-ish)

Relay closes

Ground Checked

L1/L2 Checked and pilot set

Blue off

Red off

If all tests pass Green light on in State A

If tests fail LED indicator is off


![http://farm8.staticflickr.com/7272/7463134098_3e9a4c6c7f.jpg](http://farm8.staticflickr.com/7272/7463134098_3e9a4c6c7f.jpg)

http://code.google.com/p/open-evse/downloads/detail?name=EVSEwAdvanced_Power_supply.pdf&can=2&q=#makechanges

# EV Simulator #
An EV simulator can be as simple as a diode in series with the correct resistor. If you plan to test EVSEs regulary you may want to build a Board.

## Simple ##
<a href='http://www.flickr.com/photos/60192309@N05/6790149512/' title='Untitled by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7060/6790149512_fd64eb3201.jpg' width='500' height='350'>

<h2>Board</h2>
<a href='http://www.flickr.com/photos/60192309@N05/6936255065/' title='Untitled by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7060/6936255065_b6754ae80f_z.jpg' width='549' height='470'>

<h1>Pilot</h1>
The J1772 Pilot is a 1khz +12V to -12V square wave, the voltage defines the state and the duty cycle defines the current available to the EV. The EVSE sets the duty cycle and the EV adds resistance from the pilot the Ground to vary the voltage. The EVSE reads the voltage and changes state accordingly.<br>
<br>
<table><thead><th> State </th><th> Pilot Voltage </th><th> EV Resistance </th><th> Description </th></thead><tbody>
<tr><td> State A </td><td> 12            </td><td> N/A           </td><td> Not Connected </td></tr>
<tr><td> State B </td><td> 9             </td><td> 2.74k         </td><td> Connected   </td></tr>
<tr><td> State C </td><td> 6             </td><td> 882           </td><td> Charging    </td></tr>
<tr><td> State D </td><td> 3             </td><td> 246           </td><td> Ventilation Required </td></tr>
<tr><td> State E </td><td> 0             </td><td> N/A           </td><td> No power    </td></tr>
<tr><td> State F </td><td> -12           </td><td> N/A           </td><td> EVSE Error  </td></tr></tbody></table>

<h2>State A</h2>
To test State A, power up the EVSE. The EVSE should go to the ready state. For Open EVSE, the LED should light Green.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6898998841/' title='IMG_0194 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7193/6898998841_ed91d5247a.jpg' width='500' height='375'>

<h2>State B</h2>
To test State B, with the EVSE powered connect the EV Simulator (or diode and resistor) with a resistance of 2.74k Ohms. The EVSE should go to the EV Connected - EVSE ready state. For Open EVSE, the LED should light Yellow.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936304585/' title='2012-02-26_21-54-17_105 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7057/6936304585_fd8386e8ef.jpg' width='500' height='281'>

<h2>State C</h2>
To test State C, with the EVSE powered connect the EV Simulator (or diode and resistor) with a resistance of 882 Ohms. The EVSE should go to the EV Connected - EVSE ready state. For Open EVSE, the LED should light Blue.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936306517/' title='2012-02-26_21-54-27_427 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7184/6936306517_3b31387f2b.jpg' width='500' height='281'>

<h2>State D</h2>
To test State D, with the EVSE powered connect the EV Simulator (or diode and resistor) with a resistance of 246 Ohms. The EVSE should go to the Error Vent required. For Open EVSE, the LED should light Red.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936308687/' title='2012-02-26_21-54-35_715 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7066/6936308687_2888cf31c3.jpg' width='500' height='281'>

<h2>State E</h2>
To test State E, the EVSE should be disconnected from power. The EVSE should turn off. For Open EVSE, the LED should go out.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6903519199/' title='2012-02-16_08-53-54_262 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7192/6903519199_8cc5a008a5.jpg' width='500' height='281'>

<h2>State F</h2>
To test State F, with the EVSE powered connect the EV Simulator (just a resistor) with a resistance of 2.74k Ohms. The EVSE should go to the Error Diode Check Failed. For Open EVSE, the LED should light Red.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936308687/' title='2012-02-26_21-54-35_715 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7066/6936308687_2888cf31c3.jpg' width='500' height='281'>

<h2>Frequency</h2>
The Pilot should have a frequancy of 1kHz(1000Hz). The acceptible J1772 tolerance is from 980-1020Hz. Test Frequency by attaching the EV simulator in State C "Charging Mode) (or diode and 882 Ohm resistor). Attach a multimeter or occiloscope from pilot to EVSE Ground.<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936301695/' title='2012-02-26_21-53-24_202 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7191/6936301695_b7da995c81.jpg' width='500' height='281'>


<h2>Pilot Duty Cycle</h2>
The Pilot Duty Cycle is dependant on the Max current setting of the EVSE. Test Duty Cycle by attaching the EV simulator in State C "Charging Mode) (or diode and 882 Ohm resistor). Attach an occiloscope from pilot to EVSE Ground. Duty cycle should match the chart below.<br>
<br>
Up to 51A<br>
Amps = Duty cycle x 0.6<br>
Duty cycle = Amps / 0.6<br>
<br>
51 - 80A<br>
Amps = (Duty Cycle - 64) <b>2.5</b>

<table><thead><th> Duty Cycle </th><th> Max Current </th></thead><tbody>
<tr><td> < 3%       </td><td> Error       </td></tr>
<tr><td> 3% - 7%    </td><td> Digitial Com Required </td></tr>
<tr><td> 10%        </td><td> 6A          </td></tr>
<tr><td> 20%        </td><td> 12A         </td></tr>
<tr><td> 30%        </td><td> 18A         </td></tr>
<tr><td> 40%        </td><td> 24A         </td></tr>
<tr><td> 50%        </td><td> 30A         </td></tr>
<tr><td> 60%        </td><td> 36A         </td></tr>
<tr><td> 70%        </td><td> 42A         </td></tr>
<tr><td> 80%        </td><td> 48A         </td></tr>
<tr><td> 86%        </td><td> 55A         </td></tr>
<tr><td> 88%        </td><td> 60A         </td></tr>
<tr><td> 90%        </td><td> 65A         </td></tr>
<tr><td> 92%        </td><td> 70A         </td></tr>
<tr><td> 94%        </td><td> 75A         </td></tr>
<tr><td> 96%        </td><td> 80A         </td></tr>
<tr><td> >96        </td><td> Error       </td></tr></tbody></table>

The EVSE in the picture has a 30A max current setting or a 50% duty cycle. (50% on - 50% off)<br>
<a href='http://www.flickr.com/photos/60192309@N05/6936311363/' title='2012-02-26_21-57-20_482 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7052/6936311363_08c48f4a52.jpg' width='500' height='281'>

<h1>Relay</h1>

To test Relay enter State C, with the EVSE powered connect the EV Simulator (or diode and resistor) with a resistance of 882 Ohms. The EVSE should go to the EV Connected - EVSE ready state and you should be able to hear the relay "click".<br>
<br>
<a href='http://www.flickr.com/photos/60192309@N05/6889916589/' title='2012-02-16_21-12-16_730 by chris1howell, on Flickr'><img src='http://farm8.staticflickr.com/7192/6889916589_a591e9ef06_z.jpg' width='360' height='640'>