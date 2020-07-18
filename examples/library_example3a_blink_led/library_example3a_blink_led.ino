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
  Serial.begin(9600);
  bot.begin(); //must include the begin (otherwise things don't work)  
  microbit.matrix.begin();

  while (bot.readA()) { //wait for BTNA to be pushed
    microbit.matrix.print("A");
  }

  microbit.matrix.clear();
  microbit.matrix.show(smile_bmp);
 }

void loop() {
  digitalWrite(LED1,HIGH); //LED1 is defined in the library (left led)
  digitalWrite(LED2,LOW); //LED2 is defined in the library (right led)
  bot.beep(note_C6, 500); //this function is blocking and will create the delay
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  bot.beep(note_E6, 500);

}
