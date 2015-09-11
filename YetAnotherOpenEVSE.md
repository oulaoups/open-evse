# Introduction #

My principle motivation started as an effort to make a portable L2 EVSE, but I suspect as I go that this will become a platform for personal experimentation.

Since I was going for a portable unit, I decided, whenever a choice presented itself, to attempt to make a waterproof (or at least water resistant) design.


# Details #

I am waiting for the two boards from Chris (an OpenEVSE Plus and an LCD).

I am using the waterproof 6x6x4 box with a clear lid. I bought the Adafruit waterproof lit button and am using a pair of CG-16 cable glands. The AC supply cable is 10W3 cable from Home Depot terminated in an L6-30. I also built a couple of adapters for other socket types: an L1 adapter that goes from a normal grounded 120V plug to an L6-30 (this is, of course, normally out of spec, but I've labeled the socket with warnings that it's only 120V), a NEMA 6-50 to L6-30 adapter and a special NEMA 14-x0 adapter. That one is a NEMA 14-50 plug with the neutral conductor removed. Configured that way the plug will fit in a 14-20, 14-50 or 14-60 socket. And it will work without difficulty because the neutral is not used.

Since this is a portable EVSE, I placed the two cables on opposite sides of the box - the "pregnant snake" design.

Here's the box as it is so far. The AC cable gland has been removed, as the component plate cannot be installed with both cable glands in place. The AC cable will need to be installed as the last step of construction.

The ground bus is going to be on the AC input side of the box. If one were to yank on the AC cable, it would rip the conductors off of the fuse holders first, then rip the ground out of the ground bus. The J1772 cable has had its inner conductors trimmed so that the pilot pin should have very little slack compared to the other conductors. As a result, if the J1772 cable is yanked out of the box, it will break the pilot lead first, which should turn off the system. The current conductors would be yanked off the relay second, and finally the ground would be last.

Note that the ground bus is mounted slightly off-center. This is a result of a discovery that I made. The plate can be mounted in either orientation in the bottom of the box. What this means is that if you imagine turning the plate 90 degrees from where the mounting holes are, there will be two spots that are unusable for mounting anything, as any hardware under the plate will collide with the case. I made this discovery the hard way and was forced to move the ground bar about a half inch to one side to insure the mounting plate would sit correctly in the case when the project was finished.

Note also that the logic board is mounted out-of-the-way of the mounting holes so that it can be attached while still outside of the case. The LCD board is mounted much closer to the edge of the plate because it is intended to be mounted to the standoffs after the rest of the assembly has been put in the box.

The logic board will be mounted "upside down" - that is, with the AC input and test terminals to the right and the I2C and SPI connectors towards the center of the mounting plate. The purpose of that will be to facilitate connecting the SPI or FTDI cable without having to remove the LCD.

http://www.kfu.com/~nsayer/evse/photo%202.JPG

In order to preserve the water resistance of the case, no holes were drilled in the box for component mounting. Instead, I bought a component mounting plate designed to be attached to the bottom of the box. I can drill as many holes as is necessary to mount components.

I decided to mount the LCD above the logic board on longer standoffs. One gotcha I ran into was that the hole for the bottom left corner of the logic board wound up too close to the relay. I've decided to simply dispense with that hole and use the remaining three only. An alternative would be to mount the relay in the opposite orientation. You may wind up struggling to find a spot for the fuse holders... I'm not sure.

The Adafruit button is mounted dead center in the top of the box. The way the LCD standoffs are positioned, it should wind up directly under the LCD. The LCD will be oriented so that the two cables will exit from the right and left side of the box.

Again, in order to preserve the watertight rating of the box, the fuse holders I chose were chassis mount ones that will be mounted internally. Note that in the picture the fuse holders are the wrong type - they have ends configured for soldering, not for quick-connects. The quick-connects... sort of fit, but they're loose, and that makes me nervous enough that I've ordered replacements.

http://www.kfu.com/~nsayer/evse/photo%201.JPG

I got the new fuse holders today and decided to change the order of operations around. I've installed and wired everything except for the logic boards (still waiting for them). My leads are long enough that I hope to be able to install everything and shoehorn it into place.

Everything is a tight fit in the bottom half of the box, but it _does_ fit.

http://www.kfu.com/~nsayer/evse/photo%203.JPG

The remaining steps:

  1. Assemble the two boards.
  1. Attach the AC supply, test, relay, pilot, CT and ground leads to the logic board.
  1. Install the logic board to the short standoffs.
  1. Attach the I2C cable and button cable to the LCD board.
  1. Install the LCD board on the tall standoffs.
  1. Close the box.
  1. Have a Fresca.

# Meanwhile... #

I also separately ordered a DIY v4.2 board and the BOM of parts from DigiKey. It's a race now to see whether the board from OSHPark comes or the PLUS board kit from Chris. :)

Of course, it was challenge enough fitting everything required for the OpenEVSE Plus onto the 5x5 panel for the 6x6x4 box. The OpenEVSE DIY board makes things much, much worse. Not only is the board physically larger, but it requires an external power supply.

I decided to go with a chassis mounted power supply module. The one listed in the BOM is said to be deprecated, so instead I bought DigiKey's 102-2664-ND. It's a 900 mA 12V supply, but fits in the same physical space.

My thought at the moment is to mount the logic board on a right angle against the side of the box. Hopefully I can find two angle brackets to screw into the panel and into one side of the board and that it will be stiff enough. The display will be mounted on tall standoffs above the power supply.

### Some days later... ###

Well, the DIY board won the race, so I completed that first.

Assembly was, more or less, straightforward. There were some errors on the BOM, which I fixed.

Here it is on the bench: http://www.kfu.com/~nsayer/evse/photo%204.JPG

I discovered the happy coincidence that the DIY board's hole spacing is more or less the same as the hole spacing of the RGB LCD display. I've decided to mount the DIY board on standoffs above the power supply, then cantilever the display off two standoffs above the main board.

So to make it all happen...

Almost all of the hardware holding the components to the backplane is 4-40. The exceptions are the relay, which is held with 6-32 hardware and the ground bus, which came with its own self-tapping screw.

I was able to use a fine point marker and hold most of the components on the plate and mark the spots to drill. 4-40 hardware needs a 1/8" drill bit. The 6-32 holes and the ground bus use 9/16".

The least forgiving component for mounting is the power supply. It's also more difficult because the holes are too small and too thick to fit a pen in. I put a 1/16" drill bit in the drill and used the drill to make a "divot." That gave me an opportunity to visually insure that the holes will be in the right place (I wound up having to redo one). The divot also keeps the bit from wandering before the hole gets started.

The power supply needs 2 5/8" 4-40 bolts to hold it in place. The two fuse holders need 3/8" 4-40 bolts. The relay needs two 3/8" 6-32 bolts. The main board was put in place with two 1 1/4" 4-40 M-F standoffs. The male end was bolted to the mounting plate and the female end accepts the circuit board. The bottom two board holes got 1/4" 4-40 bolts and the top two got two more 1 1/4" standoffs. The LCD will eventually be mounted to the top standoffs with 1/2" 4-40 bolts.

In this picture, you can see the standoffs at the top that will later accept the display: http://www.kfu.com/~nsayer/evse/photo%208.JPG

The power supply is mounted below the board, so it's not visible. If you peer through the lid at just the right angle, you can see its LED light up when it gets power.

At the moment, I'm temporarily wiring an LCD shield up as the display.

http://www.kfu.com/~nsayer/evse/photo%207.JPG
http://www.kfu.com/~nsayer/evse/photo%206.JPG

Some lessons learned:

  1. The button extends down into the case quite far. As it is, it comes close to hitting a couple of components on the motherboard. But moving it downwards would risk coming too close to the HV wiring on the relay.
  1. The cable glands with the cables coming in are a challenge to put into place given how the board is mounted.
  1. The quick connects on the fuse holders are at an awkward angle. I had to carefully bend them upwards to get everything to fit. Changing the fuses, if that's ever going to be necessary, will be a pain.
  1. The ground bus isn't designed to take in small gauge wires. Getting the screw to find and bite them is difficult, particularly when the bus is mounted.
  1. slo-blo fuses heat up when they're run at their rated capacity. I switched from 3AB 30A slo-blo to 3AG 35A quick and the overheating issue went away. If I had to do it over, I would strongly consider using 40A breakers. 3AG fuses aren't really correct for this application, but a more applicable fuse would be difficult to fit in that box. Also, a ganged breaker would shut off both phase lines instead of one, which would be safer. Panel-mount breakers can be had, but you sacrifice the NEMA 4 rating by drilling the holes in the box for them to fit.

And here's the target:

http://www.kfu.com/~nsayer/evse/photo%209.JPG

... and here's his opinion:

http://www.kfu.com/~nsayer/evse/photo%2010.PNG

My order from Chris came today. I didn't get the Plus completed, but I did manage to add a display to the DIY and finally, for the first time, close the lid all the way.

http://www.kfu.com/~nsayer/evse/photo%2011.JPG

This weekend I decided to swap the DIY for the Plus board. The benefits to going that way are that the LCD is held to standoffs on each corner rather than being cantilevered, and it's lighter weight. I didn't take a picture, but it doesn't look too different from the DIY. I'll take a picture when I have it up on the wall.

## Future directions ##

I definitely want to get another current transformer and connect it to the A3 input and add some software to work as an ammeter to display the current draw.

# Parts #

| Source | Part # | Quantity | Description |
|:-------|:-------|:---------|:------------|
| Polycase | CG-16  | 2        | Cable gland |
| DigiKey | 377-1787-ND | 1        | 6x6x4 box, transparent top, NEMA 4 |
| DigiKey | 582-1018-ND | 1        | Current Transformer |
| DigiKey | PB486-ND | 1        | 30A 12V DPST relay |
| DigiKey | 377-1939-ND | 1        | 5" square internal panel |
| DigiKey | 4813K-ND | 4        | 4-40 nylon 2" M-F standoff |
| DigiKey | F1779-ND | 2        | 3AG 30A slo-blo fuse |
| DigiKey | WM7273-ND | 4        | Quick-connect M-M-F adapter |
| DigiKey | F1500-ND | 2        | 3AG fuse block Quick-connect |
| Leviton | ?      | 1        | J1772 plug, 30A, 25' cable |
| Home Depot | ?      | 10'      | 10W3 cable  |
| Home Depot | ?      | 1        | L6-30 plug  |
| Home Depot | ?      | 1        | 4 position ground bus |
| Home Depot | ?      | misc     | 4-40 hardware - nuts, 1/4" & 1/2" bolts |
| Home Depot | ?      | 8        | 10 gauge quick-connect crimp connectors |
| Home Depot | ?      | 6        | 22 gauge quick-connect crimp connectors |
| Halted Spec. | n/a    | misc     | 22 gauge stranded wire |
| Halted Spec. | n/a    | 2        | 1." header crimp-on connector (1x 2 pos, 1x 3 pos) |
| AdaFruit | 560    | 1        | Waterproof metal lit pushbutton (green) |
| SparkFun | ?      | 1        | 4 pin, 12" jumper wire |
| SparkFun | ?      | 1        | Pocket AVR Programmer |
| SparkFun | ?      | 1        | FTDI Cable 5V |