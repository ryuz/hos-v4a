/**
 *  Hyper Operating System V4 Advance
 *
 * @file  proc.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}%en{Processor archtecture}
 *
 * @version $Id: proc.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__win32__proc_h__
#define _KERNEL__win32__proc_h__


/** %jp{Windows ヘッダファイルの読みこみ} */
#define SIZE  WIN_SIZE
#include <windows.h>
#undef  SIZE
#include <setjmp.h>


/* %jp{
   Windows 標準の SIZE 構造体が ITRON の標準型と重なるので
   上記のように強制的に WIN_SIZE に名前を変えている
   Windows APIで SIZE を利用するときは要注意}
*/



/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	HANDLE  hEvent;				/**< %jp{スレッドハンドル} */
	HANDLE  hThread;			/**< %jp{スレッドハンドル} */
	DWORD   dwThreadId;			/**< %jp{スレッドID} */
	BOOL    blIntSuspend;		/**< %jp{割り込みディスパッチされた} */
	FP      entry;				/**< %jp{エントリーアドレス} */
	VP_INT  exinf1;				/**< %jp{パラメータ１} */
	VP_INT  exinf2;				/**< %jp{パラメータ２} */
	jmp_buf jmpenv;				/**< %jp{コンテキストリセット用のlongjmpデータ} */
} _KERNEL_T_CTXCB;



extern HANDLE          _kernel_win32_hSemLock;			/** %jp{システムの排他制御用セマフォ} */
extern _KERNEL_T_CTXCB *_kernel_win32_ctxcb_run;		/** %jp{実行中のコンテキスト} */


#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ini_prc(void);																/**< アーキテクチャ固有の初期化 */

void    _kernel_ena_int(void);																/**< 割り込み許可 */
void    _kernel_dis_int(void);																/**< 割り込み禁止 */
void    _kernel_wai_int(void);																/**< 割り込み待ち(アイドル時の処理) */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, FP entry, VP_INT exinf1, VP_INT exinf2);	/**< 実行コンテキストの作成 */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb);											/**< 実行コンテキストの削除 */
void    _kernel_rst_ctx(_KERNEL_T_CTXCB *pk_ctxcb);											/**< 実行コンテキストのリスタート */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);											/**< 実行コンテキストの開始 */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxcb_now, _KERNEL_T_CTXCB *pk_ctxinf_nxt);		/**< 実行コンテキストの切替 */

void     vsig_int(int inhno);		/* %jp{割り込み} */


#if KERNEL_SMP

int     _kernel_get_prc(void);
void    _kernel_ini_prc(int prcid);
void    _kernel_loc_ctx(_KERNEL_T_LOC *loc);
void    _kernel_unl_ctx(_KERNEL_T_LOC *loc);
void    _kernel_loc_wri(_KERNEL_T_LOC *loc);
void    _kernel_unl_wri(_KERNEL_T_LOC *loc);
void    _kernel_loc_red(_KERNEL_T_LOC *loc);
void    _kernel_unl_red(_KERNEL_T_LOC *loc);

#endif

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_PRC()	_kernel_ini_prc()

#define _KERNEL_ENA_INT()	_kernel_ena_int()

#define _KERNEL_ENA_INT()	_kernel_ena_int()												/**< 割り込み許可 */
#define _KERNEL_DIS_INT()	_kernel_dis_int()												/**< 割り込み禁止 */
#define _KERNEL_WAI_INT()	_kernel_wai_int()												/**< 割り込み待ち(アイドル時の処理) */


#define _KERNEL_CRE_CTX(pk_ctxcb, stksz, stk, isp, entry, par1, par2)		\
							_kernel_cre_ctx(pk_ctxcb, entry, par1, par2)
#define _KERNEL_DEL_CTX(pk_ctxcb)	_kernel_del_ctx(pk_ctxcb)
#define _KERNEL_RST_CTX(pk_ctxcb, stksz, stk, isp, entry, par1, par2)		\
							_kernel_rst_ctx(pk_ctxcb)
#define _KERNEL_STA_CTX(pk_ctxcb)	_kernel_sta_ctx(pk_ctxcb)
#define _KERNEL_SWI_CTX(pk_ctxcb_now, pk_ctxinf_nxt)						\
							_kernel_swi_ctx(pk_ctxcb_now, pk_ctxinf_nxt)



#endif	/* _KERNEL__win32__proc_h__ */


/* end of file */
