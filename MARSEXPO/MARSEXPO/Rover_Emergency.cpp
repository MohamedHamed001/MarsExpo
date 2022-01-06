#include "Rover_Emergency.h"
#include <stdlib.h> // to use rand() function

Rover_Emergency::Rover_Emergency(int S, int CheckMissions, int CheckDur) : Rover(S, CheckMissions, CheckDur)
{
	set_ID(++ID); // increases static id from 0 to 1 for example, then places it
	set_Speed(get_Speed());
}

void Rover_Emergency::set_Speed(int S)
{
	int percentage = rand() % 41;		     // generates a random number between 0 and 40
	percentage += 90;					     // shifts the numbers to [90, 130]
	Speed = (float(percentage) / 100.0) * S; // sets the actual speed of the rover to
											 // a number from 90% to 130% of the speed entered
}

float Rover_Emergency::get_Speed() const
{
	return Speed;
}