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


#include "sysvol_local.h"


/* コンストラクタ */
void SysVol_Constructor(C_SYSVOL *self, const T_VOLUMEOBJ_METHODS *pMethods)
{
/*	int i;	*/
	
	/* 親クラスコンストラクタ呼び出し */
	VolumeObj_Constructor(&self->VolumeObj, pMethods);	
	
	/* メンバ変数初期化 */
	Assoc_Constructor(&self->asDevice, SysMem_GetMemHeap());
}


/* end of file */
