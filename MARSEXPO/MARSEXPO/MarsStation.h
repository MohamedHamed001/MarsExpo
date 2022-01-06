#pragma once

#include "LinkedList.h"
#include "Node.h"
#include "PriNode.h"
#include "PriQ.h"
#include "Queue.h"

#include "Events.h"
#include "UI.h"
#include "Mission.h"
#include "Rovers.h"
#include "Cancellation.h"
#include "Formulation.h"
#include "Promotion.h"
#include "Mission_Emergency.h"
#include "Mission_Mountainous.h"
#include "Mission_Polar.h"
#include "Rover_Emergency.h"
#include "Rover_Mountainous.h"
#include "Rover_Polar.h"



/// <summary>
/// FOR AMIN EL AMAR <3
/// </summary>
class Event;

class MarsStation
{
private:
	Queue<Event*> Event_List;
	PriQ<Mission*> CompletedMissions;

	// available rovers sorted according to speed
	PriQ<Rover*> rovers_Mountainous;
	PriQ<Rover*> rovers_Emergency;
	PriQ<Rover*> rovers_Polar;          

	//PriQ<Rover*> rovers_Inexecution;    // sorted according to completion day

	Queue<Rover*> rovers_Mountainous_checkup;
	Queue<Rover*> rovers_Emergency_checkup;
	Queue<Rover*> rovers_Polar_checkup;   


	List<Mission_Mountainous> mountainousWaitingMission; //linked list implementation for mountainous Missions 
	PriQ<Mission_Emergency*> EmergencyWaitingMission;
	Queue<Mission_Polar*> PolarWaitingMission;


	UI* UserInterface;	 // pointer to user interface

	int current_day;
	int Num_Of_Events;
	int NoOfPromotedMissions;

public:
	MarsStation(); //contructor
	~MarsStation();


	//promotion related
	Mission_Mountainous getMountainious(int index);

	//Auto Promotion
	void PromoteMtoE();


	//Formulation Section
	void AddMission(Mission* m);

	//cancellation event related
	int IndexOfMountainousMission(const Mission_Mountainous& mMission);
	void removeMountainousMission(int index);

};