#include "Mission_Emergency.h"

Mission_Emergency::Mission_Emergency(int id, int location, int duration, int formulation, int sig) :Mission(id, location, duration, formulation, sig)
{
	Calc_Priority();
}

int Mission_Emergency::Get_Priority()
{
	return priority;
}

void Mission_Emergency::Calc_Priority()
{
	priority = 3 * (this->Get_Formulation_day()) + (this->Get_Tloc()) * 0.01 + 2 * (this->Get_MissionDuration()) + 4 * (this->Get_SIG());
	//priority is assignend according to:
	// the hishest factor is the segnificance then the formulation day the higher the better
	//for mission duration and location the lower it is in value the better
}