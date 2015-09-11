# Introduction #

The Hydra began its life as an EVSE adjunct - something you plug into a normal EVSE to allow it to be shared between two vehicles. In and of itself, that's a useful thing for some, but others simply have a single 240V dedicated circuit and two cars. For them, the EVSE + Hydra is more expensive than is required simply because it involves buying a J1772 inlet and cable whose entire purpose is to remain connected to each other in perpetuity.

With only a few modifications, the Hydra can serve exactly that purpose by itself.

# Hardware changes #

Hydra v3.0 is the EVSE variant. It's the same as the v2.2 board except that the inlet handling systems have been replaced by a single GFI circuit and an RTC chip and battery. There is only a single GFI to handle the entire system, meaning that a ground fault on either car will fault **both** cars. GFI trips are so rare that in practice there is not a lot to worry about.

Compared to OpenEVSE, the Hydra EVSE differs in the following ways:

  * The biggest, most obvious difference is the presence of two car connections.
  * The ADVPWR system from OpenEVSE is not present, and there is no L1/L2 detection, nor is there open-ground or stuck relay detection. There is no attempt to discern power or voltage. The Hydra firmware has always been, and remains, current-centric.
  * The relays are DPST. There is only a single digital output dedicated to the power control for each car.
  * In the reference design, there are three CT coils - one serves the GFI, and the other two are individual car ammeters. This allows the Hydra to attempt to protect against over-current excursions.
  * The AC/DC converter is mounted off-board, typically below the logic board. It is +12 VDC @ 0.9A (10 watts). +5 and +/- 15 volts are generated with on-board DC-DC converter modules.

# Assembling the Quick Kit #

The quick kit comes with:
  * The board
  * 2 "larger" two-pin screw terminals
  * 5 "smaller" two-pin screw terminals
  * 1 3 pin screw terminal
  * a trimmer pot
  * a shrouded 2x3 DIP header
  * an 18 pin SIP header
  * a 6 pin SIP header
  * a 3 pin SIP header
  * 4 nylon 2-56 3/4" bolts
  * 4 nylon 2-56 nuts
  * 4 nylon #4 1/4" standoffs
  * a 2x16 RGB backlit LCD module
  * a 12 -> 5 volt DC-DC converter module
  * a 12 -> +/-15 volt DC-DC converter module

Assembly is the same as the "traditional" variant board quick kit with the following differences:

  * The 3 pin screw terminal goes on the GFI connector.
  * The "larger" 2 pin terminals are for the pilot connections on each car. The footprint on the board is for a 3 pin terminal. You want to use the square and center hole of each. The round hole on the "end" (which has no label on the silkscreen) is not connected.

When you're finished with assembling the quick kit, stick a CR1220 battery in the battery holder. The positive side of the battery goes up.

# Parts list #

  * A Hydra EVSE board, assembled.
  * An AdaFruit waterproof momentary button (from the OpenEVSE store - ask Chris to use longer wires).
  * A Polycase WC-40 chassis and a WX-42 internal panel.
  * 2 CG-16 cable glands
  * A power cable and plug (if necessary) to suit your installation.
  * 1 CG-17 cable gland if you're using 8 AWG SOOW for your power cable, or another CG-16 for 10 AWG.
  * A Cooper Bussmann 16220-2 power distribution module.
  * 2 CT coils - CR Magnetics 8420-1000 recommended.
  * 1 GFI CT coil - CR magnetics 8420-1000-G recommended (yes, it's different from the other two).
  * 2 DPST relays with 12 VDC coils rated for your desired outlet power - The reference design uses TE T92P7D22-12 for 30A. If you want to use line powered contactors instead, then you will need to use contactor adapter boards to allow 12 volt DC to control them.
  * 2 J1772 cable/plug assemblies.
  * a 12 volt 10 watt DC power supply - CUI VSK-S10-12UA-T recommended.
  * 4 4-40 2" standoffs to mount the logic board.
  * a 4 position grounding bus.
  * A CR-1220 battery to preserve the clock during power outages.
  * A foot each of suitably sized (for your outlet current - 10 AWG for 30 amp) red and black wire. You can scavenge that by trimming the J1772 cables.
  * A foot each of 22 gauge red, black, yellow and green wire.
  * various 6-32 and 4-40 nuts, bolts and washers.

# Wiring #

![http://www.kfu.com/~nsayer/hydra/hydra_wiring_evse.png](http://www.kfu.com/~nsayer/hydra/hydra_wiring_evse.png)

Compared to the original Hydra variant, the EVSE variant obviously lacks inlet handling. Instead, there is a third CT coil through which you pass both of the inlet hot lines. This must be done _before_ they split to go to each car. The two hot lines, but _not_ the ground must pass through the CT, and in the same direction. Also, a small 22 gauge wire must be looped through and around the CT coil three times and connect to the GFI test pin and ground. At startup, the Hydra will pulse this line and attempt to detect a GFI interrupt to insure that the GFI system is operating properly.

There is also an RTC chip on the board. This can be used to set up time-of-use schedules.

There is a single button. Like OpenEVSE, this button enters the menu system where the inlet and outlet currents can be set, along with the date/time and any desired on/off scheduling. You can also change the operating mode (shared or sequential).

The inlet current is the maximum current that the Hydra may use as a whole. Generally, this is limited by the size of the circuit breaker supplying the Hydra and the gauge of wire used to feed it. Remember that in general you must derate your circuit breaker by 20% because EV charging is a continuous duty cycle service. So if you have a 40A circuit breaker, your maximum inlet current is 32A.

The outlet current is the maximum current that the Hydra may supply to any one car. This is limited by the relays, J1772 cables and plugs that you pick.

The reference design is rated for 40A inlet current (that is, a 50A circuit breaker) and 30A outlet current. This means that it can supply 20A to both cars simultaneously or 30A to a single car.

For a 50A circuit, the NEC mandates AWG 8 cable with 75ºC insulation. This should be available as SOOW (that is, rubber insulated, oil, water and weather resistant cable) cable, which can be fed through a cable gland on the Hydra chassis and connected to a NEMA 6-50 or 14-50 plug on the other end. Run the two hot lines through the GFI coil (it may be a tight fit, but it should just fit) and into a Cooper-Bussman 16220-2 bus module, one into each LINE side.

On the load side of each, you'll run a 10 gauge wire from each hot group to each relay, plus a 22 gauge wire from each hot group to the 12 VDC power supply. You'll also use 22 gauge wire from the power supply to the 12 VDC input on the logic board.

From each J1772 cable, run each of the hot lines to the two load sides of one relay, passing _one_ of the hot lines through that same car's ammeter CT. Remember: run _both_ power input hot lines through the GFI coil, but only _one_ outlet hot line through the ammeter coil. It does not matter which hot line you choose for the ammeter. Run the pilot wire for the same car to the pilot terminal for the appropriate car. If your J1772 cable includes a proximity wire, leave it unconnected. If you're in Europe and have IEC 62196 sockets with a Proximity Pilot wire, leave that disconnected as well.

The GFI CT terminal has three positions on it. Two are for the GFI coil itself, and the third is for a test wire. Run a 22 gauge yellow wire from the test position through the GFI CT, looping it through twice, and then return it to the CT terminal opposite the test terminal (that is, not the middle terminal). The Hydra will test the GFI circuit every time it starts up. The Hydra will not operate if the GFI test fails.

Run the power cable's ground wire, each of the two car ground wires and a wire from one of the ground pins on one of the car connectors on the logic board to a ground bus.

Connect each ammeter CT coil up to the appropriate car's CT connector. Connect each car's relay coil up to the appropriate car's relay terminal. Connect the UI switch to the logic board, and install a CR1220 battery in the RTC backup battery retainer.

![http://www.kfu.com/~nsayer/hydra/hydra_3_0.jpg](http://www.kfu.com/~nsayer/hydra/hydra_3_0.jpg)

# User's guide #

The Hydra is controlled by the single push-button. There are two "gestures" you can use - shorter than a quarter second (a "short push") or longer (a "long push").

Normally the display will show the time and operating mode on the top line, and the state of the two cars on the bottom line. The backlight colors are:

  * Yellow - paused
  * Green - Neither car is charging
  * Blue - A single car is charging
  * Violet - Both cars are charging
  * Red - One or both cars are in an error state

A short push on the button will toggle the pause mode. If a timer event has paused the Hydra, then you may override that with a short push.

A long push will enter the menu system, but only when no cars are connected to the plugs. The menu system operates with short pushes to select among currently displayed available options, and a long push to accept the currently chosen option and move to the next menu item. The default (or currently selected) item will be marked with a "+" sign when cycling through the choices.

The menu items:

  * Operating mode - either shared or sequential
  * Total available current
  * Set clock? Yes or no
  * Use DST (Daylight Savings Time)? Yes or no
  * Edit events? Yes or no
  * Exit menus? Yes or no

If you choose to set the clock, then you will go into a clock-setting screen. The time will show with the hour blinking. Use short pushes to change the blinking digit and long pushes to advance to the next digit. Once you've set the current time and date, perform a long push at 0 seconds and the time will be set and the menu system exited. If you have not yet enabled DST and wish to, then you should set the time to your "winter" time. Enabling DST will advance the time during Summer.

If you choose to edit the events, then you will go to a similar event editing screen. The first thing that will be blinking will be the event (1-4) you wish to edit. As you cycle through the event numbers the settings for each will be displayed. After event 4 there's an "Exit" option to exit the event editor. If you long push to select an event to edit, then the hour of the event time will blink, followed by the minutes and meridian (AM or PM). After that are 7 day-of-week flags. If the flag shows a "-" then the event will not fire on that day. If the letter for the day of the week shows, then the event will fire. Lastly, there's a single letter for the event action. "G" means "Go" - the Hydra will "unpause" at that time if paused. "S" means "Stop" - the hydra will pause at that time if unpaused. "N" means "Nothing." The event will do nothing at all.

When in shared mode, the Hydra will split the available current in half if both cars wish to charge simultaneously. If only one car wants power, then it will be given 100%.

In sequential mode, only one car at a time is given power. When that car finishes, the pilot is offered to the other car. If neither car wishes power, then the "offer" will switch between the two cars every five minutes (in case one of them changes its mind).

The Hydra will remember (in the ATMega's EEPROM) the menu settings, events and if in sequential mode, the last car that was "it," and restore all of that if there's a power outage. However, the Hydra will always come up "unpaused" after a power outage.

The possible error codes:

  * G - Ground fault detected.
  * E - Pilot state error (including missing diode).
  * O - Overcurrent event detected.
  * R - Relay test failure.
  * T - Illegal transition (car attempted to request charging when it was not offered a pilot).

If a car enters an error state for whatever reason, the error can be cleared by disconnecting and reconnecting that car.

The inlet current is settable in the menu system, but the maximum outlet current (the maximum current offered each car separately) is compiled into the firmware. This is because it is a consequence of choices made during assembly and not reliant on outside factors, like circuit breakers. The default maximum outlet current is 30A. If you wish to change that, you must edit the firmware source and recompile.

The daylight savings time rules that are compiled into the firmware are the U.S. rules. If you live elsewhere, you'll need to customize those rules for your jurisdiction if you wish to use DST.

If you wish to display the time using 24 hour time instead of AM/PM, then that too is a compile-time option.