#include "Resource.h"
#include <Windows.h>
#include <thread>


Resource::Resource()
{
	status = ResStatus::FREE;
}


Resource::~Resource()
{
}

bool Resource::get(int length)
{
	if (status == ResStatus::FREE)
	{
		lock();
		std::thread th_unlock(&Resource::release, this, length);
		th_unlock.detach();
		return true;
	}
	else
	{
		return false;
	}
}

void Resource::release(int length)
{
	Sleep(length);
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

