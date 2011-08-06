
#include "sysvolfile_local.h"


void SysVolFile_Destructor(C_SYSVOLFILE *self)
{
	/* 親クラスデストラクタ呼び出し */
	FilePtr_Destructor(&self->FilePtr);
}

