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
	virtual bool get(int length);
protected:
	virtual void release(int length);
	void lock();
	void unlock();
};

