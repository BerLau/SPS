#pragma once
enum ItrpType
{
	TIMEOUT,
	CREATED,
	BLOCKED,
	FINISHED,
	REVIVED
};
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

