/*******************************************************
 * Copyright (C) Vgyan Solutions Inc - All Rights Reserved
 * 
 * This file is part of Knoker Project, licensed to Level Properties of Dallas, TX.
 * 
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Jason Garner <jason@vgyansol.com>, 2015
 *******************************************************/
#ifndef __DRV8833_H
#define __DRV8833_H

#include <Particle.h>

typedef int PinName;

#define HB_FORWARD 1
#define HB_REVERSE 2
#define HB_BRAKE 3
#define HB_COAST 4
#define HB_SLEEP 5

class DRV8833
{    
    int AIN1;
    int AIN2;
    int BIN1;
    int BIN2;
    int nFAULT;
    int nSLEEP;
    int TPS_EN;
    public:
    DRV8833(PinName, PinName, PinName, PinName, PinName, PinName, PinName); //ain1, ain2, bin1, bin2, nFault, nSleep, tps
    
    void Amode(int);
    void Bmode(int);
    
    bool hasError();
};

#endif