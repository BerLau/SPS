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
}

bool SProcess::getResource(int r_id)
{

}

void SProcess::releaseResource(int r_id)
{
}
