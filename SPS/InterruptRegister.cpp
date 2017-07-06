#include "InterruptRegister.h"



InterruptRegister::InterruptRegister()
{
	recorder = 0;
}

bool InterruptRegister::hasRecord()
{
	return recorder;
}

void InterruptRegister::setRecord(ItrpType type)
{
	recorder |= MUtil::Type2Int(type);
}

void InterruptRegister::reset()
{
	recorder = 0;
}

void InterruptRegister::reset(ItrpType type)
{
	recorder ^= MUtil::Type2Int(type);
}

ItrpType InterruptRegister::getItrpType()
{
	int index = 16;
	while (index>0)
	{
		if (recorder&index) {
			break;
		}
		else
		{
			index /= 2;
		}
	}
	return MUtil::Int2Type(index);
}


InterruptRegister::~InterruptRegister()
{
}
