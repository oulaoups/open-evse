Directions for compiling and loading firware with Atmel Studio.

# Using Atmel Studio to edit and load firmware #

### (This page under construction: If you have useful input, please send it to mrpilotron@gmail.com for inclusion. ) ###

**If you just have to be different than the cool kids who use Arduino IDE, you can use Atmel Studio to load your firmware** This tutorial assumes that you are building an EVSE from scratch, not ordering a Plus kit or pre-built & tested board from Chris. If you do decide to play with the firmware on one of Chris's boards, you can skip the _Set Fuse Bits_ section.

## Download and install Atmel Studio ##
[Atmel Studio](http://www.atmel.com/tools/atmelstudio.aspx) is a free development environment for the MS Windows environment. Once you get it installed and running, everything is point and click. There are no command lines to type or external tools like AVRDude required. **PLEASE NOTE:** Atmel Studio 6 seems to be very buggy and unstable. I encountered many problems trying to program chips. Mostly, it just refuses to enter programming mode. It also wouldn't reset incorrect fuses even when using HVPP mode (see below for more about this).  I finally gave up and went back to AVR Studio 4.19, which is available here: http://www.atmel.com/tools/avrstudio4.aspx and all those buggy problems went away. I HIGHLY recommend skipping the frustration of Studio 6 and just use the older Studio 4. In this case, newer is definitely NOT better!

Installing the Atmel Studio 6 took nearly 3 hours total because it's built on the .NET framework and required a lot of extra downloading and rebooting. Studio 4 took about 5 minutes with a simple download, install, and start using it. No reboots. If I haven't convinced you to avoid Studio 6 yet, please see a psychiatrist to adjust your meds!

After installing Studio 4, you need to do a separate download and install of the AVR Tool Chain 3.3.0. This is available from the same lauch page where you found Studio 4. Once Studio 4 and the AVR Tool Chain are installed and running you can start AVR Studio and create a new project. Give it a useful name like "ATOpenEVSE".

## A few notes about ISP programmers ##
You can use just about any ISP programmer. The [AVRISP mkII](http://store.atmel.com/PartDetail.aspx?q=p:10500054#tc:description) (~$35) is very popular. The [AVR Dragon](http://store.atmel.com/PartDetail.aspx?q=p:10500053#tc:description) (~$50) is my prefered weapon and most of my tutorial is written while using one. For those who have big budgets, the [STK600](http://store.atmel.com/PartDetail.aspx?q=p:10500155#tc:description) (~$200) is the ultimate programmer/debugger board. Many people get by with a simple _bit banger_ programmer (Google it) for less than $20. There is a very nice tutorial at [LadyAda.net](http://www.ladyada.net/learn/avr/programmers.html) that discusses programmer selection plus a whole lot more for AVR projects. It's worth spending 20 minutes reading through the whole tutorial.

### --> Notes unique to the AVR DRAGON ###
Since the Dragon is my programmer of choice, I have a few hints that will help others avoid the learning curve issues that I encountered.
  1. Update the firmware: From AVR Studio, click "Tools -> AVR Tools Firmware Upgrade". The upgrade tool will automatically detect the Dragon and tell you if it needs an update. Follow the directions. If you already have newer updates that were for Studio 6, it will prompt you to downgrade the firmware. Again, follow the prompts.
  1. Solder a few headers to the Dragon board if you plan on doing on-board programming/debugging. This is not required to use the Dragon as an ISP programmer, but sometimes it's nice to burn chips without connecting the ISP cable to your EVSE device. The Dragon has through-hole header holes, but does not come with all the headers installed. Choosing male or female headers is personal preference. Male headers require jumper wires with female connectors. Female headers can be jumpered with simple pieces of wire with a bit of insulation stripped back. You can also go hard core and solder the jumper wires directly into the board, but this is only recommended if you are certain that you will never want to use the Dragon to program a different type of chip.
  1. Buy a ZIF Socket and solder it to the prototyping area. You can get away with using a 28 pin socket, but that limits you to 28 pin or smaller chips. Buy the 40 pin socket and just use the portion you need. That way you will never wish you had a bigger socket.
  1. (TO DO: Take picture of Dragon with ZIF installed.)
  1. Use the right device [connection schematic](http://support.atmel.no/knowledgebase/avrstudiohelp/mergedProjects/AVRDragon/AVRDragon.htm#SCKT3200A2.htm). Assuming you soldered headers and a ZIF socket to your Dragon and have your ATmega328 chip installed in the ZIF socket, you will need to map the ISP header to the right pins to perform the programming. Click the link above to go straight to the right one.
  1. Read the schematic and pay attention to numbering. Sounds simple, I know, but pay attention to the numbering on the chip vs the numbering on the header. That 40 pin header is numbered for a 40 pin chip. You are connecting to a chip with 28 pins. Header pins 1-14 match chip pins 1-14, but header pins 15-26 don't connect to anything. Header pins 27-40 map to chip pins 15-28.
  1. **BUG ALERT!** I encountered a situation where the Dragon refused to enter programming mode several times. Google helped me discover that this is a fairly common problem when using a Dragon to do ISP programming in the Dragon's prototyping area. Don't assume you have a bad chip or a broken Dragon if you get this error. First, try the standard unplug, reconnect, restart Studio, and recheck that you have the wires connected properly. It is possible that the fuse bits got set for external oscillator (HIGHLY likely if you already followed the directions below for fuse bits!) and once that happens the chip needs to have an external clock source between pins 9 & 10 before it will do anything, including accept new programming. Atmel has nothing in their documentation about this, but thankfully the folks at [AVRFreaks](http://www.avrfreaks.net/index.php?name=PNphpBB2&file=printview&t=122619&start=0) figured this out. The solution is simple: plug the chip back into the OpenEVSE board instead of the Dragon prototyping area and connect the ISP cable. This works because the OpenEVSE board just happens to have an external oscillator connected to pins 9 and 10. You could also manually connect an extra oscillator into the prototyping area if you happen to have an extra one laying around.
  1. Consider using HVPP (High Voltage Parallel Programming) instead of ISP. While ISP is very simple and uses only a few jumper wires, high voltage programming on the prototyping area is much more powerful, faster, and avoids some of the warnings I mentioned above like failing to enter programming mode. The HV programming mode is required to rescue a chip that stopped responding due to improper fuse bit settings. No matter how bad you screwed it up, HV programming will bring it back (unless you are using Studio 6, then you're hosed). The only exception is chips that are physically damaged.

## --> Note about the DIY V4.0 PCB ##
If you ordered the DIY board from Osh Park and just spent 10 hours soldering little components to it, you are probably tired of soldering. Plug the iron back in and make a jumper wire connection to fix a mistake in the board design. The mistake isn't Osh Park's fault, they built exactly what the .brd file calls for. The mistake is a missing connection between pin 5 of the ISP header and pin 1 of the ATMega328. Without this connection, ISP programming is not possible. The connection can be created on the back of the board by soldering an insulated jumper wire to the same solder blob you created to connect the components. Be sure to only strip back a small chunk of insulation in order to avoid accidental shorting with adjacent pins.
(TO DO: Post picture of board with jumper installed)

If you don't want to make this jumper a permanent thing, just unsolder it after you get done programming the chip. It serves no purpose other than at programming.

## Set Fuse Bits ##
Setting fuse bits only **needs** to be done once per chip, but you can go back and reset them to different values as many times as you like. Fuse bits have nothing to do with power overload protection; they are the software equivalent of dip switches (if you are old enough to remember those...) and control how the chip operates. The officially supported fuse bit settings for OpenEVSE will be the best settings for most people, but if you want to experiment with different settings, you can calculate fuse settings here: http://www.engbedded.com/fusecalc

To set fuse bits from Atmel Studio, select "Tools -> Device Programming". Select your programmer from the _Tool_ drop down, select "ATmega328" from the _Device_ drop down, and select "ISP" from the _Interface_ drop down. _**NOTE:** Some people buy the ATMega328P, others buy the ATMega328. The "P" at the end makes a difference for the device signature. Be sure to select the right one for your chip. Also, there is some confusion about the "-PU" at the end of the model number. That is NOT a "P" chip, it designates the caterpillar-like PDIP packaging vs. the surface-mount square chips and both the "P" and "Non-P" ATMega328 chips have this._ Click the Apply button then click "Fuses" on the left side of the dialog window. From here, you can either click check boxes or go directly to the hex numbers at the bottom. I prefer going directly to the hex numbers since I already know what values to use. Use these settings: <br>
<pre><code>Extended: 0x05 <br>
High: 0xDA <br>
Low: 0xFF <br>
</code></pre>
The appropriate check boxes will automagically update in the top of the window.<br>
<b>NOTE:</b> The extended bits (efuse) setting may get a readback of "FD" rather than "05". This is okay. "FD" is functionally the same as "05" and you can use either value to accomplish the same thing.<br>
<br>
<br>
To send these settings to the chip, click the Program button.<br>
<br>
<b>CAUTION:</b> Do NOT set the RSTDSBL bit or the DWEN bit. If you do, the chip will no longer accept ISP programming instructions. As mentioned above, you can still save the chip by using high voltage programming in an AVR Dragon or STK600 programmer/debugger board. I can unlock chips for you too if you contact me.<br>
<br>
<h2>Burning a hex file to the chip</h2>
Assuming you have successfully programmed the fuse bits and have a stable connection to the chip and it enters programming mode when you need it to, start by just burning a pre-compiled HEX file. You can download one from the Downloads area of this project site. Save it to any convenient location.<br>
In Atmel Studio, click "Tools -> Device Programming". Follow the same setup process you used to program fuse bits, and then click "Memories" on the left pane. In the "Flash (32KB)" area, keep the default check boxes checked, navigate to the file you downloaded and then click the Program button. Done! You now have a chip that will function in an Open EVSE board. If you get a chip that already has a program on it, you can save the existing program prior to burning a new one by clicking the "Read..." button and saving the file somewhere you can find. Feel free to open the HEX file in Notepad or Wordpad. You can't read anything useful, but it's kind of cool to see what the chip actually reads to perform the magic.<br>
<br>
<h2>Changing source code</h2>
If you've made it this far, Congratulations! You are now ready to start the real work. The entire OpenEVSE firmware source code is built for the Arduino IDE. That means you need to modify the header <i>#includes</i> and go download some external libraries. If you just try opening and compiling the source code, you will get many errors for missing libraries.<br>
<ul><li>Download the following files and save them to C:\Program Files\Atmel\AVR Tools\AVR Toolchain\avr\. Be sure to create a separate directory for each pair of .h & .cpp files that is named the same as the files. Ex: WProgram.h & WProgram.cpp go in a directory named WProgram.<br>
</li></ul><ol><li><a href='http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/WProgram.h'>http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/WProgram.h</a>
</li><li><a href='http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/WProgram.cpp'>http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/WProgram.cpp</a>
</li><li><a href='http://arduino-time.googlecode.com/svn/trunk/Time.h'>http://arduino-time.googlecode.com/svn/trunk/Time.h</a>
<ol><li><a href='http://arduino-time.googlecode.com/svn/trunk/Time.cpp'>http://arduino-time.googlecode.com/svn/trunk/Time.cpp</a>
</li></ol></li></ol><ol><li><a href='http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/pins_arduino.h'>http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/pins_arduino.h</a>
</li><li><a href='http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/pins_arduino.cpp'>http://arduino.googlecode.com/svn/trunk/hardware/arduino/cores/arduino/pins_arduino.cpp</a>
<ol><li><a href='http://arduino.googlecode.com/svn-history/r1092/trunk/libraries/Wire/Wire.h'>http://arduino.googlecode.com/svn-history/r1092/trunk/libraries/Wire/Wire.h</a>
</li><li><a href='http://arduino.googlecode.com/svn-history/r1092/trunk/libraries/Wire/Wire.cpp'>http://arduino.googlecode.com/svn-history/r1092/trunk/libraries/Wire/Wire.cpp</a>
</li></ol><ul><li>Edit the source code to include "avr/" in front of the .h files. Example:<br>
<pre><code>#include &lt;avr/EEPROM.h&gt;<br>
#include &lt;avr/wdt.h&gt;<br>
#include &lt;avr/pgmspace.h&gt;<br>
#include &lt;avr/pins_arduino.h&gt;<br>
#include &lt;avr/Wire.h&gt;<br>
#include &lt;avr/Time.h&gt;<br>
</code></pre>
(TO DO: Show how to download and configure libraries)</li></ul></li></ol>

(TO DO: Walk through a complete compile/upload of known stable code)<br>
<br>
(TO DO: Make modifications and compile/upload them)