#pragma once
#include "Pqueue.h"
#include "Queue.h"
#include "Mission.h"


class Event
{
protected:
	char T;
	int ID;
	int Event_day;

public:
	Event(char, int, int);
	virtual void Execute(PriQ<Mission*>& Emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& Polar) = 0;
};
