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


/** バッファ内のデータの送信(省コピー) */
void StreamBuf_SendBuf(C_STREAMBUF *self, unsigned int uiSize)
{
	unsigned int uiNextTail;
	
	/* サイズチェック */
	if ( uiSize == 0 )
	{
		return;
	}

	/* 次のポインタ位置計算 */
	uiNextTail = self->uiTail + uiSize;
	if ( uiNextTail >= self->uiBufSize )
	{
		uiNextTail = 0;
	}
	self->uiTail = uiNextTail;
}


/* end of file */
