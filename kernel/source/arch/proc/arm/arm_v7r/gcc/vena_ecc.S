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
  ECC有効化 (必ずキャッシュOFF状態で呼ぶこと)
  void 	vena_ecc(void);
 ************************************************/
                .global vena_ecc
vena_ecc:
                mrc     p15, 0, r1, c1, c0, 1   /* Read Auxiliary Control Register */
                bic     r0, r0, #(0x1 << 5)     /* Generate abort on parity errors, with [5:3]= b000 */
                bic     r0, r0, #(0x1 << 4)
                bic     r0, r0, #(0x1 << 3)
                mcr     p15, 0, r1, c1, c0, 1   /* Write Auxiliary Control Register */
                bx      lr

                .end


/* end of file */
