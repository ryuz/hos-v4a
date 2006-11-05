# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Directories
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


# C source files
CSRCS         += $(DSP_DIR)/ent_tsk.c			\
                 $(DSP_DIR)/idl_lop.c			\
                 $(DSP_DIR)/dsp_tsk.c			\
                 $(DSP_DIR)/dsp_sta.c			\
                 $(DSP_DIR)/dsp_ext.c			\
                 $(DSP_DIR)/dsp_ter.c			\
                 $(DSP_DIR)/dsp_wai.c			\
                 $(DSP_DIR)/dsp_wup.c			\
                 $(DSP_DIR)/dsp_sus.c			\
                 $(DSP_DIR)/dsp_rsm.c			\
                 $(QUE_DIR)/add_que.c			\
                 $(QUE_DIR)/adf_que.c			\
                 $(QUE_DIR)/adp_que.c			\
                 $(QUE_DIR)/rmv_que.c			\
                 $(QUE_DIR)/rmh_que.c			\
                 $(QUE_DIR)/trm_que.c			\
                 $(QUE_DIR)/nxt_que.c			\
                 $(QUE_DIR)/rot_que.c			\
                 $(TOQ_DIR)/sig_toq.c			\
                 $(TOQ_DIR)/add_toq.c			\
                 $(TOQ_DIR)/rmv_toq.c			\
                 $(HEP_DIR)/cre_hep.c			\
                 $(HEP_DIR)/alc_hep.c			\
                 $(HEP_DIR)/fre_hep.c			\
                 $(SYSOBJ_DIR)/sta_knl.c		\
                 $(SYSOBJ_DIR)/get_tid.c		\
                 $(SYSOBJ_DIR)/loc_cpu.c		\
                 $(SYSOBJ_DIR)/unl_cpu.c		\
                 $(SYSOBJ_DIR)/sns_loc.c		\
                 $(SYSOBJ_DIR)/ena_dsp.c		\
                 $(SYSOBJ_DIR)/dis_dsp.c		\
                 $(SYSOBJ_DIR)/sns_dsp.c		\
                 $(SYSOBJ_DIR)/sns_ctx.c		\
                 $(TSKOBJ_DIR)/acre_tsk.c		\
                 $(TSKOBJ_DIR)/kcre_tsk.c		\
                 $(TSKOBJ_DIR)/act_tsk.c		\
                 $(TSKOBJ_DIR)/ext_tsk.c		\
                 $(TSKOBJ_DIR)/slp_tsk.c		\
                 $(TSKOBJ_DIR)/wup_tsk.c		\
                 $(TSKOBJ_DIR)/can_wup.c		\
                 $(TSKOBJ_DIR)/rel_wai.c		\
                 $(TSKOBJ_DIR)/dly_tsk.c		\
                 $(TSKOBJ_DIR)/ref_tsk.c		\
                 $(SEMOBJ_DIR)/cre_sem.c		\
                 $(SEMOBJ_DIR)/acre_sem.c		\
                 $(SEMOBJ_DIR)/kcre_sem.c		\
                 $(SEMOBJ_DIR)/del_sem.c		\
                 $(SEMOBJ_DIR)/sig_sem.c		\
                 $(SEMOBJ_DIR)/wai_sem.c		\
                 $(SEMOBJ_DIR)/pol_sem.c		\
                 $(SEMOBJ_DIR)/twai_sem.c		\
                 $(SEMOBJ_DIR)/ref_sem.c		\
                 $(FLGOBJ_DIR)/cre_flg.c		\
                 $(FLGOBJ_DIR)/acre_flg.c		\
                 $(FLGOBJ_DIR)/kcre_flg.c		\
                 $(FLGOBJ_DIR)/del_flg.c		\
                 $(FLGOBJ_DIR)/set_flg.c		\
                 $(FLGOBJ_DIR)/clr_flg.c		\
                 $(FLGOBJ_DIR)/wai_flg.c		\
                 $(FLGOBJ_DIR)/pol_flg.c		\
                 $(FLGOBJ_DIR)/twai_flg.c		\
                 $(FLGOBJ_DIR)/kchk_flg.c		\
                 $(FLGOBJ_DIR)/ref_flg.c		\
                 $(MBXOBJ_DIR)/acre_mbx.c		\
                 $(MBXOBJ_DIR)/kcre_mbx.c		\
                 $(MBXOBJ_DIR)/snd_mbx.c		\
                 $(MBXOBJ_DIR)/rcv_mbx.c		\
                 $(MBXOBJ_DIR)/kadf_msg.c		\
                 $(MBXOBJ_DIR)/kadp_msg.c		\
                 $(MBXOBJ_DIR)/kadd_msq.c		\
                 $(MBXOBJ_DIR)/krmf_msg.c		\
                 $(MBXOBJ_DIR)/krmp_msg.c		\
                 $(MBXOBJ_DIR)/krmv_msq.c		\
                 $(MPFOBJ_DIR)/acre_mpf.c		\
                 $(MPFOBJ_DIR)/kcre_mpf.c		\
                 $(MPFOBJ_DIR)/get_mpf.c		\
                 $(MPFOBJ_DIR)/pget_mpf.c		\
                 $(MPFOBJ_DIR)/rel_mpf.c		\
                 $(TIMOBJ_DIR)/set_tim.c		\
                 $(TIMOBJ_DIR)/get_tim.c		\
                 $(TIMOBJ_DIR)/isig_tim.c		\
                 $(INHOBJ_DIR)/def_inh.c		\
                 $(INHOBJ_DIR)/sta_inh.c		\
                 $(INHOBJ_DIR)/exe_inh.c		\
                 $(INHOBJ_DIR)/end_inh.c		\
                 $(ISROBJ_DIR)/acre_isr.c		\
                 $(ISROBJ_DIR)/kcre_isr.c		\
                 $(ISROBJ_DIR)/exe_isr.c


# Header files
ITRON_HEADERS  = $(INC_DIR)/itron.h				\
                 $(INC_DIR)/kernel.h

CFG_HEADERS    = $(INC_DIR)/parser/parssys.h	\
                 $(INC_DIR)/parser/parsknl.h	\
                 $(INC_DIR)/parser/parserr.h	\
                 $(INC_DIR)/parser/parshok.h

PARS_HEADERS   = $(INC_DIR)/config/cfgsys.h		\
                 $(INC_DIR)/config/cfgknl.h		\
                 $(INC_DIR)/config/cfgerr.h		\
                 $(INC_DIR)/config/cfghok.h

CORE_HEADERS   = $(INC_DIR)/core/adtq.h			\
                 $(INC_DIR)/core/basetyp.h		\
                 $(INC_DIR)/core/chkptr.h		\
                 $(INC_DIR)/core/cmpl.h			\
                 $(INC_DIR)/core/core.h			\
                 $(INC_DIR)/core/dsp.h			\
                 $(INC_DIR)/core/hep.h			\
                 $(INC_DIR)/core/objhdl.h		\
                 $(INC_DIR)/core/objid.h		\
                 $(INC_DIR)/core/opttyp.h		\
                 $(INC_DIR)/core/que.h			\
                 $(INC_DIR)/core/rdq.h			\
                 $(INC_DIR)/core/sys.h			\
                 $(INC_DIR)/core/tmq.h			\
                 $(INC_DIR)/core/toq.h

TSKOBJ_HEADERS = $(INC_DIR)/object/tskobj.h

SEMOBJ_HEADERS = $(INC_DIR)/object/semobj.h

FLGOBJ_HEADERS = $(INC_DIR)/object/flgobj.h

DTQOBJ_HEADERS = $(INC_DIR)/object/dtqobj.h

MBXOBJ_HEADERS = $(INC_DIR)/object/mbxobj.h

MPFOBJ_HEADERS = $(INC_DIR)/object/mpfobj.h

TIMOBJ_HEADERS = $(INC_DIR)/object/timobj.h

INHOBJ_HEADERS = $(INC_DIR)/object/inhobj.h

ISROBJ_HEADERS = $(INC_DIR)/object/isrobj.h


COMMON_HEADERS = $(ITRON_HEADERS) $(CFG_HEADERS) $(PARS_HEADERS) $(TSKOBJ_HEADERS)


# end of file
