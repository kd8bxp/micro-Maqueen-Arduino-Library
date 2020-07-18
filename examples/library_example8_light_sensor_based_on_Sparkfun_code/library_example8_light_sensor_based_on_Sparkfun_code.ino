/**
 * Based on code from Sparkfun by LeRoy Miller (c) 2018
 * https://www.sparkfun.com/news/2161
 * 
 * This code works kind of opposite of what you might expect.
 * PIN 3 is used on the LED Matrix, When a flash light or bright light
 * is shown on this PIN, the pin goes low (or lower), and the robot moves
 * forward.  It will stop when the light is removed. 
 * It's slow to react. but it does work.
 * 
 * SparkFun Inventor's Kit Project
 * LED as Light Sensor
 * Date: July 8, 2016
 * 
 * Description:
 *  Demonstration of how to use an LED as a light sensors. Cover 
 *  up the LED plugged into pin 2/3 to light up the output LED
 *  plugged into pin 9. Note that you might have to change the
 *  THRESHOLD parameter. Connect a Serial terminal to get raw
 *  readings of the light value.
 *  
 * License:
 *  Public Domain
 */
#include <Maqueen.h>

Maqueen bot;
Adafruit_Microbit microbit;
// Any reading over this value will turn on the output LED
const unsigned int THRESHOLD = 10;

// Stop counting after this value (we can assume it is total darkness)
const unsigned int MAX_T = 10000; //20000;

// Pin definitions
const int P_JNCT_PIN = -1;// P junction of sensing LED
const int N_JNCT_PIN = 3;// N junction of sensing LED

// Global variables
unsigned int sen_time;// Time it takes to discharge LED

void setup() {

  // Start serial communications
  Serial.begin(9600);
  microbit.matrix.begin();
  bot.begin();
  // Set P junction pin to output low (GND)
  pinMode(P_JNCT_PIN, OUTPUT);
  digitalWrite(P_JNCT_PIN, LOW);
}

void readLED() {

  unsigned int t;

  // Reset global LED discharge time
  sen_time = 0;

  // Apply reverse voltage to charge the sensing LED's capacitance
  pinMode(N_JNCT_PIN, OUTPUT);
  digitalWrite(N_JNCT_PIN, HIGH);

  // Isolate N junction and turn off pull-up resistor
  pinMode(N_JNCT_PIN, INPUT);
  digitalWrite(N_JNCT_PIN, LOW);

  // Count how long it takes for the LED to discharge
  for ( t = 0; t < MAX_T; t++ ) {
    if ( digitalRead(N_JNCT_PIN) == 0 ) {
      break;
    }

  }

  sen_time = t;
}

void loop() {

  // Read the amount of light falling on the LED
  readLED();

  // Print out the raw discharge time
  //Serial.println(sen_time);
  int number = sen_time/500;
  microbit.matrix.print(number);
  Serial.println(number);
  // If the light is below a certain level (discharge time is over the
  // threshold), turn on the output LED
  if ( number < THRESHOLD ) {
    bot.setSpeed(30);
    bot.forward();
  } else {
    bot.stop();
  }
}
