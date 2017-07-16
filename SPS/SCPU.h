#pragma once
#include "SProcess.h"
#include "InterruptRegister.h"
#include <list>
class SCPU
{
public:
	SCPU();
	SCPU(int comm, int peri);
	~SCPU();
	int commandLen;
	int period;
	void run(SProcess& p, ResRepoistory& res, InterruptRegister& reg);
	bool checkOut(InterruptRegister& reg, ResRepoistory& res);
};

