#pragma once
#include "Mission.h"

class Mission_Emergency :public Mission
{
private:
	int priority;
	void Calc_Priority();

public:
	Mission_Emergency(int, int, int, int, int);
	int Get_Priority();
};
