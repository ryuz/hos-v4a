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
#include "sysvolfile_local.h"


/* コンストラクタ */
void SysVolFile_Constructor(C_SYSVOLFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_sysvol *pSysVol, int iMode)
{
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Constructor(&self->FileObj, pMethods, &pSysVol->VolumeObj.DrvObj, iMode);
	
	/* メンバ変数初期化 */
	self->posRead = ASSOC_POS_NULL;
}



/* end of file */
