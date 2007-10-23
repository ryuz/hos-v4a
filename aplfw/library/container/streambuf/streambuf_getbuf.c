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



/** 送信用バッファの取得(省コピー) */
unsigned int StreamBuf_GetBuf(C_STREAMBUF *self, void **ppBuf)
{
	unsigned int uiHead;

	*ppBuf = (void *)(self->pubBuf + self->uiTail);	/* 送信バッファ先頭番地の格納 */

	uiHead = self->uiHead;
	if ( uiHead > self->uiTail )	/* データがバッファ末尾で折り返されているか */
	{
		return uiHead - self->uiTail - 1;
	}
	else
	{
		if ( uiHead == 0 )	/* バッファ先頭にデータがあるか */
		{
			return self->uiBufSize - self->uiTail - 1;		/* 先頭にデータがあるなら1バイト開ける */
		}
		else
		{
			return self->uiBufSize - self->uiTail;
		}
	}
}



/* end of file */
