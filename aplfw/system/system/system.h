/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__system_h__
#define __HOS__system_h__


#include "system/type/type.h"


/* システム初期化情報 */
typedef struct t_system_initialize_inf
{
	void	*pSysMemBase;					/**< システムヒープメモリに割り当てる領域の先頭アドレス */
	MEMSIZE	SysMemSize;						/**< システムヒープメモリのサイズ */
	MEMSIZE	SysMemAlign;					/**< システムヒープメモリのアライメント単位 */
	
	void	*pIoMemBase;					/**< I/O用のヒープメモリ領域 */
	MEMSIZE	IoMemSize;						/**< I/O用のヒープメモリ領域サイズ */
	MEMSIZE	IoMemAlign;						/**< I/O用のヒープメモリのアライメント単位 */
	
	MEMSIZE	SystemStackSize;				/**< システムプロセスに割り当てるスタックサイズ */
	
	int		(*pfncBoot)(VPARAM Param);		/**< ブートプロセスの起動番地 */	
	MEMSIZE	BootStackSize;					/**< ブートプロセスに割り当てるスタックサイズ */
	VPARAM	BootParam;						/**< ブートプロセスのパラメータ */
} T_SYSTEM_INITIALIZE_INF;


#ifdef __cplusplus
extern "C" {
#endif

void   System_Initialize(const T_SYSTEM_INITIALIZE_INF *pInf);												/**< システム初期化 */
int    System_RequestProc(void (*pfncProc)(VPARAM Param1, VPARAM Param2), VPARAM Param1, VPARAM Param2);	/**< システムプロセスへの処理依頼 */

void   System_Lock(void);
void   System_Unlock(void);

HANDLE System_GetNextProcess(HANDLE hProcess);																/**< 次のプロセスを取得 */


void          Whiteboard_SetString(const char *pszKey, const char *pszValue);
const char   *Whiteboard_GetString(const char *pszKey, char *pszBuf, int iBufSize, const char *pszDefault);
void          Whiteboard_SetInteger(const char *pszKey, unsigned long ulValue);
unsigned long Whiteboard_GetInteger(const char *pszKey, unsigned long ulDefault);
const char   *Whiteboard_GetNextKey(const char *pszKey, char *pszBuf, int iBufSize);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__system_h__ */


/* end of file */
