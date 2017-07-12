#include "LeisureProcess.h"



LeisureProcess::LeisureProcess():SProcess(6,0)
{
}

ItrpType LeisureProcess::doJob(ResRepoistory& res)
{
	return NORMAL;
}


LeisureProcess::~LeisureProcess()
{
}
