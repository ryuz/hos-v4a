/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volumeobj.h
 * @brief %jp{ボリュームオブジェクト基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "volumeobj.h"


void VolumeObj_Create(C_VOLUMEOBJ *self, const T_VOLUMEOBJ_METHODS *pVolumeObjMethods)
{
	/* 親クラスコンストラクタ */
	DrvObj_Create(&self->DrvObj, &pVolumeObjMethods->DrvObjMethods);
}


/* end of file */
