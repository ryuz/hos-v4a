

#include "vt100drv.h"
#include "system/file/drvobj_local.h"

#define VT100DRV_ESC_IDLE		0
#define VT100DRV_ESC_ESC1		1
#define VT100DRV_ESC_ESC2		2
#define VT100DRV_ESC_FUNC		3
#define VT100DRV_ESC_NUM		4


#ifdef __cplusplus
extern "C" {
#endif

void      Vt100Drv_Constructor(C_VT100DRV *self, const T_DRVOBJ_METHODS *pMethods, HANDLE hTty);		/**< コンストラクタ */
void      Vt100Drv_Destructor(C_VT100DRV *self);														/**< デストラクタ */

HANDLE    Vt100Drv_Open(struct c_drvobj *self, const char *pszPath, int iMode);
void      Vt100Drv_Close(struct c_drvobj *self, C_FILEOBJ *pFileObj);
FILE_ERR  Vt100Drv_IoControl(struct c_drvobj *self, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  Vt100Drv_Seek(struct c_drvobj *self, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE Vt100Drv_Read(struct c_drvobj *self, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE Vt100Drv_Write(struct c_drvobj *self, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  Vt100Drv_Flush(struct c_drvobj *self, C_FILEOBJ *pFileObj);

int       Vt100Drv_GetCh(C_VT100DRV *self);


#ifdef __cplusplus
}
#endif

