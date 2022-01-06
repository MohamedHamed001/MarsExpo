#include "Rovers.h"

Rover::Rover() : Speed(-1), Missions_Befor_Checkup(-1), Checkup_Dur(-1)
{
	Num_Missions = 0;
	Curr_Mission = nullptr;
	Checkup_EndDay = -1;
	Missions_Till_Checkup = Missions_Befor_Checkup;
}

Rover::Rover(int S, int CheckMissions, int CheckDur) : Speed(S), Missions_Befor_Checkup(CheckMissions), Checkup_Dur(CheckDur)
{
	// initially, the rover has done no missions
	// and has no assinged mission
	Num_Missions = 0;
	Curr_Mission = nullptr;
	Checkup_EndDay = -1;
	Missions_Till_Checkup = Missions_Befor_Checkup;
}

void Rover::set_ID(int ID)
{
	Rover_ID = ID;
}

int Rover::get_ID() const
{
	return Rover_ID;
}

void Rover::set_Num_Mission(int N)
{
	Num_Missions = N;
}

int Rover::get_Num_Missions() const
{
	return Num_Missions;
}

void Rover::set_Checkup_EndDay(int endDay)
{
	Checkup_EndDay = endDay;
}

int Rover::get_Checkup_EndDay() const
{
	return Checkup_EndDay;
}

float Rover::get_Speed() const
{
	return Speed;
}

int Rover::get_Missions_Befor_Checkup() const
{
	return Missions_Befor_Checkup;
}

int Rover::get_Checkup_Dur() const
{
	return Checkup_Dur;
}

void Rover::set_Missions_Till_Checkup(int x)
{
	Missions_Till_Checkup = x;
}

int Rover::get_Missions_Till_Checkup() const
{
	return Missions_Till_Checkup;
}

void Rover::set_Mission(Mission* mission = nullptr)  // if no parameter is given, it removes the mission / frees the rover 
{
	Curr_Mission = mission;
}

Mission* Rover::get_Mission() const
{
	return Curr_Mission;
}

bool Rover::ReachCheckup() const
{
	return Missions_Till_Checkup == 0;
}

