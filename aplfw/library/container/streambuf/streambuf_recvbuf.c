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


/** 受信したデータの入ったバッファの取得(省コピー) */
unsigned int StreamBuf_RecvBuf(C_STREAMBUF *self, void **ppBuf)
{
	unsigned int uiTail;
	
	*ppBuf = (void *)(self->pubBuf + self->uiHead);	/* 受信バッファ先頭番地の格納 */
	
	uiTail = self->uiTail;
	if ( uiTail < self->uiHead )	/* データがバッファ末尾で折り返されているか */
	{
		return self->uiBufSize - self->uiHead;		/* 折り返されていたらバッファ末尾まで */
	}
	else
	{
		return uiTail - self->uiHead;				/* 折り返されていなければデータ末尾まで */
	}
}


/* end of file */
