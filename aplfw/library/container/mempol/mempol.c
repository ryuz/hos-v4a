#include <stdio.h>
#include <string.h>
#include "mempol.h"


/** %jp{コンストラクタ} */
void MemPol_Create(C_MEMPOL *self, void *p_base, MEMPOL_MEMSIZE Size)
{
	T_MEMPOL_MEMBLK *blk_last;
	
	/* %jp{サイズのアライメントを調整} */
	Size &= ~(MEMPOL_MEMALIGN - 1);

	/* %jp{サイズチェック} */
	if ( Size <= sizeof(T_MEMPOL_MEMBLK) )
	{
		self->pBase = NULL;
		return;
	}

	/* %jp{設定保存} */
	self->pBase   = (T_MEMPOL_MEMBLK *)p_base;
	self->MemSize = Size;
	
	/* %jp{終端位置に番人を設定} */
	blk_last = (T_MEMPOL_MEMBLK *)((char *)p_base + Size - MEMPOL_MEMBLK_SIZE);
	
	/* %jp{全体を空き領域に設定} */
	self->pBase->pPrev = NULL;
	self->pBase->Size = Size - (MEMPOL_MEMBLK_SIZE * 2);
	self->pBase->iFlag = MEMPOL_FREE;
	
	/* %jp{終端の番人を利用中に設定} */
	blk_last->pPrev = NULL;
	blk_last->Size = 0;
	blk_last->iFlag = MEMPOL_USING;
}


/** %jp{メモリの割り当て} */
void *MemPol_Alloc(C_MEMPOL *self, MEMPOL_MEMSIZE Size)
{
	T_MEMPOL_MEMBLK *mblk;
	T_MEMPOL_MEMBLK *mblk_next;
	T_MEMPOL_MEMBLK *mblk_next2;
	
	/* %jp{ヒープの存在チェック} */
	if ( self->pBase == NULL )
	{
		return NULL;
	}
	
	/* %jp{サイズのアライメントを調整} */
	Size = MEMPOL_ALIGNED(Size);
	
	/* %jp{空き領域を検索} */
	mblk = self->pBase;
	while ( mblk->Size != 0 )
	{
		if ( mblk->iFlag == MEMPOL_FREE && mblk->Size >= Size )
		{
			/* 十分な容量があったら */
			if ( mblk->Size - Size > MEMPOL_MEMBLK_SIZE + MEMPOL_MEMALIGN )
			{
				/* ブロックを分割する */
				mblk_next  = (T_MEMPOL_MEMBLK *)((char *)mblk + MEMPOL_MEMBLK_SIZE + Size);
				mblk_next2 = (T_MEMPOL_MEMBLK *)((char *)mblk + MEMPOL_MEMBLK_SIZE + mblk->Size);
				mblk_next->pPrev  = mblk;
				mblk_next->Size   = mblk->Size - Size - MEMPOL_MEMBLK_SIZE;
				mblk_next->iFlag  = MEMPOL_FREE;
				mblk_next2->pPrev = mblk_next;
				mblk->Size        = Size;
			}
			mblk->iFlag = MEMPOL_USING;
			
			return (void *)((char *)mblk + MEMPOL_MEMBLK_SIZE);
		}
		
		/* 次のブロックへ進む */
		mblk = (T_MEMPOL_MEMBLK *)((char *)mblk + mblk->Size + MEMPOL_MEMBLK_SIZE);
	}

	return NULL;	/* 空きが無い */
}


/** %jp{メモリの再割り当て} */
void *MemPol_ReAlloc(C_MEMPOL *self, void *pPtr, MEMPOL_MEMSIZE Size)
{
	void *pNewPtr;

	/* とりあえず手抜き */
	if ( (pNewPtr = MemPol_Alloc(self, Size)) != NULL )
	{
		memcpy(pNewPtr, pPtr, MemPol_GetSize(self, pPtr));
		MemPol_Free(self, pPtr);
	}

	return pNewPtr;
}


/** %jp{メモリの解放} */
void MemPol_Free(C_MEMPOL *self, void *pPtr)
{
	T_MEMPOL_MEMBLK *mblk;
	T_MEMPOL_MEMBLK *mblktmp;
	T_MEMPOL_MEMBLK *mblknext;

	/* %jp{ポインタ範囲チェック */
	if ( pPtr < (void *)self->pBase || pPtr >= (void *)((char *)self->pBase + self->MemSize) )
	{
		return;
	}

	/* %jp{メモリブロック位置を取得 */
	mblk = (T_MEMPOL_MEMBLK *)((char *)pPtr - MEMPOL_MEMBLK_SIZE);

	/* %jp{パラメーターチェック */
	if ( mblk->iFlag != MEMPOL_USING )	/* %jp{使用中で無ければ */
	{
		return;
	}

	/* %jp{フラグを未使用に設定} */
	mblk->iFlag = MEMPOL_FREE;
	
	/* %jp{次のブロックをチェック} */
	mblktmp = (T_MEMPOL_MEMBLK *)((char *)pPtr + mblk->Size);
	if ( mblktmp->iFlag == MEMPOL_FREE )
	{
		/* %jp{次のブロックが未使用なら結合する} */
		mblknext = (T_MEMPOL_MEMBLK *)((char *)mblktmp + mblktmp->Size + MEMPOL_MEMBLK_SIZE);
		mblknext->pPrev = mblk;
		mblk->Size += mblktmp->Size + MEMPOL_MEMBLK_SIZE;
	}
	
	/* %jp{前のブロックをチェック} */
	if ( mblk->pPrev != NULL )
	{
		mblktmp = mblk->pPrev;
		if ( mblktmp->iFlag == MEMPOL_FREE )
		{
			/* %jp{前のブロックが未使用なら結合する} */
			mblknext = (T_MEMPOL_MEMBLK *)((char *)mblk + mblk->Size + MEMPOL_MEMBLK_SIZE);
			mblknext->pPrev = mblktmp;
			mblktmp->Size += mblk->Size + MEMPOL_MEMBLK_SIZE;
		}
	}
}


/** %jp{メモリサイズの取得} */
MEMPOL_MEMSIZE  MemPol_GetSize(C_MEMPOL *self, void *pPtr)
{
	T_MEMPOL_MEMBLK *mblk;

	/* %jp{ポインタ範囲チェック */
	if ( pPtr < (void *)self->pBase || pPtr >= (void *)((char *)self->pBase + self->MemSize) )
	{
		return 0;	/* このメモリプールの所属でない */
	}

	/* %jp{メモリブロック位置を取得 */
	mblk = (T_MEMPOL_MEMBLK *)((char *)pPtr - MEMPOL_MEMBLK_SIZE);

	/* %jp{パラメーターチェック */
	if ( mblk->iFlag != MEMPOL_USING )	/* %jp{使用中で無ければ */
	{
		return 0;	/* 割り当ていない */
	}

	/* サイズを返す */
	return mblk->Size;
}

