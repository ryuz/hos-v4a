/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  volumeobj.h
 * @brief %jp{ボリュームオブジェクト基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "volumeobj_local.h"


/** コンストラクタ */
void VolumeObj_Constructor(C_VOLUMEOBJ *self, const T_VOLUMEOBJ_METHODS *pMethods)
{
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Constructor(&self->DrvObj, &pMethods->DrvObjMethods);
}


/* end of file */
