# Introduction #

The base design for OpenEVSE v2 and Hydra boards calls for 12 volt DC relays to turn the vehicle power on and off. For higher powered EVSE designs, however, high current capacity relays with 12 volt DC coils are rare. More often you find line powered relays, also known as contactors. In order to use contactors with OpenEVSE or Hydra boards, you must use a driver to allow the low voltage DC to switch high voltage AC power on and off.

# Details #

There are two ways to adapt contactors. You can either use a pilot relay or you can use a semiconductor adapter, such as a solid-state relay or a triac.

In the [Geppetto Electronics store](http://store.geppettoelectronics.com) there is a contactor driver board that can be used to drive a contactor from a 12 volt DC signal.

The board has a small terminal block and a larger terminal block. The board is also divided (across an optoisolator) between low voltage and high voltage sides. Be aware that line voltage is present throughout the high voltage side of the board. Do not touch the board while line voltage is connected.

The low voltage terminals are polarized, unlike the relays that would normally be used. For OpenEVSE v2 boards, the common terminal of the relay output is positive and the two independent outputs are negative. For Hydra boards, the top terminal (furthest from the pilot block) is positive, and the other terminal is negative.

The high voltage terminals act like a switch. Wire one coil terminal of the contactor directly to one of the power supply terminals. Wire the other to one of the terminals on the adapter board. Wire the other terminal on the adapter board to the other power supply terminal.

Be sure to mount the board securely so that nothing can potentially come in contact with the board.

The board is thermally designed to switch up to 100 mA at 240VAC (24 watts), which should be plenty for a contactor coil.

# Use #
![http://www.kfu.com/~nsayer/hydra/ContactorAdapter.png](http://www.kfu.com/~nsayer/hydra/ContactorAdapter.png)

Before use, you should attempt to insure that the relay coil draws no more than 100 mA of continuous current (brief higher surge currents when the coil is first energized are ok). 100 mA is the maximum the adapter is rated. This equates to 24 watts at 240 VAC (it is unlikely a contactor would be used at 120 VAC), which should be plenty.

22 gauge wire is acceptable for the coil wiring and the input wiring. Be sure that the addition of the coil driving circuit does not in any way compromise the current carrying capacity of the high current path.

If the current limit is observed, additional cooling should not be required. The board should have the same operating temperature range as the OpenEVSE or Hydra controller.

The input side has a resistor sized for 12 volt DC switching. If you use different voltages, you should replace the series resistor. Do not exceed the 50 mA forward current rating of the LED in the optoisolator.

Most contactors have .25" QD terminals for the coil, and auxiliary QD terminals on the relay terminals in addition to a large box screw terminal for the high current wiring. These QD terminals provide an ideal mechanism to provide the coil control voltage. On the AC Line side of the relay, run a 22 gauge wire from one phase to one of the coil inputs. From the other phase, run a 22 gauge wire to one of the adapter AC terminals. Run a 22 gauge wire from the other AC terminal on the adapter to the unused coil input on the contactor. Often each coil terminal will have two QD terminals. **DO NOT** connect both phases to a single coil input terminal - you will short out the AC supply and probably blow the adapter's triac in the process.