#include "AutoP.h"

AutoPromotionEvent::AutoPromotionEvent(int ED):Event(ED)
{}

void AutoPromotionEvent::execute(MarsStation* mStation)
{
	mStation->PromoteMtoE();
}

AutoPromotionEvent::~AutoPromotionEvent()
{
}


