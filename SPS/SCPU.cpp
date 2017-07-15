#include "SCPU.h"



SCPU::SCPU()
{
}


SCPU::~SCPU()
{
}

void SCPU::run(SProcess & p, ResRepoistory& res, InterruptRegister& reg)
{
	reg.setRecord(p.doJob(res));
	if (blockingCheck(res)) {
		reg.setRecord(REVIVED);
	}
}

bool SCPU::checkOut(InterruptRegister& reg)
{
	return reg.hasRecord();
}

bool SCPU::blockingCheck(ResRepoistory& res)
{
	bool rs = false;
	auto itor = checkingList.begin();
	while (itor!=checkingList.end())
	{
		if (res.resList[*itor].status = FREE) {
			rs = true;
			checkingList.erase(itor);
		}
		else
		{
			itor++;
		}
	}
	return rs;
}
