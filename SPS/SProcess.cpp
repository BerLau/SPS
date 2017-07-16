#include "SProcess.h"
#include "MUtil.h"
#include "IOResource.h"
#include "SharedResource.h"
#include <thread>
#include <Windows.h>



SProcess::SProcess()
{
}

SProcess::SProcess(int pri,int id)
{
	priority = pri;
	p_id = id;
	int len = MUtil::getRadom(5)+5;
	for (int i = 0; i < len; i++)
	{
		int res = MUtil::getRadom(5);//
		Task t = { res,FRESH };
		tasks.push_back(t);
	}
}


SProcess::~SProcess()
{

}

ItrpType SProcess::doJob(ResRepoistory& res)
{
	
	if (MUtil::getRadom(5) == 0) {
		if (tasks.empty()) {
			return TERMINATE;
		}
		else
		{
			switch (tasks.front().status)
			{
			case FRESH: {
				if (!getResource(res, tasks.front().ResId)) {
					res.checkingList.push_back(tasks.front().ResId);
					return BLOCKED;
				}
				else
				{
					tasks.front().status = WORKING;
				}
			}break;
			case WORKING: {
				if (MUtil::getRadom(5) == 0) {
					releaseRes(res, tasks.front().ResId);
					tasks.front().status = FINISHED;
				}
			}break;
			case FINISHED: {
				tasks.pop_front();
			}break;
			default:
				break;
			}
		}
	}

	return NORMAL;
}

bool SProcess::getResource(ResRepoistory& repo, int r)
{
	if (repo.getRes(r)) {
		return true;
	}
	else
	{
		return false;
	}
}

void SProcess::releaseRes(ResRepoistory & repo, int r)
{
	repo.releaseRes(r);
}
