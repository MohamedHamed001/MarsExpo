#include "MarsStation.h"

MarsStation::MarsStation()
{
    UIptr = new UI();
    current_day = 0;
    Num_Of_Events = 0;
    AutoP = 0;
    srand(time(NULL)); // changes the seed for rand()
}

bool MarsStation::Load()
{
    bool Valid = UIptr->Read_File(Event_List, rovers_Mountainous, rovers_Polar, rovers_Emergency);

    if (Valid)
    {
        UIptr->getMode();
        Num_Of_Events = Event_List.getSize();
    }
    return Valid;
}

void MarsStation::simulate()
{
    bool Sim_Possible = Load();
    if (!Sim_Possible)
    {
        UIptr->Error();
        return;
    }
    while (Num_Of_Events != CompletedMissions.getSize())
    {
        current_day++;
        CheckEvent();
        CheckInExe();
        CheckInCheckup();

        Assign_mountainousMission();
        Assign_PolarMission();
        Assign_EmergencyMission();

        Output();
    }


    SaveFile();
}

void MarsStation::setAutoPromot(int autoProm)
{
    AutoP = (autoProm >= 0 ? autoProm : 0);
}
int MarsStation::getAutoPromot()
{
    return AutoP;
}

void MarsStation::setEventCount(int count)
{
    Num_Of_Events = (count >= 0 ? count : 0);
}

int MarsStation::getEventCount() const
{
    return  Num_Of_Events;
}

void MarsStation::AddMission(Mission* m)
{
    Mission_Emergency* nM1 = dynamic_cast<Mission_Emergency*>(m);
    if (nM1)
    {
        EmergencyWaitingMission.insert(nM1, nM1->Get_Priority());
        return;
    }
    Mission_Mountainous* nM2 = dynamic_cast<Mission_Mountainous*>(m);
    if (nM2)
    {
        mountainousWaitingMission.insert(mountainousWaitingMission.getLength()+1,*nM2); //insertEND
        return;
    }
    Mission_Polar* nM3 = dynamic_cast<Mission_Polar*>(m);
    if (nM3)
    {
        PolarWaitingMission.enqueue(nM3);
        return;
    }
}


int MarsStation::IndexOfMountainousMission(const Mission_Mountainous& mMission)
{
    return mountainousWaitingMission.getIndexOf(mMission);
}

void MarsStation::removeMountainousMission(int index)
{
    mountainousWaitingMission.remove(index);
}



Mission_Mountainous MarsStation::getMountainious(int index)
{
    return mountainousWaitingMission.getEntry(index);
}

void MarsStation::PromoteMtoE()
{
    if (mountainousWaitingMission.isEmpty())    
        return;
    Mission_Mountainous* Temp = new Mission_Mountainous(mountainousWaitingMission.getEntry(1)); //Temp -> to first element
    while (Temp->needsAutoP())
    {
        Mission_Emergency* NEM = new Mission_Emergency(Temp->Get_ID(), Temp->Get_Tloc(), Temp->Get_MissionDuration(), Temp->Get_Formulation_day(), Temp->Get_SIG());
        EmergencyWaitingMission.insert(NEM, NEM->Get_Priority());
        NoOfPromotedMissions++;
        mountainousWaitingMission.remove(1);
        if (mountainousWaitingMission.isEmpty())
            return;
        Temp = new Mission_Mountainous(mountainousWaitingMission.getEntry(1));
    }
}

MarsStation::~MarsStation()
{
}



void MarsStation::CheckEvent()
{
    Event* Temp;
    while (Event_List.peek(Temp))
    {
        if (Temp->getED() != current_day) return;

        Event_List.dequeue(Temp);
        Temp->execute(this);
    }
}

void MarsStation::CheckInExe()
{
    Rover* TempR;
    Mission* TempM;
    while (!rovers_Inexecution.isEmpty())
    {
        if (rovers_Inexecution.peek()->get_Mission()->Get_Completion_Day() != current_day) return;

        TempR = rovers_Inexecution.GetMax();
        TempM = TempR->get_Mission();
        TempR->set_Mission(nullptr);

        CompletedMissions.insert(TempM,TempM->Get_Excution_Days());

        if (TempR->ReachCheckup())
        {
            TempR->set_Checkup_EndDay(TempR->get_Checkup_Dur() + current_day);

            if (dynamic_cast<Rover_Mountainous*>(TempR))
                rovers_Mountainous_checkup.enqueue(TempR);
            if (dynamic_cast<Rover_Polar*>(TempR))
                rovers_Polar_checkup.enqueue(TempR);
            if (dynamic_cast<Rover_Emergency*>(TempR))
                rovers_Emergency_checkup.enqueue(TempR);
        }
        else
        {
            if (dynamic_cast<Rover_Mountainous*>(TempR))
                rovers_Mountainous.insert(TempR, ((Rover_Mountainous*)TempR)->get_Speed());
            if (dynamic_cast<Rover_Polar*>(TempR))
                rovers_Polar.insert(TempR, ((Rover_Polar*)TempR)->get_Speed());
            if (dynamic_cast<Rover_Emergency*>(TempR))
                rovers_Emergency.insert(TempR, ((Rover_Emergency*)TempR)->get_Speed());
        }

    }
}

void MarsStation::CheckInCheckup()
{
    Rover* TempR;
    while (rovers_Mountainous_checkup.peek(TempR))
    {
        if (TempR->get_Checkup_EndDay() != current_day)
            break;
        rovers_Mountainous_checkup.dequeue(TempR);
        TempR->set_Checkup_EndDay(-1);
        rovers_Mountainous.insert(TempR, ((Rover_Mountainous*)TempR)->get_Speed());
    }
    while (rovers_Polar_checkup.peek(TempR))
    {
        if (TempR->get_Checkup_EndDay() != current_day)
            break;
        rovers_Polar_checkup.dequeue(TempR);
        TempR->set_Checkup_EndDay(-1);
        rovers_Polar.insert(TempR, ((Rover_Polar*)TempR)->get_Speed());
    }
    while (rovers_Emergency_checkup.peek(TempR))
    {
        if (TempR->get_Checkup_EndDay() != current_day)
            break;
        rovers_Emergency_checkup.dequeue(TempR);
        TempR->set_Checkup_EndDay(-1);
        rovers_Emergency.insert(TempR, ((Rover_Emergency*)TempR)->get_Speed());
    }
}

void MarsStation::Assign_mountainousMission()
{
    Rover* R;
    Mission_Mountainous* M;

    while (!(mountainousWaitingMission.isEmpty()))
    {
        if (!(rovers_Mountainous.isEmpty()))
        {
            M = new Mission_Mountainous(mountainousWaitingMission.getEntry(1));
            mountainousWaitingMission.remove(1);
            R = rovers_Mountainous.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Mountainous*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else if (!(rovers_Emergency.isEmpty()))
        {
            M = new Mission_Mountainous(mountainousWaitingMission.getEntry(1));
            mountainousWaitingMission.remove(1);
            R = rovers_Emergency.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Emergency*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else
            return;
    }

}

void MarsStation::Assign_PolarMission()
{
    Rover* R;
    Mission_Polar* M;

    while (!(PolarWaitingMission.peek(M)))
    {
        if (!(rovers_Polar.isEmpty()))
        {
            PolarWaitingMission.dequeue(M);
            R = rovers_Polar.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Polar*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else
            return;
    }
}

void MarsStation::Assign_EmergencyMission()
{
    Rover* R;
    Mission* M;

    while (!(EmergencyWaitingMission.isEmpty()))
    {
        if (!(rovers_Emergency.isEmpty()))
        {
            M = EmergencyWaitingMission.GetMax();
            R = rovers_Emergency.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Emergency*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else if (!(rovers_Mountainous.isEmpty()))
        {
            M = EmergencyWaitingMission.GetMax();
            R = rovers_Mountainous.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Mountainous*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else if (!(rovers_Polar.isEmpty()))
        {
            M = EmergencyWaitingMission.GetMax();
            R = rovers_Polar.GetMax();
            R->set_Mission(M);

            M->Set_Waiting_Days(current_day);
            M->Set_Excution_Days(((Rover_Polar*)R)->get_Speed());
            M->Set_Completion_Day();

            rovers_Inexecution.insert(R, (M->Get_Completion_Day()) * -1);

            R->set_Num_Mission(R->get_Num_Missions() + 1);
            R->set_Missions_Till_Checkup(R->get_Missions_Till_Checkup() - 1);
        }
        else
            return;
    }


}

void MarsStation::Output()
{
    string line1, line2, line3, line4, line5, line6;

    line1 = "Current Day:" + to_string(current_day);
    int waittingMission = mountainousWaitingMission.getLength() + PolarWaitingMission.getSize() + EmergencyWaitingMission.getSize();
    line2 = to_string(waittingMission) + " Waiting Missions: " + stringMissionPriQ(EmergencyWaitingMission) + " " + stringPMissionQ(PolarWaitingMission) + " " + stringMMission(mountainousWaitingMission); // with rover ID

    int inexc = rovers_Inexecution.getSize();
    line3 = to_string(inexc) + " In-Execution Missions/Rovers: " + stringInExcM_R(rovers_Inexecution);

    int availableRovers = rovers_Emergency.getSize() + rovers_Mountainous.getSize() + rovers_Polar.getSize();
    line4 = to_string(availableRovers) + " Available Rovers: "  + stringRover(rovers_Emergency) + stringRover(rovers_Polar) + stringRover(rovers_Mountainous);

    int inCheckup = rovers_Emergency_checkup.getSize() + rovers_Mountainous_checkup.getSize() + rovers_Polar_checkup.getSize();
    line5 = to_string(inCheckup) + " In-Checkup Rovers: " + stringCheckUpRover(rovers_Emergency_checkup) + stringCheckUpRover(rovers_Polar_checkup) + stringCheckUpRover(rovers_Mountainous_checkup);

    int compMission = CompletedMissions.getSize();
    line6 = to_string(compMission) + " Completed Missions: " + stringCompMission(CompletedMissions);

    UIptr->Print(line1, line2, line3, line4, line5, line6);
}

string MarsStation::stringRover(PriQ<Rover*> x)
{
    PriQ<Rover*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string wattingE = "[";
    string watinngP = "(";
    string wattingM = "{";

    for (int i = 0; i < size; i++)
    {
        Rover* cur = Temp.GetMax();

        if (dynamic_cast<Rover_Emergency*>(cur)) 
            wattingE += to_string(cur->get_ID()) + ", ";

        else if (dynamic_cast<Rover_Polar*>(cur))
            watinngP += to_string(cur->get_ID()) + ", ";

        else if (dynamic_cast<Rover_Mountainous*>(cur))
            wattingM += to_string(cur->get_ID()) + ", ";
    }
    if (wattingE == "[") wattingE = "";
    if (watinngP == "(") watinngP = "";
    if (wattingM == "{") watinngP = "";
    if (wattingE != "") wattingE.pop_back(), wattingE.pop_back(), wattingE += "]";
    if (watinngP != "") watinngP.pop_back(), watinngP.pop_back(), watinngP += ")";
    if (wattingM != "") wattingM.pop_back(), wattingM.pop_back(), wattingM += "}";
    return wattingE + " " + watinngP + " " + wattingM;
}

string MarsStation::stringInExcM_R(PriQ<Rover*> x)
{
    PriQ<Rover*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string inexcE = "[";
    string inexcP = "(";
    string inexcM = "{";

    for (int i = 0; i < size; i++)
    {
        Rover* curR = Temp.GetMax();
        Mission* curM = curR->get_Mission();

        if (dynamic_cast<Mission_Emergency*>(curR)) {
            inexcE += to_string(curM->Get_ID()) + "/";
            inexcE += to_string(curR->get_ID()) + ", ";
        }

        else if (dynamic_cast<Mission_Polar*>(curR)) {
            inexcP += to_string(curM->Get_ID()) + "/";
            inexcP += to_string(curR->get_ID()) + ", ";
        }

        else if (dynamic_cast<Mission_Mountainous*>(curR)) {
            inexcM += to_string(curM->Get_ID()) + "/";
            inexcM += to_string(curR->get_ID()) + ", ";

        }
    }
    if (inexcE == "[") inexcE = "";
    if (inexcP == "(") inexcP = "";
    if (inexcM == "{") inexcP = "";
    if (inexcE != "") inexcE.pop_back(), inexcE.pop_back(), inexcE += "]";
    if (inexcP != "") inexcP.pop_back(), inexcP.pop_back(), inexcP += ")";
    if (inexcM != "") inexcM.pop_back(), inexcM.pop_back(), inexcM += "}";
    return inexcE + " " + inexcP + " " + inexcM;
}

string MarsStation::stringCheckUpRover(Queue<Rover*> x)
{
    Queue<Rover*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string wattingE = "[";
    string watinngP = "(";
    string wattingM = "{";

    for (int i = 0; i < size; i++)
    {
        Rover* cur;
        Temp.dequeue(cur);

        if (dynamic_cast<Rover_Emergency*>(cur))
            wattingE += to_string(cur->get_ID()) + ", ";

        else if (dynamic_cast<Rover_Polar*>(cur))
            watinngP += to_string(cur->get_ID()) + ", ";

        else if (dynamic_cast<Rover_Mountainous*>(cur))
            wattingM += to_string(cur->get_ID()) + ", ";
    }
    if (wattingE == "[") wattingE = "";
    if (watinngP == "(") watinngP = "";
    if (wattingM == "{") watinngP = "";
    if (wattingE != "") wattingE.pop_back(), wattingE.pop_back(), wattingE += "]";
    if (watinngP != "") watinngP.pop_back(), watinngP.pop_back(), watinngP += ")";
    if (wattingM != "") wattingM.pop_back(), wattingM.pop_back(), wattingM += "}";
    return wattingE + " " + watinngP + " " + wattingM;
}

string MarsStation::stringCompMission(PriQ<Mission*> x)
{
    PriQ<Mission*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string compE = "[";
    string compP = "(";
    string compM = "{";

    for (int i = 0; i < size; i++)
    {
        Mission* cur = Temp.GetMax();

        if (dynamic_cast<Mission_Emergency*>(cur))
            compE += to_string(cur->Get_ID()) + ", ";

        else if (dynamic_cast<Mission_Polar*>(cur))
            compP += to_string(cur->Get_ID()) + ", ";

        else if (dynamic_cast<Mission_Mountainous*>(cur))
            compM += to_string(cur->Get_ID()) + ", ";
    }
    if (compE == "[") compE = "";
    if (compP == "(") compP = "";
    if (compM == "{") compP = "";
    if (compE != "") compE.pop_back(), compE.pop_back(), compE += "]";
    if (compP != "") compP.pop_back(), compP.pop_back(), compP += ")";
    if (compM != "") compM.pop_back(), compM.pop_back(), compM += "}";
    return compE + " " + compP + " " + compM;

}

string MarsStation::stringMissionPriQ(PriQ<Mission_Emergency*> x)
{
    PriQ<Mission_Emergency*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string E = "[";

    for (int i = 0; i < size; i++)
    {
        Mission_Emergency* cur = Temp.GetMax();
        E += to_string(cur->Get_ID()) + ", ";
    }
    if (E == "[") E = "";
    if (E != "") E.pop_back(), E.pop_back(), E += "]";
    return E + " ";
}

string MarsStation::stringPMissionQ(Queue<Mission_Polar*> x)
{
    Queue<Mission_Polar*> Temp = x;

    int size = Temp.getSize();
    if (size == 0) return "";

    string P = "(";

    for (int i = 0; i < size; i++)
    {
        Mission_Polar* cur;
        Temp.dequeue(cur);
        P += to_string(cur->Get_ID()) + ", ";
    }
    if (P == "(") P= "";
    if (P != "") P.pop_back(), P.pop_back(), P += ")";
    return P + " ";
}

string MarsStation::stringMMission(List<Mission_Mountainous> x)
{
    List<Mission_Mountainous> Temp = x;

    int size = Temp.getLength();
    if (size == 0) return "";

    string M = "{";

    for (int i = 1 ; i < size+1; i++)
    {
        Mission_Mountainous cur(i,0,0,0,0,0);
        Temp.remove(i);
        M += to_string(cur.Get_ID()) + ", ";
    }
    if (M == "{") M = "";
    if (M != "") M.pop_back(), M.pop_back(), M += "}";
    return M + " ";
}

void MarsStation::SaveFile()
{
    string line1 = "CD\tID\tFD\tWD\tED";

    Mission* x;
    string line2 = "";
    int num_missions(0), num_mount(0), num_pol(0), num_emerg(0), wait_Days(0), exec_Days(0),
    num_rov(0),num_mount_rov(0), num_pol_rov(0), num_emerg_rov(0);
    while (true)
    {
        x = CompletedMissions.GetMax();
        if (!x)
            break;
        num_missions++;
        wait_Days += x->Get_Waiting_Days();
        exec_Days += x->Get_Excution_Days();
        line2 += to_string(x->Get_Completion_Day()) + "\t" + to_string(x->Get_ID())
            + "\t" + to_string(x->Get_Formulation_day()) + "\t" + to_string(x->Get_Waiting_Days())
            + "\t" + to_string(x->Get_Excution_Days()) + "\n";
        if (dynamic_cast<Mission_Emergency*>(x)) num_emerg++;
        else if (dynamic_cast<Mission_Polar*>(x)) num_pol++;
        else num_mount++;
    }
    //Rover* y;
    num_rov = rovers_Mountainous.getSize() + rovers_Polar.getSize() + rovers_Emergency.getSize();
    num_mount_rov = rovers_Mountainous.getSize();
    num_pol_rov = rovers_Polar.getSize();
    num_emerg_rov = rovers_Emergency.getSize();

    string line3 = "Missions: " + to_string(num_missions) +"[M: "+ to_string(num_mount) +", P: " + to_string(num_pol) + ", E: " + to_string(num_emerg) + "]";
    string line4 = "Rovers: " + to_string(num_rov) + "[M: " + to_string(num_mount_rov) + ", P: " + to_string(num_pol_rov) + ", E: " + to_string(num_emerg_rov) + "]";
    float avg_wait, avg_exec, autoP;

    //Handling possible -but improbable- divison by zero
    if (num_missions == 0) {
        avg_wait = 0;
        avg_exec = 0;
    }
    else {
        avg_wait = 1.0 * wait_Days / num_missions;
        avg_exec = 1.0 * exec_Days / num_missions;
    }
    if ((num_mount + mountainousWaitingMission.getLength() + NoOfPromotedMissions) == 0)
        autoP = 0;
    else
        autoP = 100 * (NoOfPromotedMissions / (num_mount + mountainousWaitingMission.getLength() + NoOfPromotedMissions));
    
    //Calling UI Save Function
    UIptr->SaveFile(line1, line2, line3, line4, avg_wait, avg_exec, autoP);
}

