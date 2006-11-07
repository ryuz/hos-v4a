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



/* タイマオブジェクトをリストに追加 */
void _kernel_add_tmq(
		_KERNEL_T_TMQ    *pk_tmq,
		_KERNEL_T_TIMOBJ *pk_timobj)
{
	/* 既に登録されていたら何もしない */
	if ( pk_timobj->next != NULL )
	{
		return;
	}
	
	/* リストに登録 */
	if ( pk_tmq->head == NULL )
	{
		/* リストが空の場合の追加 */
		pk_timobj->next = pk_timobj;
		pk_timobj->prev = pk_timobj;
		pk_tmq->head    = pk_timobj;
	}
	else
	{
		/* リストの末尾に追加 */
		pk_timobj->next       = pk_tmq->head;
		pk_timobj->prev       = pk_tmq->head->prev;
		pk_timobj->next->prev = pk_timobj;
		pk_timobj->prev->next = pk_timobj;
	}
}



/* end of file */
