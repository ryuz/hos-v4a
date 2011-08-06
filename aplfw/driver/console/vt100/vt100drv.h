

#include "system/file/console.h"
#include "system/file/file_local.h"



typedef struct c_vt100drv
{
	C_FILEOBJ		FileObj;

	HANDLE			hTty;
	int				iEscState;
	int				iEscNum;

} C_VT100DRV;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE Vt100Drv_Create(HANDLE hTty);			/**< 生成 */
void   Vt100Drv_Delete(HANDLE hDriver);			/**< 削除 */

#ifdef __cplusplus
}
#endif

