#pragma once
#include "SProcess.h"
#include "InterruptRegister.h"
#include <list>
class SCPU
{
public:
	SCPU();
	~SCPU();
	int commandLen;
	int period;
	void run(SProcess& p, ResRepoistory& res, InterruptRegister& reg);
	bool checkOut(InterruptRegister& reg);
private:
	bool blockingCheck(ResRepoistory& res);
	list<int> checkingList;
};

