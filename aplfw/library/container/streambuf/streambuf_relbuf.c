/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streambuf.h
 * @brief %jp{ストリームデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streambuf_local.h"


/** 受信用バッファの解放(省コピー) */
void StreamBuf_RelBuf(C_STREAMBUF *self, unsigned int uiSize)
{
	unsigned int uiNextHead;

	/* データ先頭位置更新 */
	uiNextHead = self->uiHead + uiSize;
	if ( uiNextHead >= self->uiBufSize )
	{
		uiNextHead = 0;
	}
	self->uiHead = uiNextHead;
}


/* end of file */
