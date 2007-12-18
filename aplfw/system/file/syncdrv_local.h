/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncdrv.h
 * @brief %jp{同期機能付きデバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncdrv_local_h__
#define __HOS__syncdrv_local_h__


#include "system/file/syncdrv.h"
#include "system/file/drvobj_local.h"


#define SYNCDRV_STATUS_WRITE		0x0001
#define SYNCDRV_STATUS_READ			0x0002
#define SYNCDRV_STATUS_IO			0x0004



#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR SyncDrv_Constructor(C_SYNCDRV *self, const T_DRVOBJ_METHODS *pMethods);	/**< コンストラクタ */
void     SyncDrv_Destructor(C_SYNCDRV *self);										/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
