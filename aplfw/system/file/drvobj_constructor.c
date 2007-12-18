
#include "drvobj_local.h"



/**< コンストラクタ */
void DrvObj_Constructor(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods)
{
	HandleObj_Constructor(&self->HandleObj, &pMethods->HandleObj_Methods);
}


/* end of file */
