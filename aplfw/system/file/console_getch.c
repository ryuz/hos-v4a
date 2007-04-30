
#include "console.h"


int Console_GetCh(HANDLE hFile)
{
	int c;

	if ( File_IoControl(hFile, FILE_IOCTL_CON_GETCH, &c, sizeof(c), NULL, 0) != FILE_ERR_OK )
	{
		return FILE_ERR_NG;
	}

	return c;
}



