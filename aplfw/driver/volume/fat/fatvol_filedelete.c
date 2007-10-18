
#include <stdio.h>
#include "fatvol_local.h"


void FatVol_FileDelete(C_FATVOL *self, HANDLE hFile)
{
	C_FATFILE *pFile;
	
	pFile = (C_FATFILE *)hFile;
	
	FileObj_Delete(pFile);
	SysMem_Free(pFile);
}


/* end of file */
