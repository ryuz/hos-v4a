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



/** データの受信 */
unsigned int StreamBuf_RecvData(C_STREAMBUF *self, void *pBuf, unsigned int uiSize)
{
	void 			*pRecvBuf;			/* バッファアドレス */
	unsigned int 	uiBufSize;			/* バッファサイズ */
	unsigned int	uiRecvSize = 0;	/* 受信サイズ */

	do
	{
		/* 受信バッファ取得 */
		if ( (uiBufSize = StreamBuf_RecvBuf(self, &pRecvBuf)) <= 0 )
		{
			break;
		}

		/* 受信サイズ計算 */
		if ( uiBufSize > uiSize )
		{
			uiBufSize = uiSize;
		}

		/* 受信 */
		memcpy(pBuf, pRecvBuf, uiBufSize);
		StreamBuf_RelBuf(self, uiBufSize);
		uiSize     -= uiBufSize;
		uiRecvSize += uiBufSize;
		pBuf        = (void *)((char *)pBuf + uiBufSize);
	} while ( uiSize > 0 );

	return uiRecvSize;
}


/* end of file */
