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
			/* 次のポインタを事前に設定 */
			timobj      = tmqcb->next;
			tmqcb->next = timobj->next;
			
			while ( timobj->lefttim <= tictim )
			{
				/* タイマハンドラ呼び出し */
				timobj->timhdr(timobj);
				
				/* ハンドラ内で削除された場合 */
				if ( timobj->next == NULL )
				{
					goto loop_continue;
				}
			}
			timobj->lefttim -= tictim;

loop_continue:
			;
		} while ( tmqcb->next != tmqcb->head );
		
		/* 検索ポインタのクリア */
		tmqcb->next = NULL;
	}
}


/* end of file */
