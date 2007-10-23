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



/** データの受信 */
unsigned int PacketBuf_RecvData(C_PACKETBUF *self, void *pBuf, unsigned int uiSize)
{
	void			*pDataBuf;
	unsigned int	uiDataSize;
	
	/* 受信バッファ取得 */
	if ( (uiDataSize = PacketBuf_RecvBuf(self, &pDataBuf)) == 0)
	{
		return 0;
	}
	
	/* サイズチェック */
	if ( uiDataSize > uiSize)
	{
		return 0;
	}
	
	/* バッファからデータ読み込み */
	memcpy(pBuf, pDataBuf, uiDataSize);

	/* バッファ解放 */
	PacketBuf_RelBuf(self);

	return uiDataSize;
}


/* end of file */
