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
	Formulation(char, char, int, int, int, int);
	void Execute(PriQ<Mission>& Emergency, Queue<int>& Mountainous, Queue<Mission>& Polar);

};

