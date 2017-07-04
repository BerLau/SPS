#pragma once
#include <iostream>
#include <time.h>
class MUtil
{
public:
	MUtil();
	~MUtil();
	static void setSeed() { srand((long)time(NULL)); };
	static int getRadom(int end) { return getRadom(0, end); };
	static int getRadom(int begin, int end) { if (begin < end) { return begin + rand() % (end - begin); } else { return 0; } };
};

