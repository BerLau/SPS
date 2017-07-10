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
		if (item.priority == 0) {
			return;
		}
		if (item.priority != 2 && item.priority < 5) {
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
	for (int i = 1; i < 7; i++)
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
	ItrpType type = NORMAL;
	while (!queues.Queue_CREATING.empty)
	{
		SProcess& item = queues.Queue_CREATING.front();
		queues.Queue_READY[item.priority].push_back(item);
		queues.Queue_CREATING.pop_front();
		if (queues.Queue_RUNNING.front().priority > 2) {
			type = REALTIME;
		}
	}
	if (type == REALTIME) {
		onTimeOut(queues);
	}
}

void MasterProcess::onProcessBlocked(PQueues & queues)
{
	if (!queues.Queue_RUNNING.empty)
	{
		SProcess& item = queues.Queue_RUNNING.front();
		queues.Queue_BLOCKED[item.p_id] = item;
		queues.Queue_RUNNING.pop_front();
		onTimeOut(queues);
	}
}

void MasterProcess::onProcessRevived(PQueues & queues,int id)
{
	if (queues.Queue_BLOCKED.find(id) != queues.Queue_BLOCKED.end()) {
		SProcess item = queues.Queue_BLOCKED[id];
		queues.Queue_READY[item.priority].push_back(item);
		queues.Queue_BLOCKED.erase(id);
	}
}

void MasterProcess::onProcessTerminated(PQueues & queues)
{
	if (!queues.Queue_RUNNING.empty)
	{
		SProcess& item = queues.Queue_RUNNING.front();
		queues.Queue_FINISHED.push_back(item);
		queues.Queue_RUNNING.pop_front();
		onTimeOut(queues);
	}
}
