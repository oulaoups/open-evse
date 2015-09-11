# Introduction #

I decided to try my hand at designing a new version of OpenEVSE.

One of the hallmarks of my work on the Hydra has been the segregation of the HV wiring and control systems from the logic. I decided to make that the centerpiece of the design for OpenEVSE II.

It consists of two boards - an HV board and a logic / display board. There are three choices for the HV board. The first is a board with two DC relays mounted on it. It's similar to the OpenEVSE DIY 30A board. It's usable at L1 or L2, but only rated for 24A charging maximum. The second choice is the Contactor board. It will control an external line voltage powered contactor to turn the car power on and off. It has no limitation on charging current - that limitation is imposed by your  choice of contactor. However, the contactor coil will only work at one voltage, so that means it'll be useful for 208/240 volt charging only (in principle you could use a 120 volt contactor for an L1 contactor EVSE, but in practice, you would be unlikely to want to do so). The third variant is for external relays. It provides a 12vdc switched output for driving a relay, but like the contactor variant, the relay is supplied by the builder and is the limiting factor for current capacity. High current relays (with 12 vdc coils) are much more rare than contactors. However, if you can find one, the resulting design would be usable at both L1 and L2.

No voltages higher than 12 volts are present on the logic/display board. The HV + Relay board is designed to be as simple and safe as is possible for such a device. The two boards connect to one another with a "mezzanine" cable - a 10 pin FFC.

The firmware used is the same OpenEVSE firmware. Be sure to compile the firmware with the OPENEVSE\_2 macro defined. That will alter the code for compatibility.

# Details #

## Wiring ##

Wiring is almost the same as traditional OpenEVSE. The only changes are the addition of an optional ammeter CT coil and the mezzanine cable connecting the two boards.

![http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Relay.png](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Relay.png)
The wiring for the internal relay variant

![http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Ext_Relay.png](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Ext_Relay.png)
The wiring for the external relay variant

![http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Contactor.png](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Wiring_Contactor.png)
The wiring for the contactor or external relay variant

On the HV + Relay board, there are two SPST relays (not unlike the OpenEVSE DIY 30A board). QD terminals crimped onto the power and J1772 hot leads connect to these two relays. The PCB connections on the relays provide AC power and relay test signals to the rest of the board. _Both_ J1772 hot lines must pass through the GFI coil, and then (optionally) _one_ of the hot lines must pass through the ammeter coil.

The CT coil wiring, J1772 pilot line and ground connect to the logic/display board along with the mezzanine cable. Be sure the mezzanine cable is oriented the correct way - pin 1 must be connected to pin 1 on both ends! This means you must use a 10 pin 1 mm FFC cable with the "top/bottom" orientation. That means that the pins are exposed on opposite sides on each end. This effectively gives the cable a half-twist, which will connect pin 1 to pin 1 on the two boards.

A select button (the pinout of the 3 pin terminal is the same as on the OpenEVSE display board) connects to its terminal on the logic/display board.

A CR1220 battery in the battery clip will preserve the clock when power is disconnected.

## Assembling the quick kit ##

If you ordered your boards as a "quick kit" then you'll have received the two boards with all of the surface mount components installed, and a collection of through-hole components.

### Logic/display board ###

To complete the logic/display board, first install all of the remaining through-hole parts except the display. The display must be the last step, as it mounts on the solder side of the board and covers all of the solder positions for the other components. First install the 6 pin (2x3) DIP header in the ISP position on the board. Next, install the 4 pin SIP header in the i2c position. When installing SIP headers, insure that they're straight and flush and solder one pin. Turn the board over and check it once more for alignment, then solder the remaining pins. Install the 6 pin SIP header in the FTDI position. Lastly, the 3 pin SIP header in the SELECT position.

Next, install the mezzanine cable connector. When doing so, take careful note of the side of the connector that has the contacts. that side should go in the same direction as the arrow marker on the board. Do not install the mezzanine connector backwards!

Next, install the "Rb" - the ammeter burden resistor. This resistor should be chosen for the desired ampacity of your charging station and the specifications of your ammeter current transformer. The recommended value for the contactor variant is 27 ohms (up to 50A), and 47 ohms for the relay variant (up to 24A).

Next, install the 3 screw terminals. The larger 2 pin terminal is for the PILOT connector. The smaller 2 pin terminal is for the ammeter connector, and the 3 pin terminal is for the GFI CT. Insure that the openings for the screw terminal face the edge of the board and that the terminal rests flat against the board.

To install the display, set it on your work surface solder-side up and temporarily install the 18 pin SIP header on the solder side of the logic board. DO NOT solder it at this point. Temporarily mount the display on the pins. Again, do not solder yet. Lift each corner of the display and place a 3/8" standoff between the logic board and the display and thread a #4 bolt (from your chassis kit) through both, with the bolt head against the logic board. To make things easier, you might temporarily use 4 #4 nuts to hold the two boards together. Check again that the SIP header is positioned snugly against one of the two boards (it doesn't matter which) and that one pin is passing through each of the 18 positions on both boards. Most importantly, make sure that both boards are snugly resting against each of the four standoffs. Later, the #4 bolts will be used to secure both boards into the chassis, and the if the standoffs are not snug then the boards may bend unduly. Solder the SIP header to both boards.

If you used temporary nuts, then you can remove them at this point and attach the display to the lid of your chassis by screwing the four bolts into the chassis mounted standoffs. If your LCD has a clear plastic protective film, be sure to remove it first.

### HV boards ###

First, install the FFC connector for the mezzanine cable. Take careful note of the connector to locate the side which has the cable contacts. If you open the cable latch, the latch should swing away from the contacts. The side with the contacts should match the position of the arrowhead on the silkscreen. **Do not** install the FFC connector backwards!

Next, for the external relay or contactor variant, you'll find 3 dual screw terminal blocks. Install them in the AC in, relay test and either the relay or contactor blocks. For the contactor variant, there is an MOV that installs in two holes immediately adjacent to the contactor terminal.

Next, install the board-mounted QD grounding terminal. Use a lot of solder to flood the entire pad and thoroughly heat both the pad and the connector to insure a solid connection. While doing this, use a pair of needle-nose pliers to hold the connector straight.

Next, install the 3 1/2W flameproof resistors. For North American installations, all three will be 150K, but for 220V hot-neutral-ground systems (basically just about everywhere outside of North America), you must use a 300K resistor for the ground impedance test series resistor. DO NOT use 150K on 220V hot-neutral-ground electrical systems or you may burn out the current limiter! Note that 208/240V power in North America is hot-hot-ground, and each hot line is 120V to ground, so 150K **is** the correct value.

Next, install the fuses. If you have the contactor board, then you have three fuses. Two are slow-blow fuses intended for the power supply, and the third is a normal fuse for the contactor. Two of the fuses, therefore, should have similar color and markings and should be easy to distinguish. The oddball fuse should be oriented 90 degrees different from the other two. If you have the contactor board, you will also have a MOV. It will look somewhat like a ceramic capacitor, but will be thicker and likely blue. Install this in the two holes immediately adjacent to the contactor terminal.

Next, depending on which board you have, you will install either one or two electrolytic capacitors. If you have two, take careful note of which is which. The 120 µF cap is installed in the logic section, and the 4.7 µF 400V cap is installed in the HV section. **Be sure to carefully note the polarity of each**.

For the internal relay variant, install the two relays. They should only fit in one way. Hold each relay flat against the board and solder one of the smaller pins. Check the relays positioning and that it's flat against the board and solder the remaining pins. Note that there will be an unused hole that may not have a corresponding relay pin.

Lastly, install the power supply. It should only fit one way. Make sure it's flat against the board. Trim the pins after soldering them. They're a bit thick, so it takes some elbow grease.

If you wish to test the assembled boards, then connect the mezzanine cable between the two and temporarily attach a line voltage power cable to the AC input terminals. **USE EXTREME CAUTION** Make sure that the HV board is resting on an insulated surface and there is no possibility that it could contact **anything** else during the test. Apply power briefly and observe both boards. The power LED on the HV board should light and the display on the logic/display board should indicate the firmware version, and then show one ore more self-test failures. These failures are to be expected, as the remaining chassis wiring is not complete. Remove power before attempting to do any necessary troubleshooting.

## Construction ##

You will need

  * A complete logic/display board
  * A complete HV board - either the 30A relay, contactor or external relay board.
  * For the contactor or external relay HV board, you'll need an appropriate contactor or relay.
  * An OpenEVSE chassis (available from the OpenEVSE store - either the aluminum or polycarb variant)
  * A mezzanine cable (10 pin 1 mm FFC top/bottom ended)
  * A ground bus
  * A lit pushbutton (available from the OpenEVSE store)
  * A GFI current transformer (available from the OpenEVSE store - CR Magnetics 8420-1000G recommended)
  * An ammeter current transformer (available from the OpenEVSE store - CR Magnetics 8420-1000 recommended)
  * An AC cable
  * A J1772 cable / plug assembly

Note the mounting hole dimensions for each of the different HV boards:
  * For the contactor board, 2.4 x 2.2 inches
  * For the relay board, 3.2 x 2.7 inches
  * For the external relay board, 2.7 x 1.7 inches

Start with the (plastic or metal) mounting plate that came with the chassis. Mark the four corners of a square for the mounting holes for the HV board. You need to arrange the board so that it is out of the way of the other components that will be mounted on the mounting plate - specifically the relay or contactor (if applicable), the fuse block (again, if applicable) and the ground bus. Note as well that the UI button extends downwards from its position in the lid a fair distance. Do not place HV components on the mounting plate so that they will wind up too close to the button and it's terminals. Drill the holes with a 1/8" drill bit.

If you're going to use an external relay or contactor, then similarly mark and drill the appropriate mounting holes for it. Be sure to leave enough room around the contactor or relay to bend the AC and J1772 cables, including enough room to mount the two current transformers on the J1772 hot lines. Also, insure there's enough space for the QD terminals for the AC power, relay test and relay and/or contactor coil lines.

Attach the HV/Relay board to the mounting plate using the mounting hardware originally intended for the OpenEVSE v2 board using the newly drilled holes. Similarly, attach the relay or contactor (if applicable), the fuse block and the ground bus to the mounting plate using its intended hardware.

If your mounting plate is plastic, crimp a QD terminal onto a 12 gauge copper wire. Connect the QD terminal to the ground terminal on the HV board and the other end of the wire to the ground bus. If your mounting plate is metal, then you can skip this step as the metal mounting hardware should provide a sufficient electrical connection to ground via the mounting plate and ground bus.

Similarly, if your mounting plate is plastic and chassis is metal, crimp a spade or ring crimp terminal to a second 12 gauge wire and attach the loose end to the ground bus. The ring/spade terminal will go under one of the screws holding the panel into the chassis (this will ground the chassis. Do not omit this step if your chassis is metal! It is hazardous to leave a metal chassis ungrounded). If your chassis is plastic, then this step is not required.

Place the mounting plate in the chassis and screw down each corner using the supplied mounting hardware. Be sure to place the grounding ring/spade terminal under its intended screw, if applicable.

### Relay HV board steps ###

Prepare the AC cable by stripping 6 inches of its outer jacket and installing a cable gland. Trim the individual wires to the correct length and crimp a .25" QD terminal on each hot line. Connect the ground wire of the AC cable to the ground bus. Connect the hot line to the LINE terminal of one of the relays. Connect the neutral line to the LINE terminal of the other relay.

Prepare the J1772 cable by stripping 6 inches off the outer jacket. Locate and identify each wire - the two hots, the ground and the pilot. If your cable includes a proximity wire, trim it short to keep it out of the way. Install the cable into its cable gland and install the gland in its chassis hole. Estimate how long the two hots and ground must be to reach their destination. Be sure to leave room for the GFI over both hot lines and the ammeter coil over one of them. Cut the hot and ground wires to length. Install QD terminals on the hot wires. Screw the ground wire into the ground bus. Pass both hot lines through the GFI CT coil and one of the hot lines (it doesn't matter which) through the ammeter coil. Attach the QD terminals to the LOAD terminals on the relays. It doesn't matter which J1772 hot wire connects to which relay. Connect the ground wire to the ground bus. The pilot line will be attached to the logic/display board later.

### External relay HV board steps ###

The external relay HV board can drive either two SPST relays or a single DPST relay. In either case, the relay coils must be compatible with 12 VDC and draw no more than 400 mA total. This board is designed to be a direct replacement for the OpenEVSE v2 board, and can be used with the recommended fuse block for a maximum charge current of 24A.

Prepare two 22 gauge red and black wires. Trim 3/8" insulation off one end of each and 1/8" off the other end. Crimp a .25" QD terminal on the end of each wire trimmed to 3/8". Connect the QD terminals to the QD flanges on the load end of each fuse block. Connect the other end of each to the HV board's AC IN terminal.

If you're not using the recommended SPST relays, then you will need to drill new holes to place a DPST relay (the recommended model is a TE T92P7D22-12. If you're using the two recommended SPST relays, then prepare two 22 gauge wires by crimping two .187" female QD terminals on each, with enough wire between each to reach between the two relays and enough wire at one end to reach over to where the HV board will be installed. If you're using the DPST relay, then instead crimp a .25" QD terminal on one end of each of two 22 gauge wires. In either case, attach all of the appropriate QD terminals to the relay coils, leaving the free ends near where the HV board will be installed. If you're using two SPST relays, their coils must be wired in parallel.

Attach the relay wires to the relay terminal on the HV board.

Prepare the AC cable by stripping 6 inches of its outer jacket and installing a cable gland. Trim the individual wires to the correct length and connect the ground wire to the ground bus and the other two wires to each of the two line side terminals on the fuse block. Take two lengths of wire trimmed from the AC cable sized to reach from the load side of the fuse terminal to the line side of the relay(s). Trim 3/8" of insulation off each end of each wire. Crimp a QD terminal on one end of each wire. Install the QD terminals on the line sides of the relay(s). Screw the other end of the large wires into the load side of the fuse blocks, matching the colors with the AC input wires.

Strip 6 inches of jacket off of the end of your J1772 cable and identify each of the wires inside - the ground, two hot lines, and pilot. If your cable includes a proximity line, trim it short to keep it out of the way. Install a cable gland and install the gland in the chassis. Run each hot line through the GFI coil and one of them through the ammeter coil. Then trim 5/8" off of each hot line. Cut two red and black 6 inch 22 gauge wires and trim 3/8" of insulation off one end and 1/8" off the other end of each. Take one of the 22 gauge wires and one of the large J1772 cable hot wires (matching the colors) and insert them both into a .25" QD female crimp terminal and securely crimp the terminal into place. Connect the QD terminals to the load side of the relay(s), and connect the free end of the two 22 gauge wires to the "relay test" terminals on the HV board.

### Contactor HV board steps ###

Prepare the AC cable by stripping 6 inches of its outer jacket and installing a cable gland. Trim the individual wires to the correct length and connect one hot line of the AC cable to the contactor on the line side. Connect the ground wire of the AC cable to the ground bus.

Prepare the J1772 cable by stripping 6 inches off the outer jacket. Locate and identify each wire - the two hots, the ground and the pilot. If your cable includes a proximity wire, trim it short to keep it out of the way. Install the cable into its cable gland and install the gland in its chassis hole. Estimate how long the two hots and ground must be to reach their destination. Be sure to leave room for the GFI over both hit lines and the ammeter coil over one of them. Cut the hot and ground wires to length. Screw the ground wire into the ground bus. Pass both hot lines through the GFI CT coil and one of the hot lines (it doesn't matter which) through the ammeter coil. Attach the two hot wires to the LOAD terminals on the contactor. The pilot line will be attached to the logic/display board later.

Prepare three pairs of 22 gauge wires by twisting them together and attaching 22 gauge QD crimp terminals to each on one end. Attach one pair each to the auxiliary QD terminals on the contactor on the line side, load side and the contactor coil. Connect each pair to the screw terminals on the HV board, as appropriate, to the AC in (contactor line side) block, the relay test (contactor load side) block, and the contactor (contactor coil) block.

### Continue ###

Attach one end of the mezzanine cable to the HV board, taking careful note of the location of pin 1. To insert the cable into the connector, pull the edge of the connector opposite the contacts forward to loosen it. It should pop up and outwards. Insert the cable until it bottoms out in the connector, then carefully push the clip back into place until it snaps. The FFC should be straight and should resist moderate tension without coming out of the connector.

Set the chassis aside for now.

Prepare the lid by attaching the waterproofing gasket (if you bought one) and the LCD waterproofing kit (again, if you bought it). Solder the 3 wire cable onto the select switch as instructed and install the button in the hole in the lid. Install the OpenEVSE II logic/display board onto the 4 mounting posts in the lid. Connect the button cable up to the SELECT 3 pin terminal on the board. Connect the GFI CT coil up to the GFI terminals, noting the orientation - the GFI test pin is the left, the GFI pin is in the center, and ground is on the right. Connect the ammeter coil up to its terminal block - orientation does not matter. Connect the J1772 pilot wire up to the left terminal of the pilot block. The top screw is the pilot, the bottom screw is ground (normally unused). Connect the mezzanine cable up to the mezzanine connector in the upper left corner, carefully noting the position of pin 1.

Install a CR1220 battery in the battery clip.

Set the lid on top of the box, carefully inspecting the fit to insure that none of the wires place undue pressure on either of the board and that no wires are pinched. Screw the lid onto the box with the 6 chassis screws.

Assembly is now complete.

# Theory of operation #

Feel free to follow along with the schematics (below). Each subsection here corresponds to a page of the schematic.

### Power / GFI ###

There are two DC/DC converters built around the venerable MC34063 chip, The one on the left is a buck topology to reduce the 12 volts input to 5 volts at up to 250 mA. The one on the right is an inverting topology to turn +12 volts into -12 volts at up to 50 mA. Since the only use for the -12 volts is the pilot generator, there's a 2.4 k-ohm resistor across it to provide a minimal load. This improves the efficiency and stability of the converter.

The GFI is in three basic pieces. The first op-amp stage is a rectifying amplifier with a gain of 100 and a low-pass filter with a roll-off of 120 Hz (or so). It gets its input from the GFI current transformer. A current transformer outputs a current proportional to the current flowing on the conductor(s) passing through it. For a GFI, the two power supply conductors pass through it, and in a correct environment, all of the current flowing out through one of them should be balanced by the same amount of current flowing back through the other, for a net result of 0. If the current can find some other path to ground, the resulting imbalance will result in a current output from the CT. Immediately across the CT is a burden resistor. The burden resistor's job is to convert the current into a voltage that can be measured. There is a zener diode clamp to protect the amplifier from excessive voltage swings in the case of massive imbalances. The output of the amplifier is fed into a comparator. Whenever the amplifier output exceeds the comparison voltage (calibrated for between 15 mA and 20 mA), it interrupts the controller.

In addition, there's a GFI test circuit. This is merely a current limiting resistor. It's intended to be connected to a wire that takes 2 or 3 loops around and through the GFI coil and then connects to ground. The controller can test the GFI by pulsing this line with a 60 Hz square wave The multiple loops will serve to amplify the impact of the current flowing through the wire (each loop through represents another wire with the same current flowing through it), assuring that the GFI will trigger.

### Car signalling ###

The ammeter consists of another current transformer. In this case, only a single hot line passes through so rather than sensing any current imbalance, we will sense the total current flow. As before, there is a burden resistor and a zener clamp to protect the micro controller's A/D converter from excessive voltage, this time caused potentially by too much current. To keep the (expected) voltages positive, one leg of the CT is anchored to 2.5 volts with a voltage divider. The capacitor to ground from this leg is intended to reduce noise, by providing it a direct path to ground.

The pilot generator is a set of four transistors in a modified half-H bridge configuration. The output is a pair of PNP and NPN transistors in a push-pull arrangement from +/- 12 volts. Each transistor has a pull-up or down resistor on its base intended - in the default case - to keep the transistor switched off.

From each base there is a second complimentary transistor wired up to switch the final transistor on when the appropriate logic level is present on its input. On the high side, an NPN transistor will bring the PNP transistor's base to ground, causing it to turn on, but only when the first transistor's base is high. On the low side, a PNP transistor will bring the NPN transistor's base towards +5 volts, causing it to turn on, but only when the primary transistor's base is low. Finally, there is a pull-up resistor on the input to insure that there is always an unambiguous state present. When programming the controller, the pilot pin will be in a high impedance state. Without the pull-up, both transistors would wind up being on, shorting -12 to +12.

On the output there is a 1k impedance setting resistor mandated by the spec. After that there is a sampling resistor network. It's intended to scale the +/-12 volts on the pilot line to 0-5 volts to present to an A/D pin on the controller. This allows the controller to sense the state requested by the car and insure the presence of the pilot diode in the vehicle.

### Controller / display ###

The micro controller is the ATMega328p with a 16 MHz crystal. A crystal is called for in particular because the 1 kHz pilot has a frequency tolerance specification that requires that level of accuracy. 16 MHz is an otherwise arbitrary choice, but it is compatible with the Arduino Uno, from which the legacy of OpenEVSE is derived.

The i2c bus of the controller goes to an MC23017 i2c-to-GPIO expander chip, which is in turn connected to the RGB LCD and to the select button. This portion is exactly the same as both the AdaFruit i2c RGB LCD Arduino shield and the OpenEVSE display backpack. The i2c bus also goes to a DS1307 RTC chip, also equipped with its own crystal and backup battery, and an MCP9808 temperature sensor.

### HV board(s) ###

Each HV board has five jobs:
  1. Provide 12 volts DC to power the logic board
  1. Switch the car power on and off
  1. Provide a crude voltmeter for the input AC power
  1. Perform a ground impedance test
  1. Perform a relay output state (aka stuck relay) test.

Each HV board comes with either a 10W isolated power supply or a 3W one. The contactor version uses 3 watts because the contactor control circuit requires much less low-voltage power than the relay versions do.

The relay boards use an MMBT4401 power transistor to switch the relay(s) on and off. A flyback diode protects the transistor from coil collapse voltages. The contactor version uses an opto-isolated driver triac to switch a small triac on and off to control an external line powered contactor. Both the driver and power triacs are provisioned with snubbers to similarly protect them from coil collapse voltages when the contactor is switched off.

The voltmeter is one out of two opto-isolators in an LTV-844S connected across the AC line input with a 150 k-ohm series resistor. The series resistor is intended to reduce the current down to the 1-2 mA range, which results in a 0.5-1 mA transfer current (or so) from the transistor on the secondary. This winds up providing an output voltage with peaks at up to around 3 volts or so for 240 Vrms. The secondary is fed into a buffering OP amp and then passed to the logic board.

The ground impedance / stuck relay test starts with the relay test terminals. Each feeds into the anode of a beefy diode. The two diodes'  cathodes are connected together and then feed into a similar series resistor and then through a 1 mA current limit circuit, another opto-isolator and then to ground. The secondary side of the opto-isolator is fed into an OP amp comparator circuit. The output of that is fed into a simple peak-hold circuit made of a blocking diode, a large cap and a bleed resistor. The intention of the system is that when the relay or contactor is open, there should be no potential to ground on the load side. When the relay or contactor is closed, there must be a potential from at least one of the load terminals to ground.

# Schematics #

  * [Logic/display board v1.0](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_Logic_1_0.pdf)
  * [HV+External Relay board v1.0](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_HV_Ext_Relay_1_0.pdf)
  * [HV+Relay board v1.0](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_HV_Relay_1_0.pdf)
  * [HV+Contactor board v1.0](http://www.kfu.com/~nsayer/hydra/OpenEVSE_II_HV_Contactor_1_0.pdf)

# Links #

  * [OpenEVSE II on Tindie (store)](http://www.tindie.com/products/nsayer/openevse-ii/)