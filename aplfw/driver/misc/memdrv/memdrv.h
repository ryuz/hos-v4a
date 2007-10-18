/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__memdrv_h__
#define __HOS__memdrv_h__


#include "system/sysapi/sysapi.h"
#include "system/file/drvobj.h"


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



#ifdef __cplusplus
extern "C" {
#endif

void MemDrv_Create(C_MEMDRV *self, void *pMemAddr, FILE_POS MemSize, FILE_POS IniSize, int iAttr);		/**< コンストラクタ */
void MemDrv_Delete(C_DRVOBJ *self);																		/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memdrv_h__ */


/* end of file */
