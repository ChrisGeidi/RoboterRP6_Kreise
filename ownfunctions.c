/******************************************************************************
 *
 * Project: Kreisfahren mit dem RP6
 * File:    ownfunctions.c
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

#include "ownfunctions.h"


void calculateSpeed(int iRadius, int iSpeed, char direction)
{
    switch(direction)
    {
    case 'R':
        iLeftSpeed  = iSpeed;
        iRightSpeed = iLeftSpeed / (iRadius + HALBER_ACHSABSTAND) * (iRadius - HALBER_ACHSABSTAND);
        break;

    case 'L':
        iRightSpeed = iSpeed;
        iLeftSpeed  = iRightSpeed / (iRadius + HALBER_ACHSABSTAND) * (iRadius - HALBER_ACHSABSTAND);
        break;

    case 'G':
        iLeftSpeed  = iSpeed;
        iRightSpeed = iSpeed;
        break;
    }
}

uint16_t calculateDistanceForLeftTrack(int iRadius, char direction)
{
    uint16_t distance = 0;

    switch(direction)
    {
    case 'R':
        distance = 2 * PI * (iRadius + HALBER_ACHSABSTAND);
        break;

    case 'L':
        distance = 2 * PI * (iRadius - HALBER_ACHSABSTAND);
        break;
    }

    return distance;
}



 /***************** End of file <ownfunctions.c> *****************************/
