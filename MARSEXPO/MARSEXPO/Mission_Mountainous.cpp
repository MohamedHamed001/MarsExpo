#include "Mission_Mountainous.h"

Mission_Mountainous::Mission_Mountainous(int id, int location, int duration, int formulation, int sig, int Promo) :Mission(id, location, duration, formulation, sig)
{
	this->AutoP = Promo;
}

int Mission_Mountainous::Get_AutoP()
{
	return AutoP;
}

bool Mission_Mountainous::needsAutoP()
{
	return (this->Get_Waiting_Days() >= AutoP);
}