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

bool Resource::get(int length,bool& status)
{
	if (status == ResStatus::FREE)
	{
		lock();
		std::thread th_unlock(&Resource::release, this, length,status);
		th_unlock.detach();
		return true;
	}
	else
	{
		return false;
	}
}

void Resource::release(int length,bool& status)
{
	Sleep(length);
	if (status = ResStatus::LOCKED)
	{
		unlock();
		status = false;
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

