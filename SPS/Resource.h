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
	virtual bool get();
protected:
	virtual void release();
	void lock();
	void unlock();
};

