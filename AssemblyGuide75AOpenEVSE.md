# IN PROGRESS/ NOT PROOFED/ PHOTOS TO FOLLOW #
# Introduction #

This is an open source design for a J1772 compliant, 75A, 240VAC Electric Vehicle Supply Equipment. More information is posted at http://code.google.com/p/open-evse/

### **This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.** ###

The project requires the use of tools and methods that can cause injury if not performed correctly. Any electrical work can be dangerous. This EVSE operates on 240Volts AC up to 75 Amps. Improper assembly can cause damage to the car, fire, injury and/or death. Do not attempt this project unless you are qualified.

This Assembly guide is based on information gleaned from garygid, chris1howell, glennD and mwolrich. It is written by a novice to help people at a similar level. It assumes that one has the basic skills for soldering, wire work, working with electricity and general understanding of how to assemble things. Think about each step critically before proceeding. If any step seems questionable or you are uncomfortable with it, don’t do it. Get advice from a knowledgeable person if something is not clear or seems questionable.

### **No warranty, guarantee or assurances are made that this will work, be safe or last. In other words, proceed at your own risk!** ###

# Parts #
Parts list and information:
http://code.google.com/p/open-evse/wiki/75AOpenEVSE

This project used-
  * Leviton 75A J1772 (discontinued) http://store.leviton.com/Electric-Vehicle-Charge-Connector-A2055-PEV/dp/B009UCEXYI#.UPj3weicxgI
  * Project box- http://www.digikey.com/product-detail/e ... -ND/387065
  * Metal mounting plate- http://www.digikey.com/product-detail/en/NBX-10985/NBX-10985-ND/439529
  * (4) Bolts/lock nuts- #10, ¾” long
  * (2) Bolts/lock nuts/washers- #4, ½” long
  * (4) Bolts/lock nuts- #4, 5/8” long
  * (4) Bolts/plastic nuts- #4, 1-1/4” long
  * Hookup wire- 18AWG, 300V, 90C, stranded (largest gauge that fits in the small screw downs).
  * Strain Relief- http://www.grainger.com/Grainger/HUBBELL-WIRING-DEVICEKELLEMS-Cord-Connector-2DPD9?Pid=search

# Notes #
  1. Current Transformer- Component listed is too small. Needed to squeeze the 6AWG wires into oblong shape to fit them through but it is very tight fit. A 11/16” hole diameter or larger is required.
  1. This project used a smaller box than listed on the “Parts List” link. This necessitated cutting a hole in the metal partition to close over the Contactor.
  1. A larger strain relief collar for the J1772 cable may better. It is a tight fit but doable.

## Changes for assembling the OpenEVSE Plus Version 2- ##
  1. Version 2 has three connections for the Relay Coil. This project has one DPST relay using the Relay 1, 12VDC and the Relay Common connections.
  1. The Relay 2, 12VDC connection is used if your design has two SPST relays. The second relay connects to the Relay Common as well. Using 2 relays allows the self tests to run one leg at a time avoiding powering the J1772 handle during the test. Also, power can be removed from a leg if there is a stuck relay.
  1. There is a row of three 0.1” pins next to the Relay connections. The two pins closest to the edge of the board are for the CT Coil. They are not polarized.

# A. Assemble Components on the Mounting Plate #
  1. Mark the hole positions on the mounting plate from a template or from your choice of component locations.
    * ![http://imageshack.us/a/img825/9940/1mountingplateimg0538.jpg](http://imageshack.us/a/img825/9940/1mountingplateimg0538.jpg)
  1. Punch starting holes at those locations.
  1. Drill holes: 1/8” for the #4 bolts; 3/16” for the #10 bolts; 11/64” for the #8 bolt that came with the Ground bar.
  1. File the holes smooth on both surfaces.
    * ![http://imageshack.us/a/img832/523/2componentplacementimg0.jpg](http://imageshack.us/a/img832/523/2componentplacementimg0.jpg)
  1. Mount the components with the lock nuts on the back (bottom).
    * The Contactor was centered horizontally, 2 ½” below top ot the box. Use four  3/4”,  #10 bolts.
    * The Relay was placed at the bottom right corner with the two coil lugs towards the EVSE Plus board. Use two 1/2”, #4 bolts with washers.
    * ![http://imageshack.us/a/img341/405/3componentmountingimg06.jpg](http://imageshack.us/a/img341/405/3componentmountingimg06.jpg)
    * The EVSE board was placed at the bottom right corner, oriented as shown in Photo 1. Insert 1/4” stand offs between the EVSE/Power supply board and the mounting plate. Use four 5/8”, #4 bolts.
    * The ground bar was positioned between the Relay and the Contactor. Use the #8 bolt provided and a lock nut.
  1. Check that the mounting plate, with components, fits in the box with no conflicts. If the nuts or bolts keep the mounting plate from seating, shorten the bolts or file the nub that interferes.
# B. Wiring the Open EVSE Plus Board #

Version 1

![http://imageshack.us/a/img40/5868/openevseplus.jpg](http://imageshack.us/a/img40/5868/openevseplus.jpg)

Version 2

![http://imageshack.us/a/img196/7398/5openevseplusv2img0527.jpg](http://imageshack.us/a/img196/7398/5openevseplusv2img0527.jpg)

## Notes: ##
  1. The following measurements are those used for this project. Depending on the components and design, your measurements may be very different.
  1. When connecting the stranded wire, be sure no stray strands of wire are outside the connector.
  1. All the following use the 18 gauge stranded hook-up wire.
    * Strip the wire:
      * 3/8” for the .250 Quick Connects.
      * 1/4” for the .187 Quick Connects.
      * 1/8” for the larger blue screw downs.
      * 3/32” for the smaller blue screw downs.
      * 1/4” for the Ground Bar.
**[If soldering the current sensor directly to the pins, do now (See diagram in the J1772 Plug section).**
  1. Strip the end of the wires connected to the Coil. Tin.
  1. Tin the 2 CT Coil pins on the EVSE board.
  1. Put shrink wrap over each wire.
  1. Solder the wires to the pins. These connections are not polarized.
  1. Place the shrink wrap over the exposed metal and heat with a hair dryer.]

### EVSE Ground: ###
![http://imageshack.us/a/img716/3893/6openevsegroundimg0613.jpg](http://imageshack.us/a/img716/3893/6openevsegroundimg0613.jpg)
  1. Cut a 3-1/4” length of the green wire.
  1. Strip one end 1/4”; the other end 1/8”.
  1. Connect the 1/8” end to the blue screw down marked “ground” (photo ?). Tighten securely.
  1. Connect the 1/4” end to the ground bar. Tighten securely.

### Relay Coil: ###
![http://imageshack.us/a/img221/9462/7relaycoilwiresimg0542.jpg](http://imageshack.us/a/img221/9462/7relaycoilwiresimg0542.jpg)
  1. Cut a 5-1/2" length, each, of the Gray and the Violet wire. Any color other than black red, white or green is fine.
  1. Strip one end of each wire 1/4”; the other end 3/32”
  1. Crimp a .187” Quick Connect (red) on the end of each wire that was stripped 1/4”.
  1. Twist the wires together if desired. Be sure to leave enough free length at each to reach the connection points.
    * ![http://imageshack.us/a/img40/6199/8relaywiredimg0620img06.jpg](http://imageshack.us/a/img40/6199/8relaywiredimg0620img06.jpg)
  1. Connect the 3/32” stripped end of one wire to “Relay 1, 12V DC” and the stripped end of the other wire to “Relay Common” on the EVSE Plus v2 board. These connections are not polarized.
  1. Attach the .187” Quick Connects (red) of the Relay Coil 12V wires to the Relay coil lugs (photo ?). These connections are not polarized.
### AC Line 2 to Relay and Contactor Coil ###
![http://imageshack.us/a/img707/9536/9contactorrelaycoilredi.jpg](http://imageshack.us/a/img707/9536/9contactorrelaycoilredi.jpg)
  1. Cut two 13” lengths of the Red wire.
  1. Strip both ends of each 3/8”.
  1. Crimp a .250” Quick Connect (red) on all four ends.
  1. Twist the wires together if desired. Mark the Quick Connects of one wire for identification. Be sure to leave enough free length at each end to reach the connection points.
  1. Attach one wire to the input lug on the Relay. The other end attaches to a lug of 5L3 on the Contactor.
  1. Attach the other wire to the output lug on the Relay. The other end attaches to the Coil lug underneath 5L3 on the Contactor.

### AC Line 1 Contactor Coil ###
![http://imageshack.us/a/img96/6506/10contactortocoilblacki.jpg](http://imageshack.us/a/img96/6506/10contactortocoilblacki.jpg)
  1. Cut a 3-3/4” length of the Black wire.
  1. Strip both ends of 3/8”.
  1. Crimp a .250” Quick Connect (red) on both ends.
  1. Attach one end to a lug of 1L1 on the Contactor.
  1. The other end attaches to the Coil lug underneath 1L1 on the Contactor.
### AC Line 1 and 2 ###
![http://imageshack.us/a/img809/3120/11contactortoopenevseim.jpg](http://imageshack.us/a/img809/3120/11contactortoopenevseim.jpg)
  1. Cut a 12" length of the Black wire and a 13-1/2” length of the Red wire.
  1. Strip one end of each 3/8”.
  1. Crimp a .250” Quick Connect (red) on those ends.
  1. Strip the other end of each 1/8”.
  1. Twist the wires together if desired. Be sure to leave enough free length at each end to reach the connection points.
  1. Connect the stripped end of the Black wire to blue screw down for AC Line 1. Tighten securely.
  1. Connect the stripped end of the Red wire to the blue screw down for AC Line 2. Tighten securely.
  1. Attach the Quick Connect of the Black wire to a lug of 1L1 on the Contactor.
  1. Attach the Quick Connect of the Red wire to a lug of 5L3 on the Contactor.
![http://imageshack.us/a/img59/9813/12contactorinputwiringi.jpg](http://imageshack.us/a/img59/9813/12contactorinputwiringi.jpg)
### AC Test 1 and 2 ###
![http://imageshack.us/a/img259/7429/13contactoropenevserela.jpg](http://imageshack.us/a/img259/7429/13contactoropenevserela.jpg)
  1. Cut a 5-3/8" length of the Black wire and a 7-3/8” length of the Red wire.
  1. Strip one end of each 3/8”.
  1. Crimp a .250” Quick Connect (red) on those ends.
  1. Strip the other end of each 1/8”.
  1. Twist the wires together if desired. Be sure to leave enough free length at each end to reach the connection points.
  1. Connect the stripped end of the Black wire to blue screw down for AC Test 1. Tighten securely.
  1. Connect the stripped end of the Red wire to the blue screw down for AC Test 2. Tighten securely.
  1. Attach the Quick Connect of the Black wire to a lug of 2T1 on the Contactor.
  1. Attach the Quick Connect of the Red wire to a lug of 6T3 on the Contactor.
    * ![http://imageshack.us/a/img35/1213/14outputimg0659.jpg](http://imageshack.us/a/img35/1213/14outputimg0659.jpg)
    * ![http://imageshack.us/a/img197/7213/15completecomponentwiri.jpg](http://imageshack.us/a/img197/7213/15completecomponentwiri.jpg)
  1. Install connector to the Current Transformer wires or solder directly to the 0.1" pins on the OpenEVSE Board.
    * **If using a 0.1” pin female connector for the Current Transformer-**
      * a.	Strip the end of both wires.
      * b.	Crimp each wire to a female metal pin.
      * c.	Insert each female pin into the plastic housing until it clicks.
      * ![http://imageshack.us/a/img268/1192/16ctwireassemblyimg0668.jpg](http://imageshack.us/a/img268/1192/16ctwireassemblyimg0668.jpg)
    * **If the wire of the Current Transformer is too large for the 0.1” pin connector:**
      * a.	Strip the end of both wires. Tin.
      * b.	Strip the end of two smaller wires with the 0.1” female metal pins on the other end. Tin.
      * c.	Solder each wire of the Current Transformer to a smaller wire.
      * d.	Slip shrink wrap over the exposed metal and heat with a hair dryer.
      * e.	Insert each female pin into the plastic housing until it clicks.
      * ![http://imageshack.us/a/img153/8716/17ctconnectionimg0679.jpg](http://imageshack.us/a/img153/8716/17ctconnectionimg0679.jpg)
  1. Attach the Connector to the CT Coil pins on the EVSE board. These are not polarized. They are the two pins towards the outside edge of the EVSE Board labeled GFCI CT.

# C. Project Box #
![http://imageshack.us/a/img43/8679/18projectboximg0548.jpg](http://imageshack.us/a/img43/8679/18projectboximg0548.jpg)
  1. Determine the orientation of the box and the board. For this project the latches are on the right; AC power enters from the top  left side; J1772 wire enters at the center bottom.
  1. Hole size for the AC power is dependant on the size of conduit used.
  1. Drill a 1-1/2" hole in the bottom for the J1772 wire strain relief fitting. This project positioned it centered horizontally (3-1/16” from the side); 1-7/16” from the bottom.
  1. Clean and smooth the hole.
    * ![http://imageshack.us/a/img818/4466/19j1772holestrainrelief.jpg](http://imageshack.us/a/img818/4466/19j1772holestrainrelief.jpg)
  1. Install J1772 strain relief fitting through the hole. The rubber washer is on the outside. Secure with the lock nut on the inside of the box. Tighten securely.
    * ![http://imageshack.us/a/img5/355/20strainreliefinstalled.jpg](http://imageshack.us/a/img5/355/20strainreliefinstalled.jpg)
  1. Install the mounting plate with components in the box with the four screws provided. If the nuts or bolts keep the mounting plate from seating, shorten the bolts or file the nub that interferes.

# D. J1772 Cable #
  * ![http://imageshack.us/a/img545/7868/2180acableimg0707.jpg](http://imageshack.us/a/img545/7868/2180acableimg0707.jpg)
  1. Remove the end 6 inches of the J1772 line jacket (outside insulation). Be very careful not to nick the underlying insulation.
    * ![http://imageshack.us/a/img266/7863/2280acablewiresimg0716.jpg](http://imageshack.us/a/img266/7863/2280acablewiresimg0716.jpg)
  1. Slide the strain relief nut over the cable (facing the correct way!).
  1. Bend the blue wire 180º and insulate by covering with electric tape. It is not used.
  1. Shorten each Black and Red wire 3/4”.
  1. Strip the ends of the Black and Red wires from the J1772 plug 5/8”.
  1. Strip the Ground (green) wire 1/4”.
    * ![http://imageshack.us/a/img11/725/23j1772cableinstallingi.jpg](http://imageshack.us/a/img11/725/23j1772cableinstallingi.jpg)
  1. Run the 5 wires of the J1772 plug through the strain relief fitting with the jacket inserted all the way into the collar. Tighten securely.
    * ![http://imageshack.us/a/img441/331/24j1772cableinstalledim.jpg](http://imageshack.us/a/img441/331/24j1772cableinstalledim.jpg)
  1. Shorten the Pilot (orange) wire 3” so there is minimal extra length to its connection.
  1. Strip the Pilot (orange) wire 1/8”.
  1. Connect to the blue screw down marked “J1772 Pilot”.
    * ![http://imageshack.us/a/img13/5927/25pilotconnectionimg072.jpg](http://imageshack.us/a/img13/5927/25pilotconnectionimg072.jpg)
  1. Connect the Ground (green) wire to the ground bar. Tighten securely.
    * ![http://imageshack.us/a/img203/9468/26j1772groundimg0723.jpg](http://imageshack.us/a/img203/9468/26j1772groundimg0723.jpg)
  1. Feed the black and red wires through the Ferrite Core.
  1. Feed the black and red wires through the Current Transformer.
    * If using the smaller diameter Current Transformer, the wires need to be squeezed into an oblong shape using smooth jaw pliers. Be careful not to damage the insulation when using the pliers or sliding the Current Transformer over the wires.
    * ![http://imageshack.us/a/img856/5397/27poweroutctferriteimg0.jpg](http://imageshack.us/a/img856/5397/27poweroutctferriteimg0.jpg)
  1. Insert the Black AC power wire into the screw down of 2T1 on the Contactor and clamp down tightly. Be sure there are no stray wire strands outside the hole.
  1. Insert the White AC power wire into the screw down of 6T3 on the Contactor and clamp down tightly. Be sure there are no stray wire strands outside the hole.

If powered on 240V, the unit should now be functional unless the firmware on the EVSE board requires a display.

Test the unit as described at http://code.google.com/p/open-evse/wiki/EVSE_TESTING

# E. Metal Partition #
  * ![http://imageshack.us/a/img835/9707/28metalpartitionimg0553.jpg](http://imageshack.us/a/img835/9707/28metalpartitionimg0553.jpg)
  1. If using the small box with the metal partition, it is necessary to cut out a hole for the Contactor to fit through as well as the holes to mount the display and button.
  1. Measure the shape and size of the top of the Contactor. Allow room to avoid any electrical connections! Best to insulate the edges of this hole.
  1. Transfer these measurements to the metal partition plate.
  1. Be sure there is no possiblity of electrical contact with power connections on the Contactor!
    * ![http://imageshack.us/a/img12/7752/29faceplatecutoutimg075.jpg](http://imageshack.us/a/img12/7752/29faceplatecutoutimg075.jpg)
  1. Cut the hole for Contactor.
  1. Check for proper fit.
  1. Decide where the display will be placed.
  1. Measure the shape and size of the LCD display.
  1. Transfer these measurements to the metal partition plate.
  1. Cut hole for LCD display.
  1. Mark the positions of the four holes in the corners of the LCD display board.
    * ![http://imageshack.us/a/img542/7264/30faceplatecutoutbutton.jpg](http://imageshack.us/a/img542/7264/30faceplatecutoutbutton.jpg)
  1. Drill four 1/8” holes for mounting the display.
  1. Decide on the location of the button.
  1. Mark and drill a 5/8” hole there.
  1. Smooth all the edges of the metal partition with a file.
  1. Remove all metal dust and filings.
  1. Fit insulating grommet around the edges of the Contactor hole.
    * A grommet or frame may be placed around the display.
  1. Use 3/16” (or 1/4”) spacers between display and bottom of metal partition.

# F. Wiring the Shield and Momentary Button #

  1. Cut 4 wires ?”. Use green and, preferably, any colors other than black red, white.
  1. Connect wires as described in Adafruit Section.

### Select Button ###
  * ![http://imageshack.us/a/img534/5459/31buttonbackimg0010.jpg](http://imageshack.us/a/img534/5459/31buttonbackimg0010.jpg)
  1. Unscrew the nut on the button.
  1. Position the rubber gasket on the underside of the button.
  1. Insert the button and gasket through the prepared hole from the top.
  1. Screw the nut on the button securely.
  1. Cut a 7” length of green, gray and violet wire.
  1. Strip one end of each wire 1/4” the other end ?”.
  1. Tin the stripped end of each wire.
  1. Tin the LED+, LED-. C1 and NO1 lugs on the button.
    * ![http://imageshack.us/a/img845/4719/32buttonwiredimg0020.jpg](http://imageshack.us/a/img845/4719/32buttonwiredimg0020.jpg)
  1. Solder the green wire to the two lugs on the button marked LED- and C1 (common).
  1. Solder the gray wire to the lug on the button marked NO1(normally open).
  1. Solder the violet wire to the lug on the button marked LED+.
    * ![http://imageshack.us/a/img94/4377/33buttonwiredshrinkimg0.jpg](http://imageshack.us/a/img94/4377/33buttonwiredshrinkimg0.jpg)
  1. Cover exposed metal on each wire with shrink wrap and heat with a hair dryer.
  1. Strip the free end of each wire ?”.
  1. Solder the green wire to ground on the shield.
  1. Solder the gray wire to “select” position on the shield.
  1. Solder the violet wire to the +5V position on the shield.
    * ![http://imageshack.us/a/img197/4748/35buttonsolderpointsimg.jpg](http://imageshack.us/a/img197/4748/35buttonsolderpointsimg.jpg)
    * Alternative (Used for this project):
      1. solder these three wires to individual 0.1” pin connectors.
      1. solder 0.1” pins to the three locations listed above.

Wire managment clips may be used as desired.


### Display and Shield: Adafruit display ###

  1. Assemble the shield and the display using the Adafruit tutorial on the web at http://learn.adafruit.com/rgb-lcd-shield/parts-list.
    * **Except:**
      * a.	Only a select button and the potentiometer are being used for the Open EVSE with the current firmware
      * b.	Solder the potentiometer and select button (if wanted) on the reverse side of the shield!
      * c.	Do not install pins on the back of the shield for the Arduino connection.
      * d.	Skip Arduino connection instructions.
      * e.	You may slightly enlarge the holes used to hold the di splay and shield to better fit the bolts.
      * f.	Use 1/4” spacers and the bolts to hold the display and shield aligned before soldering the headers to the boards. Alternatively: 3/8” or 1/2” spacers if using a male and female header.
      * ![http://imageshack.us/a/img208/9277/34shielddisplaypinsolde.jpg](http://imageshack.us/a/img208/9277/34shielddisplaypinsolde.jpg)
  1. Strip the four wires connected to the 4 pin connector 1/16". Be especially careful not to nick the wire. Tin the wire ends.
  1. Attach the wires from the 4 pin connector to the shield at the following holes located between “adafruit!” and “Reset” (looking from above):
    * a.	Yellow wire- 3rd hole from the left. This project used violet.
    * b.	Green wire- 4th hole from the left.
    * c.	Connect the 4th hole from the left to the 5th hole from left with a solder bridge or a jumper.
    * d.	Red wire- 2nd hole from the right.
    * e.	Orange wire- the far right hole. This project used gray.
      * ![http://imageshack.us/a/img62/5615/36shieldsolderpointsimg.jpg](http://imageshack.us/a/img62/5615/36shieldsolderpointsimg.jpg)
  1. Use one of the following methods:
    * a.	Solder the wires directly to the holes in the board, entering from below.
    * b.	Solder the wires to two headers. (Used for this project)
      * Looking at the shield from the top:
        * i.	Solder a 1x3 0.1” header into the 3rd, 4th and 5th hole from the left, with the long pins down.
        * ii.	Solder a 1x2 0.1” header into the two holes on the far right, with the long pins down.
        * iii.	Put shrink wrap over each wire and solder each wire to the correct long pin.
        * iv.	Create a solder bridge between the short pins (on top) connected to the 4th and 5th hole from the left.
        * v.	Position the shrink wrap over the exposed metal. Heat to shrink.
    * c.	Solder the wires to two connectors that will plug into two headers.
      * i.	Solder the headers to the shield as described in the previous section.
      * ii.	Crimp a metal pin to each wire.
      * iii.	Orient the pin so the tab is towards the opening on the side of the connector. Insert each metal pin into the plastic housing until it clicks and won’t pull out.
      * iv.	Insert the yellow and green wire into one 2 pin connector.
      * v.	Insert the red and orange wire into the other 2 pin connector.
      * vi.	Attach the connectors to the pins on the shield so that the correct color wire contacts the correct pin.
  1. Use 3/4”, 1” or 1-1/4”, #4 bolts to connect the display and shield to the metal partition if using 3/16”, 1/4” or 1/2” spacers, respectively.
  1. Attach the 4 pin connector to the 4 pins at the bottom right of the EVSE board. Ground is the far right pin, going clockwise around the board.
  1. After powering the EVSE, adjust the potentiometer to get a clear display of the characters.
  1. The information and control available from the display is determined by the firmware version loaded on the EVSE board.