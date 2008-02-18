/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_isr.c
 * @brief %jp{$OBJNAME_JP$ 割込みサービスルーチン}%en{$OBJNAME_EN$  interrupt service routine}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/* 割込み処理 */
void XxxxDrv_Isr(VPARAM Param)
{
	C_XXXXDRV	*self;
	int			c;
	
	self = (C_XXXXDRV *)Param;
	
	
	/* I/O処理完了 */
	SyncDrv_EndProcess(&self->SyncDrv, SYNCDRV_FACTOR_IOCTL, (VPARAM)FILE_ERR_OK);
	
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNum);
}


/* end of file */
