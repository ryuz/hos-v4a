/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  arraybuf.h
 * @brief %jp{リストバッファクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__array_h__
#define __HOS__array_h__


#include "library/container/memheap/memheap.h"

/* エラーコード */
#define ARRAY_ERR_OK			0
#define ARRAY_ERR_NG			(-1)

/* サイズ拡張時の単位 */
#define ARRAY_SIZE_UNIT			16

typedef int		ARRAY_ERR;
typedef int		ARRAY_INDEX;


/* ストリームバッファクラス */
typedef struct c_array
{
	C_MEMHEAP	*pMemHeap;	/* 利用するメモリI/F */
	void		**ppArray;	/* データ配列 */
	ARRAY_INDEX	ArraySize;	/* 配列サイズ */
	ARRAY_INDEX	Size;		/* 配列要素のサイズ */
} C_ARRAY;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void        Array_Create(C_ARRAY *self);													/* 配列クラスの生成 */
void        Array_CreateEx(C_ARRAY *self, C_MEMHEAP *pMemHeap);								/* 配列クラスの生成 */
void        Array_Delete(C_ARRAY *self);													/* 配列クラスの削除 */

/* 操作 */
ARRAY_INDEX Array_GetSize(C_ARRAY *self);													/* 配列サイズの取得 */
ARRAY_ERR   Array_SetSize(C_ARRAY *self, ARRAY_INDEX Size);									/* 配列サイズの設定 */
void        Array_Clear(C_ARRAY *self);														/* 配列のクリア */
ARRAY_ERR   Array_Add(C_ARRAY *self, const void *pData, long lSize);						/* データの追加 */
ARRAY_ERR   Array_SetAt(C_ARRAY *self, ARRAY_INDEX Index, const void *pData, long lSize);	/* データの設定 */
void       *Array_GetAt(C_ARRAY *self, ARRAY_INDEX Index);									/* データの挿入 */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__array_h__ */


/* end of file */
