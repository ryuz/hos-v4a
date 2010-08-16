# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for nmake
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# ----------------------------------
#  source copy
# ----------------------------------

makelib_srcobjcp:


$(OBJS_DIR)\ent_tsk.c : $(DSP_DIR)\ent_tsk.c
	$(CMD_CP) $(DSP_DIR)\ent_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\idl_lop.c : $(DSP_DIR)\idl_lop.c
	$(CMD_CP) $(DSP_DIR)\idl_lop.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_tsk.c : $(DSP_DIR)\dsp_tsk.c
	$(CMD_CP) $(DSP_DIR)\dsp_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_sta.c : $(DSP_DIR)\dsp_sta.c
	$(CMD_CP) $(DSP_DIR)\dsp_sta.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_ext.c : $(DSP_DIR)\dsp_ext.c
	$(CMD_CP) $(DSP_DIR)\dsp_ext.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_ter.c : $(DSP_DIR)\dsp_ter.c
	$(CMD_CP) $(DSP_DIR)\dsp_ter.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_wai.c : $(DSP_DIR)\dsp_wai.c
	$(CMD_CP) $(DSP_DIR)\dsp_wai.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_wup.c : $(DSP_DIR)\dsp_wup.c
	$(CMD_CP) $(DSP_DIR)\dsp_wup.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_sus.c : $(DSP_DIR)\dsp_sus.c
	$(CMD_CP) $(DSP_DIR)\dsp_sus.c $(OBJS_DIR)\

$(OBJS_DIR)\dsp_rsm.c : $(DSP_DIR)\dsp_rsm.c
	$(CMD_CP) $(DSP_DIR)\dsp_rsm.c $(OBJS_DIR)\


$(OBJS_DIR)\add_que.c : $(QUE_DIR)\add_que.c
	$(CMD_CP) $(QUE_DIR)\add_que.c $(OBJS_DIR)\

$(OBJS_DIR)\adf_que.c : $(QUE_DIR)\adf_que.c
	$(CMD_CP) $(QUE_DIR)\adf_que.c $(OBJS_DIR)\

$(OBJS_DIR)\adp_que.c : $(QUE_DIR)\adp_que.c
	$(CMD_CP) $(QUE_DIR)\adp_que.c $(OBJS_DIR)\

$(OBJS_DIR)\rmv_que.c : $(QUE_DIR)\rmv_que.c
	$(CMD_CP) $(QUE_DIR)\rmv_que.c $(OBJS_DIR)\

$(OBJS_DIR)\rmh_que.c : $(QUE_DIR)\rmh_que.c
	$(CMD_CP) $(QUE_DIR)\rmh_que.c $(OBJS_DIR)\

$(OBJS_DIR)\trm_que.c : $(QUE_DIR)\trm_que.c
	$(CMD_CP) $(QUE_DIR)\trm_que.c $(OBJS_DIR)\

$(OBJS_DIR)\nxt_que.c : $(QUE_DIR)\nxt_que.c
	$(CMD_CP) $(QUE_DIR)\nxt_que.c $(OBJS_DIR)\

$(OBJS_DIR)\rot_que.c : $(QUE_DIR)\rot_que.c
	$(CMD_CP) $(QUE_DIR)\rot_que.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_rdq.c : $(RDQ_DIR)\cre_rdq.c
	$(CMD_CP) $(RDQ_DIR)\cre_rdq.c $(OBJS_DIR)\

$(OBJS_DIR)\del_rdq.c : $(RDQ_DIR)\del_rdq.c
	$(CMD_CP) $(RDQ_DIR)\del_rdq.c $(OBJS_DIR)\

$(OBJS_DIR)\add_rdq.c : $(RDQ_DIR)\add_rdq.c
	$(CMD_CP) $(RDQ_DIR)\add_rdq.c $(OBJS_DIR)\

$(OBJS_DIR)\rmv_rdq.c : $(RDQ_DIR)\rmv_rdq.c
	$(CMD_CP) $(RDQ_DIR)\rmv_rdq.c $(OBJS_DIR)\

$(OBJS_DIR)\rmh_rdq.c : $(RDQ_DIR)\rmh_rdq.c
	$(CMD_CP) $(RDQ_DIR)\rmh_rdq.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_rdq.c : $(RDQ_DIR)\ref_rdq.c
	$(CMD_CP) $(RDQ_DIR)\ref_rdq.c $(OBJS_DIR)\


$(OBJS_DIR)\sig_tim.c : $(TIM_DIR)\sig_tim.c
	$(CMD_CP) $(TIM_DIR)\sig_tim.c $(OBJS_DIR)\


$(OBJS_DIR)\sig_toq.c : $(TOQ_DIR)\sig_toq.c
	$(CMD_CP) $(TOQ_DIR)\sig_toq.c $(OBJS_DIR)\

$(OBJS_DIR)\add_toq.c : $(TOQ_DIR)\add_toq.c
	$(CMD_CP) $(TOQ_DIR)\add_toq.c $(OBJS_DIR)\

$(OBJS_DIR)\rmv_toq.c : $(TOQ_DIR)\rmv_toq.c
	$(CMD_CP) $(TOQ_DIR)\rmv_toq.c $(OBJS_DIR)\


$(OBJS_DIR)\sig_tmq.c : $(TMQ_DIR)\sig_tmq.c
	$(CMD_CP) $(TMQ_DIR)\sig_tmq.c $(OBJS_DIR)\

$(OBJS_DIR)\add_tmq.c : $(TMQ_DIR)\add_tmq.c
	$(CMD_CP) $(TMQ_DIR)\add_tmq.c $(OBJS_DIR)\

$(OBJS_DIR)\rmv_tmq.c : $(TMQ_DIR)\rmv_tmq.c
	$(CMD_CP) $(TMQ_DIR)\rmv_tmq.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_hep.c : $(HEP_DIR)\cre_hep.c
	$(CMD_CP) $(HEP_DIR)\cre_hep.c $(OBJS_DIR)\

$(OBJS_DIR)\alc_hep.c : $(HEP_DIR)\alc_hep.c
	$(CMD_CP) $(HEP_DIR)\alc_hep.c $(OBJS_DIR)\

$(OBJS_DIR)\fre_hep.c : $(HEP_DIR)\fre_hep.c
	$(CMD_CP) $(HEP_DIR)\fre_hep.c $(OBJS_DIR)\


$(OBJS_DIR)\ini_dpc.c : $(DPC_DIR)\ini_dpc.c
	$(CMD_CP) $(DPC_DIR)\ini_dpc.c $(OBJS_DIR)\

$(OBJS_DIR)\req_dpc.c : $(DPC_DIR)\req_dpc.c
	$(CMD_CP) $(DPC_DIR)\req_dpc.c $(OBJS_DIR)\

$(OBJS_DIR)\exe_dpc.c : $(DPC_DIR)\exe_dpc.c
	$(CMD_CP) $(DPC_DIR)\exe_dpc.c $(OBJS_DIR)\


$(OBJS_DIR)\frcv_adq.c : $(ADTQ_DIR)\frcv_adq.c
	$(CMD_CP) $(ADTQ_DIR)\frcv_adq.c $(OBJS_DIR)\

$(OBJS_DIR)\fsnd_adq.c : $(ADTQ_DIR)\fsnd_adq.c
	$(CMD_CP) $(ADTQ_DIR)\fsnd_adq.c $(OBJS_DIR)\

$(OBJS_DIR)\rcv_adq.c : $(ADTQ_DIR)\rcv_adq.c
	$(CMD_CP) $(ADTQ_DIR)\rcv_adq.c $(OBJS_DIR)\

$(OBJS_DIR)\reff_adq.c : $(ADTQ_DIR)\reff_adq.c
	$(CMD_CP) $(ADTQ_DIR)\reff_adq.c $(OBJS_DIR)\

$(OBJS_DIR)\refs_adq.c : $(ADTQ_DIR)\refs_adq.c
	$(CMD_CP) $(ADTQ_DIR)\refs_adq.c $(OBJS_DIR)\

$(OBJS_DIR)\snd_adq.c : $(ADTQ_DIR)\snd_adq.c
	$(CMD_CP) $(ADTQ_DIR)\snd_adq.c $(OBJS_DIR)\


$(OBJS_DIR)\sta_knl.c : $(SYSOBJ_DIR)\sta_knl.c
	$(CMD_CP) $(SYSOBJ_DIR)\sta_knl.c $(OBJS_DIR)\

$(OBJS_DIR)\get_tid.c : $(SYSOBJ_DIR)\get_tid.c
	$(CMD_CP) $(SYSOBJ_DIR)\get_tid.c $(OBJS_DIR)\

$(OBJS_DIR)\loc_cpu.c : $(SYSOBJ_DIR)\loc_cpu.c
	$(CMD_CP) $(SYSOBJ_DIR)\loc_cpu.c $(OBJS_DIR)\

$(OBJS_DIR)\unl_cpu.c : $(SYSOBJ_DIR)\unl_cpu.c
	$(CMD_CP) $(SYSOBJ_DIR)\unl_cpu.c $(OBJS_DIR)\

$(OBJS_DIR)\sns_loc.c : $(SYSOBJ_DIR)\sns_loc.c
	$(CMD_CP) $(SYSOBJ_DIR)\sns_loc.c $(OBJS_DIR)\

$(OBJS_DIR)\ena_dsp.c : $(SYSOBJ_DIR)\ena_dsp.c
	$(CMD_CP) $(SYSOBJ_DIR)\ena_dsp.c $(OBJS_DIR)\

$(OBJS_DIR)\dis_dsp.c : $(SYSOBJ_DIR)\dis_dsp.c
	$(CMD_CP) $(SYSOBJ_DIR)\dis_dsp.c $(OBJS_DIR)\

$(OBJS_DIR)\sns_dsp.c : $(SYSOBJ_DIR)\sns_dsp.c
	$(CMD_CP) $(SYSOBJ_DIR)\sns_dsp.c $(OBJS_DIR)\

$(OBJS_DIR)\sns_ctx.c : $(SYSOBJ_DIR)\sns_ctx.c
	$(CMD_CP) $(SYSOBJ_DIR)\sns_ctx.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_tsk.c : $(TSKOBJ_DIR)\cre_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\cre_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_tsk.c : $(TSKOBJ_DIR)\acre_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\acre_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_tsk.c : $(TSKOBJ_DIR)\kcre_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\kcre_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\del_tsk.c : $(TSKOBJ_DIR)\del_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\del_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\act_tsk.c : $(TSKOBJ_DIR)\act_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\act_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\iact_tsk.c : $(TSKOBJ_DIR)\iact_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\iact_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\can_act.c : $(TSKOBJ_DIR)\can_act.c
	$(CMD_CP) $(TSKOBJ_DIR)\can_act.c $(OBJS_DIR)\

$(OBJS_DIR)\ext_tsk.c : $(TSKOBJ_DIR)\ext_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\ext_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\exd_tsk.c : $(TSKOBJ_DIR)\exd_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\exd_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\ter_tsk.c : $(TSKOBJ_DIR)\ter_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\ter_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\chg_pri.c : $(TSKOBJ_DIR)\chg_pri.c
	$(CMD_CP) $(TSKOBJ_DIR)\chg_pri.c $(OBJS_DIR)\

$(OBJS_DIR)\kchg_pri.c : $(TSKOBJ_DIR)\kchg_pri.c
	$(CMD_CP) $(TSKOBJ_DIR)\kchg_pri.c $(OBJS_DIR)\

$(OBJS_DIR)\get_pri.c : $(TSKOBJ_DIR)\get_pri.c
	$(CMD_CP) $(TSKOBJ_DIR)\get_pri.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_tsk.c : $(TSKOBJ_DIR)\ref_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\ref_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_tst.c : $(TSKOBJ_DIR)\ref_tst.c
	$(CMD_CP) $(TSKOBJ_DIR)\ref_tst.c $(OBJS_DIR)\

$(OBJS_DIR)\slp_tsk.c : $(TSKOBJ_DIR)\slp_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\slp_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\wup_tsk.c : $(TSKOBJ_DIR)\wup_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\wup_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\iwup_tsk.c : $(TSKOBJ_DIR)\iwup_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\iwup_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\can_wup.c : $(TSKOBJ_DIR)\can_wup.c
	$(CMD_CP) $(TSKOBJ_DIR)\can_wup.c $(OBJS_DIR)\

$(OBJS_DIR)\rel_wai.c : $(TSKOBJ_DIR)\rel_wai.c
	$(CMD_CP) $(TSKOBJ_DIR)\rel_wai.c $(OBJS_DIR)\

$(OBJS_DIR)\irel_wai.c : $(TSKOBJ_DIR)\irel_wai.c
	$(CMD_CP) $(TSKOBJ_DIR)\irel_wai.c $(OBJS_DIR)\

$(OBJS_DIR)\sus_tsk.c : $(TSKOBJ_DIR)\sus_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\sus_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\rsm_tsk.c : $(TSKOBJ_DIR)\rsm_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\rsm_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\frsm_tsk.c : $(TSKOBJ_DIR)\frsm_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\frsm_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\dly_tsk.c : $(TSKOBJ_DIR)\dly_tsk.c
	$(CMD_CP) $(TSKOBJ_DIR)\dly_tsk.c $(OBJS_DIR)\

$(OBJS_DIR)\def_tex.c : $(TSKOBJ_DIR)\def_tex.c
	$(CMD_CP) $(TSKOBJ_DIR)\def_tex.c $(OBJS_DIR)\

$(OBJS_DIR)\ras_tex.c : $(TSKOBJ_DIR)\ras_tex.c
	$(CMD_CP) $(TSKOBJ_DIR)\ras_tex.c $(OBJS_DIR)\

$(OBJS_DIR)\ena_tex.c : $(TSKOBJ_DIR)\ena_tex.c
	$(CMD_CP) $(TSKOBJ_DIR)\ena_tex.c $(OBJS_DIR)\

$(OBJS_DIR)\kexe_tex.c : $(TSKOBJ_DIR)\kexe_tex.c
	$(CMD_CP) $(TSKOBJ_DIR)\kexe_tex.c $(OBJS_DIR)\

$(OBJS_DIR)\tcb2id.c : $(TSKOBJ_DIR)\tcb2id.c
	$(CMD_CP) $(TSKOBJ_DIR)\tcb2id.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_sem.c : $(SEMOBJ_DIR)\cre_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\cre_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_sem.c : $(SEMOBJ_DIR)\acre_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\acre_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_sem.c : $(SEMOBJ_DIR)\kcre_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\kcre_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\del_sem.c : $(SEMOBJ_DIR)\del_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\del_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\sig_sem.c : $(SEMOBJ_DIR)\sig_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\sig_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\isig_sem.c : $(SEMOBJ_DIR)\isig_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\isig_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\wai_sem.c : $(SEMOBJ_DIR)\wai_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\wai_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\pol_sem.c : $(SEMOBJ_DIR)\pol_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\pol_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\twai_sem.c : $(SEMOBJ_DIR)\twai_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\twai_sem.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_sem.c : $(SEMOBJ_DIR)\ref_sem.c
	$(CMD_CP) $(SEMOBJ_DIR)\ref_sem.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_flg.c : $(FLGOBJ_DIR)\cre_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\cre_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_flg.c : $(FLGOBJ_DIR)\acre_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\acre_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_flg.c : $(FLGOBJ_DIR)\kcre_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\kcre_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\del_flg.c : $(FLGOBJ_DIR)\del_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\del_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\set_flg.c : $(FLGOBJ_DIR)\set_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\set_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\iset_flg.c : $(FLGOBJ_DIR)\iset_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\iset_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\clr_flg.c : $(FLGOBJ_DIR)\clr_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\clr_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\wai_flg.c : $(FLGOBJ_DIR)\wai_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\wai_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\pol_flg.c : $(FLGOBJ_DIR)\pol_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\pol_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\twai_flg.c : $(FLGOBJ_DIR)\twai_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\twai_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\kchk_flg.c : $(FLGOBJ_DIR)\kchk_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\kchk_flg.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_flg.c : $(FLGOBJ_DIR)\ref_flg.c
	$(CMD_CP) $(FLGOBJ_DIR)\ref_flg.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_dtq.c : $(DTQOBJ_DIR)\cre_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\cre_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_dtq.c : $(DTQOBJ_DIR)\acre_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\acre_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_dtq.c : $(DTQOBJ_DIR)\kcre_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\kcre_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\del_dtq.c : $(DTQOBJ_DIR)\del_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\del_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\snd_dtq.c : $(DTQOBJ_DIR)\snd_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\snd_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\fsnd_dtq.c : $(DTQOBJ_DIR)\fsnd_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\fsnd_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\rcv_dtq.c : $(DTQOBJ_DIR)\rcv_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\rcv_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\prcv_dtq.c : $(DTQOBJ_DIR)\prcv_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\prcv_dtq.c $(OBJS_DIR)\

$(OBJS_DIR)\trcv_dtq.c : $(DTQOBJ_DIR)\trcv_dtq.c
	$(CMD_CP) $(DTQOBJ_DIR)\trcv_dtq.c $(OBJS_DIR)\


$(OBJS_DIR)\acre_mbx.c : $(MBXOBJ_DIR)\acre_mbx.c
	$(CMD_CP) $(MBXOBJ_DIR)\acre_mbx.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_mbx.c : $(MBXOBJ_DIR)\kcre_mbx.c
	$(CMD_CP) $(MBXOBJ_DIR)\kcre_mbx.c $(OBJS_DIR)\

$(OBJS_DIR)\snd_mbx.c : $(MBXOBJ_DIR)\snd_mbx.c
	$(CMD_CP) $(MBXOBJ_DIR)\snd_mbx.c $(OBJS_DIR)\

$(OBJS_DIR)\rcv_mbx.c : $(MBXOBJ_DIR)\rcv_mbx.c
	$(CMD_CP) $(MBXOBJ_DIR)\rcv_mbx.c $(OBJS_DIR)\

$(OBJS_DIR)\kadf_msg.c : $(MBXOBJ_DIR)\kadf_msg.c
	$(CMD_CP) $(MBXOBJ_DIR)\kadf_msg.c $(OBJS_DIR)\

$(OBJS_DIR)\kadp_msg.c : $(MBXOBJ_DIR)\kadp_msg.c
	$(CMD_CP) $(MBXOBJ_DIR)\kadp_msg.c $(OBJS_DIR)\

$(OBJS_DIR)\kadd_msq.c : $(MBXOBJ_DIR)\kadd_msq.c
	$(CMD_CP) $(MBXOBJ_DIR)\kadd_msq.c $(OBJS_DIR)\

$(OBJS_DIR)\krmf_msg.c : $(MBXOBJ_DIR)\krmf_msg.c
	$(CMD_CP) $(MBXOBJ_DIR)\krmf_msg.c $(OBJS_DIR)\

$(OBJS_DIR)\krmp_msg.c : $(MBXOBJ_DIR)\krmp_msg.c
	$(CMD_CP) $(MBXOBJ_DIR)\krmp_msg.c $(OBJS_DIR)\

$(OBJS_DIR)\krmv_msq.c : $(MBXOBJ_DIR)\krmv_msq.c
	$(CMD_CP) $(MBXOBJ_DIR)\krmv_msq.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_mtx.c : $(MTXOBJ_DIR)\cre_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\cre_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_mtx.c : $(MTXOBJ_DIR)\acre_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\acre_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_mtx.c : $(MTXOBJ_DIR)\kcre_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\kcre_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\del_mtx.c : $(MTXOBJ_DIR)\del_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\del_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\loc_mtx.c : $(MTXOBJ_DIR)\loc_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\loc_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\ploc_mtx.c : $(MTXOBJ_DIR)\ploc_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\ploc_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\tloc_mtx.c : $(MTXOBJ_DIR)\tloc_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\tloc_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\unl_mtx.c : $(MTXOBJ_DIR)\unl_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\unl_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\kadd_mtx.c : $(MTXOBJ_DIR)\kadd_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\kadd_mtx.c $(OBJS_DIR)\

$(OBJS_DIR)\krmv_mtx.c : $(MTXOBJ_DIR)\krmv_mtx.c
	$(CMD_CP) $(MTXOBJ_DIR)\krmv_mtx.c $(OBJS_DIR)\


$(OBJS_DIR)\acre_mpf.c : $(MPFOBJ_DIR)\acre_mpf.c
	$(CMD_CP) $(MPFOBJ_DIR)\acre_mpf.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_mpf.c : $(MPFOBJ_DIR)\kcre_mpf.c
	$(CMD_CP) $(MPFOBJ_DIR)\kcre_mpf.c $(OBJS_DIR)\

$(OBJS_DIR)\get_mpf.c : $(MPFOBJ_DIR)\get_mpf.c
	$(CMD_CP) $(MPFOBJ_DIR)\get_mpf.c $(OBJS_DIR)\

$(OBJS_DIR)\pget_mpf.c : $(MPFOBJ_DIR)\pget_mpf.c
	$(CMD_CP) $(MPFOBJ_DIR)\pget_mpf.c $(OBJS_DIR)\

$(OBJS_DIR)\rel_mpf.c : $(MPFOBJ_DIR)\rel_mpf.c
	$(CMD_CP) $(MPFOBJ_DIR)\rel_mpf.c $(OBJS_DIR)\


$(OBJS_DIR)\set_tim.c : $(TIMOBJ_DIR)\set_tim.c
	$(CMD_CP) $(TIMOBJ_DIR)\set_tim.c $(OBJS_DIR)\

$(OBJS_DIR)\get_tim.c : $(TIMOBJ_DIR)\get_tim.c
	$(CMD_CP) $(TIMOBJ_DIR)\get_tim.c $(OBJS_DIR)\

$(OBJS_DIR)\isig_tim.c : $(TIMOBJ_DIR)\isig_tim.c
	$(CMD_CP) $(TIMOBJ_DIR)\isig_tim.c $(OBJS_DIR)\


$(OBJS_DIR)\cre_cyc.c : $(CYCOBJ_DIR)\cre_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\cre_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\acre_cyc.c : $(CYCOBJ_DIR)\acre_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\acre_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_cyc.c : $(CYCOBJ_DIR)\kcre_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\kcre_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\del_cyc.c : $(CYCOBJ_DIR)\del_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\del_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\sta_cyc.c : $(CYCOBJ_DIR)\sta_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\sta_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\stp_cyc.c : $(CYCOBJ_DIR)\stp_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\stp_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\ref_cyc.c : $(CYCOBJ_DIR)\ref_cyc.c
	$(CMD_CP) $(CYCOBJ_DIR)\ref_cyc.c $(OBJS_DIR)\

$(OBJS_DIR)\kcyc_hdr.c : $(CYCOBJ_DIR)\kcyc_hdr.c
	$(CMD_CP) $(CYCOBJ_DIR)\kcyc_hdr.c $(OBJS_DIR)\


$(OBJS_DIR)\def_inh.c : $(INHOBJ_DIR)\def_inh.c
	$(CMD_CP) $(INHOBJ_DIR)\def_inh.c $(OBJS_DIR)\

$(OBJS_DIR)\sta_inh.c : $(INHOBJ_DIR)\sta_inh.c
	$(CMD_CP) $(INHOBJ_DIR)\sta_inh.c $(OBJS_DIR)\

$(OBJS_DIR)\exe_inh.c : $(INHOBJ_DIR)\exe_inh.c
	$(CMD_CP) $(INHOBJ_DIR)\exe_inh.c $(OBJS_DIR)\

$(OBJS_DIR)\end_inh.c : $(INHOBJ_DIR)\end_inh.c
	$(CMD_CP) $(INHOBJ_DIR)\end_inh.c $(OBJS_DIR)\


$(OBJS_DIR)\acre_isr.c : $(ISROBJ_DIR)\acre_isr.c
	$(CMD_CP) $(ISROBJ_DIR)\acre_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\kcre_isr.c : $(ISROBJ_DIR)\kcre_isr.c
	$(CMD_CP) $(ISROBJ_DIR)\kcre_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\del_isr.c : $(ISROBJ_DIR)\del_isr.c
	$(CMD_CP) $(ISROBJ_DIR)\del_isr.c $(OBJS_DIR)\

$(OBJS_DIR)\exe_isr.c : $(ISROBJ_DIR)\exe_isr.c
	$(CMD_CP) $(ISROBJ_DIR)\exe_isr.c $(OBJS_DIR)\




# ----------------------------------
#  depend
# ----------------------------------

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ent_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\idl_lop.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_sta.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_ext.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_ter.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_wai.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_wup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_sus.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dsp_rsm.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\add_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\adf_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\adp_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmv_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmh_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\trm_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\nxt_que.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rot_que.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_rdq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_rdq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\add_rdq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmv_rdq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmh_rdq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_rdq.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sig_tim.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sig_toq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\add_toq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmv_toq.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sig_tmq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\add_tmq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rmv_tmq.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_hep.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\alc_hep.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\fre_hep.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ini_dpc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\req_dpc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exe_dpc.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\frcv_adq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\fsnd_adq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rcv_adq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\reff_adq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\refs_adq.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\snd_adq.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sta_knl.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\get_tid.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\loc_cpu.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\unl_cpu.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sns_loc.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ena_dsp.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dis_dsp.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sns_dsp.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sns_ctx.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\act_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\iact_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\can_act.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ext_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exd_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ter_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\chg_pri.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kchg_pri.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\get_pri.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_tst.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\slp_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\wup_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\iwup_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\can_wup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rel_wai.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\irel_wai.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sus_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rsm_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\frsm_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dly_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\def_tex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ras_tex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ena_tex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kexe_tex.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\tcb2id.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sig_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\isig_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\wai_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\pol_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\twai_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_sem.c	$(COMMON_HEADERS) $(SEMOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\set_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\iset_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\clr_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\wai_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\pol_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\twai_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kchk_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_flg.c	$(COMMON_HEADERS) $(FLGOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\snd_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\fsnd_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rcv_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\prcv_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\trcv_dtq.c	$(COMMON_HEADERS) $(DTQOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_mbx.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_mbx.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\snd_mbx.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rcv_mbx.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kadf_msg.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kadp_msg.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kadd_msq.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\krmf_msg.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\krmp_msg.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\krmv_msq.c	$(COMMON_HEADERS) $(MBXOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\loc_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ploc_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\tloc_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\unl_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kadd_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\krmv_mtx.c	$(COMMON_HEADERS) $(MTXOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_mpf.c	$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_mpf.c	$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\get_mpf.c	$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\pget_mpf.c	$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rel_mpf.c	$(COMMON_HEADERS) $(MPFOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\set_tim.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\get_tim.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\isig_tim.c	$(COMMON_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\cre_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sta_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\stp_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_cyc.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcyc_hdr.c	$(COMMON_HEADERS) $(CYCOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\def_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sta_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exe_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\end_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\del_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exe_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)



# end of file
