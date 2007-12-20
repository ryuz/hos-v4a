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
srcobjcp_makelib:
	$(CMD_CP) $(DSP_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(QUE_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(RDQ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(TIM_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(TOQ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(TMQ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(HEP_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(DPC_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(ADTQ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(SYSOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(TSKOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(SEMOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(FLGOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(DTQOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(MBXOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(MTXOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(MPFOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(TIMOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(INHOBJ_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(ISROBJ_DIR)\*.* $(OBJS_DIR)



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

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\act_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ext_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\slp_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\wup_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\can_wup.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rel_wai.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sus_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\rsm_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\dly_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\ref_tst.c	$(COMMON_HEADERS)

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

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\def_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\sta_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exe_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\end_inh.c	$(COMMON_HEADERS) $(INHOBJ_HEADERS)

$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\acre_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\kcre_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr..$(EXT_OBJ):	$(OBJS_DIR)\exe_isr.c	$(COMMON_HEADERS) $(ISROBJ_HEADERS)



# end of file
