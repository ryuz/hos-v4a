/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fileobj_local.h"



static const T_FILEOBJ_METHODS FileObj_FileObjMethods =
	{
		{File_Close},	/* デストラクタ */
	};


HANDLE FileObj_Create(struct c_drvobj *pDrvObj, int iMode)
{
	C_FILEOBJ *self;
	
	/* メモリ確保 */
	if ( (self = (C_FILEOBJ *)SysMem_Alloc(sizeof(C_FILEOBJ))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	FileObj_Constructor(self, &FileObj_FileObjMethods, pDrvObj, iMode);
	
	return (HANDLE)self;
}


/* end of file */
