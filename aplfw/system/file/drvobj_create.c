
#include "drvobj_local.h"


/**< コンストラクタ */
void DrvObj_Create(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods)
{
	self->pMethods = pMethods;
}


