#include "Mission.h"


Mission::Mission(char ET, char Type, int ED, int Id, int Loc, int Dur, int S, Rover* R)
{
	EventType = ET;
	MissionType = Type;
	EventDay = ED;
	ID = Id;
	TargetLoc = Loc;
	MissionDur = Dur;
	significance = S;
	rover = R;
	WaitingDays = 0;
	TotalMissionDuration = 0;
}

Mission::Mission(char EventTyp, int EventD, int id, Rover* r)
{
	EventType = EventTyp;
	EventDay = EventD;
	ID = id;
}

void Mission::setID(int id)
{
	ID = id;
}

int Mission::getID()
{
	return ID;
}

void Mission::setRover(Rover* R)
{
	if (R)
		TotalMissionDuration = MissionDur + (TargetLoc / (R->getSpeed())) * 2 / 25; //wa2t el mission + el tari2 ray7 rag3 w khod balk day on mars 25h
	rover = R;
}

Rover* Mission::getRover()
{
	return rover;
}

void  Mission::setMissionType(char Type)
{
	MissionType = Type;
}

char  Mission::getMissionType()
{
	return MissionType;
}

void Mission::setFormulationDay(int FD)
{
	FormulationDay = FD;
}

int Mission::getFormulationDay()
{
	return FormulationDay;
}

void Mission::setTargetLoc(int Loc)
{
	TargetLoc = Loc;
}

int Mission::getTargetLoc()
{
	return TargetLoc;
}

void Mission::setMissionDur(int Dur)
{
	MissionDur = Dur;
}

int Mission::getMissionDur()
{
	return MissionDur;
}

void Mission::setSignificance(int S)
{
	significance = S;
}

int Mission::getSignificance()
{
	return significance;
}

int Mission::getTotalMissionDur()
{
	return TotalMissionDuration;
}

void  Mission::increamentWaitingDays()
{
	WaitingDays++;
}

int Mission::getWD()
{
	return WaitingDays;
}

void Mission::setCD(int CD)
{
	CompleteDay = CD;
}

int Mission::getCD()
{
	return CompleteDay;
}

void Mission::setED(int ED)
{
	ExecutionDays = ED;
}

int Mission::getED()
{
	return ExecutionDays;
}
