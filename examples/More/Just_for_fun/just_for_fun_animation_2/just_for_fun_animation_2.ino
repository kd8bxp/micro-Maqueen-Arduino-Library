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
Adafruit_Microbit_Matrix microbit;

const uint8_t pac[] = 
{B10101,
B01010,
B10101,
B01010,
B10101};

const uint8_t pacc[] =
{B01010,
B10101,
B01010,
B10101,
B01010};

void setup() {
  Serial.begin(9600);
  bot.begin();
 microbit.begin();
microbit.clear();
delay(1000);
 
}

void loop() {
  microbit.show(pac);
 delay(500);
  microbit.show(pacc);
  //waka();
  delay(500);
 
}

