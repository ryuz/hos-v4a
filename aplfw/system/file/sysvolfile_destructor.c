
#include "sysvolfile_local.h"


void SysVolFile_Destructor(C_SYSVOLFILE *self)
{
	/* 親クラスデストラクタ呼び出し */
	FileObj_Destructor(&self->FileObj);
}

