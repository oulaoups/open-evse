# Introduction #

If you're reading this page, it probably means that you were left a courtesy note by someone while your car was charging. They probably left it because they connected your car to a device called the J1772 Hydra, either after disconnecting your car or noticing that you were waiting for a charge.

# The J1772 Hydra #

The J1772 Hydra is a device intended to allow two Electric Vehicles (EVs) to share a single EVSE (Electric Vehicle Servicing Equipment - the acronym for a car charger). It does this one of two ways: either by allowing the vehicles to simultaneously share, or by seamlessly sequencing them.

In shared mode, each car is allowed to draw 50% of the power available from the charger so long as both of them are charging. When one car finishes, the other car will be shifted up to full power.

In sequential mode, full power is given to the first car until it finishes. When it does, the other car will be given an opportunity to request power.

Rest assured that the Hydra is safe and fully compliant with the J1772 specification. Since each Hydra is built by its owner, the designers of the Hydra cannot guarantee that it is impossible for a Hydra to cause any damage. However, we have taken great pains both in the firmware and hardware design to insure safety and compatibility.

Most public EVSEs are rated for 30 amperes of current - either 6.2 kW or 7.2 kW, depending on the voltage. Many EVs will take full advantage of this power, but some EVs (All current plug-in Hybrids and many Leafs) only charge at 3.3 kW - 15 amperes. Given this state of affairs, a low power EV can share the EVSE without any change. The charge will happen at the same rate, and more importantly will take the same amount of time.

Two high-powered EVs can use the Hydra to share an EVSE, but in shared mode they will charge at half the speed they would alone. That still provides a benefit, however, since both cars will be making profitable use of the time, rather than one waiting for the other, and there is no need to switch the plug when the first vehicle completes. In sequential mode, the first car will charge identically to how it would by itself. When it finishes, the second car will begin charging without human intervention.

If you were charging at a public station that charges a fee, and your charging was interrupted briefly, then you should realize that the Hydra owner will have assumed the cost - you get the remainder of the charging for free. If your car did not immediately resume charging, then that likely means that your car was not set to automatically resume charging after the interruption. Hopefully, the Hydra owner left your car plugged in in the hopes that you would remotely reactivate it. You should consider configuring your car for automatic charging when using public chargers. Even absent human intervention, there are any number of reasons that your charge may be briefly interrupted (for instance, power glitches or software errors that cause the EVSE to reboot).

If your car does have a high-powered charger, and you were connected to a Hydra set for shared mode, then your charging will have been slowed by 50%. It is not considered acceptable etiquette for a Hydra owner to do this without seeking the permission of the other owner. It is possible that the Hydra owner did not realize that your car was a high powered car (this can happen if your car is a Leaf - most Leafs only charge at 3.3 kW, but some newer ones do not). If your car has a 3.3 kW charger, then your car will have charged at the same speed whether the Hydra was configured for shared or sequential mode.

The Hydra has an LCD display on it. The top line displays the available power from the host EVSE on the left, and the operating mode on the right. The bottom line shows status for each car. If a car is charging, then it will show how much current the car is taking. Other things that can appear for each car are "wait" (in sequential mode, a car is connected, but waiting for the first car to finish), "off" (the car is connected, but not requesting power), "---" (no car is connected), or "ERR" (some error condition has occurred).

If your car is still connected to the Hydra as you're reading this, then you are free to disconnect the plug whenever you like. It should work exactly the same as any other J1772 plug. If there is another car in range waiting to charge, then feel free to connect them up. Otherwise, just leave your plug and cable coiled up near the Hydra - its owner will take care of it when they return.

If you'd like more information about the Hydra, then you can visit [its page on this wiki](https://code.google.com/p/open-evse/wiki/Hydra).

Those of you contemplating building a Hydra for use at public charging stations should make some business cards with this graphic on it:

![http://chart.apis.google.com/chart?chs=200x200&cht=qr&chld=|1&chl=http%3A%2F%2Fcode.google.com%2Fp%2Fopen-evse%2Fwiki%2FHydraCourtesyNote&ignore=.gif](http://chart.apis.google.com/chart?chs=200x200&cht=qr&chld=|1&chl=http%3A%2F%2Fcode.google.com%2Fp%2Fopen-evse%2Fwiki%2FHydraCourtesyNote&ignore=.gif)

That graphic will link back to this page. You should also put contact information on the card.