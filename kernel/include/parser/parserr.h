/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  parserr.h
 * @brief %jp{エラー処理コンフィギュレーションの解析}%en{error configulation parser}
 *
 * @version $Id: parserr.h,v 1.3 2006-10-08 05:30:35 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__parser__parserr_h__
#define _KERNEL__parser__parserr_h__



/* cre_tsk */
/* acre_tsk */
/* del_tsk */

/* act_tsk */
#define _KERNEL_SPT_ACT_TSK_E_ID		_KERNEL_CFG_ACT_TSK_E_ID

/* iact_tsk */
/* can_act */
/* sta_tsk */
/* ext_tsk */
/* exd_tsk */
/* ter_tsk */
/* chg_pri */
/* get_pri */
/* ref_tsk */
#define _KERNEL_SPT_REF_TSK_E_ID		_KERNEL_CFG_REF_TSK_E_ID

/* ref_tst */

/* slp_tsk */
/* tslp_tsk */
/* wup_tsk */
#define _KERNEL_SPT_WUP_TSK_E_ID		_KERNEL_CFG_WUP_TSK_E_ID
#define _KERNEL_SPT_WUP_TSK_E_NOEXS		_KERNEL_CFG_WUP_TSK_E_NOEXS

/* iwup_tsk */
/* can_wup */
#define _KERNEL_SPT_CAN_WUP_E_ID		_KERNEL_CFG_CAN_WUP_E_ID
#define _KERNEL_SPT_CAN_WUP_E_NOEXS		_KERNEL_CFG_CAN_WUP_E_NOEXS

/* rel_wai */
#define _KERNEL_SPT_REL_WAI_E_ID		_KERNEL_CFG_REL_WAI_E_ID
#define _KERNEL_SPT_REL_WAI_E_NOEXS		_KERNEL_CFG_REL_WAI_E_NOEXS
/* irel_wai */
/* sus_tsk */
/* rsm_tsk */
/* frsm_tsk */
/* dly_tsk */



/* def_tex */
/* ras_tex */
/* iras_tex */
/* dis_tex */
/* ena_tex */
/* sns_tex */
/* ref_tex */


/* cre_sem */
#define _KERNEL_SPT_CRE_SEM_E_ID		_KERNEL_CFG_CRE_SEM_E_ID	
#define _KERNEL_SPT_CRE_SEM_E_RSATR 	_KERNEL_CFG_CRE_SEM_E_RSATR 
#define _KERNEL_SPT_CRE_SEM_E_OBJ		_KERNEL_CFG_CRE_SEM_E_OBJ
#define _KERNEL_SPT_CRE_SEM_E_NOMEM		_KERNEL_CFG_CRE_SEM_E_NOMEM	
#define _KERNEL_SPT_CRE_SEM_E_NOSPT		_KERNEL_CFG_CRE_SEM_E_NOSPT

/* acre_sem */
#define _KERNEL_SPT_ACRE_SEM_E_NOID		_KERNEL_CFG_ACRE_SEM_E_NOID
#define _KERNEL_SPT_ACRE_SEM_E_RSATR 	_KERNEL_CFG_ACRE_SEM_E_RSATR
#define _KERNEL_SPT_ACRE_SEM_E_NOMEM	_KERNEL_CFG_ACRE_SEM_E_NOMEM	
#define _KERNEL_SPT_ACRE_SEM_E_NOSPT	_KERNEL_CFG_ACRE_SEM_E_NOSPT

/* del_sem */
#define _KERNEL_SPT_DEL_SEM_E_ID		_KERNEL_CFG_DEL_SEM_E_ID
#define _KERNEL_SPT_DEL_SEM_E_NOEXS		_KERNEL_CFG_DEL_SEM_E_NOEXS
#define _KERNEL_SPT_DEL_SEM_E_NOSPT		_KERNEL_CFG_DEL_SEM_E_NOSPT

/* sig_sem */
#define _KERNEL_SPT_SIG_SEM_E_ID		_KERNEL_CFG_SIG_SEM_E_ID
#define _KERNEL_SPT_SIG_SEM_E_NOEXS		_KERNEL_CFG_SIG_SEM_E_NOEXS
#define _KERNEL_SPT_SIG_SEM_E_QOVR		_KERNEL_CFG_SIG_SEM_E_QOVR
#define _KERNEL_SPT_SIG_SEM_E_NOSPT		_KERNEL_CFG_SIG_SEM_E_NOSPT
/* isig_sem */

/* wai_sem */
#define _KERNEL_SPT_WAI_SEM_E_ID		_KERNEL_CFG_WAI_SEM_E_ID
#define _KERNEL_SPT_WAI_SEM_E_CTX		_KERNEL_CFG_WAI_SEM_E_CTX
#define _KERNEL_SPT_WAI_SEM_E_NOEXS		_KERNEL_CFG_WAI_SEM_E_NOEXS
#define _KERNEL_SPT_WAI_SEM_E_RLWAI 	_KERNEL_CFG_WAI_SEM_E_RLWAI 
#define _KERNEL_SPT_WAI_SEM_E_DLT   	_KERNEL_CFG_WAI_SEM_E_DLT   
#define _KERNEL_SPT_WAI_SEM_E_NOSPT		_KERNEL_CFG_WAI_SEM_E_NOSPT

/* pol_sem */
#define _KERNEL_SPT_POL_SEM_E_ID		_KERNEL_CFG_POL_SEM_E_ID
#define _KERNEL_SPT_POL_SEM_E_NOEXS		_KERNEL_CFG_POL_SEM_E_NOEXS
#define _KERNEL_SPT_POL_SEM_E_TMOUT		_KERNEL_CFG_POL_SEM_E_TMOUT
#define _KERNEL_SPT_POL_SEM_E_NOSPT		_KERNEL_CFG_POL_SEM_E_NOSPT

/* twai_sem */
#define _KERNEL_SPT_TWAI_SEM_E_ID		_KERNEL_CFG_TWAI_SEM_E_ID
#define _KERNEL_SPT_TWAI_SEM_E_CTX		_KERNEL_CFG_TWAI_SEM_E_CTX
#define _KERNEL_SPT_TWAI_SEM_E_NOEXS	_KERNEL_CFG_TWAI_SEM_E_NOEXS
#define _KERNEL_SPT_TWAI_SEM_E_TMOUT	_KERNEL_CFG_TWAI_SEM_E_TMOUT
#define _KERNEL_SPT_TWAI_SEM_E_RLWAI 	_KERNEL_CFG_TWAI_SEM_E_RLWAI 
#define _KERNEL_SPT_TWAI_SEM_E_DLT   	_KERNEL_CFG_TWAI_SEM_E_DLT   
#define _KERNEL_SPT_TWAI_SEM_E_NOSPT	_KERNEL_CFG_TWAI_SEM_E_NOSPT

/* _kernel_wai_sem */
#if _KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED	/* %jp{wai_sem, pol_sem, twai_semのコード統合を行うなら} */
#define _KERNEL_SPT_KWAI_SEM_E_ID		(_KERNEL_CFG_TWAI_SEM_E_ID    || _KERNEL_CFG_WAI_SEM_E_ID    || _KERNEL_CFG_POL_SEM_E_ID)
#define _KERNEL_SPT_KWAI_SEM_E_CTX		(_KERNEL_CFG_TWAI_SEM_E_CTX   || _KERNEL_CFG_WAI_SEM_E_CTX)
#define _KERNEL_SPT_KWAI_SEM_E_NOEXS	(_KERNEL_CFG_TWAI_SEM_E_NOEXS || _KERNEL_CFG_WAI_SEM_E_NOEXS || _KERNEL_CFG_POL_SEM_E_NOEXS)
#define _KERNEL_SPT_KWAI_SEM_E_TMOUT	(_KERNEL_CFG_TWAI_SEM_E_TMOUT                                || _KERNEL_CFG_POL_SEM_E_TMOUT)
#define _KERNEL_SPT_KWAI_SEM_E_RLWAI 	(_KERNEL_CFG_TWAI_SEM_E_RLWAI || _KERNEL_CFG_WAI_SEM_E_RLWAI)
#define _KERNEL_SPT_KWAI_SEM_E_DLT   	(_KERNEL_CFG_TWAI_SEM_E_DLT   || _KERNEL_CFG_WAI_SEM_E_DLT)
#define _KERNEL_SPT_KWAI_SEM_E_NOSPT	_KERNEL_CFG_TWAI_SEM_E_NOSPT
#else
#define _KERNEL_SPT_KWAI_SEM_E_ID		_KERNEL_CFG_TWAI_SEM_E_ID
#define _KERNEL_SPT_KWAI_SEM_E_CTX		_KERNEL_CFG_TWAI_SEM_E_CTX
#define _KERNEL_SPT_KWAI_SEM_E_NOEXS	_KERNEL_CFG_TWAI_SEM_E_NOEXS
#define _KERNEL_SPT_KWAI_SEM_E_TMOUT	_KERNEL_CFG_TWAI_SEM_E_TMOUT
#define _KERNEL_SPT_KWAI_SEM_E_RLWAI 	_KERNEL_CFG_TWAI_SEM_E_RLWAI 
#define _KERNEL_SPT_KWAI_SEM_E_DLT   	_KERNEL_CFG_TWAI_SEM_E_DLT   
#define _KERNEL_SPT_KWAI_SEM_E_NOSPT	_KERNEL_CFG_TWAI_SEM_E_NOSPT
#endif

/* ref_sem */
#define _KERNEL_SPT_REF_SEM_E_ID		_KERNEL_CFG_REF_SEM_E_ID
#define _KERNEL_SPT_REF_SEM_E_NOEXS		_KERNEL_CFG_REF_SEM_E_NOEXS
#define _KERNEL_SPT_REF_SEM_E_PAR		_KERNEL_CFG_REF_SEM_E_PAR
#define _KERNEL_SPT_REF_SEM_E_NOSPT		_KERNEL_CFG_REF_SEM_E_NOSPT


/* cre_flg */
#define _KERNEL_SPT_CRE_FLG_E_ID		_KERNEL_CFG_CRE_FLG_E_ID	
#define _KERNEL_SPT_CRE_FLG_E_RSATR 	_KERNEL_CFG_CRE_FLG_E_RSATR 
#define _KERNEL_SPT_CRE_FLG_E_OBJ		_KERNEL_CFG_CRE_FLG_E_OBJ
#define _KERNEL_SPT_CRE_FLG_E_NOMEM		_KERNEL_CFG_CRE_FLG_E_NOMEM	
#define _KERNEL_SPT_CRE_FLG_E_NOSPT		_KERNEL_CFG_CRE_FLG_E_NOSPT

/* acre_flg */
#define _KERNEL_SPT_ACRE_FLG_E_NOID		_KERNEL_CFG_ACRE_FLG_E_NOID	
#define _KERNEL_SPT_ACRE_FLG_E_RSATR	_KERNEL_CFG_ACRE_FLG_E_RSATR
#define _KERNEL_SPT_ACRE_FLG_E_NOMEM	_KERNEL_CFG_ACRE_FLG_E_NOMEM
#define _KERNEL_SPT_ACRE_FLG_E_NOSPT	_KERNEL_CFG_ACRE_FLG_E_NOSPT

/* del_flg */
#define _KERNEL_SPT_DEL_FLG_E_ID		_KERNEL_CFG_DEL_FLG_E_ID
#define _KERNEL_SPT_DEL_FLG_E_NOEXS		_KERNEL_CFG_DEL_FLG_E_NOEXS
#define _KERNEL_SPT_DEL_FLG_E_NOSPT		_KERNEL_CFG_DEL_FLG_E_NOSPT

/* set_flg */
#define _KERNEL_SPT_SET_FLG_E_ID		_KERNEL_CFG_SET_FLG_E_ID
#define _KERNEL_SPT_SET_FLG_E_NOEXS		_KERNEL_CFG_SET_FLG_E_NOEXS
#define _KERNEL_SPT_SET_FLG_E_PAR		_KERNEL_CFG_SET_FLG_E_PAR
#define _KERNEL_SPT_SET_FLG_E_NOSPT		_KERNEL_CFG_SET_FLG_E_NOSPT

/* iset_flg */
/* clr_flg */
#define _KERNEL_SPT_CLR_FLG_E_ID		_KERNEL_CFG_CLR_FLG_E_ID
#define _KERNEL_SPT_CLR_FLG_E_NOEXS		_KERNEL_CFG_CLR_FLG_E_NOEXS
#define _KERNEL_SPT_CLR_FLG_E_PAR		_KERNEL_CFG_CLR_FLG_E_PAR
#define _KERNEL_SPT_CLR_FLG_E_NOSPT		_KERNEL_CFG_CLR_FLG_E_NOSPT

/* wai_flg */
#define _KERNEL_SPT_WAI_FLG_E_ID		_KERNEL_CFG_WAI_FLG_E_ID		
#define _KERNEL_SPT_WAI_FLG_E_CTX		_KERNEL_CFG_WAI_FLG_E_CTX
#define _KERNEL_SPT_WAI_FLG_E_NOEXS		_KERNEL_CFG_WAI_FLG_E_NOEXS 
#define _KERNEL_SPT_WAI_FLG_E_PAR		_KERNEL_CFG_WAI_FLG_E_PAR   
#define _KERNEL_SPT_WAI_FLG_E_ILUSE		_KERNEL_CFG_WAI_FLG_E_ILUSE 
#define _KERNEL_SPT_WAI_FLG_E_RLWAI		_KERNEL_CFG_WAI_FLG_E_RLWAI 
#define _KERNEL_SPT_WAI_FLG_E_DLT		_KERNEL_CFG_WAI_FLG_E_DLT   
#define _KERNEL_SPT_WAI_FLG_E_NOSPT		_KERNEL_CFG_WAI_FLG_E_NOSPT		

/* pol_flg */
#define _KERNEL_SPT_POL_FLG_E_ID		_KERNEL_CFG_WAI_FLG_E_ID
#define _KERNEL_SPT_POL_FLG_E_NOEXS 	_KERNEL_CFG_WAI_FLG_E_NOEXS
#define _KERNEL_SPT_POL_FLG_E_PAR   	_KERNEL_CFG_WAI_FLG_E_PAR  
#define _KERNEL_SPT_POL_FLG_E_TMOUT   	_KERNEL_CFG_WAI_FLG_E_TMOUT
#define _KERNEL_SPT_POL_FLG_E_NOSPT		_KERNEL_CFG_WAI_FLG_E_NOSPT

/* twai_flg */
#if _KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED	/* %jp{twai_flgへの集約を行う場合} */
#define _KERNEL_SPT_TWAI_FLG_E_ID		(_KERNEL_CFG_TWAI_FLG_E_ID    || _KERNEL_CFG_WAI_FLG_E_ID    || _KERNEL_CFG_POL_FLG_E_ID) 
#define _KERNEL_SPT_TWAI_FLG_E_CTX		(_KERNEL_CFG_TWAI_FLG_E_CTX   || _KERNEL_CFG_WAI_FLG_E_CTX)
#define _KERNEL_SPT_TWAI_FLG_E_NOEXS 	(_KERNEL_CFG_TWAI_FLG_E_NOEXS || _KERNEL_CFG_WAI_FLG_E_NOEXS || _KERNEL_CFG_POL_FLG_E_NOEXS)
#define _KERNEL_SPT_TWAI_FLG_E_PAR   	(_KERNEL_CFG_TWAI_FLG_E_PAR   || _KERNEL_CFG_WAI_FLG_E_PAR   || _KERNEL_CFG_POL_FLG_E_PAR)
#define _KERNEL_SPT_TWAI_FLG_E_ILUSE 	(_KERNEL_CFG_TWAI_FLG_E_ILUSE || _KERNEL_CFG_WAI_FLG_E_ILUSE)
#define _KERNEL_SPT_TWAI_FLG_E_TMOUT   	(_KERNEL_CFG_TWAI_FLG_E_TMOUT                                || _KERNEL_CFG_POL_FLG_E_TMOUT)
#define _KERNEL_SPT_TWAI_FLG_E_RLWAI 	(_KERNEL_CFG_TWAI_FLG_E_RLWAI || _KERNEL_CFG_WAI_FLG_E_RLWAI)
#define _KERNEL_SPT_TWAI_FLG_E_DLT   	(_KERNEL_CFG_TWAI_FLG_E_DLT   || _KERNEL_CFG_WAI_FLG_E_DLT)
#define _KERNEL_SPT_TWAI_FLG_E_NOSPT	_KERNEL_CFG_TWAI_FLG_E_NOSPT
#else
#define _KERNEL_SPT_TWAI_FLG_E_ID		_KERNEL_CFG_TWAI_FLG_E_ID
#define _KERNEL_SPT_TWAI_FLG_E_CTX		_KERNEL_CFG_TWAI_FLG_E_CTX
#define _KERNEL_SPT_TWAI_FLG_E_NOEXS 	_KERNEL_CFG_TWAI_FLG_E_NOEXS
#define _KERNEL_SPT_TWAI_FLG_E_PAR   	_KERNEL_CFG_TWAI_FLG_E_PAR  
#define _KERNEL_SPT_TWAI_FLG_E_ILUSE 	_KERNEL_CFG_TWAI_FLG_E_ILUSE
#define _KERNEL_SPT_TWAI_FLG_E_TMOUT   	_KERNEL_CFG_TWAI_FLG_E_TMOUT
#define _KERNEL_SPT_TWAI_FLG_E_RLWAI 	_KERNEL_CFG_TWAI_FLG_E_RLWAI
#define _KERNEL_SPT_TWAI_FLG_E_DLT   	_KERNEL_CFG_TWAI_FLG_E_DLT  
#define _KERNEL_SPT_TWAI_FLG_E_NOSPT	_KERNEL_CFG_TWAI_FLG_E_NOSPT
#endif

/* ref_flg */
#define _KERNEL_SPT_REF_FLG_E_ID		_KERNEL_CFG_REF_FLG_E_ID
#define _KERNEL_SPT_REF_FLG_E_NOEXS 	_KERNEL_CFG_REF_FLG_E_NOEXS
#define _KERNEL_SPT_REF_FLG_E_PAR   	_KERNEL_CFG_REF_FLG_E_PAR  
#define _KERNEL_SPT_REF_FLG_E_NOSPT		_KERNEL_CFG_REF_FLG_E_NOSPT


/* cre_dtq */
/* acre_dtq */
/* del_dtq */
/* snd_dtq */
/* ipsnd_dtq */
/* tsnd_dtq */
/* fsnd_dtq */
/* ifsnd_dtq */
/* rcv_dtq */
/* prcv_dtq */
/* trcv_dtq */
/* ref_dtq */


/* cre_mbx */
#define _KERNEL_SPT_CRE_MBX_E_ID		_KERNEL_CFG_CRE_MBX_E_ID	
#define _KERNEL_SPT_CRE_MBX_E_RSATR 	_KERNEL_CFG_CRE_MBX_E_RSATR 
#define _KERNEL_SPT_CRE_MBX_E_OBJ		_KERNEL_CFG_CRE_MBX_E_OBJ
#define _KERNEL_SPT_CRE_MBX_E_NOMEM		_KERNEL_CFG_CRE_MBX_E_NOMEM	
#define _KERNEL_SPT_CRE_MBX_E_NOSPT		_KERNEL_CFG_CRE_MBX_E_NOSPT

/* acre_mbx */
#define _KERNEL_SPT_ACRE_MBX_E_NOID		_KERNEL_CFG_ACRE_MBX_E_NOID
#define _KERNEL_SPT_ACRE_MBX_E_RSATR 	_KERNEL_CFG_ACRE_MBX_E_RSATR
#define _KERNEL_SPT_ACRE_MBX_E_NOMEM	_KERNEL_CFG_ACRE_MBX_E_NOMEM	
#define _KERNEL_SPT_ACRE_MBX_E_NOSPT	_KERNEL_CFG_ACRE_MBX_E_NOSPT

/* del_mbx */
#define _KERNEL_SPT_DEL_MBX_E_ID		_KERNEL_CFG_DEL_MBX_E_ID
#define _KERNEL_SPT_DEL_MBX_E_NOEXS		_KERNEL_CFG_DEL_MBX_E_NOEXS
#define _KERNEL_SPT_DEL_MBX_E_NOSPT		_KERNEL_CFG_DEL_MBX_E_NOSPT

/* snd_mbx */
/* rcv_mbx */
/* prcv_mbx */
/* trcv_mbx */
/* ref_mbx */


/* cre_mtx */
/* acre_mtx */
/* del_mtx */
/* loc_mtx */
/* ploc_mtx */
/* tloc_mtx */
/* unl_mtx */
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
#define _KERNEL_SPT_CRE_MPF_E_ID		_KERNEL_CFG_CRE_MPF_E_ID	
#define _KERNEL_SPT_CRE_MPF_E_RSATR 	_KERNEL_CFG_CRE_MPF_E_RSATR 
#define _KERNEL_SPT_CRE_MPF_E_OBJ		_KERNEL_CFG_CRE_MPF_E_OBJ
#define _KERNEL_SPT_CRE_MPF_E_NOMEM		_KERNEL_CFG_CRE_MPF_E_NOMEM	
#define _KERNEL_SPT_CRE_MPF_E_NOSPT		_KERNEL_CFG_CRE_MPF_E_NOSPT

/* acre_mpf */
#define _KERNEL_SPT_ACRE_MPF_E_NOID		_KERNEL_CFG_ACRE_MPF_E_NOID
#define _KERNEL_SPT_ACRE_MPF_E_RSATR 	_KERNEL_CFG_ACRE_MPF_E_RSATR
#define _KERNEL_SPT_ACRE_MPF_E_NOMEM	_KERNEL_CFG_ACRE_MPF_E_NOMEM	
#define _KERNEL_SPT_ACRE_MPF_E_NOSPT	_KERNEL_CFG_ACRE_MPF_E_NOSPT

/* del_mpf */
#define _KERNEL_SPT_DEL_MPF_E_ID		_KERNEL_CFG_DEL_MPF_E_ID
#define _KERNEL_SPT_DEL_MPF_E_NOEXS		_KERNEL_CFG_DEL_MPF_E_NOEXS
#define _KERNEL_SPT_DEL_MPF_E_NOSPT		_KERNEL_CFG_DEL_MPF_E_NOSPT


/* get_mpf */
#define _KERNEL_SPT_GET_MPF_E_ID		_KERNEL_CFG_GET_MPF_E_ID
#define _KERNEL_SPT_GET_MPF_E_CTX		_KERNEL_CFG_GET_MPF_E_CTX
#define _KERNEL_SPT_GET_MPF_E_NOEXS 	_KERNEL_CFG_GET_MPF_E_NOEXS
#define _KERNEL_SPT_GET_MPF_E_PAR   	_KERNEL_CFG_GET_MPF_E_PAR  
#define _KERNEL_SPT_GET_MPF_E_ILUSE 	_KERNEL_CFG_GET_MPF_E_ILUSE
#define _KERNEL_SPT_GET_MPF_E_RLWAI 	_KERNEL_CFG_GET_MPF_E_RLWAI
#define _KERNEL_SPT_GET_MPF_E_DLT   	_KERNEL_CFG_GET_MPF_E_DLT  
#define _KERNEL_SPT_GET_MPF_E_NOSPT		_KERNEL_CFG_GET_MPF_E_NOSPT

/* pget_mpf */
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
#define _KERNEL_SPT_SET_TIM_E_PAR	 	_KERNEL_CFG_SET_TIM_E_PAR	
#define _KERNEL_SPT_SET_TIM_E_NOSPT		_KERNEL_CFG_SET_TIM_E_NOSPT	

/* get_tim */
#define _KERNEL_SPT_GET_TIM_E_PAR	 	_KERNEL_CFG_GET_TIM_E_PAR
#define _KERNEL_SPT_GET_TIM_E_NOSPT		_KERNEL_CFG_GET_TIM_E_NOSPT

/* isig_tim */
#define _KERNEL_SPT_ISIG_TIM_E_NOSPT	_KERNEL_CFG_ISIG_TIM_E_NOSPT



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




#endif	/* _KERNEL__parser__parserr_h__ */


/* end of file */
