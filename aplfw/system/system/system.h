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
	void	*pHeapMem;						/**< システムヒープメモリに割り当てる領域の先頭アドレス */
	MEMSIZE	HeapSize;						/**< システムヒープメモリのサイズ */
	
	MEMSIZE	SystemStackSize;				/**< システムプロセスに割り当てるスタックサイズ */
	
	int		(*pfncBoot)(VPARAM Param);		/**< ブートプロセスの起動番地 */	
	MEMSIZE	BootStackSize;					/**< ブートプロセスに割り当てるスタックサイズ */
	VPARAM	BootParam;						/**< ブートプロセスのパラメータ */
} T_SYSTEM_INITIALIZE_INF;


#ifdef __cplusplus
extern "C" {
#endif

void System_Initialize(const T_SYSTEM_INITIALIZE_INF *pInf);											/**< システム初期化 */
int  System_RequestProc(void (*pfncProc)(VPARAM Param1, VPARAM Param2), VPARAM Param1, VPARAM Param2);	/**< システムプロセスへの処理依頼 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__system_h__ */


/* end of file */
