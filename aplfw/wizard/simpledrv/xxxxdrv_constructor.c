/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_constructor.c
 * @brief %jp{$OBJNAME_JP$ オブジェクト削除}%en{$OBJNAME_EN$  delete object}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** %jp{仮想関数テーブル}%en{virtual functions table} */
const T_DRVOBJ_METHODS XxxxDrv_Methods = 
	{
		{ XxxxDrv_Delete },
		XxxxDrv_Open,
		XxxxDrv_Close,
		XxxxDrv_IoControl,
		XxxxDrv_Seek,
		XxxxDrv_Read,
		XxxxDrv_Write,
		XxxxDrv_Flush,
	};


/** コンストラクタ */
FILE_ERR XxxxDrv_Constructor(C_XXXXDRV *self, const T_DRVOBJ_METHODS *pMethods)
{
	FILE_ERR	ErrCode;
	
		
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &XxxxDrv_Methods;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Constructor(&self->DrvObj, pMethods);
	
	/* メンバ変数初期化 */
	self->iOpenCount  = 0;
	
	return FILE_ERR_OK;
}


/* end of file */
