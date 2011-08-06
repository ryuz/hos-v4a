/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_local.h
 * @brief %jp{$OBJNAME_JP$ ローカルヘッダファイル}%en{$OBJNAME_EN$ private header file}
 *
 * $COPYRIGHT$
 */


#ifndef __ZZZZ__xxxxdrv_local_h__
#define __ZZZZ__xxxxdrv_local_h__


#include "xxxxdrv.h"
#include "system/file/syncdrv_local.h"
#include "library/container/streambuf/streambuf.h"
#include "system/sysapi/sysapi.h"



/** %jp{ドライバクラス}%en{Device driver class} */
typedef struct c_xxxxdrv
{
	C_SYNCDRV		SyncDrv;		/**< %jp{同期機能付きデバイスドライバを継承} */

	void			*pRegBase;		/**< %jp{レジスタベースアドレス} */
	unsigned long	ulBaseClock;	/**< %jp{ベースクロック} */
	int				iIntNum;		/**< %jp{割込み番号} */
	SYSISR_HANDLE	hIsr;			/**< %jp{割込みサービスルーチンハンドル} */

	int				iOpenCount;		/**< %jp{オープンカウンタ} */
	
	C_STREAMBUF		StmBufRecv;		/**< %jp{受信バッファ} */
} C_XXXXDRV;




#ifdef __cplusplus
extern "C" {
#endif

FILE_ERR  XxxxDrv_Constructor(C_XXXXDRV *self, const T_FILEOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize);
																												/**< コンストラクタ */
void      XxxxDrv_Destructor(C_XXXXDRV *self);																	/**< デストラクタ */

HANDLE    XxxxDrv_Open(C_FILEOBJ *pFileObj, const char *pszPath, int iMode);
void      XxxxDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);
FILE_ERR  XxxxDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  XxxxDrv_Seek(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, FILE_POS Offset, int iOrign);
FILE_SIZE XxxxDrv_Read(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, void *pBuf, FILE_SIZE Size);
FILE_SIZE XxxxDrv_Write(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, const void *pData, FILE_SIZE Size);
FILE_ERR  XxxxDrv_Flush(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr);

void      XxxxDrv_Isr(VPARAM Param);			/**< %jp{割込み処理} */


#ifdef __cplusplus
}
#endif


#endif	/* __ZZZZ__xxxxdrv_local_h__ */


/* end of file */
