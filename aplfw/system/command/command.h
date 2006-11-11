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


#define COMMAND_MAX_NAME	32


/* コマンド情報 */
typedef struct t_command_cmdinf
{
	char szName[COMMAND_MAX_NAME];
	int (*pfncMain)(int argc, char *argv[], void *pParam);
	void *pParam;
} T_COMMAND_CMDINF;


#ifdef __cplusplus
extern "C" {
#endif

void Command_AddCommand(const T_COMMAND_CMDINF *pCmdInf);	/* コマンドを登録する */
void Command_Execute(const char *pszCommand);				/* コマンドを実行する */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handle_h__ */


/* end of file */
