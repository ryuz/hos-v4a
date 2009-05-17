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
	
	/* 受信 */	
	if ( 0 )
	{
		/* 受信バッファ読み出し */	
		do
		{
			/* 受信バッファ読み出し処理 */	
			
			StreamBuf_SendChar(&self->StmBufRecv, c);
		} while ( 0 );
		
		/* 読込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_READ);
	}
	
	/* 送信 */	
	if ( 0 )
	{
		/* 送信割込み禁止 */
		
		/* 書込みシグナルを発生 */
		SyncDrv_SendSignal(&self->SyncDrv, SYNCDRV_FACTOR_WRITE);
	}
	
	/* 割込み要因クリア */
	SysInt_Clear(self->iIntNum);
}


/* end of file */
