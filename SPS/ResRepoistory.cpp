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

bool ResRepoistory::getRes(int id,int length)
{
	return resList[id].get(length);
}
