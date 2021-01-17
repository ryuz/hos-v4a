/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2021 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "arm_v7r.inc"

                .text
                .align  2

/************************************************
  Iキャッシュ無効化
  void  vdis_icache(void);
 ************************************************/
                .global vdis_icache
vdis_icache:
                mrc     p15, 0, R1, c1, c0, 0   /* Read System Control Register configuration data */
                bic     r1, r1, #0x1 << 12      /* instruction cache enable */
                mcr     p15, 0, r1, c1, c0, 0   /* disabled instruction cache */
                isb
                bx      lr

                .end

/* end of file */
