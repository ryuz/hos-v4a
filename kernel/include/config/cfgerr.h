/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cfgerr.h
 * @brief %jp{エラー処理のコンフィギュレーション用ヘッダファイル}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__config__cfgerr_h__
#define _KERNEL__config__cfgerr_h__


/*
%jp{
  本ファイルにて、カーネル内のエラーチェックサポートのコンフィギュ
レーションを行う。
  エラーチェックを取り外した場合、コードサイズなどの削減が可能となるが、
そのエラーが発生する状況を発生させた場合は、動作未保証となるので注意して
取り外すこと。
  また、本ファイルはセンブリ言語の前処理にも使う事を想定しているので、
C言語構文(例えばtypedefなど)はこの中には記載せず、マクロ定義などの
プリプロセッサディレクティブのみを記載する事とする。
}
*/


/* cre_tsk */
#define _KERNEL_CFG_CRE_TSK_E_ID		TRUE
#define _KERNEL_CFG_CRE_TSK_E_RSATR 	TRUE
#define _KERNEL_CFG_CRE_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_TSK_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_TSK_E_NOSPT		FALSE

/* acre_tsk */
#define _KERNEL_CFG_ACRE_TSK_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_TSK_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_TSK_E_NOMEM	TRUE	
#define _KERNEL_CFG_ACRE_TSK_E_NOSPT	FALSE

/* del_tsk */
#define _KERNEL_CFG_DEL_TSK_E_ID		TRUE
#define _KERNEL_CFG_DEL_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_DEL_TSK_E_NOSPT		FALSE

/* act_tsk */
#define _KERNEL_CFG_ACT_TSK_E_ID		TRUE
#define _KERNEL_CFG_ACT_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_ACT_TSK_E_NOSPT		FALSE

/* iact_tsk */
#define _KERNEL_CFG_IACT_TSK_E_ID		TRUE
#define _KERNEL_CFG_IACT_TSK_E_CTX		TRUE	
#define _KERNEL_CFG_IACT_TSK_E_NOEXS	TRUE
#define _KERNEL_CFG_IACT_TSK_E_NOSPT	FALSE

/* can_act */
#define _KERNEL_CFG_CAN_ACT_E_ID		TRUE
#define _KERNEL_CFG_CAN_ACT_E_NOEXS		TRUE
#define _KERNEL_CFG_CAN_ACT_E_NOSPT		FALSE

/* sta_tsk */
#define _KERNEL_CFG_STA_TSK_E_ID		TRUE	
#define _KERNEL_CFG_STA_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_STA_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_STA_TSK_E_NOSPT		FALSE
 
/* ext_tsk */
#define _KERNEL_CFG_EXT_TSK_E_NOSPT		FALSE

/* exd_tsk */
#define _KERNEL_CFG_EXD_TSK_E_NOSPT		FALSE

/* ter_tsk */
#define _KERNEL_CFG_TER_TSK_E_ID		TRUE
#define _KERNEL_CFG_TER_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_TER_TSK_E_ILUSE		TRUE
#define _KERNEL_CFG_TER_TSK_E_NOSPT		FALSE

/* chg_pri */
/* get_pri */
/* ref_tsk */
#define _KERNEL_CFG_REF_TSK_E_ID		TRUE
#define _KERNEL_CFG_REF_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_REF_TSK_E_NOSPT		FALSE

/* ref_tst */
#define _KERNEL_CFG_REF_TST_E_ID		TRUE
#define _KERNEL_CFG_REF_TST_E_NOEXS		TRUE
#define _KERNEL_CFG_REF_TST_E_NOSPT		FALSE

/* slp_tsk */
/* tslp_tsk */
/* wup_tsk */
#define _KERNEL_CFG_WUP_TSK_E_ID		TRUE
#define _KERNEL_CFG_WUP_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_WUP_TSK_E_QOVR		TRUE

/* iwup_tsk */


/* can_wup */
#define _KERNEL_CFG_CAN_WUP_E_ID		TRUE
#define _KERNEL_CFG_CAN_WUP_E_NOEXS		TRUE

/* rel_wai */
#define _KERNEL_CFG_REL_WAI_E_ID		TRUE
#define _KERNEL_CFG_REL_WAI_E_NOEXS		TRUE
#define _KERNEL_CFG_REL_WAI_E_OBJ		TRUE
#define _KERNEL_CFG_REL_WAI_E_NOSPT		FALSE

/* irel_wai */
#define _KERNEL_CFG_IREL_WAI_E_ID		TRUE
#define _KERNEL_CFG_IREL_WAI_E_NOEXS	TRUE
#define _KERNEL_CFG_IREL_WAI_E_OBJ		TRUE
#define _KERNEL_CFG_IREL_WAI_E_NOSPT	FALSE

/* sus_tsk */
#define _KERNEL_CFG_SUS_TSK_E_ID		TRUE		
#define _KERNEL_CFG_SUS_TSK_E_CTX		TRUE
#define _KERNEL_CFG_SUS_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_SUS_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_SUS_TSK_E_QOVR		TRUE
#define _KERNEL_CFG_SUS_TSK_E_NOSPT		FALSE

/* rsm_tsk */
#define _KERNEL_CFG_RSM_TSK_E_ID		TRUE
#define _KERNEL_CFG_RSM_TSK_E_NOEXS		TRUE
#define _KERNEL_CFG_RSM_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_RSM_TSK_E_NOSPT		FALSE

/* frsm_tsk */
#define _KERNEL_CFG_FRSM_TSK_E_ID		TRUE
#define _KERNEL_CFG_FRSM_TSK_E_NOEXS	TRUE
#define _KERNEL_CFG_FRSM_TSK_E_OBJ		TRUE
#define _KERNEL_CFG_FRSM_TSK_E_NOSPT	FALSE

/* dly_tsk */
#define _KERNEL_CFG_DLY_TSK_E_CTX		TRUE



/* def_tex */
#define _KERNEL_CFG_DEF_TEX_E_ID		TRUE
#define _KERNEL_CFG_DEF_TEX_E_NOEXS		TRUE	
#define _KERNEL_CFG_DEF_TEX_E_RSATR 	TRUE
#define _KERNEL_CFG_DEF_TEX_E_NOMEM		TRUE
#define _KERNEL_CFG_DEF_TEX_E_NOSPT		FALSE


/* ras_tex */
/* iras_tex */
/* dis_tex */
/* ena_tex */
/* sns_tex */
/* ref_tex */


/* cre_sem */
#define _KERNEL_CFG_CRE_SEM_E_ID		TRUE
#define _KERNEL_CFG_CRE_SEM_E_RSATR 	TRUE
#define _KERNEL_CFG_CRE_SEM_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_SEM_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_SEM_E_NOSPT		FALSE

/* acre_sem */
#define _KERNEL_CFG_ACRE_SEM_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_SEM_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_SEM_E_NOMEM	TRUE	
#define _KERNEL_CFG_ACRE_SEM_E_NOSPT	FALSE

/* del_sem */
#define _KERNEL_CFG_DEL_SEM_E_ID		TRUE
#define _KERNEL_CFG_DEL_SEM_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_SEM_E_NOSPT		FALSE

/* sig_sem */
#define _KERNEL_CFG_SIG_SEM_E_ID		TRUE
#define _KERNEL_CFG_SIG_SEM_E_NOEXS		TRUE
#define _KERNEL_CFG_SIG_SEM_E_QOVR		TRUE
#define _KERNEL_CFG_SIG_SEM_E_NOSPT		FALSE

/* isig_sem */
#define _KERNEL_CFG_ISIG_SEM_E_ID		TRUE
#define _KERNEL_CFG_ISIG_SEM_E_NOEXS	TRUE
#define _KERNEL_CFG_ISIG_SEM_E_QOVR		TRUE	
#define _KERNEL_CFG_ISIG_SEM_E_NOSPT	FALSE

/* wai_sem */
#define _KERNEL_CFG_WAI_SEM_E_ID		TRUE
#define _KERNEL_CFG_WAI_SEM_E_CTX		TRUE
#define _KERNEL_CFG_WAI_SEM_E_NOEXS		TRUE
#define _KERNEL_CFG_WAI_SEM_E_RLWAI 	TRUE
#define _KERNEL_CFG_WAI_SEM_E_DLT   	TRUE
#define _KERNEL_CFG_WAI_SEM_E_NOSPT		FALSE

/* pol_sem */
#define _KERNEL_CFG_POL_SEM_E_ID		TRUE
#define _KERNEL_CFG_POL_SEM_E_NOEXS		TRUE
#define _KERNEL_CFG_POL_SEM_E_TMOUT		TRUE
#define _KERNEL_CFG_POL_SEM_E_NOSPT		FALSE

/* twai_sem */
#define _KERNEL_CFG_TWAI_SEM_E_ID		TRUE
#define _KERNEL_CFG_TWAI_SEM_E_CTX		TRUE
#define _KERNEL_CFG_TWAI_SEM_E_NOEXS	TRUE
#define _KERNEL_CFG_TWAI_SEM_E_PAR		TRUE
#define _KERNEL_CFG_TWAI_SEM_E_RLWAI 	TRUE
#define _KERNEL_CFG_TWAI_SEM_E_TMOUT	TRUE
#define _KERNEL_CFG_TWAI_SEM_E_DLT   	TRUE
#define _KERNEL_CFG_TWAI_SEM_E_NOSPT	FALSE

/* ref_sem */
#define _KERNEL_CFG_REF_SEM_E_ID		TRUE
#define _KERNEL_CFG_REF_SEM_E_NOEXS		TRUE
#define _KERNEL_CFG_REF_SEM_E_PAR		TRUE
#define _KERNEL_CFG_REF_SEM_E_NOSPT		FALSE


/* cre_flg */
#define _KERNEL_CFG_CRE_FLG_E_ID		TRUE
#define _KERNEL_CFG_CRE_FLG_E_RSATR 	TRUE
#define _KERNEL_CFG_CRE_FLG_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_FLG_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_FLG_E_NOSPT		TRUE

/* acre_flg */
#define _KERNEL_CFG_ACRE_FLG_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_FLG_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_FLG_E_NOMEM	TRUE	
#define _KERNEL_CFG_ACRE_FLG_E_NOSPT	FALSE

/* del_flg */
#define _KERNEL_CFG_DEL_FLG_E_ID		TRUE
#define _KERNEL_CFG_DEL_FLG_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_FLG_E_NOSPT		FALSE

/* set_flg */
#define _KERNEL_CFG_SET_FLG_E_ID		TRUE
#define _KERNEL_CFG_SET_FLG_E_NOEXS		TRUE
#define _KERNEL_CFG_SET_FLG_E_PAR		TRUE
#define _KERNEL_CFG_SET_FLG_E_NOSPT		FALSE

/* iset_flg */
#define _KERNEL_CFG_ISET_FLG_E_ID		TRUE
#define _KERNEL_CFG_ISET_FLG_E_NOEXS	TRUE
#define _KERNEL_CFG_ISET_FLG_E_NOSPT	FALSE

/* clr_flg */
#define _KERNEL_CFG_CLR_FLG_E_ID		TRUE
#define _KERNEL_CFG_CLR_FLG_E_NOEXS		TRUE
#define _KERNEL_CFG_CLR_FLG_E_PAR		TRUE
#define _KERNEL_CFG_CLR_FLG_E_NOSPT		FALSE

/* wai_flg */
#define _KERNEL_CFG_WAI_FLG_E_ID		TRUE	
#define _KERNEL_CFG_WAI_FLG_E_CTX		TRUE
#define _KERNEL_CFG_WAI_FLG_E_NOEXS 	TRUE
#define _KERNEL_CFG_WAI_FLG_E_PAR   	TRUE
#define _KERNEL_CFG_WAI_FLG_E_ILUSE 	TRUE
#define _KERNEL_CFG_WAI_FLG_E_RLWAI 	TRUE
#define _KERNEL_CFG_WAI_FLG_E_DLT   	TRUE
#define _KERNEL_CFG_WAI_FLG_E_NOSPT		FALSE

/* pol_flg */
#define _KERNEL_CFG_POL_FLG_E_ID		TRUE	
#define _KERNEL_CFG_POL_FLG_E_NOEXS 	TRUE
#define _KERNEL_CFG_POL_FLG_E_PAR   	TRUE
#define _KERNEL_CFG_POL_FLG_E_TMOUT   	TRUE
#define _KERNEL_CFG_POL_FLG_E_NOSPT		FALSE

/* twai_flg */
#define _KERNEL_CFG_TWAI_FLG_E_ID		TRUE	
#define _KERNEL_CFG_TWAI_FLG_E_CTX		TRUE
#define _KERNEL_CFG_TWAI_FLG_E_NOEXS 	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_PAR   	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_ILUSE 	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_RLWAI 	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_TMOUT   	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_DLT   	TRUE
#define _KERNEL_CFG_TWAI_FLG_E_NOSPT	FALSE

/* ref_flg */
#define _KERNEL_CFG_REF_FLG_E_ID		TRUE	
#define _KERNEL_CFG_REF_FLG_E_NOEXS 	TRUE
#define _KERNEL_CFG_REF_FLG_E_PAR   	TRUE
#define _KERNEL_CFG_REF_FLG_E_NOSPT		FALSE



/* cre_dtq */
#define _KERNEL_CFG_CRE_DTQ_E_ID		TRUE
#define _KERNEL_CFG_CRE_DTQ_E_RSATR		TRUE
#define _KERNEL_CFG_CRE_DTQ_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_DTQ_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_DTQ_E_NOSPT		FALSE

/* acre_dtq */
#define _KERNEL_CFG_ACRE_DTQ_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_DTQ_E_NOID		TRUE	
#define _KERNEL_CFG_ACRE_DTQ_E_NOMEM	TRUE
#define _KERNEL_CFG_ACRE_DTQ_E_NOSPT	FALSE

/* del_dtq */
#define _KERNEL_CFG_DEL_DTQ_E_ID		TRUE
#define _KERNEL_CFG_DEL_DTQ_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_DTQ_E_NOSPT		FALSE

/* snd_dtq */
#define _KERNEL_CFG_SND_DTQ_E_ID		TRUE
#define _KERNEL_CFG_SND_DTQ_E_CTX		TRUE
#define _KERNEL_CFG_SND_DTQ_E_NOEXS		TRUE
#define _KERNEL_CFG_SND_DTQ_E_NOSPT		FALSE

/* psnd_dtq */
#define _KERNEL_CFG_PSND_DTQ_E_ID		TRUE
#define _KERNEL_CFG_PSND_DTQ_E_NOEXS	TRUE
#define _KERNEL_CFG_PSND_DTQ_E_TMOUT	TRUE
#define _KERNEL_CFG_PSND_DTQ_E_NOSPT	FALSE

/* ipsnd_dtq */
#define _KERNEL_CFG_IPSND_DTQ_E_ID		TRUE
#define _KERNEL_CFG_IPSND_DTQ_E_CTX		TRUE
#define _KERNEL_CFG_IPSND_DTQ_E_NOEXS	TRUE
#define _KERNEL_CFG_IPSND_DTQ_E_TMOUT	TRUE
#define _KERNEL_CFG_IPSND_DTQ_E_NOSPT	FALSE

/* tsnd_dtq */
#define _KERNEL_CFG_TSND_DTQ_E_ID		TRUE
#define _KERNEL_CFG_TSND_DTQ_E_CTX		TRUE
#define _KERNEL_CFG_TSND_DTQ_E_NOEXS	TRUE
#define _KERNEL_CFG_TSND_DTQ_E_PAR		TRUE
#define _KERNEL_CFG_TSND_DTQ_E_RLWAI	TRUE
#define _KERNEL_CFG_TSND_DTQ_E_TMOUT	TRUE
#define _KERNEL_CFG_TSND_DTQ_E_NOSPT	FALSE

/* fsnd_dtq */
#define _KERNEL_CFG_FSND_DTQ_E_ID		TRUE
#define _KERNEL_CFG_FSND_DTQ_E_NOEXS	TRUE
#define _KERNEL_CFG_FSND_DTQ_E_ILUSE	TRUE
#define _KERNEL_CFG_FSND_DTQ_E_NOSPT	FALSE

/* ifsnd_dtq */


/* rcv_dtq */
#define _KERNEL_CFG_RCV_DTQ_E_CTX		TRUE
#define _KERNEL_CFG_RCV_DTQ_E_ID		TRUE
#define _KERNEL_CFG_RCV_DTQ_E_NOEXS		TRUE
#define _KERNEL_CFG_RCV_DTQ_E_NOSPT		FALSE

/* prcv_dtq */
#define _KERNEL_CFG_PRCV_DTQ_E_CTX		TRUE
#define _KERNEL_CFG_PRCV_DTQ_E_ID		TRUE
#define _KERNEL_CFG_PRCV_DTQ_E_NOEXS	TRUE
#define _KERNEL_CFG_PRCV_DTQ_E_NOSPT	FALSE

/* trcv_dtq */
/* ref_dtq */


/* cre_mbx */
#define _KERNEL_CFG_CRE_MBX_E_ID		TRUE	
#define _KERNEL_CFG_CRE_MBX_E_RSATR 	TRUE	
#define _KERNEL_CFG_CRE_MBX_E_OBJ		TRUE	
#define _KERNEL_CFG_CRE_MBX_E_NOMEM		TRUE	
#define _KERNEL_CFG_CRE_MBX_E_NOSPT		FALSE
	
/* acre_mbx */
#define _KERNEL_CFG_ACRE_MBX_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_MBX_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_MBX_E_NOMEM	TRUE
#define _KERNEL_CFG_ACRE_MBX_E_NOSPT	FALSE

/* del_mbx */
#define _KERNEL_CFG_DEL_MBX_E_ID		TRUE
#define _KERNEL_CFG_DEL_MBX_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_MBX_E_NOSPT		FALSE


/* snd_mbx */
/* rcv_mbx */
#define _KERNEL_CFG_RCV_MBX_E_ID		TRUE
#define _KERNEL_CFG_RCV_MBX_E_NOEXS		TRUE
#define _KERNEL_CFG_RCV_MBX_E_NOSPT		FALSE

/* prcv_mbx */
/* trcv_mbx */
/* ref_mbx */


/* cre_mtx */
#define _KERNEL_CFG_CRE_MTX_E_ID		TRUE
#define _KERNEL_CFG_CRE_MTX_E_RSATR		TRUE
#define _KERNEL_CFG_CRE_MTX_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_MTX_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_MTX_E_NOSPT		FALSE

/* acre_mtx */
#define _KERNEL_CFG_ACRE_MTX_E_RSATR	TRUE
#define _KERNEL_CFG_ACRE_MTX_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_MTX_E_NOMEM	TRUE
#define _KERNEL_CFG_ACRE_MTX_E_NOSPT	FALSE

/* del_mtx */
#define _KERNEL_CFG_DEL_MTX_E_ID		TRUE
#define _KERNEL_CFG_DEL_MTX_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_MTX_E_NOSPT		FALSE

/* loc_mtx */
#define _KERNEL_CFG_LOC_MTX_E_CTX		TRUE
#define _KERNEL_CFG_LOC_MTX_E_ID		TRUE
#define _KERNEL_CFG_LOC_MTX_E_NOEXS		TRUE
#define _KERNEL_CFG_LOC_MTX_E_ILUSE		TRUE
#define _KERNEL_CFG_LOC_MTX_E_NOSPT		FALSE

/* ploc_mtx */
#define _KERNEL_CFG_PLOC_MTX_E_ID		TRUE
#define _KERNEL_CFG_PLOC_MTX_E_NOEXS	TRUE
#define _KERNEL_CFG_PLOC_MTX_E_ILUSE	TRUE
#define _KERNEL_CFG_PLOC_MTX_E_TMOUT	TRUE
#define _KERNEL_CFG_PLOC_MTX_E_NOSPT	FALSE

/* tloc_mtx */
#define _KERNEL_CFG_TLOC_MTX_E_ID		TRUE
#define _KERNEL_CFG_TLOC_MTX_E_CTX		TRUE
#define _KERNEL_CFG_TLOC_MTX_E_NOEXS	TRUE
#define _KERNEL_CFG_TLOC_MTX_E_PAR		TRUE
#define _KERNEL_CFG_TLOC_MTX_E_ILUSE	TRUE
#define _KERNEL_CFG_TLOC_MTX_E_RLWAI 	TRUE
#define _KERNEL_CFG_TLOC_MTX_E_TMOUT	TRUE
#define _KERNEL_CFG_TLOC_MTX_E_DLT   	TRUE
#define _KERNEL_CFG_TLOC_MTX_E_NOSPT	FALSE

/* unl_mtx */
#define _KERNEL_CFG_UNL_MTX_E_CTX		TRUE
#define _KERNEL_CFG_UNL_MTX_E_ID		TRUE
#define _KERNEL_CFG_UNL_MTX_E_NOEXS		TRUE
#define _KERNEL_CFG_UNL_MTX_E_ILUSE		TRUE
#define _KERNEL_CFG_UNL_MTX_E_NOSPT		FALSE

/* ref_mtx */


/* cre_mbf */
/* acre_mbf */
/* del_mbf */
/* snd_mbf */
/* psnd_mbf */
/* tsnd_mbf */
/* rcv_mbf */
/* prcv_mbf */
/* trcv_mbf */
/* ref_mbf */


/* cre_por */
/* acre_por */
/* del_por */
/* cal_por */
/* tcal_por */
/* acp_por */
/* pacp_por */
/* tacp_por */
/* fwd_por */
/* rpl_rdv */
/* ref_por */
/* ref_rdv */


/* cre_mpf */
#define _KERNEL_CFG_CRE_MPF_E_ID		TRUE
#define _KERNEL_CFG_CRE_MPF_E_RSATR 	TRUE
#define _KERNEL_CFG_CRE_MPF_E_OBJ		TRUE
#define _KERNEL_CFG_CRE_MPF_E_NOMEM		TRUE
#define _KERNEL_CFG_CRE_MPF_E_NOSPT		FALSE

/* acre_mpf */
#define _KERNEL_CFG_ACRE_MPF_E_NOID		TRUE
#define _KERNEL_CFG_ACRE_MPF_E_RSATR 	TRUE
#define _KERNEL_CFG_ACRE_MPF_E_NOMEM	TRUE
#define _KERNEL_CFG_ACRE_MPF_E_NOSPT	FALSE

/* del_mpf */
#define _KERNEL_CFG_DEL_MPF_E_ID		TRUE
#define _KERNEL_CFG_DEL_MPF_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_MPF_E_NOSPT		FALSE

/* get_mpf */
#define _KERNEL_CFG_GET_MPF_E_ID		TRUE	
#define _KERNEL_CFG_GET_MPF_E_CTX		TRUE
#define _KERNEL_CFG_GET_MPF_E_NOEXS 	TRUE
#define _KERNEL_CFG_GET_MPF_E_PAR   	TRUE
#define _KERNEL_CFG_GET_MPF_E_ILUSE   	TRUE
#define _KERNEL_CFG_GET_MPF_E_RLWAI 	TRUE
#define _KERNEL_CFG_GET_MPF_E_DLT   	TRUE
#define _KERNEL_CFG_GET_MPF_E_NOSPT		FALSE

/* pget_mpf */
#define _KERNEL_CFG_PGET_MPF_E_ID		TRUE	
#define _KERNEL_CFG_PGET_MPF_E_CTX		TRUE
#define _KERNEL_CFG_PGET_MPF_E_NOEXS 	TRUE
#define _KERNEL_CFG_PGET_MPF_E_PAR   	TRUE
#define _KERNEL_CFG_PGET_MPF_E_NOSPT	FALSE

/* tget_mpf */
/* rel_mpf */
/* ref_mpf */


/* cre_mpl */
/* acre_mpl */
/* del_mpl */
/* get_mpl */
/* pget_mpl */
/* tget_mpl */
/* rel_mpl */
/* ref_mpl */


/* set_tim */
#define _KERNEL_CFG_SET_TIM_E_PAR	 	TRUE	
#define _KERNEL_CFG_SET_TIM_E_NOSPT		FALSE

/* get_tim */
#define _KERNEL_CFG_GET_TIM_E_PAR	 	TRUE	
#define _KERNEL_CFG_GET_TIM_E_NOSPT		FALSE

/* isig_tim */
#define _KERNEL_CFG_ISIG_TIM_E_NOSPT	FALSE


/* cre_cyc */
/* acre_cyc */
/* del_cyc */
/* sta_cyc */
/* stp_cyc */
/* ref_cyc */


/* cre_alm */
/* acre_alm */
/* del_alm */
/* sta_alm */
/* stp_alm */
/* ref_alm */


/* def_ovr */
/* sta_ovr */
/* stp_ovr */
/* ref_ovr */


/* rot_rdq */
/* irot_rdq */
/* get_tid */
/* iget_tid */
/* loc_cpu */
/* iloc_cpu */
/* unl_cpu */
/* ilnl_cpu */
/* dis_dsp */
/* ena_dsp */
/* sns_ctx */
/* sns_loc */
/* sns_dsp */
/* sns_dpn */
/* ref_sys */


/* def_inh */
/* cre_isr */
/* acre_isr */
/* del_isr */
#define _KERNEL_CFG_DEL_ISR_E_ID		TRUE
#define _KERNEL_CFG_DEL_ISR_E_NOEXS		TRUE
#define _KERNEL_CFG_DEL_ISR_E_NOSPT		FALSE

/* ref_isr */
/* dis_int */
/* ena_int */
/* chg_ilv */
/* get_ilv */


/* def_svc */
/* cal_svc */


/* def_exc */
/* ref_cfg */
/* ref_ver */



#endif	/* _KERNEL__config__cfgerr_h__ */


/* end of file */
