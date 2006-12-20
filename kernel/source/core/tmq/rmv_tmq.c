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



/* タイマオブジェクトをリストから削除 */
void _kernel_rmv_tmq(
		_KERNEL_T_TMQCB  *tmqcb,
		_KERNEL_T_TIMOBJ *pk_timobj)
{
	/* %jp{未登録なら何もしない} */
	if ( pk_timobj->next == NULL )
	{
		return;
	}
	
	/* %jp{処理中オブジェクトからの呼び出しなら} */
	if ( pk_timobj == tmqcb->busy )
	{
		tmqcb->busy = NULL;
	}
	
	/* %jp{検索中のタイマならポインタをずらす} */
	if ( pk_timobj == tmqcb->next )
	{
		tmqcb->next = pk_timobj->next;		/* %jp{次のオブジェクトに移動} */
	}
	
	/* %jp{リストから削除} */
	if ( pk_timobj == pk_timobj->next )
	{
		/* %jp{リストが空になる場合} */
		tmqcb->head = NULL;
		tmqcb->next = NULL;
	}
	else
	{
		/* %jp{先頭なら先頭位置をずらす} */
		if ( pk_timobj == tmqcb->head )
		{
			tmqcb->head = pk_timobj->next;
		}
		
		/* %jp{リストから削除} */
		pk_timobj->next->prev = pk_timobj->prev;
		pk_timobj->prev->next = pk_timobj->next;
	}
	
	/* %jp{未登録に設定} */
	pk_timobj->next = NULL;
}


/* end of file */
