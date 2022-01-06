#pragma once
#include<iostream>

class MarsStation;
class Event
{
private:
	const int ED; //EventDay 
public:
	Event(int);
	int getED()const;
	virtual void execute(MarsStation*) = 0; //pure virtual as each event has its logic and to make the event abstract class
	virtual ~Event();
};
