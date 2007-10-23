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


/* １キャラクタの送信 */
int StreamBuf_SendChar(C_STREAMBUF *self, int c)
{
	unsigned int uiNextTail;

	/* 次の位置を計算 */
	uiNextTail = self->uiTail + 1;
	if ( uiNextTail >= self->uiBufSize )
	{
		uiNextTail = 0;
	}

	/* バッファフルチェック */
	if ( uiNextTail == self->uiHead )
	{
		return -1;	/* 失敗 */
	}
	
	/* １キャラクタ送信 */
	c = (*(self->pubBuf + self->uiTail) = (unsigned char)c);
	self->uiTail = uiNextTail;

	return c;		/* 成功 */
}


/* end of file */
