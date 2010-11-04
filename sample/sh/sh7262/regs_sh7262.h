/* SH7262レジスタ定義ファイル */



#ifndef __sh7262_regs_h__
#define __sh7262_regs_h__


/* SCI0 */
#define	REG_SCI0_SMR		((volatile UH*)0xffff8000)		/* シリアルモードレジスタ_0 */
#define	REG_SCI0_BRR		((volatile UB*)0xffff8004)		/* ビットレートレジスタ_0 */
#define	REG_SCI0_SCR		((volatile UH*)0xffff8008)		/* シリアルコントロールレジスタ_0 */
#define	REG_SCI0_FTDR		((volatile UB*)0xffff800c)		/* 送信FIFOデータレジスタ_0 */
#define	REG_SCI0_SSR		((volatile UH*)0xffff8010)		/* シリアルステータスレジスタ_0 */
#define	REG_SCI0_FRDR		((volatile UB*)0xffff8014)		/* 受信FIFOデータレジスタ_0 */



#endif	/* __sh7262_regs_h__ */


/* end of file */
