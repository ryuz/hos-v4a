# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for nmake
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# Directories
KERNEL_SRC_DIR  = $(KERNEL_DIR)\source
KERNEL_INC_DIR  = $(KERNEL_DIR)\include
KERNEL_CORE_DIR = $(KERNEL_SRC_DIR)\core
KERNEL_OBJ_DIR  = $(KERNEL_SRC_DIR)\object



# Kernel include directorys
INC_DIRS = $(INC_DIRS) $(KERNEL_INC_DIR)


# Header files
ITRON_HEADERS  = $(KERNEL_INC_DIR)\itron.h				\
                 $(KERNEL_INC_DIR)\kernel.h

CFG_HEADERS    = $(KERNEL_INC_DIR)\parser\parssys.h		\
                 $(KERNEL_INC_DIR)\parser\parsknl.h		\
                 $(KERNEL_INC_DIR)\parser\parserr.h		\
                 $(KERNEL_INC_DIR)\parser\parshok.h

PARS_HEADERS   = $(KERNEL_INC_DIR)\config\cfgsys.h		\
                 $(KERNEL_INC_DIR)\config\cfgknl.h		\
                 $(KERNEL_INC_DIR)\config\cfgerr.h		\
                 $(KERNEL_INC_DIR)\config\cfghok.h

CORE_HEADERS   = $(KERNEL_INC_DIR)\core\adtq.h			\
                 $(KERNEL_INC_DIR)\core\basetyp.h		\
                 $(KERNEL_INC_DIR)\core\chkptr.h		\
                 $(KERNEL_INC_DIR)\core\cmpl.h			\
                 $(KERNEL_INC_DIR)\core\core.h			\
                 $(KERNEL_INC_DIR)\core\dsp.h			\
                 $(KERNEL_INC_DIR)\core\hep.h			\
                 $(KERNEL_INC_DIR)\core\objhdl.h		\
                 $(KERNEL_INC_DIR)\core\objid.h			\
                 $(KERNEL_INC_DIR)\core\que.h			\
                 $(KERNEL_INC_DIR)\core\rdq.h			\
                 $(KERNEL_INC_DIR)\core\sys.h			\
                 $(KERNEL_INC_DIR)\core\tmq.h			\
                 $(KERNEL_INC_DIR)\core\toq.h			\
                 $(KERNEL_INC_DIR)\core\dpc.h

ARCH_HEADERS   = $(INC_PROC_DIR)\proc.h					\
                 $(INC_PROC_DIR)\procatr.h				\
                 $(INC_IRC_DIR)\irc.h					\
                 $(INC_IRC_DIR)\ircatr.h

TSKOBJ_HEADERS = $(KERNEL_INC_DIR)\object\tskobj.h

SEMOBJ_HEADERS = $(KERNEL_INC_DIR)\object\semobj.h

FLGOBJ_HEADERS = $(KERNEL_INC_DIR)\object\flgobj.h

DTQOBJ_HEADERS = $(KERNEL_INC_DIR)\object\dtqobj.h

MBXOBJ_HEADERS = $(KERNEL_INC_DIR)\object\mbxobj.h

MTXOBJ_HEADERS = $(KERNEL_INC_DIR)\object\mtxobj.h

MPFOBJ_HEADERS = $(KERNEL_INC_DIR)\object\mpfobj.h

CYCOBJ_HEADERS = $(KERNEL_INC_DIR)\object\cycobj.h

INHOBJ_HEADERS = $(KERNEL_INC_DIR)\object\inhobj.h

ISROBJ_HEADERS = $(KERNEL_INC_DIR)\object\isrobj.h

COMMON_HEADERS = $(ITRON_HEADERS)		\
                 $(CFG_HEADERS)			\
                 $(PARS_HEADERS)		\
                 $(CORE_HEADERS)		\
                 $(ARCH_HEADERS)		\
                 $(TSKOBJ_HEADERS)		\



# Dispatcher
DSP_DIR = $(KERNEL_CORE_DIR)\dsp
CSRCS = $(CSRCS) $(DSP_DIR)\ent_tsk.c
CSRCS = $(CSRCS) $(DSP_DIR)\idl_lop.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_tsk.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_sta.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_ext.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_ter.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_wai.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_wup.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_sus.c
CSRCS = $(CSRCS) $(DSP_DIR)\dsp_rsm.c
OBJS = $(OBJS) $(OBJS_DIR)\ent_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\idl_lop.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_sta.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_ext.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_ter.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_wai.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_wup.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_sus.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dsp_rsm.$(EXT_OBJ)


# Task-queue
QUE_DIR = $(KERNEL_CORE_DIR)\que
CSRCS = $(CSRCS) $(QUE_DIR)\add_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\adf_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\adp_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\rmv_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\rmh_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\trm_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\nxt_que.c
CSRCS = $(CSRCS) $(QUE_DIR)\rot_que.c
OBJS = $(OBJS) $(OBJS_DIR)\add_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\adf_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\adp_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmh_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\trm_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\nxt_que.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rot_que.$(EXT_OBJ)


# Ready-queue
RDQ_DIR = $(KERNEL_CORE_DIR)\rdq
CSRCS = $(CSRCS) $(RDQ_DIR)\cre_rdq.c
CSRCS = $(CSRCS) $(RDQ_DIR)\del_rdq.c
CSRCS = $(CSRCS) $(RDQ_DIR)\add_rdq.c
CSRCS = $(CSRCS) $(RDQ_DIR)\rmv_rdq.c
CSRCS = $(CSRCS) $(RDQ_DIR)\rmh_rdq.c
CSRCS = $(CSRCS) $(RDQ_DIR)\ref_rdq.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmh_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_rdq.$(EXT_OBJ)


# Time management
TIM_DIR = $(KERNEL_CORE_DIR)\tim
CSRCS = $(CSRCS) $(TIM_DIR)\sig_tim.c
OBJS = $(OBJS) $(OBJS_DIR)\sig_tim.$(EXT_OBJ)


# Timeout-queue
TOQ_DIR = $(KERNEL_CORE_DIR)\toq
CSRCS = $(CSRCS) $(TOQ_DIR)\sig_toq.c
CSRCS = $(CSRCS) $(TOQ_DIR)\add_toq.c
CSRCS = $(CSRCS) $(TOQ_DIR)\rmv_toq.c
OBJS = $(OBJS) $(OBJS_DIR)\sig_toq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_toq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_toq.$(EXT_OBJ)


# Timer-queue
TMQ_DIR = $(KERNEL_CORE_DIR)\tmq
CSRCS = $(CSRCS) $(TMQ_DIR)\sig_tmq.c
CSRCS = $(CSRCS) $(TMQ_DIR)\add_tmq.c
CSRCS = $(CSRCS) $(TMQ_DIR)\rmv_tmq.c
OBJS = $(OBJS) $(OBJS_DIR)\sig_tmq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_tmq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_tmq.$(EXT_OBJ)


# Memory-heap
HEP_DIR = $(KERNEL_CORE_DIR)\hep
CSRCS = $(CSRCS) $(HEP_DIR)\cre_hep.c
CSRCS = $(CSRCS) $(HEP_DIR)\alc_hep.c
CSRCS = $(CSRCS) $(HEP_DIR)\fre_hep.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_hep.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\alc_hep.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fre_hep.$(EXT_OBJ)


# Deferrable procedure call
DPC_DIR = $(KERNEL_CORE_DIR)\dpc
CSRCS = $(CSRCS) $(DPC_DIR)\ini_dpc.c
CSRCS = $(CSRCS) $(DPC_DIR)\req_dpc.c
CSRCS = $(CSRCS) $(DPC_DIR)\exe_dpc.c
OBJS = $(OBJS) $(OBJS_DIR)\ini_dpc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\req_dpc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_dpc.$(EXT_OBJ)


# Asyncronous data-queue
ADTQ_DIR = $(KERNEL_CORE_DIR)\adtq
CSRCS = $(CSRCS) $(ADTQ_DIR)\frcv_adq.c
CSRCS = $(CSRCS) $(ADTQ_DIR)\fsnd_adq.c
CSRCS = $(CSRCS) $(ADTQ_DIR)\rcv_adq.c
CSRCS = $(CSRCS) $(ADTQ_DIR)\reff_adq.c
CSRCS = $(CSRCS) $(ADTQ_DIR)\refs_adq.c
CSRCS = $(CSRCS) $(ADTQ_DIR)\snd_adq.c
OBJS = $(OBJS) $(OBJS_DIR)\frcv_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fsnd_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rcv_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\reff_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\refs_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\snd_adq.$(EXT_OBJ)


# System
SYSOBJ_DIR = $(KERNEL_OBJ_DIR)\sys
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\sta_knl.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\get_tid.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\loc_cpu.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\unl_cpu.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\sns_loc.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\ena_dsp.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\dis_dsp.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\sns_dsp.c
CSRCS = $(CSRCS) $(SYSOBJ_DIR)\sns_ctx.c
OBJS = $(OBJS) $(OBJS_DIR)\sta_knl.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_tid.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\loc_cpu.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\unl_cpu.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sns_loc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_dsp.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dis_dsp.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sns_dsp.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sns_ctx.$(EXT_OBJ)


# Tasks
TSKOBJ_DIR = $(KERNEL_OBJ_DIR)\tsk
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\cre_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\acre_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\kcre_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\del_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\act_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\iact_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\can_act.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ext_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\exd_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ter_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\chg_pri.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\kchg_pri.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\get_pri.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ref_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ref_tst.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\slp_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\wup_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\iwup_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\can_wup.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\rel_wai.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\irel_wai.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\sus_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\rsm_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\frsm_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\dly_tsk.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\def_tex.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ras_tex.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\ena_tex.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\kexe_tex.c
CSRCS = $(CSRCS) $(TSKOBJ_DIR)\tcb2id.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\act_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\iact_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\can_act.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ext_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exd_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ter_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\chg_pri.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kchg_pri.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_pri.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_tst.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\slp_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\wup_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\iwup_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\can_wup.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rel_wai.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\irel_wai.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sus_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rsm_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\frsm_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dly_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\def_tex.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ras_tex.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_tex.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kexe_tex.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\tcb2id.$(EXT_OBJ)


# Semaphores
SEMOBJ_DIR = $(KERNEL_OBJ_DIR)\sem
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\cre_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\acre_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\kcre_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\del_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\sig_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\isig_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\wai_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\pol_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\twai_sem.c
CSRCS = $(CSRCS) $(SEMOBJ_DIR)\ref_sem.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sig_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\isig_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\wai_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\pol_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\twai_sem.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_sem.$(EXT_OBJ)


# Event-flags
FLGOBJ_DIR = $(KERNEL_OBJ_DIR)\flg
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\cre_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\acre_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\kcre_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\del_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\set_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\iset_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\clr_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\wai_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\pol_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\twai_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\kchk_flg.c
CSRCS = $(CSRCS) $(FLGOBJ_DIR)\ref_flg.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\set_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\iset_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\clr_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\wai_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\pol_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\twai_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kchk_flg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_flg.$(EXT_OBJ)


# Data queues
DTQOBJ_DIR = $(KERNEL_OBJ_DIR)\dtq
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\cre_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\acre_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\kcre_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\del_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\snd_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\fsnd_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\rcv_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\prcv_dtq.c
CSRCS = $(CSRCS) $(DTQOBJ_DIR)\trcv_dtq.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\snd_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fsnd_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rcv_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\prcv_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\trcv_dtq.$(EXT_OBJ)


# Mailboxes
MBXOBJ_DIR = $(KERNEL_OBJ_DIR)\mbx
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\acre_mbx.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\kcre_mbx.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\snd_mbx.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\rcv_mbx.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\kadf_msg.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\kadp_msg.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\kadd_msq.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\krmf_msg.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\krmp_msg.c
CSRCS = $(CSRCS) $(MBXOBJ_DIR)\krmv_msq.c
OBJS = $(OBJS) $(OBJS_DIR)\acre_mbx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_mbx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\snd_mbx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rcv_mbx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kadf_msg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kadp_msg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kadd_msq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krmf_msg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krmp_msg.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krmv_msq.$(EXT_OBJ)


# Mutexes
MTXOBJ_DIR = $(KERNEL_OBJ_DIR)\mtx
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\cre_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\acre_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\kcre_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\del_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\loc_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\ploc_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\tloc_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\unl_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\kadd_mtx.c
CSRCS = $(CSRCS) $(MTXOBJ_DIR)\krmv_mtx.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\loc_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ploc_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\tloc_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\unl_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kadd_mtx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krmv_mtx.$(EXT_OBJ)


# Fixed-sized Memory Pools
MPFOBJ_DIR = $(KERNEL_OBJ_DIR)\mpf
CSRCS = $(CSRCS) $(MPFOBJ_DIR)\acre_mpf.c
CSRCS = $(CSRCS) $(MPFOBJ_DIR)\kcre_mpf.c
CSRCS = $(CSRCS) $(MPFOBJ_DIR)\get_mpf.c
CSRCS = $(CSRCS) $(MPFOBJ_DIR)\pget_mpf.c
CSRCS = $(CSRCS) $(MPFOBJ_DIR)\rel_mpf.c
OBJS = $(OBJS) $(OBJS_DIR)\acre_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\pget_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rel_mpf.$(EXT_OBJ)


# System Time Management
TIMOBJ_DIR = $(KERNEL_OBJ_DIR)\tim
CSRCS = $(CSRCS) $(TIMOBJ_DIR)\set_tim.c
CSRCS = $(CSRCS) $(TIMOBJ_DIR)\get_tim.c
CSRCS = $(CSRCS) $(TIMOBJ_DIR)\isig_tim.c
OBJS = $(OBJS) $(OBJS_DIR)\set_tim.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_tim.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\isig_tim.$(EXT_OBJ)


# Cyclic Handlers
CYCOBJ_DIR = $(KERNEL_OBJ_DIR)\cyc
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\cre_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\acre_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\kcre_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\del_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\sta_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\stp_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\ref_cyc.c
CSRCS = $(CSRCS) $(CYCOBJ_DIR)\kcyc_hdr.c
OBJS = $(OBJS) $(OBJS_DIR)\cre_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sta_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\stp_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_cyc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcyc_hdr.$(EXT_OBJ)


# Interrupt handlers
INHOBJ_DIR = $(KERNEL_OBJ_DIR)\inh
CSRCS = $(CSRCS) $(INHOBJ_DIR)\def_inh.c
CSRCS = $(CSRCS) $(INHOBJ_DIR)\sta_inh.c
CSRCS = $(CSRCS) $(INHOBJ_DIR)\exe_inh.c
CSRCS = $(CSRCS) $(INHOBJ_DIR)\end_inh.c
OBJS = $(OBJS) $(OBJS_DIR)\def_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sta_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\end_inh.$(EXT_OBJ)


# Interrupt Service Routines
ISROBJ_DIR = $(KERNEL_OBJ_DIR)\isr
CSRCS = $(CSRCS) $(ISROBJ_DIR)\acre_isr.c
CSRCS = $(CSRCS) $(ISROBJ_DIR)\kcre_isr.c
CSRCS = $(CSRCS) $(ISROBJ_DIR)\del_isr.c
CSRCS = $(CSRCS) $(ISROBJ_DIR)\exe_isr.c
OBJS = $(OBJS) $(OBJS_DIR)\acre_isr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_isr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_isr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_isr.$(EXT_OBJ)


# end of file
