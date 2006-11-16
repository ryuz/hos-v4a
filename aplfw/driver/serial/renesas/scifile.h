/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scifile.h
 * @brief %jp{SCI用デバイスドライバ用ファイルI/Fクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scifile_h__
#define __HOS__renesas_scifile_h__


#include "scidrv.h"
#include "system/file/fileobj.h"


/* SCI用ドライバ制御部 */
typedef struct c_scifile
{
	C_FILEOBJ FileObj;		/* ファイルオブジェクトを継承 */

	C_SCIDRV  *pSciDrv;		/* SciDrvクラスの参照 */
} C_SCIFILE;



#ifdef __cplusplus
extern "C" {
#endif

/* SCI用デバイスドライバ */
FILE_ERR SciFile_Create(HANDLE hFile, void *pParam);			/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scifile_h__ */


/* end of file */
