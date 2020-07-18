/*
Copyright (c) 2018 LeRoy Miller

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

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

#include <Maqueen.h>
Maqueen bot;

//NewPing.h and Adafruit_Microbit.h are inlcuded the library header
//but still need to be invoked here.
Adafruit_Microbit microbit;

void setup() {
  bot.begin();
microbit.matrix.begin();

  while (bot.readA()) { //wait for BTNA to be pushed
microbit.matrix.print("A");
}

microbit.matrix.clear();
microbit.matrix.show(smile_bmp);

//Spin the motor to the right
bot.motorRun(M1, CW, 50); //Motor Number, direction, speed (PWM)
bot.motorRun(M2, CCW, 50);
delay(5000); //wait 5 seconds
bot.stop(); //turn motors off

//Set speed by percentage (0 to 100) slow to fastest. For both motors resets when stopped
bot.setSpeed(50); 
bot.spinLeft(); //Spin robot in place to left
delay(5000); //wait 5 seconds
bot.stop(); //turn motors off speed set to zero
}

void loop() {
  

}
