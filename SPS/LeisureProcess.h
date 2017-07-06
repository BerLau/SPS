#pragma once
#include "SProcess.h"
class LeisureProcess :
	public SProcess
{
public:
	LeisureProcess();
	virtual ItrpType doJob(ResRepoistory& res);
	~LeisureProcess();
};

