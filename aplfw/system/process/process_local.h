/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__process_local_h__
#define __HOS__process_local_h__


#include "process.h"
#include "system/handle/handleobj_local.h"
#include "system/sysapi/sysapi.h"


/* プロセスオブジェクト基本クラス定義 */
typedef struct c_process
{
	C_HANDLEOBJ			HandleObj;						/**< ハンドルオブジェクトを継承 */

	HANDLE				*pHandleList;					/**< 所有するハンドルのリスト(終了時に開放) */
	
	struct c_process	*pNext;							/*< 次のプロセス */
	struct c_process	*pPrev;							/*< 前のプロセス */
	
	SYSPRC_HANDLE		hPrc;							/**< プロセスハンドル */
	SYSEVT_HANDLE		hEvt;							/**< 待ち合わせ用イベント */
	int					iExitCode;						/**< 終了コード */
	void				*pStack;						/**< スタック領域のメモリ */

	char				*pszCommandLine;				/**< 実行するコマンド */
	char				*pszCurrentDir;					/**< カレントディレクトリ */

	int					(*pfncEntry)(VPARAM Param);		/**< 起動アドレス */
	VPARAM				Param;							/**< ユーザーパラメータ */

	MEMSIZE				StackSize;						/**< スタックサイズ */
	int					Priority;						/**< プロセス優先度 */
	HANDLE				hTerminal;						/**< ターミナル */
	HANDLE				hConsole;						/**< コンソール */
	HANDLE				hStdIn;							/**< 標準入力 */
	HANDLE				hStdOut;						/**< 標準出力 */
	HANDLE				hStdErr;						/**< 標準エラー出力 */
} C_PROCESS;


#ifdef __cplusplus
extern "C" {
#endif

PROCESS_ERR Process_Constructor(C_PROCESS *self, const T_HANDLEOBJ_METHODS *pMethods, const T_PROCESS_CREATE_INF *pInf);		/**< コンストラクタ */
void        Process_Destructor(C_PROCESS *self);																				/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__process_local_h__ */



/* end of file */
