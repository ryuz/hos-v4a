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
  Dキャッシュ無効化
  void  vdis_dcache(void);
 ************************************************/
                .global vdis_dcache
vdis_dcache:
                mrc     p15, 0, r1, c1, c0, 0   /* Read System Control Register configuration data */
                bic     r1, r1, #0x1 << 2
                dsb
                mcr     p15, 0, r1, c1, c0, 0   /* disabled data cache */
                /* Clean entire data cache. This routine depends on the data cache size. It can be
                   omitted if it is known that the data cache has no dirty data. */
                bx      lr

                .end

/* end of file */
