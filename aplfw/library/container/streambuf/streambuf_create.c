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


/** コンストラクタ */
void StreamBuf_Create(C_STREAMBUF *self, unsigned int uiBufSize, void *pBuf)
{
	/* クラスメンバの初期化 */
	self->uiBufSize = uiBufSize;
	self->pubBuf    = (unsigned char *)pBuf;
	self->uiHead    = 0;
	self->uiTail    = 0;
}


/* end of file */
