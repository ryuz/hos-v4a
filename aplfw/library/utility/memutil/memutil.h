/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memutil.h
 * @brief %jp{メモリ操作}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__memutil_h__
#define __HOS__memutil_h__


#ifdef __cplusplus
extern "C" {
#endif

void MemUtil_MemCopyB(void *pDst, const void *pSrc, MEMSIZE Num);
void MemUtil_MemCopyH(void *pDst, const void *pSrc, MEMSIZE Num);
void MemUtil_MemCopyW(void *pDst, const void *pSrc, MEMSIZE Num);

void MemUtil_MemSetB(void *pDst, unsigned char ubData, MEMSIZE Num);
void MemUtil_MemSetH(void *pDst, unsigned short uhData, MEMSIZE Num);
void MemUtil_MemSetW(void *pDst, unsigned long uwData, MEMSIZE Num);

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memutil_h__ */


/* end of file */
