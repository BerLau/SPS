#include "ResRepoistory.h"
#include "IOResource.h"
#include "SharedResource.h"



ResRepoistory::ResRepoistory()
{
	for (int i = 0; i<10; i++)
	{
		Resource r = IOResource();
		resList[i] = r;
	}
	for (int i = 10; i < 20; i++)
	{
		Resource r = SharedResource();
		resList[i] = r;
	}
}


ResRepoistory::~ResRepoistory()
{
}

bool ResRepoistory::getRes(int id)
{
	return resList[id].get();
}

void ResRepoistory::releaseRes(int id)
{
	resList[id].release();
}

bool ResRepoistory::BlockingCheck()
{
	bool rs = false;
	if (checkingList.empty()) {
		return false;
	}
	auto itor = checkingList.begin();
	while (itor != checkingList.end())
	{
		if (resList[*itor].status = FREE) {
			checkingList.erase(itor++);
			rs = true;
		}
		else
		{
			++itor;
		}
	}
	return rs;
}
