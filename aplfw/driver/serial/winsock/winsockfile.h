/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockfile.h
 * @brief 
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__winsockfile_h__
#define __HOS__winsockfile_h__


#include "winsockdrv.h"
#include "system/file/fileobj.h"


/* SCI用ドライバ制御部 */
typedef struct c_winsockfile
{
	C_FILEOBJ     FileObj;			/* ファイルオブジェクトを継承 */

	C_WINSOCKDRV  *pWinSockDrv;		/* SciDrvクラスの参照 */
} C_WINSOCKFILE;



#ifdef __cplusplus
extern "C" {
#endif

/* SCI用デバイスドライバ */
FILE_ERR WinSockFile_Create(HANDLE hFile, void *pParam, int iMode);			/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__winsockfile_h__ */


/* end of file */
