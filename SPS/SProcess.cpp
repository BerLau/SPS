#include "SProcess.h"
#include "MUtil.h"
#include "IOResource.h"
#include "SharedResource.h"



SProcess::SProcess()
{
}

SProcess::SProcess(int p,int id)
{
	priority = p;
	p_id = p_id;
	int len = MUtil::getRadom(20)+5;
	for (int i = 0; i < len; i++)
	{
		int res = MUtil::getRadom(20);
		Task t = { res,false};
		tasks.push_back(t);
	}
}


SProcess::~SProcess()
{

}

ItrpType SProcess::doJob(ResRepoistory& res)
{
	
	if (MUtil::getRadom(20) == 0) {
		if (tasks.empty) {
			return FINISHED;
		}
		else
		{
			if (tasks.front().IsFinished) {
				tasks.pop_front();
			}
			if (!getResource(res, tasks.front(), MUtil::getRadom(10000) + 5000))
			{
				return BLOCKED;
			}
		}
	}

	return NORMAL;
}

bool SProcess::getResource(ResRepoistory& repo, Task& r, int length)
{
	return repo.getRes(r.ResId, length);
}

void SProcess::releaseRes(ResRepoistory & repo, Task & r)
{
}
