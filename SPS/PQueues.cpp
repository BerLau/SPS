#include "PQueues.h"
#include "LeisureProcess.h"


PQueues::PQueues()
{
	SProcess p = LeisureProcess();
	Queue_READY[6].push_back(p);
}


PQueues::~PQueues()
{
}
