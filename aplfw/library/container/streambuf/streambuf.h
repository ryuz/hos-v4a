/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streambuf.h
 * @brief %jp{ストリームデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__streambuf_h__
#define __HOS__streambuf_h__


/* ストリームバッファクラス */
typedef struct c_streambuf
{
	unsigned char			*pubBuf;	/**< バッファ領域の先頭アドレス */
	unsigned int			uiBufSize;	/**< バッファ領域のサイズ */
	volatile unsigned int	uiHead;		/**< データの先頭 */
	volatile unsigned int	uiTail;		/**< データの末尾 */
} C_STREAMBUF;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void         StreamBuf_Create(C_STREAMBUF *self, unsigned int uiBufSize, void *pBuf);		/**< コンストラクタ */
#define      StreamBuf_Delete(self)	do {} while(0)											/**< デストラクタ */

/* データ送信 */
unsigned int StreamBuf_SendData(C_STREAMBUF *self, const void *pData, unsigned int uiSize);	/**< データの送信 */
unsigned int StreamBuf_GetBuf(C_STREAMBUF *self, void **ppBuf);								/**< 送信用バッファの取得(省コピー) */
void         StreamBuf_SendBuf(C_STREAMBUF *self, unsigned int uiSize);						/**< バッファ内のデータの送信(省コピー) */
int          StreamBuf_SendChar(C_STREAMBUF *self, int c);									/**< １キャラクタの送信 */

/* データ受信 */
unsigned int StreamBuf_RecvData(C_STREAMBUF *self, void *pBuf, unsigned int uiSize);		/**< データの受信 */
unsigned int StreamBuf_RecvBuf(C_STREAMBUF *self, void **ppBuf);							/**< 受信したデータの入ったバッファの取得(省コピー) */
void         StreamBuf_RelBuf(C_STREAMBUF *self, unsigned int uiSize);						/**< 受信用バッファの解放(省コピー) */
int          StreamBuf_RecvChar(C_STREAMBUF *self);											/**< １キャラクタの受信 */

/* 制御 */
void         StreamBuf_Clear(C_STREAMBUF *self);											/**< バッファのクリア */
unsigned int StreamBuf_RefDataSize(C_STREAMBUF *self);										/**< バッファ空き容量の参照 */
unsigned int StreamBuf_RefFreeSize(C_STREAMBUF *self);

#define      StreamBuf_RefMaxSize(self)		((self)->uiBufSize - 1)							/**< 最大格納可能サイズ参照 */
#define      StreamBuf_RefBufAddr(self)		((void *)(self)->pubBuf)						/**< バッファアドレスの参照 */
#define      StreamBuf_RefBufSize(self)		((self)->uiBufSize)								/**< バッファ内データ量の参照 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__streambuf_h__ */


/* end of file */
