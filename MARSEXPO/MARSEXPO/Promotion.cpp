#include "Events.h"
#include "Node.h"
#include "Queue.h"
#include "Pqueue.h"
#include "Promotion.h"


Promotion::Promotion(int id, int ED):Event('P',ED,id)
{
}

void Promotion::Execute(PriQ<Mission*>& Emergency, Queue<Mission*>& Mountainous, Queue<Mission*>& Polar) //me7tag amshy 3la el list w adwr 3la el id ely mab3oltly 3lashan yt3mlo promotion
{	// lazm 2a search 3la el list el awl for the the givin id to locate the mission 
	//step 1 find the mission in the missions list of mountinious
	Mission* m=new Mission('M',Event_day,ID,-1,-1,-1);
	Node  <Mission*>* toprom = new Node<Mission*>(m,ID);
	Mission* temp;
	while (Mountainous.dequeue(temp))
	{
		if (temp->getID() == m->getID())
		{
			//found the mission to be promoted 
			//n7otaha f node w n enque f el emergency ba2a
			Mission* t2 = toprom->getData();
			Mission* promoted = new Mission('E', t2->getED(), t2->getID(), t2->getTargetLoc(), t2->getMissionDur(), t2->getSignificance());
			int priority; //Priroity equation 
			Emergency.enqueue(&promoted,priority);
		}
	}
	
	

}