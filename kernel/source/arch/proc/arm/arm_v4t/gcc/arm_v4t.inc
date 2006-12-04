/** 
 *  Hyper Operating System V4 Advance
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/* %jp{割込みハンドラ番号}%en{interruput handler number} */
#define INHNO_IRQ		0
#define INHNO_FIQ		1


/* %jp{_KERNEL_T_ICTXCB構造体オフセット} */
#define ICTXCB_IMSK		0
#define ICTXCB_INTCNT	1
#define ICTXCB_ISP		4


/* %jp{プロセッサモード定義} */
#define Mode_USR		0x10		/* USR モード */
#define Mode_FIQ		0x11		/* FIQ モード */
#define Mode_IRQ		0x12		/* IRQ モード */
#define Mode_SVC		0x13		/* SVC モード */
#define Mode_ABT		0x17		/* ABT モード */
#define Mode_UND		0x1b		/* UND モード */
#define Mode_SYS		0x1f		/* SYS モード */
#define Mode_MASK		0x1f		/* モードビットマスク */

/* %jp{フラグ定義} */
#define T_Bit			0x20		/* T ビット */
#define F_Bit			0x40		/* F ビット */
#define I_Bit			0x80		/* I ビット */


/* end of file */
