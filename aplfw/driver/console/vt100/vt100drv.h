

#include "system/file/console.h"
#include "system/file/drvobj.h"



typedef struct c_vt100drv
{
	C_DRVOBJ		DrvObj;

	HANDLE			hTty;
	int				iEscState;
	int				iEscNum;

} C_VT100DRV;


#ifdef __cplusplus
extern "C" {
#endif

void      Vt100Drv_Create(C_VT100DRV *self, HANDLE hTty);					/**< コンストラクタ */
void      Vt100Drv_Delete(C_VT100DRV *self);								/**< デストラクタ */

#ifdef __cplusplus
}
#endif

