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
void FormulationEvent::execute(MarsStation* mStation)
{

	if (TYP == 'E')
	{
		Mission* mission = new Mission_Emergency(ID, TLOC, MDUR, getED(), SIG);
		mStation->AddMission(mission);
	}
	else if (TYP == 'M')
	{
		Mission* mission = new Mission_Mountainous(ID, TLOC, MDUR, getED(), SIG, mStation->getAutoPromot());
		mStation->AddMission(mission);
	}
	else if (TYP == 'P')
	{
		Mission* mission = new Mission_Polar(ID, TLOC, MDUR, getED(), SIG);
		mStation->AddMission(mission);
	}
	return;
}

