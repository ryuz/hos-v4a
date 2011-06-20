/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_local.h
 * @brief %jp{XILINX UART driver ローカルヘッダファイル}%en{XILINX UART driver private header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__xilinxuartdrv_local_h__
#define __HOS__xilinxuartdrv_local_h__


#include "xilinxuartdrv.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"



/** %jp{ドライバクラス}%en{Device driver class} */
typedef struct c_xilinxuartdrv
{
	C_SYNCDRV		SyncDrv;		/**< %jp{同期機能付きデバイスドライバを継承} */

	void			*pRegBase;		/**< %jp{レジスタベースアドレス} */
	int				iIntNum;		/**< %jp{割込み番号} */
	SYSISR_HANDLE	hIsr;			/**< %jp{割込みサービスルーチンハンドル} */
	
	int				iOpenCount;		/**< %jp{オープンカウンタ} */
	
	C_STREAMBUF		StmBufRecv;		/**< %jp{受信バッファ} */
} C_XILINXUARTDRV;


#define XILINXUARTDRV_REG_RX			0x00
#define XILINXUARTDRV_REG_TX			0x04
#define XILINXUARTDRV_REG_STAT			0x08
#define XILINXUARTDRV_REG_CTRL			0x0c

#define XILINXUARTDRV_REG_WRITE(self, offset, val)		SysIo_OutPortW(((char *)(self)->pRegBase + (offset)), val)
#define XILINXUARTDRV_REG_READ(self, offset)			SysIo_InPortW(((char *)(self)->pRegBase + (offset)))



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  XilinxUartDrv_Constructor(C_XILINXUARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, int iBufSize);
																															/**< コンストラクタ */
void      XilinxUartDrv_Destructor(C_XILINXUARTDRV *self);																	/**< デストラクタ */

HANDLE    XilinxUartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      XilinxUartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  XilinxUartDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  XilinxUartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE XilinxUartDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE XilinxUartDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  XilinxUartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      XilinxUartDrv_Isr(VPARAM Param);			/**< %jp{割込み処理} */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__xilinxuartdrv_local_h__ */


/* end of file */
