#include <stdio.h>
#include "system/sysapi/sysapi.h"
#include "fatfile.h"
#include "fatvol_local.h"


HANDLE FatVol_CreateFile(
		C_FATVOL    *self,
		FATVOL_UINT uiCluster,
		HANDLE      hDir,
		int         iDirEntry,
		int         iMode)
{
	C_FATFILE *pFatFile;
	
	/* オブジェクトを生成 */
	pFatFile = (C_FATFILE *)SysMem_Alloc(sizeof(C_FATFILE));
	if ( pFatFile == NULL )
	{
		return HANDLE_NULL;
	}
	FatFile_Create(pFatFile, self, uiCluster, hDir, iDirEntry, iMode);
	
	return (HANDLE)pFatFile;
}


/* end of file */
