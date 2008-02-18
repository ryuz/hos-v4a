/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile.h
 * @brief %jp{$OBJNAME_JP$ オブジェクト削除}%en{$OBJNAME_EN$  delete}
 *
 * $COPYRIGHT$
 */


#include "xxxxfile_local.h"


void XxxxFile_Delete(HANDLE hFile)
{
	C_XXXXFILE *self;
	
	self = (C_XXXXFILE *)hFile;
	
	/* デストラクタ */
	XxxxFile_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */
