
#ifndef __HOS__mutex_h__
#define __HOS__mutex_h__

/* エラーコード定義 */
#define MUTEX_ERR_OK			0
#define MUTEX_ERR_NG			(-1)

/* エラー型 */
typedef int		MUTEX_ERR;		

#ifdef __cplusplus
extern "C" {
#endif

HANDLE    Mutex_Create(void);
MUTEX_ERR Mutex_Delete(HANDLE hMutex);
MUTEX_ERR Mutex_Lock(HANDLE hMutex);
MUTEX_ERR Mutex_Unlock(HANDLE hMutex);


#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mutex_h__ */
