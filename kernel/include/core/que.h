/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  que.h
 * @brief %jp{キューオブジェクトのヘッダファイル}%en{queue object heder file}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__knl_que_h__
#define _KERNEL__core__knl_que_h__




#if _KERNEL_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST

/* ------------------------------------------ */
/*              one-way list                  */
/* ------------------------------------------ */


/** %en{queue control block}%jp{キュー管理ブロック} */
typedef struct _kernel_t_que
{
	_KERNEL_TCB_T_TSKHDL tail			_KERNEL_TCB_TBITDEF_TSKHDL;		/**< %en{task of queue-tail} %jp{キュー末尾のタスク} */
} _KERNEL_T_QUE;


/** %en{object for queue connection} %jp{キュー接続用オブジェクト} */
#define _KERNEL_QUEOBJ	\
	_KERNEL_TCB_T_TSKHDL queobj_next	_KERNEL_TCB_TBITDEF_TSKHDL;

#define _KERNEL_CRE_QUEOBJ(tcb)				do{ (tcb)->queobj_next = _KERNEL_TSKHDL_NULL; }  while (0)
#define _KERNEL_DEL_QUEOBJ(tcb)				do{ }  while (0)


/* accessor */
#define _KERNEL_QUE_SET_TAIL(pk_que, x)		do { (pk_que)->tail = x; } while (0)
#define _KERNEL_QUE_GET_TAIL(pk_que)		((pk_que)->tail)

#define _KERNEL_TSK_SET_QUENEXT(tcb, x)		do { (tcb)->queobj_next = (x); } while (0)
#define _KERNEL_TSK_GET_QUENEXT(tcb)		((tcb)->queobj_next)


/* function  declaration */
#ifdef __cplusplus
extern "C" {
#endif

#define          _kernel_cre_que(pk_que)	do { (pk_que)->tail = _KERNEL_TSKHDL_NULL; } while (0)		/**< %jp{キューの生成}%en{create queue} */
#define          _kernel_del_que(pk_que)	do {} while (0)												/**< %jp{キューの削除}%en{delete queue} */

void             _kernel_add_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl, ATR atr);				/**< %jp{タスクをキューに追加} */
void             _kernel_adf_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクをFIFO順でキューに追加} */
void             _kernel_adp_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクを優先度順でキューに追加}%en{in the order of the task's priority} */

void             _kernel_rmv_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクをキューから取り除く} */
_KERNEL_T_TSKHDL _kernel_rmh_que(_KERNEL_T_QUE *pk_que);
void             _kernel_trm_que(_KERNEL_T_TSKHDL tskhdl);												/**< %jp{タスクをキューから取り除く} */

_KERNEL_T_TSKHDL _kernel_nxt_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{キューの次のタスクの取り出し} */

void             _kernel_rot_que(_KERNEL_T_QUE *pk_que);												/**< %jp{レディーキューの回転} */
#define          _kernel_ref_que(pk_que)		\
					((pk_que)->tail != _KERNEL_TSKHDL_NULL ? (_KERNEL_TSK_GET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB((pk_que)->tail))) : _KERNEL_TSKHDL_NULL)
																										/**< %jp{キューの先頭タスクの参照(マクロ関数)} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_CRE_QUE(pk_que)					_kernel_cre_que(pk_que)
#define _KERNEL_DEL_QUE(pk_que)					_kernel_del_que(pk_que)
#define _KERNEL_ADD_QUE(pk_que, tskhdl, atr)	_kernel_add_que(pk_que, tskhdl, atr)
#define _KERNEL_ADF_QUE(pk_que, tskhdl)			_kernel_adf_que(pk_que, tskhdl)
#define _KERNEL_ADP_QUE(pk_que, tskhdl)			_kernel_adp_que(pk_que, tskhdl)
#define _KERNEL_RMV_QUE(pk_que, tskhdl)			_kernel_rmv_que(pk_que, tskhdl)
#define _KERNEL_RMH_QUE(pk_que)					_kernel_rmh_que(pk_que)
#define _KERNEL_TRM_QUE(tskhdl)					_kernel_trm_que(tskhdl)
#define _KERNEL_NXT_QUE(pk_que, tskhdl)			_kernel_nxt_que(pk_que, tskhdl)
#define _KERNEL_ROT_QUE(pk_que)					_kernel_rot_que(pk_que)
#define _KERNEL_REF_QUE(pk_que)					_kernel_ref_que(pk_que)



#elif _KERNEL_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST

/* ------------------------------------------ */
/*              two-way list                  */
/* ------------------------------------------ */


/** %en{queue control block} %jp{キュー管理ブロック} */
typedef struct _kernel_t_que
{
	_KERNEL_TCB_T_TSKHDL head				_KERNEL_TCB_TBITDEF_TSKHDL;			/**< %en{task of queue-head} %jp{キュー先頭のタスク} */
} _KERNEL_T_QUE;

/** %en{object for queue connection(Two-way list)} %jp{キュー接続用オブジェクト(双方向リスト)} */
#define _KERNEL_QUEOBJ									\
	_KERNEL_TCB_T_TSKHDL queobj_next		_KERNEL_TCB_TBITDEF_TSKHDL;	\
	_KERNEL_TCB_T_TSKHDL queobj_prev		_KERNEL_TCB_TBITDEF_TSKHDL;

#define _KERNEL_CRE_QUEOBJ(tcb)				do{ (tcb)->queobj_next = _KERNEL_TSKHDL_NULL; }  while (0)
#define _KERNEL_DEL_QUEOBJ(tcb)				do{ }  while (0)


#define _KERNEL_QUE_SET_HEAD(pk_que, x)		do { (pk_que)->head = x; } while (0)
#define _KERNEL_QUE_GET_HEAD(pk_que)		((pk_que)->head)

#define _KERNEL_TSK_SET_QUENEXT(tcb, x)		do { (tcb)->queobj_next = (x); } while (0)
#define _KERNEL_TSK_GET_QUENEXT(tcb)		((tcb)->queobj_next)
#define _KERNEL_TSK_SET_QUEPREV(tcb, x)		do { (tcb)->queobj_prev = (x); } while (0)
#define _KERNEL_TSK_GET_QUEPREV(tcb)		((tcb)->queobj_prev)


/* function  declaration */
#ifdef __cplusplus
extern "C" {
#endif

#define          _kernel_cre_que(pk_que)		do { (pk_que)->head = _KERNEL_TSKHDL_NULL; } while (0)	/**< %en{create queue}%jp{キューの生成} */
#define          _kernel_del_que(pk_que)		do {} while (0)											/**< %en{delete queue}%jp{キューの削除} */

void             _kernel_add_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl, ATR atr);				/**< %jp{タスクをキューに追加} */
void             _kernel_adf_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクをFIFO順でキューに追加} */
void             _kernel_adp_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクを優先度順でキューに追加} (in the order of the task's priority) */

void             _kernel_trm_que(_KERNEL_T_TSKHDL tskhdl);												/**< %jp{タスクをキューから取り除く} */
void             _kernel_rmv_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{タスクをキューから取り除く} */
_KERNEL_T_TSKHDL _kernel_rmh_que(_KERNEL_T_QUE *pk_que);												/**< %jp{キュー先頭タスクの取り出し} */

_KERNEL_T_TSKHDL _kernel_nxt_que(_KERNEL_T_QUE *pk_que, _KERNEL_T_TSKHDL tskhdl);						/**< %jp{キューの次のタスクの取り出し} */

void             _kernel_rot_que(_KERNEL_T_QUE *pk_que);												/**< %jp{レディーキューの回転} */
#define          _kernel_ref_que(pk_que)	((pk_que)->head)											/**< %jp{キューの先頭タスクの参照(マクロ関数)} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_CRE_QUE(pk_que)					_kernel_cre_que(pk_que)
#define _KERNEL_DEL_QUE(pk_que)					_kernel_del_que(pk_que)
#define _KERNEL_ADD_QUE(pk_que, tskhdl, atr)	_kernel_add_que(pk_que, tskhdl, atr)
#define _KERNEL_ADF_QUE(pk_que, tskhdl)			_kernel_adf_que(pk_que, tskhdl)
#define _KERNEL_ADP_QUE(pk_que, tskhdl)			_kernel_adp_que(pk_que, tskhdl)
#define _KERNEL_RMV_QUE(pk_que, tskhdl)			_kernel_rmv_que(pk_que, tskhdl)
#define _KERNEL_RMH_QUE(pk_que)					_kernel_rmh_que(pk_que)
#define _KERNEL_TRM_QUE(tskhdl)					_kernel_trm_que(tskhdl)
#define _KERNEL_NXT_QUE(pk_que, tskhdl)			_kernel_nxt_que(pk_que, tskhdl)
#define _KERNEL_ROT_QUE(pk_que)					_kernel_rot_que(pk_que)
#define _KERNEL_REF_QUE(pk_que)					_kernel_ref_que(pk_que)


#else	/* error */

#error Illegal value : _KERNEL_QUE_ALGORITHM

#endif



#endif	/* _KERNEL__core__knl_que_h__ */



/* end of file */
