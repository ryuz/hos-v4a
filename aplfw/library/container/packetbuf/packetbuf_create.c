/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  packetbuf.h
 * @brief %jp{パケットデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "packetbuf_local.h"



/** コンストラクタ */
void PacketBuf_Create(C_PACKETBUF *self, unsigned int uiBufSize, void *pBuf)
{
	/* メンバ変数の初期化 */
	self->pubBuf        = (unsigned char *)pBuf;
	self->uiBufSize     = uiBufSize;
	self->uiReturnPoint = uiBufSize;
	self->uiHead        = 0;
	self->uiTail        = 0;
}


/* end of file */
