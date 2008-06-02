/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv_local.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__memdrv_local_h__
#define __HOS__memdrv_local_h__


#include "memdrv.h"
#include "system/file/drvobj_local.h"
#include "system/sysapi/sysapi.h"


/* ドライバ制御部 */
typedef struct c_memdrv
{
	C_DRVOBJ		DrvObj;			/* デバイスドライバを継承 */

	int				iOpenCount;		/* オープンカウンタ */
	unsigned char	*pubMemAddr;	/* メモリの先頭アドレス */
	FILE_POS		MemSize;		/* メモリサイズ */
	FILE_POS		FileSize;		/* ファイルとしてのサイズ */
	int				iAttr;			/* 属性 */
	
	SYSMTX_HANDLE	hMtx;			/* 排他制御用ミューテックス */
} C_MEMDRV;


#include "memfile_local.h"


#ifdef __cplusplus
extern "C" {
#endif

void      MemDrv_Constructor(C_MEMDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pMemAddr, FILE_POS MemSize, FILE_POS IniSize, int iAttr);	/** コンストラクタ */
void      MemDrv_Destructor(C_MEMDRV *self);																									/** デストラクタ */

HANDLE    MemDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode);
void      MemDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  MemDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  MemDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE MemDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE MemDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  MemDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj);
FILE_ERR  MemDrv_GetInformation(C_DRVOBJ *pDrvObj, char *pszInformation, int iLen);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memdrv_local_h__ */


/* end of file */
