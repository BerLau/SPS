#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "MUtil.h"
#include "MasterProcess.h"
#include "InterruptRegister.h"
#include "ResRepoistory.h"
#include "PQueues.h"
#include "SCPU.h"

using namespace std;
int main() {
	MUtil::setSeed();
	static int id_seed = 1000;
	ResRepoistory resp = ResRepoistory();
	InterruptRegister reg = InterruptRegister();
	PQueues queues = PQueues();
	SCPU cpu = SCPU();
	MasterProcess mp = MasterProcess();
	SProcess p = SProcess(0, id_seed);
	id_seed++;
	queues.Queue_CREATING.push_back(p);
	for (int i = 0; i < 8; i++) {
		SProcess p = SProcess(1+MUtil::getRadom(6), id_seed);
		id_seed++;
		queues.Queue_CREATING.push_back(p);
	}
	mp.onNewProcess(queues);
	int runl = 0;
	while (true) {
		cpu.run(queues.Queue_RUNNING.front(), resp, reg);
		runl += cpu.commandLen;
		if (runl == cpu.period*((queues.Queue_RUNNING.front().priority + 1))) {
			reg.setRecord(TIMEOUT);
			runl = 0;
		}
		if (cpu.checkOut(reg,resp)) {
			while (reg.hasRecord()) {
				switch (reg.getItrpType())
				{
				case TIMEOUT: {
					mp.onTimeOut(queues); 
					reg.reset(TIMEOUT);
				} break;
				case CREATED: {
					mp.onNewProcess(queues);
					reg.reset(CREATED);
				} break;
				case BLOCKED: {
					mp.onProcessBlocked(queues);
					reg.reset(BLOCKED);
				} break;
				case TERMINATE: {
					mp.onProcessTerminated(queues);
					reg.reset(TERMINATE);
				} break;
				case REVIVED: {
					mp.onProcessRevived(queues,resp);
					reg.reset(REVIVED);
				} break;
				case REALTIME: {
					reg.reset(REALTIME);
				} break;
				default: break;
				}
			}
		}
		cout << queues.Queue_RUNNING.front().p_id << endl;
		Sleep(cpu.commandLen);
	}
	cin.get();
}
int log(string s) {
	ofstream fout;
	fout.open("D:\\debugLogs\\pss.log", ios::app);
	if (fout.is_open())
	{
		fout << s << endl;
		fout.close();
	}
	return 0;
}