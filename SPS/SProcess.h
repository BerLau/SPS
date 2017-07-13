#pragma once
#include <list>
#include "ResRepoistory.h"
#include "InterruptRegister.h"

struct Task
{
	int ResId;
	bool IsFinished;
};

class SProcess
{
public:
	SProcess();
	SProcess(int p,int id);
	~SProcess();
	virtual ItrpType doJob(ResRepoistory& res);
	int p_id;
	int priority;
	std::list<Task> tasks;
private:
	bool getResource(ResRepoistory& repo, Task& r, int length);
	void releaseRes(ResRepoistory& repo, Task& r,int length);
};

