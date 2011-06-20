/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv.h
 * @brief %jp{XILINX UART driver 公開ヘッダファイル}%en{XILINX UART driver public header file}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__xilinxuartdrv_h__
#define __HOS__xilinxuartdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE XilinxUartDrv_Create(void *pRegBase, int iIntNum, int iBufSize);	/**< %jp{生成}%en{create} */
void   XilinxUartDrv_Delete(HANDLE hDriver);							/**< %jp{削除}%en{delete} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__xilinxuartdrv_h__ */


/* end of file */
