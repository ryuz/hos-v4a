

#ifndef __HOS__mempol_h__
#define __HOS__mempol_h__


#define MEMPOL_MEMALIGN		sizeof(void *)		/**< %jp{メモリアライメント} */
#define MEMPOL_USING		0x1234				/**< %jp{使用中} */
#define MEMPOL_FREE			0xabcd				/**< %jp{未使用} */

typedef long	MEMPOL_MEMSIZE;


/** %jp{サイズアライメント} */
#define MEMPOL_ALIGNED(size)	(((size) + MEMPOL_MEMALIGN - 1) & ~(MEMPOL_MEMALIGN - 1))


/** %jp{ヒープメモリブロック} */
typedef struct t_mempol_memblk
{
	struct t_mempol_memblk* pPrev;	/**< %jp{前のブロック} */
	MEMPOL_MEMSIZE	Size;			/**< %jp{ブロックのサイズ} */
	int				iFlag;			/**< %jp{使用中フラグ} */
} T_MEMPOL_MEMBLK;


/** %jp{ヒープ制御ブロック} */
typedef struct c_mempol
{
	T_MEMPOL_MEMBLK		*pBase;		/**< %jp{カーネル用メモリ先頭ブロックのアドレス} */
	MEMPOL_MEMSIZE		MemSize;	/**< %jp{カーネル用メモリサイズ} */
} C_MEMPOL;


/** %jp{カーネルメモリ管理ブロックサイズ} */
#define MEMPOL_MEMBLK_SIZE			MEMPOL_ALIGNED(sizeof(T_MEMPOL_MEMBLK))


#ifdef __cplusplus
extern "C" {
#endif

void    MemPol_Create(C_MEMPOL *self, void *p_base, MEMPOL_MEMSIZE Size);	/**< %jp{コンストラクタ} */
#define MemPol_Delete(self)	do {} while(0)									/**< %jp{デストラクタ} */
void   *MemPol_Alloc(C_MEMPOL *self, MEMPOL_MEMSIZE Size);					/**< %jp{メモリの割り当て} */
void    MemPol_Free(C_MEMPOL *self, void *pPtr);							/**< %jp{メモリの解放} */
#define MemPol_Align(Size)		MEMPOL_ALIGNED(size)						/**< %jp{メモリサイズのアライメントを合わせる} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__mempol_h__ */


/* end of file */
