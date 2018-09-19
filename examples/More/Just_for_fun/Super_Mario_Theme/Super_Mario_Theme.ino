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
/*
 * Adapted from Arduino Mario Bros Tunes with Piezo Buzzer by LeRoy Miller (Sep 18, 2018) 
 * by: Dipto Pratyaksa
 * 31/3/13
 * http://www.princetronics.com/supermariothemesong/
 */

#include <Maqueen.h>
Maqueen bot;

int melody[] = {
  note_E7, note_E7, 0, note_E7,
  0, note_C7, note_E7, 0,
  note_G7, 0, 0,  0,
  note_G6, 0, 0, 0,

  note_C7, 0, 0, note_G6,
  0, 0, note_E6, 0,
  0, note_A6, 0, note_B6,
  0, note_Ab6, note_A6, 0,

  note_G6, note_E7, note_G7,
  note_A7, 0, note_F7, note_G7,
  0, note_E7, 0, note_C7,
  note_D7, note_B6, 0, 0,

  note_C7, 0, 0, note_G6,
  0, 0, note_E6, 0,
  0, note_A6, 0, note_B6,
  0, note_Ab6, note_A6, 0,

  note_G6, note_E7, note_G7,
  note_A7, 0, note_F7, note_G7,
  0, note_E7, 0, note_C7,
  note_D7, note_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

void setup() {
bot.begin();
Serial.begin(9600);
delay(1000);
}

void loop() {

  Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisnote = 0; thisnote < size; thisnote++) {
      int noteDuration = 1000 / tempo[thisnote];
      bot.beep(melody[thisnote], noteDuration);
      int pauseBetweennotes = noteDuration * 1.30;
      delay(pauseBetweennotes);
}
while(1);
}
