/******************************************************************************
 *
 * Project: Kreisfahren mit dem RP6
 * File:    main.c
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

//#include <avr/io.h>
#include <RP6RobotBaseLib.h>
#define HALBER_ACHSABSTAND  51.5
#define PI                  3.142

    enum direction
    {
        left,
        right,
        straight
    };

    int iRadius     = 0; // Radius
    int iLeftSpeed;
    int iRightSpeed;
    int iSpeed = 60;
    void calculateSpeed(int, int, int);
    void driveRadius (int,int,int direction);

    uint16_t calculateDistanceForLeftTrack_Arc(int, int direction);


int main(void)
{
    initRobotBase();
    int r = 200;
    mleft_dist = 0;
    mright_dist = 0;
    iLeftSpeed = 80;
    iRightSpeed = 80;
    int speed = 80;
    mSleep(1500);

    powerON(); // Encoder und Motorstromsensoren anschalten!

    moveAtSpeed(iLeftSpeed,iRightSpeed); // Geschwindigkeit einstellen#
    void driveRadius(r, speed, left);

    while(true)
    {



        moveAtSpeed(iLeftSpeed,iRightSpeed);


        // Aus der Hauptschleife ständig die motionControl Funktion
        // aufrufen – sie regelt die Motorgeschwindigkeiten:
        task_motionControl();
        task_ADC(); // Wird wegen den Motorstromsensoren aufgerufen!
    }
    return 0;
    while(1)
    {
        //
    }

    return 0;
}

void driveRadius (int Radius, int speed, int direction)
{
        if (getLeftDistance()== Radius)
        {
            calculateSpeed(Radius, speed, direction);
        }

        if (getLeftDistance()== (Radius+calculateDistanceForLeftTrack_Arc(Radius  , direction)))
        {
            calculateSpeed(Radius, speed, straight);
        }
        if (getLeftDistance()> (2*Radius+calculateDistanceForLeftTrack_Arc(Radius, direction)))
        {
            stop();
            iLeftSpeed=0;
            iRightSpeed=0;
        }
};

void calculateSpeed(int iRadius, int iSpeed, int direction)
{
    switch(direction)
    {
    case 1:
        iLeftSpeed  = iSpeed;
        iRightSpeed = iLeftSpeed / (iRadius + HALBER_ACHSABSTAND) * (iRadius - HALBER_ACHSABSTAND);
        break;

    case 0:
        iRightSpeed = iSpeed;
        iLeftSpeed  = iRightSpeed / (iRadius + HALBER_ACHSABSTAND) * (iRadius - HALBER_ACHSABSTAND);
        break;

    case 2:
        iLeftSpeed  = iSpeed;
        iRightSpeed = iSpeed;
        break;
    }
}

uint16_t calculateDistanceForLeftTrack_Arc(int iRadius, int direction)
{
    uint16_t distance = 0;

    switch(direction)
    {
    case 1:
        distance = 2 * PI * (iRadius + HALBER_ACHSABSTAND)*3/4;
        break;

    case 0:
        distance = 2 * PI * (iRadius - HALBER_ACHSABSTAND)*3/4;
        break;
    }

    return distance;
}

/******************** End of file <main.c> ***********************************/
