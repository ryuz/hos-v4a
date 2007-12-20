/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv.h
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ 公開ヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__at91usartdrv_h__
#define __HOS__at91usartdrv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE At91UsartDrv_Create(void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);	/**< 生成 */
void   At91UsartDrv_Delete(HANDLE hDriver);															/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__at91usartdrv_h__ */


/* end of file */
