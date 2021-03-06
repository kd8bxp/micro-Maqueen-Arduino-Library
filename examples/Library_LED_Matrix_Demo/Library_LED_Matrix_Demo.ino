// This is a demo of the matrix driver code
// works with Adafruit GFX commands - its just
// a really small screen!
// https://learn.adafruit.com/adafruit-gfx-graphics-library

#include <Maqueen.h>
Maqueen bot;

Adafruit_Microbit microbit;


    
void setup() {  
  Serial.begin(9600);
  bot.begin();
  microbit.matrix.begin();
}
    
void loop(){

  // The Images below are from the Adafruit microbit library.
  // Fill screen
  microbit.matrix.fillScreen(LED_ON);
  delay(1000);

  // draw a heart
  microbit.matrix.show(microbit.matrix.HEART);
  delay(1000);
  //empty heart
  microbit.matrix.show(microbit.matrix.EMPTYHEART);
  delay(1000);
  // draw a no cross
  microbit.matrix.show(microbit.matrix.NO);
  delay(1000);

  // draw a yes check
  microbit.matrix.show(microbit.matrix.YES);
  delay(1000);
 
  
  microbit.matrix.clear();

  //These are included in the Adafruit Microbit library.
  // Draw a line 'by hand'
  microbit.matrix.drawPixel(0, 0, LED_ON);
  microbit.matrix.drawPixel(1, 1, LED_ON);
  microbit.matrix.drawPixel(2, 2, LED_ON);
  microbit.matrix.drawPixel(3, 3, LED_ON);
  microbit.matrix.drawPixel(4, 4, LED_ON);
  // draw the 'opposite' line with drawline (easier!)
  microbit.matrix.drawLine(0, 4, 4, 0, LED_ON);

  delay(1000);

  // erase screen, draw a square
  microbit.matrix.clear();
  microbit.matrix.drawRect(0,0, 5, 5, LED_ON); // top left corner @ (0,0), 5 by 5 pixels size

  delay(1000);

  // erase screen, draw a circle
  microbit.matrix.clear();
  microbit.matrix.drawCircle(2,2, 2, LED_ON); // center on 2, 2, radius 2

  delay(1000);

  // erase screen, draw a filled triangle
  microbit.matrix.clear();
  microbit.matrix.fillTriangle(0,4, 2,0, 4,4, LED_ON); 

  delay(1000);

//These Images are included in the Maqueen Library
//some are based off images on makecode.microbit.org
// draw a custom made bitmap face
  microbit.matrix.show(smile_bmp);
  delay(1000);

  microbit.matrix.show(sad);
  delay(1000);

  microbit.matrix.show(confused);
  delay(1000);

  microbit.matrix.show(small_heart);
  delay(1000);

  microbit.matrix.show(up_arrow);
  delay(1000);

  microbit.matrix.show(down_arrow);
  delay(1000);

  microbit.matrix.show(left_arrow);
  delay(1000);

  microbit.matrix.show(right_arrow);
  delay(1000);

  microbit.matrix.show(ghost);
  delay(1000);

  microbit.matrix.show(skull);
  delay(1000);
  
}
