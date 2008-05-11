/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  console.h
 * @brief %jp{コンソール}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__console_h__
#define __HOS__console_h__

#include "system/file/file.h"


#define	CONSOLE_KEY_DOWN			258
#define	CONSOLE_KEY_UP				259
#define	CONSOLE_KEY_LEFT			260
#define	CONSOLE_KEY_RIGHT			261
#define	CONSOLE_KEY_HOME			262
#define	CONSOLE_KEY_END				360
#define	CONSOLE_KEY_BACKSPACE		263
#define CONSOLE_KEY_DEL				330
#define CONSOLE_KEY_INS				331

#define CONSOLE_KEY_PAGEDOWN		338
#define CONSOLE_KEY_PAGEUP			339

#define CONSOLE_KEY_F1				265
#define CONSOLE_KEY_F2				266
#define CONSOLE_KEY_F3				267
#define CONSOLE_KEY_F4				268
#define CONSOLE_KEY_F5				269
#define CONSOLE_KEY_F6				270
#define CONSOLE_KEY_F7				271
#define CONSOLE_KEY_F8				272
#define CONSOLE_KEY_F9				273
#define CONSOLE_KEY_F10				274
#define CONSOLE_KEY_F11				275
#define CONSOLE_KEY_F12				276



#ifdef __cplusplus
extern "C" {
#endif

int Console_GetCh(HANDLE hConsole);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__console_h__ */


/* end of file */
