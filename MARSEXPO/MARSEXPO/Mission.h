#pragma once
#include "Rovers.h"
class Mission
{
private:
	Rover* rover;
	int ID;
	int FormulationDay;
	char MissionType;
	int TargetLoc;
	int MissionDur;
	int significance;
	int WaitingDays;
	int TotalMissionDuration;
	int ExecutionDays;
	int CompleteDay;

public:
	Mission(int FormulationDay, char MissionType, int id, int TargetLoc, int MissionDur, int Significance, Rover* r = nullptr);

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
	int getCD();
	int getED(); 
	int getID();


};
