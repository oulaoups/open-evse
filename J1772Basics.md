# Introduction #

Basics of the J1772 standard.

# Charging #

| | Voltage | Max Current |
|:|:--------|:------------|
| Level 1 (L1) | 120VAC  | 16A max per J1772|
| Level 2 (L2) | 208 - 240VAC | 80A         |

# Pilot #

![http://farm9.staticflickr.com/8398/9020779024_283cdd58f8_b.jpg](http://farm9.staticflickr.com/8398/9020779024_283cdd58f8_b.jpg)


# Max Current #


| Duty Cycle | Max Current |
|:-----------|:------------|
| < 3%       | Error       |
| 3% - 7%    | Digitial Com Required |
| 10% - 96%  | 6A - 80A    |
| >96        | Error       |

![http://farm6.staticflickr.com/5453/9018558031_dc6f8d9c8c_b.jpg](http://farm6.staticflickr.com/5453/9018558031_dc6f8d9c8c_b.jpg)


# Pilot States #
![http://farm6.staticflickr.com/5454/9020798724_df0ed0ebd4_b.jpg](http://farm6.staticflickr.com/5454/9020798724_df0ed0ebd4_b.jpg)
# Proximity #
The proximity runs between the EV and the J1772 handle, some J1772 cordsets include 4 wires (AC Hot 1, AC Hot 2, Ground, Pilot) and some have 5 wires an additional to access the proximity circuit.

From the J1772 handle (not connected to vehicle) the proximity circuit should read about 150 ohms when measured from proximity to ground. When the button is pressed the reading should increase to about 480 ohms. The change in resistance signals the EV to stop pulling current. The relay in the EVSE will stay closed until the pilot is dropped however J1772 compliant EVs will stop pulling significant current.


![http://farm6.staticflickr.com/5331/9018719465_9df5c4392e_b.jpg](http://farm6.staticflickr.com/5331/9018719465_9df5c4392e_b.jpg)

**Note**- There have been many reports of missing proximity components or binding in the switch of inexpensive J1772 cables from China. Before using on of these cables measure resistance in the proximity circuit and ensure the resistance drops as expected when the button is pressed.