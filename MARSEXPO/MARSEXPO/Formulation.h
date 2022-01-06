#pragma once
#include "Events.h"

class Formulation : public Event
{
private:
	char TYP;
	int TLOC;
	int MDUR;
	int SIG;

public:
	Formulation(char, int, int, int, int, int);
	void Execute(PriQ<Mission*>& Emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& Polar);
};

