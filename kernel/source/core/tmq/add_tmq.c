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
		_KERNEL_T_TMQCB  *tmqcb,
		_KERNEL_T_TIMOBJ *pk_timobj)
{
	/* 既に登録されていたら何もしない */
	if ( pk_timobj->next != NULL )
	{
		return;
	}
	
	/* 次のティックまでの時間を加算しておく */
	pk_timobj->lefttim += _KERNEL_SYS_GET_TIC();
	
	/* リストに登録 */
	if ( tmqcb->head == NULL )
	{
		/* リストが空の場合の追加 */
		pk_timobj->next = pk_timobj;
		pk_timobj->prev = pk_timobj;
		tmqcb->head     = pk_timobj;
	}
	else
	{
		/* リストの末尾に追加 */
		pk_timobj->next       = tmqcb->head;
		pk_timobj->prev       = tmqcb->head->prev;
		pk_timobj->next->prev = pk_timobj;
		pk_timobj->prev->next = pk_timobj;
	}
}



/* end of file */
