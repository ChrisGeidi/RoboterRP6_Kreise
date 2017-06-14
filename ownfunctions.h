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
 * Marc T�pker
 *
 *****************************************************************************/
#ifndef OWNFUNCTIONS_H
#define OWNFUNCTIONS_H

#include <RP6RobotBaseLib.h>

#define HALBER_ACHSABSTAND  51.5
#define PI                  3.142

 int iRadius     = 0; // Radius
 int iLeftSpeed  = 0;
 int iRightSpeed = 0;

 void calculateSpeed(int, int, char);

 uint16_t calculateDistanceForLeftTrack(int, char);


#endif // OWNFUNCTIONS_H
/***************** End of file <ownfunctions.h> *****************************/
