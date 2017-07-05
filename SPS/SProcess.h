#pragma once
#include <list>
#include "ResRepoistory.h"
using namespace std;

struct Task
{
	int ResId;
	bool IsFinished;
};

class SProcess
{
public:
	SProcess();
	SProcess(int p);
	~SProcess();
	virtual void doJob();
	int priority;
	list<Task> tasks;
private:
	bool getResource(ResRepoistory& repo, int r_id, int length);
};

