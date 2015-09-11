# Introduction #

The Hydra is a special EVSE forked from the original design of OpenEVSE. As of version 4, there are two variants of the Hydra. The first variant is called the "splitter." It is equipped with a J1772 inlet and will allow sharing a EVSE (usually a public one) with two vehicles. The other variant is the "standalone" or "EVSE" variant. Instead of an inlet, it is equipped with a hardwired or plug-in 208/220/240 VAC power circuit. It replaces the inlet handling circuitry with a GFI and a real-time clock with an event system.

Version four makes some fundamental changes in how the Hydra is constructed. Like OpenEVSE II, Hydra v4 consists of two boards. The first is a logic/display board. It is this board that differs depending on whether you have the standalone or splitter variant. It has all of the low-voltage signaling and monitoring systems and the microcontroller and display. It is connected with an FFC to the second board, the HV/Power board. That board has all of the high voltage monitoring circuitry, the AC/DC primary power supply and the necessary isolation and conditioning circuitry to interface with the logic board.

Both boards are the same physical size, and the intention is that you mount the AC board directly underneath the logic/display board, with 1/4" standoffs between the chassis mounting plate and the AC board, and then anywhere from 1 to 2" standoffs between the AC board and the logic/display board.

Because the incoming AC power must be fed to two contactors, an HV distribution block is required to allow the high current wiring to be safely divided. In addition, there are two two-pole 208/240 volt contactors to turn the power on and off to each vehicle. Each vehicle also has an ammeter current transformer. The standalone variant also has a GFI current transformer, while the splitter variant instead has a J1772 inlet (the standalone variant lacks a GFI because the host EVSE will have one already).

The AC board has five two-pin screw terminals. Each is intended to accept 22 gauge wire terminated in .25" QD female terminals, which then get attached to the two contactors. The first screw terminal is connected to one of the contactors on the line side (that is, the side connected to the HV distribution block). It doesn't matter which contactor is used, but the "A" side is closest. This is intended to supply the AC board with power. Each car also has a pair of terminals, one pair for the contactor coil and one pair for the contactor load side terminals. The contactor coil terminals are used to power the contactor to close it, turning the vehicle power on. The load-side terminals, marked "relay test" are used to detect whether or not AC power is being supplied to the vehicle, and to perform the ground impedance test.

The logic/display board has two screw terminals for each vehicle. One is for the ammeter CT, and the other is for the J1772 pilot line and (for the splitter variant only) the J1772 proximity line. Each variant also has one additional screw terminal. For the splitter variant, the screw terminal is for the inlet pilot and proximity lines. For the standalone variant, it's for the GFCI coil and the GFI test line.

The logic/display boards also have a 6 pin SIP header, which is an FTDI compatible serial interface for logging or other expansion use. They also have a 3x2 DIP socket, which is the AVR ISP terminal for reprogramming the controller. There's also a 3 pin terminal for the user interface button, a trimmer resistor for the LCD contrast and for the standalone variant, a battery clip for the real-time clock backup battery.


# Details #

![http://www.kfu.com/~nsayer/hydra/Hydra_wiring-EVSE.png](http://www.kfu.com/~nsayer/hydra/Hydra_wiring-EVSE.png)

Chassis wiring for the standalone variant

![http://www.kfu.com/~nsayer/hydra/Hydra_wiring-splitter.png](http://www.kfu.com/~nsayer/hydra/Hydra_wiring-splitter.png)

Chassis wiring for the splitter variant

The recommended HV bus module is the Cooper Bussmann 16220-2. This has a single line-side terminal per pole large enough to accept 2/0 gauge wire, and four load-side terminals that will accept all the way up to 4 gauge wire. It's rated for 175 amps, which is more than enough for any reasonable EVSE.

The recommended contactors are either Dayton 6GNV0 or the Packard C240C. Both are good for outlet currents up to 40A (their ratings are listed as 40A for inductive and 50A for resistive loads. EVSE service qualifies as resistive, but given that EVSEs are a continuous load, taking the lower number would be conservative engineering).

The recommended current transformers are from CR Magnetics. The ammeter coil is CR8420-1000 and is good for designs up to 50A, and the GFI coil is CR8420-1000G (yes, the two are different).

For J1772 cable/plug sets, your choice is dictated by the maximum design current you wish to support per vehicle (keeping in mind that the lowest current rating in the path will dictate the maximum). Also, if you're building the splitter variant, you must insure your choice of cable/plug sets include a proximity line. The proximity line is often left out, as most EVSEs don't need or use it. But the splitter must be able to communicate an inlet proximity transition to the vehicles should it occur.

If you're building the splitter variant, then your choice of J1772 inlet will constrain the maximum combined current for your Hydra. This is enforced separately by the firmware to insure that the inlet is not pushed beyond its rating.

Lastly, the choice of wire used for the high current paths will also have an impact on the maximum current rating of your Hydra. Be sure that the combination of wire gauge and insulation temperature for all of the wiring carrying charge current to the vehicles is rated for at least as much current as your design rating. For 40A designs, 8 gauge wire with 90 degree insulation is recommended.

You'll also need a user interface button. The recommended button is available from either AdaFruit or the OpenEVSE store. It's a waterproof 16mm lit metal momentary pushbutton.

## Assembling the 'Quick Kit' boards ##

If you've purchased the 'Quick Kit', then you will have two boards with all of the surface mount components pre-installed and the controller pre-programmed. You will simply need to add all of the through-hole components to complete assembly.

### AC board ###

For the AC board, all components will mount on the component side of the board. You will find:

  * 3 150K 1/2W flame-proof resistors. Outside of North America, one of these will be replaced by a 300K one.
  * 2 500 mA slow-blow fuses
  * 2 1A quick-blow fuses
  * 5 2 pole large screw terminals
  * 1 AC/DC power supply module
  * 1 FFC connector
  * 1 PC mount QD terminal
  * 1 120 µF electrolytic capacitor
  * 1 4.7 µF 400V electrolytic capacitor

When installing the capacitors, pay close attention to the polarization markings on the board and cap. Do not install them backwards!

If you are outside of North America, then the middle 1/2 watt resistor is the one that should be changed to 300K. DO NOT use 150K for that resistor if you are going to power your Hydra from 220V hot-neutral circuits! 150K is ONLY for use when the voltage between hot and ground is 120V, as is the case with North American 208/240V or 120V circuits.

Note that there are two types of fuses. Do not confuse them or they will blow immediately when power is applied. The slow-blow fuses are for the AC/DC power module, and the quick-blow fuses are for the contactor switching triacs. Insure the fuses are flat once they're soldered into place.

When installing the ground terminal, flood the top of the pad with solder and insure that both the pad and the tab are well wetted. Hold the terminal straight with a pair of needle-nose pliers while soldering it. Then turn the board over and solder each pin to the bottom.

When installing the FFC connector, make sure that the opening for the cable faces the edge of the board. Do not install the FFC connector backwards.

When installing the screw terminal blocks, make sure the wire openings face the outside edge of the board.

The power supply module should only fit into the board in one orientation. Insure it is flat against the board before soldering all the pins.

### logic/display board ###

  * 2 burden resistors. Values depend on the ammeter CT and design current.
  * 2 small (2.54mm) 2 pin screw terminals
  * 2 large (3.0mm) 2 pin (standalone variant) or 3 pin (splitter variant) screw terminals
  * 1 large (3.0mm) 3 pin screw terminal
  * 1 PC mount trimmer resistor
  * 1 6 pin SIP header
  * 1 2x3 pin shrouded DIP header
  * 1 3 pin SIP header
  * 1 18 pin SIP header
  * 1 RGB backlit 80x36mm LCD display module
  * 4 2-56 5/8" nylon bolts
  * 4 1/8" #4 nylon standoffs
  * 4 2-56 nylon nuts

For the logic/display board, most of the added components attach to the **opposite** side of the board as all of the surface mount components. When mounted in the chassis, the intent is for the component side of the board to face downwards and the opposite side, with the display and connectors, to be visible.

First, mount the two through-hole burden resistors for the ammeter circuits. These resistors are through-hole so that you can easily substitute values suitable for the ammeter coil you select. If you're using the recommended CR Magnetics CR8420-1000 coils, then the recommended values are either 47 ohms for designs up to 50A or 27 ohms for designs of 30A or less (per vehicle). Note that if you alter these values, then you'll need to alter the appropriate macro values in the firmware source code and recompile and upload the firmware. Mount the two resistors on the **same** side of the board as the surface mount components.

Next, mount the FFC cable terminal. Make sure the opening for the FFC faces the edge of the board. Do not install it backwards. The FFC cable terminal mounts on the **same** side of the board as the surface mount components.

Next, mount the SIP and DIP headers for the AVR ISP, FTDI and button connectors. All three of them are mounted on the **opposite** side of the board from the surface mount components. Solder one pin first, then flip the board over and check that the connectors are straight and flush before soldering the remaining pins.

Next, mount the trimmer resistor for the LCD contrast. It mounts on the **opposite** side of the board from the surface mount components.

Next, mount all of the screw terminals. The two smaller two-pin terminals are for the ammeter current transformers. If you have the standalone variant, then the pilot terminals are larger two-pin units. For the splitter variant, they are 3 pins. Lastly, there is a three pin terminal for either the GFI (standalone variant) or the inlet signals (splitter variant). Make sure that all of the terminals are mounted so that the wire inlets face the edge of the board. All of them mount on the **opposite** side of the board from the surface mount components.

Lastly, mount the display. To do so, place the 18 pin SIP header in its place on the **opposite** side of the board from the surface mount components, but do not solder it yet. Set the display on top of the connector, but again - do not solder. Place a 1/8" nylon #4 standoff under each corner of the display and pass a 2-56 nylon bolt through the display, standoff and logic board. Secure with a 2-56 nylon nut. Once the display is physically secured, then solder the SIP header to both the display and the logic board.

If you wish to test the boards at this point, then connect the two boards with the FFC cable. To insert the FFC cable, pull the clip out and upwards. Insert the cable with the pins facing downwards (away from the direction of the swing of the clip). Make sure the cable is fully inserted and straight, then push the clip down and in until it clicks into place. The cable should be snug enough to resist moderate tension.

Make sure that the AC board is resting on a non-conductive surface and cannot touch anything else. Adjust the LCD contrast knob to approximately 85% of its rotation range one direction or the other. Connect a line cord temporarily to the AC in terminals. **USE EXTREME CAUTION** and briefly apply power. You should see the power LED on the AC board light up, and the LCD display briefly show a banner with the firmware version and then an indication of a self test failure (this is to be expected, as the chassis wiring is not complete). If you see the backlight light up white, then red, but no text, then disconnect power and rotate the LCD contrast knob to 85% of its rotational range in the opposite direction and try again.

## Chassis assembly ##

The recommended chassis for the Hydra is the Polycase WC-35 (aka the Bud Industries PN-1335-C), with the WX-34 internal mounting panel accessory (Bud PNX-91435). You will also need two CG-16 (Bud NG-9516) cable glands for the J1772 cables (possibly CG-17 - Bud NG-9517 - if your J1772 cables are particularly large). If you're building the standalone variant, you'll need another CG-16 or CG-17 cable gland for the AC input cable as well as either a suitable plug or hard-wiring kit. If you're building the splitter variant, you'll need a J1772 inlet.

If you're building the splitter variant, examine your inlet. If you do not see a resistor mounted between the ground pin and the proximity pin, then you must find the PROX\_RES solder jumper on the component side of the logic board and use a bead of solder to short it closed.

If you're building the splitter variant, you have two choices as to how it will be powered:

The first option is for the Hydra to be powered by the host EVSE. In this case, the INT\_PWR jumper should be soldered closed (this is the default).

The other option is for the Hydra to be separately powered. In this configuration, the Hydra will switch the host EVSE on and off in response to power demand from either vehicle. If you wish to build your Hydra for this configuration, then you will provide separate AC line power to the AC input jack on the AC board. Whatever voltage you use for this auxiliary power must match the voltage rating of the coils of the two contactors you use. If you pick this option, then remove the solder from the INT\_PWR jumper so that it is open. Your Hydra will cycle the inlet between states B and C depending on whether either or both of the vehicles wishes to charge.

If you're building the standalone variant, then you must construct the GFI coil system. The GFI system includes a test wire, which is simply a piece of 22 gauge wire that takes 3 or 4 wraps through the center of the GFI coil. This wire connects between the GFI TEST terminal and ground. The two GFI coil wires connect between the GFI terminal and ground. The recommended procedure is to solder two extension wires - one black, one green - onto the GFI coil wires. Attach the GFI test wire (red) to the green terminal, then wrap it around/through the coil 3 or 4 times and bring it back. Use heat-shrink tubing or electrical tape to insulate the soldered connections. The green wire is ground, the black wire is the GFI wire, and the red wire is the GFI TEST wire.

To begin assembly, drill the four holes in the chassis for the user interface button, the two J1772 cable glands, and either the J1772 inlet or the AC cable gland. Pick one of the two short sides of the chassis to be the top. That side will be where the user interface button is. The opposite short side will be where either the J1772 inlet or AC cable is. The two long sides will house the J1772 cable glands, near the bottom edge. Drill a 5/8 inch hole in the center of the top side for the button. Measure the outer diameter of the J1772 cable glands, divide that by two and add a quarter inch. Measure that distance up from the bottom "rib" on each long side of the chassis. Draw a line perpendicular to the bottom of the chassis at that distance. Along that line, half way between the top and bottom of the chassis, drill the appropriate sized hole for the cable glands. Lastly, if you're building the standalone variant, drill the appropriate hole for the AC input cable gland centered in the bottom side. If you're building the splitter variant, then position the inlet as close to the top edge of the chassis as you can without going over. Even if you do this correctly, you may find that either the inlet or its mounting hardware impinges on the mounting plate. If it does, you'll need to trim relief notches in the mounting plate.

Next, lay out all of the chassis mounted components on the mounting plate in the locations where they will be attached. Use a marker to mark the mounting holes on the plate. For the board and the ground bus, drill 1/8" holes. For the contactors and the HV distribution module, use 9/16" holes (for 6-32 nuts and bolts). The PC boards will mount in the top half of the chassis, and the HV module will mount in the bottom middle, flanked on either side by the contactors. Make sure that the contactors are mounted closer to the center of the chassis to allow room below the contactors for the J1772 cables as they pass through their cable glands. Similarly, make sure to leave enough room below the HV distribution module for either the inlet or the AC cable, its cable gland and the GFI coil.

Mount the distribution module first, insuring that the line side faces the bottom edge of the chassis (relative to the logic board). Mount the two contactors next. The contactors may have an indication of which side is line or load. If so, then you should mount the line side at the top end. The high current path will go from the bottom center, where either the J1772 inlet of the AC cable gland is, up through the HV distribution block, then splitting in half to curve around to the top side of each contactor, through the contactor, and then to the J1772 cables near the bottom of each side of the chassis.

Mount the ground block near the bottom of the mounting plate. Make sure it's out of the way of everything else nearby and that you can easily route the ground wires from the inlet or AC cable and each J1772 cable. The AC board will be grounded through its standoffs and the mounting plate, assuming that both are conductive. If your mounting plate is non-conductive, then you'll need to run a ground wire from the ground terminal to the grounding block. 22 gauge wire is sufficient.

Next, mount the 1/4" standoffs for the AC board. Attach the FFC cable to the AC board before mounting it to the standoffs. Lay the AC board on its standoffs and screw the taller standoffs in, securing the AC board in position.

Next, install the mounting plate in the chassis.

Prepare 5 pairs of 22 gauge wires for the AC board wiring by twisting each pair (red and black) into a loose braid. Strip 1/8" off each wire on one end, and 3/8" off each wire on the other end and attach a female QD terminal. Connect one pair to each contactor on the load side, one pair to each contactor on the coil terminals, and the last pair on the car A contactor's line side. Screw the other end of each wire into the appropriate terminals on the AC board. If you're outside of North America or if you plan on powering the Hydra with 120V, then be sure to connect the hot side of each pair to the terminal marked "H" and the neutral side to the terminal marked "N". For those terminals not marked, or if you're using North American split-phase 208/240V power, then it doesn't matter which is which.

Prepare the user interface button by soldering wires from a 3 pin SIP female connector. The middle wire should be red, the outer two black and green. The button should have 5 terminals. They'll be labeled +, -, C or COM, NO and NC. Solder the red wire to +, the black wire to NO and connect the green wire to both - and C (or COM).

Install the user interface button in the hole in the top center of the chassis. Route the wires over the AC board. You'll attach the connector to the logic/display board later.

Attach the other end of the FFC cable to the logic/display board. Lay the logic/display board on top of the long standoffs and secure it with 4 4-40 1/4" screws. Plug in the button connector, taking careful note of which direction it goes (the black wire is SW, the green wire is GND).

Prepare the ammeter current transformers, if required, by soldering extension wires to each lead and insulating them with heat-shrink tubing or electrical tape. Attach each to the ammeter terminals for each car and place them temporarily near the line side of each contactor.

Cut four pieces of large gauge wire (at least as large as the J1772 cable hot lines), two red and two black. Connect one red and one black wire to each pole of each contactor. Pass one of the wires of each contactor through the appropriate ammeter CT and then connect each wire to the appropriate terminal on the load side of the HV distribution module. The two red wires should connect to the same pole of the distribution block and the two black wires should connect to the opposite pole. Outside North America, the red pole should be the hot, and the black pole the neutral.

For the standalone variant, install the AC input cable in its gland and the gland in the chassis. Run both of the two hot lines through the GFI coil and attach them to the appropriate terminals on the line side of the distribution block. Connect the ground wire to the ground block.

For the splitter variant, install the J1772 inlet in the bottom side of the chassis. Connect the two hot lines to the distribution block and the ground wire to the ground block. Route the pilot and proximity lines up to the inlet block on the logic/display board and connect the wires to the appropriate terminals (there is no connection necessary to the ground pin of the inlet terminal).

For each car, prepare its J1772 cable by installing it in a cable gland and installing the gland in the chassis. Route the two hot lines to the appropriate contactor and the ground to the ground block. Route the pilot wire up to the logic/display board and connect it to the pilot terminal. Do the same for the proximity line if you're building the splitter variant. There is no connection necessary to the ground terminal of the car pilot/proximity terminal.

Attach the lid to the chassis, making sure not to pinch any wires between it and the chassis. Your Hydra is now complete and ready for testing.

## Testing ##

For the standalone variant, connect the AC input cable to its power source and turn the breaker on. For the splitter variant, connect the host EVSE's J1772 cable to the inlet. If your splitter Hydra has separate power, connect that to a power source. You should see the LCD backlight start white, then turn green. If it turns red, then one of the self tests has failed and you must troubleshoot it.

If you're using the splitter variant, and the display comes up yellow, with "I:PAUSED" in the upper left corner, then that means that the host EVSE is not making an offer of power (that is, its pilot is not oscillating). If your splitter Hydra is not separately powered, then that is a paradox, since the host EVSE should not turn on and power the Hydra without offering a correct pilot. You should stop and troubleshoot at that point.

For the splitter variant, the upper left corner will indicate the number of amps being offered by the host EVSE. Assuming that this value is not higher than either the inlet or outlet ampacity restrictions in the firmware, then if you connect a single car at this point, it should be able to charge, and should itself be offered that same amount of current. It might be helpful to use an EVSimMark2 to observe this.

For the standalone variant, the upper left corner shows the time of day. Since the clock hasn't yet been set, it will be blank. To set the clock, check out the [User's Guide](https://code.google.com/p/open-evse/wiki/Hydra_EVSE#User's_guide) to learn how the menu system works. The menu system will also allow you to set the configured maximum current. **WARNING** You must never exceed 80% of the current rating of the circuit supplying power to your Hydra! The NEC and UL require a 20% circuit de-rating for EVSEs since they are a constant maximum current draw when operating. If you wish to charge at 40A, you must use a circuit and breaker rated for at least 50A.

Connect each J1772 car cable in turn to a vehicle and charge for 15 minutes. **Do not leave your Hydra unattended during this test!** As the car is charging, periodically feel the chassis and examine the wiring for any signs of heating. After the 15 minutes, disconnect power and quickly open the chassis and feel the wiring and contactors for elevated temperature. The wires will likely be warm, but if they are too hot to touch, then something is wrong and _must_ be corrected. This test should be repeated periodically during the service lifetime of the Hydra. Also, if during operation you see any signs of fog or smoke inside the chassis, or if any of the wiring changes color, that is a sign that unsafe temperature increases are taking place, and **must** be investigated and corrected. **DO NOT** reuse heat-damaged components!

# Links #
  * [EVSE logic/display board schematic](http://www.kfu.com/~nsayer/hydra/Hydra-EVSE-4_1.pdf)
  * [Splitter logic/display board schematic](http://www.kfu.com/~nsayer/hydra/Hydra-split-4_1.pdf)
  * [HV board schematic](http://www.kfu.com/~nsayer/hydra/Hydra-AC-4_2.pdf)