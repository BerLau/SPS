#pragma once
#include <map>
#include "Resource.h"
using namespace std;
class ResRepoistory
{
public:
	ResRepoistory();
	~ResRepoistory();
	map<int, Resource> resList;
	bool getRes(int id,int length);
};

