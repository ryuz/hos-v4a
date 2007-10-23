/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  packetbuf.h
 * @brief %jp{パケットデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "packetbuf_local.h"



/** データの送信 */
unsigned int PacketBuf_SendData(C_PACKETBUF *self, const void *pData, unsigned int uiSize)
{
	void *pBuf;
	
	/* 送信バッファ取得 */
	if ( PacketBuf_GetBuf(self, &pBuf, uiSize) < uiSize )
	{
		return 0;
	}

	/* バッファにデータ書き込み */
	memcpy(pBuf, pData, uiSize);

	/* バッファ送信 */
	PacketBuf_SendBuf(self, uiSize);

	return uiSize;
}


/* end of file */
