/**
 *  Hyper Operating System V4 Advance
 *
 * @file  hep.h
 * @brief %jp{メモリヒープのヘッダファイル}%en{memory heap heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__hep_h_
#define _KERNEL__core__hep_h_


#include "itron.h"


#define _KERNEL_HEP_MEMALIGN		32			/**< %jp{メモリアライメント} */
#define _KERNEL_HEP_USING			0x1234		/**< %jp{使用中} */
#define _KERNEL_HEP_FREE			0xabcd		/**< %jp{未使用} */



/** %jp{サイズアライメント} */
#define _KERNEL_HEP_ALIGNED(size)	(((size) + _KERNEL_HEP_MEMALIGN - 1) & ~(_KERNEL_HEP_MEMALIGN - 1))


/** %jp{ヒープメモリブロック} */
typedef struct _kernel_t_hepblk
{
	struct _kernel_t_hepblk* prev;	/**< %jp{前のブロック} */
	SIZE   size;					/**< %jp{ブロックのサイズ} */
	INT    flag;					/**< %jp{使用中フラグ} */
} _KERNEL_T_HEPBLK;


/** %jp{ヒープ制御ブロック} */
typedef struct _kernel_t_hepcb
{
	_KERNEL_T_HEPBLK *base;			/**< %jp{カーネル用メモリ先頭ブロックのアドレス} */
	SIZE            heapsz;			/**< %jp{カーネル用メモリサイズ} */
} _KERNEL_T_HEPCB;


/** %jp{カーネルメモリ管理ブロックサイズ} */
#define _KERNEL_HEP_BLKSIZE			_KERNEL_HEP_ALIGNED(sizeof(_KERNEL_T_HEPBLK))


#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_cre_hep(_KERNEL_T_HEPCB *hepcb, SIZE hepsz, VP hep);					/**< %jp{メモリヒープを生成} */
VP      _kernel_alc_hep(_KERNEL_T_HEPCB *hepcb, SIZE size);								/**< %jp{メモリの割り当て} */
void    _kernel_fre_hep(_KERNEL_T_HEPCB *hepcb, VP ptr);								/**< %jp{メモリの解放} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_CRE_HEP(hepcb, hepsz, hep)	_kernel_cre_hep((hepcb), (hepsz), (hep))	/**< %jp{メモリヒープを生成} */
#define _KERNEL_DEL_HEP(hepcb)				do {} while(0)								/**< %jp{メモリヒープを削除} */
#define _KERNEL_ALC_HEP(hepcb, size)		_kernel_alc_hep((hepcb), (size))			/**< %jp{メモリの割り当て} */
#define _KERNEL_FRE_HEP(hepcb, ptr)			_kernel_fre_hep((hepcb), (ptr))				/**< %jp{メモリの解放} */
#define _KERNEL_ALG_HEP(hepcb, size)		_KERNEL_HEP_ALIGNED(size)					/**< %jp{メモリサイズのアライメントを合わせる} */



#endif	/* _KERNEL__core__hep_h_ */


/* end of file */
