#include "Cancellation.h"

CancellationEvent::CancellationEvent(int ED, int i) : Event(ED)
{
	id = i;
}

void CancellationEvent::execute(MarsStation* mStation)
{
	Mission_Mountainous m(id, 0, 0, 0, 0, 0);
	int indexofmission = mStation->IndexOfMountainousMission(m);
	if (indexofmission != 1)
	{
		mStation->removeMountainousMission(indexofmission);
	}
}

CancellationEvent::~CancellationEvent()
{
}