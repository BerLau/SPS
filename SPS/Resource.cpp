#include "Resource.h"



Resource::Resource()
{
	status = ResStatus::FREE;
}


Resource::~Resource()
{
}

bool Resource::get()
{
	if (status == ResStatus::FREE)
	{
		lock();
		return true;
	}
	else
	{
		return false;
	}
}

void Resource::release()
{
	if (status = ResStatus::LOCKED)
	{
		unlock();
	}
}

void Resource::lock()
{
	status = ResStatus::LOCKED;
}

void Resource::unlock()
{
	status = ResStatus::FREE;
}

