#include "Events.h"

Event::Event(char t, int ED, int id)
{
	T = t; //Event type (F,P,C)
	ID = id;
	Event_day = ED;
}
