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

Adafruit_Microbit microbit;

int byteValue;

void setup() {
  Serial.begin(9600);
  bot.begin();
  microbit.matrix.begin();
  microbit.matrix.clear();

}

void loop() {
  /* This will print the IR code (or codes) to the serial
   * monitor. It's best to hit each key a number of times
   * and note these numbers, keys that produce the same
   * number should be noted, and those numbers not used.
   * It works best if you can hit the button on your remote
   * quickly. 
   * A lot of trail and error has to be used.
   */

  byteValue = bot.readIR();
  if (byteValue != 0) {
    Serial.println(byteValue);
    microbit.matrix.print(byteValue);
    delay(100);
  }
}
