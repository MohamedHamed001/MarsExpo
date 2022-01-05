#pragma once
#include "Pqueue.h"
#include "Queue.h"
#include "Mission.h"


class Event
{
protected:
	int ID;
	int Event_day;

public:
	Event(int, int);
	virtual void Execute(PriQ<Mission>& Emergency, Queue<int>& Mountainous, Queue<Mission>& Polar) = 0;

};
