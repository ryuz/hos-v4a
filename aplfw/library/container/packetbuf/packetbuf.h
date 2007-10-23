/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  packetbuf.h
 * @brief %jp{パケットデータ用バッファクラス}
 *
 * Copyright (C) 2002-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__packetbuf_h__
#define __HOS__packetbuf_h__



/* パケットバッファクラス構造体 */
typedef struct c_packetbuf
{
	unsigned char			*pubBuf;			/**< バッファ領域の先頭アドレス */
	unsigned int			uiBufSize;			/**< バッファ領域のサイズ */
	volatile unsigned int	uiReturnPoint;		/**< バッファ折り返し位置 */
	volatile unsigned int	uiHead;				/**< データの先頭 */
	volatile unsigned int	uiTail;				/**< データの末尾 */
} C_PACKETBUF;



#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void         PacketBuf_Create(C_PACKETBUF *self, unsigned int uiBufSize, void *pBuf);		/**< コンストラクタ */
#define      PacketBuf_Delete(self)		do {} while(0)										/**< デストラクタ */

/* パケット送信 */
unsigned int PacketBuf_SendData(C_PACKETBUF *self, const void *pData, unsigned int uiSize);	/**< データの送信 */
unsigned int PacketBuf_GetBuf(C_PACKETBUF *self, void **ppBuf, unsigned int uiSize);		/**< 送信用バッファの取得(省コピー) */
void         PacketBuf_SendBuf(C_PACKETBUF *self, unsigned int uiSize);						/**< バッファ内のデータの送信(省コピー) */

/* パケット受信 */
unsigned int PacketBuf_RecvData(C_PACKETBUF *self, void *pBuf, unsigned int uiSize);		/**< データの受信 */
unsigned int PacketBuf_RecvBuf(C_PACKETBUF *self, void **ppBuf);							/**< 受信したデータの入ったバッファの取得(省コピー) */
void         PacketBuf_RelBuf(C_PACKETBUF *self);											/**< 受信用バッファの解放(省コピー) */

/* 制御 */
void         PacketBuf_Clear(C_PACKETBUF *self);											/**< バッファのクリア */


#ifdef __cplusplus
}
#endif



#endif	/* __HOS__packetbuf_local_h__ */


/* end of file */
