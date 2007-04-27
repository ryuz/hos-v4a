
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


#define SHELL_MAX_COMMAND		256


typedef struct c_shell
{
	char szCommanBuf[SHELL_MAX_COMMAND];
	int  iCommandLen;						/* コマンドの文字列長 */
	int  iCurPos;							/* カーソルの文字列上の位置 */
	int  iCurScreenX;						/* カーソルのスクリーンのX位置 */
	int  iScreenWidth;						/* スクリーンの幅 */
} C_SHELL;


void Shell_Create(C_SHELL *self);
void Shell_Delete(C_SHELL *self);
int  Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize);
void Shell_PutChar(C_SHELL *self, int c);
void Shell_CurRight(C_SHELL *self);
void Shell_CurLeft(C_SHELL *self);
void Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand);




int Shell_Main(int argc, char *argv[])
{
	C_SHELL *pShell;
	int     iExitCode;

	/* メモリ確保 */
	if ( (pShell = Memory_Alloc(sizeof(C_SHELL))) == NULL )	{ return 1;	}
	Shell_Create(pShell);
	
	
	for ( ; ; )
	{
		Shell_InputLine(pShell, pShell->szCommanBuf, SHELL_MAX_COMMAND);
		if ( strcmp(pShell->szCommanBuf, "exit") == 0 )
		{
			break;
		}
#if 0
		if ( Command_Execute(pShell->szCommanBuf, &iExitCode) != COMMAND_ERR_OK )
		{
			File_PutString(pShell->hTty, "command is not found.\r\n");
		}
#endif
		Shell_ExecuteCommand(pShell, pShell->szCommanBuf);
	}

	/* メモリ開放 */
	Shell_Delete(pShell);
	Memory_Free(pShell);
	
	return 0;
}


void Shell_Create(C_SHELL *self)
{
	self->iScreenWidth = 80;
}


void Shell_Delete(C_SHELL *self)
{
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

void Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand)
{
	int iLen;
	iLen = strlen(pszCommand);
	if ( iLen > 1 && pszCommand[iLen - 1] == '&' )
	{
		char *pszBuf;
		pszBuf = Memory_Alloc(iLen);
		strcpy(pszBuf, pszCommand);
		pszBuf[iLen - 1] = '\0';
		Process_CreateEx(Shell_ExecEntry, (VPARAM)pszBuf, 1024, PROCESS_PRIORITY_NORMAL+1, NULL);
	}
	else
	{
		if ( Command_Execute(pszCommand, NULL) != COMMAND_ERR_OK )
		{
			StdIo_PutString("command is not found.\r\n");
		}
	}
}



/* インタラクティブモードでの１行入力 */
int Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize)
{
	int  iPos = 0;
	int  iLen = 0;
	int  i;
	int  c;

	/* プロンプトを出す */
	StdIo_PutString("\r% ");
	self->iCurScreenX = 2;
	
	for ( ; ; )
	{
		c = ConIo_GetCh();
		
		switch ( c )
		{
		case '\n':		/* 改行なら入力完了 */
			pszBuf[iLen] = '\0';
			ConIo_PutString("\r\n");
			return iLen;
		
		
		case CONSOLE_KEY_BACKSPACE:	/* バックスペースなら */
			if ( iPos > 0 )
			{
				memmove(&pszBuf[iPos - 1], &pszBuf[iPos], iLen - iPos);
				iPos--;
				iLen--;
				Shell_CurLeft(self);
				for ( i = 0; i < iLen - iPos; i++ )
				{
					Shell_PutChar(self, pszBuf[iPos + i]);
				}
				Shell_PutChar(self, ' ');
				for ( i = 0; i < iLen - iPos + 1; i++ )
				{
					Shell_CurLeft(self);
				}
			}
			break;

		case CONSOLE_KEY_UP:	/* 上 */
			ConIo_PutString("\x1b[1A");
			break;

		case CONSOLE_KEY_DOWN:	/* 下 */
			ConIo_PutString("\x1b[1B");
			break;
		
		case CONSOLE_KEY_RIGHT:	/* 右 */
			if ( iPos < iLen )
			{
				Shell_CurRight(self);
				iPos++;
			}
			break;
		
		case CONSOLE_KEY_LEFT:	/* 左 */
			if ( iPos > 0 )
			{
				Shell_CurLeft(self);
				iPos--;
			}
			break;

		default:		/* カーソル位置に文字設定 */
			if ( c >= 0x20 && c <= 255 )
			{
				if ( iPos < iBufSize - 1 )
				{
					memmove(&pszBuf[iPos + 1], &pszBuf[iPos], iLen - iPos);
					pszBuf[iPos++] = (char)c;
					iLen++;
					for ( i = 0; i < iLen - iPos + 1; i++ )
					{
						Shell_PutChar(self, pszBuf[iPos + i - 1]);
					}
					for ( i = 0; i < iLen - iPos; i++ )
					{
						Shell_CurLeft(self);
					}
				}
				else
				{
					ConIo_PutChar('\a');
				}
			}
			break;
		}
	}
}



/* スクリーンに１文字出力 */
void Shell_PutChar(C_SHELL *self, int c)
{
	ConIo_PutChar(c);	
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		ConIo_PutString("\n");
	}	
}

/* カーソル右移動 */
void Shell_CurRight(C_SHELL *self)
{
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		ConIo_PutString("\n");
	}
	else
	{
		ConIo_PutString("\x1b[1C");		/* カーソル右 */
	}
}

/* カーソル左移動 */
void Shell_CurLeft(C_SHELL *self)
{
	if ( self->iCurScreenX == 0 )
	{
		self->iCurScreenX = self->iScreenWidth - 1;
		ConIo_PutString("\x1b[1A\x1b[80C");
	}
	else
	{
		self->iCurScreenX--;
		ConIo_PutString("\x1b[1D");		/* カーソル左 */
	}
}


/* end of file */
