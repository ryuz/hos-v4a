/**
 *  Hyper Operating System V4 Advance
 *
 * @file  hep.h
 * @brief %jp{メモリヒープのヘッダファイル}%en{memory heap heder file}
 *
 * @version $Id: hep.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
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

void    _kernel_cre_hep(_KERNEL_T_HEPCB *pk_hepcb, void *p_base, SIZE size);	/**< %jp{メモリヒープを生成} */
#define _kernel_del_hep(pk_hepcb)	do {} while(0)								/**< %jp{メモリヒープを削除} */
VP      _kernel_alc_hep(_KERNEL_T_HEPCB *pk_hepcb, SIZE size);					/**< %jp{メモリの割り当て} */
void    _kernel_fre_hep(_KERNEL_T_HEPCB *pk_hepcb, VP ptr);						/**< %jp{メモリの解放} */
#define _kernel_alg_hep(size)		_KERNEL_HEP_ALIGNED(size)					/**< %jp{メモリサイズのアライメントを合わせる} */

#ifdef __cplusplus
}
#endif


#endif	/* _KERNEL__core__hep_h_ */


/* end of file */
