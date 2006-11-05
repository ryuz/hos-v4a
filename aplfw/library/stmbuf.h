

#ifndef __HOS__stmbuf_h__
#define __HOS__stmbuf_h__


/* ストリームバッファクラス */
typedef struct c_streambuf
{
	unsigned char *buf;		/* バッファ領域の先頭アドレス */
	int           bufsz;	/* バッファ領域のサイズ */
	int           head;		/* データの先頭 */
	int           tail;		/* データの末尾 */
} C_STREAMBUF;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void    StreamBuf_Create(C_STREAMBUF *self, int bufsz, void *buf);		/* バッファの生成 */
#define StreamBuf_Delete(self)	do {} while(0)							/* バッファの削除 */

/* データ送信 */
int     StreamBuf_SendData(C_STREAMBUF *self, void *data, int len);		/* データの送信 */
int     StreamBuf_GetBuf(C_STREAMBUF *self, void **p_buf);				/* 送信用バッファの取得(省コピー) */
void    StreamBuf_SendBuf(C_STREAMBUF *self, int len);					/* バッファ内のデータの送信(省コピー) */
int     StreamBuf_SendChar(C_STREAMBUF *self, int chr);					/* １キャラクタの送信 */

/* データ受信 */
int     StreamBuf_RecvData(C_STREAMBUF *self, void *data, int len);		/* データの受信 */
int     StreamBuf_RecvBuf(C_STREAMBUF *self, void **p_buf);				/* 受信したデータの入ったバッファの取得(省コピー) */
void    StreamBuf_RelBuf(C_STREAMBUF *self, int len);					/* 受信用バッファの解放(省コピー) */
int     StreamBuf_RecvChar(C_STREAMBUF *self);							/* １キャラクタの受信 */

/* 制御 */
void    StreamBuf_ClearBuf(C_STREAMBUF *self);							/* バッファのクリア */
#define StreamBuf_RefMaxSize(self)		((self)->bufsz - 1)				/* 最大格納可能サイズ参照 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__stmbuf_h__ */

