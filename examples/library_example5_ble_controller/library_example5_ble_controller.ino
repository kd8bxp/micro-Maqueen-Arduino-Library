// Example for using Adafruit Bluefruit App to send/receive controller data

// BLE Serial code Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//Softdevice S110 - Adafruit sketch adapted for use with the DF Robot Maqueen
//by LeRoy Miller (c) 2018

#include <Maqueen.h>
Maqueen bot;
Adafruit_Microbit microbit;


// function prototypes over in packetparser.cpp
uint8_t readPacket(Stream *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);
// the packet buffer
extern uint8_t packetbuffer[];

#define BLE_READPACKET_TIMEOUT 1000

void setup() {
  Serial.begin(9600);
  bot.begin();
  Serial.println("Controller demo ready!");

  // custom services and characteristics can be added as well
  microbit.BTLESerial.begin();
  microbit.BTLESerial.setLocalName("microbit");

  // Start LED matrix driver after radio (required)
  microbit.matrix.begin();
  microbit.matrix.clear();
  microbit.matrix.show(smile_bmp);
}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void)
{
  /* Wait for new data to arrive */
  uint8_t len = readPacket(&(microbit.BTLESerial), BLE_READPACKET_TIMEOUT);
  if (len == 0) return;

  /* Got a packet! */
  // printHex(packetbuffer, len);

  

  // Buttons
  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';
    Serial.print ("Button "); Serial.print(buttnum);
    if (pressed) {
      Serial.println(" pressed");
    } else {
      Serial.println(" released");
    }
  
//number keys 1 to 4 aren't used in this example.
switch (buttnum) {
  case 5:
  if (pressed) { bot.setSpeed(50); bot.forward(); } else { bot.stop(); }
  break;
  case 6: 
  if (pressed) {bot.setSpeed(50); bot.backward(); } else {bot.stop(); }
  break;
  case 7: 
  if (pressed) { bot.setSpeed(50); bot.spinLeft(); } else {bot.stop();}
  break;
  case 8:
  if (pressed) {bot.setSpeed(50); bot.spinRight(); } else {bot.stop();}
  break;
  default:
  bot.stop();
  break;
  }
 }
}
