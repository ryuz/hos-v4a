

#include <string.h>
#include "shell.h"
#include "system/file/file.h"
#include "system/memory/memory.h"
#include "system/process/process.h"
#include "system/command/command.h"


#define SHELL_MAX_COMMAND		256


typedef struct c_shell
{
	HANDLE hTty;
	char szCommanBuf[SHELL_MAX_COMMAND];
	int  iCommandLen;						/* コマンドの文字列長 */
	int  iCurPos;							/* カーソルの文字列上の位置 */
	int  iCurScreenX;						/* カーソルのスクリーンのX位置 */
	int  iScreenWidth;						/* スクリーンの幅 */
} C_SHELL;




void Shell_Create(C_SHELL *self);
void Shell_Delete(C_SHELL *self);
int  Shell_InputLineVt100(C_SHELL *self, char *pszBuf, int  iBufSize);


int Shell_Main(int argc, char *argv[])
{
	C_SHELL *pShell;

	/* メモリ確保 */
	if ( (pShell = Memory_Alloc(sizeof(C_SHELL))) == NULL )	{ return 1;	}
	Shell_Create(pShell);
	
	for ( ; ; )
	{
		Shell_InputLineVt100(pShell, pShell->szCommanBuf, SHELL_MAX_COMMAND);
		if ( strcmp(pShell->szCommanBuf, "exit") == 0 )
		{
			break;
		}
		Command_Execute(pShell->szCommanBuf);
	}

	/* メモリ開放 */
	Shell_Delete(pShell);
	Memory_Free(pShell);
	
	return 0;
}


void Shell_Create(C_SHELL *self)
{
	self->hTty         = Process_GetTty();
	self->iScreenWidth = 80;
}


void Shell_Delete(C_SHELL *self)
{
}


#define SHELL_TERM_COLUMN		80
#define SHELL_STATE_NORMAL		0
#define SHELL_STATE_ESC			1
#define SHELL_STATE_ARROW 		2


void Shell_Vt100PutChar(C_SHELL *self, int c);
void Shell_Vt100CurRight(C_SHELL *self);
void Shell_Vt100CurLeft(C_SHELL *self);


/* インタラクティブモードでの１行入力(VT100互換用) */
int Shell_InputLineVt100(C_SHELL *self, char *pszBuf, int  iBufSize)
{
	int  iState = SHELL_STATE_NORMAL;
	int  iPos = 0;
	int  iLen = 0;
	int  i;
	int  c;

	/* プロンプトを出す */
	File_PutString(self->hTty, "\r% ");
	self->iCurScreenX = 2;
	
	for ( ; ; )
	{
		c = File_GetChar(self->hTty);
		switch ( iState )
		{
		case SHELL_STATE_NORMAL:	/* 通常 */
			switch ( c )
			{
			case '\r':		/* 改行なら入力完了 */
				pszBuf[iLen] = '\0';
				File_PutString(self->hTty, "\r\n");
				return iLen;

			case '\x1b':	/* エアスケープ文字なら */
				iState = SHELL_STATE_ESC;
				break;

			case '\x08':	/* バックスペースなら */
				if ( iPos > 0 )
				{
					memmove(&pszBuf[iPos - 1], &pszBuf[iPos], iLen - iPos);
					iPos--;
					iLen--;
					Shell_Vt100CurLeft(self);
					for ( i = 0; i < iLen - iPos; i++ )
					{
						Shell_Vt100PutChar(self, pszBuf[iPos + i]);
					}
					Shell_Vt100PutChar(self, ' ');
					for ( i = 0; i < iLen - iPos + 1; i++ )
					{
						Shell_Vt100CurLeft(self);
					}
				}
				break;

			default:		/* カーソル位置に文字設定 */
				if ( c >= 0x20 )
				{
					if ( iPos < iBufSize - 1 )
					{
						memmove(&pszBuf[iPos + 1], &pszBuf[iPos], iLen - iPos);
						pszBuf[iPos++] = (char)c;
						iLen++;
						for ( i = 0; i < iLen - iPos + 1; i++ )
						{
							Shell_Vt100PutChar(self, pszBuf[iPos + i - 1]);
						}
						for ( i = 0; i < iLen - iPos; i++ )
						{
							Shell_Vt100CurLeft(self);
						}
					}
					else
					{
						File_PutChar(self->hTty, '\a');
					}
				}
				break;
			}
			break;

		case SHELL_STATE_ESC:	/* エスケープ後続 */	
			switch ( c )
			{
			case '\x5b':
				iState = SHELL_STATE_ARROW;
				break;
			default:
				iState = SHELL_STATE_NORMAL;
			}
			break;

		case SHELL_STATE_ARROW:	/* 矢印 */	
			switch ( c )
			{
			case '\x41':	/* 上 */
				File_PutString(self->hTty, "\x1b[1A");
				break;

			case '\x42':	/* 下 */
				File_PutString(self->hTty, "\x1b[1B");
				break;
			
			case '\x43':	/* 右 */
				if ( iPos < iLen )
				{
					Shell_Vt100CurRight(self);
					iPos++;
				}
				break;
			
			case '\x44':	/* 左 */
				if ( iPos > 0 )
				{
					Shell_Vt100CurLeft(self);
					iPos--;
				}
				break;
			}
			iState = SHELL_STATE_NORMAL;
			break;
		}
	}
}


/* スクリーンに１文字出力 */
void Shell_Vt100PutChar(C_SHELL *self, int c)
{
	File_PutChar(self->hTty, c);	
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		File_PutString(self->hTty, "\n\r");
	}	
}

/* カーソル右移動 */
void Shell_Vt100CurRight(C_SHELL *self)
{
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		File_PutString(self->hTty, "\n\r");
	}
	else
	{
		File_PutString(self->hTty, "\x1b[1C");	/* カーソル右 */
	}
}

/* カーソル左移動 */
void Shell_Vt100CurLeft(C_SHELL *self)
{
	if ( self->iCurScreenX == 0 )
	{
		self->iCurScreenX = self->iScreenWidth - 1;
		File_PutString(self->hTty, "\x1b[1A\x1b[80C");
	}
	else
	{
		self->iCurScreenX--;
		File_PutString(self->hTty, "\x1b[1D");	/* カーソル左 */
	}
}