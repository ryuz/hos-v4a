
/* Shellのようなもの (現状てきとーー) */
/* そのうちちゃんとリダイレクトとか Ctrl+C とかいろいろつける予定... (--; */


#include <string.h>
#include "shell.h"
#include "system/file/file.h"
#include "system/file/stdfile.h"
#include "system/file/console.h"
#include "system/memory/memory.h"
#include "system/process/process.h"
#include "system/command/command.h"


#define SHELL_MAX_COMMAND		128
#define SHELL_MAX_HISTORY		8


typedef struct c_shell
{
	int		iCurPos;											/* カーソルの文字列上の位置 */
	int		iCurScreenX;										/* カーソルのスクリーンのX位置 */
	int		iScreenWidth;										/* スクリーンの幅 */
	int		iCommandLen;										/* コマンドの文字列長 */
	char	szCommanBuf[SHELL_MAX_COMMAND];						/* コマンドラインバッファ */
	char	szHistory[SHELL_MAX_HISTORY][SHELL_MAX_COMMAND];	/* ヒストリバッファ */
	int		iHistoryNum;
} C_SHELL;


C_SHELL *Shell_Create(void);
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
	int     iExitCode;
	int		i;
	
	/* オブジェクト生成 */
	if ( (self = Shell_Create()) == NULL )
	{
		return 0;
	}
	
	/* オプションを解析して実行 */
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( argv[i][1] == 'i' )		/* インタラクティブモード */
			{
				iExitCode = Shell_Interactive(self);
			}
			else if ( argv[i][1] == 's' )	/* 文字列実行 */
			{
				/* 後続を結合 */
				self->szCommanBuf[0] = '\0';
				for ( i++; i < argc; i++ )
				{
					strcat(self->szCommanBuf, argv[i]);
					if ( i + 1 < argc )
					{
						strcat(self->szCommanBuf, " ");
					}
				}
				
				/* 実行 */
				iExitCode = Shell_ExecuteCommand(self, self->szCommanBuf);
			}
		}
		else	/* スクリプト実行 */
		{
			return Shell_ExecuteScript(self, argv[i]);
		}
	}
	
	/* オブジェクト削除 */
	Shell_Delete(self);
	
	return iExitCode;
}


/* コンストラクタ */
C_SHELL *Shell_Create(void)
{
	C_SHELL *self;

	/* オブジェクト生成 */
	if ( (self = Memory_Alloc(sizeof(C_SHELL))) == NULL )
	{
		StdIo_PutString("Memory error\n");
		return NULL;
	}
	
	/* メンバ初期化 */
	self->iScreenWidth = 80;
	self->iHistoryNum  = 0;
	
	return self;
}


/* デストラクタ */
void Shell_Delete(C_SHELL *self)
{
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
	while ( (iLen = File_GetString(hFile, self->szCommanBuf, sizeof(self->szCommanBuf))) > 0 )
	{
		/* 末尾の改行削除 */
		if ( self->szCommanBuf[iLen-1] == '\n' )
		{
			self->szCommanBuf[iLen-1] = '\0';
		}
		
		/* 実行 */
		if ( self->szCommanBuf[0] != '\0' && self->szCommanBuf[0] != '#' )
		{
			Shell_ExecuteCommand(self, self->szCommanBuf);
		}
	}
	
	/* ファイルクローズ */
	File_Close(hFile);
	
	return 0;
}



/* インタラクティブモード */
int Shell_Interactive(C_SHELL *self)
{
	int i;

	for ( ; ; )
	{
		/* コマンド入力 */
		Shell_InputLine(self, self->szCommanBuf, SHELL_MAX_COMMAND);

		/* exit なら抜ける */
		if ( strcmp(self->szCommanBuf, "exit") == 0 )
		{
			break;
		}

		/* 空行なら無視 */
		if ( self->szCommanBuf[0] == 0 )
		{
			continue;
		}
		
		/* ヒストリ重複削除 */
		for ( i = 0; i < self->iHistoryNum; i++ )
		{
			if ( strcmp(self->szHistory[i], self->szCommanBuf) == 0 )
			{
				memmove(self->szHistory[i], self->szHistory[i+1], (SHELL_MAX_HISTORY-i-1)*(SHELL_MAX_COMMAND));
				self->iHistoryNum--;
			}
		}
		
		/* ヒストリ記憶 */
		memmove(self->szHistory[1], self->szHistory[0], (SHELL_MAX_HISTORY-1)*(SHELL_MAX_COMMAND));
		strcpy(self->szHistory[0], self->szCommanBuf);
		if ( self->iHistoryNum < SHELL_MAX_HISTORY )
		{
			self->iHistoryNum++;
		}

		/* コマンド実行 */
		Shell_ExecuteCommand(self, self->szCommanBuf);
	}
	
	return 0;
}


int Shell_ExecEntry(VPARAM Param)
{
	int iExitCode;
	char *pszCommand;
	
	pszCommand = (char *)Param;
	if ( Command_Execute(pszCommand, &iExitCode) != COMMAND_ERR_NG )
	{
		iExitCode = -1;
	}
	
	Memory_Free(pszCommand);
	
	return iExitCode;
}


int Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand)
{
	T_PROCESS_CREATE_INF Inf;
	int iExitCode;

	int iLen;
	iLen = strlen(pszCommand);
	if ( iLen > 1 && pszCommand[iLen - 1] == '&' )
	{
		char *pszBuf;
		pszBuf = Memory_Alloc(iLen);
		strcpy(pszBuf, pszCommand);
		pszBuf[iLen - 1] = '\0';

		/* プロセスの生成情報 */
		Inf.pfncEntry  = Shell_ExecEntry;						/* 起動アドレス */
		Inf.Param      = (VPARAM)pszBuf;						/* ユーザーパラメータ */
		Inf.StackSize  = 1024;									/* スタックサイズ */
		Inf.Priority   = PROCESS_PRIORITY_NORMAL+1;				/* プロセス優先度 */
		Inf.hTerminal  = Process_GetTerminal(HANDLE_NULL);		/* ターミナル */
		Inf.hConsole   = Process_GetConsole(HANDLE_NULL);		/* コンソール */
		Inf.hStdIn     = Process_GetStdIn(HANDLE_NULL);			/* 標準入力 */
		Inf.hStdOut    = Process_GetStdOut(HANDLE_NULL);		/* 標準出力 */
		Inf.hStdErr    = Process_GetStdErr(HANDLE_NULL);		/* 標準エラー出力 */
		Process_GetCurrentDir(HANDLE_NULL, Inf.szCurrentDir, sizeof(Inf.szCurrentDir));	/* カレントディレクトリ */
		
		Process_Create(&Inf);
	}
	else
	{
		if ( Command_Execute(pszCommand, &iExitCode) != COMMAND_ERR_OK )
		{
			StdIo_PutString("command is not found.\r\n");
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
			if ( iHistoryPos + 1 < self->iHistoryNum )
			{
				iHistoryPos++;
				Shell_ReplaceLine(self, self->szHistory[iHistoryPos]);
			}
			break;

		case CONSOLE_KEY_DOWN:	/* 下 */
			if ( iHistoryPos > 0 )
			{
				iHistoryPos--;
				Shell_ReplaceLine(self, self->szHistory[iHistoryPos]);
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
		self->szCommanBuf[i] = pszNewLine[i];
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
