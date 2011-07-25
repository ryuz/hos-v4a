/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processhandle.h
 * @brief %jp{プロセスハンドル}
 *
 * %jp{プロセスハンドル}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__processhandle_h__
#define __HOS__processhandle_h__


#include "system/handle/handleobj.h"



/* ファイルオブジェクトクラス基本メソッドテーブル */
typedef struct t_processhandle_methods
{
	T_OBJECT_METHODS	HandlObjMethods;	/* ハンドルオブジェクトを継承 */
} T_PROCESSHANDLE_METHODS;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_processhandle
{
	C_HANDLEOBJ			HandleObj;			/* ハンドルオブジェクトを継承 */
	
	struct c_process	*pProcess;			/* プロセス本体への参照 */
} C_PROCESSHANDLE;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE     ProcessHandle_Create(struct c_process *pProcess);
void       ProcessHandle_Delete(HANDLE Handle);
C_PROCESS *ProcessHandle_GetProcess(HANDLE Handle);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__processhandle_h__ */


/* end of file */
