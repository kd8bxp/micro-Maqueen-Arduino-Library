#include "Arduino.h"
#include "Maqueen.h"
#include "Maqueen_cfg.h"


Maqueen::Maqueen() {
}

void Maqueen::begin() {
Wire.begin();

#if defined(SOUNDOFF)
//donot set pinMode of BUZZER
#else
pinMode(BUZZER, OUTPUT);
#endif

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(PATROLLEFT, INPUT);
pinMode(PATROLRIGHT, INPUT);
pinMode(BTNA, INPUT);
pinMode(BTNB, INPUT);
pinMode(IR, INPUT);
_previousMillis = 0;
_isplaying = 0;
_m1spd = 0;
_m2spd = 0;
Maqueen::stop();

#if defined(NOSTARTUPSOUND)
//don't play the Startup sound
#else
Maqueen::squeak();
#endif

}

void Maqueen::beep (float noteFrequency, long noteDuration)
{
#if defined(SOUNDOFF)
//don't play any sounds at all exit routine
#else
_isplaying = 1;
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)
          {
              digitalWrite(BUZZER,HIGH);
              delayMicroseconds(microsecondsPerWave);
              digitalWrite(BUZZER,LOW);
              delayMicroseconds(microsecondsPerWave);
          }
#endif
}     
 
void Maqueen::error()
{
          Maqueen::beep(note_D7,100); //C: play the note C for 500ms
          Maqueen::beep(note_C7,100); //C 
 _isplaying = 0;
}  

void Maqueen::sos() {
Maqueen::beep(note_C7,100); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,100); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,100); //C: play the note C 
delay(25);
Maqueen::beep(note_C7,250); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,250); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,250); //C: play the note C 
delay(25);
Maqueen::beep(note_C7,100); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,100); //C: play the note C 
delay(50);
Maqueen::beep(note_C7,100); //C: play the note C
_isplaying = 0; 
}

void Maqueen::scale() 
{    
          Maqueen::beep(note_C7,500); //C: play the note C for 500ms 
          Maqueen::beep(note_D7,500); //D 
          Maqueen::beep(note_E7,500); //E 
          Maqueen::beep(note_F7,500); //F 
          Maqueen::beep(note_G7,500); //G 
          Maqueen::beep(note_A7,500); //A 
          Maqueen::beep(note_B7,500); //B 
          Maqueen::beep(note_C8,500); //C 
_isplaying = 0;
}  

void Maqueen::r2d2(){

          Maqueen::beep(note_A7,100); //A 
          Maqueen::beep(note_G7,100); //G 
          Maqueen::beep(note_E7,100); //E 
          Maqueen::beep(note_C7,100); //C
          Maqueen::beep(note_D7,100); //D 
          Maqueen::beep(note_B7,100); //B 
          Maqueen::beep(note_F7,100); //F 
          Maqueen::beep(note_C8,100); //C 
          Maqueen::beep(note_A7,100); //A 
          Maqueen::beep(note_G7,100); //G 
          Maqueen::beep(note_E7,100); //E 
          Maqueen::beep(note_C7,100); //C
          Maqueen::beep(note_D7,100); //D 
          Maqueen::beep(note_B7,100); //B 
          Maqueen::beep(note_F7,100); //F 
          Maqueen::beep(note_C8,100); //C 
_isplaying = 0;
}

void Maqueen::laugh2() {

          Maqueen::beep(note_C6,200); //C
          Maqueen::beep(note_E6,200); //E  
          Maqueen::beep(note_G6,200); //G 
          Maqueen::beep(note_C7,200); //C 
          Maqueen::beep(note_C6,200); //C
          delay(50);
          Maqueen::beep(note_C6,200); //C
          Maqueen::beep(note_E6,200); //E  
          Maqueen::beep(note_G6,200); //G 
          Maqueen::beep(note_C7,200); //C 
          Maqueen::beep(note_C6,200); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
          delay(50);
          Maqueen::beep(note_C6,50); //C
_isplaying = 0;                    
}

void Maqueen::squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    Maqueen::beep(i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    Maqueen::beep(i,20);
  }
_isplaying = 0;
}

void Maqueen::waka() {
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
}

void Maqueen::catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    Maqueen::beep(i,10);
  }
 delay(300);
 
  for (int i=1000; i<3000; i=i*1.03) {
    Maqueen::beep(i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    Maqueen::beep(i,10);
  }
_isplaying = 0;
}

void Maqueen::ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    Maqueen::beep(i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    Maqueen::beep(i,10);
  }
_isplaying = 0;
}

void Maqueen::uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    Maqueen::beep(i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    Maqueen::beep(i,30);
  }
_isplaying = 0;
}

void Maqueen::laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    Maqueen::beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    Maqueen::beep(i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    Maqueen::beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    Maqueen::beep(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    Maqueen::beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    Maqueen::beep(i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    Maqueen::beep(i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    Maqueen::beep(i,10);
  }
//  delay(50);
_isplaying = 0;
}

void Maqueen::forward() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00);
  Wire.write(_m1spd); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x00);
  Wire.write(_m2spd); //speed
  Wire.endTransmission();
}

void Maqueen::backward() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x01);
  Wire.write(_m1spd); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x01);
  Wire.write(_m2spd); //speed
  Wire.endTransmission();
}

void Maqueen::spinLeft() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x01);
  Wire.write(_m1spd); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x00);
  Wire.write(_m2spd); //speed
  Wire.endTransmission();
}

void Maqueen::spinRight() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00);
  Wire.write(_m1spd); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x01);
  Wire.write(_m2spd); //speed
  Wire.endTransmission();
}

void Maqueen::left() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x00);
  Wire.write(_m2spd); //speed
  Wire.endTransmission();
}

void Maqueen::right() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00);
  Wire.write(_m1spd); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00); //speed
  Wire.endTransmission();
}

void Maqueen::setSpeed(int speed) {
if (speed <= 0) {speed = 1;}
if (speed > 100) {speed = 100;}
_m1spd = map(speed,0,100,20,255);
_m2spd = map(speed,0,100,20,255);
}

void Maqueen::stop() {
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00); //speed
  Wire.endTransmission();
  Wire.beginTransmission(0x10);
  Wire.write((byte)0x02);
  Wire.write((byte)0x00);
  Wire.write((byte)0x00); //speed
  Wire.endTransmission();
_m1spd = 0;
_m2spd = 0;
}

void Maqueen::motorRun(int motor, int direction, int speed) {
  Wire.beginTransmission(0x10);
  Wire.write((byte)motor);
  Wire.write((byte)direction);
  Wire.write((byte)speed); //speed
  Wire.endTransmission();
}

int Maqueen::isRunning() {
	return (_isrunning);

};

int Maqueen::isPlaying() {
	return (_isplaying);

};

int Maqueen::readIR() {
  //look for a header pulse from the IR Receiver
_lengthHeader = pulseIn(IR, LOW);
if(_lengthHeader > 5000)
{
//step through each of the 32 bits that streams from the remote
_byteValue = 0;
for(int i = 1; i <= 32; i++)
{
_bit = pulseIn(IR, HIGH);

//read the 8 bits that are specifically the key code
//use bitwise operations to convert binary to decimal
if (i > 16 && i <= 24)
if(_bit > 1000)
_byteValue = _byteValue + (1 << (i - 17)); 
}
return (_byteValue);
}

}

int Maqueen::readPatrolLeft() {
return (digitalRead(PATROLLEFT));
}

int Maqueen::readPatrolRight() {
return (digitalRead(PATROLRIGHT));
}

int Maqueen::readA() {
return (digitalRead(BTNA));
}

int Maqueen::readB() {
return (digitalRead(BTNB));
}


