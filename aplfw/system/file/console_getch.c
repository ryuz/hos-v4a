#include "consoleobj.h"



FILE_ERR Console_GetCh(HANDLE hConsole)
{
	C_CONSOLEOBJ *self;

	self = (C_CONSOLEOBJ *)hConsole;

	if ( ConsoleObj_GetMethods(self)->pfncGetCh != NULL )
	{
		return ConsoleObj_GetMethods(self)->pfncGetCh(hConsole);
	}

	return FILE_ERR_NG;
}



