/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc_local.h
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__assoc_local_h__
#define __HOS__assoc_local_h__

#include "assoc.h"


#ifdef __cplusplus
extern "C" {
#endif

T_ASSOC_NODE *Assoc_GetNode(C_ASSOC *self, T_ASSOC_NODE *pNode, const char *pszKey);
T_ASSOC_NODE *Assoc_AddNode(T_ASSOC_NODE *pParent, T_ASSOC_NODE *pNode);
T_ASSOC_NODE *Assoc_GetMinNode(T_ASSOC_NODE *pNode);
void         Assoc_RemoveNode(C_ASSOC *self, T_ASSOC_NODE *pNode);

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assoc_local_h__ */

