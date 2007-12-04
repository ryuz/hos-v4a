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

MPFOBJ_HEADERS = $(KERNEL_INC_DIR)\object\mpfobj.h

TIMOBJ_HEADERS = $(KERNEL_INC_DIR)\object\timobj.h

INHOBJ_HEADERS = $(KERNEL_INC_DIR)\object\inhobj.h

ISROBJ_HEADERS = $(KERNEL_INC_DIR)\object\isrobj.h



# Dispatcher
DSP_DIR = $(KERNEL_CORE_DIR)\dsp
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
OBJS = $(OBJS) $(OBJS_DIR)\cre_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\del_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmh_rdq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_rdq.$(EXT_OBJ)


# Time management
TIM_DIR = $(KERNEL_CORE_DIR)\tim
OBJS = $(OBJS) $(OBJS_DIR)\sig_tim.$(EXT_OBJ)


# Timeout-queue
TOQ_DIR = $(KERNEL_CORE_DIR)\toq
OBJS = $(OBJS) $(OBJS_DIR)\sig_toq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_toq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_toq.$(EXT_OBJ)


# Timer-queue
TMQ_DIR = $(KERNEL_CORE_DIR)\tmq
OBJS = $(OBJS) $(OBJS_DIR)\sig_tmq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\add_tmq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rmv_tmq.$(EXT_OBJ)


# Memory-heap
HEP_DIR = $(KERNEL_CORE_DIR)\hep
OBJS = $(OBJS) $(OBJS_DIR)\cre_hep.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\alc_hep.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fre_hep.$(EXT_OBJ)


# Deferrable procedure call
DPC_DIR = $(KERNEL_CORE_DIR)\dpc
OBJS = $(OBJS) $(OBJS_DIR)\exe_dpc.$(EXT_OBJ)


# Asyncronous data-queue
ADTQ_DIR = $(KERNEL_CORE_DIR)\adtq
OBJS = $(OBJS) $(OBJS_DIR)\frcv_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fsnd_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rcv_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\reff_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\refs_adq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\snd_adq.$(EXT_OBJ)


# System
SYSOBJ_DIR = $(KERNEL_OBJ_DIR)\sys
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
OBJS = $(OBJS) $(OBJS_DIR)\acre_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\act_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ext_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\slp_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\wup_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\can_wup.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rel_wai.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dly_tsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ref_tsk.$(EXT_OBJ)


# Semaphores
SEMOBJ_DIR = $(KERNEL_OBJ_DIR)\sem
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
OBJS = $(OBJS) $(OBJS_DIR)\cre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\acre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\snd_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\fsnd_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rcv_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\prcv_dtq.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\trcv_dtq.$(EXT_OBJ)


# Mailboxes
MBXOBJ_DIR = $(KERNEL_OBJ_DIR)\mbx
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


# Fixed-sized Memory Pools
MPFOBJ_DIR = $(KERNEL_OBJ_DIR)\mpf
OBJS = $(OBJS) $(OBJS_DIR)\acre_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\pget_mpf.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\rel_mpf.$(EXT_OBJ)


# System Time Management
TIMOBJ_DIR = $(KERNEL_OBJ_DIR)\tim
OBJS = $(OBJS) $(OBJS_DIR)\set_tim.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_tim.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\isig_tim.$(EXT_OBJ)


# Interrupt handlers
INHOBJ_DIR = $(KERNEL_OBJ_DIR)\inh
OBJS = $(OBJS) $(OBJS_DIR)\def_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\sta_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_inh.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\end_inh.$(EXT_OBJ)


# Interrupt Service Routines
ISROBJ_DIR = $(KERNEL_OBJ_DIR)\isr
OBJS = $(OBJS) $(OBJS_DIR)\acre_isr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_isr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_isr.$(EXT_OBJ)


# end of file
