/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fileobj.h"


static const T_FILEOBJ_METHODS FileObj_FileObjMethods =
	{
		{File_Close},	/* デストラクタ */
	};


void FileObj_Create(C_FILEOBJ *self, C_DRVOBJ *pDrvObj, const T_FILEOBJ_METHODS *pMethods)
{
	if ( pMethods == NULL )	/* オーバーライド無しなら */
	{
		pMethods = &FileObj_FileObjMethods;
	}

	/* 親クラスコンストラクタ */
	HandleObj_Create(&self->HandleObj, &pMethods->HandlObjMethods);
	
	self->pDrvObj = pDrvObj;
}


/* end of file */
