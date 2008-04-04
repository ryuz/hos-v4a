/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell.h
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__shell_local_h__
#define __HOS__shell_local_h__


#include "hosaplfw.h"


#define SHELL_MAX_COMMAND		256			/**< デフォルトのコマンドラン文字数 */
#define SHELL_MAX_HISTORY		8			/**< デフォルトのヒストリ記憶数 */



/** バックグランドジョブ管理構造体 */
typedef struct t_shell_background
{
	struct t_shell_background	*pNext;
	HANDLE						hProcess;
} T_SHELL_BACKGROUND;


/** シェルクラス */
typedef struct c_shell
{
	int					iCurPos;			/**< カーソルの文字列上の位置 */
	int					iCurScreenX;		/**< カーソルのスクリーンのX位置 */
	int					iScreenWidth;		/**< スクリーンの幅 */
	int					iCommandLen;		/**< コマンドの文字列長 */

	char				*pszCommanBuf;		/**< コマンドラインバッファ */
	char				**ppszHistory;		/**< ヒストリバッファ */
	int					iCommandBufSize;	/**< コマンドバッファのサイズ */
	int					iHistoryMax;		/**< ヒストリの最大個数 */

	char				ExecSimple;			/**< 単純実行オプション */
	char				ExecTime;			/**< 実行時間計測オプション */

	T_SHELL_BACKGROUND	*pBackGround;		/**< バックグランドプロセスリスト */
} C_SHELL;


#ifdef __cplusplus
extern "C" {
#endif

C_SHELL *Shell_Create(int iCommandBufSize, int iHistoryMax, int iExecSimple, int iExecTime);	/**< 生成 */
void    Shell_Delete(C_SHELL *self);															/**< 削除 */
int     Shell_Interactive(C_SHELL *self);														/**< インタラクティブモード */
int     Shell_ExecuteScript(C_SHELL *self, const char *pszFileName);							/**< スクリプト実行 */
int     Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand);							/**< コマンド実行 */
void	Shell_CheckBackGround(C_SHELL *self);													/**< バックグランドで終わったものが無いかチェック */
int     Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize);							/**< １ライン入力 */
void    Shell_PutChar(C_SHELL *self, int c);													/**< １文字出力 */
void    Shell_CurRight(C_SHELL *self);															/**< カーソル右移動 */
void    Shell_CurLeft(C_SHELL *self);															/**< カーソル左移動 */
void    Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine);								/**< ラインを置き換える */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__shell_local_h__ */


/* end of file */
