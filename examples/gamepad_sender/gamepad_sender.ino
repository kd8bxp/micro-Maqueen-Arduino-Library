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

//Remember to set the soft device to S110 

#include "NRF51_Radio_library.h" //https://github.com/tipih/NRF51_Radio_library
#include <Adafruit_Microbit.h>

#define DOWN 13
#define LEFT 14
#define UP 8
#define RIGHT 15
#define XBTN 1
#define YBTN 2
#define LED 16
#define BUZZER 0
#define VIBRATE 12
#define ABTN 5
#define BBTN 11

Adafruit_Microbit_Matrix microbit;      //We only use this library to get easy access to the MATRIX LED, to sad you need to set the soft device to S110, even though we do not use it
                      //Should be easy to fix, by removing the ble class of the in the library
NRF51_Radio MicrobitRadio = NRF51_Radio();  //Let's get a new instance of the Radio


FrameBuffer        *myDataSendData;  //FrameBuffer for sending data to another device
FrameBuffer* myData;

static long currentMillis;          //Var to store the time gone since last time
const long interval = 5000;         //Wait time before sending
const long send_interval = 200;        //In state send, after start we send out at 1 sec interval, ontil we start receiving something

void setup() {
  Serial.begin(115200);
 microbit.begin();
 MicrobitRadio.enable();
 MicrobitRadio.setGroup(10);
  MicrobitRadio.setFrequencyBand(50);
pinMode (UP, INPUT);
pinMode (DOWN, INPUT);
pinMode (LEFT, INPUT);
pinMode (RIGHT,INPUT);
pinMode (ABTN, INPUT);
pinMode (BBTN, INPUT);
pinMode (XBTN, INPUT);  
pinMode (YBTN, INPUT);
pinMode (LED, OUTPUT);
pinMode (BUZZER, OUTPUT);
pinMode (VIBRATE, OUTPUT);
//digitalWrite(IR, HIGH);
analogWrite(BUZZER, 2055);
digitalWrite(VIBRATE, HIGH);
delay(100);
analogWrite(BUZZER, 0);
digitalWrite(VIBRATE, LOW);
  
    
  myDataSendData = new FrameBuffer();
  currentMillis = millis();
}

void loop() {
  
digitalWrite(LED,HIGH);
if (digitalRead(UP) == 0) {microbit.print("U"); myDataSendData->protocol=1; radio(); } else
if (digitalRead(DOWN) == 0) {microbit.print("D"); myDataSendData->protocol=2; radio();} else
if (digitalRead(LEFT) == 0) {microbit.print("L"); myDataSendData->protocol=3; radio();} else
if (digitalRead(RIGHT) == 0) {microbit.print("R"); myDataSendData->protocol=4; radio();} else
if (digitalRead(XBTN) == 0) {microbit.print("X"); myDataSendData->protocol=5; radio(); } else
if (digitalRead(YBTN) == 0) {microbit.print("Y"); myDataSendData->protocol=6; radio(); } else
if (digitalRead(ABTN) == 0) {microbit.print("A"); myDataSendData->protocol=7; radio();} else
if (digitalRead(BBTN) == 0) {microbit.print("B"); myDataSendData->protocol=8; radio();} else
 { myDataSendData->protocol=0; radio(); }
delay(250);
digitalWrite(LED, LOW);
delay(250);
microbit.print(" ");

}

void radio() {
 
    if (millis() - currentMillis >= send_interval) {
      
      currentMillis = millis();             //so we start to send, and then wait for a ack.
      
      myDataSendData->length = 3;
      myDataSendData->group = 2;            //(1=ACK 2=SEND)
      myDataSendData->version = 10;
      
      MicrobitRadio.send(myDataSendData);
    }
  
}
