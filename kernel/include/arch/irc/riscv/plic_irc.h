/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic-irc.h
 * @brief RISC-V Platform-Level Interrupt Controller
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc__riscv__plic__plic_irc_h__
#define _KERNEL__arch__irc__riscv__plic__plic_irc_h__

/** %jp{QEMU Platform-Level Interrupt Controller (PLIC) レジスタアドレス}   */
#define _KERNEL_RISCV_IRC_PLIC_ADDR        ((VP)(0xC000000))
/** %jp{QEMU Platform-Level Interrupt Controller (PLIC) 最低割込み優先度}   */
#define _KERNEL_RISCV_IRC_MIN_PRIO         (-7)
/** %jp{QEMU Platform-Level Interrupt Controller (PLIC) 最高割込み優先度}   */
#define _KERNEL_RISCV_IRC_MAX_PRIO         (-1)

/**< %jp{割込みコントローラレジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_REGSIZE         (4)
/**< %jp{優先度設定レジスタオフセット(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_PRIO_OFFSET     (0x0)
 /**< %jp{保留割込みレジスタオフセット(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_PEND_OFFSET     (0x1000)
/**< %jp{マシンモード割込み許可レジスタオフセット(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_MENABLE_OFFSET  (0x2000)
/**< %jp{hart単位での割込み許可レジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_ENABLE_PER_HART (0x100)
/**< %jp{マシンモード割込み優先度レジスタオフセット(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_MPRIO_OFFSET    (0x200000)
/**< %jp{hart単位での割込み優先度レジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_PRIO_PER_HART   (0x2000)
/**< %jp{マシンモード割込みクレームレジスタオフセット(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_MCLAIM_OFFSET   (0x200004)
/**< %jp{hart単位での割込みクレームレジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_IRC_PLIC_CLAIM_PER_HART  (0x2000)

/**
   %jp{優先度レジスタ取得}
   _irq %jp{割込み番号}
   返り値 %jp{PLIC優先度レジスタアドレス}
 */
#define _KERNEL_RISCV_IRC_PLIC_PRIO_REG(_irq) \
	((volatile UW *)(_KERNEL_RISCV_IRC_PLIC_ADDR + _KERNEL_RISCV_IRC_PLIC_PRIO_OFFSET + ( (_irq) * _KERNEL_RISCV_IRC_PLIC_REGSIZE ) ))

/**
   %jp{割込みペンディングレジスタ取得}
   _irq %jp{割込み番号}
   返り値  %jp{PLIC割込みペンディングレジスタアドレス}
 */
#define _KERNEL_RISCV_IRC_PLIC_PEND_REG(_irq)				\
	((volatile UW *)(_KERNEL_RISCV_IRC_PLIC_ADDR		\
	    + _KERNEL_RISCV_IRC_PLIC_PEND_OFFSET			\
	    + ( (_irq) / ( _KERNEL_RISCV_IRC_PLIC_REGSIZE * 8 ) ) ) )

/**
   %jp{割込み許可レジスタ取得}
   _hart %jp{物理プロセッサID (hart番号)}
   _irq  %jp{割込み線番号}
   返り値  %jp{割込み許可レジスタアドレス}
 */
#define _KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_hart, _irq)			\
	(((volatile UW *)(_KERNEL_RISCV_IRC_PLIC_ADDR  + _KERNEL_RISCV_IRC_PLIC_MENABLE_OFFSET + ( (_hart) * _KERNEL_RISCV_IRC_PLIC_ENABLE_PER_HART) ) ) \
	    + ( (_irq) / ( _KERNEL_RISCV_IRC_PLIC_REGSIZE * 8 ) ) )

/**
   %jp{割込み優先度レジスタ取得}
   _hart %jp{物理プロセッサID (hart番号)}
   返り値 %jp{割込み優先度レジスタアドレス}
 */
#define _KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_hart) \
	((volatile UW *)(_KERNEL_RISCV_IRC_PLIC_ADDR  + _KERNEL_RISCV_IRC_PLIC_MPRIO_OFFSET + ( (_hart) * _KERNEL_RISCV_IRC_PLIC_PRIO_PER_HART) ) )

/**
   %jp{割込みクレームレジスタ取得}
   _hart %jp{物理プロセッサID (hart番号)}
   返り値 %jp{割込みクレームレジスタアドレス}
 */
#define _KERNEL_RISCV_IRC_PLIC_MCLAIM_REG(_hart) \
	((volatile UW *)(_KERNEL_RISCV_IRC_PLIC_ADDR  + _KERNEL_RISCV_IRC_PLIC_MCLAIM_OFFSET + ( (_hart) * _KERNEL_RISCV_IRC_PLIC_CLAIM_PER_HART) ) )

/**
   %jp{割込み番号からIRQ番号を算出}
   _intno %jp{割込み番号}
   返り値 %jp{IRQ番号}
 */
#define _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(_intno)			\
	((_intno) - _KERNEL_IRCATR_PLIC_TMIN_INTNO)

/**
   %jp{割込みレジスタ中でのビット位置を立てたビットマスクを取得}
   _irq %jp{irq番号}
   返り値 %jp{ビットマスク}
 */
#define _KERNEL_RISCV_IRC_PLIC_IRQBITMASK(_irq)				\
	( (UW)1 << ( (_irq) % ( _KERNEL_RISCV_IRC_PLIC_REGSIZE * 8 ) ) )

#ifdef __cplusplus
extern "C" {
#endif

/* TODO: kernel.hに移す */
/** %jp{割込み管理機能マクロ定義} */
#define TA_ENAINT                        (0x01U)  /**< %jp{割込み要求禁止フラグをクリア */
#define TA_EDGE                          (0x02U)  /**< %jp{エッジトリガ} */
#define TA_POSEDGE                       (0x10U)  /**< %jp{ポジティブエッジトリガ} */
#define TA_NEGEDGE                       (0x20U)  /**< %jp{ネガティブエッジトリガ} */
#define TA_BOTHEDGE                      (TA_POSEDGE|TA_NEGEDGE)  /**< %jp{ネガティブエッジトリガ} */
#define TA_LOWLEVEL                      (0x40U)  /**< %jp{ローレベルトリガ} */
#define TA_HIGHLEVEL                     (0x80U)  /**< %jp{ハイレベルトリガ} */
#define TA_NONKERNEL                     (0x02U)  /**< %jp{カーネル外の割込み} */

/* %jp{割込み線情報} */
typedef struct t_cint {
	ATR intatr; /* %jp{割込み要求ライン属性} */
	PRI intpri; /* %jp{割込み優先度} */
}T_CINT;

/* %jp{割込み線の設定が可能であることを確認する} */
#define VALID_INTNO_CFGINT(_intno) \
	( ( ( _KERNEL_IRCATR_PLIC_TMIN_INTNO <= intno ) \
	    && ( _intno <= _KERNEL_IRCATR_PLIC_TMAX_INTNO  ) ) \
	    ? (E_OK) : (E_PAR) )

void _kernel_riscv_irc_plic_ini_irc(void);	  /**< %jp{割込みコントローラの初期化} */
void _kernel_riscv_irc_plic_exe_irc(INHNO inhno); /**< %jp{割込み処理} */
ER _kernel_riscv_irc_plic_ena_int(INTNO intno);   /**< %jp{割込み許可} */
ER _kernel_riscv_irc_plic_dis_int(INTNO intno);   /**< %jp{割込み禁止} */
ER _kernel_riscv_irc_plic_chg_imsk(INT imsk);     /**< %jp{割込みマスク変更} */
ER _kernel_riscv_irc_plic_get_imsk(INT *p_imsk);  /**< %jp{割込みマスク取得} */
ER _kernel_riscv_irc_plic_clr_int(INTNO intno);   /**< %jp{割込み要因クリア} */
ER _kernel_riscv_irc_plic_cfg_int(INTNO intno, T_CINT *pk_cint);   /**< %jp{割込み線設定} */


#ifdef __cplusplus
}
#endif


#endif	/* _KERNEL__arch__irc__riscv__plic__plic_irc_h__ */


/* end of file */
