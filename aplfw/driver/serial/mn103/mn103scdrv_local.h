/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_local.h
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__mn103scdrv_local_h__
#define __HOS__mn103scdrv_local_h__


#include "mn103scdrv.h"
#include "system/file/syncdrv_local.h"
#include "system/sysapi/sysapi.h"


#define MN103SC_RB			0x04		/* シリアル受信レジスタ */
#define MN103SC_TB			0x0c		/* シリアル送信レジスタ */
#define MN103SC_CTR			0x00		/* シリアル制御レジスタ */
#define MN103SC_STR			0x09		/* シリアルステータスレジスタ */

#define MN103SC_READ_RB(self)			SysIo_InPortB(((char *)(self)->pRegBase + (MN103SC_RB)))

#define MN103SC_WRITE_TB(self, val)		SysIo_OutPortB(((char *)(self)->pRegBase + (MN103SC_TB)), val)

#define MN103SC_WRITE_CTR(self, val)	SysIo_OutPortH(((char *)(self)->pRegBase + (MN103SC_CTR)), val)
#define MN103SC_READ_CTR(self)			SysIo_InPortH(((char *)(self)->pRegBase + (MN103SC_CTR)))

#define MN103SC_READ_STR(self)			SysIo_InPortB(((char *)(self)->pRegBase + (MN103SC_STR)))



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  Mn103ScDrv_Constructor(C_MN103SCDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize);	/**< コンストラクタ */
void      Mn103ScDrv_Destructor(C_MN103SCDRV *self);																								/**< デストラクタ */

HANDLE    Mn103ScDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      Mn103ScDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  Mn103ScDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Mn103ScDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Mn103ScDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Mn103ScDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Mn103ScDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);

void      Mn103ScDrv_IsrTx(VPARAM Param);			/* 送信割込み処理 */
void      Mn103ScDrv_IsrRx(VPARAM Param);			/* 受信割込み処理 */


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__armuartdrv_h__ */


/* end of file */
