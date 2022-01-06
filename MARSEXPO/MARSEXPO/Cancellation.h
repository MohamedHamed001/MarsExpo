#pragma once
#include "Events.h"
#include "MarsStation.h"


class CancellationEvent :public Event
{
private:
	int id;
public:
	CancellationEvent(int ED, int i);
	void execute(MarsStation* mStation);
	~CancellationEvent();
};