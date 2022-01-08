#include "Rover_Mountainous.h"
#include <stdlib.h> // to use rand() function

Rover_Mountainous::Rover_Mountainous(int S, int CheckMissions, int CheckDur) : Rover(S, CheckMissions, CheckDur)
{
	set_ID(++I_D); // increases static id from 0 to 1 for example, then places it
	set_Speed(get_Avg_Speed());
}

void Rover_Mountainous::set_Speed(float S)
{
	int percentage = rand() % 21;					// generates a random number between 0 and 20
	percentage += 80;	
	Speed = (float(percentage) / 100.0) * S;		// shifts the numbers to [80, 100]
													// sets the actual speed of the rover to
													 // a number from 80% to 100% of the speed entered
}

float Rover_Mountainous::get_Speed() const
{
	return Speed;
}