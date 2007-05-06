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


/* %jp{1文字送信} */
int SciHal_SendChar(C_SCIHAL *self, int c)
{
	/* 送信可能かチェック */
	if ( !(*SCIHAL_REG_SSR(self) & 0x80) )
	{
		return -1;
	}
	
	*SCIHAL_REG_TDR(self) = (unsigned char)c;
	
	*SCIHAL_REG_SSR(self) &= 0x7f;

	return (unsigned char)c;
}



/* end of file */
