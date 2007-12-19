/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncdrv.h
 * @brief %jp{同期機能付きデバイスドライバの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__syncdrv_h__
#define __HOS__syncdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/syncfile.h"
#include "system/file/drvobj.h"


/* デバイスドライバオブジェクト基本クラス(抽象クラス) */
typedef struct c_syncdrv
{
	C_DRVOBJ		DrvObj;				/**< DrvObjクラスを継承 */

	C_SYNCFILE		*pFileHead;			/**< ファイルオブジェクトの連結ポインタ */
	
	SYSEVT_HANDLE	hMtx;				/**< 排他制御ミューテックス */
	
	int				iSyncFactorNum;		/**< 同期要因の数 */
	C_SYNCFILE		**ppBusyFile;		/**< 処理中ファイルオブジェクト */
} C_SYNCDRV;



#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__syncdrv_h__ */


/* end of file */
