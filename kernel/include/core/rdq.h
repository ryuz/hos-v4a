/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  knl_que.h
 * @brief %en{queue object heder file}%jp{キューオブジェクトのヘッダファイル}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__knl_rdq_h__
#define __HOS_V4a__knl_rdq_h__


/* ------------------------------------------ */
/*         constant value definition          */
/* ------------------------------------------ */

#define _KERNEL_RDQ_ALG_SINGLE_QUE				1
#define _KERNEL_RDQ_ALG_ARRAYED_QUE				2
#define _KERNEL_RDQ_ALG_BITMAP_ARRAYED_QUE		3



#if _KERNEL_CFG_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_SINGLE_QUE

/* ------------------------------------------ */
/*             single queue                   */
/* ------------------------------------------ */


/** %en{ready-queue control block}%jp{レディーキュー管理ブロック} */
typedef struct _kernel_t_rdqcb
{
	_KERNEL_T_QUE que;
} _KERNEL_T_RDQCB;


#define _KERNEL_CRE_RDQ(rdqcb)			_KERNEL_CRE_QUE(&(rdqcb)->que)								/**< %en{create ready-queue}%jp{レディーキューの生成} */
#define _KERNEL_DEL_RDQ(rdqcb)			_KERNEL_DEL_QUE(&(rdqcb)->que)								/**< %en{delete ready-queue}%jp{レディーキューの削除} */

#define _KERNEL_ADD_RDQ(rdqcb, tskhdl)	_KERNEL_ADP_QUE(&(rdqcb)->que, (tskhdl))					/**< %jp{タスクをレディーキューに追加} */
#define _KERNEL_RMV_RDQ(rdqcb, tskhdl)	_KERNEL_RMV_QUE(&(rdqcb)->que, (tskhdl))					/**< %jp{タスクをレディーから取り外し} */

#define _KERNEL_RMH_RDQ(rdqcb)			_KERNEL_RMH_QUE(&(rdqcb)->que)								/**< %jp{キューの先頭タスクの取り外し} */
#define _KERNEL_REF_RDQ(rdqcb)			_KERNEL_REF_QUE(&(rdqcb)->que)								/**< %jp{キューの先頭タスクの参照} */

#define _KERNEL_ROT_RDQ(rdqcb, tskpri)	_KERNEL_RTP_QUE(&(rdqcb)->que, (tskpri))					/**< %jp{レディーキューの回転} */

#if 0
#define _KERNEL_CRE_RDQ()			_KERNEL_CRE_QUE(&_KERNEL_SYS_GET_RDQ()->que)					/**< %en{create ready-queue}%jp{レディーキューの生成} */
#define _KERNEL_DEL_RDQ()			_KERNEL_DEL_QUE(&_KERNEL_SYS_GET_RDQ()->que)					/**< %en{delete ready-queue}%jp{レディーキューの削除} */

#define _KERNEL_ADD_RDQ(tskhdl)		_KERNEL_ADP_QUE(&_KERNEL_SYS_GET_RDQ()->que, (tskhdl))			/**< %jp{タスクをレディーキューに追加} */
#define _KERNEL_RMV_RDQ(tskhdl)		_KERNEL_RMV_QUE(&_KERNEL_SYS_GET_RDQ()->que, (tskhdl))			/**< %jp{タスクをレディーから取り外し} */

#define _KERNEL_RMH_RDQ()			_KERNEL_RMH_QUE(&_KERNEL_SYS_GET_RDQ()->que)					/**< %jp{キューの先頭タスクの取り外し} */
#define _KERNEL_REF_RDQ()			_KERNEL_REF_QUE(&_KERNEL_SYS_GET_RDQ()->que)					/**< %jp{キューの先頭タスクの参照} */

#define _KERNEL_ROT_RDQ(tskpri)		_KERNEL_RTP_QUE(&_KERNEL_SYS_GET_RDQ()->que, (tskpri))			/**< %jp{レディーキューの回転} */
#endif


#elif _KERNEL_CFG_RDQ_ALGORITHM == _KERNEL_RDQ_ALG_ARRAYED_QUE

/* ------------------------------------------ */
/*               arrayed que                  */
/* ------------------------------------------ */

/** %en{ready-queue control block}%jp{レディーキュー管理ブロック} */
typedef struct _kernel_t_rdq
{
	T__KERNEL_QUE que[_KERNEL_TMAX_TSKPRI];
} _KERNEL_T_RDQ;


#define _kernel_cre_rdq()		_kernel_cre_que(&_KERNEL_SYS_GET_RDQ()->que)						/**< %en{create ready-queue}%jp{レディーキューの生成} */
#define _kernel_del_rdq()		_kernel_del_que(&_KERNEL_SYS_GET_RDQ()->que)						/**< %en{delete ready-queue}%jp{レディーキューの削除} */

#define _kernel_add_rdq(tskhdl)	_kernel_adp_que(&_KERNEL_SYS_GET_RDQ()->que[_KERNEL_TSK_GET_TSKPRI(tskhdl) - 1], tskhdl)				/**< %jp{タスクをキューに追加} */
#define _kernel_rmv_rdq(tskhdl)	_kernel_rmv_que(&_KERNEL_SYS_GET_RDQ()->que[_KERNEL_TSK_GET_TSKPRI(tskhdl) - 1], tskhdl)				/**< */

#define _kernel_rmh_rdq()		_kernel_rmh_que(&_KERNEL_SYS_GET_RDQ()->que)
#define _kernel_ref_rdq()		_kernel_ref_que(&_KERNEL_SYS_GET_RDQ()->que)						/**< %jp{キューの先頭タスクの参照(マクロ関数)} */

void    _kernel_rot_rdq(PRI tskpri);																/**< %jp{レディーキューの回転} */


#ifdef __cplusplus
}
#endif



#else	/* error */

#error Illegal value : _KERNEL_CFG_QUE_ALGORITHM

#endif



#endif	/* __HOS_V4a__knl_que_h__ */



/* end of file */
