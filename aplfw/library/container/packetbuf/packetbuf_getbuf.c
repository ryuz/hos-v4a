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



/** 送信用バッファの取得(省コピー) */
unsigned int PacketBuf_GetBuf(C_PACKETBUF *self, void **ppBuf, unsigned int uiSize)
{
	unsigned int uiAllocSize;
	
	/* 割り当てサイズ計算 */
	uiAllocSize = PACKETBUF_DATASIZE(uiSize) + sizeof(unsigned int);
	
	/* 割り当て可能性チェック */
	if ( self->uiTail >= self->uiHead )
	{
		if ( self->uiTail > self->uiBufSize - uiAllocSize )
		{
			/* 折り返し可能かチェック */
			if ( self->uiHead <= uiAllocSize )
			{
				return 0;	/* 割り当て不可 */
			}
			
			/* 折り返し */
			self->uiReturnPoint = self->uiTail;
			self->uiTail        = 0;
		}
	}
	else
	{
		if ( self->uiHead - self->uiTail <= uiAllocSize )
		{
			return 0;	/* 割り当て不可 */
		}
	}
	
	/* 割り当てたバッファを返す */
	*ppBuf = (void *)(self->pubBuf + self->uiTail + sizeof(unsigned int));
	
	return uiSize;	/* 割り当てたサイズを返す */
}


/* end of file */
