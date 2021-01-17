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
  分岐予測有効化
  void 	vena_bpredict(void);
 ************************************************/
                .global vena_bpredict
vena_bpredict:
                mrc     p15, 0, r0, c1, c0, 1       /* Read ACTLR */
                bic     r0, r0, #0x1 << 17          /* Clear RSDIS bit 17 to enable return stack */
                bic     r0, r0, #0x1 << 16          /* Clear BP bit 15 and BP bit 16 */
                bic     r0, r0, #0x1 << 15          /* Normal operation, BP is taken from the global history table */
                mcr     p15, 0, r0, c1, c0, 1       /* Write ACTLR */
                dsb
                bx      lr

                .end


/* end of file */
