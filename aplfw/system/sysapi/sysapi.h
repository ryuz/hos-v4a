/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/* ITRONをマイクロカーネルとして、依存性はこのモジュールで極力隠蔽する */
/* いわゆるシステムモード(デバドラとか)のみに許すAPIを定義する */
/* ユーザーモード用APIは別途作成予定 */


#ifndef __HOS__sysapi_h__
#define __HOS__sysapi_h__


#include "system/type/type.h"
#include "library/container/memif/memif.h"


/* プロセスハンドル(システム用) */
#define SYSPRC_HANDLE_NULL			(0)
typedef void* SYSPRC_HANDLE;

/* ミューテックスハンドル(システム用) */
#define SYSMTX_HANDLE_NULL			(0)
typedef void* SYSMTX_HANDLE;

/* イベントハンドル(システム用) */
#define SYSEVT_HANDLE_NULL			(0)
typedef void* SYSEVT_HANDLE;

/* 割込みサービスルーチンハンドル(システム用) */
#define SYSISR_HANDLE_NULL			(0)
typedef void* SYSISR_HANDLE;

/* プロセス属性(システム用) */
#define	SYSPRC_ATTR_NORMAL			0x00

/* イベント属性(システム用) */
#define	SYSEVT_ATTR_NORMAL			0x00
#define	SYSEVT_ATTR_AUTOCLEAR		0x01

/* ミューテックス属性(システム用) */
#define	SYSMTX_ATTR_NORMAL			0x00

/* 時刻管理用 */
typedef _HOS_UINT64					SYSTIM_SYSTIME;
typedef _HOS_UINT64					SYSTIM_CPUTIME;


#ifdef __cplusplus
extern "C" {
#endif

/* 初期化 */
void           SysApi_Initialize(void *pMem, MEMSIZE lSize);				/**< システムの初期化処理 */

/* システム状態取得 */
int            SysCtx_IsIsr(void);											/**< ISRコンテキストかどうか調べる(システム用) */

/* システムロック */
void           SysLoc_Lock(void);											/**< システム全体のロック(システム用) */
void           SysLok_Unlock(void);											/**< システム全体のロック解除(システム用) */

/* システム用メモリ制御API */
void          *SysMem_Alloc(MEMSIZE Size);									/**< メモリの割り当て(システム用) */
void          *SysMem_ReAlloc(void *pMem, MEMSIZE Size);					/**< メモリの再割り当て(システム用) */
void           SysMem_Free(void *pMem);										/**< メモリの返却(システム用) */
MEMSIZE        SysMem_GetSize(void *pMem);									/**< メモリのサイズ取得(システム用) */
C_MEMIF       *SysMem_GetMemIf(void);										/**< メモリインターフェースの取得(システム用) */

/* システム用割り込み制御API */
void           SysInt_Enable(int iIntNum);									/**< 割込み許可(システム用) */
void           SysInt_Disable(int iIntNum);									/**< 割込み禁止(システム用) */
void           SysInt_Clear(int iIntNum);									/**< 割込み要因クリア(システム用) */
void           SysInt_SetIntTime(int iIntNum, SYSTIM_CPUTIME Time);			/**< 割込み計測タイマを初期化 */
SYSTIM_CPUTIME SysInt_GetIntTime(int iIntNum);								/**< 割込み計測タイマを取得 */

/* 割り込みサービスルーチン制御API */
SYSISR_HANDLE  SysIsr_Create(int iIntNum, void (*pfncIsr)(VPARAM Param), VPARAM Param);
void           SysIsr_Delete(SYSISR_HANDLE hIsr);

/* システム用プロセス制御API */
SYSPRC_HANDLE  SysPrc_Create(void (*pfncEntry)(VPARAM Param), VPARAM Param, void *pStack, MEMSIZE StackSize, int Priority, int iAttr);
																			/**< プロセス生成(システム用) */
void           SysPrc_Delete(SYSPRC_HANDLE hPrc);							/**< プロセス削除(システム用) */
VPARAM         SysPrc_GetParam(SYSPRC_HANDLE hPrc);							/**< プロセスのパラメータ取得(システム用) */

void           SysPrc_Terminate(SYSPRC_HANDLE hPrc);						/**< プロセス終了(システム用) */
void           SysPrc_Suspend(SYSPRC_HANDLE hPrc);							/**< プロセス強制停止(システム用) */			
void           SysPrc_Resume(SYSPRC_HANDLE hPrc);							/**< プロセス強制停止解除(システム用) */	
void           SysPrc_Signal(SYSPRC_HANDLE hPrc, VPARAM Signal);			/**< プロセスへのシグナル送信(システム用) */
void           SysPrc_SetSignalHandler(SYSPRC_HANDLE hPrc, void (*pfncHanler)(VPARAM Signal));
																			/**< プロセスへのシグナルハンドラ登録(システム用) */
SYSPRC_HANDLE  SysPrc_GetCurrentHandle(void);								/**< 現在のプロセスの取得(システム用) */
void           SysPrc_SetExecTime(SYSPRC_HANDLE hPrc, SYSTIM_CPUTIME Time);	/**< プロセス実行時間計測タイマを初期化 */
SYSTIM_CPUTIME SysPrc_GetExecTime(SYSPRC_HANDLE hPrc);						/**< プロセス実行時間計測タイマを取得 */

/* システム用ミューテックス制御API */
SYSMTX_HANDLE  SysMtx_Create(int iAttr);									/**< ミューテックス生成(システム用) */
void           SysMtx_Delete(SYSMTX_HANDLE hMtx);							/**< ミューテックス削除(システム用) */
int            SysMtx_PolingLock(SYSMTX_HANDLE hMtx);						/**< ミューテックスポーリングロック(システム用) */
void           SysMtx_Lock(SYSMTX_HANDLE hMtx);								/**< ミューテックスロック(システム用) */
void           SysMtx_Unlock(SYSMTX_HANDLE hMtx);							/**< ミューテックスロック解除(システム用) */
int            SysMtx_RefStatus(SYSMTX_HANDLE hMtx);						/**< イベントの状態を取得(システム用) */

/* システム用イベント制御API */
SYSEVT_HANDLE  SysEvt_Create(int iAttr);									/**< イベント生成(システム用) */
void           SysEvt_Delete(SYSEVT_HANDLE hEvt);							/**< イベント削除(システム用) */
void           SysEvt_Wait(SYSEVT_HANDLE hEvt);								/**< イベント待ち(システム用) */
void           SysEvt_Set(SYSEVT_HANDLE hEvt);								/**< イベントセット(システム用) */
void           SysEvt_Clear(SYSEVT_HANDLE hEvt);							/**< イベントクリア(システム用) */
int            SysEvt_RefStatus(SYSEVT_HANDLE hEvt);						/**< イベントの状態を取得(システム用) */

/* 時間管理 */
void           SysTim_Wait(unsigned long ulTime);							/**< 時間待ち(システム用) */
TIME           SysTim_GetCurrentTime(void);									/**< 現在の時刻取得(システム用) */
SYSTIM_SYSTIME SysTim_GetSystemTime(void);									/**< 現在のシステム時刻取得(システム用) */
SYSTIM_CPUTIME SysTim_GetCpuTime(void);										/**< 現在のCPU時刻取得(システム用) */
unsigned long  SysTim_CpuTimeToMillisecond(SYSTIM_CPUTIME CpuTime);			/**< CPU時刻をミリ秒に換算(システム用) */
unsigned long  SysTim_CpuTimeToNanosecond(SYSTIM_CPUTIME CpuTime);			/**< CPU時刻をナノ秒に換算(システム用) */

/* I/Oアクセス */
#ifdef __HOSAPLFW_IOMAPEDIO
/* I/OマップドI/O  */
unsigned char  SysIo_OutPortB(unsigned int Port, unsigned char Data);
unsigned short SysIo_OutPortH(unsigned int Port, unsigned short Data);
unsigned long  SysIo_OutPortW(unsigned int Port, unsigned long Data);
unsigned char  SysIo_InPortB(unsigned int Port);
unsigned short SysIo_InPortH(unsigned int Port);
unsigned long  SysIo_InPortW(unsigned int Port);
#else
/* メモリマップドI/O */
#define        SysIo_OutPortB(Port, Data)	(*(volatile unsigned char *)(Port) = (unsigned char)(Data))
#define        SysIo_OutPortH(Port, Data)	(*(volatile unsigned short *)(Port) = (unsigned short)(Data))
#define        SysIo_OutPortW(Port, Data)	(*(volatile unsigned long *)(Port) = (unsigned long)(Data))
#define        SysIo_InPortB(Port)			(*(volatile unsigned char *)(Port))
#define        SysIo_InPortH(Port)			(*(volatile unsigned short *)(Port))
#define        SysIo_InPortW(Port)			(*(volatile unsigned long *)(Port))
#endif


#ifdef __cplusplus
}
#endif


#endif

