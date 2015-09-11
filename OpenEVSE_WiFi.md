This solution does not require any additional code on the OpenEVSE side. Here is how I did it...


# Parts: ~$60 #

RN-XV wifly Module - U.FL Connector $34.95
https://www.sparkfun.com/products/11048

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/1/0/4/8/11048-01_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/1/0/4/8/11048-01_i_ma.jpg)

Xbee Explorer Regulated $9.95
https://www.sparkfun.com/products/11373

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/1/3/7/3/11373-01_medium.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/1/3/7/3/11373-01_medium.jpg)

2.4GHz Duck Antenna RP-SMA - Large $9.95
https://www.sparkfun.com/products/558

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/5/5/8/00558-1_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/5/5/8/00558-1_i_ma.jpg)

Interface Cable RP-SMA to U.FL $4.95
https://www.sparkfun.com/products/662

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/6/6/2/00662-1_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/6/6/2/00662-1_i_ma.jpg)

Jumper wire $1.50
https://www.sparkfun.com/products/10371

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/0/3/7/1/10371-01_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/0/3/7/1/10371-01_i_ma.jpg)

Break Away Male Headers - Right Angle
https://www.sparkfun.com/products/553


![https://dlnmh9ip6v2uc.cloudfront.net/images/products/5/5/3/00553-03-L_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/5/5/3/00553-03-L_i_ma.jpg)


# Programming Cable for WIFI Module (optional) #

3.3v FTDI $14.95
https://www.sparkfun.com/products/9873

![https://dlnmh9ip6v2uc.cloudfront.net/images/products/9/8/7/3/09873-01_i_ma.jpg](https://dlnmh9ip6v2uc.cloudfront.net/images/products/9/8/7/3/09873-01_i_ma.jpg)

# WIFI Module Configuration #

There are several ways to program the module to connect to your network. The easiest is with a 3.3v FTDI cable with a terminal set to 9600 enter $$$ at the prompt and use the guide for ssid, ip, change uart to 38400 for OpenEVSE, etc. http://dlnmh9ip6v2uc.cloudfront.net/datasheets/Wireless/WiFi/WiFly-RN-UM.pdf


An alternate is to setup a ad-hoc network with SSID roving1, the module will join. the tricky part is discovering the modules ip address. With the IP address telnet to the IPaddress:2000 and type $$$

# Connect to OpenEVSE via WIFI #

Once configured you can access OpenEVSE SerialCLI using a telnet app (I like PuTTY) via the IPaddress:2000 (example 192.168.1.123:2000).


The Module also has a HTTP client so it will not be too hard to send data to a webserver in the future...