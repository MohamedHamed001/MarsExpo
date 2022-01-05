#include "Events.h"

Event::Event(int ED, int missionID)
{
	Eventday = ED;
	MissionID = missionID;
}

int Event::getED()
{
	return Eventday;
}