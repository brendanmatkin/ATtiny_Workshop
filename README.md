Shrinking the Arduino: Intro to ATtiny
===============
Workshop: Techniques & Discussion
---------------------------------
ATtiny is a super cheap, low power, Arduino compatible microcontroller. This repository contains all of the technical info and code necessary to complete the "Shrinking the Arudino: Introduction to ATtiny" workshop. It is a result of me sifting through and gathering my favorite tools and information for programming the Atmel ATtiny84/85 with the Arduino IDE. If you feel that I missed something important or did something stupid, feel free to send a pull-request, message, or issue. 

Locations
---------
Previous:
* [Eastern Bloc](http://www.easternbloc.ca) in Montreal, QC
Coming soon:
* [Beakerhead](http://beakerhead.org) in Calgary, AB
* TBA in Lethbridge, AB

Suggested Parts List
--------------------
* ATtiny84A-20PU
* CR2032
* 20mm Battery Holder
* [Simple Vibration Switch](https://www.adafruit.com/products/1766) 
* RGB LED (I'm using 5mm diffused common anode)
* 220 Ohm 1/4 watt resistor
* 8 pin DIP socket
* Female header
* 10uF Capacitor 
* Arduino UNO (for programming)
* probably some wire scraps
* 6 jumper wires
* probably a bread board
* Soldering iron, solder, wire snips, hot glue

Basic Instructions
------------------
1. Install the arduino-tiny core and copy relevant board information from "Prospective Boards.txt" to "boards.txt". Start with ATtiny84 @ 8MHz (internal, no BOD) and any others you want (probably also 1Mhz internal)
2. Breadboard the ATtiny circuit according to schematic
3. Upload file/examples/ArduinoISP to UNO. Connect ATtiny RESET, MOSI, MISO, SCK to UNO pins 10, 11, 12, 13 respectively. Connect VCC to UNO 5V and GND to GND and place a 10uF capacitor across RESET and GND on UNO.
4. Choose tools/boards/ATtiny84 @ 8MHz (internal, no BOD) (or the chip you are using)
5. Select UNO COM port
6. Select tools/programmer/Arduino as ISP
7. Tools/Burn Bootloader (first time only or when changing frequency or BOD)
7. Upload your code (if you get an error that starts with: "avrdude: please define PAGEL and BS2" you can ignore it - It's possible to get rid of it but a huge pain and not necessary)
8. Solder your circuit

If you choose to include female header on your circuit, you can reprogram the ATtiny without removing it. Just be sure to disconnect the battery and power with 5V from UNO. 

Useful Links
------------
* [arduino-tiny core](https://code.google.com/p/arduino-tiny/)
* Alternate core and tutorial by MIT [high-low tech](http://highlowtech.org/?p=1695)
* Great info on [AVR interrupts & sleep](http://www.gammon.com.au/interrupts)
* Specific to ATtiny - pin change interrupt, [down to 500nA!](http://www.gammon.com.au/forum/?id=11488&reply=9#reply9)
* [Make Magazine ATtiny intro](http://youtu.be/30rPt802n1k)
* Quick prototyping, forum, & modified libraries: [Digispark](http://digistump.com/products/1)
* Watchdog timer-based sleep/interrupt: [H2OhNo! Tutorial](https://learn.sparkfun.com/tutorials/h2ohno/low-power-attiny)
* Chip info & datasheets: [Atmel tinyAVR](http://www.atmel.ca/products/microcontrollers/avr/tinyAVR.aspx)
* AVR [fuse calculator](http://www.engbedded.com/fusecalc)
* [Paperduino](http://paperduino.eu/doku.php?id=start)
* Usb Bootloader on DigiSpark & Paperduino: [micronucleus](https://github.com/micronucleus/micronucleus)
* [TinyTX](http://nathan.chantrell.net/tinytx-wireless-sensor/)
* Pre-built sensor code: [TinyTX github](https://github.com/nathanchantrell/TinyTX)