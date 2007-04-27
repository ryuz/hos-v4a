
#include "system/file/consoleobj.h"
#include "vt100drv.h"


typedef struct c_vt100con
{
	C_CONSOLEOBJ	ConObj;

	C_VT100DRV      *pVt100Drv;
} C_VT100CON;

FILE_ERR Vt100Con_Create(HANDLE hFile, void *pParam, int iMode);