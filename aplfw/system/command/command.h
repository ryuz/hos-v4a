/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/* コマンドのようなものを登録できるようにしてみるてすと */


#ifndef __HOS__command_h__
#define __HOS__command_h__

#define COMMAND_ERR_OK		0
#define COMMAND_ERR_NG		1


typedef int COMMAND_ERR;
typedef int (*COMMAND_FUNC)(int argc, char *argv[]);


#ifdef __cplusplus
extern "C" {
#endif

void        Command_Initialize(void);
void        Command_AddCommand(const char *pszName, COMMAND_FUNC pfncMain);		/* コマンドを登録する */
COMMAND_ERR Command_Execute(const char *pszCommandLine, int *piExitCode);		/* コマンドを実行する */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handle_h__ */


/* end of file */
