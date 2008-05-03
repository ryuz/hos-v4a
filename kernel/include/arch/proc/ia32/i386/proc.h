/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctl.h
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__ia32__i386__proc_h__
#define _KERNEL__arch__proc__ia32__i386__proc_h__


/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	VP_INT	sp;
} _KERNEL_T_CTXCB;

/** %jp{割込みコンテキスト制御ブロック} */
typedef struct _kernel_t_ictxcb
{
	INT		intcnt;
	VP		isp;
} _KERNEL_T_ICTXCB;


extern _KERNEL_T_ICTXCB _kernel_ictxcb;		/**< %jp{割込みコンテキスト制御ブロック} */



#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ini_prc(void);																		/**< %jp{プロセッサ固有の初期化} */

void    _kernel_ena_int(void);																		/**< %jp{割込み許可} */
void    _kernel_dis_int(void);																		/**< %jp{割込み禁止} */
void    _kernel_wai_int(void);																		/**< %jp{割込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, VP isp, FP entry, VP_INT par1, VP_INT par2);		/**< %jp{実行コンテキストの作成} */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの削除} */
void    _kernel_rst_ctx(VP_INT par1, VP_INT par2, FP entry, VP isp);								/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxinf_nxt, _KERNEL_T_CTXCB *pk_ctxcb_now);				/**< %jp{実行コンテキストの切替} */

void    _kernel_exc_hdr(void);
void    _kernel_int_hdr(void);

void    _kernel_outpb(UH port, UB data);
void    _kernel_outph(UH port, UH data);
void    _kernel_outpw(UH port, UW data);
UB      _kernel_inpb(UH port);
UH      _kernel_inph(UH port);
UW      _kernel_inpw(UH port);

void    _kernel_lgdt(VP gdt);
void    _kernel_lldt(VP ldt);
void    _kernel_lidt(VP idt);

void    _kernel_vector_000(void);
void    _kernel_vector_001(void);
void    _kernel_vector_002(void);
void    _kernel_vector_003(void);
void    _kernel_vector_004(void);
void    _kernel_vector_005(void);
void    _kernel_vector_006(void);
void    _kernel_vector_007(void);
void    _kernel_vector_008(void);
void    _kernel_vector_009(void);
void    _kernel_vector_010(void);
void    _kernel_vector_011(void);
void    _kernel_vector_012(void);
void    _kernel_vector_013(void);
void    _kernel_vector_014(void);
void    _kernel_vector_015(void);
void    _kernel_vector_016(void);
void    _kernel_vector_017(void);
void    _kernel_vector_018(void);
void    _kernel_vector_019(void);
void    _kernel_vector_020(void);
void    _kernel_vector_021(void);
void    _kernel_vector_022(void);
void    _kernel_vector_023(void);
void    _kernel_vector_024(void);
void    _kernel_vector_025(void);
void    _kernel_vector_026(void);
void    _kernel_vector_027(void);
void    _kernel_vector_028(void);
void    _kernel_vector_029(void);
void    _kernel_vector_030(void);
void    _kernel_vector_031(void);
void    _kernel_vector_032(void);
void    _kernel_vector_033(void);
void    _kernel_vector_034(void);
void    _kernel_vector_035(void);
void    _kernel_vector_036(void);
void    _kernel_vector_037(void);
void    _kernel_vector_038(void);
void    _kernel_vector_039(void);
void    _kernel_vector_040(void);
void    _kernel_vector_041(void);
void    _kernel_vector_042(void);
void    _kernel_vector_043(void);
void    _kernel_vector_044(void);
void    _kernel_vector_045(void);
void    _kernel_vector_046(void);
void    _kernel_vector_047(void);
void    _kernel_vector_048(void);
void    _kernel_vector_049(void);
void    _kernel_vector_050(void);
void    _kernel_vector_051(void);
void    _kernel_vector_052(void);
void    _kernel_vector_053(void);
void    _kernel_vector_054(void);
void    _kernel_vector_055(void);
void    _kernel_vector_056(void);
void    _kernel_vector_057(void);
void    _kernel_vector_058(void);
void    _kernel_vector_059(void);
void    _kernel_vector_060(void);
void    _kernel_vector_061(void);
void    _kernel_vector_062(void);
void    _kernel_vector_063(void);
void    _kernel_vector_064(void);
void    _kernel_vector_065(void);
void    _kernel_vector_066(void);
void    _kernel_vector_067(void);
void    _kernel_vector_068(void);
void    _kernel_vector_069(void);
void    _kernel_vector_070(void);
void    _kernel_vector_071(void);
void    _kernel_vector_072(void);
void    _kernel_vector_073(void);
void    _kernel_vector_074(void);
void    _kernel_vector_075(void);
void    _kernel_vector_076(void);
void    _kernel_vector_077(void);
void    _kernel_vector_078(void);
void    _kernel_vector_079(void);
void    _kernel_vector_080(void);
void    _kernel_vector_081(void);
void    _kernel_vector_082(void);
void    _kernel_vector_083(void);
void    _kernel_vector_084(void);
void    _kernel_vector_085(void);
void    _kernel_vector_086(void);
void    _kernel_vector_087(void);
void    _kernel_vector_088(void);
void    _kernel_vector_089(void);
void    _kernel_vector_090(void);
void    _kernel_vector_091(void);
void    _kernel_vector_092(void);
void    _kernel_vector_093(void);
void    _kernel_vector_094(void);
void    _kernel_vector_095(void);
void    _kernel_vector_096(void);
void    _kernel_vector_097(void);
void    _kernel_vector_098(void);
void    _kernel_vector_099(void);
void    _kernel_vector_100(void);
void    _kernel_vector_101(void);
void    _kernel_vector_102(void);
void    _kernel_vector_103(void);
void    _kernel_vector_104(void);
void    _kernel_vector_105(void);
void    _kernel_vector_106(void);
void    _kernel_vector_107(void);
void    _kernel_vector_108(void);
void    _kernel_vector_109(void);
void    _kernel_vector_110(void);
void    _kernel_vector_111(void);
void    _kernel_vector_112(void);
void    _kernel_vector_113(void);
void    _kernel_vector_114(void);
void    _kernel_vector_115(void);
void    _kernel_vector_116(void);
void    _kernel_vector_117(void);
void    _kernel_vector_118(void);
void    _kernel_vector_119(void);
void    _kernel_vector_120(void);
void    _kernel_vector_121(void);
void    _kernel_vector_122(void);
void    _kernel_vector_123(void);
void    _kernel_vector_124(void);
void    _kernel_vector_125(void);
void    _kernel_vector_126(void);
void    _kernel_vector_127(void);
void    _kernel_vector_128(void);
void    _kernel_vector_129(void);
void    _kernel_vector_130(void);
void    _kernel_vector_131(void);
void    _kernel_vector_132(void);
void    _kernel_vector_133(void);
void    _kernel_vector_134(void);
void    _kernel_vector_135(void);
void    _kernel_vector_136(void);
void    _kernel_vector_137(void);
void    _kernel_vector_138(void);
void    _kernel_vector_139(void);
void    _kernel_vector_140(void);
void    _kernel_vector_141(void);
void    _kernel_vector_142(void);
void    _kernel_vector_143(void);
void    _kernel_vector_144(void);
void    _kernel_vector_145(void);
void    _kernel_vector_146(void);
void    _kernel_vector_147(void);
void    _kernel_vector_148(void);
void    _kernel_vector_149(void);
void    _kernel_vector_150(void);
void    _kernel_vector_151(void);
void    _kernel_vector_152(void);
void    _kernel_vector_153(void);
void    _kernel_vector_154(void);
void    _kernel_vector_155(void);
void    _kernel_vector_156(void);
void    _kernel_vector_157(void);
void    _kernel_vector_158(void);
void    _kernel_vector_159(void);
void    _kernel_vector_160(void);
void    _kernel_vector_161(void);
void    _kernel_vector_162(void);
void    _kernel_vector_163(void);
void    _kernel_vector_164(void);
void    _kernel_vector_165(void);
void    _kernel_vector_166(void);
void    _kernel_vector_167(void);
void    _kernel_vector_168(void);
void    _kernel_vector_169(void);
void    _kernel_vector_170(void);
void    _kernel_vector_171(void);
void    _kernel_vector_172(void);
void    _kernel_vector_173(void);
void    _kernel_vector_174(void);
void    _kernel_vector_175(void);
void    _kernel_vector_176(void);
void    _kernel_vector_177(void);
void    _kernel_vector_178(void);
void    _kernel_vector_179(void);
void    _kernel_vector_180(void);
void    _kernel_vector_181(void);
void    _kernel_vector_182(void);
void    _kernel_vector_183(void);
void    _kernel_vector_184(void);
void    _kernel_vector_185(void);
void    _kernel_vector_186(void);
void    _kernel_vector_187(void);
void    _kernel_vector_188(void);
void    _kernel_vector_189(void);
void    _kernel_vector_190(void);
void    _kernel_vector_191(void);
void    _kernel_vector_192(void);
void    _kernel_vector_193(void);
void    _kernel_vector_194(void);
void    _kernel_vector_195(void);
void    _kernel_vector_196(void);
void    _kernel_vector_197(void);
void    _kernel_vector_198(void);
void    _kernel_vector_199(void);
void    _kernel_vector_200(void);
void    _kernel_vector_201(void);
void    _kernel_vector_202(void);
void    _kernel_vector_203(void);
void    _kernel_vector_204(void);
void    _kernel_vector_205(void);
void    _kernel_vector_206(void);
void    _kernel_vector_207(void);
void    _kernel_vector_208(void);
void    _kernel_vector_209(void);
void    _kernel_vector_210(void);
void    _kernel_vector_211(void);
void    _kernel_vector_212(void);
void    _kernel_vector_213(void);
void    _kernel_vector_214(void);
void    _kernel_vector_215(void);
void    _kernel_vector_216(void);
void    _kernel_vector_217(void);
void    _kernel_vector_218(void);
void    _kernel_vector_219(void);
void    _kernel_vector_220(void);
void    _kernel_vector_221(void);
void    _kernel_vector_222(void);
void    _kernel_vector_223(void);
void    _kernel_vector_224(void);
void    _kernel_vector_225(void);
void    _kernel_vector_226(void);
void    _kernel_vector_227(void);
void    _kernel_vector_228(void);
void    _kernel_vector_229(void);
void    _kernel_vector_230(void);
void    _kernel_vector_231(void);
void    _kernel_vector_232(void);
void    _kernel_vector_233(void);
void    _kernel_vector_234(void);
void    _kernel_vector_235(void);
void    _kernel_vector_236(void);
void    _kernel_vector_237(void);
void    _kernel_vector_238(void);
void    _kernel_vector_239(void);
void    _kernel_vector_240(void);
void    _kernel_vector_241(void);
void    _kernel_vector_242(void);
void    _kernel_vector_243(void);
void    _kernel_vector_244(void);
void    _kernel_vector_245(void);
void    _kernel_vector_246(void);
void    _kernel_vector_247(void);
void    _kernel_vector_248(void);
void    _kernel_vector_249(void);
void    _kernel_vector_250(void);
void    _kernel_vector_251(void);
void    _kernel_vector_252(void);
void    _kernel_vector_253(void);
void    _kernel_vector_254(void);
void    _kernel_vector_255(void);

#ifdef __cplusplus
}
#endif



#define _KERNEL_INI_PRC()			_kernel_ini_prc()												/**< %jp{プロセッサ固有の初期化} */

#define _KERNEL_INI_INT(stksz, stk)	do { _kernel_ictxcb.isp = (VB *)(stk) + (stksz); } while (0)	/**< %jp{割込み初期化} */
#define _KERNEL_ENA_INT()			_kernel_ena_int()												/**< %jp{割込み許可} */
#define _KERNEL_DIS_INT()			_kernel_dis_int()												/**< %jp{割込み禁止} */
#define _KERNEL_WAI_INT()			_kernel_wai_int()												/**< %jp{割込み待ち(アイドル時の処理)} */

#define _KERNEL_CRE_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_cre_ctx((pk_ctxcb), (isp), (entry), (exinf1), (exinf2))	/**< %jp{実行コンテキストの作成} */	
#define _KERNEL_DEL_CTX(pk_ctxcb)	do {} while (0)													/**< %jp{実行コンテキストの削除} */
#define _KERNEL_RST_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_rst_ctx((exinf1), (exinf2), (entry), (isp))				/**< %jp{実行コンテキストのリスタート} */
#define _KERNEL_STA_CTX(pk_ctxcb)	_kernel_sta_ctx(pk_ctxcb)
#define _KERNEL_SWI_CTX(pk_ctxcb_now, pk_ctxinf_nxt)							\
									_kernel_swi_ctx((pk_ctxinf_nxt), (pk_ctxcb_now))				/**< %jp{実行コンテキストの切替} */



#endif	/* _KERNEL__arch__proc__ia32__i386__proc_h__ */


/* end of file */
