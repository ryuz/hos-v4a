/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__winsockdrv_h__
#define __HOS__winsockdrv_h__


#ifdef __cplusplus
extern "C" {
#endif

HANDLE WinSockDrv_Create(int iPortNum, int iIntNum, int iBufSize);		/**< 生成 */
void   WinSockDrv_Delete(HANDLE hDriver);								/**< 削除 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__winsockdrv_h__ */


/* end of file */
