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

#include <RP6RobotBaseLib.h>
#define HALBER_ACHSABSTAND  51.5
#define PI                  3.142

	unsigned int radius_eins;
    unsigned int radius_zwei;
    unsigned int radius_drei;
    unsigned int radius_vier;
    int iLeftSpeed;
    int iRightSpeed;
    int iSpeed = 60;
    void calculateSpeed(unsigned int, int, int);
    void driveRadius (unsigned int,int,int direction);
    void checkState();

    uint16_t calculateDistanceForLeftTrack_Arc(unsigned int, int direction);

    enum direction
    {
        left,
        right,
        straight
    };

    enum Zustand
    {
		IDLE,
        r1, //Radius1
        r2, //Radius2
        r3, //Radius3
        r4  //Radius4
    } state;

void Zustand (void)
{
	switch (state)
	{
		case IDLE:
			stop();
		break;

		case r1:
		driveRadius(radius_eins,iSpeed, left);
		setLEDs(0b000001); // Und dieser schaltet StatusLED1 an und alle anderen aus.
		state = r2;
		break;

		case r2:
		driveRadius(radius_zwei,iSpeed, right);
		setLEDs(0b000010); // StatusLED2
		state = r3;
		break;

		case r3:
		driveRadius(radius_drei,iSpeed, left);
		setLEDs(0b000100); // StatusLED3
		state = r4;
		break;

		case r4:
		driveRadius(radius_vier,iSpeed, right);
		setLEDs(0b001010);		// StatusLED4 und StatusLED2
		state =IDLE;
		break;
	}
}

void driveRadius (unsigned int Radius, int speed, int direction)
{
        if (getLeftDistance()== Radius) calculateSpeed(Radius, speed, direction);
        if (getLeftDistance()== (Radius+calculateDistanceForLeftTrack_Arc(Radius  , direction))) calculateSpeed(Radius, speed, straight);
        if (getLeftDistance()> (2*Radius+calculateDistanceForLeftTrack_Arc(Radius, direction)))
        {
            stop();
            iLeftSpeed=0;
            iRightSpeed=0;
        }
};

void calculateSpeed(unsigned int iRadius, int iSpeed, int direction)
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

uint16_t calculateDistanceForLeftTrack_Arc(unsigned int iRadius, int direction)
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

void moveCircle(uint8_t iLeftSpeed, uint8_t iRightSpeed)
{
	if(iLeftSpeed > 200) iLeftSpeed = 200;
	if(iRightSpeed > 200) iRightSpeed = 200;
	mleft_des_speed = iLeftSpeed;
	mright_des_speed = iRightSpeed;
}

int main(void)
{


    iSpeed = 80;
    radius_eins = 400;
    radius_zwei = 500;
    radius_drei = 600;
    radius_vier = 700;
    mleft_dist = 0;
    mright_dist = 0;
    iLeftSpeed = 80;
    iRightSpeed = 80;
    initRobotBase();
    mSleep(1500);

    powerON(); // Encoder und Motorstromsensoren anschalten!

	//inital value
	state = r1;


    while(true)
    {
        Zustand();
        task_motionControl();
		task_RP6System();
    }
    return 0;

}



/******************** End of file <main.c> ***********************************/
