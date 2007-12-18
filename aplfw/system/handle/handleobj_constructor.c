/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "handleobj_local.h"


/* コンストラクタ */
void HandleObj_Constructor(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods)
{
	/* 仮想関数テーブルの登録 */
	self->pMethods = pMethods;

	/* プロセスに紐付け(予定) */
}



/* end of file */
