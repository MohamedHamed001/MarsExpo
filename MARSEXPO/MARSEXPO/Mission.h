#pragma once
#pragma once
#include <cmath>

class Mission
{
private:
	const int ID;
	int Tloc;
	int MissionDuration; //excution day
	int SIG; //significance given from file

	///////////////////////
	int Formulation_day; //given in the doc
	int Waiting_Days; //curr-formulation
	int Excution_Days; //calculated= MissionDuration + Ceil[((2*Tloc)/(velocity))/25]	

	int Completion_Day; //calculated = Formulation + Waiting + Excution

public:
	Mission(int, int, int, int, int);

	//setters
	void Set_Formulation_day(int);
	void Set_Waiting_Days(int);
	void Set_Excution_Days(float); //calc the ED takes input the velocity of each rovers
	void Set_Completion_Day(); //calculates the completion day

	virtual int Get_Formulation_day(); //mission rekated getters
	virtual int Get_Waiting_Days();
	virtual int Get_Excution_Days();
	virtual int Get_Completion_Day();
	virtual int Get_SIG();

	virtual int Get_ID();  //rover related getters
	virtual int Get_Tloc();
	virtual int Get_MissionDuration();
	virtual int Get_Priority() = 0;

};