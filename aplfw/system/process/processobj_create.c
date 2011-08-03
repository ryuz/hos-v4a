/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processobj_create.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "process_local.h"



const T_OBJECT_METHODS ProcessObj_Methods =
	{
		"ProcessObj",
		ProcessObj_Delete,	/* デストラクタ */
		NULL,
	};


/* プロセス生成 */
HANDLE ProcessObj_Create(const T_PROCESS_CREATE_INF *pInf)
{
	C_PROCESSOBJ	*self;
	
	/* メモリ確保 */
	if ( (self = (C_PROCESSOBJ *)SysMem_Alloc(sizeof(C_PROCESSOBJ))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( ProcessObj_Constructor(self, &ProcessObj_Methods, pInf) != PROCESS_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}

	return (HANDLE)self;
}


/* end of file */
