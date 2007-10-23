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



/** 受信したデータの入ったバッファの取得(省コピー) */
unsigned int PacketBuf_RecvBuf(C_PACKETBUF *self, void **ppBuf)
{
	unsigned int uiSize;
	
	if ( self->uiHead == self->uiTail )
	{
		return 0;	/* データなし */
	}

	/* データサイズ取得 */
	uiSize = *(unsigned int *)(self->pubBuf + self->uiHead);
	
	/* バッファ位置設定 */
	*ppBuf = (void *)(self->pubBuf + self->uiHead + sizeof(unsigned int));

	return uiSize;
}


/* end of file */
