#include "SProcess.h"
#include "MUtil.h"
#include "IOResource.h"
#include "SharedResource.h"



SProcess::SProcess()
{
}

SProcess::SProcess(int p)
{
	priority = p;
	int len = MUtil::getRadom(50);
	for (int i = 0; i < len; i++)
	{
		int t = MUtil::getRadom(20);
		tasks.push_back(t);
	}
}


SProcess::~SProcess()
{

}

void SProcess::doJob()
{
	if (taskStatus) {
		if()
	}
	else
	{
		tasks.pop_front();
		if (MUtil::getRadom(20) == 0) {

		}
	}
	
}

bool SProcess::getResource(ResRepoistory& repo, int r_id, int length)
{
	return repo.getRes(r_id,length,taskStatus);
}
