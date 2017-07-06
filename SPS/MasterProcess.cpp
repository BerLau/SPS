#include "MasterProcess.h"



MasterProcess::MasterProcess()
{
}


MasterProcess::~MasterProcess()
{
}

void MasterProcess::onTimeOut(PQueues & queues)
{
	if (!queues.Queue_RUNNING.empty) {
		SProcess& item = queues.Queue_RUNNING.front();
		if (item.priority != 0 && item.priority != 2 && item.priority < 5) {
			item.priority++;
		}
		queues.Queue_READY[item.priority].push_back(item);
		queues.Queue_RUNNING.pop_front();
	}
	if (!queues.Queue_READY[0].empty) {
		SProcess& item = queues.Queue_READY[0].front();
		queues.Queue_RUNNING.push_back(item);
		queues.Queue_READY[0].pop_front();
		return;
	}
	for (int i = 1; i < 3; i++)
	{
		if (!queues.Queue_READY[i].empty) {
			SProcess& item = queues.Queue_READY[i].front();
			queues.Queue_RUNNING.push_back(item);
			queues.Queue_READY[i].pop_front();
			return;
		}
	}

}

void MasterProcess::onNewProcess(PQueues & queues)
{
}

void MasterProcess::onProcessBlocked(PQueues & queues)
{
}

void MasterProcess::onProcessRevived(PQueues & queues)
{
}

void MasterProcess::onProcessTerminated(PQueues & queues)
{
}

void MasterProcess::onRealtimeProc(PQueues & queues)
{
}
