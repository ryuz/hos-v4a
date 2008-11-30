/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_local.h
 * @brief %jp{JellyUart ローカルヘッダファイル}%en{JellyUart private header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__jellyuartdrv_local_h__
#define __HOS__jellyuartdrv_local_h__


#include "jellyuartdrv.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"


#define JELLYUART_DATA				0x00		/* Mode Register */
#define JELLYUART_STATUS			0x04		/* Control Register */


#define JELLYUART_REG_WRITE(self, offset, val)		SysIo_OutPortW(((char *)(self)->pRegBase + (offset)), val)
#define JELLYUART_REG_READ(self, offset)			SysIo_InPortW(((char *)(self)->pRegBase + (offset)))



/** %jp{ドライバクラス}%en{Device driver class} */
typedef struct c_jellyuartdrv
{
	C_SYNCDRV		SyncDrv;		/**< %jp{同期機能付きデバイスドライバを継承} */

	void			*pRegBase;		/**< %jp{レジスタベースアドレス} */
	unsigned long	ulBaseClock;	/**< %jp{ベースクロック} */
	int				iIntNumRx;		/**< %jp{割込み番号} */
	int				iIntNumTx;		/**< %jp{割込み番号} */
	SYSISR_HANDLE	hIsrRx;			/**< %jp{割込みサービスルーチンハンドル} */
	SYSISR_HANDLE	hIsrTx;			/**< %jp{割込みサービスルーチンハンドル} */

	int				iOpenCount;		/**< %jp{オープンカウンタ} */
	
	C_STREAMBUF		StmBufRecv;		/**< %jp{受信バッファ} */
} C_JELLYUARTDRV;




#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  JellyUartDrv_Constructor(C_JELLYUARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize);
																															/**< コンストラクタ */
void      JellyUartDrv_Destructor(C_JELLYUARTDRV *self);																	/**< デストラクタ */

HANDLE    JellyUartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      JellyUartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  JellyUartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  JellyUartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE JellyUartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE JellyUartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  JellyUartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      JellyUartDrv_IsrRx(VPARAM Param);			/**< %jp{割込み処理} */
void      JellyUartDrv_IsrTx(VPARAM Param);			/**< %jp{割込み処理} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__jellyuartdrv_local_h__ */


/* end of file */
