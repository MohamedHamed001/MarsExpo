#pragma once
#include"Events.h"
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Mountainous.h"
#include "Mission_Polar.h"
#include "PriQ.h"
#include "Queue.h"

//class FormulatoinEvent
class FormulationEvent : public Event
{
private:
	const int ID;
	const char TYP;
	const int TLOC;
	const int MDUR;
	const int SIG;
public:
	FormulationEvent(int, int, char, int, int, int);
	~FormulationEvent();

	virtual void execute(PriQ<Mission*>& , Queue<Mission*>& , Queue<Mission*>& );
	int getTargetLocation()const;
	int getMissionDuration()const;
	int getMissionSignificance()const;
	int getId() const;
};;

