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

    int iRadius     = 0; // Radius
    int iLeftSpeed;
    int iRightSpeed;
    int iSpeed = 60;
    void calculateSpeed(int , int , char );
    void driveRad (int,int,char);

    uint16_t calculateDistanceForLeftTrack_Arc(int, char);


int main(void)
{
    initRobotBase();
    int r = 400;
    mleft_dist = 0;
    mright_dist = 0;
    iLeftSpeed = 80;
    iRightSpeed = 80;
    int speed = 80;
    mSleep(1500);

    powerON(); // Encoder und Motorstromsensoren anschalten!

    moveAtSpeed(iLeftSpeed,iRightSpeed); // Geschwindigkeit einstellen#

    while(true)
    {

    void driveRad(r, speed,'R');

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

void driveRad (int Radius, int speed, char direction)
{
        if (getLeftDistance()== Radius)
        {
            calculateSpeed(Radius, speed, direction);
        }

        if (getLeftDistance()== (Radius+calculateDistanceForLeftTrack_Arc(Radius  , direction)))
        {
            calculateSpeed(Radius, speed, 'G');
        }
        if (getLeftDistance()> (2*Radius+calculateDistanceForLeftTrack_Arc(Radius, direction)))
        {
            stop();
            iLeftSpeed=0;
            iRightSpeed=0;
        }
};

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

uint16_t calculateDistanceForLeftTrack_Arc(int iRadius, char direction)
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

/******************** End of file <main.c> ***********************************/
