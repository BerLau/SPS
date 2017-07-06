#pragma once
#include <list>
#include "ResRepoistory.h"
#include "InterruptRegister.h"
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
	virtual ItrpType doJob(ResRepoistory& res);
	int priority;
	list<Task> tasks;
private:
	bool getResource(ResRepoistory& repo, Task& r, int length);
};

