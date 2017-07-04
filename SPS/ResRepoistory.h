#pragma once
#include <map>
#include "Resource.h"
using namespace std;
class ResRepoistory
{
public:
	ResRepoistory();
	~ResRepoistory();
	static map<int, Resource> resList;
	bool getRes(int id);
	void releaseRes(int id);
};

