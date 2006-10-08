
KERNEL_DIR  = $(TOP_DIR)/kernel
SRC_DIR     = $(KERNEL_DIR)/source
INC_DIR     = $(KERNEL_DIR)/include

CORE_DIR    = $(SRC_DIR)/core
OBJ_DIR     = $(SRC_DIR)/object

DSP_DIR     = $(CORE_DIR)/dsp
QUE_DIR     = $(CORE_DIR)/que
TOQ_DIR     = $(CORE_DIR)/toq
HEP_DIR     = $(CORE_DIR)/hep

SYSOBJ_DIR  = $(OBJ_DIR)/sys
TSKOBJ_DIR  = $(OBJ_DIR)/tsk
SEMOBJ_DIR  = $(OBJ_DIR)/sem
FLGOBJ_DIR  = $(OBJ_DIR)/flg
MBXOBJ_DIR  = $(OBJ_DIR)/mbx
MPFOBJ_DIR  = $(OBJ_DIR)/mpf
INHOBJ_DIR  = $(OBJ_DIR)/inh
ISROBJ_DIR  = $(OBJ_DIR)/isr
TIMOBJ_DIR  = $(OBJ_DIR)/tim


VPATH := $(VPATH):$(DSP_DIR):$(QUE_DIR):$(TOQ_DIR):$(HEP_DIR):$(SYSOBJ_DIR):$(TSKOBJ_DIR)
VPATH := $(VPATH):$(SEMOBJ_DIR):$(FLGOBJ_DIR):$(MBXOBJ_DIR):$(MPFOBJ_DIR):$(INHOBJ_DIR):$(ISROBJ_DIR):$(TIMOBJ_DIR)


CSRCS += $(DSP_DIR)/ent_tsk.c		\
         $(DSP_DIR)/idl_lop.c		\
         $(DSP_DIR)/dsp_tsk.c		\
         $(DSP_DIR)/dsp_sta.c		\
         $(DSP_DIR)/dsp_ext.c		\
         $(DSP_DIR)/dsp_ter.c		\
         $(DSP_DIR)/dsp_wai.c		\
         $(DSP_DIR)/dsp_wup.c		\
         $(DSP_DIR)/dsp_sus.c		\
         $(DSP_DIR)/dsp_rsm.c		\
         $(QUE_DIR)/add_que.c		\
         $(QUE_DIR)/adf_que.c		\
         $(QUE_DIR)/adp_que.c		\
         $(QUE_DIR)/rmv_que.c		\
         $(QUE_DIR)/rmh_que.c		\
         $(QUE_DIR)/trm_que.c		\
         $(QUE_DIR)/nxt_que.c		\
         $(QUE_DIR)/rot_que.c		\
         $(TOQ_DIR)/sig_toq.c		\
         $(TOQ_DIR)/add_toq.c		\
         $(TOQ_DIR)/rmv_toq.c		\
         $(HEP_DIR)/cre_hep.c		\
         $(HEP_DIR)/alc_hep.c		\
         $(HEP_DIR)/fre_hep.c		\
         $(SYSOBJ_DIR)/sta_knl.c	\
         $(SYSOBJ_DIR)/get_tid.c	\
         $(SYSOBJ_DIR)/loc_cpu.c	\
         $(SYSOBJ_DIR)/unl_cpu.c	\
         $(SYSOBJ_DIR)/sns_loc.c	\
         $(SYSOBJ_DIR)/ena_dsp.c	\
         $(SYSOBJ_DIR)/dis_dsp.c	\
         $(SYSOBJ_DIR)/sns_dsp.c	\
         $(SYSOBJ_DIR)/sns_ctx.c	\
         $(TSKOBJ_DIR)/acre_tsk.c	\
         $(TSKOBJ_DIR)/kcre_tsk.c	\
         $(TSKOBJ_DIR)/act_tsk.c	\
         $(TSKOBJ_DIR)/ext_tsk.c	\
         $(TSKOBJ_DIR)/slp_tsk.c	\
         $(TSKOBJ_DIR)/wup_tsk.c	\
         $(TSKOBJ_DIR)/can_wup.c	\
         $(TSKOBJ_DIR)/rel_wai.c	\
         $(TSKOBJ_DIR)/dly_tsk.c	\
         $(TSKOBJ_DIR)/ref_tsk.c	\
         $(SEMOBJ_DIR)/cre_sem.c	\
         $(SEMOBJ_DIR)/acre_sem.c	\
         $(SEMOBJ_DIR)/kcre_sem.c	\
         $(SEMOBJ_DIR)/sig_sem.c	\
         $(SEMOBJ_DIR)/wai_sem.c	\
         $(SEMOBJ_DIR)/pol_sem.c	\
         $(SEMOBJ_DIR)/twai_sem.c	\
         $(SEMOBJ_DIR)/ref_sem.c	\
         $(FLGOBJ_DIR)/cre_flg.c	\
         $(FLGOBJ_DIR)/acre_flg.c	\
         $(FLGOBJ_DIR)/kcre_flg.c	\
         $(FLGOBJ_DIR)/set_flg.c	\
         $(FLGOBJ_DIR)/clr_flg.c	\
         $(FLGOBJ_DIR)/wai_flg.c	\
         $(FLGOBJ_DIR)/pol_flg.c	\
         $(FLGOBJ_DIR)/twai_flg.c	\
         $(FLGOBJ_DIR)/kchk_flg.c	\
         $(FLGOBJ_DIR)/ref_flg.c	\
         $(MBXOBJ_DIR)/acre_mbx.c	\
         $(MBXOBJ_DIR)/kcre_mbx.c	\
         $(MBXOBJ_DIR)/snd_mbx.c	\
         $(MBXOBJ_DIR)/rcv_mbx.c	\
         $(MBXOBJ_DIR)/kadf_msg.c	\
         $(MBXOBJ_DIR)/kadp_msg.c	\
         $(MBXOBJ_DIR)/kadd_msq.c	\
         $(MBXOBJ_DIR)/krmf_msg.c	\
         $(MBXOBJ_DIR)/krmp_msg.c	\
         $(MBXOBJ_DIR)/krmv_msq.c	\
         $(MPFOBJ_DIR)/acre_mpf.c	\
         $(MPFOBJ_DIR)/kcre_mpf.c	\
         $(MPFOBJ_DIR)/get_mpf.c	\
         $(MPFOBJ_DIR)/pget_mpf.c	\
         $(MPFOBJ_DIR)/rel_mpf.c	\
         $(TIMOBJ_DIR)/set_tim.c	\
         $(TIMOBJ_DIR)/get_tim.c	\
         $(TIMOBJ_DIR)/isig_tim.c	\
         $(INHOBJ_DIR)/def_inh.c	\
         $(INHOBJ_DIR)/sta_inh.c	\
         $(INHOBJ_DIR)/exe_inh.c	\
         $(INHOBJ_DIR)/end_inh.c	\
         $(ISROBJ_DIR)/acre_isr.c	\
         $(ISROBJ_DIR)/kcre_isr.c	\
         $(ISROBJ_DIR)/exe_isr.c



CORE_HEADERS = $(INC_DIR)/core/adtq.h		\
               $(INC_DIR)/core/basetyp.h	\
               $(INC_DIR)/core/chkptr.h		\
               $(INC_DIR)/core/cmpl.h		\
               $(INC_DIR)/core/core.h		\
               $(INC_DIR)/core/dsp.h		\
               $(INC_DIR)/core/hep.h		\
               $(INC_DIR)/core/objhdl.h		\
               $(INC_DIR)/core/objid.h		\
               $(INC_DIR)/core/opttyp.h		\
               $(INC_DIR)/core/que.h		\
               $(INC_DIR)/core/rdq.h		\
               $(INC_DIR)/core/sys.h		\
               $(INC_DIR)/core/tmq.h		\
               $(INC_DIR)/core/toq.h


COMMON_HEADERS = $(CORE_HEADERS)


$(OBJS_DIR)/ent_tsk.$(OBJ_EXT):		$(DSP_DIR)/ent_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/idl_lop.$(OBJ_EXT):		$(DSP_DIR)/idl_lop.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_tsk.$(OBJ_EXT):		$(DSP_DIR)/dsp_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_sta.$(OBJ_EXT):		$(DSP_DIR)/dsp_sta.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_ext.$(OBJ_EXT):		$(DSP_DIR)/dsp_ext.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_ter.$(OBJ_EXT):		$(DSP_DIR)/dsp_ter.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_wai.$(OBJ_EXT):		$(DSP_DIR)/dsp_wai.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_wup.$(OBJ_EXT):		$(DSP_DIR)/dsp_wup.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_sus.$(OBJ_EXT):		$(DSP_DIR)/dsp_sus.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dsp_rsm.$(OBJ_EXT):		$(DSP_DIR)/dsp_rsm.c		$(COMMON_HEADERS)
$(OBJS_DIR)/add_que.$(OBJ_EXT):		$(QUE_DIR)/add_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/adf_que.$(OBJ_EXT):		$(QUE_DIR)/adf_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/adp_que.$(OBJ_EXT):		$(QUE_DIR)/adp_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rmv_que.$(OBJ_EXT):		$(QUE_DIR)/rmv_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rmh_que.$(OBJ_EXT):		$(QUE_DIR)/rmh_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/trm_que.$(OBJ_EXT):		$(QUE_DIR)/trm_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/nxt_que.$(OBJ_EXT):		$(QUE_DIR)/nxt_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rot_que.$(OBJ_EXT):		$(QUE_DIR)/rot_que.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sig_toq.$(OBJ_EXT):		$(TOQ_DIR)/sig_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)/add_toq.$(OBJ_EXT):		$(TOQ_DIR)/add_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rmv_toq.$(OBJ_EXT):		$(TOQ_DIR)/rmv_toq.c		$(COMMON_HEADERS)
$(OBJS_DIR)/cre_hep.$(OBJ_EXT):		$(HEP_DIR)/cre_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)/alc_hep.$(OBJ_EXT):		$(HEP_DIR)/alc_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)/fre_hep.$(OBJ_EXT):		$(HEP_DIR)/fre_hep.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sta_knl.$(OBJ_EXT):		$(SYSOBJ_DIR)/sta_knl.c		$(COMMON_HEADERS)
$(OBJS_DIR)/get_tid.$(OBJ_EXT):		$(SYSOBJ_DIR)/get_tid.c		$(COMMON_HEADERS)
$(OBJS_DIR)/loc_cpu.$(OBJ_EXT):		$(SYSOBJ_DIR)/loc_cpu.c		$(COMMON_HEADERS)
$(OBJS_DIR)/unl_cpu.$(OBJ_EXT):		$(SYSOBJ_DIR)/unl_cpu.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sns_loc.$(OBJ_EXT):		$(SYSOBJ_DIR)/sns_loc.c		$(COMMON_HEADERS)
$(OBJS_DIR)/ena_dsp.$(OBJ_EXT):		$(SYSOBJ_DIR)/ena_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dis_dsp.$(OBJ_EXT):		$(SYSOBJ_DIR)/dis_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sns_dsp.$(OBJ_EXT):		$(SYSOBJ_DIR)/sns_dsp.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sns_ctx.$(OBJ_EXT):		$(SYSOBJ_DIR)/sns_ctx.c		$(COMMON_HEADERS)
$(OBJS_DIR)/acre_tsk.$(OBJ_EXT):	$(TSKOBJ_DIR)/acre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_tsk.$(OBJ_EXT):	$(TSKOBJ_DIR)/kcre_tsk.c	$(COMMON_HEADERS)
$(OBJS_DIR)/act_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/act_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/ext_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/ext_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/slp_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/slp_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/wup_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/wup_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/can_wup.$(OBJ_EXT):		$(TSKOBJ_DIR)/can_wup.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rel_wai.$(OBJ_EXT):		$(TSKOBJ_DIR)/rel_wai.c		$(COMMON_HEADERS)
$(OBJS_DIR)/dly_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/dly_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/ref_tsk.$(OBJ_EXT):		$(TSKOBJ_DIR)/ref_tsk.c		$(COMMON_HEADERS)
$(OBJS_DIR)/cre_sem.$(OBJ_EXT):		$(SEMOBJ_DIR)/cre_sem.c		$(COMMON_HEADERS)
$(OBJS_DIR)/acre_sem.$(OBJ_EXT):	$(SEMOBJ_DIR)/acre_sem.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_sem.$(OBJ_EXT):	$(SEMOBJ_DIR)/kcre_sem.c	$(COMMON_HEADERS)
$(OBJS_DIR)/sig_sem.$(OBJ_EXT):		$(SEMOBJ_DIR)/sig_sem.c		$(COMMON_HEADERS)
$(OBJS_DIR)/wai_sem.$(OBJ_EXT):		$(SEMOBJ_DIR)/wai_sem.c		$(COMMON_HEADERS)
$(OBJS_DIR)/pol_sem.$(OBJ_EXT):		$(SEMOBJ_DIR)/pol_sem.c		$(COMMON_HEADERS)
$(OBJS_DIR)/twai_sem.$(OBJ_EXT):	$(SEMOBJ_DIR)/twai_sem.c	$(COMMON_HEADERS)
$(OBJS_DIR)/ref_sem.$(OBJ_EXT):		$(SEMOBJ_DIR)/ref_sem.c		$(COMMON_HEADERS)
$(OBJS_DIR)/cre_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/cre_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/acre_flg.$(OBJ_EXT):	$(FLGOBJ_DIR)/acre_flg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_flg.$(OBJ_EXT):	$(FLGOBJ_DIR)/kcre_flg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/set_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/set_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/clr_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/clr_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/wai_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/wai_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/pol_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/pol_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/twai_flg.$(OBJ_EXT):	$(FLGOBJ_DIR)/twai_flg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kchk_flg.$(OBJ_EXT):	$(FLGOBJ_DIR)/kchk_flg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/ref_flg.$(OBJ_EXT):		$(FLGOBJ_DIR)/ref_flg.c		$(COMMON_HEADERS)
$(OBJS_DIR)/acre_mbx.$(OBJ_EXT):	$(MBXOBJ_DIR)/acre_mbx.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_mbx.$(OBJ_EXT):	$(MBXOBJ_DIR)/kcre_mbx.c	$(COMMON_HEADERS)
$(OBJS_DIR)/snd_mbx.$(OBJ_EXT):		$(MBXOBJ_DIR)/snd_mbx.c		$(COMMON_HEADERS)
$(OBJS_DIR)/rcv_mbx.$(OBJ_EXT):		$(MBXOBJ_DIR)/rcv_mbx.c		$(COMMON_HEADERS)
$(OBJS_DIR)/kadf_msg.$(OBJ_EXT):	$(MBXOBJ_DIR)/kadf_msg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kadp_msg.$(OBJ_EXT):	$(MBXOBJ_DIR)/kadp_msg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kadd_msq.$(OBJ_EXT):	$(MBXOBJ_DIR)/kadd_msq.c	$(COMMON_HEADERS)
$(OBJS_DIR)/krmf_msg.$(OBJ_EXT):	$(MBXOBJ_DIR)/krmf_msg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/krmp_msg.$(OBJ_EXT):	$(MBXOBJ_DIR)/krmp_msg.c	$(COMMON_HEADERS)
$(OBJS_DIR)/krmv_msq.$(OBJ_EXT):	$(MBXOBJ_DIR)/krmv_msq.c	$(COMMON_HEADERS)
$(OBJS_DIR)/acre_mpf.$(OBJ_EXT):	$(MPFOBJ_DIR)/acre_mpf.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_mpf.$(OBJ_EXT):	$(MPFOBJ_DIR)/kcre_mpf.c	$(COMMON_HEADERS)
$(OBJS_DIR)/get_mpf.$(OBJ_EXT):		$(MPFOBJ_DIR)/get_mpf.c		$(COMMON_HEADERS)
$(OBJS_DIR)/pget_mpf.$(OBJ_EXT):	$(MPFOBJ_DIR)/pget_mpf.c	$(COMMON_HEADERS)
$(OBJS_DIR)/rel_mpf.$(OBJ_EXT):		$(MPFOBJ_DIR)/rel_mpf.c		$(COMMON_HEADERS)
$(OBJS_DIR)/set_tim.$(OBJ_EXT):		$(TIMOBJ_DIR)/set_tim.c		$(COMMON_HEADERS)
$(OBJS_DIR)/get_tim.$(OBJ_EXT):		$(TIMOBJ_DIR)/get_tim.c		$(COMMON_HEADERS)
$(OBJS_DIR)/isig_tim.$(OBJ_EXT):	$(TIMOBJ_DIR)/isig_tim.c	$(COMMON_HEADERS)
$(OBJS_DIR)/def_inh.$(OBJ_EXT):		$(INHOBJ_DIR)/def_inh.c		$(COMMON_HEADERS)
$(OBJS_DIR)/sta_inh.$(OBJ_EXT):		$(INHOBJ_DIR)/sta_inh.c		$(COMMON_HEADERS)
$(OBJS_DIR)/exe_inh.$(OBJ_EXT):		$(INHOBJ_DIR)/exe_inh.c		$(COMMON_HEADERS)
$(OBJS_DIR)/end_inh.$(OBJ_EXT):		$(INHOBJ_DIR)/end_inh.c		$(COMMON_HEADERS)
$(OBJS_DIR)/acre_isr.$(OBJ_EXT):	$(ISROBJ_DIR)/acre_isr.c	$(COMMON_HEADERS)
$(OBJS_DIR)/kcre_isr.$(OBJ_EXT):	$(ISROBJ_DIR)/kcre_isr.c	$(COMMON_HEADERS)
$(OBJS_DIR)/exe_isr.$(OBJ_EXT):		$(ISROBJ_DIR)/exe_isr.c		$(COMMON_HEADERS)

