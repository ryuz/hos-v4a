/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle_local.h
 * @brief %jp{ハンドル ローカルヘッダファイル}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__handle_local_h__
#define __HOS__handle_local_h__


#include "system/handle/handle.h"


/* オブジェクトクラスのメソッドテーブル定義 */
typedef struct t_object_methods
{
	const char	*pszObjectIdentify;
	void		(*pfncDelete)(HANDLE Handle);		/* 削除 */
} T_OBJECT_METHODS;


struct c_ownerobj;

/* オブジェクトクラス定義 */
typedef struct c_object
{
	const T_OBJECT_METHODS		*pMethods;
	
	struct c_ownerobj			*pParent;			/* 親プロセスのハンドル */
	struct c_object				*pNext;				/* 次のハンドル */
	struct c_object				*pPrev;				/* 前のハンドル */
} C_OBJECT;


/* ターゲットオブジェクト */
typedef struct c_targetobj
{
	C_OBJECT					Object;				/* 親クラスを継承 */

	int							iDeleteFlag;		/* 削除フラグ */
	int							iRefCounter;		/* 参照カウンタ */
} C_TARGETOBJ;


/* ハンドルオブジェクト */
typedef struct c_pointerobj
{
	C_OBJECT					Object;

	C_TARGETOBJ					*pTargetObj;
} C_POINTEROBJ;


/* オーナーオブジェクトクラス定義 */
typedef struct c_ownerobj
{
	C_TARGETOBJ					TargetObj;			/* 親クラスを継承 */

	struct c_object				*pChild;			/* 子オブジェクト */
} C_OWNEROBJ;


#ifdef __cplusplus
extern "C" {
#endif

void    Object_Constructor(C_OBJECT *self, const T_OBJECT_METHODS *pMethods, C_OWNEROBJ *pParent);				/**< コンストラクタ */
void    Object_Destructor(C_OBJECT *self);																		/**< デストラクタ */
void    Object_SetParent(C_OBJECT *self, C_OWNEROBJ *pParent);													/**< 親の設定 */

void    TargetObj_Constructor(C_TARGETOBJ *self, const T_OBJECT_METHODS *pMethods);								/**< コンストラクタ */
void    TargetObj_Destructor(C_TARGETOBJ *self);																/**< デストラクタ */
#define TargetObj_SetDeleteFlag(self)		do{ ((C_TARGETOBJ *)(self))->iDeleteFlag = 1; } while(0)			/**< 削除フラグセット */
#define TargetObj_GetDeleteFlag(self)		(((C_TARGETOBJ *)(self))->iDeleteFlag)								/**< 削除フラグ取得 */
#define TargetObj_GetRefCounter(self)		(((C_TARGETOBJ *)(self))->iRefCounter)								/**< 参照カウンタ取得 */

HANDLE  PointerObj_Create(const T_OBJECT_METHODS *pMethods, C_TARGETOBJ *pTargetObj);							/**< 生成 */
void    PointerObj_Delete(HANDLE handle);																		/**< 削除 */
void    PointerObj_Constructor(C_POINTEROBJ *self, const T_OBJECT_METHODS *pMethods, C_TARGETOBJ *pTargetObj);	/**< コンストラクタ */
void    PointerObj_Destructor(C_POINTEROBJ *self);																/**< デストラクタ */
#define PointerObj_GetTargetObj(self)	(((C_POINTEROBJ *)(self))->pTargetObj)									/**< ターゲット参照 */

void    OwnerObj_Constructor(C_OWNEROBJ *self, const T_OBJECT_METHODS *pMethods);								/**< コンストラクタ */
void    OwnerObj_Destructor(C_OWNEROBJ *self);																	/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handleobj_h__ */


/* end of file */
