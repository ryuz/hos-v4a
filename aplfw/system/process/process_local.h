/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__process_local_h__
#define __HOS__process_local_h__


#include "process.h"
#include "system/handle/handle_local.h"
#include "system/sysapi/sysapi.h"


/* プロセスオブジェクトクラス定義 */
typedef struct c_processobj
{
	C_OWNEROBJ			OwnerObj;						/**< 親クラスを継承 */
	
	unsigned long		ulProcessId;					/**< プロセスID */
	
	SYSPRC_HANDLE		hPrc;							/**< プロセスハンドル */
	SYSEVT_HANDLE		hEvt;							/**< 待ち合わせ用イベント */
	int					iExitCode;						/**< 終了コード */
	void				*pStack;						/**< スタック領域のメモリ */
	
	char				*pszCommandLine;				/**< 実行中のコマンド */
	char				*pszCurrentDir;					/**< カレントディレクトリ */

	int					(*pfncEntry)(VPARAM Param);		/**< 起動アドレス */
	VPARAM				Param;							/**< ユーザーパラメータ */
	C_ASSOC				*pEnv;							/**< 環境変数用 */
	
	void				(*pfncSignalProc)(int iSignal);	/**< シグナル受信プロシージャ */
	int					iSignal;						/**< ユーザーパラメータ */

	MEMSIZE				StackSize;						/**< スタックサイズ */
	int					Priority;						/**< プロセス優先度 */
	char				SysMode;						/**< システムモード */
	char				Exit;							/**< 終了フラグ */
	
	HANDLE				hTerminal;						/**< ターミナル */
	HANDLE				hConsole;						/**< コンソール */
	HANDLE				hStdIn;							/**< 標準入力 */
	HANDLE				hStdOut;						/**< 標準出力 */
	HANDLE				hStdErr;						/**< 標準エラー出力 */
} C_PROCESSOBJ;


/* プロセスポインタクラス定義 */
typedef C_POINTEROBJ					C_PROCESSPTR;


extern const T_OBJECT_METHODS ProcessObj_Methods;
extern const T_OBJECT_METHODS ProcessPtr_Methods;


#ifdef __cplusplus
extern "C" {
#endif

C_PROCESSOBJ *Process_GetCurrentProcessObj(void);											/**< 現在のプロセスオブジェクト取得 */	
PROCESS_ERR   Process_Attach(C_PROCESSOBJ *self, const T_PROCESS_CREATE_INF *pInf);			/**< 既存プロセスをアタッチ */

HANDLE        ProcessObj_Create(const T_PROCESS_CREATE_INF *pInf);																/**< 生成 */
void          ProcessObj_Delete(HANDLE handle);																					/**< 削除 */
PROCESS_ERR   ProcessObj_Constructor(C_PROCESSOBJ *self, const T_OBJECT_METHODS *pMethods, const T_PROCESS_CREATE_INF *pInf);	/**< コンストラクタ */
void          ProcessObj_Destructor(C_PROCESSOBJ *self);																		/**< デストラクタ */

/* プロセスポインタクラス(PointerObjをそのまま継承) */
#define ProcessPtr_Create(pProcessObj)					PointerObj_Create(&ProcessPtr_Methods, (C_TARGETOBJ *)(pProcessObj))
#define ProcessPtr_Delete								PointerObj_Delete
#define ProcessPtr_Constructor(self, methods, owner)	PointerObj_Constructor((C_POINTEROBJ *)(self), methods, (C_TARGETOBJ *)(owner))
#define ProcessPtr_Destructor							PointerObj_Destructor
#define ProcessPtr_GetProcessObj(self)					((C_PROCESSOBJ *)PointerObj_GetTargetObj(self))

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__process_local_h__ */



/* end of file */
