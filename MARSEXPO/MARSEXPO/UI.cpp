#include "UI.h"



/*void UI::Abort()
{
	cout << "Simulation aborted due to improper input" << endl;
}*/

int UI::get_Num_M_Rovers() const
{
	return M_Rovers;
}

int UI::get_Num_P_Rovers() const
{
	return P_Rovers;
}

int UI::get_Num_E_Rovers() const
{
	return E_Rovers;
}

int UI::get_Checkup() const
{
	return Checkup;
}

int UI::get_M_Checkup_Dur() const
{
	return M_Checkup_Dur;
}

int UI::get_P_Checkup_Dur() const
{
	return P_Checkup_Dur;
}

int UI::get_E_Checkup_Dur() const
{
	return E_Checkup_Dur;
}

int UI::get_AutoP() const
{
	return AutoP;
}

int UI::get_NumEvents() const
{
	return Num_Events;
}

bool UI::Read_File(Queue<Event*>& Event_List, PriQ<Rover*>& rovers_emergency, PriQ<Rover*>& rovers_Mountainous, PriQ<Rover*>& rovers_polar )
{
	bool Valid;
	string filename;
	cout << "Enter file name to be loaded: ";
	cin >> filename;
	cout << endl;
	filename += ".txt"; // adds .txt extension to filename

	ifstream fin(filename); // opens file to read from

	if (fin.is_open()) // makes sure file was opened successfully
	{
		Fill_Rovers(fin, rovers_emergency, rovers_polar, rovers_Mountainous); // fills the rover lists
		Valid = Fill_Events(fin, Event_List);			  // fills the event list
	}

	fin.close(); // closes file so other handles could use it later on

	return Valid;
}

bool UI::Fill_Events(ifstream& fin, Queue<Event*>& Event_List)
{
	char ETyp = 'x';
	char MTyp = 'x';
	int ED = -1, id = -1, TLoc = -1, dur = -1, sig = -1;

	fin >> Num_Events;

	// There are no rovers, but there are missions
	// so simulation can't run
	if (M_Rovers == 0 && P_Rovers == 0 && E_Rovers == 0 && Num_Events != 0)
	{
		return false;
	}

	// There are rovers, but their speeds = 0
	// so simulation can't run 
	if (Num_Events != 0 && ((P_Rovers != 0 && P_Speed == 0) || (E_Rovers != 0 && E_Speed == 0) || (M_Rovers != 0 && M_Speed == 0)))
	{
		return false;
	}

	for (int i = 0; i < Num_Events; i++)  // loads the data of each event
	{
		fin >> ETyp >> MTyp >> ED >> id >> TLoc >> dur >> sig;

		// there are x missions, but no x rovers
		// so simulation can't run properly
		if (E_Rovers == 0 && MTyp == 'E' || M_Rovers == 0 && MTyp == 'M' || P_Rovers == 0 && MTyp == 'P')
		{
			return false;
		}
		if (ETyp == 'F')
		{
			FormulationEvent* Formulation = new FormulationEvent(MTyp, ED, id, TLoc, dur, sig);
			Event_List.enqueue(Formulation);
		}
		else if (ETyp == 'X')
		{
			Event* Cancellation = new Event(ED, id);
			Event_List.enqueue(Cancellation);
		}
		else if (ETyp == 'P')
		{
			Event* Promotion = new Event(ED, id);
			Event_List.enqueue(Promotion);
		}
	}

	return true; // simulation possible
}

void UI::Fill_Rovers(ifstream& fin, PriQ<Rover*>& rovers_emergency, PriQ<Rover*>& rovers_Mountainous, PriQ<Rover*>& rovers_polar)
{
	Rover* rover = nullptr;

	// takes input from file
	fin >> M_Rovers >> P_Rovers >> E_Rovers;
	fin >> M_Speed >> P_Speed >> E_Speed;
	fin >> Checkup >> M_Checkup_Dur >> P_Checkup_Dur >> E_Checkup_Dur;
	for (int i = 0; i < M_Rovers; i++)
	{
		rover = new Rover(M_Speed, Checkup, M_Checkup_Dur);						// creates the rover
		rovers_polar.insert(rover, ((Rover_Mountainous*)rover)->get_Speed());	// places it in the list, sorted
																				// descendingly according to speed
	}
	for (int i = 0; i < E_Rovers; i++)
	{
		rover = new Rover(E_Speed, Checkup, E_Checkup_Dur);						// creates the rover
		rovers_emergency.insert(rover, ((Rover_Emergency*)rover)->get_Speed()); // places it in the list, sorted
																				// descendingly according to speed
	}
	for (int i = 0; i < P_Rovers; i++)
	{
		rover = new Rover(P_Speed, Checkup, P_Checkup_Dur);				// creates the rover
		rovers_polar.insert(rover, ((Rover_Polar*)rover)->get_Speed()); // places it in the list, sorted
																		// descendingly according to speed
	}
}

int UI::getMode() {
	cout << "Welcome To Mars Ground Station !\n";
	cout << "Please choose mode of operation: 1-Interactive   2-Step-by-step   3-Silent\n";
	cin >> mode;
	return mode;
}

void UI::Print(string line1, string line2, string line3, string line4, string line5, string line6) {
	if (mode == 1) {
		cin.ignore();
		string x = "\n-------------------------------------------------------\n";
		cout << line1 << endl << line2 << x << line3 << x << line4 << x << line5 << x << line6 << endl << endl;

	}
	else if (mode == 2) {
		string x = "\n-------------------------------------------------------\n";
		cout << line1 << endl << line2 << x << line3 << x << line4 << x << line5 << x << line6 << endl << endl;
		Sleep(1000);
	}
}

void UI::SaveFile(string line1, string line2, string line3, string line4, float wait, float exec, int fails) {
	if (mode == 3)
		cout << "Silent Mode \nSimulation Starts...\n";

	ofstream saved_file;
	saved_file.open("saved_file.txt", ios::out | ios::trunc);
	saved_file << line1 << endl << line2 << endl << line3 << endl << line4 << endl;
	saved_file << "Avg. Wait = " << setprecision(3) << wait << ", Avg. Exec = " << setprecision(3) << exec;
	saved_file << endl << "Failures = " << fails;
	saved_file.close();
	cout << "Simulation ends, Output file created\n\n";
}

