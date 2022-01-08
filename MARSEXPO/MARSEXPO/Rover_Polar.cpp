#include "Rover_Polar.h"
#include <stdlib.h> // to use rand() function

Rover_Polar::Rover_Polar(int S, int CheckMissions, int CheckDur) : Rover(S, CheckMissions, CheckDur)
{
	set_ID(++I_D); // increases static id from 0 to 1 for example, then places it
	set_Speed(get_Avg_Speed());
}

void Rover_Polar::set_Speed(int S)
{
	int percentage = rand() % 31;		     // generates a random number between 0 and 30
	percentage += 60;					     // shifts the numbers to [60, 90]
	Speed = (float(percentage) / 100.0) * S; // sets the actual speed of the rover to
											 // a number from 60% to 90% of the speed entered
}

float Rover_Polar::get_Speed() const
{
	return Speed;
}
