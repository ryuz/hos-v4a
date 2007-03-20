/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{ADuC7000シリーズ用割込みコントローラ操作}%en{ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"
#include "aduc7000.h"


/* FIQ割り込み処理開始 */
void _kernel_arm_fiq(void)
{
	INTNO intno;
	UW    fiqsta;
	
	fiqsta = FIQSTA;
	
	/* 割り込み番号取得 */
	for ( intno = 0; intno <= 23; intno++ )
	{
		if ( fiqsta & 1 )
		{
			/* 割込みサービスルーチン呼び出し */
			_kernel_exe_isr(intno);
		}
		
		fiqsta >>= 1;
	}
}



/* end of file */
