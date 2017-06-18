/******************************************************************************
 *
 * Project: Kreisfahren mit dem RP6
 * File:    ownfunctions.h
 *
 * Ingenieurorientierte Programmierung
 * Dr. Alexander Kling
 *
 * Carsten Bevermann
 * Christoph Geitner
 * Jens Reimer
 * Marc Töpker
 *
 *****************************************************************************/
#ifndef OWNFUNCTIONS_H
#define OWNFUNCTIONS_H

#include <RP6RobotBaseLib.h>

#define HALBER_ACHSABSTAND  51.5
#define PI                  3.142

    int iRadius     = 0; // Radius
    int iLeftSpeed;
    int iRightSpeed;
    int iSpeed = 60;
    void calculateSpeed(int , int , char );
    void driveRad (int,char);

    uint16_t calculateDistanceForLeftTrack_Arc(int, char);


#endif // OWNFUNCTIONS_H
/***************** End of file <ownfunctions.h> *****************************/
