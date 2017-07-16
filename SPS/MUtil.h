#pragma once
#include <iostream>
#include <time.h>
enum ItrpType
{
	NORMAL,
	TIMEOUT,
	CREATED,
	BLOCKED,
	TERMINATE,
	REVIVED,
	REALTIME
};
class MUtil
{
public:
	MUtil();
	~MUtil();
	static void setSeed() { srand((long)time(NULL)); };
	static int getRadom(int end) { return getRadom(0, end); };
	static int getRadom(int begin, int end) {return begin<end?(begin+rand()%(end-begin)):0;}
	static int Type2Int(ItrpType type);
	static ItrpType Int2Type(int i);
};

