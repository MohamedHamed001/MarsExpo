#include "Rovers.h"

Rover::Rover(char RoverType, int speed, int checkupdur, int numMBC)
{
	Type = RoverType;
	Speed = speed;
	CheckupDur = checkupdur;
	NumMissionBeforChechup = numMBC; // Numbeer of missions befor checkup
	inMaintainance = false;
}

void Rover::setType(char RT)
{
	Type = RT;
}

char Rover::getType()
{
	return Type;
}

void Rover::setID(int ID)
{
	Rover_ID = ID;
}

int Rover::getID()
{
	return Rover_ID;
}

void Rover::setSpeed(int S)
{
	Speed = S;
}

int Rover::getSpeed()
{
	return Speed;
}

void Rover::setCheckUpDur(int CD)
{
	CheckupDur = CD;
}

int Rover::getCheckupDur()
{
	return CheckupDur;
}

bool Rover::getinMaintainance()
{
	return inMaintainance;
}