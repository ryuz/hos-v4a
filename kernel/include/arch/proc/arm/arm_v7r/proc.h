/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctl.h
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__arm__arm_v7r__proc_h__
#define _KERNEL__arch__proc__arm__arm_v7r__proc_h__


#define _KERNEL_IMSK_F		0x40		/**< %jp{FIQ割込みマスクビット} */
#define _KERNEL_IMSK_I		0x80		/**< %jp{IRQ割込みマスクビット} */

#define _KERNEL_IMSK_LV0	0xc0		/**< %jp{割込みマスクレベル0(すべてマスク)} */
#define _KERNEL_IMSK_LV1	0x80		/**< %jp{割込みマスクレベル1(FIQのみ許可)} */
#define _KERNEL_IMSK_LV2	0x00		/**< %jp{割込みマスクレベル2(すべて許可)} */



/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	VP_INT  sp;
} _KERNEL_T_CTXCB;

/** %jp{割込みコンテキスト制御ブロック} */
typedef struct _kernel_t_ictxcb
{
	UB  imsk;
	UB	intcnt;
	VP	isp;
} _KERNEL_T_ICTXCB;


extern _KERNEL_T_ICTXCB _kernel_ictxcb;		/**< %jp{割込みコンテキスト制御ブロック} */



#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ini_prc(void);																		/**< %jp{プロセッサ初期化} */

void    _kernel_ena_int(void);																		/**< %jp{割込み許可} */
void    _kernel_dis_int(void);																		/**< %jp{割込み禁止} */
void    _kernel_wai_int(void);																		/**< %jp{割込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, VP isp, FP entry, VP_INT par1, VP_INT par2);		/**< %jp{実行コンテキストの作成} */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの削除} */
void    _kernel_rst_ctx(VP_INT par1, VP_INT par2, FP entry, VP isp);								/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxinf_nxt, _KERNEL_T_CTXCB *pk_ctxcb_now);				/**< %jp{実行コンテキストの切替} */


/* exception handler */
void    _kernel_und_hdr(void);
void    _kernel_swi_hdr(void);
void    _kernel_pre_hdr(void);
void    _kernel_abt_hdr(void);
void    _kernel_irq_hdr(void);
void    _kernel_fiq_hdr(void);

/* Cache control */
void    vena_cache(void);       /* Enable All Cache */
void    vdis_cache(void);       /* Disable All Cache */
void    vena_icache(void);      /* Enable I-Cache */
void    vdis_icache(void);      /* Disable I-Cache */
void    vena_dcache(void);      /* Enable D-Cache */
void    vdis_dcache(void);      /* Disable D-Cache */
void    vena_ecc(void);         /* Enable ECC */
void    vdis_ecc(void);         /* Enable ECC */
void    vena_bpredict(void);    /* Enable barnch prediction */
void    vdis_bpredict(void);    /* Disable barnch prediction */

/* Access to CP15 */
UW      _kernel_read_cp15_c0_c0_4(void);	/* read MPU Type Register */

void    _kernel_write_cp15_c6_c1_0(UW v);	/* write MPU Region Size and Enable Registers */
UW      _kernel_read_cp15_c6_c1_0(void);	/* read MPU Region Size and Enable Registers */

void    _kernel_write_cp15_c6_c2_0(UW v);	/* write MPU Region Number Register */
UW      _kernel_read_cp15_c6_c2_0(void);	/* read MPU Region Number Register */

void    _kernel_write_cp15_c6_c1_4(UW v);	/* write MPU Region Access Control Register */
UW      _kernel_read_cp15_c6_c1_4(void);	/* read MPU Region Access Control Register */

void    _kernel_write_cp15_c6_c1_2(UW v);	/* write Data MPU Region Size and Enable Register */
UW      _kernel_read_cp15_c6_c1_2(void);	/* read Data MPU Region Size and Enable Register */


#ifdef __cplusplus
}
#endif



#define _KERNEL_INI_PRC()			_kernel_ini_prc();												/**< %jp{プロセッサ固有の初期化} */

#define _KERNEL_INI_INT(stksz, stk)	do { _kernel_ictxcb.isp = (VB *)(stk) + (stksz); } while (0)	/**< %jp{割込み初期化} */
#define _KERNEL_ENA_INT()			_kernel_ena_int()												/**< %jp{割込み許可} */
#define _KERNEL_DIS_INT()			_kernel_dis_int()												/**< %jp{割込み禁止} */
#define _KERNEL_WAI_INT()			_kernel_wai_int()												/**< %jp{割込み待ち(アイドル時の処理)} */

#define _KERNEL_CRE_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_cre_ctx((pk_ctxcb), (isp), (entry), (exinf1), (exinf2))	/**< %jp{実行コンテキストの作成} */	
#define _KERNEL_DEL_CTX(pk_ctxcb)	do {} while (0)													/**< %jp{実行コンテキストの削除} */
#define _KERNEL_RST_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_rst_ctx((exinf1), (exinf2), (entry), (isp))				/**< %jp{実行コンテキストのリスタート} */
#define _KERNEL_STA_CTX(pk_ctxcb)	_kernel_sta_ctx(pk_ctxcb)
#define _KERNEL_SWI_CTX(pk_ctxcb_now, pk_ctxinf_nxt)							\
									_kernel_swi_ctx((pk_ctxinf_nxt), (pk_ctxcb_now))				/**< %jp{実行コンテキストの切替} */


#define _KERNEL_MPU_DISABLE					(0)
#define _KERNEL_MPU_SIZE_32					((0x04 << 1) | 1)
#define _KERNEL_MPU_SIZE_64					((0x05 << 1) | 1)
#define _KERNEL_MPU_SIZE_128				((0x06 << 1) | 1)
#define _KERNEL_MPU_SIZE_256				((0x07 << 1) | 1)
#define _KERNEL_MPU_SIZE_512				((0x08 << 1) | 1)
#define _KERNEL_MPU_SIZE_1K					((0x09 << 1) | 1)
#define _KERNEL_MPU_SIZE_2K					((0x0a << 1) | 1)
#define _KERNEL_MPU_SIZE_4K					((0x0b << 1) | 1)
#define _KERNEL_MPU_SIZE_8K					((0x0c << 1) | 1)
#define _KERNEL_MPU_SIZE_16K				((0x0d << 1) | 1)
#define _KERNEL_MPU_SIZE_32K				((0x0e << 1) | 1)
#define _KERNEL_MPU_SIZE_64K				((0x0f << 1) | 1)
#define _KERNEL_MPU_SIZE_128K				((0x10 << 1) | 1)
#define _KERNEL_MPU_SIZE_256K				((0x11 << 1) | 1)
#define _KERNEL_MPU_SIZE_512K				((0x12 << 1) | 1)
#define _KERNEL_MPU_SIZE_1M					((0x13 << 1) | 1)
#define _KERNEL_MPU_SIZE_2M					((0x14 << 1) | 1)
#define _KERNEL_MPU_SIZE_4M					((0x15 << 1) | 1)
#define _KERNEL_MPU_SIZE_8M					((0x16 << 1) | 1)
#define _KERNEL_MPU_SIZE_16M				((0x17 << 1) | 1)
#define _KERNEL_MPU_SIZE_32M				((0x18 << 1) | 1)
#define _KERNEL_MPU_SIZE_64M				((0x19 << 1) | 1)
#define _KERNEL_MPU_SIZE_128M				((0x1a << 1) | 1)
#define _KERNEL_MPU_SIZE_256M				((0x1b << 1) | 1)
#define _KERNEL_MPU_SIZE_512M				((0x1c << 1) | 1)
#define _KERNEL_MPU_SIZE_1G					((0x1d << 1) | 1)
#define _KERNEL_MPU_SIZE_2G					((0x1e << 1) | 1)
#define _KERNEL_MPU_SIZE_4G					((0x1f << 1) | 1)

#define _KERNEL_MPU_XN						(1 << 12)
#define _KERNEL_MPU_S						(1 << 2)

#define _KERNEL_MPU_AP_NO					(0x0 << 8)
#define _KERNEL_MPU_AP_FULL					(0x3 << 8)

#define _KERNEL_MPU_STRONGLY_ORDERED		((0x0 << 3) | 0x0)
#define _KERNEL_MPU_SHAREABLE_DEVICE		((0x0 << 3) | 0x1)
#define _KERNEL_MPU_WRITE_THROUGH			((0x0 << 3) | 0x2)
#define _KERNEL_MPU_WRITE_BACK				((0x0 << 3) | 0x3)
#define _KERNEL_MPU_NO_CACHEABLE			((0x1 << 3) | 0x0)
#define _KERNEL_MPU_WRITE_BACK_ALLOC		((0x1 << 3) | 0x3)
#define _KERNEL_MPU_NON_SHAREABLE_DEVICE	((0x2 << 3) | 0x0)

#define _KERNEL_MPU_2_NO_CACHEABLE			((0x4 << 3) | 0x0)
#define _KERNEL_MPU_2_WRITE_BACK_ALLOC		((0x4 << 3) | 0x1)
#define _KERNEL_MPU_2_WRITE_THROUGH			((0x4 << 3) | 0x2)
#define _KERNEL_MPU_2_WRITE_BACK			((0x4 << 3) | 0x3)

#define vmpu_get_number_of_regions()		((_kernel_read_cp15_c0_c0_4() >> 8) & 0xff)
#define vmpu_set_region_number(v)			do { _kernel_write_cp15_c6_c2_0(v); } while(0)
#define vmpu_set_region_base_address(v)		do { _kernel_write_cp15_c6_c1_0(v); } while(0)
#define vmpu_set_region_size(v)				do { _kernel_write_cp15_c6_c1_2(v); } while(0)
#define vmpu_set_region_access_control(v)   do { _kernel_write_cp15_c6_c1_4(v); } while(0)


#endif	/* _KERNEL__arch__proc__arm__arm_v7r__proc_h__ */


/* end of file */
