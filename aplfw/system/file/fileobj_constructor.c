

#include "file_local.h"
#include "system/system/system_local.h"


/**< コンストラクタ */
void FileObj_Constructor(C_FILEOBJ *self, const T_FILEOBJ_METHODS *pMethods)
{
	TargetObj_Constructor(&self->TargetObj, &pMethods->ObjectMethods);
}


/* end of file */
