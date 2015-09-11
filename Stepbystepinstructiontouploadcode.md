# Introduction #

These are my notes on what I needed to get, install, change to be able to upload code to the open evse board. Your experience may vary.


# Details #

## Preparation ##
### ISP ###
Since the board does not have bootloader, you would need an ISP programmer. The one I used is the sparkfun usbtinyisp:
$15 http://www.sparkfun.com/products/9825
It came with a 6 pin cable - so you can plug it directly to the 6 pin header on the open evse board.
It took some time to figure out the orientation of the header so here is a photo of the ISP and open evse board connected.

### Mini-usb cable ###
You would need mini usb to usb cable to connect your computer to the ISP programmer.

### Arduino programming environment ###
This would allow you to compile and upload the code, download it here:
http://arduino.cc/en/Main/Software
I downloaded the latest version 1.0.

After download and unpacking I needed to change few things:
  * #1 Find and download the Time library
I downloaded it from here:
http://www.arduino.cc/playground/uploads/Code/Time.zip and unpack it in the libraries arduino IDE folder - for me (on Windows 7) that was <install dir>\arduino-1.0-windows\arduino-1.0\libraries. The library zip file contained 3 folders - so I got Time, DateTime and a 3rd library.

  * #2 Add definition for the evse board
add to <install dir>\arduino-1.0-windows\arduino-1.0\hardware\arduino\boards.txt the following lines:
```
##############################################################

usbtiny328.name=[usbtinyisp]OPEN EVSE

usbtiny328.upload.using=usbtinyisp
usbtiny328.upload.maximum_size=32768

usbtiny328.build.mcu=atmega328p
usbtiny328.build.f_cpu=16000000L
usbtiny328.build.core=arduino
usbtiny328.build.variant=standard
```

  * #3 Download and install the usbtinyisp driver
I downloaded it from here http://www.sparkfun.com/datasheets/Programmers/pocketprog-driver.zip

## Ready ##
You are now ready.
  1. Start up the Arduino IDE (in <install dir>\arduino-1.0-windows\arduino-1.0\arduino.exe)
  1. Open and load the source code for the firmware
  1. Select the target board from Tools->Board->[usbtinyisp](usbtinyisp.md)OPEN EVSE
  1. Select programmer from Tools->Programmer->USBTinyISP
  1. Import Time library from Sketch->Import Library->Time (not sure if this is absolutely needed)
  1. Connect the usbtinyisp board to your computer with the usb cable, and to the open evse board with the header cable.
  1. Test your code with Sketch->Verify/Compile (or Ctrl+R)
  1. Upload the sketch to the open evse board using File->Upload.


## Done ##
You should now have your open evse with a new functionality.