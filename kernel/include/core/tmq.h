/**
 *  Hyper Operating System V4 Advance
 *
 * @file  tmq.h
 * @brief %jp{タイマキューのヘッダファイル}%en{timer queue heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__tmq_h__
#define _KERNEL__core__tmq_h__



/** %jp{タイマオブジェクト構造体} */
typedef struct _kernel_t_timobj
{
	struct _kernel_t_timobj	*next;										/**< %jp{次のオブジェクト} */
	struct _kernel_t_timobj	*prev;										/**< %jp{前のオブジェクト} */
	RELTIM                  lefttim;									/**< %jp{残時間} */
	void (*timhdr)(struct _kernel_t_timobj *timobj, RELTIM ovetim);		/**< %jp{タイマハンドラ} */
} _KERNEL_T_TIMOBJ;


/** %jp{タイマキュー} */
typedef struct _kernel_t_tmqcb
{
	_KERNEL_T_TIMOBJ		*head;										/**< %jp{先頭のオブジェクト} */
	_KERNEL_T_TIMOBJ		*busy;										/**< %jp{処理中のオブジェクト} */
	_KERNEL_T_TIMOBJ		*next;										/**< %jp{次の処理予定オブジェクト} */
} _KERNEL_T_TMQCB;



#ifdef __cplusplus
extern "C" {
#endif

void _kernel_add_tmq(_KERNEL_T_TMQCB *tmqcb, _KERNEL_T_TIMOBJ *pk_timobj);
void _kernel_rmv_tmq(_KERNEL_T_TMQCB *tmqcb, _KERNEL_T_TIMOBJ *pk_timobj);
void _kernel_sig_tmq(_KERNEL_T_TMQCB *tmqcb, RELTIM tictim);

#ifdef __cplusplus
}
#endif


#define _KERNEL_TIMOBJ_CRE_TIMOBJ(pk_timobj)		do { (pk_timobj)->next = NULL; } while (0)
#define _KERNEL_TIMOBJ_DEL_TIMOBJ(pk_timobj)		do { } while (0)
#define _KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, x)	do { (pk_timobj)->lefttim = (x); } while (0)
#define _KERNEL_TIMOBJ_GET_LEFTTIM(pk_timobj)		((pk_timobj)->lefttim)
#define _KERNEL_TIMOBJ_SET_TIMHDR(pk_timobj, x)		do { (pk_timobj)->timhdr = (x); } while (0)
#define _KERNEL_TIMOBJ_GET_TIMHDR(pk_timobj)		((pk_timobj)->timhdr)

#define _KERNEL_ADD_TMQ(tmqcb, pk_timobj)			_kernel_add_tmq((tmqcb), (pk_timobj))
#define _KERNEL_RMV_TMQ(tmqcb, pk_timobj)			_kernel_rmv_tmq((tmqcb), (pk_timobj))
#define _KERNEL_BSY_TMQ(tmqcb, pk_timobj)			((tmqcb)->busy == (pk_timobj))
#define _KERNEL_SIG_TMQ(tmqcb, tictim)				_kernel_sig_tmq((tmqcb), (tictim))


#endif	/* _KERNEL__core__tmq_h__ */



/* end of file */
