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
	switch (type)
	{
	case TIMEOUT:recorder |= 1;
		break;
	case CREATED:recorder |= 2;
		break;
	case BLOCKED:recorder |= 4;
		break;
	case FINISHED:recorder |= 8;
		break;
	case REVIVED:recorder |= 16;
		break;
	default:
		break;
	}
}

void InterruptRegister::reset()
{
	recorder = 0;
}

void InterruptRegister::reset(ItrpType type)
{
	switch (type)
	{
	case TIMEOUT:recorder ^= 1;
		break;
	case CREATED:recorder ^= 2;
		break;
	case BLOCKED:recorder ^= 4;
		break;
	case FINISHED:recorder ^= 8;
		break;
	case REVIVED:recorder ^= 16;
		break;
	default:
		break;
	}
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
	switch (index)
	{
	case 1:
		return ItrpType::TIMEOUT;
	case 2:
		return ItrpType::CREATED;
	case 4:
		return ItrpType::BLOCKED;
	case 8:
		return ItrpType::FINISHED;
	case 16:
		return ItrpType::REVIVED;
	default:
		break;//;
	}
}


InterruptRegister::~InterruptRegister()
{
}
