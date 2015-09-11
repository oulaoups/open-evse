# Introduction #

In creating your own EVSE, it is often helpful to be able not only to send the pilot signal into the various states (including missing diode), but to analyze the frequency and duty cycle of the pilot being presented. Measuring frequency can be done by some higher-end VOMs, but duty cycle typically requires an oscilloscope.

In lieu of that, I've taken some of the circuitry from the Hydra and an ATTiny85 microcontroller and created a small(ish) extension to the EV Simulator which uses the controller to analyze the pilot and report its frequency, duty cycle and the resulting J1772 amperage allowance either via the 2 line LCD "backpack" from the OpenEVSE store (or the AdaFruit shield) or via asynchronous serial via an FTDI connector.

# Backpack version #

The latest version of the Ev Sim II is in the form of a self-contained LCD + Backpack module. The backpack has an ATTiny84 on it instead of the ATTiny85 previously used. This does away with the i2c + GPIO interface for the LCD. This version lacks the serial I/O option, but at the end of the day it's less expensive.

# Details #

You can download an Eagle board and schematic file from the project downloads. You have some no-stuff options if you like:

  * If you want to use the internal 8 MHz oscillator instead of a crystal, you can leave out the crystal and C5 and C6. If you do so, then you can expect the frequency readout to be off by as much as 10%. Also, you may have some difficulty with the async serial option, as the baud rate should, in principle, be within 5% in order to be reliable.
  * If you do not want to use the i2c LCD display option, you can leave out the i2c connector, the power jack, LM7805 and C1 and C2. You will be relying on the FTDI cable to power the circuit from your computer.
  * If you do not want to use FTDI, then you can leave that connector off.
  * If you have some alternate means to program your ATTiny chip, you can leave out the ISP connector.
  * If you have a pile of 16 MHz crystals laying around, then you can use one of them in place of the 20 MHz crystal specified in the project BOM. If you do, you'll need to modify the boards.txt fragment added by the "master.zip" file (see below) to specify a 16 MHz CPU clock rather than 20. You must pick a clock frequency compatible with SoftwareSerial - which supports only 8, 16 or 20 Mhz.
  * If you have no need of the actual duty cycle measurement, you could just use [R2](https://code.google.com/p/open-evse/source/detail?r=2)-[R4](https://code.google.com/p/open-evse/source/detail?r=4), D1 and the dip switch block. That would be equivalent to the original EV Sim. You could even put an oscilloscope sampling pin on the anode side of D2.

For the sketch, you first need to configure the Arduino IDE to understand the ATTiny controllers. To do that, visit http://hlt.media.mit.edu/?p=1695 and download and install their ATTiny "master.zip" files. I also found that I needed to correct a bug in the AVR 'ld' command that came with Arduino. You need to fetch the patch at https://github.com/TCWORLD/ATTinyCore/tree/master/PCREL%20Patch%20for%20GCC and install it.

You need to fetch the TinyWireM library from https://github.com/adafruit/TinyWireM and install it. You also need the LiquidTWI2 library. You can fetch that from https://github.com/lincomatic/LiquidTWI2 and install it.

Next, fetch the sketch from https://github.com/nsayer/hydra/blob/master/EV_Sim.ino

Set the Arduino IDE up for either an ATTiny85 20 MHz (if using the crystal) or 8 MHz (if using the internal clock), burn the bootloader (this step doesn't actually upload a bootloader, but is required at least once to set the fuses), and upload the sketch.

Note that you cannot connect both the FTDI and i2c connectors at the same time. Both output mechanisms use the same controller pins. If the display is connected to the i2c connector, then it should be automatically detected and used at boot time. If you connect to the FTDI connector instead, you'll see a burst of line noise as the sketch starts, then you'll see the serial output take over after the i2c autodetection fails. Do not connect both at the same time. Also, although the sketch currently does not use the RD pin, you should connect it. The received data pin will serve to drag the SDA pin during the i2c autodetect phase and encourage it to fail.

To use, connect either a power source (6 volts minimum) and LCD or an FTDI connector to the board. Flip all four DIP switches off. Connect the ground and pilot pins of the pilot connector up to the EVSE under test. Your EVSE should show no vehicle connected. The display should show 0 Hz and a "+" indicating that the pilot is pinned high.

Flip switch 4 (the one closest to the edge of the board) to "on". That should cause a transition to state "B". The EVSE should indicate a vehicle is connected. If it is prepared to supply energy, then you will see the display show 1000 Hz (+/- 20 Hz or so) and a duty cycle and amp rating that's appropriate for the EVSE in question. If your EVSE has a timer or a pause function, engaging either should result in a pinned (that is, 0 Hz) pilot.

Flip switch 3 on to enter state "C". The EVSE will indicate that the vehicle has requested charging and should switch on the AC power. It goes without saying that at this point you must be extremely cautious as the two AC pins on the charge handle will (or at least should) be energized.

Flip switch 2 on to enter state "D". The EVSE will respond as appropriate for a ventilation request. Some EVSEs will error out, some will proceed without complaint. It depends.

Note that switches 4 through 2 act cumulatively. For example, you should not turn off switch 4 as you turn on switch 3. It is invalid to have a lower numbered switch (except switch 1) turned on without all of the higher numbered switches also on.

If you flip switch 1 on at any point, the EVSE should respond with a diode check failure and enter an error state.

There are other tests you could attempt, but they involve manipulating the hot lines. Because of this, I cannot recommend attempting them unless you are an expert in dealing with high voltage electricity. For completeness, however, they include:

  * Using a voltmeter to check the AC voltage between each hot line and ground, or between the two hot lines. For North America, you would expect to see 240 (or 208 if using 2 legs of 3 phase power) between the two hots and 120 between either hot and ground when using L2, or 120 between the two hots, 120 between one of the hots and ground and 0 between the other "hot" and ground (which hot is actually hot doesn't matter) if using L1. In Europe, I believe the expectation is that you should see the same as L1 in North America, but with 240 volts instead of 120.
  * Using a 5 kilohm 5W resistor between a hot line and ground to simulate a ground fault. Your EVSE should, of course, immediately disconnect the power and enter an error state. The pilot should show 0 Hz and a "-" to indicate being pinned low (though pinned high is also reasonably acceptable).


# Theory of Operation #

The pilot from the EVSE is connected first to the DIP switches, which switch [R2](https://code.google.com/p/open-evse/source/detail?r=2)-4 in and out of place. The unswitched side of each resistor then goes to D1 and then to ground. Switch 1 on the DIP switch block shorts out the diode, simulating a "missing diode" for the diode check.

The sampling circuit also comes from the incoming pilot pin and is rectified by D2. This is necessary to prevent the negative portion of the pilot signal from arriving at IC1, which cannot tolerate negative voltages. Since the cathode side of D2 will float whenever the pilot is negative, [R8](https://code.google.com/p/open-evse/source/detail?r=8) will pull the comparator input down to ground. To insure the comparator sees a definitive transition between the two states, a voltage divider provides approximately one volt to the inverting input. This means that the comparator output will be high when the pilot is higher than 1v. This should be sufficient to see the pilot oscillating even in state D. [R5](https://code.google.com/p/open-evse/source/detail?r=5) is a pull-up for the LM393's open collector output.

The ATTiny85 controller is intended to be fused for an active /RESET pin (without this, high voltage programming would be necessary), and external crystal clocking. That occupies three of the I/O pins, leaving just 3 left (along with two power pins). Those 3 pins are first and foremost the SPI programming interface. During programming, the programmer must have priority over any other potential signals on those pins, so [R9](https://code.google.com/p/open-evse/source/detail?r=9)-[R11](https://code.google.com/p/open-evse/source/detail?r=11) protect those pins from any stray signals that could be present.

When not in programming mode, two of the three available pins are slated as universal serial pins. They can be used to create a variety of different serial bus signals. We use the TInyWireM library to use them as an i2c bus. When the i2c bus is not being used (that is, when autodetection of the LCD fails) we use SoftwareSerial to create a serial port on those pins instead.

The display will normally show the pilot frequency and duty cycle, along with a J1772 decoding of the amp rating for the given duty cycle. If the frequency is 0 (that is, no oscillations were detected at all), then the duty cycle will be replaced with either a "+" or "-", which indicate that the pilot is pinned either high or low (respectively).

# Backpack Quick Kit Assembly Instructions #

The Quick Kit comes with all the surface mount components installed and pre-programmed with the latest firmware.

To complete assembly, simply install the ISP jack, DIP switch block and pilot screw terminal on the board. Make sure to install them on the same side of the board as the surface mount components. Also, make sure that the key for the ISP jack is on the same side as the square hole on the board  (pin 1). Make sure as well that the screw terminal holes face the bottom of the board. The DIP switches can be installed either way, depending on which direction you want to push the switches to turn them on.

After all of the other through-hole parts are installed, you can mount the LCD. Install the 16 pin SIP header in the LCD, but do not solder it yet. Place the board over the pins, forming the backpack, but again - do not solder yet. Place a standoff on each corner between the two boards, then thread a 2-56 bolt from the display side of the sandwich through to the component side of the board. Secure it with a 2-56 nut. Repeat on all four corners. Once the display is physically secure, solder the 16 pin SIP header on both boards.

Your EV Sim II is complete!

# Assembly Instructions #

Install the ISP socket first. It is the largest and least forgiving component on the board. After that, install the power connector. Because of the oversize holes, it has a bit more "play" in its placement.

Note that there are three capacitor values on the board, and there are different numbers of capacitors for each value (1 x 0.33 uF, 2 x 22 pF and 3 0.1 uF). This should make it easier to tell them apart.

Be sure to install the diodes with the banded end (the cathode) as marked on the board. The LM7805 heat sink side should be towards the edge of the board (rather than towards the center).

The two ICs both point such that pin 1 is near the edge of the board. The ATTiny is nearest the voltage regulator, and the comparator is nearest the pilot input block.

The black FTDI pin is traditionally the grounded one. The BLK marking on the board indicates which end of the FTDI connector is for that pin. The square pad on the i2c connector is pin 1. It is, paradoxically, opposite the FTDI connector (pin 1 is closer to the edge of the board). The i2c connector pinout is the same as OpenEVSE:

  1. ground
  1. +5 volts
  1. SCL
  1. SDA

There are no i2c pull-up resistors on the board, as the SCL and SDA pins are also used for the FTDI connector. It is assumed that the i2c peripheral will supply them.

You should not need to use a heat sink on the voltage regulator if you keep the input voltage at or lower than 12 volts (higher input voltages do little more than waste power). 7-9 volts is ideal. The circuit will likely function at lower voltages, but the LCD will start losing readability and eventually stop functioning.

The first generation of EV Sim kit includes a 1N4004 diode "extra". This diode was added to the circuit to protect against incorrect input power, but the current run of boards doesn't have a space for it. The diode should be mounted across top and bottom two pins of the input power jack, with the banded end (the cathode) pointing towards the tip pin (away from the edge of the board). This diode will short-circuit if the power polarity is reversed.

![http://www.kfu.com/~nsayer/evse/diode_hack.jpg](http://www.kfu.com/~nsayer/evse/diode_hack.jpg)

# Pictures #
![http://www.kfu.com/~nsayer/evse/ev_sim_bp.jpg](http://www.kfu.com/~nsayer/evse/ev_sim_bp.jpg)
The EV Sim II backpack

![http://www.kfu.com/~nsayer/evse/IMG_3236.jpg](http://www.kfu.com/~nsayer/evse/IMG_3236.jpg)
My original portable EVSE tester setup in the car.

# Links #
  * [My online store for boards and kits](https://squareup.com/market/nick-sayer)
  * [My OSHPark profile - buy your own boards](http://oshpark.com/profiles/nsayer)
  * [Arduino support for ATTiny](https://github.com/damellis/attiny/archive/master.zip)
  * [ATTiny Arduino patch](https://github.com/TCWORLD/ATTinyCore/tree/master/PCREL%20Patch%20for%20GCC)
  * [TinyWireM](https://github.com/adafruit/TinyWireM)
  * [LiquidTWI2](https://github.com/lincomatic/LiquidTWI2)
  * [EV Sim Mark II sketch](https://github.com/nsayer/hydra/blob/master/EV_Sim.ino)
  * [Backpack schematic (PDF)](http://www.kfu.com/~nsayer/evse/ev_sim_bp_sch.pdf)
  * [Original Schematic (PDF)](http://www.kfu.com/~nsayer/hydra/EV_Sim_schematic.pdf)