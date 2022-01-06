#pragma once
#include "Events.h" 

class Promotion : public Event
{
public:
	Promotion(int id, int ED);
	void Execute(PriQ<Mission*>& Emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& Polar);
};
