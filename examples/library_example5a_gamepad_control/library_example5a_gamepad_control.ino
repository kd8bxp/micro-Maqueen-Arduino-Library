/*
Copyright (c) 2020 LeRoy Miller

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

//Remember to set your soft device to S110

#include <Maqueen.h>
#include "NRF51_Radio_library.h" //https://github.com/tipih/NRF51_Radio_library

Maqueen bot;
Adafruit_Microbit microbit;      
NRF51_Radio MicrobitRadio = NRF51_Radio();  

static long currentMillis;
const long interval = 5000;
FrameBuffer        *myDataSendData;  //FrameBuffer for sending data to another device
FrameBuffer* myData;

void setup() {
  Serial.begin(115200);
  bot.begin();
  Serial.println("Gamepad Control demo ready!");
  microbit.matrix.begin();
  MicrobitRadio.enable();
  MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);
  Serial.println("Radio running");
  microbit.matrix.clear();
  microbit.matrix.show(smile_bmp);
}

void loop() {
 
//Check if there is any data in the buffer
  FrameBuffer* myData = MicrobitRadio.recv();
  if (myData != NULL) {
    Serial.print(myData->length);
    Serial.print("    ");
    Serial.print(myData->version);
    Serial.print("    ");
    Serial.print(myData->group);
    Serial.print("    ");
    Serial.println(myData->protocol);
    //Serial.print("    ");
    //Serial.print(myData->payload[10]);
    //Serial.println("    ");
    //Serial.println(MicrobitRadio.dataReady());

    if (myData->protocol == 0) {bot.stop();}
    if (myData->protocol == 1) {bot.setSpeed(50); bot.forward(); }
    if (myData->protocol == 2) {bot.setSpeed(50); bot.backward(); }
    if (myData->protocol == 3) {bot.setSpeed(50); bot.spinLeft(); }
    if (myData->protocol == 4) {bot.setSpeed(50); bot.spinRight(); }
    if (myData->protocol == 5) {bot.stop(); /*Button X is pushed*/}
    if (myData->protocol == 6) {bot.stop(); /*Button Y is pushed*/}
    if (myData->protocol == 7) {bot.stop(); /*Button A is pushed*/}
    if (myData->protocol == 8) {bot.stop(); /*Button B is pushed*/}
    delete myData;  //Remember to delete it
  }
  
}
