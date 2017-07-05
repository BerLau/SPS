#pragma once
#include <list>
#include "ResRepoistory.h"
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
	bool taskStatus;
private:
	bool getResource(ResRepoistory& repo, int r_id, int length);
};

