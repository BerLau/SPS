#pragma once
#include <list>
#include "ResRepoistory.h"
#include "InterruptRegister.h"

enum TaskStatus {FRESH,WORKING,FINISHED};
struct Task
{
	int ResId;
	TaskStatus status;
};

class SProcess
{
public:
	SProcess();
	SProcess(int pri,int id);
	~SProcess();
	virtual ItrpType doJob(ResRepoistory& res);
	int p_id;
	int priority;
	std::list<Task> tasks;
private:
	bool getResource(ResRepoistory& repo, int r);
	void releaseRes(ResRepoistory& repo, int r);
};

