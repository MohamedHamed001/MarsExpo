#pragma once
#include "Events.h"
#include"MarsStation.h"

class AutoPromotionEvent :public Event
{
public:
	AutoPromotionEvent(int);
	void execute(MarsStation* mStation);

	~AutoPromotionEvent();
};

