#pragma once
#include "Mission.h"
#include "Mission_Emergency.h"
#include "Mission_Mountainous.h"
#include "Mission_Polar.h"
class Rover
{
private:
	int Rover_ID;				// ID for each rover
	int Num_Missions;			// number of missions done by rover (failures are counted too)
	int Checkup_EndDay;			// the day the rover will finish checkup
	float AvgSpeed;				// speed for each rover type
	int Missions_Befor_Checkup;	// number of missions before needing a checkup
	int Checkup_Dur;			// checkup duration
	int Missions_Till_Checkup;	// number of missions left till checkup is required
	Mission* Curr_Mission;		// the missions currently in execution

	
public:
	static int I_D;
	Rover();
	Rover(int, int, int);
	~Rover();

	virtual void set_ID(int);
	virtual int get_ID() const;

	virtual void set_Num_Mission(int);
	virtual int get_Num_Missions() const;

	virtual void set_Checkup_EndDay(int);
	virtual int get_Checkup_EndDay() const;

	virtual float get_Avg_Speed() const;
	virtual int get_Missions_Befor_Checkup() const;
	virtual int get_Checkup_Dur() const;

	virtual void set_Missions_Till_Checkup(int);
	virtual int get_Missions_Till_Checkup() const;

	virtual void set_Mission(Mission*);  // set/removes the mission
	virtual Mission* get_Mission() const;

	bool ReachCheckup() const;

};
