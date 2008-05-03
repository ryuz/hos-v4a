/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctl.h
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__ia32__i386__proc_h__
#define _KERNEL__arch__proc__ia32__i386__proc_h__


/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	VP_INT	sp;
} _KERNEL_T_CTXCB;

/** %jp{割込みコンテキスト制御ブロック} */
typedef struct _kernel_t_ictxcb
{
	INT		intcnt;
	VP		isp;
} _KERNEL_T_ICTXCB;


extern _KERNEL_T_ICTXCB _kernel_ictxcb;		/**< %jp{割込みコンテキスト制御ブロック} */



#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ena_int(void);																		/**< %jp{割込み許可} */
void    _kernel_dis_int(void);																		/**< %jp{割込み禁止} */
void    _kernel_wai_int(void);																		/**< %jp{割込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, VP isp, FP entry, VP_INT par1, VP_INT par2);		/**< %jp{実行コンテキストの作成} */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの削除} */
void    _kernel_rst_ctx(VP_INT par1, VP_INT par2, FP entry, VP isp);								/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxinf_nxt, _KERNEL_T_CTXCB *pk_ctxcb_now);				/**< %jp{実行コンテキストの切替} */

void    _kernel_exc_hdr(void);
void    _kernel_int_hdr(void);

void    _kernel_outpb(UH port, UB data);
void    _kernel_outph(UH port, UH data);
void    _kernel_outpw(UH port, UW data);
UB      _kernel_inpb(UH port);
UH      _kernel_inph(UH port);
UW      _kernel_inpw(UH port);

void    _kernel_lgdt(VP gdt);
void    _kernel_lldt(VP ldt);
void    _kernel_lidt(VP idt);



#ifdef __cplusplus
}
#endif



#define _KERNEL_INI_PRC()			do {} while (0)													/**< %jp{プロセッサ固有の初期化} */

#define _KERNEL_INI_INT(stksz, stk)	do { _kernel_ictxcb.isp = (VB *)(stk) + (stksz); } while (0)	/**< %jp{割込み初期化} */
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



#endif	/* _KERNEL__arch__proc__ia32__i386__proc_h__ */


/* end of file */
