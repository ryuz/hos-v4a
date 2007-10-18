#include <string.h>
#include "stmbuf.h"


/* バッファの生成 */
void StreamBuf_Create(
		C_STREAMBUF *self,		/* クラスポインタ */
		int         bufsz,		/* バッファに割り当てる領域の先頭番地 */
		void        *buf)		/* バッファに割り当てる領域のサイズ(バイト数) */
{
	/* クラスメンバの初期化 */
	self->bufsz = bufsz;
	self->buf   = buf;
	self->head  = 0;
	self->tail  = 0;
}


/* データの送信 */
int StreamBuf_SendData(
		C_STREAMBUF *self,		/* クラスポインタ */
		const void  *data,		/* 送信データ */
		int         len)		/* 送信データサイズ */
{
	void *buf;			/* バッファアドレス */
	int  buf_len;		/* バッファサイズ */
	int  snd_len = 0;	/* 送信サイズ */

	do
	{
		/* 送信バッファ取得 */
		if ( (buf_len = StreamBuf_GetBuf(self, &buf)) <= 0 )
		{
			break;
		}
		
		/* サイズ計算 */
		if ( buf_len > len )
		{
			buf_len = len;
		}

		/* 送信 */
		memcpy(buf, data, buf_len);
		StreamBuf_SendBuf(self, buf_len);
		len     -= buf_len;
		snd_len += buf_len;
		data     = (void *)((char *)data + buf_len);
	} while ( len > 0 );
	
	return snd_len;		/* 送信サイズを返す */
}


/* 送信用バッファの取得(省コピー) */
int StreamBuf_GetBuf(
		C_STREAMBUF *self,		/* クラスポインタ */
		void        **p_buf)	/* 送信バッファ先頭番地の格納先 */
{
	int head;

	*p_buf = (void *)(self->buf + self->tail);	/* 送信バッファ先頭番地の格納 */

	head = self->head;
	if ( head > self->tail )	/* データがバッファ末尾で折り返されているか */
	{
		return head - self->tail - 1;
	}
	else
	{
		if ( head == 0 )	/* バッファ先頭にデータがあるか */
		{
			return self->bufsz - self->tail - 1;		/* 先頭にデータがあるなら1バイト開ける */
		}
		else
		{
			return self->bufsz - self->tail;
		}
	}
}


/* バッファ内のデータの送信(省コピー) */
void StreamBuf_SendBuf(
		C_STREAMBUF *self,		/* クラスポインタ */
		int         len)		/* 送信サイズ */
{
	int next_tail;

	/* サイズチェック */
	if ( len <= 0 )
	{
		return;
	}

	/* 次のポインタ位置計算 */
	next_tail = self->tail + len;
	if ( next_tail >= self->bufsz )
	{
		next_tail = 0;
	}
	self->tail = next_tail;
}


/* １キャラクタの送信 */
int StreamBuf_SendChar(
		C_STREAMBUF *self,		/* クラスポインタ */
		int         chr)		/* 送信キャラクタ */
{
	int next_tail;

	/* 次の位置を計算 */
	next_tail = self->tail + 1;
	if ( next_tail >= self->bufsz )
	{
		next_tail = 0;
	}

	/* バッファフルチェック */
	if ( next_tail == self->head )
	{
		return -1;	/* 失敗 */
	}

	/* １キャラクタ送信 */
	chr = (*(self->buf + self->tail) = (unsigned char)chr);
	self->tail = next_tail;

	return chr;		/* 成功 */
}


/* データの受信 */
int StreamBuf_RecvData(
		C_STREAMBUF *self,		/* クラスポインタ */
		void        *data,		/* 受信データの格納先 */
		int         len)		/* 受信データの格納先のサイズ */
{
	void *buf;			/* バッファアドレス */
	int  buf_len;		/* バッファサイズ */
	int  rcv_len = 0;	/* 受信サイズ */

	do
	{
		/* 受信バッファ取得 */
		if ( (buf_len = StreamBuf_RecvBuf(self, &buf)) <= 0 )
		{
			break;
		}

		/* 受信サイズ計算 */
		if ( buf_len > len )
		{
			buf_len = len;
		}

		/* 受信 */
		memcpy(data, buf, buf_len);
		StreamBuf_RelBuf(self, buf_len);
		len     -= buf_len;
		rcv_len += buf_len;
		data     = (void *)((char *)data + buf_len);
	} while ( len > 0 );

	return rcv_len;
}


/* 受信用バッファの取得(省コピー) */
int StreamBuf_RecvBuf(
		C_STREAMBUF *self,		/* クラスポインタ */
		void        **p_buf)	/* 受信バッファ先頭番地の格納先 */
{
	int tail;

	*p_buf = (void *)(self->buf + self->head);	/* 受信バッファ先頭番地の格納 */

	tail = self->tail;
	if ( tail < self->head )	/* データがバッファ末尾で折り返されているか */
	{
		return self->bufsz - self->head;	/* 折り返されていたらバッファ末尾まで */
	}
	else
	{
		return tail - self->head;			/* 折り返されていなければデータ末尾まで */
	}
}




/* 受信用バッファの解放(省コピー) */
void StreamBuf_RelBuf(
		C_STREAMBUF *self,		/* クラスポインタ */
		int         len)		/* 解放するデータサイズ */
{
	int next_head;

	/* データ先頭位置更新 */
	next_head = self->head + len;
	if ( next_head >= self->bufsz )
	{
		next_head = 0;
	}
	self->head = next_head;
}



/* １キャラクタの受信 */
int StreamBuf_RecvChar(
		C_STREAMBUF *self)		/* クラスポインタ */
{
	int next_head;
	int chr;

	/* バッファエンプティ−チェック */
	if ( self->head == self->tail )
	{
		return -1;	/* 失敗 */
	}

	/* １キャラクタ受信 */
	chr = *(self->buf + self->head);

	/* 次の位置を計算 */
	next_head = self->head + 1;
	if ( next_head >= self->bufsz )
	{
		next_head = 0;
	}
	self->head = next_head;

	return chr;	/* 成功 */
}


/* バッファのクリア */
void StreamBuf_ClearBuf(
		C_STREAMBUF *self)		/* クラスポインタ */
{
	self->head = self->tail;
}


int StreamBuf_RefDataSize(C_STREAMBUF *self)
{
	int head;
	int tail;
	
	head = self->head;
	tail = self->tail;
	
	if ( head <= tail )
	{
		return tail - head;
	}
	else
	{
		return self->bufsz + tail - head;
	}
}


int StreamBuf_RefFreeSize(C_STREAMBUF *self)
{
	return StreamBuf_RefMaxSize(self) - StreamBuf_RefDataSize(self);
}

