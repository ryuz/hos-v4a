/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "file_local.h"



static const T_FILEOBJ_METHODS FilePtr_FilePtrMethods =
	{
		{
			"FilePtr",
			File_Close
		},	/* デストラクタ */
	};


HANDLE FilePtr_Create(struct c_fileobj *pFileObj, int iMode)
{
	C_FILEPTR *self;
	
	/* メモリ確保 */
	if ( (self = (C_FILEPTR *)SysMem_Alloc(sizeof(C_FILEPTR))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	FilePtr_Constructor(self, &FilePtr_FilePtrMethods, pFileObj, iMode);
	
	return (HANDLE)self;
}


/* end of file */
