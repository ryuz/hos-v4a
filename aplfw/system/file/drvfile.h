/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバファイルの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvfile_h__
#define __HOS__drvfile_h__


#include "system/file/drvobj.h"
#include "system/file/fileobj.h"


/* SCI用ドライバ制御部 */
typedef struct c_drvfile
{
	C_FILEOBJ FileObj;		/* ファイルオブジェクトを継承 */

	C_DRVOBJ  *pDrvObj;		/* ドライバクラスの参照 */
} C_DRVFILE;



#ifdef __cplusplus
extern "C" {
#endif

void DrvFile_Create(C_DRVFILE *self, C_DRVOBJ *pDrvObj, int iMode, const T_FILEOBJ_METHODS *pMethods);		/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__drvobj_h__ */


/* end of file */
