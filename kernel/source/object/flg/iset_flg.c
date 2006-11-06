/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  iset_flg.c
 * @brief %jp{イベントフラグのセット}%en{Set Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"


#if _KERNEL_SPT_ISET_FLG

#if _KERNEL_SPT_DPC

static void _kernel_dpc_set_flg(void);

/** %jp{イベントフラグのセット}%en{Set Eventflag}
 * @param  flgid    %jp{セット対象のイベントフラグのID番号}%en{ID number of the eventflag to be set}
 * @param  flgptn   %jp{セットするビットパターン}%en{Bit pattern to set}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(setptnが不正)}%en{Parameter error(setptn is invalid)}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	ER ercd;
	
	_KERNEL_SYS_LOC_DPC();	/* %jp{多重割り込み対策でロックをかける} */

	if (  _KERNEL_SYS_RFR_DPC() >= 3 )
	{
		_KERNEL_SYS_SND_DPC((VP_INT)_kernel_dpc_set_flg);
		_KERNEL_SYS_SND_DPC((VP_INT)flgid);
		_KERNEL_SYS_SND_DPC((VP_INT)setptn);
		ercd = E_OK;		/* %jp{正常終了}%en{Normal completion} */
	}
	else
	{
		ercd = E_NOMEM;		/* %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution} */
	}
	
	_KERNEL_SYS_UNL_DPC();	/* jp{ロック解除} */
	
	return ercd;
}

/** %jp{set_flgの遅延実行}%en{service call for delayed execution(set_flg)} */
void _kernel_dpc_set_flg(void)
{
	ID     flgid;
	FLGPTN setptn;
	
	/* %jp{パラメータ取り出し} */
	flgid  = (ID)_KERNEL_SYS_RCV_DPC();
	setptn = (FLGPTN)_KERNEL_SYS_RCV_DPC();
	
	/* %jp{遅延実行} */
	set_flg(flgid, setptn);
}

#else	/* _KERNEL_SPT_DPC */

/** %jp{イベントフラグ資源の返却}%en{Release Flgaphore Resource}
 * @param  flgid    %jp{イベントフラグ資源返却対象のイベントフラグのID番号}%en{ID number of the Eventflag to which resource is released}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	return set_flg(flgid, setptn);
}

#endif	/* _KERNEL_SPT_DPC */


#else	/* _KERNEL_SPT_SET_FLG */


#if _KERNEL_SPT_SET_IFLG_E_NOSPT

/** %jp{イベントフラグ資源の返却}%en{Release Flgaphore Resource}
 * @param  flgid    %jp{イベントフラグ資源返却対象のイベントフラグのID番号}%en{ID number of the Eventflag to which resource is released}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER iset_flg(ID flgid, FLGPTN setptn)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SET_FLG */



/* end of file */
