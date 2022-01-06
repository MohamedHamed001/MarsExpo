#include "Events.h"
#include "Node.h"
#include "Queue.h"
#include "Pqueue.h"
#include "Formulation.h"

Formulation::Formulation(char T, int ED, int id, int Loc, int MD, int sig) :Event('F', ED, id)
{
	TYP = T;
	TLOC = Loc;
	MDUR = MD;
	SIG = sig;
}
// void Formulation::Execute()