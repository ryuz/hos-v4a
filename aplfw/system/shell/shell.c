

#include "system/file/file.h"


#define SHELL_TERM_COLUMN		80

#define SHELL_STATE_NORMAL		0
#define SHELL_STATE_ESC			1
#define SHELL_STATE_ARROW 		2


/* インタラクティブモードでのコマンド入力(とりあえずVT100互換しか考えない) */
int Shell_InputTty(HANDLE hTty, char *pszBuf, int iBufSize)
{
	int iCurPos;						/* 画面上のカーソル位置 */
	int iPos = 0;						/* 入力位置 */
	int iLen = 0;						/* コマンドの長さ */
	int iState = SHELL_STATE_NORMAL;
	int c;

	/* プロンプトを出す */
	File_PutString(hTty, "% ");
	iCurPos = 2;

	for ( ; ; )
	{
		c = File_GetChar(hTty);
		switch ( iState )
		{
		case SHELL_STATE_NORMAL:	/* 通常 */
			switch ( c )
			{
			case '\r':		/* 改行なら入力完了 */
				pszBuf[iLen] = '\0';
				File_PutString(hTty, "\r\n");
				return iLen;

			case '\x1b':	/* エアスケープ文字なら */
				iState = SHELL_STATE_ESC;
				break;

			default:		/* カーソル位置に文字設定 */
				pszBuf[iPos] = (char)c;
				if ( iLen == iPos )
				{
					/* 末尾追加なら */
					if ( iLen < iBufSize - 1)
					{
						File_PutChar(hTty, c);
						iLen++;
						iCurPos = (iCurPos + 1) % SHELL_TERM_COLUMN;
						iPos++;
					}
					else
					{
						File_PutChar(hTty, '\b');
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
				break;

			case '\x42':	/* 下 */
				break;
			
			case '\x43':	/* 右 */
				File_PutString(hTty, "\x1b[1C");	/* カーソル右 */
				break;
			
			case '\x44':	/* 左 */
				File_PutString(hTty, "\x1b[1D");	/* カーソル左 */
				break;
			}
			iState = SHELL_STATE_NORMAL;
			break;
		}
	}
}
