/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2021 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"

              .text
              .align    2

/************************************************
  ECC無効化 (必ずキャッシュOFF状態で呼ぶこと)
  void 	vdis_ecc(void);
 ************************************************/
                .global vdis_ecc
vdis_ecc:
                mrc     p15, 0, r1, c1, c0, 1   /* Read Auxiliary Control Register */
                orr     r0, r0, #(0x1 << 5)     /* Disable parity checking, with [5:3]= b100 */
                bic     r0, r0, #(0x1 << 4)
                bic     r0, r0, #(0x1 << 3)
                mcr     p15, 0, r1, c1, c0, 1   /* Write Auxiliary Control Register */
                bx      lr

                .end

/* end of file */
