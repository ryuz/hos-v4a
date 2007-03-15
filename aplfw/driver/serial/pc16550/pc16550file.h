/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  pc16550file.h
 * @brief %jp{PC16550用デバイスドライバ用ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__pc16550file_h__
#define __HOS__pc16550file_h__


#include "pc16550drv.h"
#include "system/file/fileobj.h"


/* PC16550用ドライバ制御部 */
typedef struct c_pc16550file
{
	C_FILEOBJ		FileObj;		/* ファイルオブジェクトを継承 */

	C_PC16550DRV	*pPc16550Drv;	/* Pc16550Drvクラスの参照 */
} C_PC16550FILE;



#ifdef __cplusplus
extern "C" {
#endif

/* PC16550用デバイスドライバ */
FILE_ERR Pc16550File_Create(HANDLE hFile, void *pParam, int iMode);			/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550file_h__ */


/* end of file */
