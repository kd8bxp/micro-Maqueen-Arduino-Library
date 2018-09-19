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
{B01100,
B11010,
B00110,
B11010,
B01100};
//{B01111,
//B11110,
//B11100,
//B11110,
//B01111};

const uint8_t pacc[] =
{B01100,
B11010,
B11110,
B11010,
B01100};
//{B01111,
//B11111,
//B11111,
//B11111,
//B01111};

void setup() {
  Serial.begin(9600);
  bot.begin();
 microbit.begin();
microbit.clear();
delay(1000);
 
}

void loop() {
  microbit.show(pac);
  waka();
  microbit.show(pacc);
  //waka();
  delay(100);
 
}

void waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    bot.beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    bot.beep(i,10);
  }
 /*   for (int i=1000; i<3000; i=i*1.05) {
    Maqueen::beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    Maqueen::beep(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    Maqueen::beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    Maqueen::beep(i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    Maqueen::beep(i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    Maqueen::beep(i,10);
  }
_isplaying = 0;
*/
}
