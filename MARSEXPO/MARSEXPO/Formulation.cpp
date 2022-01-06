#include "Formulation.h"


FormulationEvent::FormulationEvent(char t, int e, int i, int tL, int nD, int s):Event(e),
 ID(i), TYP(t), TLOC(tL), MDUR(nD), SIG(s)
{}


FormulationEvent::~FormulationEvent() {}

int FormulationEvent::getTargetLocation()const { return TLOC; }

int FormulationEvent::getMissionDuration()const { return MDUR; }

int FormulationEvent::getMissionSignificance()const { return SIG; }

int FormulationEvent::getId() const
{
	return ID;
}

//execute
void FormulationEvent::execute(PriQ<Mission*>& emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& polar)
{


	Mission* mission;

	if (TYP == 'E')
	{
		mission = new Mission_Emergency(ID, TLOC, MDUR, getED(), SIG);
		emergency.insert(mission, ((Mission_Emergency*)mission)->Get_Priority());
	}
	else if (TYP == 'M')
	{
		mission = new Mission_Mountainous(ID, TLOC, MDUR, getED(), SIG, ((Mission_Mountainous*)mission)->Get_AutoP());
		Mountainous.enqueue(mission);
	}
	else if (TYP == 'P')
	{
		mission = new Mission_Polar(ID, TLOC, MDUR, getED(), SIG);
		polar.enqueue(mission);
	}
	return;
}