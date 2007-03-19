# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# Directories
SRC_DIR     = $(KERNEL_DIR)/source
INC_DIR     = $(KERNEL_DIR)/include
CORE_DIR    = $(SRC_DIR)/core
OBJ_DIR     = $(SRC_DIR)/object


# Kernel include directorys
INC_DIRS   += $(INC_DIR)



# Kernel header files
ITRON_HDRS  = $(INC_DIR)/itron.h			\
              $(INC_DIR)/kernel.h

# configulation header files
CFG_HDRS    = $(INC_DIR)/parser/parssys.h	\
              $(INC_DIR)/parser/parsknl.h	\
              $(INC_DIR)/parser/parserr.h	\
              $(INC_DIR)/parser/parshok.h

# Parser header files
PARS_HDRS   = $(INC_DIR)/config/cfgsys.h	\
              $(INC_DIR)/config/cfgknl.h	\
              $(INC_DIR)/config/cfgerr.h	\
              $(INC_DIR)/config/cfghok.h

# Core header files
CORE_HDRS   = $(INC_DIR)/core/adtq.h		\
              $(INC_DIR)/core/basetyp.h		\
              $(INC_DIR)/core/chkptr.h		\
              $(INC_DIR)/core/cmpl.h		\
              $(INC_DIR)/core/core.h		\
              $(INC_DIR)/core/dsp.h			\
              $(INC_DIR)/core/hep.h			\
              $(INC_DIR)/core/objhdl.h		\
              $(INC_DIR)/core/objid.h		\
              $(INC_DIR)/core/que.h			\
              $(INC_DIR)/core/rdq.h			\
              $(INC_DIR)/core/sys.h			\
              $(INC_DIR)/core/tmq.h			\
              $(INC_DIR)/core/toq.h			\
              $(INC_DIR)/core/dpc.h

# Architecture header files
ARCH_HDRS   = $(INC_PROC_DIR)/proc.h		\
              $(INC_PROC_DIR)/procatr.h		\
              $(INC_IRC_DIR)/irc.h			\
              $(INC_IRC_DIR)/ircatr.h

# Common header files
COMMON_HDRS = $(ITRON_HDRS)					\
              $(CFG_HDRS)					\
              $(PARS_HDRS)					\
              $(CORE_HDRS)					\
              $(ARCH_HDRS)					\
              $(TSKOBJ_HDRS)



# Dispatcher
DSP_DIR     = $(CORE_DIR)/dsp
SRC_DIRS   += $(DSP_DIR)
CSRCS      += $(DSP_DIR)/ent_tsk.c			\
              $(DSP_DIR)/idl_lop.c			\
              $(DSP_DIR)/dsp_tsk.c			\
              $(DSP_DIR)/dsp_sta.c			\
              $(DSP_DIR)/dsp_ext.c			\
              $(DSP_DIR)/dsp_ter.c			\
              $(DSP_DIR)/dsp_wai.c			\
              $(DSP_DIR)/dsp_wup.c			\
              $(DSP_DIR)/dsp_sus.c			\
              $(DSP_DIR)/dsp_rsm.c



# Task-queue
QUE_DIR     = $(CORE_DIR)/que
SRC_DIRS   += $(QUE_DIR)
CSRCS      += $(QUE_DIR)/add_que.c			\
              $(QUE_DIR)/adf_que.c			\
              $(QUE_DIR)/adp_que.c			\
              $(QUE_DIR)/rmv_que.c			\
              $(QUE_DIR)/rmh_que.c			\
              $(QUE_DIR)/trm_que.c			\
              $(QUE_DIR)/nxt_que.c			\
              $(QUE_DIR)/rot_que.c


# Time management
TIM_DIR     = $(CORE_DIR)/tim
SRC_DIRS   += $(TIM_DIR) 
CSRCS      += $(TIM_DIR)/sig_tim.c


# Timeout-queue
TOQ_DIR     = $(CORE_DIR)/toq
SRC_DIRS   += $(TOQ_DIR) 
CSRCS      += $(TOQ_DIR)/sig_toq.c			\
              $(TOQ_DIR)/add_toq.c			\
              $(TOQ_DIR)/rmv_toq.c


# Timer-queue
TMQ_DIR     = $(CORE_DIR)/tmq
SRC_DIRS   += $(TMQ_DIR) 
CSRCS      += $(TMQ_DIR)/sig_tmq.c			\
              $(TMQ_DIR)/add_tmq.c			\
              $(TMQ_DIR)/rmv_tmq.c


# Memory-heap
HEP_DIR     = $(CORE_DIR)/hep
SRC_DIRS   += $(HEP_DIR)
CSRCS      += $(HEP_DIR)/cre_hep.c			\
              $(HEP_DIR)/alc_hep.c			\
              $(HEP_DIR)/fre_hep.c


# Deferrable procedure call
DPC_DIR     = $(CORE_DIR)/dpc
SRC_DIRS   += $(DPC_DIR)
CSRCS      += $(DPC_DIR)/exe_dpc.c


# Asyncronous data-queue
ADTQ_DIR    = $(CORE_DIR)/adtq
SRC_DIRS   += $(ADTQ_DIR)
CSRCS      += $(ADTQ_DIR)/frcv_adq.c		\
              $(ADTQ_DIR)/fsnd_adq.c		\
              $(ADTQ_DIR)/rcv_adq.c			\
              $(ADTQ_DIR)/reff_adq.c		\
              $(ADTQ_DIR)/refs_adq.c		\
              $(ADTQ_DIR)/snd_adq.c



# System
SYSOBJ_DIR  = $(OBJ_DIR)/sys
SRC_DIRS   += $(SYSOBJ_DIR)
CSRCS      += $(SYSOBJ_DIR)/sta_knl.c		\
              $(SYSOBJ_DIR)/get_tid.c		\
              $(SYSOBJ_DIR)/loc_cpu.c		\
              $(SYSOBJ_DIR)/unl_cpu.c		\
              $(SYSOBJ_DIR)/sns_loc.c		\
              $(SYSOBJ_DIR)/ena_dsp.c		\
              $(SYSOBJ_DIR)/dis_dsp.c		\
              $(SYSOBJ_DIR)/sns_dsp.c		\
              $(SYSOBJ_DIR)/sns_ctx.c


# Tasks
TSKOBJ_DIR  = $(OBJ_DIR)/tsk
SRC_DIRS   += $(TSKOBJ_DIR)
TSKOBJ_HDRS = $(INC_DIR)/object/tskobj.h
CSRCS      += $(TSKOBJ_DIR)/acre_tsk.c		\
              $(TSKOBJ_DIR)/kcre_tsk.c		\
              $(TSKOBJ_DIR)/act_tsk.c		\
              $(TSKOBJ_DIR)/ext_tsk.c		\
              $(TSKOBJ_DIR)/slp_tsk.c		\
              $(TSKOBJ_DIR)/wup_tsk.c		\
              $(TSKOBJ_DIR)/can_wup.c		\
              $(TSKOBJ_DIR)/rel_wai.c		\
              $(TSKOBJ_DIR)/dly_tsk.c		\
              $(TSKOBJ_DIR)/ref_tsk.c


# Semaphores
SEMOBJ_DIR  = $(OBJ_DIR)/sem
SEMOBJ_HDRS = $(INC_DIR)/object/semobj.h
SRC_DIRS   += $(SEMOBJ_DIR)
CSRCS      += $(SEMOBJ_DIR)/cre_sem.c		\
              $(SEMOBJ_DIR)/acre_sem.c		\
              $(SEMOBJ_DIR)/kcre_sem.c		\
              $(SEMOBJ_DIR)/del_sem.c		\
              $(SEMOBJ_DIR)/sig_sem.c		\
              $(SEMOBJ_DIR)/isig_sem.c		\
              $(SEMOBJ_DIR)/wai_sem.c		\
              $(SEMOBJ_DIR)/pol_sem.c		\
              $(SEMOBJ_DIR)/twai_sem.c		\
              $(SEMOBJ_DIR)/ref_sem.c


# Event-flags
FLGOBJ_DIR  = $(OBJ_DIR)/flg
FLGOBJ_HDRS = $(INC_DIR)/object/flgobj.h
SRC_DIRS   += $(FLGOBJ_DIR)
CSRCS      += $(FLGOBJ_DIR)/cre_flg.c		\
              $(FLGOBJ_DIR)/acre_flg.c		\
              $(FLGOBJ_DIR)/kcre_flg.c		\
              $(FLGOBJ_DIR)/del_flg.c		\
              $(FLGOBJ_DIR)/set_flg.c		\
              $(FLGOBJ_DIR)/iset_flg.c		\
              $(FLGOBJ_DIR)/clr_flg.c		\
              $(FLGOBJ_DIR)/wai_flg.c		\
              $(FLGOBJ_DIR)/pol_flg.c		\
              $(FLGOBJ_DIR)/twai_flg.c		\
              $(FLGOBJ_DIR)/kchk_flg.c		\
              $(FLGOBJ_DIR)/ref_flg.c


# Data queues
DTQOBJ_DIR  = $(OBJ_DIR)/dtq
DTQOBJ_HDRS = $(INC_DIR)/object/dtqobj.h
SRC_DIRS   += $(DTQOBJ_DIR)
CSRCS      += $(DTQOBJ_DIR)/cre_dtq.c		\
              $(DTQOBJ_DIR)/acre_dtq.c		\
              $(DTQOBJ_DIR)/kcre_dtq.c		\
              $(DTQOBJ_DIR)/snd_dtq.c		\
              $(DTQOBJ_DIR)/fsnd_dtq.c		\
              $(DTQOBJ_DIR)/rcv_dtq.c		\
              $(DTQOBJ_DIR)/prcv_dtq.c		\
              $(DTQOBJ_DIR)/trcv_dtq.c


# Mailboxes
MBXOBJ_DIR  = $(OBJ_DIR)/mbx
MBXOBJ_HDRS = $(INC_DIR)/object/mbxobj.h
SRC_DIRS   += $(MBXOBJ_DIR)
CSRCS      += $(MBXOBJ_DIR)/acre_mbx.c		\
              $(MBXOBJ_DIR)/kcre_mbx.c		\
              $(MBXOBJ_DIR)/snd_mbx.c		\
              $(MBXOBJ_DIR)/rcv_mbx.c		\
              $(MBXOBJ_DIR)/kadf_msg.c		\
              $(MBXOBJ_DIR)/kadp_msg.c		\
              $(MBXOBJ_DIR)/kadd_msq.c		\
              $(MBXOBJ_DIR)/krmf_msg.c		\
              $(MBXOBJ_DIR)/krmp_msg.c		\
              $(MBXOBJ_DIR)/krmv_msq.c


# Fixed-sized Memory Pools
MPFOBJ_DIR  = $(OBJ_DIR)/mpf
MPFOBJ_HDRS = $(INC_DIR)/object/mpfobj.h
SRC_DIRS   += $(MPFOBJ_DIR)
CSRCS      += $(MPFOBJ_DIR)/acre_mpf.c		\
              $(MPFOBJ_DIR)/kcre_mpf.c		\
              $(MPFOBJ_DIR)/get_mpf.c		\
              $(MPFOBJ_DIR)/pget_mpf.c		\
              $(MPFOBJ_DIR)/rel_mpf.c


# System Time Management
TIMOBJ_DIR  = $(OBJ_DIR)/tim
TIMOBJ_HDRS = 
SRC_DIRS   += $(TIMOBJ_DIR)
CSRCS      += $(TIMOBJ_DIR)/set_tim.c		\
              $(TIMOBJ_DIR)/get_tim.c		\
              $(TIMOBJ_DIR)/isig_tim.c		\


# Interrupt handlers
INHOBJ_DIR  = $(OBJ_DIR)/inh
INHOBJ_HDRS = $(INC_DIR)/object/inhobj.h
SRC_DIRS   += $(INHOBJ_DIR)
CSRCS      += $(INHOBJ_DIR)/def_inh.c		\
              $(INHOBJ_DIR)/sta_inh.c		\
              $(INHOBJ_DIR)/exe_inh.c		\
              $(INHOBJ_DIR)/end_inh.c


# Interrupt Service Routines
ISROBJ_DIR  = $(OBJ_DIR)/isr
ISROBJ_HDRS = $(INC_DIR)/object/isrobj.h
SRC_DIRS   += $(ISROBJ_DIR)
CSRCS      += $(ISROBJ_DIR)/acre_isr.c		\
              $(ISROBJ_DIR)/kcre_isr.c		\
              $(ISROBJ_DIR)/exe_isr.c




# end of file
