/* SH7262レジスタ定義ファイル */



#ifndef __sh7262_regs_h__
#define __sh7262_regs_h__


#define REG_INTC_IPR10		((volatile UH *)0xfffe0C08)

#define	REG_STBCR7			((volatile UB *)0xfffe0418)

/* SCI0 */
#define	REG_SCI0_SMR		((volatile UH *)0xffff8000)		/* シリアルモードレジスタ_0 */
#define	REG_SCI0_BRR		((volatile UB *)0xffff8004)		/* ビットレートレジスタ_0 */
#define	REG_SCI0_SCR		((volatile UH *)0xffff8008)		/* シリアルコントロールレジスタ_0 */
#define	REG_SCI0_FTDR		((volatile UB *)0xffff800c)		/* 送信FIFOデータレジスタ_0 */
#define	REG_SCI0_SSR		((volatile UH *)0xffff8010)		/* シリアルステータスレジスタ_0 */
#define	REG_SCI0_FRDR		((volatile UB *)0xffff8014)		/* 受信FIFOデータレジスタ_0 */

/* CMT */
#define REG_CMT_CMSTR		((volatile UH *)0xfffec000)		/* コンペアマッチタイマコントロールレジスタ */
#define REG_CMT0_CMCSR		((volatile UH *)0xfffec002)		/* コンペアマッチタイマコントロール／ステータスレジスタ_0 */
#define REG_CMT0_CMCNT		((volatile UH *)0xfffec004)		/* コンペアマッチカウンタ_0 */
#define REG_CMT0_CMCOR		((volatile UH *)0xfffec006)		/* コンペアマッチコンスタントレジスタ_0 */
#define REG_CMT1_CMCSR		((volatile UH *)0xfffec008)		/* コンペアマッチタイマコントロール／ステータスレジスタ_1 */
#define REG_CMT1_CMCNT		((volatile UH *)0xfffec00a)		/* コンペアマッチカウンタ_1 */
#define REG_CMT1_CMCOR		((volatile UH *)0xfffec00c)		/* コンペアマッチコンスタントレジスタ_1 */


#endif	/* __sh7262_regs_h__ */


/* end of file */
