#include "Mission.h"

Mission::Mission(int id, int location, int durration, int formulation, int sig) :ID(id)
{
	this->Tloc = location;
	this->MissionDuration = durration;
	this->Formulation_day = formulation;
	this->SIG = sig;

	Waiting_Days = -1;
	Excution_Days = -1;
	Completion_Day = -1;
}

void Mission::Set_Formulation_day(int currentDay)
{
	Formulation_day = currentDay;
}

void Mission::Set_Waiting_Days(int currentDay)
{
	Waiting_Days = (currentDay - Formulation_day);
}

void Mission::Set_Excution_Days(float velocity)//calc the ED takes input the velocity of each rovers
{
	Excution_Days = MissionDuration + ceil(((2 * Tloc) / (velocity)) / 25);
}

void Mission::Set_Completion_Day() //calculates the completion day
{
	Completion_Day = Formulation_day + Waiting_Days + Excution_Days;
}

//mission rekated getters
int Mission::Get_Formulation_day() { return Formulation_day; }

int Mission::Get_Waiting_Days() { return Waiting_Days; }

int Mission::Get_Excution_Days() { return Excution_Days; }

int Mission::Get_Completion_Day() { return Completion_Day; }

//rover related getters
int Mission::Get_ID() { return ID; }

int Mission::Get_Tloc() { return Tloc; }

int Mission::Get_MissionDuration() { return MissionDuration; }

int Mission::Get_SIG() { return SIG; }

bool Mission::operator==(const Mission& recivedMission)
{
	if (recivedMission.ID == ID)
		return true;
	return false;
}

