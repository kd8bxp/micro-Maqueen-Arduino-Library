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

/* Define our IR Codes
 * Use example 6a to get your IR codes, you may see three or four different codes
 * Some trail and error will be needed to get the correct codes.
 * A you can see from my example, the UP button produced 3, 64, 15 - 64 worked
 * most of the time. The other buttons all had different codes.
 */
//for this experiment we are only going to use 5 buttons on the remote
#define UP 64 //(3 || 64 || 15)
#define LEFT 7 //(7 || 127)
#define RIGHT 9 //(9 || 39)
#define DOWN 25 //(25 || 103)
#define SETUP 21 //(87 || 21)

Maqueen bot;

//NewPing.h and Adafruit_Microbit.h are inlcuded the library header
//but still need to be invoked here.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_Microbit microbit;

int byteValue;
int speed = 50; //50% of full speed

void setup() {
  Serial.begin(9600);
  bot.begin();
  microbit.matrix.begin();
  microbit.matrix.clear();
  microbit.matrix.show(smile_bmp);

}

void loop() {
 byteValue = bot.readIR();

  switch (byteValue) {
    case 0:
      bot.stop();
      break;
    case UP:
      bot.setSpeed(speed);
      bot.forward();
      break;
    case DOWN:
      bot.setSpeed(speed);
      bot.backward();
      break;
    case LEFT:
      bot.setSpeed(speed);
      bot.spinLeft();
      break;
    case RIGHT:
      bot.setSpeed(speed);
      bot.spinRight();
      break;
    case SETUP:
      bot.stop();
      break;
    default:
      bot.stop();
      break;
  }
  byteValue = 0; 
}
