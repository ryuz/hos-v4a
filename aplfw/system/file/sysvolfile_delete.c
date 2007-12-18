
#include "sysvolfile_local.h"


void SysVolFile_Delete(HANDLE hFile)
{
	C_SYSVOLFILE *self;

	self = (C_SYSVOLFILE *)hFile;

	/* デストラクタ呼び出し */
	SysVolFile_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}

