#pragma once
#include "Events.h" 
#include "Mission_Emergency.h"
#include "MarsStation.h"

class PromotionEvent : public Event
{
private:
	int ID;
public:
	//bool operator ==(const Mission& M);

	int getId() const;
	PromotionEvent(int id, int ED);
	void execute(MarsStation* mStation);
	~PromotionEvent();
};
