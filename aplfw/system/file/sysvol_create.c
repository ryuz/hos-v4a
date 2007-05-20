/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysvol.h
 * @brief %jp{システムボリューム}
 *
 *  %jp{ルートディレクトリや /dev ディレクトリなど、システム上の仮想ボリュームを管理}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include "sysvol_local.h"


const T_VOLUMEOBJ_METHODS SysVol_VolumeObjMethods =
{
	{
		SysVol_Delete,
		SysVol_Open,
		SysVol_Close,
		SysVol_IoControl,
		DrvObj_Seek,
		DrvObj_Read,
		DrvObj_Write,
		DrvObj_Flush,
	},
	VolumeObj_MakeDir,
	VolumeObj_Remove,
};


void SysVol_Create(C_SYSVOL *self)
{
	int i;
	
	/* 親クラスコンストラクタ呼び出し */
	VolumeObj_Create(&self->VolumeObj, &SysVol_VolumeObjMethods);	
	
	/* 初期化 */
	for ( i = 0; i < DEVVOL_MAX_DEVICE; i++ )
	{
		self->DevTable[i].pDrvObj = NULL;
	}
}


