

#include "system/file/consoleobj.h"



typedef struct c_vt100drv
{
	C_CONSOLEOBJ	ConObj;
	HANDLE			hTty;
	int				iEscState;
	int				iEscNum;

} C_VT100DRV;


#ifdef __cplusplus
extern "C" {
#endif

void      Vt100Drv_Create(C_VT100DRV *self, HANDLE hTty);					/**< コンストラクタ */
void      Vt100Drv_Delete(C_VT100DRV *self);								/**< デストラクタ */
FILE_ERR  Vt100Drv_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
FILE_SIZE Vt100Drv_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size);
FILE_SIZE Vt100Drv_Write(HANDLE hFile, const void *pData, FILE_SIZE Size);

#ifdef __cplusplus
}
#endif

