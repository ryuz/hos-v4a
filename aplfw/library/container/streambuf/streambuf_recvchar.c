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


/** １キャラクタの受信 */
int StreamBuf_RecvChar(C_STREAMBUF *self)
{
	unsigned int	uiNextHead;
	int				c;

	/* バッファエンプティ−チェック */
	if ( self->uiHead == self->uiTail )
	{
		return -1;	/* 失敗 */
	}

	/* １キャラクタ受信 */
	c = *(self->pubBuf + self->uiHead);

	/* 次の位置を計算 */
	uiNextHead = self->uiHead + 1;
	if ( uiNextHead >= self->uiBufSize )
	{
		uiNextHead = 0;
	}
	self->uiHead = uiNextHead;

	return c;	/* 成功 */
}


/* end of file */
