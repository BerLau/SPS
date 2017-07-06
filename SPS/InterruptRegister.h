#pragma once
#include "MUtil.h"
class InterruptRegister
{
public:
	InterruptRegister();
	bool hasRecord();
	void setRecord(ItrpType type);
	void reset();
	void reset(ItrpType type);
	ItrpType getItrpType();
	~InterruptRegister();
private:
	int recorder;
};

