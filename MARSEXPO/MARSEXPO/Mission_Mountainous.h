#pragma once
#include "Mission.h"

class Mission_Mountainous :public Mission
{
	int AutoP;
public:
	Mission_Mountainous(int, int, int, int, int, int);

	int Get_AutoP();
	bool needsAutoP();

};
