/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  puts.c
 * @brief %jp{モニタへの出力}%en{console output}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


void Console_Initialize(void);
void Console_PutChar(int c);					/* %jp{1文字出力} */
void Console_PutString(const char *text);		/* %jp{文字列出力} */


int Debug_PutHex(int num);
int Debug_PutChar(int c);
int Debug_PrintFormat(const char *pszFormat, ...);	/* デバッグ用 */


/* end of file */
