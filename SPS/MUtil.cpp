#include "MUtil.h"



MUtil::MUtil()
{
}


MUtil::~MUtil()
{
}

int MUtil::Type2Int(ItrpType type)
{
	switch (type)
	{
		case TIMEOUT:return 1;
		case CREATED:return 2;
		case BLOCKED:return 4;
		case TERMINATE:return 8;
		case REVIVED:return 16;
		case REALTIME:return 32;
		default: return 0;
	}
}

ItrpType MUtil::Int2Type(int i)
{
	switch (i)
	{
		case 1:return TIMEOUT;
		case 2:return CREATED;
		case 4:return BLOCKED;
		case 8:return TERMINATE;
		case 16:return REVIVED;
		case 32:return REALTIME;
		default:return NORMAL;
	}
}
