/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "uart.h"



/** %jp{初期化ハンドラ} */
void Sample_Initialize(VP_INT exinf)
{
	/* %jp{UART初期化} */
	Uart_Initialize();

	/* %jp{タスク起動} */
	act_tsk(TSKID_WAIT);
	act_tsk(TSKID_SIGNAL);
}


/** %jp{乱数取得} */
int GetRand(void)
{
	int r;

	wai_sem(SEMID_RAND);
	r = rand();
	sig_sem(SEMID_RAND);
	
	return r;
}



/** %jp{待ちタスク} */
void Sample_WaitTask(VP_INT exinf)
{
	TMO	tmo;
	ER	ercd;

	for ( ; ; )
	{
		/* 待ち時間を決める */
		tmo = GetRand() % 5;
		
		/* 待つ */
		ercd = twai_sem(SEMID_TEST, tmo);
		switch ( ercd )
		{
		case E_OK:
			Uart_PutString("OK\n");
			break;
		
		case E_TMOUT:
			Uart_PutString("TMOUT\n");
			break;

		default:
			Uart_PutString("error!\n");
			for ( ; ; ) ;
		}
	}
}


/** %jp{sig_semタスク} */
void Sample_SignalTask(VP_INT exinf)
{
	RELTIM tim;
	
	for ( ; ; )
	{
		tim = GetRand() % 5;
		dly_tsk(tim);
		
		sig_sem(SEMID_TEST);
	}
}



/* end of file */
