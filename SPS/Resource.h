#pragma once
enum ResStatus
{
	WAITING,
	LOCKED,
	FREE
};
class Resource
{
public:
	Resource();
	~Resource();
	ResStatus status;
	virtual bool get(int length ,bool& status);
protected:
	virtual void release(int length,bool& status);
	void lock();
	void unlock();
};

