# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http:\\sourceforge.jp\projects\hos\
# ----------------------------------------------------------------------------



# ----------------------------------
#  %jp{ソースコピー}
# ----------------------------------
srcobjcp_makelib:
	$(CMD_CP) $(DSP_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(QUE_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(TOQ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(HEP_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(DPC_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(SYSOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(TSKOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(SEMOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(FLGOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(MBXOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(MPFOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(INHOBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(ISROBJ_DIR)\*.c $(OBJS_DIR)
	$(CMD_CP) $(TIMOBJ_DIR)\*.c $(OBJS_DIR)


# ----------------------------------
#  %jp{依存関係}
# ----------------------------------

$(OBJS_DIR)\ent_tsk.$(EXT_OBJ):		$(OBJS_DIR)\ent_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\idl_lop.$(EXT_OBJ):		$(OBJS_DIR)\idl_lop.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_tsk.$(EXT_OBJ):		$(OBJS_DIR)\dsp_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_sta.$(EXT_OBJ):		$(OBJS_DIR)\dsp_sta.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_ext.$(EXT_OBJ):		$(OBJS_DIR)\dsp_ext.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_ter.$(EXT_OBJ):		$(OBJS_DIR)\dsp_ter.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_wai.$(EXT_OBJ):		$(OBJS_DIR)\dsp_wai.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_wup.$(EXT_OBJ):		$(OBJS_DIR)\dsp_wup.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_sus.$(EXT_OBJ):		$(OBJS_DIR)\dsp_sus.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dsp_rsm.$(EXT_OBJ):		$(OBJS_DIR)\dsp_rsm.c		$(COMMON_HEADERS)
$(OBJS_DIR)\add_que.$(EXT_OBJ):		$(OBJS_DIR)\add_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\adf_que.$(EXT_OBJ):		$(OBJS_DIR)\adf_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\adp_que.$(EXT_OBJ):		$(OBJS_DIR)\adp_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\rmv_que.$(EXT_OBJ):		$(OBJS_DIR)\rmv_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\rmh_que.$(EXT_OBJ):		$(OBJS_DIR)\rmh_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\trm_que.$(EXT_OBJ):		$(OBJS_DIR)\trm_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\nxt_que.$(EXT_OBJ):		$(OBJS_DIR)\nxt_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\rot_que.$(EXT_OBJ):		$(OBJS_DIR)\rot_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)\sig_toq.$(EXT_OBJ):		$(OBJS_DIR)\sig_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)\add_toq.$(EXT_OBJ):		$(OBJS_DIR)\add_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)\rmv_toq.$(EXT_OBJ):		$(OBJS_DIR)\rmv_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)\cre_hep.$(EXT_OBJ):		$(OBJS_DIR)\cre_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)\alc_hep.$(EXT_OBJ):		$(OBJS_DIR)\alc_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)\fre_hep.$(EXT_OBJ):		$(OBJS_DIR)\fre_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dpc_fre.$(EXT_OBJ):		$(OBJS_DIR)\dpc_fre.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dpc_rcv.$(EXT_OBJ):		$(OBJS_DIR)\dpc_rcv.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dpc_snd.$(EXT_OBJ):		$(OBJS_DIR)\dpc_snd.c		$(COMMON_HEADERS)
$(OBJS_DIR)\lev_svc.$(EXT_OBJ):		$(OBJS_DIR)\lev_svc.c		$(COMMON_HEADERS)

$(OBJS_DIR)\sta_knl.$(EXT_OBJ):		$(OBJS_DIR)\sta_knl.c		$(COMMON_HEADERS)
$(OBJS_DIR)\get_tid.$(EXT_OBJ):		$(OBJS_DIR)\get_tid.c		$(COMMON_HEADERS)
$(OBJS_DIR)\loc_cpu.$(EXT_OBJ):		$(OBJS_DIR)\loc_cpu.c		$(COMMON_HEADERS)
$(OBJS_DIR)\unl_cpu.$(EXT_OBJ):		$(OBJS_DIR)\unl_cpu.c		$(COMMON_HEADERS)
$(OBJS_DIR)\sns_loc.$(EXT_OBJ):		$(OBJS_DIR)\sns_loc.c		$(COMMON_HEADERS)
$(OBJS_DIR)\ena_dsp.$(EXT_OBJ):		$(OBJS_DIR)\ena_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dis_dsp.$(EXT_OBJ):		$(OBJS_DIR)\dis_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)\sns_dsp.$(EXT_OBJ):		$(OBJS_DIR)\sns_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)\sns_ctx.$(EXT_OBJ):		$(OBJS_DIR)\sns_ctx.c		$(COMMON_HEADERS)

$(OBJS_DIR)\acre_tsk.$(EXT_OBJ):	$(OBJS_DIR)\acre_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\kcre_tsk.$(EXT_OBJ):	$(OBJS_DIR)\kcre_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\act_tsk.$(EXT_OBJ):		$(OBJS_DIR)\act_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\ext_tsk.$(EXT_OBJ):		$(OBJS_DIR)\ext_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\slp_tsk.$(EXT_OBJ):		$(OBJS_DIR)\slp_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\wup_tsk.$(EXT_OBJ):		$(OBJS_DIR)\wup_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\can_wup.$(EXT_OBJ):		$(OBJS_DIR)\can_wup.c		$(COMMON_HEADERS)
$(OBJS_DIR)\rel_wai.$(EXT_OBJ):		$(OBJS_DIR)\rel_wai.c		$(COMMON_HEADERS)
$(OBJS_DIR)\dly_tsk.$(EXT_OBJ):		$(OBJS_DIR)\dly_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)\ref_tsk.$(EXT_OBJ):		$(OBJS_DIR)\ref_tsk.c		$(COMMON_HEADERS)

$(OBJS_DIR)\cre_sem.$(EXT_OBJ):		$(OBJS_DIR)\cre_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\acre_sem.$(EXT_OBJ):	$(OBJS_DIR)\acre_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\kcre_sem.$(EXT_OBJ):	$(OBJS_DIR)\kcre_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\del_sem.$(EXT_OBJ):		$(OBJS_DIR)\del_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\sig_sem.$(EXT_OBJ):		$(OBJS_DIR)\sig_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\wai_sem.$(EXT_OBJ):		$(OBJS_DIR)\wai_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\pol_sem.$(EXT_OBJ):		$(OBJS_DIR)\pol_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\twai_sem.$(EXT_OBJ):	$(OBJS_DIR)\twai_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\ref_sem.$(EXT_OBJ):		$(OBJS_DIR)\ref_sem.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\cre_flg.$(EXT_OBJ):		$(OBJS_DIR)\cre_flg.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\acre_flg.$(EXT_OBJ):	$(OBJS_DIR)\acre_flg.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)
$(OBJS_DIR)\kcre_flg.$(EXT_OBJ):	$(OBJS_DIR)\kcre_flg.c		$(COMMON_HEADERS) $(SEMOBJ_HEADERS)

$(OBJS_DIR)\cre_flg.$(EXT_OBJ):		$(OBJS_DIR)\cre_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\acre_flg.$(EXT_OBJ):	$(OBJS_DIR)\acre_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\kcre_flg.$(EXT_OBJ):	$(OBJS_DIR)\kcre_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\del_flg.$(EXT_OBJ):		$(OBJS_DIR)\del_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\set_flg.$(EXT_OBJ):		$(OBJS_DIR)\set_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\iset_flg.$(EXT_OBJ):	$(OBJS_DIR)\iset_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\clr_flg.$(EXT_OBJ):		$(OBJS_DIR)\clr_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\wai_flg.$(EXT_OBJ):		$(OBJS_DIR)\wai_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\pol_flg.$(EXT_OBJ):		$(OBJS_DIR)\pol_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\twai_flg.$(EXT_OBJ):	$(OBJS_DIR)\twai_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\kchk_flg.$(EXT_OBJ):	$(OBJS_DIR)\kchk_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)
$(OBJS_DIR)\ref_flg.$(EXT_OBJ):		$(OBJS_DIR)\ref_flg.c		$(COMMON_HEADERS) $(FLGOBJ_HEADERS)

$(OBJS_DIR)\acre_mbx.$(EXT_OBJ):	$(OBJS_DIR)\acre_mbx.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\kcre_mbx.$(EXT_OBJ):	$(OBJS_DIR)\kcre_mbx.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\snd_mbx.$(EXT_OBJ):		$(OBJS_DIR)\snd_mbx.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\rcv_mbx.$(EXT_OBJ):		$(OBJS_DIR)\rcv_mbx.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\kadf_msg.$(EXT_OBJ):	$(OBJS_DIR)\kadf_msg.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\kadp_msg.$(EXT_OBJ):	$(OBJS_DIR)\kadp_msg.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\kadd_msq.$(EXT_OBJ):	$(OBJS_DIR)\kadd_msq.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\krmf_msg.$(EXT_OBJ):	$(OBJS_DIR)\krmf_msg.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\krmp_msg.$(EXT_OBJ):	$(OBJS_DIR)\krmp_msg.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)
$(OBJS_DIR)\krmv_msq.$(EXT_OBJ):	$(OBJS_DIR)\krmv_msq.c		$(COMMON_HEADERS) $(MBXOBJ_HEADERS)

$(OBJS_DIR)\acre_mpf.$(EXT_OBJ):	$(OBJS_DIR)\acre_mpf.c		$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\kcre_mpf.$(EXT_OBJ):	$(OBJS_DIR)\kcre_mpf.c		$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\get_mpf.$(EXT_OBJ):		$(OBJS_DIR)\get_mpf.c		$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\pget_mpf.$(EXT_OBJ):	$(OBJS_DIR)\pget_mpf.c		$(COMMON_HEADERS) $(MPFOBJ_HEADERS)
$(OBJS_DIR)\rel_mpf.$(EXT_OBJ):		$(OBJS_DIR)\rel_mpf.c		$(COMMON_HEADERS) $(MPFOBJ_HEADERS)

$(OBJS_DIR)\set_tim.$(EXT_OBJ):		$(OBJS_DIR)\set_tim.c		$(COMMON_HEADERS) $(TIMOBJ_HEADERS)
$(OBJS_DIR)\get_tim.$(EXT_OBJ):		$(OBJS_DIR)\get_tim.c		$(COMMON_HEADERS) $(TIMOBJ_HEADERS)
$(OBJS_DIR)\isig_tim.$(EXT_OBJ):	$(OBJS_DIR)\isig_tim.c		$(COMMON_HEADERS) $(TIMOBJ_HEADERS)

$(OBJS_DIR)\def_inh.$(EXT_OBJ):		$(OBJS_DIR)\def_inh.c		$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\sta_inh.$(EXT_OBJ):		$(OBJS_DIR)\sta_inh.c		$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\exe_inh.$(EXT_OBJ):		$(OBJS_DIR)\exe_inh.c		$(COMMON_HEADERS) $(INHOBJ_HEADERS)
$(OBJS_DIR)\end_inh.$(EXT_OBJ):		$(OBJS_DIR)\end_inh.c		$(COMMON_HEADERS) $(INHOBJ_HEADERS)

$(OBJS_DIR)\acre_isr.$(EXT_OBJ):	$(OBJS_DIR)\acre_isr.c		$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\kcre_isr.$(EXT_OBJ):	$(OBJS_DIR)\kcre_isr.c		$(COMMON_HEADERS) $(ISROBJ_HEADERS)
$(OBJS_DIR)\exe_isr.$(EXT_OBJ):		$(OBJS_DIR)\exe_isr.c		$(COMMON_HEADERS) $(ISROBJ_HEADERS)


# end of file
