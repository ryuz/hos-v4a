/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/* ITRONをマイクロカーネルとして、依存性はこのモジュールで極力隠蔽する */
/* いわゆるシステムモード(デバイスドライバなど)のみに許すAPIを定義する */
/* ユーザーモード用APIは別途作成予定 */


#ifndef __HOS__sysapi_h__
#define __HOS__sysapi_h__


#include "system/type/type.h"
#include "library/container/memheap/memheap.h"


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
void           SysApi_Initialize(void *pMem, MEMSIZE MemSize, MEMSIZE MemAlign, void *pIoMem, MEMSIZE IoMemSize, MEMSIZE IoMemAlign);
																			/**< システムの初期化処理 */

/* システム状態取得 */
int            SysCtx_IsIsr(void);											/**< ISRコンテキストかどうか調べる(システム用) */

/* システムロック */
void           SysLoc_Lock(void);											/**< システム全体のロック(システム用) */
void           SysLoc_Unlock(void);											/**< システム全体のロック解除(システム用) */

/* システム用メモリ制御API */
void          *SysMem_Alloc(MEMSIZE Size);									/**< メモリの割り当て(システム用) */
void          *SysMem_ReAlloc(void *pMem, MEMSIZE Size);					/**< メモリの再割り当て(システム用) */
void           SysMem_Free(void *pMem);										/**< メモリの返却(システム用) */
MEMSIZE        SysMem_GetSize(void *pMem);									/**< メモリのサイズ取得(システム用) */
C_MEMHEAP      *SysMem_GetMemHeap(void);									/**< メモリインターフェースの取得(システム用) */


/* システム用割込み制御API */
void           SysInt_Enable(int iIntNum);									/**< 割込み許可(システム用) */
void           SysInt_Disable(int iIntNum);									/**< 割込み禁止(システム用) */
void           SysInt_Clear(int iIntNum);									/**< 割込み要因クリア(システム用) */
void           SysInt_SetIntTime(int iIntNum, SYSTIM_CPUTIME Time);			/**< 割込み計測タイマを初期化 */
SYSTIM_CPUTIME SysInt_GetIntTime(int iIntNum);								/**< 割込み計測タイマを取得 */

/* 割込みサービスルーチン制御API */
SYSISR_HANDLE  SysIsr_Create(int iIntNum, void (*pfncIsr)(VPARAM Param), VPARAM Param);
void           SysIsr_Delete(SYSISR_HANDLE hIsr);

/* システム用プロセス制御API */
SYSPRC_HANDLE  SysPrc_Create(void (*pfncEntry)(void), VPARAM Param, void *pStack, MEMSIZE StackSize, int Priority, int iAttr);
																			/**< プロセス生成(システム用) */
void           SysPrc_Delete(SYSPRC_HANDLE hPrc);							/**< プロセス削除(システム用) */
VPARAM         SysPrc_GetParam(SYSPRC_HANDLE hPrc);							/**< プロセスのパラメータ取得(システム用) */

void           SysPrc_Start(SYSPRC_HANDLE hPrc);							/**< プロセス開始(システム用) */
void           SysPrc_Terminate(SYSPRC_HANDLE hPrc);						/**< プロセス終了(システム用) */
void           SysPrc_Suspend(SYSPRC_HANDLE hPrc);							/**< プロセス強制停止(システム用) */			
void           SysPrc_Resume(SYSPRC_HANDLE hPrc);							/**< プロセス強制停止解除(システム用) */	
void           SysPrc_SendSignal(SYSPRC_HANDLE hPrc);						/**< プロセスへのシグナル送信(システム用) */
void           SysPrc_SetSignalHandler(SYSPRC_HANDLE hPrc, void (*pfncHanler)(void));
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
int            SysMtx_RefStatus(SYSMTX_HANDLE hMtx);						/**< ミューテックスの状態を取得(システム用) */

/* システム用イベント制御API */
SYSEVT_HANDLE  SysEvt_Create(int iAttr);									/**< イベント生成(システム用) */
void           SysEvt_Delete(SYSEVT_HANDLE hEvt);							/**< イベント削除(システム用) */
void           SysEvt_Wait(SYSEVT_HANDLE hEvt);								/**< イベント待ち(システム用) */
void           SysEvt_Set(SYSEVT_HANDLE hEvt);								/**< イベントセット(システム用) */
void           SysEvt_Clear(SYSEVT_HANDLE hEvt);							/**< イベントクリア(システム用) */
int            SysEvt_RefStatus(SYSEVT_HANDLE hEvt);						/**< イベントの状態を取得(システム用) */

/* 時間管理 */
void           SysTim_Signal(unsigned long ulTic);							/**< システムタイムにティックを与える(システム用) */
void           SysTim_Wait(unsigned long ulTime);							/**< 時間待ち(システム用) */
TIME           SysTim_GetCurrentTime(void);									/**< 現在の時刻取得(システム用) */
SYSTIM_SYSTIME SysTim_GetSystemTime(void);									/**< 現在のシステム時刻取得(システム用) */
unsigned long  SysTim_SysTimeToSecond(SYSTIM_SYSTIME SysTime);				/**< システム時刻を秒に換算(システム用) */
unsigned long  SysTim_SysTimeToNanosecond(SYSTIM_SYSTIME SysTime);			/**< システム時刻をナノ秒に換算(システム用) */
SYSTIM_CPUTIME SysTim_GetCpuTime(void);										/**< 現在のCPU時刻取得(システム用) */
unsigned long  SysTim_CpuTimeToSecond(SYSTIM_CPUTIME CpuTime);				/**< CPU時刻を秒に換算(システム用) */
unsigned long  SysTim_CpuTimeToNanosecond(SYSTIM_CPUTIME CpuTime);			/**< CPU時刻をナノ秒に換算(システム用) */


/* I/Oアクセス */
#ifdef __HOSAPLFW_IOMAPEDIO
/* I/OマップドI/O  */
unsigned char  SysIo_InPortB(void *Port);									/**< I/Oポートからバイト(8bit)入力 */
unsigned short SysIo_InPortH(void *Port);									/**< I/Oポートからハーフワード(16bit)入力 */
unsigned long  SysIo_InPortW(void *Port);									/**< I/Oポートからワード(32bit)入力 */
unsigned char  SysIo_OutPortB(void *Port, unsigned char Data);				/**< I/Oポートへバイト(8bit)出力 */
unsigned short SysIo_OutPortH(void *Port, unsigned short Data);				/**< I/Oポートへハーフワード(16bit)出力 */
unsigned long  SysIo_OutPortW(void *Port, unsigned long Data);				/**< I/Oポートへワード(32bit)出力 */
unsigned char  SysIo_AndPortB(void *Port, unsigned char Data);				/**< I/Oポートをバイト(8bit)単位で論理積 */
unsigned short SysIo_AndPortH(void *Port, unsigned short Data); 		 	/**< I/Oポートをハーフワード(16bit)単位で論理積 */
unsigned long  SysIo_AndPortW(void *Port, unsigned long Data);  		 	/**< I/Oポートをワード(32bit)単位で論理積 */
unsigned char  SysIo_OrPortB(void *Port, unsigned char Data);				/**< I/Oポートをバイト(8bit)単位で論理和 */
unsigned short SysIo_OrPortH(void *Port, unsigned short Data);				/**< I/Oポートをハーフワード(16bit)単位で論理和 */
unsigned long  SysIo_OrPortW(void *Port, unsigned long Data);				/**< I/Oポートをワード(32bit)単位で論理和 */
unsigned char  SysIo_XorPortB(void *Port, unsigned char Data);				/**< I/Oポートをバイト(8bit)単位で排他的論理和 */
unsigned short SysIo_XorPortH(void *Port, unsigned short Data);				/**< I/Oポートをハーフワード(16bit)単位で排他的論理和 */
unsigned long  SysIo_XorPortW(void *Port, unsigned long Data);				/**< I/Oポートをワード(32bit)単位で排他的論理和 */
#else
/* メモリマップドI/O */
#define        SysIo_InPortB(Port)			(*(volatile unsigned char *)(Port))
#define        SysIo_InPortH(Port)			(*(volatile unsigned short *)(Port))
#define        SysIo_InPortW(Port)			(*(volatile unsigned long *)(Port))
#define        SysIo_OutPortB(Port, Data)	(*(volatile unsigned char *)(Port) = (unsigned char)(Data))
#define        SysIo_OutPortH(Port, Data)	(*(volatile unsigned short *)(Port) = (unsigned short)(Data))
#define        SysIo_OutPortW(Port, Data)	(*(volatile unsigned long *)(Port) = (unsigned long)(Data))
#define        SysIo_AndPortB(Port, Data)	(*(volatile unsigned char *)(Port) &= (unsigned char)(Data))
#define        SysIo_AndPortH(Port, Data)	(*(volatile unsigned short *)(Port) &= (unsigned short)(Data))
#define        SysIo_AndPortW(Port, Data)	(*(volatile unsigned long *)(Port) &= (unsigned long)(Data))
#define        SysIo_OrPortB(Port, Data)	(*(volatile unsigned char *)(Port) |= (unsigned char)(Data))
#define        SysIo_OrPortH(Port, Data)	(*(volatile unsigned short *)(Port) |= (unsigned short)(Data))
#define        SysIo_OrPortW(Port, Data)	(*(volatile unsigned long *)(Port) |= (unsigned long)(Data))
#define        SysIo_XorPortB(Port, Data)	(*(volatile unsigned char *)(Port) ^= (unsigned char)(Data))
#define        SysIo_XorPortH(Port, Data)	(*(volatile unsigned short *)(Port) ^= (unsigned short)(Data))
#define        SysIo_XorPortW(Port, Data)	(*(volatile unsigned long *)(Port) ^= (unsigned long)(Data))
#endif

/* システムによっては特定アドレス範囲にしかDMAが使えなかったり、非キャッシュ領域が必要なので別途設ける */
void          *SysIo_AllocIoMem(MEMSIZE Size);								/**< I/O操作に適したメモリの割り当て(システム用) */
void           SysIo_FreeIoMem(void *pMem);									/**< I/O操作に適したメモリの返却(システム用) */


#ifdef __cplusplus
}
#endif


#endif

