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
	virtual void release();
protected:
	void lock();
	void unlock();
};

