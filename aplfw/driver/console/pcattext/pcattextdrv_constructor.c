/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_constructor.c
 * @brief %jp{PC/AT text mode driver オブジェクト削除}%en{PC/AT text mode driver  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


/** %jp{仮想関数テーブル}%en{virtual functions table} */
const T_DRVOBJ_METHODS PcatTextDrv_Methods = 
	{
		{ PcatTextDrv_Delete },
		PcatTextDrv_Open,
		PcatTextDrv_Close,
		PcatTextDrv_IoControl,
		DrvObj_Seek,
		DrvObj_Read,
		PcatTextDrv_Write,
		DrvObj_Flush,
	};


/** コンストラクタ */
FILE_ERR PcatTextDrv_Constructor(C_PCATTEXTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, void *pVramBase)
{
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &PcatTextDrv_Methods;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Constructor(&self->DrvObj, pMethods);
	
	/* メンバ変数初期化 */
	self->pRegBase      = pRegBase;
	self->puhTextVram   = (volatile unsigned short *)pVramBase;
	
	self->iOpenCount    = 0;

	self->iScreenWidth  = 80;
	self->iScreenHeight = 25;

	self->ubCharAttr    = 0x07;
	self->iCursorX      = 0;
	self->iCursorY      = 0;
	
	
	PcatTextDrv_ClearScreen(self);
	PcatTextDrv_SetCursor(self, 0, 0);
	
	
	return FILE_ERR_OK;
}


/* end of file */
