# micro:Maqueen Library for Arduino

A simple library for the DF Robot micro:Maqueen robot, using a BBC Micro:Bit controller.  

For this project you will need at least one Micro:Bit Controller:
https://www.dfrobot.com/product-1625.html or https://www.dfrobot.com/product-1587.html   

And the Maqueen Robot chassis: https://www.dfrobot.com/product-1783.html   

## Installation

Library should be in the library manager of Arduino, search for "Maqueen".  

Prerequisites: 
1) Install the Arduino-nRF5 board core. Follow instructions here:  
https://github.com/sandeepmistry/arduino-nRF5  
2) Install the Adafruit Micro:Bit Library.  
https://github.com/adafruit/Adafruit_Microbit and learn more about it here:  https://learn.adafruit.com/use-micro-bit-with-arduino   
3) Install the arduino-BLEPeripheral library by following instructions here:  
https://github.com/sandeepmistry/arduino-BLEPeripheral   
4) Install the NewPing Library: https://github.com/eliteio/Arduino_New_Ping  
5) Install the NRF51 Libary: https://github.com/tipih/NRF51_Radio_library  

Experimental, but useful:
Sparkfun's Mag3110 compass library - https://github.com/sparkfun/SparkFun_MAG3110_Breakout_Board_Arduino_Library   

## Known Issues 
### or What is working and what is not working.

from time to time you have to reload the Micro:bit controller with a HEX file from
makecode, you may have to do this the first time you use it with the Arduino IDE.  
Generally I see this issue when I try to open the serial port before it's ready.  

The Maqueen robot has 4 Neopixels on PIN 15, currently this is not supported in any Neopixel library that I have seen. The Neopixels do work with the Makecode IDE, so this is a limitation of Arduino/Neopixel Libraries (I believe).  

The IR remote sensor works, but not as well as it could. I am using a very old method to read the IR data, using pulseIn. This works, but is limited.  

---The biggest issue I've run across so far is no peer-to-peer support in the Arduino IDE.  I am not even sure how it works. Again this is a non-issue with Makecode.---  
BLE works, and Adafruit does provide an app for Android phones that support BLE. I was able to setup remote control via that app, and using one of Adafruits base sketches.  
https://play.google.com/store/apps/details?id=com.adafruit.bluefruit.le.connect   
There is probably an app for IOS as well, but I don't own a IOS device.  

## Usage

General Usage:  

'''
#include <Maqueen.h>
Maqueen bot;

void setup() {
bot.begin();

}

void loop() {
//program here
}
'''

The Maqueen library includes both the Adafruit_Microbit.h library and the NewPing.h library, you don't need to include them in your sketch, but you do need to invoke the classes.  

'''
#include <Maqueen.h>
Maqueen bot;

//NewPing.h and Adafruit_Microbit.h are inlcuded the library header
//but still need to be invoked here.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_Microbit_Matrix microbit;

void setup() {
bot.begin(); //inits the Maqueen robot
microbit.begin(); // inits Adafruits library
}
.....
'''

These are defined in the library, and can be used as needed in your sketch.  
LED1 left led (red).  
LED2 right led (red).  
PATROLLEFT left line sensor.  
PATROLRIGHT right line sensor.  
CW and CCW motor directions clock-wise and counter clock-wise  
M1 left motor  
M2 right motor  
BUZZER connected to PIN 0, this is the buzzer.  
IR IR sensor on front of the robot.  
BTNA Button A.  
BTNB Button B.  
TRIGGER_PIN and ECHO_PIN used for the NewPing library/ultrasonic.

Functions in the library:  
bot.begin(); required, sets pin modes, and generally sets everything to initial values.  
bot.setSpeed(int speed) this will set the speed for both motors, this is a percentage from 1 to 100, with 1 being the slowest speed, and 100 being the fastest. (Which in PWM is about 20 to 255).  
bot.motorRun(int motor, int direction, int speed) - this let you control each motor indepentant of each other, int motor (M1 or M2), int direction (CW or CCW), and int speed (This is the PWM value).  I put this in the library because this is how DF Robot has it's Makecode library setup, and I thought it might be easier to "convert" the programs.  
bot.stop(); Stop both motors, this also sets the speed back to zero, see example sketches.  
bot.forward(); robot moves forward. will continue to move forward until either a stop is called, or another direction is called.   
bot.backward(); same as above, only going backward.  
bot.spinLeft(); spin in place to the left, will continue to do so until a stop or another direction is called.  
bot.spinRight(); same as above only to the right.  
bot.left(); turn left, will continue until a stop or another direction is called.  
bot.right(); same as above to the right.  
bot.readIR(); returns a bytevalue code if a IR code is recieved. (semi-blocking)  
bot.readPatrolLeft(); and bot.readPatrolRight(); returns a bool (1 or 0) of the current state of the line sensors.  
bot.readA(); bot.readB(); returns if the buttons have been pushed (bool 1 or 0)

Next we have some interesting sounds. PLEASE NOTE all sounds are BLOCKING, be aware some of these are long, your robot will not be able to do anything while it is playing a sound. * This is a known issue that I want to correct. Please make sure the motors are stopped, or it is not doing anything important if you play a sound.  

bot.squeak(); this is the start up sound that is played.  
bot.catcall();  
bot.ohhh();  
bot.laugh();  
bot.laugh2();  
bot.waka(); pac-man like sound, very long.  
bot.r2d2(); sorta sounds like r2 (no not really.)  
bot.scale(); play the musical scale.  
bot.uhoh();  
bot.error();  
bot.sos();  
bot.beep(float noteFrequency, long noteDuration); used if you want to make your own sound effects  

For examples of most of the above, please see the example sketches included with the library.  

Musical notes: It is possiable to create your own music using bot.beep(Frequency, duration); See example 3a for a little example. Or the Super_Mario_Theme sketch in the "more just for fun" examples. Note information can be found in the musical_notes.h file.  

The Adafruit Micro:bit library provides lots of useful features for the LED Matrix, and the BLE functions. Please look at the examples they provide, I've expanded a bit on the images.  
Adafruit Images:  
microbit.show(microbit.HEART);  
microbit.show(microbit.EMPTYHEART);  
microbit.show(microbit.NO); big x or cross  
microbit.show(microbit.YES); check mark  

Images added: (notice how they are called a little differently)  
Also note, serveral of these are images used on the Makecode site.  
These are setup with binary code (see images.h).  
microbit.show(smile_bmp); a smile face(used in most of the sketches). This was in one of Adafruits examples, and moved to be included with this library.  
microbit.show(sad); a sad face  
microbit.show(confused); a confused face  
microbit.show(small_heart); a small heart  
microbit.show(ghost); a ghost - pacman anyone(?)  
microbit.show(skull); a skull  

Some of my own images.  
microbit.show(up_arrow); arrow pointing up.  
microbit.show(down_arrow); a arrow pointing down - also a sword from Makecode.  
microbit.show(right_arrow); you guess it a arrow point right.  
microbit.show(left_arrow); arrow pointing left.  

These images were made using a LED Matrix tool found here:  
https://www.riyas.org/2013/12/online-led-matrix-font-generator-with.html  
There is a matrix on the page that can have a custom size (ours is 5 x 5).  

The last thing:  
There is a Maqueen_cfg.h included in the library directory.  Currently there are
two custom settings, both are related to sounds. 
If you want to use PIN 0 for something, you need to turn the sounds off, this can be found here. And if you don't want the startup sound, you can also turn that off here.  

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2018 LeRoy Miller

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
