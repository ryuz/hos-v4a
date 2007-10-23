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


/* 受信用バッファの解放(省コピー) */
void PacketBuf_RelBuf(C_PACKETBUF *self)
{
	unsigned int uiSize;
	unsigned int uiNextHead;
	
	/* データサイズ取得 */
	uiSize = *(unsigned int *)(self->pubBuf + self->uiHead);
	uiSize = PACKETBUF_DATASIZE(uiSize) + sizeof(unsigned int);
	
	/* 先頭位置更新 */
	uiNextHead = self->uiHead + uiSize;
	if ( self->uiTail < self->uiHead && uiNextHead >= self->uiReturnPoint )
	{
		uiNextHead = 0;
	}
	self->uiHead = uiNextHead;
}


/* end of file */
