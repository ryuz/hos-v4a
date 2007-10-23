/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streambuf.h
 * @brief %jp{ストリームデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "streambuf_local.h"


/** データの送信 */
unsigned int StreamBuf_SendData(C_STREAMBUF *self, const void *pData, unsigned int uiSize)
{
	void 			*pBuf;				/* バッファアドレス */
	unsigned int	uiBufSize;			/* バッファサイズ */
	unsigned int	uiSendSize = 0;		/* 送信サイズ */

	do
	{
		/* 送信バッファ取得 */
		if ( (uiBufSize = StreamBuf_GetBuf(self, &pBuf)) <= 0 )
		{
			break;
		}
		
		/* サイズ計算 */
		if ( uiBufSize > uiSize )
		{
			uiBufSize = uiSize;
		}
		
		/* データコピー */
		memcpy(pBuf, pData, uiBufSize);
		
		/* 送信 */
		StreamBuf_SendBuf(self, uiBufSize);
		
		/* ポインタ更新 */
		pData       = (void *)((char *)pData + uiBufSize);
		uiSize     -= uiBufSize;
		uiSendSize += uiBufSize;
	} while ( uiSize > 0 );
	
	
	return uiSendSize;		/* 送信サイズを返す */
}


/* end of file */
