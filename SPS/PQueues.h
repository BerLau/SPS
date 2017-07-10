#pragma once
#include <list>
#include <map>
#include "SProcess.h"
using namespace std;
class PQueues
{
public:
	PQueues();
	~PQueues();
	list<SProcess> Queue_FINISHED;
	map<int,SProcess> Queue_BLOCKED;
	list<SProcess> Queue_CREATING;
	list<SProcess> Queue_RUNNING;
	list<SProcess> Queue_READY[7];
};

