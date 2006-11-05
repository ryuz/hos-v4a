

#ifndef __HOS__memory_h__
#define __HOS__memory_h__


#ifdef __cplusplus
extern "C" {
#endif

void *Memory_Alloc(long lSize);						/* メモリの割り当て */
void  Memory_Free(void *pMem);						/* メモリの割り当て */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memory_h__ */
