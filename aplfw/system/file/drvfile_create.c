/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバファイルの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "drvfile_local.h"


const T_FILEOBJ_METHODS DrvFile_FileObjMethods =
{
	{ DrvFile_Delete },		/* デストラクタ */
	DrvFile_IoControl,		/* IoControl */
	DrvFile_Seek,			/* Seek */
	DrvFile_Read,			/* Read */
	DrvFile_Write,			/* Write */
	DrvFile_Flush,			/* Flush */
};


/** コンストラクタ */
void DrvFile_Create(C_DRVFILE *self, C_DRVOBJ *pDrvObj, int iMode, const T_FILEOBJ_METHODS *pMethods)
{
	/* 親クラスの初期化 */
	if ( pMethods == NULL )
	{
		pMethods = &DrvFile_FileObjMethods;
	}
	FileObj_Create(&self->FileObj, pMethods);
	
	/* メンバ初期化 */
	self->pDrvObj = pDrvObj;
}


/* end of file */
