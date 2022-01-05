#pragma once
class Rover
{
private:
	char Type;
	int Speed;
	int CheckupDur;
	int NumMissionBeforChechup; // Numbeer of missions befor checkup
	bool inMaintainance;
public:
	Rover(char RoverType, int Speed, int checkupDur, int numMBC);

	void setType(char);
	void setSpeed(int);
	void setCheckUpDur(int);
	char getType();
	int getSpeed();
	int getCheckupDur();
	bool getinMaintainance();
};
