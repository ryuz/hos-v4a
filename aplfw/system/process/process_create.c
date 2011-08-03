/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "process_local.h"


static void Process_Entry(void);
static void Process_SignalHandler(void);


const T_OBJECT_METHODS ProcessPtr_Methods =
	{
		"ProcessPtr",
		ProcessPtr_Delete,	/* デストラクタ */
		NULL,
	};


/* プロセス生成 */
HANDLE Process_Create(const T_PROCESS_CREATE_INF *pInf)
{
	C_PROCESSOBJ	*pObj;
	C_PROCESSPTR	*pPtr;

	/* 本体生成 */
	if ( (pObj = (C_PROCESSOBJ *)ProcessObj_Create(pInf)) == NULL )
	{
		return HANDLE_NULL;
	}

	/* ポインタ生成 */
	if ( (pPtr = (C_PROCESSPTR *)ProcessPtr_Create(pObj)) == NULL )
	{
		ProcessObj_Delete((HANDLE)pObj);
		return HANDLE_NULL;
	}
	
	return (HANDLE)pPtr;
}


/* end of file */
