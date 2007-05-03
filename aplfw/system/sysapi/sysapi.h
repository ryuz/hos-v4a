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



/* システム用プロセスハンドル */
#define SYSPRC_HANDLE_NULL			(0)
typedef void* SYSPRC_HANDLE;

/* システム用ミューテックスハンドル */
#define SYSMTX_HANDLE_NULL			(0)
typedef void* SYSMTX_HANDLE;

/* システム用イベントハンドル */
#define SYSEVT_HANDLE_NULL			(0)
typedef void* SYSEVT_HANDLE;

/* システム用割り込みサービスルーチンハンドル */
#define SYSISR_HANDLE_NULL			(0)
typedef void* SYSISR_HANDLE;


#ifdef __cplusplus
extern "C" {
#endif

/* 初期化 */
void           SysApi_Initialize(void *pMem, MEMSIZE lSize);	/* システムの初期化処理 */

/* システムロック */
void           SysLoc_Lock(void);								/* システム全体のロック */
void           SysLok_Unlock(void);								/* システム全体のロック解除 */

/* システム用メモリ制御API */
void          *SysMem_Alloc(MEMSIZE Size);						/* システムメモリの割り当て */
void          *SysMem_ReAlloc(void *pMem, MEMSIZE Size);		/* システムメモリの再割り当て */
void           SysMem_Free(void *pMem);							/* システムメモリの返却 */
MEMSIZE        SysMem_GetSize(void *pMem);						/* システムメモリのサイズ取得 */
const T_MEMIF *SysMem_GetMemIf(void);							/* メモリインターフェースの取得 */

/* システム用割り込み制御API */
void           SysInt_Enable(int iIntNum);
void           SysInt_Disable(int iIntNum);
void           SysInt_Clear(int iIntNum);

/* 割り込みサービスルーチン制御API */
SYSISR_HANDLE  SysIsr_Create(int iIntNum, void (*pfncIsr)(VPARAM Param), VPARAM Param);
void           SysIsr_Delete(SYSISR_HANDLE hIsr);


/* システム用プロセス制御API */
SYSPRC_HANDLE  SysPrc_Create(void (*pfncEntry)(VPARAM Param), VPARAM Param, MEMSIZE StackSize, int Priority);
void           SysPrc_Delete(SYSPRC_HANDLE hPrc);
void           SysPrc_Exit(void);
void           SysPrc_Start(SYSPRC_HANDLE hPrc);
void           SysPrc_Wait(SYSPRC_HANDLE hPrc);
SYSPRC_HANDLE  SysPrc_GetCurrentHandle(void);

/* システム用ミューテックス制御API */
SYSMTX_HANDLE  SysMtx_Create(void);							/* システム用ミューテックス生成 */
void           SysMtx_Delete(SYSMTX_HANDLE hMtx);			/* システム用ミューテックス削除 */
void           SysMtx_Lock(SYSMTX_HANDLE hMtx);				/* システム用ミューテックスロック*/
void           SysMtx_Unlock(SYSMTX_HANDLE hMtx);			/* システム用ミューテックスロック解除*/

/* システム用イベント制御API */
SYSEVT_HANDLE  SysEvt_Create(void);							/* システム用イベント生成 */
void           SysEvt_Delete(SYSEVT_HANDLE hEvt);			/* システム用イベント削除 */
void           SysEvt_Wait(SYSEVT_HANDLE hEvt);				/* システム用イベント待ち*/
void           SysEvt_Set(SYSEVT_HANDLE hEvt);				/* システム用イベントセット */
void           SysEvt_Clear(SYSEVT_HANDLE hEvt);			/* システム用イベントクリア */

/* 時間管理 */
void           SysTim_Wait(unsigned long ulTime);			/* 時間待ち */
TIME           SysTim_GetCurrentTime(void);					/*  */


#ifdef __cplusplus
}
#endif


#endif

