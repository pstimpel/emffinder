# EMF Finder / EMF Detector 2.0
## 3d Printed arduino based emf detector

License: https://creativecommons.org/licenses/by-nc-sa/4.0/

The result of this project is a 3D printed, arduino nano driven EMF detector. Yes, you could go for hunting ghosts, or you could try to find sources of electro magnetic fields creating noise in your speakers, or killing the functionality of your gadgets.

### Project URLs

https://www.prusaprinters.org/prints/21355-emf-finder-detector-20

https://pinshape.com/items/59651-3d-printed-emf-finder-detector-20

https://www.thingiverse.com/thing:4153746

## Why do we need another one?

Yes, this project is based on some videos I found. However, I thought I could push it further. This design does only use one resistor to drive all of the LEDs, other designs were using 10 of those, which is kind of a waste. And, I thought it would be cool to be able to change the sensitivity. So I added a switch to do exactly that.

## Video introduction

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/HLuinPxlC7E/0.jpg)](https://www.youtube.com/watch?v=HLuinPxlC7E)
 

## What we need

### Electrics/electronics
- Arduino Nano 3.0 5V (https://www.amazon.de/Anpro-Entwicklerboard-Atmega328P-Arduino-EINWEG/dp/B07H2VT2JN/)
- 10 red LED 5mm (https://www.reichelt.de/led-5-mm-bedrahtet-rot-fr-led-5-rd-dif-p230933.html)
- 1 resistor 3.3 MOhm (https://www.reichelt.de/widerstand-kohleschicht-3-3-mohm-0207-250-mw-5-1-4w-3-3m-p1398.html)
- 1 resistor 330 Ohm (https://www.reichelt.de/widerstand-kohleschicht-330-ohm-0204-0-125-w-5-k-o-rd18jn331t52-p237355.html)
- 1 Diode 1N4001 (https://www.reichelt.de/gleichrichterdiode-50-v-1-a-do-41-1n-4001-p1723.html)
- Buzzer 5 Volts (https://www.amazon.de/gp/product/B073RH8TQK/), we need the bigger one out of the package
- 2 switches (https://www.amazon.de/gp/product/B07MY2WVQ3)
- some strand wire, about 400 mm (https://www.amazon.de/gp/product/B01BI1G88C)
- some more heavy wire, about 500 mm, for our antenna. It should maintain its form if you bend it!
- 4 screw terminals, 5mm, 2 pins (https://www.amazon.de/gp/product/B07K31L4FH/)
- battery connector for 9V batteries (https://www.amazon.de/Neuftech®-Batterie-Anschluss-Anschlusskabel-schwarz/dp/B00YTRNLGU/)
- a 9V battery (https://www.amazon.de/Varta-Longlife-Batterie-Alkaline-Batterien/dp/B004WYN62O/)
- stuff to create a pcb, or a supplier for your pcb
- soldering stuff

### 3D-printing
- pla filament of your choice, I was using https://dasfilament.de - which is my favorite supplier
- a 3d printer

### Tools, other stuff
- 11 screws M3x8, cylinder head (https://www.schrauben-paul.com/DIN-912-Zylinderkopfschraube-Edelstahl-A2-ISK-M-3-x-8-Inhalt-100-Stk)
- 1 screw M3x8, countersunk (https://www.schrauben-paul.com/ISO-10642-Maschinenschraube-Innensechskant-Edelstahl-A2-M-3x8-Inhalt-100-Stk)
- screwdriver

##  How to assemble
First we need to create the PCB. You can do it yourself which I find is much fun. Or you could send the files to your favorite supplier. 

![alt text](https://github.com/pstimpel/emffinder/raw/master/media/board.jpg "schematic")

Once you received the board, you have to solder the parts to it. Put the board in front of you, copper side down, two big holes upwards. I suggest you this order, but put the Arduino sketch onto your Arduino before soldering it to the board:

1. Resistors
2. Diode
3. Arduino
4. Buzzer
5. Screw Terminals
6. LEDs

Make sure not to confuse the direction of some parts.

1. Arduino: USB faces to the right
2. Buzzer: the longer poin is +, facing upwards
3. Diode: ground points upwards
4. LEDs: shorter pin is ground, point downwards

![alt text](https://github.com/pstimpel/emffinder/raw/master/media/circuitscheme.jpg "schematic")

Next, 3D print the items. I was using a .4 nozzle on my Prusa I3 Mk3. I used 0.3 layer hight, 3 shells horizontal and vertical, and 10% cubic infill. No support needed.

Now mount the PCB into the Base, using 3 screws M3x8 cylinder head. Solder 2 100mm wires to the switch, repeat this for the second switch. Mount the switches into their position of the Base.

![alt text](https://github.com/pstimpel/emffinder/raw/master/media/assembly.jpg "schematic")

Cut the more heavy wire into half, and use something small like a small pencil to create your antennas by fiddling the wire around the pencil. Do this twice, and cut 3cm of the isolation if each antenna wire. 

![alt text](https://github.com/pstimpel/emffinder/raw/master/media/antenna.jpg "schematic")


Connect it to each other, and mount it into the 3D printed Antenna piece. Now, push it through the big hole at the upper side of the base. Connect it to the left connector of the screw terminal top/middle of the PCB. Use 2 M3x8 cylinder head screw to mount Antenna to Base.

Connect the On/Off switch to the left side, upper screw terminal.

Connect the Range switch to the top right screw terminal.

Connect the battery connector to the left screw terminal, left side, bottom. Ground is the upper connector, voltage is the connector downwards.

Time for a first test. Connect the battery, switch your device on using the upper switch. You see the LEDs flickering? If not, approach something like a TV, or mobile phone. Using the lower switch, you can switch between two ranges of sensitivity.

If all works as expected, put the Top onto the Base, and use 6 M3x8 cylinder head screws to close your device. 

Finally, put the battery into its place, and close the battery case useing the Cover, and the M3x8 countersunk screw.

![alt text](https://github.com/pstimpel/emffinder/raw/master/media/readtouse.jpg "schematic")

Done!


