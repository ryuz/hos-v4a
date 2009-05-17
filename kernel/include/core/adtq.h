/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  adtq.h
 * @brief %jp{非同期データキューヘッダファイル}%en{Asynchronous Data Queue header file}
 *
 * %jp{送信側、及び、受信側でロック(割込み禁止など)を利用しなくても成立するキュー}
 * %jp{データ領域が１つ無駄になるのでメモリ効率で若干不利}
 * %jp{DPC向けだが、将来DTQとの共用も可能なように切り出しておく}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__adtq_h__
#define _KERNEL__core__adtq_h__


typedef UINT							_KERNEL_ADTQ_T_POSITION;
typedef volatile UINT					_KERNEL_ADTQCB_T_POSITION;
#define _KERNEL_DTQCB_TBITDEF_POSITION

typedef UINT							_KERNEL_ADTQ_T_ADTQCNT;
typedef volatile UINT					_KERNEL_ADTQCB_T_ADTQCNT;
#define _KERNEL_DTQCB_TBITDEF_DTQCNT



typedef struct _kernel_t_adtqcb
{
	_KERNEL_ADTQCB_T_POSITION	head		_KERNEL_DTQCB_TBITDEF_POSITION;		/**< %jp{データキューの先頭位置} */
	_KERNEL_ADTQCB_T_POSITION	tail		_KERNEL_DTQCB_TBITDEF_POSITION;		/**< %jp{データキューの末尾位置} */
	_KERNEL_ADTQCB_T_ADTQCNT	adtqcnt		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキュー領域のサイズ(VP_INT単位)} */
	VP_INT						*adtq;											/**< %jp{データキュー領域の先頭アドレス} */
} _KERNEL_T_ADTQCB;


#define _KERNEL_ADTQ_SET_HEAD(adtqcb, x)		do { (adtqcb)->head = (x); } while (0)
#define _KERNEL_ADTQ_GET_HEAD(adtqcb)			((adtqcb)->head)
#define _KERNEL_ADTQ_SET_TAIL(adtqcb, x)		do { (adtqcb)->tail = (x); } while (0)
#define _KERNEL_ADTQ_GET_TAIL(adtqcb)			((adtqcb)->tail)
#define _KERNEL_ADTQ_SET_ADTQCNT(adtqcb, x)		do { (adtqcb)->adtqcnt = (x); } while (0)
#define _KERNEL_ADTQ_GET_ADTQCNT(adtqcb)		((adtqcb)->adtqcnt)
#define _KERNEL_ADTQ_SET_ADTQ(adtqcb, x)		do { (adtqcb)->adtq = (x); } while (0)
#define _KERNEL_ADTQ_GET_ADTQ(adtqcb)			((adtqcb)->adtq)



#ifdef __cplusplus
extern "C" {
#endif

BOOL                   _kernel_adtq_snd_dat(_KERNEL_T_ADTQCB *adtqcb, VP_INT data);
BOOL                   _kernel_adtq_rcv_dat(_KERNEL_T_ADTQCB *adtqcb, VP_INT *p_data);
void                   _kernel_adtq_fsnd_dat(_KERNEL_T_ADTQCB *adtqcb, VP_INT data);
VP_INT                 _kernel_adtq_frcv_dat(_KERNEL_T_ADTQCB *adtqcb);
_KERNEL_ADTQ_T_ADTQCNT _kernel_adtq_ref_fdtqnt(_KERNEL_T_ADTQCB *adtqcb);
_KERNEL_ADTQ_T_ADTQCNT _kernel_adtq_ref_sdtqnt(_KERNEL_T_ADTQCB *adtqcb);

#ifdef __cplusplus
}
#endif


#define _KERNEL_ADTQ_INI_QUE(adtqcb, adtq, adtqcnt)		do { _KERNEL_ADTQ_SET_ADTQ((adtqcb), (adtq)); _KERNEL_ADTQ_SET_ADTQCNT((adtqcb), (adtqcnt)); } while(0)
#define _KERNEL_ADTQ_SND_DAT(adtqcb, data)				_kernel_adtq_snd_dat((adtqcb), (data))
#define _KERNEL_ADTQ_RCV_DAT(adtqcb, p_data)			_kernel_adtq_rcv_dat((adtqcb), (p_data))
#define _KERNEL_ADTQ_FSND_DAT(adtqcb, data)				_kernel_adtq_fsnd_dat((adtqcb), (data))	
#define _KERNEL_ADTQ_FRCV_DAT(adtqcb)					_kernel_adtq_frcv_dat(adtqcb)
#define _KERNEL_ADTQ_REF_SDTQNT(adtqcb)					_kernel_adtq_ref_sdtqnt(adtqcb)
#define _KERNEL_ADTQ_REF_FDTQNT(adtqcb)					_kernel_adtq_ref_fdtqnt(adtqcb)


#endif	/* _KERNEL__core__adtq_h__ */


/* end of file */
