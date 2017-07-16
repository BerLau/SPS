#pragma once
#include <map>
#include <list>
#include "Resource.h"
using namespace std;
class ResRepoistory
{
public:
	ResRepoistory();
	~ResRepoistory();
	map<int, Resource> resList;
	bool getRes(int id);
	void releaseRes(int id);
	bool BlockingCheck();
	list<int> checkingList;
};

