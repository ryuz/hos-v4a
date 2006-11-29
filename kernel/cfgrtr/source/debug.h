

#ifndef __debug_h__
#define __debug_h__

#include "param.h"


class CDebug
{
public:
	static void PrintParam(CParamBlock *pParam, int iIndent);
};


#endif	// __debug_h__
