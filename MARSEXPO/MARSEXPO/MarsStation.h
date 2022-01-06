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

class MarsStaion
{
private:
	List<Mission_Mountainous> mountainousWaitingMission; //linked list implementation for mountainous Missions 
	PriQ<Mission_Emergency*> EmergencyWaitingMission;
	Queue<Mission_Polar*> PolarWaitingMission;
	int NoOfPromotedMissions;

public:
	MarsStaion(); //contructor
	~MarsStaion();


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