# Guide for Assembling a J1772, 30A OpenEVSE. #
> ## Using OpenEVSE Plus v1 (updated for v2) ##

# Usual Disclaimers #
This evaluation board/kit is intended for use for ENGINEERING DEVELOPMENT, DEMONSTRATION, OR EVALUATION PURPOSES ONLY and is not considered to be a finished end-product fit for general consumer use.

This project requires the use of tools and methods that can cause injury if not performed correctly. Any electrical work can be dangerous. This EVSE operates on 120 and 240Volts AC at up to 30 Amps. Improper assembly can cause damage to the car, fire, injury and/or death.
### **Do not attempt this project unless you are qualified.** ###

This guide is based on the workshops held in Cerritos, CA that occured during December, 2012, January and February 2013. This information was gleaned from garygid, chris1howell, glennD and others there. It is written by a novice to help people at a similar level. It assumes that one has the basic skills for soldering, wire work, working with electricity and general understanding of how to assemble things. Think about each step critically before doing it. Get advice from a knowledgeable person if something is not clear or seems questionable.
### **No warranty, guarantee or assurances are made that this will work, be safe or last. In other words, proceed at your own risk!** ###

## Parts list: ##
http://code.google.com/p/open-evse/wiki/OpenEVSE_Workshop?ts=1352676672&updated=OpenEVSE_Workshop

## Notes: ##

Hookup wire- 18AWG, 300V, 80C, stranded.

There are many opinions whether to use the Anderson connectors or not. Learn the pros and cons before deciding.

The strain relief collar for the J1772 cable can be the same size as the one used for the AC Line especially if not using the Anderson connectors.

Changes for assembling the OpenEVSE Plus Version 2-
  1. Version 2 has three connections for the Relay Coil. This project uses the Relay 1, 12VDC and the Relay Common connections.
  1. The Relay 2, 12VDC connection would be used if your design has two SPST relays instead of one DPST relay. The second relay would be connected to the Relay Common as well.
  1. There are three 0.1” pins in a row next to the connections. The two pins closest to the edge of the board are for the CT Coil. They are not polarized.

## A. Assemble Components on the Mounting Plate ##

  1. Mark the hole positions on the mounting plate from a template or from your choice of component locations.
  1. Punch starting holes at those locations.
  1. Drill holes 1/8". Ground bar hole is larger.
  1. File the holes smooth on both surfaces.
  1. Mount the components with the nuts on the back (bottom).
    1. The relay is at the top left corner with the four closely spaced lugs towards the bottom. Use washers on the bolts holding the relay.
    1. The EVSE board is at the top right corner, oriented as shown in Photo 1. Use ¼” stand offs between the EVSE/Power supply board and the mounting plate.
    1. The ground bar is positioned below the EVSE board.
    1. The four standoffs are set at the places marked by a black dot in Photo 1. Pre-thread the lock-washers on the same size metal bolts before to attaching them to the plastic standoffs. This will avoid stripping the plastic threads.
  1. Check that the mounting plate, with components, fits in the box with no conflicts.
    * If the nuts or bolts keep the mounting plate from seating, shorten the bolts or file the nub that interferes.

> ### ![http://imageshack.us/a/img694/1539/photo1openevse.jpg](http://imageshack.us/a/img694/1539/photo1openevse.jpg) ###

## B. Wiring the Open EVSE Plus Board ##

### Version 1 ###
> ![http://imageshack.us/a/img18/135/photo4openevse.jpg](http://imageshack.us/a/img18/135/photo4openevse.jpg)

### Version 2 ###
> ![http://imageshack.us/a/img824/2305/photo1aopenevse.jpg](http://imageshack.us/a/img824/2305/photo1aopenevse.jpg) Photo 4A- Chris Howell

  1. Cut 18 gauge stranded wire into 6 segments of the desired lengths. This project used:
    1. For AC Line 1and 2- Black 5", Red 4-1/8".
    1. For AC Test 1 and 2- Black 4-1/4", Red 4-1/16".
    1. For the Relay Coil 12V- Black 8-5/8", Red 8-3/8" (twisted together). It is better to use colors other than black red, white or green.
    * ![http://imageshack.us/a/img200/5706/photo5openevse.jpg](http://imageshack.us/a/img200/5706/photo5openevse.jpg)
  1. Strip one end of each wire 1/4". Crimp a ¼” Quick Connect (red) on that end (#15 crimp).
  1. Strip the other end 3/16” for the blue screw downs.
  1. Insert each wire into its blue screw down on the EVSE board and tighten.
  1. Attach the ¼” Quick Connects 18-22AWG (red) of the Relay Coil 12V wires to the Relay lugs labeled in photo 5. These connections are not polarized. **Version 2-** connect to Relay 1, 12V DC and Relay Common.
  * If soldering the current sensor directly to the pins, do now before installing the mounting plate in the box (See diagram in the J1772 Plug section).
    1. Strip the end of the wires connected to the Coil. Tin.
    1. Tin the 2 CT Coil pins on the EVSE board.
    1. Put shrink wrap over each wire.
    1. Solder the wires to the pins. These connections are not polarized.
    1. Push the shrink wrap over the exposed metal and heat with a hair dryer.

## C. Project Box ##

  1. Determine the orientation of the box and the board.
    * This project: The latches are on the right; AC power enters from top; J1772 wire enters at the center bottom with the fuses at the bottom left.
  1. Drill a 15/16" hole for the AC power strain relief fitting.
    * Drill hole off center so the ferrite core will fit between components.
    * ![http://imageshack.us/a/img545/5636/photo2openevse.jpg](http://imageshack.us/a/img545/5636/photo2openevse.jpg) Photo 2- **AC Line**
  1. Drill a 1.5" hole in the center of that side for the J1772 wire strain relief fitting.
  1. Drill two 1/2" holes for the fuse holders as shown below.
    * ![http://imageshack.us/a/img819/5875/photo3openevse.jpg](http://imageshack.us/a/img819/5875/photo3openevse.jpg) Photo 3- **Fuse Holders & J1772**
  1. Clean and smooth all of these holes.
  1. Attach the mounting plate with components to box with two screws.
    * If the nuts or bolts keep the mounting plate from seating, shorten the bolts or file the nub that interferes.
  1. Install AC cable and J1772 strain relief fittings. The rubber washer is on the outside.
  1. Install the bottom fuse holder. The rubber washer is on the outside. The upper fuse holder will be installed after soldering the bottom one.
> ![http://imageshack.us/a/img831/6589/photo6openevse.jpg](http://imageshack.us/a/img831/6589/photo6openevse.jpg)

## D. AC Line cable ##

  1. Cut the AC cable to desired length.
    * If the EVSE will be plugged in: Maximum length is18 inches per the Electrical Code.
    * If it will be hard wired: Skip these steps until the unit is installed. Go to **Section E. J1772 Plug**.
  1. Remove the last foot of the jacket (outside insulation) from the AC cable. Be careful not to nick the underlying insulation.
  1. Slide the strain relief nut over the cable. Feed all three wires through the fitting. Be sure the jacket extends into the fitting. Tighten.
  1. Run the two power lines (black and white) through the ferrite core.
  1. Cut a segment of the black and the white wire from the AC cable to the length needed to go from the side lug of the fuse assembly to the relay lug.
  1. Strip 3/8" of one end of these short wires and crimp each to a ¼” Quick Connect 10AWG (yellow) with piggy back (#45 crimp).
  1. Strip the other end of these short wires, 1/4". Tin the ends.
  1. Cut the green wire from the AC cable to the length needed to reach the ground bar. Strip the end 5/16". Insert it into the ground bar and tighten securely.
  1. The black and the white wires from the AC cable attach to the center lug of their respective fuse holder. Cut each to to length desired and strip each end 1/4". Tin.
  1. Tin both lugs of each fuse holder.
    * ![http://imageshack.us/a/img405/7996/photo7openevse.jpg](http://imageshack.us/a/img405/7996/photo7openevse.jpg)
  1. Slide shrink wrap over each wire. Move it as far away as possible from the soldering point.
    * A second shrink tube can be used to cover both of the same colored wires. Slide it over both wires before putting the shrink wrap on the individual wires.
  1. Solder either the black or white wire from the AC cable to the center lug of the bottom fuse holder.
  1. Solder the short wire of the same color to the small lug of the bottom fuse holder.
  1. Install the upper fuse holder and attach the remaining two wires in the same way.
  1. Position the shrink wrap over the exposed metal. Heat to shrink the tubing.
  1. Attach the black AC Line Quick Connect (red) to the piggy back of the yellow Quick Connect attached to the black wire. The bulge on the red Quick Connect should face away from the yellow Quick Connect.
  1. Attach the red AC Line Quick Connect (red) to the piggy back of the yellow Quick Connect attached to the white wire. The bulge on the red Quick Connect should face away from the yellow Quick Connect.
  1. Attach these yellow Quick Connects to the relay on AC Line 1 and 2 lugs, with the red Quick Connects facing away from the AC Test 1 & 2 lugs.
![http://imageshack.us/a/img534/2841/photo8openevse.jpg](http://imageshack.us/a/img534/2841/photo8openevse.jpg)
## E. J1772 Plug ##

+**There is disagreement whether to use Anderson Connectors.**

  1. Remove the end 15 inches of the J1772 line jacket (outside insulation). Be careful not to nick the underlying insulation.
  1. Cut the blue wire short, bend 180º and insulate by covering with electric tape. It is not used.
  1. Cut the remaining wires, measured from the stripped jacket insulation. This project used-
    1. Orange- 6cm
    1. Black- 10cm
    1. Red- 13cm (different than pictured)
    1. Green- 15cm. Must be the longest.
      * The length is staggered to disconnect the wires in the safest order if the J1772 cable is pulled out of the box.
  1. Strip the ends of the 4 wires from the J1772 plug and one end of each of the four short wires just cut.
  1. Crimp a metal Anderson connector to each of these stripped ends. Eight in total.
  1. Insert the metal connector into the plastic housing of the same color as the wire with the tab and round plastic bump down, opposite the metal plate. It should click and not pull out.
    * ![http://imageshack.us/a/img805/8892/photo9openevse.jpg](http://imageshack.us/a/img805/8892/photo9openevse.jpg) Photo 9- Chris Howell
  1. Slide the strain relief nut over the cable.
  1. Run the 5 wires of the J1772 plug through the strain relief collar in the box with the jacket inserted into the collar. Tighten.
  1. Run the black and red wire through the current sensor.
    * If using a connector for the current sensor-
      1. Strip the end of both wires. Tin.
      1. Crimp each wire to a metal pin.
      1. Insert each pin into the plastic housing until it clicks.
      1. Attach to the CT Coil pins on the EVSE board. These are not polarized. Version 2- these are the outside two pins labeled GFCI CT.
  1. Cut each short wire segment from the J1772 to the length needed to go from its Anderson connector to its connection point. See photo 10 below.
    * ![http://imageshack.us/a/img837/7981/photo10openevse.jpg](http://imageshack.us/a/img837/7981/photo10openevse.jpg)
    1. Green wire- strip the end 5/16" and insert into the ground bar (approximately 6" long).
    1. Orange wire- strip the end and connect to the Pilot screw-down on the EVSE board. (2-3/4" long)
    1. The black and the red wire attach to the lugs on the relay. Strip the ends 3/8", then crimp a yellow Quick Connect on each wire (black 4-3/8"; red 5-3/8" long).
  1. Attach each AC Test red Quick Connect to the yellow Quick Connect of the same color wire. The plastic bulge on the red Quick Connect facing away from the yellow Quick Connect.
  1. Attach the yellow Quick Connects to the AC Test 1 and 2 lugs on the relay with the red Quick Connects facing away from the AC Line lugs.
    * ![http://imageshack.us/a/img547/6241/photo11openevse.jpg](http://imageshack.us/a/img547/6241/photo11openevse.jpg) Photo 11- Chris Howell
  1. Cut the 18 gauge green stranded wire to the length needed to go from the EVSE board to the ground bar.
  1. Strip the ends of this green wire and attach one end to the screw down and the other to the ground bar. Tighten both.
  1. Install the two fuses.
  1. Test the unit as described at http://code.google.com/p/open-evse/wiki/EVSE_TESTING
  1. The unit should now be functional unless the firmware on the EVSE board requires a display.


![http://imageshack.us/a/img818/8144/photo12openevse.jpg](http://imageshack.us/a/img818/8144/photo12openevse.jpg)


![http://imageshack.us/a/img543/756/photo13openevse.jpg](http://imageshack.us/a/img543/756/photo13openevse.jpg) **Completed EVSE Wiring**
(Note: the ground wire is shown going through the ferrite core.
While not causing a problem, it should not go through the core.)

## F. Display and Shield: Adafruit display ##

  1. Assemble the shield and the display using the Adafruit tutorial on the web at http://learn.adafruit.com/rgb-lcd-shield/parts-list.
    * Except:
      1. Do not install pins on the back of the shield for the Arduino connection.
      1. Skip Arduino connection instructions.
      1. You may slightly enlarge the holes used to hold the display and shield to better fit the bolts.
      1. Use ¼” spacers and the bolts to hold the display and shield ali gned before soldering the headers to the boards.
      1. Only the select button and potentiometer are being used for the Open EVSE with the current firmware.
  1. Strip the four wires connected to the 4 pin connector 1/16". Be especially careful not to nick the wire. Tin the wire ends.
  1. Attach the wires from the 4 pin connector to the shield at the following holes located between “adafruit!” and “Reset” (looking from above):
    1. Yellow wire- 3rd hole from the left.
    1. Green wire- 4th hole from the left.
    1. Connect the 4th hole from the left to the 5th hole from left with a solder bridge or a jumper.
    1. Red wire- 2nd hole from the right.
    1. Orange wire- the far right hole.
      * ![http://imageshack.us/a/img571/1489/photo14openevse.jpg](http://imageshack.us/a/img571/1489/photo14openevse.jpg) Photo- MWolrich
      * Use one of the following methods:
      1. Solder the wires directly to the holes in the board, entering from below.
      1. Solder the wires to two headers.
        * Looking at the shield from the top:
          1. Solder a 1x3 0.1” header into the 3rd, 4th and 5th hole from the left, with the long pins down.
          1. Solder a 1x2 0.1” header into the two holes on the far right, with the long pins down.
          1. Put shrink wrap over each wire and solder each wire to the correct long pin.
          1. Create a solder bridge between the short pins (on top) connected to the 4th and 5th hole from the left.
          1. Position the shrink wrap over the exposed metal. Heat to shrink.
        * ![http://imageshack.us/a/img24/5451/photo15openevse.jpg](http://imageshack.us/a/img24/5451/photo15openevse.jpg) Photo 15
        * Underside of the Shield- Wires Soldered Directly to Headers (gray=yellow/ purple=green/ black=red/ white=orange)
      1. Solder the wires to two connectors that will plug into two headers.
        1. Solder the headers to the shield as described in the previous section.
        1. Crimp a metal pin to each wire.
        1. Orient the pin so the tab is towards the opening on the side of the connector. Insert each metal pin into the plastic housing until it clicks and won’t pull out.
        1. Insert the yellow and green wire into one 2 pin connector.
        1. Insert the red and orange wire into the other 2 pin connector.
        1. Attach the connectors to the pins on the shield so that the correct color wire contacts the correct pin.
  1. Use bolts to connect the display to the standoffs.
  1. Attach the 4 pin connector to the 4 pins at the bottom right of the EVSE board. Ground is the far right pin, going clockwise around the board.
  1. After powering the EVSE, adjust the potentiometer to get a clear display of the characters.
  1. The information and control available from the display is determined by the firmware version loaded in the EVSE board.
  * Completed Unit (Note: Ground should not go through the ferrite core. Anderson Connectors are optional.)
> ![http://imageshack.us/a/img198/7221/photo16openevse.jpg](http://imageshack.us/a/img198/7221/photo16openevse.jpg) Photo 16
