/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  confile.h
 * @brief コンソールもどき
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__confile_h__
#define __HOS__confile_h__


#include "system/file/fileobj.h"


/* SCI用ドライバ制御部 */
typedef struct c_consolefile
{
	C_FILEOBJ     FileObj;		/* ファイルオブジェクトを継承 */

	HANDLE        hTty;			/* ターミナル */
} C_CONSOLEFILE;



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR ConsoleFile_Create(HANDLE hFile, void *pParam, const char *pszName, int iMode);			/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__winsockfile_h__ */


/* end of file */
