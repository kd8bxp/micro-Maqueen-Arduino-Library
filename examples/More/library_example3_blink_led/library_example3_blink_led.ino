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
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_Microbit_Matrix microbit;

void setup() {
  Serial.begin(9600);
  bot.begin();
  microbit.begin();
while (bot.readA()) { //wait for BTNA to be pushed
microbit.print("A");
}
  microbit.clear();
  microbit.show(smile_bmp); //smile_bmp is in the library
  //delay(1000);
  
  /* The idea here was to do something while the bot
   *  was playing a sound effect. 
   *  The sound effect is still a blocking function
   *  and this didn't work as I was thinking.
   */
   
  do {
    bot.r2d2();
    Serial.println(sonar.ping_in());
  } while (bot.isPlaying());
}

void loop() {
  digitalWrite(LED1, HIGH); //LED1 is defined in the library
  digitalWrite(LED2, LOW); //LED2 is defined in the library
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(1000);
}
