#pragma once
#include "Events.h"

class Cancellation :public Event
{
public:
	Cancellation(int id, int ED);
	void Execute(PriQ<Mission*>& Emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& Polar);
};