

#ifndef __HOS__cache_h__
#define __HOS__cache_h__

#include "system/type/type.h"


#ifdef __cplusplus
extern "C" {
#endif

#if 1

void Cache_InstInvalidate(void *pAddr, MEMSIZE Size);
void Cache_InstInvalidateAll(void);
void Cache_DataInvalidate(void *pAddr, MEMSIZE Size);
void Cache_DataInvalidateAll(void);
void Cache_DataFlush(void *pAddr, MEMSIZE Size);
void Cache_DataFlushAll(void);
void Cache_InstPreLoad(void *pAddr);
void Cache_DataPreLoad(void *pAddr);

#else

#define Cache_InstInvalidate(pAddr, Size)		do {} while(0)
#define Cache_InstInvalidateAll()				do {} while(0)
#define Cache_DataInvalidate(pAddr, Size)		do {} while(0)
#define Cache_DataInvalidateAll()				do {} while(0)
#define Cache_DataFlush(pAddr, Size)			do {} while(0)
#define Cache_DataFlushAll()					do {} while(0)
#define Cache_InstPreLoad(pAddr)				do {} while(0)
#define Cache_DataPreLoad(pAddr)				do {} while(0)

#endif

#ifdef __cplusplus
}
#endif

#endif	/* __HOS__cache_h__ */
