/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.h
 * @brief %jp{ストリームパイプ 公開ヘッダファイル}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__streampipe_h__
#define __HOS__streampipe_h__


#include "hosaplfw.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE StreamPipe_Create(int iBufSize);			/**< 生成 */
void   StreamPipe_Delete(HANDLE hDriver);		/**< 削除 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__streampipe_h__ */


/* end of file */
