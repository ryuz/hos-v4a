

#ifndef __HOS__memory_h__
#define __HOS__memory_h__


#ifdef __cplusplus
extern "C" {
#endif

void SysMem_Initialize(void *pMem, long lSize);		/* システムメモリの初期化 */


void *Memory_Alloc(long lSize);						/* システムメモリの割り当て */
void  Memory_Free(void *pMem);						/* システムメモリの割り当て */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__memory_h__ */
