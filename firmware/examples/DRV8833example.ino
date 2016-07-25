// This #include statement was automatically added by the Particle IDE.
#include "DRV8833.h"

//pins for DRV8833
#define AIN1 A4
#define AIN2 A3
#define BIN1 A2
#define BIN2 A1
#define nFAULT A0
#define nSLEEP B5

#define CLOSE_DECT B4
#define OPEN_DECT B3
#define LED_DIN_MCU B2
#define KEY_LED B1

#define TPS_EN B0

#define led D6
#define boardLed D7

volatile bool pendingAForward = false;
volatile bool pendingAReverse = false;
volatile bool pendingBForward = false;
volatile bool pendingBReverse = false;
volatile bool pendingStop = false;

DRV8833 motor(AIN1, AIN2, BIN1, BIN2, nFAULT, nSLEEP, TPS_EN); //ain1, ain2, bin1, bin2, nFault, nSleep, TPS_EN

int move(String command)
{
    if(command == "AForward")
    {
        pendingAForward = true;
        return 1;
    }
    else if(command == "AReverse")
    {
        pendingAReverse = true;
        return 1;
    }
    else if(command == "BForward")
    {
        pendingBForward = true;
        return 1;
    }
    else if(command == "BReverse")
    {
        pendingBReverse = true;
        return 1;
    }
    else if(command == "Stop")
    {
        pendingStop = true;
        return 1;
    }
    else return -1;
}

void setup()
{
  pinMode(LED_DIN_MCU, OUTPUT);
  pinMode(KEY_LED, OUTPUT);

  //pinMode(CLOSE_DECT, INPUT);
  pinMode(OPEN_DECT, INPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(nFAULT, INPUT);
  pinMode(nSLEEP, OUTPUT);
  pinMode(TPS_EN,OUTPUT);
  // This part is mostly the same:
  pinMode(led,OUTPUT); // Our LED pin is output (lighting up the LED)
  pinMode(boardLed,OUTPUT); // Our on-board LED is output as well

  digitalWrite(TPS_EN, LOW);

  Particle.function("move", move);
}

void loop()
{
    if(pendingAForward)
    {
        pendingAForward = false;
        motor.Amode(HB_FORWARD);
        Particle.publish("moveRequest","received AForward");
    }
    if(pendingAReverse)
    {
        pendingAReverse = false;
        motor.Amode(HB_REVERSE);
        Particle.publish("moveRequest","received AReverse");
    }
    if(pendingBForward)
    {
        pendingBForward = false;
        motor.Amode(HB_FORWARD);
        Particle.publish("moveRequest","received BForward");
    }
    if(pendingBReverse)
    {
        pendingBReverse = false;
        motor.Amode(HB_REVERSE);
        Particle.publish("moveRequest","received BReverse");
    }
    if(pendingStop)
    {
        pendingStop = false;
        motor.Amode(HB_COAST);
        motor.Bmode(HB_COAST);
        Particle.publish("moveRequest","received Stop");
    }
}
