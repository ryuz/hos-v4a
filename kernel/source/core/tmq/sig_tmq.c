/**
 *  Hyper Operating System V4 Advance
 *
 * @file  add_tmq.c
 * @brief %jp{タイマキューにオブジェクトを追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "core/tmq.h"



/* タイマオブジェクトの時間を進める */
void _kernel_sig_tmq(
		_KERNEL_T_TMQCB *tmqcb,
		RELTIM          tictim)
{
	_KERNEL_T_TIMOBJ *timobj;
	
	/* タイマオブジェクトのハンドラ呼び出し */
	if ( tmqcb->head != NULL )
	{
		/* 検索ポインタ設定 */
		tmqcb->next = tmqcb->head;
		
		do /* リスト末尾まで繰り返し */
		{
			timobj      = tmqcb->next;
			tmqcb->busy = timobj->next;		/* %jp{処理中オブジェクト設定} */
			tmqcb->next = timobj->next;		/* %jp{次のポインタを事前に設定} */
			
			if ( timobj->lefttim > tictim )
			{
				/* %jp{残時間減算} */
				timobj->lefttim -= tictim;
			}
			else
			{
				/* %jp{タイマハンドラ呼び出し} */
				timobj->timhdr(timobj, tictim - timobj->lefttim);
				if ( tmqcb->next == NULL )
				{
					break;
				}
			}
		} while ( tmqcb->next != tmqcb->head );
		
		/* 検索ポインタのクリア */
		tmqcb->next = NULL;
		tmqcb->busy = NULL;
	}
}


/* end of file */
