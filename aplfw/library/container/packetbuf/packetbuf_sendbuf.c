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



/** バッファ内のデータの送信(省コピー) */
void PacketBuf_SendBuf(C_PACKETBUF *self, unsigned int uiSize)
{
	/* サイズの格納 */
	*(unsigned int *)(self->pubBuf + self->uiTail) = uiSize;
	
	/* 末尾位置の更新 */
	self->uiTail += PACKETBUF_DATASIZE(uiSize);
}


/* end of file */
