/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv.h
 * @brief %jp{Jelly I2C デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__jellyi2cdrv_local_h__
#define __HOS__jellyi2cdrv_local_h__


#include "jellyi2cdrv.h"
#include "driver/i2c/i2c/i2cdrv_local.h"
#include "system/file/syncdrv_local.h"


#define JELLYI2CDRV_REG_STATUS		0x00

#define JELLYI2CDRV_REG_I2C_STATUS		0x00
#define JELLYI2CDRV_REG_I2C_CONTROL		0x04
#define JELLYI2CDRV_REG_I2C_SEND		0x08
#define JELLYI2CDRV_REG_I2C_RECV		0x0c
#define JELLYI2CDRV_REG_I2C_DIVIDER		0x10

#define JELLYI2CDRV_CONTROL_START		0x01
#define JELLYI2CDRV_CONTROL_STOP		0x02
#define JELLYI2CDRV_CONTROL_ACK			0x04
#define JELLYI2CDRV_CONTROL_NAK			0x08
#define JELLYI2CDRV_CONTROL_RECV		0x10

#define JELLYI2CDRV_REG_WRITE(self, offset, val)	SysIo_OutPortW(((char *)(self)->pRegBase + (offset)), val)
#define JELLYI2CDRV_REG_READ(self, offset)			SysIo_InPortW(((char *)(self)->pRegBase + (offset)))

#define JELLYI2CDRV_WAIT_BUSY(self)		do { while (JELLYI2CDRV_REG_READ((self), JELLYI2CDRV_REG_I2C_STATUS) & 0x01) ; } while(0)


/* I2Cドライバ制御部 */
typedef struct c_jellyi2cdrv
{
	C_SYNCDRV		SyncDrv;		/* キャラクタ型デバイスドライバを継承 */

	void			*pRegBase;		/* レジスタベースアドレス */
	unsigned long	ulBaseClock;	/* ベースクロック */
	int				iIntNum;		/* 割込み番号 */
	
	int				iOpenCount;		/* オープンカウンタ */
} C_JELLYI2CDRV;




#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  JellyI2cDrv_Constructor(C_JELLYI2CDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, unsigned long ulBaseClock);	/**< コンストラクタ */
void      JellyI2cDrv_Destructor(C_JELLYI2CDRV *self);																					/**< デストラクタ */

HANDLE    JellyI2cDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      JellyI2cDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  JellyI2cDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);

FILE_ERR  JellyI2cDrv_Access(C_JELLYI2CDRV *self, const T_I2CDRV_ACCESS *pAccess);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__jellyi2cdrv_local_h__ */


/* end of file */
