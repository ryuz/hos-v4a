/**
 *  Hyper Operating System V4 Advance
 *
 * @file  proc.h
 * @brief %jp{ARMv7-M}%en{ARMv7-M}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__arm__arm_v6m__proc_h__
#define _KERNEL__arch__proc__arm__arm_v6m__proc_h__

#define _KERNEL_REG_INT_CONTROL			((volatile UW *)0xE000ED04)		/**< %jp{割り込み制御状態レジスタ}%en{Interrupt Control State Register} */

#define _KERNEL_REG_INT_SETENA_BASE		((volatile UW *)0xE000E100)		/**< %jp{割り込みイネーブルセットレジスタ} */
#define _KERNEL_REG_INT_CLRENA_BASE		((volatile UW *)0xE000E180)		/**< %jp{割り込みイネーブルクリアレジスタ} */
#define _KERNEL_REG_INT_SETPEND_BASE	((volatile UW *)0xE000E200)		/**< %jp{割り込み保留セットレジスタ} */
#define _KERNEL_REG_INT_CLRPEND_BASE	((volatile UW *)0xE000E280)		/**< %jp{割り込み保留クリアレジスタ} */


/** %jp{コンテキスト制御ブロック} */
typedef struct _kernel_t_ctxcb
{
	VP	sp;
} _KERNEL_T_CTXCB;



#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_reset_handler(void);
void    _kernel_nmi_handler(void);
void    _kernel_hw_fault_handler(void);
void    _kernel_pendsv_handler(void);

int     _kernel_ref_cpu_control(void);																/**< %jp{CONTROLレジスタの取得} */


void    _kernel_ena_int(void);																		/**< %jp{割込み許可} */
void    _kernel_dis_int(void);																		/**< %jp{割込み禁止} */
void    _kernel_wai_int(void);																		/**< %jp{割込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, VP isp, FP entry, VP_INT par1, VP_INT par2);		/**< %jp{実行コンテキストの作成} */
void    _kernel_rst_ctx(VP_INT par1, VP_INT par2, FP entry, VP isp);								/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxinf_nxt, _KERNEL_T_CTXCB *pk_ctxcb_now);				/**< %jp{実行コンテキストの切替} */

#ifdef __cplusplus
}
#endif



#define _KERNEL_INI_PRC()			do {} while (0)													/**< %jp{プロセッサ固有の初期化} */

#define _KERNEL_INI_INT(stksz, stk)	do {} while (0)													/**< %jp{割込み初期化} */
#define _KERNEL_ENA_INT()			_kernel_ena_int()												/**< %jp{割込み許可} */
#define _KERNEL_DIS_INT()			_kernel_dis_int()												/**< %jp{割込み禁止} */
#define _KERNEL_WAI_INT()			_kernel_wai_int()												/**< %jp{割込み待ち(アイドル時の処理)} */

#define _KERNEL_CRE_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_cre_ctx((pk_ctxcb), (isp), (entry), (exinf1), (exinf2))	/**< %jp{実行コンテキストの作成} */
#define _KERNEL_DEL_CTX(pk_ctxcb)	do {} while (0)													/**< %jp{実行コンテキストの削除} */
#define _KERNEL_RST_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_rst_ctx((exinf1), (exinf2), (entry), (isp))				/**< %jp{実行コンテキストのリスタート} */
#define _KERNEL_STA_CTX(pk_ctxcb)	_kernel_sta_ctx(pk_ctxcb)
#define _KERNEL_SWI_CTX(pk_ctxcb_now, pk_ctxinf_nxt)							\
									_kernel_swi_ctx((pk_ctxinf_nxt), (pk_ctxcb_now))				/**< %jp{実行コンテキストの切替} */


#define	_KERNEL_PROC_SET_CTX()		do { } while (0)
#define	_KERNEL_PROC_CLR_CTX()		do { } while (0)
#define	_KERNEL_PROC_SNS_CTX()		((_kernel_ref_cpu_control() & 0x00000002) == 0)

#define	_KERNEL_PROC_SET_DLY()		do { *_KERNEL_REG_INT_CONTROL |= 0x10000000; } while (0)
#define	_KERNEL_PROC_CLR_DLY()		do { *_KERNEL_REG_INT_CONTROL |= 0x08000000; } while (0)
#define	_KERNEL_PROC_SNS_DLY()		((*_KERNEL_REG_INT_CONTROL & 0x10000000) != 0)


#endif	/* _KERNEL__arch__proc__arm__arm_v6m__proc_h__ */



/* end of file */
