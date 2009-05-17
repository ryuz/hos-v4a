/* SH7144 レジスタ定義ファイル */



#ifndef __sh7144_regs_h__
#define __sh7144_regs_h__


/* SCI0 */
#define	REG_SCI0_SMR		((volatile UB*)0xffff81a0)		/* シリアルモードレジスタ_0 */
#define	REG_SCI0_BRR		((volatile UB*)0xffff81a1)		/* ビットレートレジスタ_0 */
#define	REG_SCI0_SCR		((volatile UB*)0xffff81a2)		/* シリアルコントロールレジスタ_0 */
#define	REG_SCI0_TDR		((volatile UB*)0xffff81a3)		/* トランスミットデータレジスタ_0 */
#define	REG_SCI0_SSR		((volatile UB*)0xffff81a4)		/* シリアルステータスレジスタ_0 */
#define	REG_SCI0_RDR		((volatile UB*)0xffff81a5)		/* レシーブデータレジスタ_0 */
#define	REG_SCI0_SDCR		((volatile UB*)0xffff81a6)		/* シリアルディレクションコントロールレジスタ_0 */

/* SCI1 */
#define	REG_SCI1_SMR		((volatile UB*)0xffff81b0)		/* シリアルモードレジスタ_1 */
#define	REG_SCI1_BRR		((volatile UB*)0xffff81b1)		/* ビットレートレジスタ_1 */
#define	REG_SCI1_SCR		((volatile UB*)0xffff81b2)		/* シリアルコントロールレジスタ_1 */
#define	REG_SCI1_TDR		((volatile UB*)0xffff81b3)		/* トランスミットデータレジスタ_1 */
#define	REG_SCI1_SSR		((volatile UB*)0xffff81b4)		/* シリアルステータスレジスタ_1 */
#define	REG_SCI1_RDR		((volatile UB*)0xffff81b5)		/* レシーブデータレジスタ_1 */
#define	REG_SCI1_SDCR		((volatile UB*)0xffff81b6)		/* シリアルディレクションコントロールレジスタ_1 */

/* SCI2 */
#define	REG_SCI2_SMR		((volatile UB*)0xffff81c0)		/* シリアルモードレジスタ_2 */
#define	REG_SCI2_BRR		((volatile UB*)0xffff81c1)		/* ビットレートレジスタ_2 */
#define	REG_SCI2_SCR		((volatile UB*)0xffff81c2)		/* シリアルコントロールレジスタ_2 */
#define	REG_SCI2_TDR		((volatile UB*)0xffff81c3)		/* トランスミットデータレジスタ_2 */
#define	REG_SCI2_SSR		((volatile UB*)0xffff81c4)		/* シリアルステータスレジスタ_2 */
#define	REG_SCI2_RDR		((volatile UB*)0xffff81c5)		/* レシーブデータレジスタ_2 */
#define	REG_SCI2_SDCR		((volatile UB*)0xffff81c6)		/* シリアルディレクションコントロールレジスタ_2 */

/* SCI3 */
#define	REG_SCI3_SMR		((volatile UB*)0xffff81d0)		/* シリアルモードレジスタ_3 */
#define	REG_SCI3_BRR		((volatile UB*)0xffff81d1)		/* ビットレートレジスタ_3 */
#define	REG_SCI3_SCR		((volatile UB*)0xffff81d2)		/* シリアルコントロールレジスタ_3 */
#define	REG_SCI3_TDR		((volatile UB*)0xffff81d3)		/* トランスミットデータレジスタ_3 */
#define	REG_SCI3_SSR		((volatile UB*)0xffff81d4)		/* シリアルステータスレジスタ_3 */
#define	REG_SCI3_RDR		((volatile UB*)0xffff81d5)		/* レシーブデータレジスタ_3 */
#define	REG_SCI3_SDCR		((volatile UB*)0xffff81d6)		/* シリアルディレクションコントロールレジスタ_3 */

/* MTU 3,4 */
#define	REG_MTU3_TCR		((volatile UB*)0xffff8200)		/* タイマコントロールレジスタ_3 */
#define	REG_MTU4_TCR		((volatile UB*)0xffff8201)		/* タイマコントロールレジスタ_4 */
#define	REG_MTU3_TMDR		((volatile UB*)0xffff8202)		/* タイマモードレジスタ_3 */
#define	REG_MTU4_TMDR		((volatile UB*)0xffff8203)		/* タイマモードレジスタ_4 */
#define	REG_MTU3_TIORH	 	((volatile UB*)0xffff8204)		/* タイマI/O コントロールレジスタH_3 */
#define	REG_MTU3_TIORL	 	((volatile UB*)0xffff8205)		/* タイマI/O コントロールレジスタL_3 */
#define	REG_MTU4_TIORH	 	((volatile UB*)0xffff8206)		/* タイマI/O コントロールレジスタH_4 */
#define	REG_MTU4_TIORL	 	((volatile UB*)0xffff8207)		/* タイマI/O コントロールレジスタL_4 */
#define	REG_MTU3_TIER		((volatile UB*)0xffff8208)		/* タイマインタラプトイネーブルレジスタ_3 */
#define	REG_MTU4_TIER		((volatile UB*)0xffff8209)		/* タイマインタラプトイネーブルレジスタ_4 */
#define	REG_MTU_TOER		((volatile UB*)0xffff820a)		/* タイマアウトプットマスタイネーブルレジスタ */
#define	REG_MTU_TOCR		((volatile UB*)0xffff820b)		/* タイマアウトプットコントロールレジスタ */
#define	REG_MTU_TGCR		((volatile UB*)0xffff820d)		/* タイマゲートコントロールレジスタ */
#define	REG_MTU3_TCNT		((volatile UH*)0xffff8210)		/* タイマカウンタ_3 */
#define	REG_MTU4_TCNT		((volatile UH*)0xffff8212)		/* タイマカウンタ_4 */
#define	REG_MTU_TCDR		((volatile UH*)0xffff8214)		/* タイマ周期データレジスタ */
#define	REG_MTU_TDDR		((volatile UH*)0xffff8216)		/* タイマデッドタイムデータレジスタ */
#define	REG_MTU3_TGRA		((volatile UH*)0xffff8218)		/* タイマジェネラルレジスタA_3 */
#define	REG_MTU3_TGRB		((volatile UH*)0xffff821a)		/* タイマジェネラルレジスタB_3 */
#define	REG_MTU4_TGRA		((volatile UH*)0xffff821c)		/* タイマジェネラルレジスタA_4 */
#define	REG_MTU4_TGRB		((volatile UH*)0xffff821e)		/* タイマジェネラルレジスタB_4 */
#define	REG_MTU_TCNTS		((volatile UH*)0xffff8220)		/* タイマサブカウンタ */
#define	REG_MTU_TCBR		((volatile UH*)0xffff8222)		/* タイマ周期バッファレジスタ */
#define	REG_MTU3_TGRC		((volatile UH*)0xffff8224)		/* タイマジェネラルレジスタC_3 */
#define	REG_MTU3_TGRD		((volatile UH*)0xffff8226)		/* タイマジェネラルレジスタD_3 */
#define	REG_MTU4_TGRC		((volatile UH*)0xffff8228)		/* タイマジェネラルレジスタC_4 */
#define	REG_MTU4_TGRD		((volatile UH*)0xffff822a)		/* タイマジェネラルレジスタD_4 */
#define	REG_MTU3_TSR		((volatile UB*)0xffff822c)		/* タイマステータスレジスタ_3 */
#define	REG_MTU4_TSR		((volatile UB*)0xffff822d)		/* タイマステータスレジスタ_4 */

/* MTU(common) */
#define	REG_MTU_TSTR		((volatile UB*)0xffff8240)		/* タイマスタートレジスタ */
#define	REG_MTU_TSYR		((volatile UB*)0xffff8241)		/* タイマシンクロレジスタ */

/* MTU0 */
#define	REG_MTU0_TCR		((volatile UB*)0xffff8260)		/* タイマコントロールレジスタ_0 */
#define	REG_MTU0_TMDR		((volatile UB*)0xffff8261)		/* タイマモードレジスタ_0 */
#define	REG_MTU0_TIORH	 	((volatile UB*)0xffff8262)		/* タイマI/OコントロールレジスタH_0 */
#define	REG_MTU0_TIORL	 	((volatile UB*)0xffff8263)		/* タイマI/OコントロールレジスタL_0 */
#define	REG_MTU0_TIER		((volatile UB*)0xffff8264)		/* タイマインタラプトイネーブルレジスタ_0 */
#define	REG_MTU0_TSR		((volatile UB*)0xffff8265)		/* タイマステータスレジスタ_0 */
#define	REG_MTU0_TCNT		((volatile UH*)0xffff8266)		/* タイマカウンタ_0 */
#define	REG_MTU0_TGRA		((volatile UH*)0xffff8268)		/* タイマジェネラルレジスタA_0 */
#define	REG_MTU0_TGRB		((volatile UH*)0xffff826a)		/* タイマジェネラルレジスタB_0 */
#define	REG_MTU0_TGRC		((volatile UH*)0xffff826c)		/* タイマジェネラルレジスタC_0 */
#define	REG_MTU0_TGRD		((volatile UH*)0xffff826e)		/* タイマジェネラルレジスタD_0 */

/* MTU1 */
#define	REG_MTU1_TCR		((volatile UB*)0xffff8280)		/* タイマコントロールレジスタ_1 */
#define	REG_MTU1_TMDR		((volatile UB*)0xffff8281)		/* タイマモードレジスタ_1 */
#define	REG_MTU1_TIOR		((volatile UB*)0xffff8282)		/* タイマI/Oコントロールレジスタ_1 */
#define	REG_MTU1_TIER		((volatile UB*)0xffff8284)		/* タイマインタラプトイネーブルレジスタ_1 */
#define	REG_MTU1_TSR		((volatile UB*)0xffff8285)		/* タイマステータスレジスタ_1 */
#define	REG_MTU1_TCNT		((volatile UH*)0xffff8286)		/* タイマカウンタ_1 */
#define	REG_MTU1_TGRA		((volatile UH*)0xffff8288)		/* タイマジェネラルレジスタA_1 */
#define	REG_MTU1_TGRB		((volatile UH*)0xffff828a)		/* タイマジェネラルレジスタB_1 */

/* MTU2 */
#define	REG_MTU2_TCR		((volatile UB*)0xffff82a0)		/* タイマコントロールレジスタ_2 */
#define	REG_MTU2_TMDR		((volatile UB*)0xffff82a1)		/* タイマモードレジスタ_2 */
#define	REG_MTU2_TIOR		((volatile UB*)0xffff82a2)		/* タイマI/O コントロールレジスタ_2 */
#define	REG_MTU2_TIER		((volatile UB*)0xffff82a4)		/* タイマインタラプトイネーブルレジスタ_2 */
#define	REG_MTU2_TSR		((volatile UB*)0xffff82a5)		/* タイマステータスレジスタ_2 */
#define	REG_MTU2_TCNT		((volatile UH*)0xffff82a6)		/* タイマカウンタ_2 */
#define	REG_MTU2_TGRA		((volatile UH*)0xffff82a8)		/* タイマジェネラルレジスタA_2 */
#define	REG_MTU2_TGRB		((volatile UH*)0xffff82aa)		/* タイマジェネラルレジスタB_2 */

/* INTC */
#define	REG_INTC_IPRA		((volatile UH*)0xffff8348)		/* インタラプトプライオリティレジスタA */
#define	REG_INTC_IPRB		((volatile UH*)0xffff834a)		/* インタラプトプライオリティレジスタB */
#define	REG_INTC_IPRC		((volatile UH*)0xffff834c)		/* インタラプトプライオリティレジスタC */
#define	REG_INTC_IPRD		((volatile UH*)0xffff834e)		/* インタラプトプライオリティレジスタD */
#define	REG_INTC_IPRE		((volatile UH*)0xffff8350)		/* インタラプトプライオリティレジスタE */
#define	REG_INTC_IPRF		((volatile UH*)0xffff8352)		/* インタラプトプライオリティレジスタF */
#define	REG_INTC_IPRG		((volatile UH*)0xffff8354)		/* インタラプトプライオリティレジスタG */
#define	REG_INTC_IPRH		((volatile UH*)0xffff8356)		/* インタラプトプライオリティレジスタH */
#define	REG_INTC_ICR1		((volatile UH*)0xffff8358)		/* 割込みコントロールレジスタ1 */
#define	REG_INTC_ISR 		((volatile UH*)0xffff835a)		/* IRQステータスレジスタ */
#define	REG_INTC_IPRI		((volatile UH*)0xffff835c)		/* インタラプトプライオリティレジスタI */
#define	REG_INTC_IPRJ		((volatile UH*)0xffff835e)		/* インタラプトプライオリティレジスタJ */
#define	REG_INTC_ICR2		((volatile UH*)0xffff8366)		/* 割込みコントロールレジスタ2 */

/* I/O, PFC (port-A) */
#define	REG_PA_DR			((volatile UW*)0xffff8380)		/* ポートA データレジスタ(H/L) */
#define	REG_PA_DRH			((volatile UH*)0xffff8380)		/* ポートA データレジスタH */
#define	REG_PA_DRL			((volatile UH*)0xffff8382)		/* ポートA データレジスタL */
#define	REG_PFC_PAIORH		((volatile UH*)0xffff8384)		/* ポートA IOレジスタH */
#define	REG_PFC_PAIORL		((volatile UH*)0xffff8386)		/* ポートA IOレジスタL */
#define	REG_PFC_PACRH		((volatile UH*)0xffff8388)		/* ポートAコントロールレジスタH */
#define	REG_PFC_PACRL1		((volatile UH*)0xffff838c)		/* ポートAコントロールレジスタL1 */
#define	REG_PFC_PACRL2		((volatile UH*)0xffff838e)		/* ポートAコントロールレジスタL2 */

/* I/O, PFC (port-B, C) */
#define	REG_PB_DR			((volatile UH*)0xffff8388)		/* ポートB データレジスタ */
#define	REG_PC_DR			((volatile UH*)0xffff8388)		/* ポートC データレジスタ */
#define	REG_PFC_PBIOR		((volatile UH*)0xffff8394)		/* ポートB IOレジスタ */
#define	REG_PFC_PCIOR		((volatile UH*)0xffff8396)		/* ポートC IOレジスタ */
#define	REG_PFC_PBCR1		((volatile UH*)0xffff8398)		/* ポートBコントロールレジスタ1 */
#define	REG_PFC_PBCR2		((volatile UH*)0xffff839a)		/* ポートBコントロールレジスタ2 */
#define	REG_PFC_PCCR		((volatile UH*)0xffff839c)		/* ポートCコントロールレジスタ2 */

/* I/O, PFC (port-D) */
#define	REG_PD_DR			((volatile UW*)0xffff83a0)		/* ポートD・データレジスタ(H/L) */
#define	REG_PD_DRH			((volatile UH*)0xffff83a0)		/* ポートD・データレジスタH */
#define	REG_PD_DRL			((volatile UH*)0xffff83a2)		/* ポートD・データレジスタL */
#define	REG_PFC_PDIORH		((volatile UH*)0xffff83a4)		/* ポートD・IOレジスタH */
#define	REG_PFC_PDIORL		((volatile UH*)0xffff83a6)		/* ポートD・IOレジスタL */
#define	REG_PFC_PDCRH1		((volatile UH*)0xffff83a8)		/* ポートDコントロールレジスタH1 */
#define	REG_PFC_PDCRH2		((volatile UH*)0xffff83aa)		/* ポートDコントロールレジスタH2 */
#define	REG_PFC_PDCRL1		((volatile UH*)0xffff83ac)		/* ポートDコントロールレジスタL1 */
#define	REG_PFC_PDCRL2		((volatile UH*)0xffff83ae)		/* ポートDコントロールレジスタL2 */

/* I/O, PFC (port-E, F) */
#define	REG_PE_DRL			((volatile UH*)0xffff83b0)		/* ポートE データレジスタL */
#define	REG_PF_DR			((volatile UB*)0xffff83b3)		/* ポートF データレジスタ */
#define	REG_PFC_PEIORL		((volatile UH*)0xffff83b4)		/* ポートE IO レジスタL */
#define	REG_PFC_PECRL1		((volatile UH*)0xffff83b8)		/* ポートE コントロールレジスタL1 */
#define	REG_PFC_PECRL2		((volatile UH*)0xffff83ba)		/* ポートE コントロールレジスタL2 */

/* POE */
#define	REG_POE_ICSR1		((volatile UH*)0xffff83c0)		/* 入力レベルコントロール／ステータスレジスタ1 */
#define	REG_POE_OCSR		((volatile UH*)0xffff83c2)		/* 出力レベルコントロール／ステータスレジスタ */

/* CMT */
#define	REG_CMT_CMSTR		((volatile UH*)0xffff83d0)		/* コンペアマッチタイマスタートレジスタ */
#define	REG_CMT0_CMCSR 		((volatile UH*)0xffff83d2)		/* コンペアマッチタイマコントロール／ステータスレジスタ_0 */
#define	REG_CMT0_CMCNT 		((volatile UH*)0xffff83d4)		/* コンペアマッチタイマカウンタ_0 */
#define	REG_CMT0_CMCOR 		((volatile UH*)0xffff83d6)		/* コンペアマッチタイマコンスタントレジスタ_0 */
#define	REG_CMT1_CMCSR 		((volatile UH*)0xffff83d8)		/* コンペアマッチタイマコントロール／ステータスレジスタ_1 */
#define	REG_CMT1_CMCNT 		((volatile UH*)0xffff83da)		/* コンペアマッチタイマカウンタ_1 */
#define	REG_CMT1_CMCOR 		((volatile UH*)0xffff83dc)		/* コンペアマッチタイマコンスタントレジスタ_1 */

/* AD */
#define	REG_AD0_ADDR0		((volatile UH*)0xffff8420)		/* A/Dデータレジスタ0 */
#define	REG_AD0_ADDR1		((volatile UH*)0xffff8422)		/* A/Dデータレジスタ1 */
#define	REG_AD0_ADDR2		((volatile UH*)0xffff8424)		/* A/Dデータレジスタ2 */
#define	REG_AD0_ADDR3		((volatile UH*)0xffff8426)		/* A/Dデータレジスタ3 */
#define	REG_AD1_ADDR4		((volatile UH*)0xffff8428)		/* A/Dデータレジスタ4 */
#define	REG_AD1_ADDR5		((volatile UH*)0xffff842a)		/* A/Dデータレジスタ5 */
#define	REG_AD1_ADDR6		((volatile UH*)0xffff842c)		/* A/Dデータレジスタ6 */
#define	REG_AD1_ADDR7		((volatile UH*)0xffff842e)		/* A/Dデータレジスタ7 */
#define	REG_AD0_ADCSR	 	((volatile UB*)0xffff8480)		/* A/Dコントロール／ステータスレジスタ_0 */
#define	REG_AD1_ADCSR	 	((volatile UB*)0xffff8481)		/* A/Dコントロール／ステータスレジスタ_1 */
#define	REG_AD0_ADCR		((volatile UB*)0xffff8488)		/* A/Dコントロールレジスタ_0 */
#define	REG_AD1_ADCR		((volatile UB*)0xffff8489)		/* A/Dコントロールレジスタ_1 */

/* FLASH */
#define	REG_FLASH_FLMCR1	((volatile UB*)0xffff8580)		/* フラッシュメモリコントロールレジスタ1 */
#define	REG_FLASH_FLMCR2	((volatile UB*)0xffff8581)		/* フラッシュメモリコントロールレジスタ2 */
#define	REG_FLASH_EBR1		((volatile UB*)0xffff8582)		/* 消去ブロック指定レジスタ1 */
#define	REG_FLASH_EBR2		((volatile UB*)0xffff8583)		/* 消去ブロック指定レジスタ2 */

/* UBC */
#define	REG_UBC_UBARH		((volatile UH*)0xffff8600)		/* ユーザブレークアドレスレジスタH */
#define	REG_UBC_UBARL		((volatile UH*)0xffff8602)		/* ユーザブレークアドレスレジスタL */
#define	REG_UBC_UBAMRH		((volatile UH*)0xffff8604)		/* ユーザブレークアドレスマスクレジスタH */
#define	REG_UBC_UBAMRL		((volatile UH*)0xffff8606)		/* ユーザブレークアドレスマスクレジスタL */
#define	REG_UBC_UBBR		((volatile UH*)0xffff8608)		/* ユーザブレークバスサイクルレジスタ */
#define	REG_UBC_UBCR		((volatile UH*)0xffff860a)		/* ユーザブレークコントロールレジスタ */

/* WDT */
#define	REG_WDT_TCSR		((volatile UB*)0xffff8610)		/* タイマコントロール／ステータスレジスタ */
#define	REG_WDT_TCNT_W		((volatile UB*)0xffff8610)		/* タイマカウンタ(Read) */
#define	REG_WDT_TCNT_R		((volatile UB*)0xffff8611)		/* タイマカウンタ(Write) */
#define	REG_WDT_RSTCSR_1	((volatile UB*)0xffff8612)		/* リセットコントロール／ステータスレジスタ */
#define	REG_WDT_RSTCSR_2	((volatile UB*)0xffff8613)		/* リセットコントロール／ステータスレジスタ */

/* Standby*/
#define	REG_STANDBY_SBYCR	((volatile UB*)0xffff8614)		/* スタンバイコントロールレジスタ */
#define	REG_STANDBY_SYSCR	((volatile UB*)0xffff8618)		/* システムコントロールレジスタ */
#define	REG_STANDBY_MSTCR1	((volatile UH*)0xffff861c)		/* モジュールスタンバイコントロールレジスタ1 */
#define	REG_STANDBY_MSTCR2	((volatile UH*)0xffff861e)		/* モジュールスタンバイコントロールレジスタ2 */

/* BSC */
#define	REG_BSC_BCR1		((volatile UH*)0xffff8620)		/* バスコントロールレジスタ1 */
#define	REG_BSC_BCR2		((volatile UH*)0xffff8622)		/* バスコントロールレジスタ2 */
#define	REG_BSC_WCR1		((volatile UH*)0xffff8624)		/* ウェイトコントロールレジスタ1 */
#define	REG_BSC_WCR2		((volatile UH*)0xffff8626)		/* ウェイトコントロールレジスタ2 */

/* FLASH */
#define	REG_FLASH_RAMER		((volatile UH*)0xffff8628)		/* RAMエミュレーションレジスタ */

/* DMA */
#define	REG_DMA_DMAOR		((volatile UH*)0xffff86b0)		/* DMAオペレーションレジスタ */
#define	REG_DMA0_SAR		((volatile UW*)0xffff86c0)		/* DMAソースアドレスレジスタ_0 */
#define	REG_DMA0_DAR		((volatile UW*)0xffff86c4)		/* DMAデスティネーションアドレスレジスタ_0 */
#define	REG_DMA0_DMATCR		((volatile UW*)0xffff86c8)		/* DMAトランスファカウントレジスタ_0 */
#define	REG_DMA0_CHCR		((volatile UW*)0xffff86cc)		/* DMAチャネルコントロールレジスタ_0 */
#define	REG_DMA1_SAR		((volatile UW*)0xffff86d0)		/* DMAソースアドレスレジスタ_1 */
#define	REG_DMA1_DAR		((volatile UW*)0xffff86d4)		/* DMAデスティネーションアドレスレジスタ_1 */
#define	REG_DMA1_DMATCR		((volatile UW*)0xffff86d8)		/* DMAトランスファカウントレジスタ_1 */
#define	REG_DMA1_CHCR		((volatile UW*)0xffff86dc)		/* DMAチャネルコントロールレジスタ_1 */
#define	REG_DMA2_SAR		((volatile UW*)0xffff86e0)		/* DMAソースアドレスレジスタ_2 */
#define	REG_DMA2_DAR		((volatile UW*)0xffff86e4)		/* DMAデスティネーションアドレスレジスタ_2 */
#define	REG_DMA2_DMATCR		((volatile UW*)0xffff86e8)		/* DMAトランスファカウントレジスタ_2 */
#define	REG_DMA2_CHCR		((volatile UW*)0xffff86ec)		/* DMAチャネルコントロールレジスタ_2 */
#define	REG_DMA3_SAR		((volatile UW*)0xffff86f0)		/* DMAソースアドレスレジスタ_3 */
#define	REG_DMA3_DAR		((volatile UW*)0xffff86f4)		/* DMAデスティネーションアドレスレジスタ_3 */
#define	REG_DMA3_DMATCR		((volatile UW*)0xffff86f8)		/* DMAトランスファカウントレジスタ_3 */
#define	REG_DMA3_CHCR		((volatile UW*)0xffff86fc)		/* DMAチャネルコントロールレジスタ_3 */

/* DTC */
#define	REG_DTC_DTEA		((volatile UB*)0xffff8700)		/* DTCイネーブルレジスタA */
#define	REG_DTC_DTEB		((volatile UB*)0xffff8701)		/* DTCイネーブルレジスタB */
#define	REG_DTC_DTEC		((volatile UB*)0xffff8702)		/* DTCイネーブルレジスタC */
#define	REG_DTC_DTED		((volatile UB*)0xffff8703)		/* DTCイネーブルレジスタD */
#define	REG_DTC_DTCSR		((volatile UH*)0xffff8706)		/* DTCコントロール／ステータスレジスタ */
#define	REG_DTC_DTBR		((volatile UH*)0xffff8708)		/* DTC情報ベースレジスタ */
#define	REG_DTC_DTEE		((volatile UB*)0xffff8710)		/* DTCイネーブルレジスタE */
#define	REG_DTC_DTEG		((volatile UB*)0xffff8712)		/* DTCイネーブルレジスタG */

/* IIC */
#define	REG_IIC_SCRX		((volatile UB*)0xffff87f0)		/* シリアルコントロールレジスタX */

/* AD */
#define	REG_AD_ADTSR		((volatile UB*)0xffff87f4)		/* ADトリガセレクトレジスタ */

/* Port-E */
#define	REG_PE_PPCR			((volatile UB*)0xffff87f8)		/* 大電流ポートコントロールレジスタ */

/* IIC */
#define	REG_IIC_ICCR		((volatile UB*)0xffff87f8)		/* IICバスコントロールレジスタ */
#define	REG_IIC_ICSR		((volatile UB*)0xffff87f8)		/* IICバスステータスレジスタ */
#define	REG_IIC_ICDR		((volatile UB*)0xffff87f8)		/* IICバスデータレジスタ */
#define	REG_IIC_SARX		((volatile UB*)0xffff87f8)		/* 第２スレーブアドレスレジスタ */
#define	REG_IIC_ICMR		((volatile UB*)0xffff87f8)		/* IICバスモードレジスタ */
#define	REG_IIC_SAR 		((volatile UB*)0xffff87f8)		/* スレーブアドレスレジスタ */

/* H-UDI */
#define	REG_HUDI_SDIR		((volatile UH*)0xffff8a50)		/* インストラクションレジスタ */
#define	REG_HUDI_SDSR		((volatile UH*)0xffff8a52)		/* ステータスレジスタ */
#define	REG_HUDI_SDDRH		((volatile UH*)0xffff8a54)		/* データレジスタH */
#define	REG_HUDI_SDDRL		((volatile UH*)0xffff8a56)		/* データレジスタL */


#endif	/* __sh7144_regs_h__ */


/* end of file */
