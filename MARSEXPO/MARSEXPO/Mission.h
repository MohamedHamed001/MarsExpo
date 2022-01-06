#pragma once
#include<iostream>
#include "Rovers.h"
class Mission
{
private:
	Rover* rover;
	char MissionType;
	int TargetLoc;
	int MissionDur;
	int significance;
	int WaitingDays;
	int TotalMissionDuration;
	int ExecutionDays;
	int CompleteDay;
	int ID;
	int EventDay;
	int FormulationDay;

public:
	Mission(char MissionType, int EventD, int id, int TargetLoc, int MissionDur, int Significance, Rover* r = nullptr);
	Mission( int EventD, int id, Rover* r = nullptr);

	void setRover(Rover*);
	Rover* getRover();

	void setTargetLoc(int);
	void setMissionDur(int);
	void setSignificance(int);
	void setFormulationDay(int);
	void setMissionType(char);
	void increamentWaitingDays();
	void setCD(int);
	void setED(int);
	void setID(int);

	int getFormulationDay();
	char getMissionType();
	int getTargetLoc();
	int getMissionDur();
	int getSignificance();
	int getWD();
	int getTotalMissionDur();
	int getED();
	int getCD();
	int getID();

};
