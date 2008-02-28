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
		{ SysVol_Delete },
		SysVol_Open,
		SysVol_Close,
		SysVol_IoControl,
		DrvObj_Seek,
		DrvObj_Read,
		DrvObj_Write,
		DrvObj_Flush,
	},
	VolumeObj_Shutdown,
	VolumeObj_MakeDir,
	VolumeObj_Remove,
};


HANDLE SysVol_Create(void)
{
	C_SYSVOL *self;
	
	/* メモリ確保 */
	if ( (self = (C_SYSVOL *)SysMem_Alloc(sizeof(C_SYSVOL))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	SysVol_Constructor(self, &SysVol_VolumeObjMethods);	
	
	return (HANDLE)self;	
}


/* end of file */
