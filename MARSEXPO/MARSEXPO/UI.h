#pragma once
#include <windows.h>

#include "Events.h"
#include "Formulation.h"
#include "Cancellation.h"
#include "Promotion.h"
#include "Rovers.h"
#include "Rover_Mountainous.h"
#include "Rover_Emergency.h"
#include "Rover_Polar.h"
#include "PriQ.h"
#include "Queue.h"
#include "MarsStation.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


class UI
{
private:
	int M_Rovers;			// number of Mountainous  rovers
	int P_Rovers;			// number of polar rovers
	int E_Rovers;			// number of emergency rovers
	int M_Speed;			// speed of Mountainous rover
	int P_Speed;			// speed of polar rover
	int E_Speed;			// speed of emergency rover
	int Checkup;			// number of missions before checkup
	int M_Checkup_Dur;		// checkup duration for polar rovers
	int P_Checkup_Dur;		// checkup duration for polar rovers
	int E_Checkup_Dur;		// checkup duration for emergency rovers
	int AutoPr;				// number of days after which a mountainous mission is automatically promoted to an emergency mission
	int Num_Events;			// number of events
	int mode;				// desired output mode
	int AutoP;
	bool Fill_Events(ifstream& fin, Queue<Event*>& Event_List, int& NoOFMissions);  // Takes empty list of events from MarsStation
																 // and fills it with the events read from file

	void Fill_Rovers(ifstream& fin, PriQ<Rover*>& rovers_Mountainous, PriQ<Rover*>& rovers_polar, PriQ<Rover*>& rovers_emergency);				// Takes empty list of rovers from Marstations
																																				// and fills it with the rovers read from file

public:
	bool Read_File(Queue<Event*>& Event_List, PriQ<Rover*>& rovers_Mountainous, PriQ<Rover*>& rovers_polar, PriQ<Rover*>& rovers_emergency, int& NoOFMissions);	// reads input from file, and calls Fill_Events and Fill_Rovers

	int get_Num_M_Rovers() const;
	int get_Num_P_Rovers() const;
	int get_Num_E_Rovers() const;
	int get_Checkup() const;
	int get_M_Checkup_Dur() const;
	int get_P_Checkup_Dur() const;
	int get_E_Checkup_Dur() const;
	int get_AutoP() const;
	int get_NumEvents() const;
	void Set_Auto(int);
	void Print(string, string, string, string, string, string);
	void SaveFile(string, string, string, string, float, float, int);
	int getMode();
	void Error();
};
//aboooood
