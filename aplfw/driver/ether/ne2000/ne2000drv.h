/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ne2000drv.c
 * @brief %jp{NE2000互換Ether用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ne2000drv_h__
#define __HOS__ne2000drv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncdrv.h"
#include "ne2000hal.h"


/* NE2000互換NIC制御ドライバクラス */
typedef struct c_ne2000drv
{
	C_SYNCDRV		SyncDrv;			/* キャラクタ型デバイスドライバを継承 */

	C_NE2000HAL		Ne2000Hal;
	int				iOpenCount;
	SYSEVT_HANDLE	hEvtSend;
	SYSEVT_HANDLE	hEvtRecv;
	SYSMTX_HANDLE	hMtx;
} C_NE2000DRV;


#ifdef __cplusplus
extern "C" {
#endif

void Ne2000Drv_Create(C_NE2000DRV *self, void *pRegAddr, int iIntNum);		/**< コンストラクタ */
void Ne2000Drv_Delete(C_DRVOBJ *pDrvObj);									/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ne2000drv_h__ */


/* end of file */
