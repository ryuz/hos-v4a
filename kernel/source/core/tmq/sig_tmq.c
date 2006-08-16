/**
 *  Hyper Operating System V4 Advance
 *
 * @file  add_tmq.c
 * @brief %jp{タイマキューにオブジェクトを追加}
 *
 * @version $Id: sig_tmq.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "core/tmq.h"



/* タイマオブジェクトをリストから削除 */
void _kernel_sig_tmq(
		_KERNEL_T_TMQ *pk_tmq,
		RELTIM        tictim)
{
	_KERNEL_T_TIMOBJ *timobj;
	
	/* タイマオブジェクトのハンドラ呼び出し */
	if ( pk_tmq->head != NULL )
	{
		/* 検索ポインタ設定 */
		pk_tmq->next = pk_tmq->head;
		
		do /* リスト末尾まで繰り返し */
		{
			/* 次のポインタを事前に設定 */
			timobj       = pk_tmq->next;
			pk_tmq->next = timobj->next;
			
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
		} while ( pk_tmq->next != pk_tmq->head );
		
		/* 検索ポインタのクリア */
		pk_tmq->next = NULL;
	}
}


/* end of file */
