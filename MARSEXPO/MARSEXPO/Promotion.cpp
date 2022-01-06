#include "Events.h"
#include "Node.h"
#include "Queue.h"
#include "Pqueue.h"
#include "Promotion.h"


PromotionEvent::PromotionEvent(int id, int ED):Event(ED)
{
	ID = id;
} 

void PromotionEvent::Execute(MarsStaion* mStation) //me7tag amshy 3la el list w adwr 3la el id ely mab3oltly 3lashan yt3mlo promotion
{	
	Mission_Mountainous m(ID, 0, 0, 0, 0, 0);
	int indexofmission = mStation->IndexOfMountainousMission(m);
	if (indexofmission != 1)
	{
		Mission_Mountainous MM = mStation->getMountainious(indexofmission);
		Mission_Emergency* NEM = new Mission_Emergency(MM.Get_ID(), MM.Get_Tloc(), MM.Get_MissionDuration(), MM.Get_Formulation_day(), MM.Get_SIG());
		mStation->removeMountainousMission(indexofmission);
		mStation->AddMission(NEM);
	}
}

PromotionEvent::~PromotionEvent()
{
}
