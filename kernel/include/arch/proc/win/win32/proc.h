/**
 *  Hyper Operating System V4 Advance
 *
 * @file  proc.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}%en{Processor archtecture}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__win32__proc_h__
#define _KERNEL__win32__proc_h__


/** %jp{Windows ヘッダファイルの読みこみ} */
#define SIZE	WIN_SIZE
#define BOOL	WIN_BOOL
#include <windows.h>
#include <tchar.h>
#undef	SIZE
#undef	BOOL

#include <setjmp.h>



/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	FP					entry;				/**< %jp{エントリーアドレス} */
	VP_INT				exinf1;				/**< %jp{パラメータ１} */
	VP_INT				exinf2;				/**< %jp{パラメータ２} */
	jmp_buf				jmpenv;				/**< %jp{コンテキストリセット用のlongjmpデータ} */

	BOOL				blInterrupt;		/**< %jp{割込み処理中フラグ} */
	HANDLE				hEvent;				/**< %jp{イベントハンドル} */
	HANDLE				hThread;			/**< %jp{スレッドハンドル} */
	DWORD				dwThreadId;			/**< %jp{スレッドID} */
	HANDLE				hIntEvent;			/**< %jp{イベントハンドル} */
	HANDLE				hIntThread;			/**< %jp{スレッドハンドル} */
	DWORD				dwIntThreadId;		/**< %jp{スレッドID} */
} _KERNEL_T_CTXCB;


/** %jp{割込みコンテキスト制御ブロック} */
typedef struct _kernel_t_ictxcb
{
	_KERNEL_T_CTXCB		*runctxcb;			/**< %jp{実行中のコンテキスト} */
	INHNO				inhno;

	CRITICAL_SECTION	CriticalSection;	/**< %jp{クリティカルセクション} */
	HANDLE				hSemIntLock;		/**< %jp{システムの排他制御用セマフォ} */
	volatile BOOL		blIntCtx;			/**< %jp{割込み処理中フラグ} */
	volatile BOOL		blDisInt;			/**< %jp{割込み禁止フラグ} */
	DWORD				dwPrimaryThreadId;	/**< %jp{プライマリスレッドID} */
} _KERNEL_T_ICTXCB;


extern _KERNEL_T_ICTXCB _kernel_ictxcb;		/**< %jp{割込みコンテキスト制御ブロック} */



#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ini_prc(void);																/**< %jp{アーキテクチャ固有の初期化} */

void    _kernel_ena_int(void);																/**< %jp{割込み許可} */
void    _kernel_dis_int(void);																/**< %jp{割込み禁止} */
void    _kernel_wai_int(void);																/**< %jp{割込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *ctxcb, FP entry, VP_INT exinf1, VP_INT exinf2);	/**< %jp{実行コンテキストの作成} */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *ctxcb);											/**< %jp{実行コンテキストの削除} */
void    _kernel_rst_ctx(_KERNEL_T_CTXCB *ctxcb);											/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *ctxcb);											/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *ctxcb_now, _KERNEL_T_CTXCB *ctxinf_nxt);			/**< %jp{実行コンテキストの切替} */

void     vsig_int(int inhno);																/**< %jp{擬似割込みサポートAPI} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_PRC()				_kernel_ini_prc()

#define _KERNEL_INI_INT(stksz, stk)		do {} while(0)
#define _KERNEL_ENA_INT()				_kernel_ena_int()									/**< %jp{割込み許可} */
#define _KERNEL_DIS_INT()				_kernel_dis_int()									/**< %jp{割込み禁止} */
#define _KERNEL_WAI_INT()				_kernel_wai_int()									/**< %jp{割込み待ち(アイドル時の処理)} */


#define _KERNEL_CRE_CTX(ctxcb, stksz, stk, isp, entry, par1, par2)		\
							_kernel_cre_ctx(ctxcb, entry, par1, par2)
#define _KERNEL_DEL_CTX(ctxcb)	_kernel_del_ctx(ctxcb)
#define _KERNEL_RST_CTX(ctxcb, stksz, stk, isp, entry, par1, par2)		\
							_kernel_rst_ctx(ctxcb)
#define _KERNEL_STA_CTX(ctxcb)	_kernel_sta_ctx(ctxcb)
#define _KERNEL_SWI_CTX(ctxcb_now, ctxcb_nxt)							\
							_kernel_swi_ctx(ctxcb_now, ctxcb_nxt)



#endif	/* _KERNEL__win32__proc_h__ */


/* end of file */
