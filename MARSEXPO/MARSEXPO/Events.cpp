#include"Events.h"

Event::Event(int ed) : ED(ed > 0 ? ed : 0)
{}


int Event::getED()const 
{ 
	return ED; 
}

Event::~Event()
{}