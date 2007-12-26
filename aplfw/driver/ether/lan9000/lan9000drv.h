/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__lan9000drv_h__
#define __HOS__lan9000drv_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE  Lan9000Drv_Create(void *pRegBase, int iIntNum);		/**< 生成 */
void    Lan9000Drv_Delete(HANDLE hDriver);					/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__lan9000drv_h__ */


/* end of file */
