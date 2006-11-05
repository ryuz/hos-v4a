#include <stdio.h>
#include "handle.h"
#include "sysapi.h"


/* コンストラクタ */
void HndleObj_Create(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods)
{
	self->pMethods = pMethods;
}


/* デストラクタ */
void HndleObj_Delete(C_HANDLEOBJ *self)
{
	/* デストラクタが登録されていれば呼ぶ */
	if ( self->pMethods->pfncDelete != NULL )
	{
		self->pMethods->pfncDelete((HANDLE)self);
	}
}


/* ハンドルを閉じる */
void Handle_Close(HANDLE handle)
{
	if ( handle == HANDLE_NULL )
	{
		return;
	}

	/* デストラクタ呼び出し */
	HndleObj_Delete((C_HANDLEOBJ *)handle);
	
	/* メモリ開放 */
	SysMem_Free((void *)handle);
}
