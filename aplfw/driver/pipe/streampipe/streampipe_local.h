/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe_local.h
 * @brief %jp{ストリームパイプ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__streampipe_local_h__
#define __HOS__streampipe_local_h__


#include "streampipe.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"


/* ストリームパイプクラス */
typedef struct c_streampipe
{
	C_SYNCDRV		SyncDrv;		/**< 同期機能付きデバイスドライバを継承 */

	int				iOpenCount;		/**< オープンカウンタ */

	C_STREAMBUF		StreamBuf;		/**< バッファ */
} C_STREAMPIPE;


#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  StreamPipe_Constructor(C_STREAMPIPE *self, const T_DRVOBJ_METHODS *pMethods, int iBufSize);	/**< コンストラクタ */
void      StreamPipe_Destructor(C_STREAMPIPE *self);													/**< デストラクタ */

HANDLE    StreamPipe_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      StreamPipe_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  StreamPipe_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  StreamPipe_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE StreamPipe_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE StreamPipe_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  StreamPipe_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__pc16550drv_h__ */


/* end of file */
