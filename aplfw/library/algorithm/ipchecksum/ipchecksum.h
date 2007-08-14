/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  ipchecksum.h
 * @brief %jp{IPチェックサム計算ライブラリ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__ipchecksum_h__
#define __HOS__ipchecksum_h__


typedef struct c_ipchecksum
{
	unsigned long uwSum;
} C_IPCHECKSUM;



#ifdef __cplusplus
extern "C" {
#endif

#define        IpCheckSum_Create(self)	do { (self)->uwSum = 0; } while (0)						/**< コンストラクタ */
#define        IpCheckSum_Delete(self)	do {} while (0)											/**< デストラクタ */

#define        IpCheckSum_Reset(self)	do { (self)->uwSum = 0; } while (0)						/**< 計算リセット */
void           IpCheckSum_Update(C_IPCHECKSUM *self, const void *pData, unsigned int iLen);		/**< 計算 */
unsigned short IpCheckSum_GetDigest(C_IPCHECKSUM *self);										/**< 計算結果取得 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__ipchecksum_h__ */


/* end of file */
