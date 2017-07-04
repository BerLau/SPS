#pragma once
#include "SProcess.h"
#include "InterruptRegister.h"
class SCPU
{
public:
	SCPU();
	~SCPU();
	int commandLen;
	int period;
	void run(SProcess& p);
	bool checkOut(InterruptRegister& resgiter);
};

