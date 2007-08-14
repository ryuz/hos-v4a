/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  crc16.h
 * @brief %jp{16bit CRC 計算ライブラリ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__crc16_h__
#define __HOS__crc16_h__


typedef struct c_crc16
{
	unsigned short uhCrc;
} C_CRC16;



#ifdef __cplusplus
extern "C" {
#endif

#define        Crc16_Create(self)	Crc16_Reset(self)										/**< コンストラクタ */
#define        Crc16_Delete(self)	do {} while (0)											/**< デストラクタ */

void           Crc16_Reset(C_CRC16 *self);													/**< 計算リセット */
void           Crc16_Update(C_CRC16 *self, const void *pData, unsigned int iLen);			/**< CRC計算 */
unsigned short Crc16_GetDigest(C_CRC16 *self);												/**< ダイジェスト(計算結果)取得 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__crc16_h__ */


/* end of file */
