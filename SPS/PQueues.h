#pragma once
#include <list>
#include "SProcess.h"
using namespace std;
class PQueues
{
public:
	PQueues();
	~PQueues();
	list<SProcess> Queue_FINISHED;
	list<SProcess> Queue_BLOCKED;
	list<SProcess> Queue_CREATING;
	list<SProcess> Queue_RUNNING;
	list<SProcess> Queue_READY[7];
};

