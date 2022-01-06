#include "MarsStation.h"

MarsStation::MarsStation()
{
    UserInterface = new UI();
    current_day = 0;
    Num_Of_Events = 0;
    srand(time(NULL)); // changes the seed for rand()
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

