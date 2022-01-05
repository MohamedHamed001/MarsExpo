#pragma once
#include "Pqueue.h";
#include "Queue.h";
#include "UI.h";
#include "Rovers.h";
#include "Mission.h";

class Event
{
protected:
	int Eventday;
	int MissionID;
public:
	Event(int ED, int missionID);
	
	int getED();

	virtual void Excute(LinkedQueue<Mission>& Mountainous, LinkedQueue<Mission>& Polar, PriQ<Mission>& Emergency) = 0;

};
