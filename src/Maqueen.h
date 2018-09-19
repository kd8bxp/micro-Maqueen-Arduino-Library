/*
Arduino Library for DF Robot Micro:Maqueen Robot v1.0.0
Sep 12, 2018.
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

/* Sound Effects from: https://mycontraption.com/sound-effects-with-and-arduino/
 * April 3, 2013 by Erik Kringen License unknown
 */

#ifndef Maqueen_h
#define Maqueen_h
#include "Arduino.h"
#include <Wire.h>
#include "musical_notes.h"
#include <NewPing.h>
#include <Adafruit_Microbit.h>
#include "Maqueen_cfg.h"
#include "images.h"

#define LED1 8 //left led
#define LED2 12 //right led
#define PATROLLEFT 13 //left line sensor
#define PATROLRIGHT 14 //right line sensor
#define CW 0x0
#define CCW 0x1
#define M1 0x00 //left motor
#define M2 0x02 //right motor
#define BUZZER 0
#define IR 16
#define BTNA 5 //button A
#define BTNB 11 //button B
#define TRIGGER_PIN 1
#define ECHO_PIN 2
#define MAX_DISTANCE 500

//#define SOUNDOFF


class Maqueen {
private:
	int _m1spd;
	int _m2spd;
	int _isrunning;
	int _isplaying;
	long _OnTime;
	unsigned long _previousMillis;
	unsigned long _lengthHeader;
	unsigned long _bit;
	int _byteValue;

public:
Maqueen();
void begin();
//void setSpeed(int number, int speed); //set speed per motor
void setSpeed(int speed); //set speed for both motors
void motorRun(int motor, int direction, int speed); //control just one motor independant of other motor controls
void stop(); //all stop both stop
void forward(); 
void backward();
void spinLeft(); 
void spinRight(); 
void right(); 
void left(); 
void squeak(); 
void catcall(); 
void ohhh(); 
void laugh(); 
void laugh2(); 
void waka(); 
void r2d2(); 
void scale(); 
void uhoh(); 
void error(); 
void sos(); //my own sound effect
//void update();
int isRunning();
int isPlaying(); //flag for if sound effects are playing.
void beep(float noteFrequency, long noteDuration);
int readIR();
int readPatrolLeft();
int readPatrolRight();
int readA();
int readB();
};

#endif

