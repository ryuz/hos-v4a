/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "system/sysapi/sysapi.h"
#include "library/container/mempol/mempol.h"
#include "kernel.h"


SYSMTX_HANDLE System_hMtx;
SYSMTX_HANDLE SysMem_hMtx;
C_MEMPOL      SysMem_MemPol;


/* システムの初期化 */
void System_Initialize(void *pMem, MEMSIZE Size)
{
	/* システムロックの作成 */
	System_hMtx = SysMtx_Create();					/* システムロック用ミューテックス生成 */

	/* メモリ管理の初期化 */
	SysMem_hMtx = SysMtx_Create();					/* メモリ管理用排他制御用ミューテックス生成 */
	MemPol_Create(&SysMem_MemPol, pMem, Size);		/* メモリプール生成 */
}


/* end of file */
