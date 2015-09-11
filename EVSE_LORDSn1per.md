# Parts List #

| **Part** | **Source** | **Cost** | **Postage** | **Quantity** | **Link** |
|:---------|:-----------|:---------|:------------|:-------------|:---------|
| Arduino UNO | eBay       | $35      | $0          | 1            | http://www.ebay.com.au |
| Open EVSE Shield | Open EVSE  | $45      | $10         | 1            | http://code.google.com/p/open-evse/wiki/Ordering |
| EV Simulator | Open EVSE  | $15      | $10         | 1            | http://code.google.com/p/open-evse/wiki/Ordering |
| 240v 30A Relay with 12v coil | RS Components | $35.31   | $0          | 1            | http://australia.rs-online.com  Part: 235-5469|
| RGB LCD Shield 16x2 Positive Display | Adafruit   | $23.95   | $45.55      | 1            | http://adafruit.com/products/716 |
| J-1772 with 3m Cable - 30A | EV Power   | $161.80  | $23         | 1            | http://ev-power.com.au/webstore/index.php/sae-charging-plugs-sockets/ev-charging-plug-sae-j1772.html |
| CR8420-1000-G Current Transformer | Amazon     | $10.67   | $6.12       | 1            | http://www.amazon.com/gp/product/B005CWO4X0/ref=ox_ya_os_product |
| 12v DC 400mA power supply | Jaycar     | $15.95   | $0          | 1            | http://www.jaycar.com.au/productView.asp?ID=MP3147 |
| Chrome push button with Green LED circle | Jaycar     | $10.95   | $0          | 1            | http://www.jaycar.com.au/productView.asp?ID=SP0797 |
| 8-13mm Cable Gland | TLE Electrical | $2.84    | $0          | 1            |          |
| 11-17mm Cable Gland | TLE Electrical | $3.73    | $0          | 1            |          |
| 15A power plug | TLE Electrical | $8.00    | $0          | 1            |          |
| 1 meter - 4mm power cable | TLE Electrical | $4.21    | $0          | 1            |          |
| IP55 150x220x75mm modular box | TLE Electrical | $38.42   | $0          | 1            |          |
|          |            |          |             |              |          |
| **TOTAL** |            | **$414.72**| **$94.67**  |              | **TOTAL $509.39** |


# Introduction #
The Following photos illustrate installation of an Arduino UNO, Arduino Shield, an Adafruit RGB LCD open EVSE.

My primary goal was to build an EVSE for under $1000. Living here in Australia a simple EVSE was $4999 and a CHEAP one was $1899! In Australia our electricity is 240v in either 10A or 15A. The supplied EVSE for my Nissan Leaf was 240v 10A but I'd like to have a permanent EVSE on the wall in my garage that can supply 15A.

I plan that my EVSE will be of high commercial standards,offering good weather protection ,and incorporating latest firmware. The adafruit RGB display was utililised as well as a MENU button.

A BIG THANKS must go out to Chris Howell for all his help and email support. What a big help he has been.

# Problems Encountered #
**No Pilot**
On the open EVSE Arduino shield the word PILOT is next to the ground pin, not the PILOT pin. There's no information that I could find to tell you this. So use the ROUND pin, not the square one as pictured. This was made difficult because once you solder on the screw terminal, you can't see the word pilot or the tracks. THANKS CHRIS for helping me out with this problem!!

![http://farm9.staticflickr.com/8203/8208823787_0de13bd47c.jpg](http://farm9.staticflickr.com/8203/8208823787_0de13bd47c.jpg)



**Proximity circuit not working**
Inside the handle is a microswitch under the button. The proximity circuit should read 150 ohms between ground and blue wire (normally) when the button is NOT pressed, and 480 Ohms when PRESSED. If it reads 480 Ohms the EVSE will NOT start charging. In mu case, my brand new J1772 handle was assembled in a way that kept the switch push ON all the time, reading 480 Ohms. The microswitch in my handle had the metal bent up too high so when the button was installed, it would press the switch, so I had to bend the metal downwards. THANKS CHRIS for helping me out with this problem!!

![http://farm9.staticflickr.com/8202/8208836539_ba39eb166b.jpg](http://farm9.staticflickr.com/8202/8208836539_ba39eb166b.jpg)

**Ground**
After fixing the pilot as above, I had to rund the ground wire to EARTH. There was little information showing this, without it, the pilot has no ground reference. THANKS CHRIS for helping me out with this problem!!!!


# Photos #
Starting to build the RGB LCD from Adafruit.
![http://farm9.staticflickr.com/8186/8140995544_d8bb15ca27_c.jpg](http://farm9.staticflickr.com/8186/8140995544_d8bb15ca27_c.jpg)


Finished assembling the RGB LCD screen from Adafruit. ![http://farm9.staticflickr.com/8049/8140962969_f8fce06df9_c.jpg](http://farm9.staticflickr.com/8049/8140962969_f8fce06df9_c.jpg)


My first Arduino program to test LCD.
![http://farm9.staticflickr.com/8196/8140962439_ba0a9c21d0_c.jpg](http://farm9.staticflickr.com/8196/8140962439_ba0a9c21d0_c.jpg)


Modified v1.0.0 to add my name and KW power display next to timer. ![http://farm9.staticflickr.com/8473/8140962169_ea7fe36a84_c.jpg](http://farm9.staticflickr.com/8473/8140962169_ea7fe36a84_c.jpg)


J-1772 with a 3m cable.
![http://farm9.staticflickr.com/8331/8140963675_ecd22726b7_c.jpg](http://farm9.staticflickr.com/8331/8140963675_ecd22726b7_c.jpg)


v1.0.3 now displays cost instead of KW.
![http://farm9.staticflickr.com/8336/8146088094_17ca9c94f7_c.jpg](http://farm9.staticflickr.com/8336/8146088094_17ca9c94f7_c.jpg)

Finished building the Open EVSE Arduino Shield. Note I have put [R1](https://code.google.com/p/open-evse/source/detail?r=1) in [R20](https://code.google.com/p/open-evse/source/detail?r=20). That will be removed and [R20](https://code.google.com/p/open-evse/source/detail?r=20) and [R1](https://code.google.com/p/open-evse/source/detail?r=1)'s position by accident. I have now replaced both of them with blue metal film 1Kohm 1% resistors.
![http://farm9.staticflickr.com/8060/8165693419_fbb68782f9_c.jpg](http://farm9.staticflickr.com/8060/8165693419_fbb68782f9_c.jpg)

Finally received the CR-8420 current sensor from America. Now I have all the parts to assemble my open EVSE
![http://farm9.staticflickr.com/8199/8177428284_6850886f7c_c.jpg](http://farm9.staticflickr.com/8199/8177428284_6850886f7c_c.jpg)

Now I have bought a box
![http://farm9.staticflickr.com/8208/8206294563_2224e84fa3_c.jpg](http://farm9.staticflickr.com/8208/8206294563_2224e84fa3_c.jpg)


Added the 240v in and J-1772 cord out

![http://farm9.staticflickr.com/8202/8207381450_72c83dc14f_c.jpg](http://farm9.staticflickr.com/8202/8207381450_72c83dc14f_c.jpg)


Placed the relay and earth terminal block
![http://farm9.staticflickr.com/8479/8206289551_cb9bb83352_c.jpg](http://farm9.staticflickr.com/8479/8206289551_cb9bb83352_c.jpg)


Placing the Arduino, Open EVSE shield and 12v power pack
![http://farm9.staticflickr.com/8486/8206290453_0b1f7c6b2e_c.jpg](http://farm9.staticflickr.com/8486/8206290453_0b1f7c6b2e_c.jpg)


Wired up and added the LCD screen too
![http://farm9.staticflickr.com/8064/8206283327_202a3ac8cf_c.jpg](http://farm9.staticflickr.com/8064/8206283327_202a3ac8cf_c.jpg)


Just need to add the J-1772 wires now

![http://farm9.staticflickr.com/8200/8206284923_e72fb25a19_c.jpg](http://farm9.staticflickr.com/8200/8206284923_e72fb25a19_c.jpg)

All wired up now. I have now connected cable to earth.
![http://farm9.staticflickr.com/8484/8206787091_16e6cdf48f_c.jpg](http://farm9.staticflickr.com/8484/8206787091_16e6cdf48f_c.jpg)

When I plugged into my Leaf it would change to EV CONNECTED but would not start charging. BIG THANKS to Chris Howell for his help. It turned out to be the switch inside the charging connector was stuck DOWN. I pulled apart the handle and fixed the switch. Now it correctly has 150 ohm from blue wire to ground when the button is NOT pressed, and 480 Ohn when the button IS pressed. Now to try it out tonight. If everything works then I can work on cleaning up the wiring and making a label to go on the INSIDE of the lid to hide all the electronics.
![http://farm9.staticflickr.com/8059/8207877040_112ef2b3d1_c.jpg](http://farm9.staticflickr.com/8059/8207877040_112ef2b3d1_c.jpg)

Just a photo to show the inner workings a bit clearer. I still have to clamp down that 12v transformer.
![http://farm9.staticflickr.com/8066/8206793313_fd73ee4832_c.jpg](http://farm9.staticflickr.com/8066/8206793313_fd73ee4832_c.jpg)


My first CHARGE!!! Charging my nissan Leaf at 10A (2391 watts)
![http://farm9.staticflickr.com/8340/8207136683_43eeff2aa6_c.jpg](http://farm9.staticflickr.com/8340/8207136683_43eeff2aa6_c.jpg)

Charging in the dark. I am not a fan of the clear lid so I will work on a way to cover that up.
![http://farm9.staticflickr.com/8062/8208812231_71fdd93a39_c.jpg](http://farm9.staticflickr.com/8062/8208812231_71fdd93a39_c.jpg)

Today, December 11th 2012 I got the power point installed to my garage. I wasted no time installing the EVSE
![http://farm9.staticflickr.com/8338/8264423430_e6524d748a_c.jpg](http://farm9.staticflickr.com/8338/8264423430_e6524d748a_c.jpg)

Here is the EVSE installed with the charging cable hanging on the wall.
![http://farm9.staticflickr.com/8224/8263355397_decbdc8ac3_c.jpg](http://farm9.staticflickr.com/8224/8263355397_decbdc8ac3_c.jpg)

My first charge at 15 Amps!
![http://farm9.staticflickr.com/8217/8264425474_4a269305c8_c.jpg](http://farm9.staticflickr.com/8217/8264425474_4a269305c8_c.jpg)

Charging my car from my garage using open EVSE.
![http://farm9.staticflickr.com/8203/8264421872_577ba5537f_c.jpg](http://farm9.staticflickr.com/8203/8264421872_577ba5537f_c.jpg)

Car is just about full. There was 37km left in the battery when I started charging.
![http://farm9.staticflickr.com/8363/8263353547_ef0351a63b_c.jpg](http://farm9.staticflickr.com/8363/8263353547_ef0351a63b_c.jpg)

Here is the EVSE mounted again
![http://farm9.staticflickr.com/8072/8263351845_e88bc69e86_c.jpg](http://farm9.staticflickr.com/8072/8263351845_e88bc69e86_c.jpg)

Here is the little power sensing board I made to measure REAL current being drawn from the power point.
![http://farm3.staticflickr.com/2870/9071516117_4c9278b089_c.jpg](http://farm3.staticflickr.com/2870/9071516117_4c9278b089_c.jpg)


# Videos #

First boot up of arduino UNO

http://www.youtube.com/watch?nomobile=1&v=DShKkW-Ruao

Booting up v1.0.3 of my customised evse
Includes my name with animation
Includes the price being drawn next to timer. The cents per kwh has to be manually programmed in but I'm working on creating a new menu so you can change it using the button and LCD screen.
http://www.youtube.com/watch?v=jZVIEaFd99M


Here is a video of me testing the Arduino based open EVSE with a relay connected.
http://www.youtube.com/watch?nomobile=1&v=v795UG82kxM

# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages