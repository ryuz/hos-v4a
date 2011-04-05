# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for GNU make
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# Directories
KERNEL_SRC_DIR  = $(KERNEL_DIR)/source
KERNEL_INC_DIR  = $(KERNEL_DIR)/include
KERNEL_CORE_DIR = $(KERNEL_SRC_DIR)/core
KERNEL_OBJ_DIR  = $(KERNEL_SRC_DIR)/object



# Kernel include directorys
INC_DIRS += $(KERNEL_INC_DIR)


# Header files
ITRON_HEADERS  = $(KERNEL_INC_DIR)/itron.h				\
                 $(KERNEL_INC_DIR)/kernel.h

CFG_HEADERS    = $(KERNEL_INC_DIR)/parser/parssys.h		\
                 $(KERNEL_INC_DIR)/parser/parsknl.h		\
                 $(KERNEL_INC_DIR)/parser/parserr.h		\
                 $(KERNEL_INC_DIR)/parser/parshok.h

PARS_HEADERS   = $(KERNEL_INC_DIR)/config/cfgsys.h		\
                 $(KERNEL_INC_DIR)/config/cfgknl.h		\
                 $(KERNEL_INC_DIR)/config/cfgerr.h		\
                 $(KERNEL_INC_DIR)/config/cfghok.h

CORE_HEADERS   = $(KERNEL_INC_DIR)/core/adtq.h			\
                 $(KERNEL_INC_DIR)/core/basetyp.h		\
                 $(KERNEL_INC_DIR)/core/chkptr.h		\
                 $(KERNEL_INC_DIR)/core/cmpl.h			\
                 $(KERNEL_INC_DIR)/core/core.h			\
                 $(KERNEL_INC_DIR)/core/dsp.h			\
                 $(KERNEL_INC_DIR)/core/hep.h			\
                 $(KERNEL_INC_DIR)/core/objhdl.h		\
                 $(KERNEL_INC_DIR)/core/objid.h			\
                 $(KERNEL_INC_DIR)/core/que.h			\
                 $(KERNEL_INC_DIR)/core/rdq.h			\
                 $(KERNEL_INC_DIR)/core/sys.h			\
                 $(KERNEL_INC_DIR)/core/tmq.h			\
                 $(KERNEL_INC_DIR)/core/toq.h			\
                 $(KERNEL_INC_DIR)/core/dpc.h

ARCH_HEADERS   = $(INC_PROC_DIR)/proc.h					\
                 $(INC_PROC_DIR)/procatr.h				\
                 $(INC_IRC_DIR)/irc.h					\
                 $(INC_IRC_DIR)/ircatr.h

TSKOBJ_HEADERS = $(KERNEL_INC_DIR)/object/tskobj.h

SEMOBJ_HEADERS = $(KERNEL_INC_DIR)/object/semobj.h

FLGOBJ_HEADERS = $(KERNEL_INC_DIR)/object/flgobj.h

DTQOBJ_HEADERS = $(KERNEL_INC_DIR)/object/dtqobj.h

MBXOBJ_HEADERS = $(KERNEL_INC_DIR)/object/mbxobj.h

MTXOBJ_HEADERS = $(KERNEL_INC_DIR)/object/mtxobj.h

MPFOBJ_HEADERS = $(KERNEL_INC_DIR)/object/mpfobj.h

CYCOBJ_HEADERS = $(KERNEL_INC_DIR)/object/cycobj.h

INHOBJ_HEADERS = $(KERNEL_INC_DIR)/object/inhobj.h

ISROBJ_HEADERS = $(KERNEL_INC_DIR)/object/isrobj.h

COMMON_HEADERS = $(ITRON_HEADERS)		\
                 $(CFG_HEADERS)			\
                 $(PARS_HEADERS)		\
                 $(CORE_HEADERS)		\
                 $(ARCH_HEADERS)		\
                 $(TSKOBJ_HEADERS)		\



# Dispatcher
DSP_DIR = $(KERNEL_CORE_DIR)/dsp
SRC_DIRS += $(DSP_DIR)
CSRCS += $(DSP_DIR)/ent_tsk.c
CSRCS += $(DSP_DIR)/idl_lop.c
CSRCS += $(DSP_DIR)/dsp_tsk.c
CSRCS += $(DSP_DIR)/dsp_sta.c
CSRCS += $(DSP_DIR)/dsp_ext.c
CSRCS += $(DSP_DIR)/dsp_ter.c
CSRCS += $(DSP_DIR)/dsp_wai.c
CSRCS += $(DSP_DIR)/dsp_wup.c
CSRCS += $(DSP_DIR)/dsp_sus.c
CSRCS += $(DSP_DIR)/dsp_rsm.c


# Task-queue
QUE_DIR = $(KERNEL_CORE_DIR)/que
SRC_DIRS += $(QUE_DIR)
CSRCS += $(QUE_DIR)/add_que.c
CSRCS += $(QUE_DIR)/adf_que.c
CSRCS += $(QUE_DIR)/adp_que.c
CSRCS += $(QUE_DIR)/rmv_que.c
CSRCS += $(QUE_DIR)/rmh_que.c
CSRCS += $(QUE_DIR)/trm_que.c
CSRCS += $(QUE_DIR)/nxt_que.c
CSRCS += $(QUE_DIR)/rot_que.c


# Ready-queue
RDQ_DIR = $(KERNEL_CORE_DIR)/rdq
SRC_DIRS += $(RDQ_DIR)
CSRCS += $(RDQ_DIR)/cre_rdq.c
CSRCS += $(RDQ_DIR)/del_rdq.c
CSRCS += $(RDQ_DIR)/add_rdq.c
CSRCS += $(RDQ_DIR)/rmv_rdq.c
CSRCS += $(RDQ_DIR)/rmh_rdq.c
CSRCS += $(RDQ_DIR)/ref_rdq.c


# Time management
TIM_DIR = $(KERNEL_CORE_DIR)/tim
SRC_DIRS += $(TIM_DIR)
CSRCS += $(TIM_DIR)/sig_tim.c


# Timeout-queue
TOQ_DIR = $(KERNEL_CORE_DIR)/toq
SRC_DIRS += $(TOQ_DIR)
CSRCS += $(TOQ_DIR)/sig_toq.c
CSRCS += $(TOQ_DIR)/add_toq.c
CSRCS += $(TOQ_DIR)/rmv_toq.c


# Timer-queue
TMQ_DIR = $(KERNEL_CORE_DIR)/tmq
SRC_DIRS += $(TMQ_DIR)
CSRCS += $(TMQ_DIR)/sig_tmq.c
CSRCS += $(TMQ_DIR)/add_tmq.c
CSRCS += $(TMQ_DIR)/rmv_tmq.c


# Memory-heap
HEP_DIR = $(KERNEL_CORE_DIR)/hep
SRC_DIRS += $(HEP_DIR)
CSRCS += $(HEP_DIR)/cre_hep.c
CSRCS += $(HEP_DIR)/alc_hep.c
CSRCS += $(HEP_DIR)/fre_hep.c


# Deferrable procedure call
DPC_DIR = $(KERNEL_CORE_DIR)/dpc
SRC_DIRS += $(DPC_DIR)
CSRCS += $(DPC_DIR)/ini_dpc.c
CSRCS += $(DPC_DIR)/req_dpc.c
CSRCS += $(DPC_DIR)/exe_dpc.c


# Asyncronous data-queue
ADTQ_DIR = $(KERNEL_CORE_DIR)/adtq
SRC_DIRS += $(ADTQ_DIR)
CSRCS += $(ADTQ_DIR)/frcv_adq.c
CSRCS += $(ADTQ_DIR)/fsnd_adq.c
CSRCS += $(ADTQ_DIR)/rcv_adq.c
CSRCS += $(ADTQ_DIR)/reff_adq.c
CSRCS += $(ADTQ_DIR)/refs_adq.c
CSRCS += $(ADTQ_DIR)/snd_adq.c


# System
SYSOBJ_DIR = $(KERNEL_OBJ_DIR)/sys
SRC_DIRS += $(SYSOBJ_DIR)
CSRCS += $(SYSOBJ_DIR)/sta_knl.c
CSRCS += $(SYSOBJ_DIR)/get_tid.c
CSRCS += $(SYSOBJ_DIR)/loc_cpu.c
CSRCS += $(SYSOBJ_DIR)/unl_cpu.c
CSRCS += $(SYSOBJ_DIR)/sns_loc.c
CSRCS += $(SYSOBJ_DIR)/ena_dsp.c
CSRCS += $(SYSOBJ_DIR)/dis_dsp.c
CSRCS += $(SYSOBJ_DIR)/sns_dsp.c
CSRCS += $(SYSOBJ_DIR)/sns_ctx.c
CSRCS += $(SYSOBJ_DIR)/exe_exc.c


# Tasks
TSKOBJ_DIR = $(KERNEL_OBJ_DIR)/tsk
SRC_DIRS += $(TSKOBJ_DIR)
CSRCS += $(TSKOBJ_DIR)/cre_tsk.c
CSRCS += $(TSKOBJ_DIR)/acre_tsk.c
CSRCS += $(TSKOBJ_DIR)/kcre_tsk.c
CSRCS += $(TSKOBJ_DIR)/del_tsk.c
CSRCS += $(TSKOBJ_DIR)/act_tsk.c
CSRCS += $(TSKOBJ_DIR)/iact_tsk.c
CSRCS += $(TSKOBJ_DIR)/can_act.c
CSRCS += $(TSKOBJ_DIR)/ext_tsk.c
CSRCS += $(TSKOBJ_DIR)/exd_tsk.c
CSRCS += $(TSKOBJ_DIR)/ter_tsk.c
CSRCS += $(TSKOBJ_DIR)/chg_pri.c
CSRCS += $(TSKOBJ_DIR)/kchg_pri.c
CSRCS += $(TSKOBJ_DIR)/get_pri.c
CSRCS += $(TSKOBJ_DIR)/ref_tsk.c
CSRCS += $(TSKOBJ_DIR)/ref_tst.c
CSRCS += $(TSKOBJ_DIR)/slp_tsk.c
CSRCS += $(TSKOBJ_DIR)/wup_tsk.c
CSRCS += $(TSKOBJ_DIR)/iwup_tsk.c
CSRCS += $(TSKOBJ_DIR)/can_wup.c
CSRCS += $(TSKOBJ_DIR)/rel_wai.c
CSRCS += $(TSKOBJ_DIR)/irel_wai.c
CSRCS += $(TSKOBJ_DIR)/sus_tsk.c
CSRCS += $(TSKOBJ_DIR)/rsm_tsk.c
CSRCS += $(TSKOBJ_DIR)/frsm_tsk.c
CSRCS += $(TSKOBJ_DIR)/dly_tsk.c
CSRCS += $(TSKOBJ_DIR)/def_tex.c
CSRCS += $(TSKOBJ_DIR)/ras_tex.c
CSRCS += $(TSKOBJ_DIR)/ena_tex.c
CSRCS += $(TSKOBJ_DIR)/kexe_tex.c
CSRCS += $(TSKOBJ_DIR)/tcb2id.c


# Semaphores
SEMOBJ_DIR = $(KERNEL_OBJ_DIR)/sem
SRC_DIRS += $(SEMOBJ_DIR)
CSRCS += $(SEMOBJ_DIR)/cre_sem.c
CSRCS += $(SEMOBJ_DIR)/acre_sem.c
CSRCS += $(SEMOBJ_DIR)/kcre_sem.c
CSRCS += $(SEMOBJ_DIR)/del_sem.c
CSRCS += $(SEMOBJ_DIR)/sig_sem.c
CSRCS += $(SEMOBJ_DIR)/isig_sem.c
CSRCS += $(SEMOBJ_DIR)/wai_sem.c
CSRCS += $(SEMOBJ_DIR)/pol_sem.c
CSRCS += $(SEMOBJ_DIR)/twai_sem.c
CSRCS += $(SEMOBJ_DIR)/ref_sem.c


# Event-flags
FLGOBJ_DIR = $(KERNEL_OBJ_DIR)/flg
SRC_DIRS += $(FLGOBJ_DIR)
CSRCS += $(FLGOBJ_DIR)/cre_flg.c
CSRCS += $(FLGOBJ_DIR)/acre_flg.c
CSRCS += $(FLGOBJ_DIR)/kcre_flg.c
CSRCS += $(FLGOBJ_DIR)/del_flg.c
CSRCS += $(FLGOBJ_DIR)/set_flg.c
CSRCS += $(FLGOBJ_DIR)/iset_flg.c
CSRCS += $(FLGOBJ_DIR)/clr_flg.c
CSRCS += $(FLGOBJ_DIR)/wai_flg.c
CSRCS += $(FLGOBJ_DIR)/pol_flg.c
CSRCS += $(FLGOBJ_DIR)/twai_flg.c
CSRCS += $(FLGOBJ_DIR)/kchk_flg.c
CSRCS += $(FLGOBJ_DIR)/ref_flg.c


# Data queues
DTQOBJ_DIR = $(KERNEL_OBJ_DIR)/dtq
SRC_DIRS += $(DTQOBJ_DIR)
CSRCS += $(DTQOBJ_DIR)/cre_dtq.c
CSRCS += $(DTQOBJ_DIR)/acre_dtq.c
CSRCS += $(DTQOBJ_DIR)/kcre_dtq.c
CSRCS += $(DTQOBJ_DIR)/del_dtq.c
CSRCS += $(DTQOBJ_DIR)/snd_dtq.c
CSRCS += $(DTQOBJ_DIR)/fsnd_dtq.c
CSRCS += $(DTQOBJ_DIR)/rcv_dtq.c
CSRCS += $(DTQOBJ_DIR)/prcv_dtq.c
CSRCS += $(DTQOBJ_DIR)/trcv_dtq.c


# Mailboxes
MBXOBJ_DIR = $(KERNEL_OBJ_DIR)/mbx
SRC_DIRS += $(MBXOBJ_DIR)
CSRCS += $(MBXOBJ_DIR)/acre_mbx.c
CSRCS += $(MBXOBJ_DIR)/kcre_mbx.c
CSRCS += $(MBXOBJ_DIR)/snd_mbx.c
CSRCS += $(MBXOBJ_DIR)/rcv_mbx.c
CSRCS += $(MBXOBJ_DIR)/kadf_msg.c
CSRCS += $(MBXOBJ_DIR)/kadp_msg.c
CSRCS += $(MBXOBJ_DIR)/kadd_msq.c
CSRCS += $(MBXOBJ_DIR)/krmf_msg.c
CSRCS += $(MBXOBJ_DIR)/krmp_msg.c
CSRCS += $(MBXOBJ_DIR)/krmv_msq.c


# Mutexes
MTXOBJ_DIR = $(KERNEL_OBJ_DIR)/mtx
SRC_DIRS += $(MTXOBJ_DIR)
CSRCS += $(MTXOBJ_DIR)/cre_mtx.c
CSRCS += $(MTXOBJ_DIR)/acre_mtx.c
CSRCS += $(MTXOBJ_DIR)/kcre_mtx.c
CSRCS += $(MTXOBJ_DIR)/del_mtx.c
CSRCS += $(MTXOBJ_DIR)/loc_mtx.c
CSRCS += $(MTXOBJ_DIR)/ploc_mtx.c
CSRCS += $(MTXOBJ_DIR)/tloc_mtx.c
CSRCS += $(MTXOBJ_DIR)/unl_mtx.c
CSRCS += $(MTXOBJ_DIR)/kadd_mtx.c
CSRCS += $(MTXOBJ_DIR)/krmv_mtx.c


# Fixed-sized Memory Pools
MPFOBJ_DIR = $(KERNEL_OBJ_DIR)/mpf
SRC_DIRS += $(MPFOBJ_DIR)
CSRCS += $(MPFOBJ_DIR)/acre_mpf.c
CSRCS += $(MPFOBJ_DIR)/kcre_mpf.c
CSRCS += $(MPFOBJ_DIR)/get_mpf.c
CSRCS += $(MPFOBJ_DIR)/pget_mpf.c
CSRCS += $(MPFOBJ_DIR)/rel_mpf.c


# System Time Management
TIMOBJ_DIR = $(KERNEL_OBJ_DIR)/tim
SRC_DIRS += $(TIMOBJ_DIR)
CSRCS += $(TIMOBJ_DIR)/set_tim.c
CSRCS += $(TIMOBJ_DIR)/get_tim.c
CSRCS += $(TIMOBJ_DIR)/isig_tim.c


# Cyclic Handlers
CYCOBJ_DIR = $(KERNEL_OBJ_DIR)/cyc
SRC_DIRS += $(CYCOBJ_DIR)
CSRCS += $(CYCOBJ_DIR)/cre_cyc.c
CSRCS += $(CYCOBJ_DIR)/acre_cyc.c
CSRCS += $(CYCOBJ_DIR)/kcre_cyc.c
CSRCS += $(CYCOBJ_DIR)/del_cyc.c
CSRCS += $(CYCOBJ_DIR)/sta_cyc.c
CSRCS += $(CYCOBJ_DIR)/stp_cyc.c
CSRCS += $(CYCOBJ_DIR)/ref_cyc.c
CSRCS += $(CYCOBJ_DIR)/kcyc_hdr.c


# Interrupt handlers
INHOBJ_DIR = $(KERNEL_OBJ_DIR)/inh
SRC_DIRS += $(INHOBJ_DIR)
CSRCS += $(INHOBJ_DIR)/def_inh.c
CSRCS += $(INHOBJ_DIR)/sta_inh.c
CSRCS += $(INHOBJ_DIR)/exe_inh.c
CSRCS += $(INHOBJ_DIR)/end_inh.c


# Interrupt Service Routines
ISROBJ_DIR = $(KERNEL_OBJ_DIR)/isr
SRC_DIRS += $(ISROBJ_DIR)
CSRCS += $(ISROBJ_DIR)/acre_isr.c
CSRCS += $(ISROBJ_DIR)/kcre_isr.c
CSRCS += $(ISROBJ_DIR)/del_isr.c
CSRCS += $(ISROBJ_DIR)/exe_isr.c



# end of file
