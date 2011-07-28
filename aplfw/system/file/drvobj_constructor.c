

#include "drvobj_local.h"
#include "system/system/system_local.h"


/**< コンストラクタ */
void DrvObj_Constructor(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods)
{
	TargetObj_Constructor(&self->TargetObj, &pMethods->PointerObj_Methods);
}


/* end of file */
