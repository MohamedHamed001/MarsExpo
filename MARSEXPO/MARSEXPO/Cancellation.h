#pragma once
#include "Events.h"

class CancellationEvent :public Event
{
public:
	CancellationEvent(int id, int ED);
	void Execute(PriQ<Mission*>& , Queue<Mission*>& , Queue<Mission*>&);

};