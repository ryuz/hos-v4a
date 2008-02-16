/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  def_tex.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/texobj.h"


/* %jp{タスク例外処理ルーチンの定義} */
ER def_tex(ID tskid, T_DTEX *pk_dtex)
{
	_KERNEL_T_TEXCB		*texcb;
	_KERNEL_T_TEXCB_RO	*texcb_ro;
	
	
	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
		_KERNEL_T_TSKHDL	tskhdl;
		
#ifdef _KERNEL_SPT_DEF_TEX_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;			/* %jp{不正ID番号} */
		}
#endif
		
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		tskid  = _KERNEL_TSK_TSKHDL2ID(tskhdl);
	}
	else
	{
#if _KERNEL_SPT_DEF_TEX_E_ID
		if ( !_KERNEL_TEX_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
	}
	
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{タスク存在チェック} */
#if _KERNEL_SPT_DEF_TEX_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif	
	
	if ( pk_dtex != NULL )	/* 登録 */
	{
		if ( !_KERNEL_TEX_CHECK_EXS(tskid) )	/* 未登録なら生成 */
		{
#if (_KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_BLKARRAY)
			{	/* %jp{ブロック配列の場合} */
				texcb    = _KERNEL_TEX_ID2TEXCB(tskid);
				texcb_ro = _KERNEL_TEX_GET_TEXCB_RO(tskid, texcb);
			}
#elif (_KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY) && _KERNEL_TEXCB_SPLIT_RO
			{	/* %jp{ポインタ管理で、ROM/RAM分離の場合} */
				VP		mem;
				SIZE	memsz;

				/* %jp{メモリサイズ決定} */
				memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TEXCB))
							+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TEXCB_RO));

				/* %jp{メモリ確保} */
				mem = _KERNEL_SYS_ALC_HEP(memsz);
				
				/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_DEF_TEX_E_NOMEM
				if ( mem == NULL )
				{
					_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
					return E_NOMEM;
				}
#endif
				
				/* %jp{メモリ割り当て} */
				texcb    = (_KERNEL_T_TEXCB *)mem;
				texcb_ro = (_KERNEL_T_TEXCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_TEXCB)));
				_KERNEL_TEX_ID2TEXCB(tskid)           = tskcb;
				_KERNEL_TEX_ID2TEXCB(tskid)->tskcb_ro = (const _KERNEL_T_TEXCB_RO *)texcb_ro;
			}
#elif (_KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY) && !(_KERNEL_TEXCB_SPLIT_RO)
			{	/* %jp{ポインタ管理で、ROM/RAM統合の場合} */
				VP   mem;
				
				/* %jp{メモリ確保} */
				mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_TEXCB));

				/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_DEF_TEX_E_NOMEM
				if ( mem == NULL )
				{
					_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
					return E_NOMEM;
				}
#endif
				
				/* %jp{メモリ割り当て} */
				texcb    = (_KERNEL_T_TEXCB *)mem;
				texcb_ro = (_KERNEL_T_TEXCB_RO *)mem;
				_KERNEL_TEX_ID2TEXCB(tskid) = texcb;
			}
#endif
		}
		else
		{
			/* %jp{すでに登録があれば現状のものを取得} */
			texcb    = _KERNEL_TEX_ID2TEXCB(tskid);
			texcb_ro = _KERNEL_TEX_GET_TEXCB_RO(tskid, texcb);
		}
		
		/* 登録 */
		_KERNEL_TEX_SET_STATE(texcb, FALSE);
		_KERNEL_TEX_SET_RASPTN(texcb, 0);
		_KERNEL_TEX_SET_TEXATR(texcb_ro, pk_dtex->texatr);
		_KERNEL_TEX_SET_TEXRTN(texcb_ro, pk_dtex->texrtn);
	}
	else		/* %jp{登録解除} */
	{
		if ( _KERNEL_TEX_CHECK_EXS(tskid) )	/* %jp{登録済みなら削除} */
		{
			/* %jp{コントロールブロック取得} */
			texcb    = _KERNEL_TEX_ID2TEXCB(tskid);

#if (_KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_BLKARRAY)
			{	/* %jp{ブロック配列の場合} */
				texcb_ro = (_KERNEL_T_TEXCB_RO *)_KERNEL_TEX_GET_TEXCB_RO(tskid, texcb);
				_KERNEL_TEX_SET_TEXRTN(texcb_ro,NULL);	/* %jp{未登録をマーク} */
			}
#elif (_KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY)
			{	/* %jp{ポインタ管理の場合} */
				_KERNEL_SYS_FRE_HEP(texcb);				/* %jp{メモリ開放} */
				_KERNEL_TEX_ID2TEXCB(tskid) = NULL;		/* %jp{未登録をマーク} */
			}
		}
#endif
	}
	
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */

	
	return E_OK;
}


/* end of file */
