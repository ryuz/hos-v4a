/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memdrv_local.h"


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS MemDrv_Methods = 
	{
		MemDrv_Delete,
		MemDrv_Open,
		MemDrv_Close,
		MemDrv_IoControl,
		MemDrv_Seek,
		MemDrv_Read,
		MemDrv_Write,
		MemDrv_Flush,
	};


/** コンストラクタ */
void MemDrv_Create(C_MEMDRV *self, void *pMemAddr, FILE_POS MemSize, FILE_POS IniSize, int iAttr)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Create(&self->DrvObj, &MemDrv_Methods);
	
	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	self->pubMemAddr = pMemAddr;	/* メモリの先頭アドレス */
	self->MemSize    = MemSize;		/* メモリサイズ */
	self->FileSize   = IniSize;		/* ファイルとしてのサイズ */
	self->iAttr      = iAttr;		/* 属性 */
	
	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create();
}


/* end of file */
