#pragma once
#include "Events.h" 
#include "MarsStation.h"

class PromotionEvent : public Event
{
private:
	int ID;
public:
	PromotionEvent(int id, int ED);
	void execute(MarsStation* mStation);
	~PromotionEvent();
};
