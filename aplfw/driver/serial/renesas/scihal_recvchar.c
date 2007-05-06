/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scihdl.c
 * @brief %jp{SCI用ハードウェアアクセス層}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scihal_local.h"



/* %jp{1文字受信} */
int SciHal_RecvChar(C_SCIHAL *self)
{
	unsigned char ssr;
	int c;
	
	ssr = *SCIHAL_REG_SSR(self);
	
	/* エラーチェック */
	if ( ssr & 0x38 )
	{
		*SCIHAL_REG_SSR(self) = (ssr & ~0x38);
		return -1;
	}
	
	/* 受信データチェック */
	if ( !(ssr & 0x40) )
	{
		return -1;
	}
	
	/* 受信 */
	c = *SCIHAL_REG_RDR(self);
	
	*SCIHAL_REG_SSR(self) &= ~0x40;
	
	return c;
}


/* end of file */
