/* */

#ifndef __HOS__process_h__
#define __HOS__process_h__

#include "system/type/type.h"
#include "system/handle/handle.h"
#include "system/file/file.h"
#include "system/file/console.h"


/* (とりあえず適当、そのうちTSSとか真面目にやるときの為にひとまず) */
#define PROCESS_PRIORITY_IDLE		14
#define PROCESS_PRIORITY_LOW		13
#define PROCESS_PRIORITY_NORMAL		12
#define PROCESS_PRIORITY_HIGH		11


/* プロセス固有情報 */
typedef struct t_process_inf
{
	HANDLE      hTty;							/* ターミナル */
	HANDLE      hConsole;						/* コンソール */
	HANDLE      hStdIn;							/* 標準入力 */
	HANDLE      hStdOut;						/* 標準出力 */
	HANDLE      hStdErr;						/* 標準エラー出力 */
} T_PROCESS_INF;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE Process_Create(int (*pfncEntry)(VPARAM Param), VPARAM Param, MEMSIZE StackSize, int Priority);
HANDLE Process_CreateEx(int (*pfncEntry)(VPARAM Param), VPARAM Param, MEMSIZE StackSize, int Priority, const T_PROCESS_INF *pInf);
void   Process_Exit(int iExitCode);
HANDLE Process_GetCurrentHandle(void);

int    Process_GetExitCode(HANDLE hProcess);
const T_PROCESS_INF *Process_GetInfo(HANDLE hProcess);

#define Process_GetTty()		(Process_GetInfo(Process_GetCurrentHandle())->hTty)
#define Process_GetConsole()	(Process_GetInfo(Process_GetCurrentHandle())->hConsole)
#define Process_GetStdIn()		(Process_GetInfo(Process_GetCurrentHandle())->hStdIn)
#define Process_GetStdOut()		(Process_GetInfo(Process_GetCurrentHandle())->hStdOut)
#define Process_GetStdErr()		(Process_GetInfo(Process_GetCurrentHandle())->hStdErr)

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__process_h__ */


/* end of file */
