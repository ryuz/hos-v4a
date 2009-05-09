/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rdq.h
 * @brief %jp{レディーキューオブジェクトのヘッダファイル}%en{ready-queue object heder file}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__knl_rdq_h__
#define __HOS_V4a__knl_rdq_h__


#if _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_SINGLE_QUE


/* ------------------------------------------ */
/*             single queue                   */
/* ------------------------------------------ */


/** %en{ready-queue control block}%jp{レディーキュー管理ブロック} */
typedef struct _kernel_t_rdqcb
{
	_KERNEL_T_QUE	que;
} _KERNEL_T_RDQCB;


#define _KERNEL_CRE_RDQ(rdqcb)			_KERNEL_CRE_QUE(&(rdqcb)->que)				/**< %en{create ready-queue}%jp{レディーキューの生成} */
#define _KERNEL_DEL_RDQ(rdqcb)			_KERNEL_DEL_QUE(&(rdqcb)->que)				/**< %en{delete ready-queue}%jp{レディーキューの削除} */

#define _KERNEL_ADD_RDQ(rdqcb, tskhdl)	_KERNEL_ADP_QUE(&(rdqcb)->que, (tskhdl))	/**< %jp{タスクをレディーキューに追加} */
#define _KERNEL_RMV_RDQ(rdqcb, tskhdl)	_KERNEL_RMV_QUE(&(rdqcb)->que, (tskhdl))	/**< %jp{タスクをレディーから取り外し} */

#define _KERNEL_RMH_RDQ(rdqcb)			_KERNEL_RMH_QUE(&(rdqcb)->que)				/**< %jp{キューの先頭タスクの取り外し} */
#define _KERNEL_REF_RDQ(rdqcb)			_KERNEL_REF_QUE(&(rdqcb)->que)				/**< %jp{キューの先頭タスクの参照} */

#define _KERNEL_ROT_RDQ(rdqcb, tskpri)	_KERNEL_RTP_QUE(&(rdqcb)->que, (tskpri))	/**< %jp{レディーキューの回転} */


#elif _KERNEL_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/* ------------------------------------------ */
/*               arrayed que                  */
/* ------------------------------------------ */

/** %en{ready-queue control block}%jp{レディーキュー管理ブロック} */
typedef struct _kernel_t_rdqcb
{
	_KERNEL_T_QUE	que[_KERNEL_TSK_TMAX_TPRI];
} _KERNEL_T_RDQCB;


#define _KERNEL_CRE_RDQ(rdqcb)			_kernel_cre_rdq((rdqcb))					/**< %jp{レディーキューの生成}%en{create ready-queue} */
#define _KERNEL_DEL_RDQ(rdqcb)			_kernel_del_rdq((rdqcb))					/**< %jp{レディーキューの削除}%en{delete ready-queue} */

#define _KERNEL_ADD_RDQ(rdqcb, tskhdl)	_kernel_add_rdq((rdqcb), (tskhdl))			/**< %jp{タスクをレディーキューに追加} */
#define _KERNEL_RMV_RDQ(rdqcb, tskhdl)	_kernel_rmv_rdq((rdqcb), (tskhdl))			/**< %jp{タスクをレディーから取り外し} */

#define _KERNEL_RMH_RDQ(rdqcb)			_kernel_rmh_rdq((rdqcb))					/**< %jp{キューの先頭タスクの取り外し} */
#define _KERNEL_REF_RDQ(rdqcb)			_kernel_ref_rdq((rdqcb))					/**< %jp{キューの先頭タスクの参照} */

#define _KERNEL_ROT_RDQ(rdqcb, tskpri)	_kernel_rot_rdq((rdqcb), (tskpri))			/**< %jp{レディーキューの回転} */


#ifdef __cplusplus
extern "C" {
#endif

void             _kernel_cre_rdq(_KERNEL_T_RDQCB *rdqcb);							/**< %jp{レディーキューの生成}%en{create ready-queue} */
void             _kernel_del_rdq(_KERNEL_T_RDQCB *rdqcb);							/**< %jp{レディーキューの削除}%en{delete ready-queue} */

void             _kernel_add_rdq(_KERNEL_T_RDQCB *rdqcb, _KERNEL_T_TSKHDL tskhdl);	/**< %jp{タスクをレディーキューに追加} */
void             _kernel_rmv_rdq(_KERNEL_T_RDQCB *rdqcb, _KERNEL_T_TSKHDL tskhdl);	/**< %jp{タスクをレディーキューから取り外し} */

_KERNEL_T_TSKHDL _kernel_rmh_rdq(_KERNEL_T_RDQCB *rdqcb);							/**< %jp{レディーキューの先頭タスクの取り外し} */
_KERNEL_T_TSKHDL _kernel_ref_rdq(_KERNEL_T_RDQCB *rdqcb);							/**< %jp{レディーキューの先頭タスクの参照} */

void             _kernel_rot_rdq(_KERNEL_T_RDQCB *rdqcb, PRI tskpri);				/**< %jp{レディーキューの回転} */

#ifdef __cplusplus
}
#endif



#else	/* error */

#error Illegal value : _KERNEL_QUE_ALGORITHM

#endif



#endif	/* __HOS_V4a__knl_que_h__ */



/* end of file */
