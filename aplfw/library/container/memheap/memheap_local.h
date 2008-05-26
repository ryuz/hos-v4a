/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memheap_local.h
 * @brief %jp{メモリヒープクラス(抽象クラス)}%en{memory heap class(abstract class)}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS__memheap_local_h__
#define __HOS__memheap_local_h__


#include "memheap.h"


#ifdef __cplusplus
extern "C" {
#endif

#define MemHeap_Constructor(self, methods)		do { (self)->pMethods = (methods); } while (0)
#define MemHeap_Destructor(self)				do { } while (0)

#ifdef __cplusplus
}
#endif



#endif	/* __HOS_memheap_local_h__ */



/* end of file */
