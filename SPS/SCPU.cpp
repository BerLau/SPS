#include "SCPU.h"



SCPU::SCPU()
{
	commandLen=100;
	period=500;
}
SCPU::SCPU(int comm,int peri)
{
	commandLen = comm;
	period = peri;
}


SCPU::~SCPU()
{
}

void SCPU::run(SProcess & p, ResRepoistory& res, InterruptRegister& reg)
{
	reg.setRecord(p.doJob(res));
}

bool SCPU::checkOut(InterruptRegister& reg, ResRepoistory& res)
{
	if (res.BlockingCheck()) {
		reg.setRecord(REVIVED);
	}
	return reg.hasRecord();
}
