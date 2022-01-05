#pragma once
#include<iostream>

class Rover
{
private:
	char Type;
	int Rover_ID;
	int Speed;
	int CheckupDur;
	int NumMissionBeforChechup; // Numbeer of missions befor checkup
	bool inMaintainance;
public:
	Rover(char RoverType, int Speed, int checkupDur, int numMBC);

	void setType(char);
	void setID(int);
	void setSpeed(int);
	void setCheckUpDur(int);
	char getType();
	int getID();
	int getSpeed();
	int getCheckupDur();
	bool getinMaintainance();
};
