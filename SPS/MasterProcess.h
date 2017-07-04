#pragma once
#include "PQueues.h"
class MasterProcess
{
public:
	MasterProcess();
	~MasterProcess();
	void onTimeOut(PQueues& queues);
	void onNewProcess(PQueues& queues);
	void onProcessBlocked(PQueues& queues);
	void onProcessRevived(PQueues& queues);
	void onProcessTerminated(PQueues& queues);
	void onRealtimeProc(PQueues& queues);
};

