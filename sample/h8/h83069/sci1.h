/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sci1.h
 * @brief %jp{SCI1への出力}%en{SCI1 device driver}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __ostimer_h__
#define __ostimer_h__


#ifdef __cplusplus
extern "C" {
#endif

void Sci1_Initialize(void);					/* %jp{SCI1 の初期化} */
void Sci1_PutChar(int c);					/* %jp{1文字出力} */
void Sci1_PutString(const char *text);		/* %jp{文字列出力} */

void Sci1_PutHexByte(char c);
void Sci1_PutHexWord(int i);

#ifdef __cplusplus
}
#endif


#endif	/* __ostimer_h__ */


/* end of file */
