/*******************************************************
 * Copyright (C) Vgyan Solutions Inc - All Rights Reserved
 * 
 * This file is part of Knoker Project, licensed to Level Properties of Dallas, TX.
 * 
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Jason Garner <jason@vgyansol.com>, 2015
 *******************************************************/
#include "DRV8833.h"

DRV8833::DRV8833(PinName a1, PinName a2, PinName b1, PinName b2, PinName nF, PinName nS, PinName tps)
{
  AIN1 = a1;
  AIN2 = a2;
  BIN1 = b1;
  BIN2 = b2;
  nFAULT = nF;
  nSLEEP = nS;
  TPS_EN = tps;
  digitalWrite(TPS_EN,LOW);
}

bool DRV8833::hasError()
{
    return !digitalRead(nFAULT);
}

void DRV8833::Amode(int mode)
{
    switch(mode)
    {
        case HB_FORWARD:
            digitalWrite(AIN1,HIGH);
            digitalWrite(AIN2,LOW);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_REVERSE:
            digitalWrite(AIN1,LOW);
            digitalWrite(AIN2,HIGH);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_BRAKE:
            digitalWrite(AIN1,HIGH);
            digitalWrite(AIN2,HIGH);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_COAST:
            digitalWrite(AIN1,LOW);
            digitalWrite(AIN2,LOW);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,LOW);
            break;
        case HB_SLEEP:
        default:
            digitalWrite(AIN1,LOW);
            digitalWrite(AIN2,LOW);
            digitalWrite(BIN1,LOW);
            digitalWrite(BIN2,LOW);
            digitalWrite(nSLEEP,LOW);
            digitalWrite(TPS_EN,LOW);
            break;
    }
}

void DRV8833::Bmode(int mode)
{
    switch(mode)
    {
        case HB_FORWARD:
            digitalWrite(BIN1,HIGH);
            digitalWrite(BIN2,LOW);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_REVERSE:
            digitalWrite(BIN1,LOW);
            digitalWrite(BIN2,HIGH);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_BRAKE:
            digitalWrite(BIN1,HIGH);
            digitalWrite(BIN2,HIGH);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,HIGH);
            break;
        case HB_COAST:
            digitalWrite(BIN1,LOW);
            digitalWrite(BIN2,LOW);
            digitalWrite(nSLEEP,HIGH);
            digitalWrite(TPS_EN,LOW);
            break;
        case HB_SLEEP:
        default:
            digitalWrite(AIN1,LOW);
            digitalWrite(AIN2,LOW);
            digitalWrite(BIN1,LOW);
            digitalWrite(BIN2,LOW);
            digitalWrite(nSLEEP,LOW);
            digitalWrite(TPS_EN,LOW);
            break;
    }
}
