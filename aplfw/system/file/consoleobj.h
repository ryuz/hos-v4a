/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  consoleobj.h
 * @brief %jp{コンソールオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__consoleobj_h__
#define __HOS__consoleobj_h__


#include "system/file/fileobj.h"
#include "console.h"


/* コンソールオブジェクト メソッドテーブル */
typedef struct t_consoleobj_methods
{
	T_FILEOBJ_METHODS FileObjMethods;				/* ファイルオブジェクトを継承 */
	FILE_ERR  (*pfncGetCh)(HANDLE hConsole);		/* １文字入力 */
} T_CONSOLEOBJ_METHODS;



/* コンソールオブジェクト */
typedef struct c_consoleobj
{
	C_FILEOBJ     FileObj;		/* ファイルオブジェクトを継承 */
} C_CONSOLEOBJ;



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR ConsoleObj_Create(HANDLE hCon, const T_CONSOLEOBJ_METHODS *pMethods);		/**< コンストラクタ */
#define  ConsoleObj_GetMethods(self)		((T_CONSOLEOBJ_METHODS *)FileObj_GetMethods(&(self)->FileObj))

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__consoleobj_h__ */


/* end of file */
