#pragma once
#include <list>
#include "Resource.h"
using namespace std;
class SProcess
{
public:
	SProcess();
	SProcess(int p);
	~SProcess();
	virtual void doJob();
	int priority;
	list<int> tasks;
private:
	bool getResource(int r_id);
	void releaseResource(int r_id);
};

