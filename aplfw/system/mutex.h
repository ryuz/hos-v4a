
#ifndef __HOS__mutex_h__
#define __HOS__mutex_h__

/* エラーコード定義 */
#define MUTEX_ERR_OK			0
#define MUTEX_ERR_NG			(-1)

/* エラー型 */
typedef int		MUTEXERR;		

#ifdef __cplusplus
extern "C" {
#endif

HANDLE   Mutex_Create(void);
MUTEXERR Mutex_Delete(HANDLE hMutex);
MUTEXERR Mutex_Lock(HANDLE hMutex);
MUTEXERR Mutex_Unlock(HANDLE hMutex);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mutex_h__ */
