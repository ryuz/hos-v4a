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
		_KERNEL_T_TMQ    *pk_tmq,
		_KERNEL_T_TIMOBJ *pk_timobj)
{
	/* 未登録なら何もしない */
	if ( pk_timobj->next == NULL )
	{
		return;
	}
	
	/* 検索中のタイマならポインタをずらす(再入対策) */
	if ( pk_timobj == pk_tmq->next )
	{
		pk_tmq->next = pk_timobj->next;		/* 次のオブジェクトに移動 */
	}
	
	/* リストから削除 */
	if ( pk_timobj == pk_timobj->next )
	{
		/* リストが空になる場合 */
		pk_tmq->head = NULL;
		pk_tmq->next = NULL;
	}
	else
	{
		/* 先頭なら先頭位置をずらす */
		if ( pk_timobj == pk_tmq->head )
		{
			pk_tmq->head = pk_timobj->next;
		}
		
		/* リストから削除 */
		pk_timobj->next->prev = pk_timobj->prev;
		pk_timobj->prev->next = pk_timobj->next;
	}

	/* 未登録に設定 */
	pk_timobj->next = NULL;
}


/* end of file */
