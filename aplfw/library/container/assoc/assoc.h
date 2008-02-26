/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assocbuf.h
 * @brief %jp{連想バッファクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__assoc_h__
#define __HOS__assoc_h__


#include "library/container/list/list.h"

#define ASSOC_ERR_OK		0
#define ASSOC_ERR_NG		(-1)
#define ASSOC_POS_NULL		LIST_POS_NULL

typedef void*	ASSOC_POS;
typedef int     ASSOC_ERR;


/* ストリームバッファクラス */
typedef struct c_assocbuf
{
	C_LIST	List;	/* とりあえず手抜き(そのうちB-Treeとかに....) */
	C_MEMIF	*pMemIf;
} C_ASSOC;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void        Assoc_Create(C_ASSOC *self);													/* 連想バッファの生成 */
void        Assoc_CreateEx(C_ASSOC *self, C_MEMIF *pMemIf);									/* 連想バッファの生成 */
void        Assoc_Delete(C_ASSOC *self);													/* 連想バッファの削除 */

/* 操作 */
ASSOC_ERR   Assoc_Add(C_ASSOC *self, const char *pszKey, const void *pData, long lSize);	/* データの登録 */
const void *Assoc_Get(C_ASSOC *self, const char *pszKey);									/* データの参照 */
ASSOC_ERR   Assoc_Remove(C_ASSOC *self, const char *pszKey);								/* データの削除 */

/* イテレータ操作 */
ASSOC_POS   Assoc_GetFirst(C_ASSOC *self);
ASSOC_POS   Assoc_GetNext(C_ASSOC *self, ASSOC_POS *Pos);
const void *Assoc_GetAt(C_ASSOC *self, ASSOC_POS *Pos, const char **ppszKey);

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assocbuf_h__ */

