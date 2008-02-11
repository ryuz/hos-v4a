
/* Shellのようなもの (現状てきとーー) */
/* そのうちちゃんとリダイレクトとか Ctrl+C とかいろいろつける予定... (--; */


#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "system/file/file.h"
#include "system/file/stdfile.h"
#include "system/file/console.h"
#include "system/memory/memory.h"
#include "system/process/process.h"
#include "system/command/command.h"


#define SHELL_MAX_COMMAND		256
#define SHELL_MAX_HISTORY		4


typedef struct t_shell_background
{
	struct t_shell_background	*pNext;
	HANDLE						hProcess;
} T_SHELL_BACKGROUND;


typedef struct c_shell
{
	int					iCurPos;											/* カーソルの文字列上の位置 */
	int					iCurScreenX;										/* カーソルのスクリーンのX位置 */
	int					iScreenWidth;										/* スクリーンの幅 */
	int					iCommandLen;										/* コマンドの文字列長 */

	char				*pszCommanBuf;										/* コマンドラインバッファ */
	char				**ppszHistory;										/* ヒストリバッファ */
	int					iCommandBufSize;									/* コマンドバッファのサイズ */
	int					iHistoryMax;										/* ヒストリの最大個数 */
/*	int					iHistoryNum;	*/									/* ヒストリの個数 */

	int					iSimpleExec;										/* 単純実行オプション */
	T_SHELL_BACKGROUND	*pBackGround;										/* バックグランドジョブ */
} C_SHELL;


C_SHELL *Shell_Create(int iCommandBufSize, int iHistoryMax, int iSimpleExec);
void    Shell_Delete(C_SHELL *self);
int     Shell_Interactive(C_SHELL *self);
int     Shell_ExecuteScript(C_SHELL *self, const char *pszFileName);
int     Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand);
int     Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize);
void    Shell_PutChar(C_SHELL *self, int c);
void    Shell_CurRight(C_SHELL *self);
void    Shell_CurLeft(C_SHELL *self);
void    Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine);	/* ラインを置き換える */



int Shell_Main(int argc, char *argv[])
{
	C_SHELL *self;
	int		iCommandBufSize = SHELL_MAX_COMMAND;
	int 	iHistoryMax     = SHELL_MAX_HISTORY;
	int		iSimpleExec     = 0;
	int		iInteractive    = 0;
	int		iExecString     = 0;
	char	*pszScript      = NULL;
	int     iExitCode       = 0;
	int		i;
	
	
	/* オプションを解析 */
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( strcmp(&argv[i][1], "i") == 0 )							/* インタラクティブモード */
			{
				iInteractive = 1;
			}
			else if ( strcmp(&argv[i][1], "exe") == 0 )						/* 単純実行 */
			{
				iSimpleExec = 1;
			}
			else if ( strcmp(&argv[i][1], "s") == 0 && i+1 < argc )			/* 文字列実行 */
			{
				i++;
				iExecString = i;
			}
			else if ( strcmp(&argv[i][1], "buf") == 0 && i+1 < argc )		/* コマンドバッファ設定 */
			{
				i++;
				iCommandBufSize = strtol(argv[i], NULL, 0);
			}
			else if ( strcmp(&argv[i][1], "his") == 0 && i+1 < argc )		/* ヒストリ数設定 */
			{
				i++;
				iHistoryMax = strtol(argv[i], NULL, 0);
			}
		}
		else
		{
			pszScript = argv[i];
		}
	}
	
	
	/* オブジェクト生成 */
	if ( (self = Shell_Create(iCommandBufSize, iHistoryMax, iSimpleExec)) == NULL )
	{
		return 1;
	}
	

	if ( iExecString > 0 )
	{
		/* 文字列実行 */
		self->pszCommanBuf[0] = '\0';
		for ( i = iExecString; i < argc; i++ )
		{
			strcat(self->pszCommanBuf, argv[i]);
			if ( i + 1 < argc )
			{
				strcat(self->pszCommanBuf, " ");
			}
		}
			
		/* 実行 */
		iExitCode = Shell_ExecuteCommand(self, self->pszCommanBuf);
	}
	else if ( pszScript != NULL )
	{
		/* スクリプト実行 */
		iExitCode = Shell_ExecuteScript(self, pszScript);
	}
	
	/* インタラクティブモード */
	if ( iInteractive )
	{
		iExitCode = Shell_Interactive(self);
	}
	
	/* オブジェクト削除 */
	Shell_Delete(self);
	
	return iExitCode;
}


/* コンストラクタ */
C_SHELL *Shell_Create(int iCommandBufSize, int iHistoryMax, int iSimpleExec)
{
	C_SHELL *self;

	/* オブジェクト生成 */
	if ( (self = Memory_Alloc(sizeof(C_SHELL))) == NULL )
	{
		StdIo_PutString("Memory error\n");
		return NULL;
	}
	
	/* メンバ初期化 */
	self->iScreenWidth    = 80;
	self->pBackGround     = NULL;
	self->iSimpleExec     = iSimpleExec;
	self->iCommandBufSize = iCommandBufSize;
	self->iHistoryMax     = iHistoryMax;
	self->pszCommanBuf    = NULL;
	self->ppszHistory     = NULL;
	
	/* メモリ確保 */
	if ( (self->pszCommanBuf = (char *)Memory_Alloc(sizeof(char) * self->iCommandBufSize)) == NULL )
	{
		return NULL;
	}
	if ( self->iHistoryMax > 0 )
	{
		if ( (self->ppszHistory = (char **)Memory_Alloc(sizeof(char *) * self->iHistoryMax)) == NULL )
		{
			Memory_Free(self->pszCommanBuf);
			return NULL;
		}
		memset(self->ppszHistory, 0, sizeof(char *) * self->iHistoryMax);
	}
	
	return self;
}


/* デストラクタ */
void Shell_Delete(C_SHELL *self)
{
	int i;
	
	if ( self->ppszHistory != NULL )
	{
		for ( i = 0; i < self->iHistoryMax; i++ )
		{
			if ( self->ppszHistory[i] != NULL )
			{
				Memory_Free(self->ppszHistory[i]);
			}
		}
		Memory_Free(self->ppszHistory);
	}
	Memory_Free(self->pszCommanBuf);
	

	Memory_Free(self);
}


/* スクリプト実行 */
int Shell_ExecuteScript(C_SHELL *self, const char *pszFileName)
{
	HANDLE	hFile;
	int		iLen;
	
	/* ファイルオープン */
	if ( (hFile = File_Open(pszFileName, FILE_OPEN_READ | FILE_OPEN_TEXT)) == HANDLE_NULL )
	{
		StdIo_PrintFormat("open error : %s\n", pszFileName);
		return 1;
	}
	
	/* ファイルを実行 */
	while ( (iLen = File_GetString(hFile, self->pszCommanBuf, self->iCommandBufSize)) > 0 )
	{
		/* 末尾の改行削除 */
		if ( self->pszCommanBuf[iLen-1] == '\n' )
		{
			self->pszCommanBuf[iLen-1] = '\0';
		}
		
		/* 実行 */
		if ( self->pszCommanBuf[0] != '\0' && self->pszCommanBuf[0] != '#' )
		{
			Shell_ExecuteCommand(self, self->pszCommanBuf);
		}
	}
	
	/* ファイルクローズ */
	File_Close(hFile);
	
	return 0;
}



/* インタラクティブモード */
int Shell_Interactive(C_SHELL *self)
{
	T_SHELL_BACKGROUND	*pBg;
	char				*pszHisBuf;
	int 				i;
	int					j;

	for ( ; ; )
	{
		/* コマンド入力 */
		Shell_InputLine(self, self->pszCommanBuf, self->iCommandBufSize - 1);

		/* exit なら抜ける */
		if ( strcmp(self->pszCommanBuf, "exit") == 0 )
		{
			break;
		}

		/* 空行なら無視 */
		if ( self->pszCommanBuf[0] == 0 )
		{
			continue;
		}


		/* ヒストリ記憶 */
		if ( self->ppszHistory != NULL )
		{
			if ( (pszHisBuf = Memory_Alloc(strlen(self->pszCommanBuf) + 1)) != NULL )
			{
				strcpy(pszHisBuf, self->pszCommanBuf);

				/* ヒストリ重複削除 */
				for ( i = 0; i < self->iHistoryMax; i++ )
				{
					if ( strcmp(self->ppszHistory[i], self->pszCommanBuf) == 0 )
					{
						Memory_Free(self->ppszHistory[i]);
						for ( j = i; j+1 < self->iHistoryMax; j++ )
						{
							self->ppszHistory[j] = 	self->ppszHistory[j+1];
						}
						break;
					}
				}
				
				/* 古いものを削除 */
				if ( self->ppszHistory[self->iHistoryMax-1] != NULL )
				{
					Memory_Free(self->ppszHistory[self->iHistoryMax-1]);
				}
				for ( i = self->iHistoryMax-1; i > 1; i-- )
				{
					self->ppszHistory[i] = self->ppszHistory[i-1];
				}
				
				/* 追加 */
				self->ppszHistory[0] = pszHisBuf;
			}
		}

		/* コマンド実行 */
		Shell_ExecuteCommand(self, self->pszCommanBuf);
		
		/* 終了ジョブが無いかチェック */
		pBg = self->pBackGround;
		if ( pBg != NULL )
		{
		}
	}
	
	return 0;
}


int Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand)
{
	T_PROCESS_CREATE_INF Inf;
	HANDLE	hProcess;
	int 	iExitCode = 0;
	int		iBackGround = 0;
	int 	iLen;
	
	if ( self->iSimpleExec )
	{
		Command_Execute(pszCommand, &iExitCode);
	}
	else
	{
		iLen = strlen(pszCommand);
		if ( iLen > 1 && pszCommand[iLen - 1] == '&' )
		{
			((char *)pszCommand)[iLen - 1] = '\0';
			iBackGround = 1;
		}	
		
		/* プロセスの生成 */
		Inf.pszCommandLine = pszCommand;
		Inf.pszCurrentDir  = Process_GetCurrentDir(HANDLE_NULL);
		Inf.pfncEntry      = NULL;									/* 起動アドレス */
		Inf.Param          = 0;										/* ユーザーパラメータ */
		Inf.StackSize      = 2048;									/* スタックサイズ */
		Inf.Priority       = PROCESS_PRIORITY_NORMAL+1;				/* プロセス優先度 */
		Inf.hTerminal      = Process_GetTerminal(HANDLE_NULL);		/* ターミナル */
		Inf.hConsole       = Process_GetConsole(HANDLE_NULL);		/* コンソール */
		Inf.hStdIn         = Process_GetStdIn(HANDLE_NULL);			/* 標準入力 */
		Inf.hStdOut        = Process_GetStdOut(HANDLE_NULL);		/* 標準出力 */
		Inf.hStdErr        = Process_GetStdErr(HANDLE_NULL);		/* 標準エラー出力 */
		hProcess = Process_Create(&Inf);

		if ( iBackGround )
		{
			T_SHELL_BACKGROUND *pBg;
			
			/* バックグランドジョブをリストに登録 */
			pBg = (T_SHELL_BACKGROUND *)Memory_Alloc(sizeof(T_SHELL_BACKGROUND));
			pBg->hProcess = hProcess;
			if ( self->pBackGround == NULL )
			{
				self->pBackGround = pBg;
				pBg->pNext = pBg;
			}
			else
			{
				pBg->pNext = self->pBackGround->pNext;
				self->pBackGround->pNext = pBg;
			}
		}
		else
		{
			/* フォアグランドなら終わるまで待つ */
			Process_WaitExit(hProcess);
			Process_Delete(hProcess);
		}
	}
	
	return iExitCode;
}



/* １行入力 */
int Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize)
{
	int  iHistoryPos = -1;
	int  i;
	int  c;


	/* プロンプトを出す */
	StdIo_PutString("\r% ");
	self->iCurScreenX = 2;

	self->iCommandLen = 0;
	self->iCurPos     = 0;
	
	for ( ; ; )
	{
		c = StdCon_GetCh();
		
		switch ( c )
		{
		case '\n':		/* 改行なら入力完了 */
			pszBuf[self->iCommandLen] = '\0';
			StdCon_PutString("\r\n");
			return self->iCommandLen;
		
		
		case CONSOLE_KEY_BACKSPACE:	/* バックスペースなら */
			if ( self->iCurPos > 0 )
			{
				memmove(&pszBuf[self->iCurPos - 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
				self->iCurPos--;
				self->iCommandLen--;
				Shell_CurLeft(self);
				for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
				{
					Shell_PutChar(self, pszBuf[self->iCurPos + i]);
				}
				Shell_PutChar(self, ' ');
				for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
				{
					Shell_CurLeft(self);
				}
			}
			break;

		case CONSOLE_KEY_UP:	/* 上 */
			if ( iHistoryPos + 1 < self->iHistoryMax && self->ppszHistory[iHistoryPos + 1] != NULL )
			{
				iHistoryPos++;
				Shell_ReplaceLine(self, self->ppszHistory[iHistoryPos]);
			}
			break;

		case CONSOLE_KEY_DOWN:	/* 下 */
			if ( iHistoryPos > 0 )
			{
				iHistoryPos--;
				Shell_ReplaceLine(self, self->ppszHistory[iHistoryPos]);
			}
			break;
		
		case CONSOLE_KEY_RIGHT:	/* 右 */
			if ( self->iCurPos < self->iCommandLen )
			{
				Shell_CurRight(self);
				self->iCurPos++;
			}
			break;
		
		case CONSOLE_KEY_LEFT:	/* 左 */
			if ( self->iCurPos > 0 )
			{
				Shell_CurLeft(self);
				self->iCurPos--;
			}
			break;

		case '\t':				/* TAB */
			break;

		default:		/* カーソル位置に文字設定 */
			if ( c >= 0x20 && c <= 255 )
			{
				if ( self->iCurPos < iBufSize - 1 )
				{
					memmove(&pszBuf[self->iCurPos + 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
					pszBuf[self->iCurPos++] = (char)c;
					self->iCommandLen++;
					for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
					{
						Shell_PutChar(self, pszBuf[self->iCurPos + i - 1]);
					}
					for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
					{
						Shell_CurLeft(self);
					}
				}
				else
				{
					StdCon_PutChar('\a');
				}
			}
			break;
		}
	}
}



/* スクリーンに１文字出力 */
void Shell_PutChar(C_SHELL *self, int c)
{
	StdCon_PutChar(c);	
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		StdCon_PutString("\n");
	}	
}

/* カーソル右移動 */
void Shell_CurRight(C_SHELL *self)
{
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		StdCon_PutString("\n");
	}
	else
	{
		StdCon_PutString("\x1b[1C");		/* カーソル右 */
	}
}

/* カーソル左移動 */
void Shell_CurLeft(C_SHELL *self)
{
	if ( self->iCurScreenX == 0 )
	{
		self->iCurScreenX = self->iScreenWidth - 1;
		StdCon_PutString("\x1b[1A\x1b[80C");
	}
	else
	{
		self->iCurScreenX--;
		StdCon_PutString("\x1b[1D");		/* カーソル左 */
	}
}

/* ラインを置き換える */
void Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine)
{
	int iOldLen;
	int i;
	
	/* 前回の長さを保存 */
	iOldLen = self->iCommandLen;
	
	/* 行先頭まで移動 */
	while ( self->iCurPos > 0 )
	{
		Shell_CurLeft(self);
		self->iCurPos--;
	}
	
	/* 新しい文字列を出力 */
	for ( i = 0; pszNewLine[i] != '\0'; i++ )
	{
		Shell_PutChar(self, pszNewLine[i]);
		self->pszCommanBuf[i] = pszNewLine[i];
		self->iCurPos++;
	}
	self->iCommandLen = i;
	
	/* 末尾削除 */
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_PutChar(self, ' ');
	}
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_CurLeft(self);
	}	
}


/* end of file */
