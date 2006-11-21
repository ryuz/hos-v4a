# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Directories
KERNEL_DIR     = $(TOP_DIR)\kernel
KERNEL_SRC_DIR = $(KERNEL_DIR)\source
KERNEL_INC_DIR = $(KERNEL_DIR)\include

CORE_DIR       = $(KERNEL_SRC_DIR)\core
OBJ_DIR        = $(KERNEL_SRC_DIR)\object

DSP_DIR        = $(CORE_DIR)\dsp
QUE_DIR        = $(CORE_DIR)\que
TOQ_DIR        = $(CORE_DIR)\toq
HEP_DIR        = $(CORE_DIR)\hep
DPC_DIR        = $(CORE_DIR)\dpc

SYSOBJ_DIR     = $(OBJ_DIR)\sys
TSKOBJ_DIR     = $(OBJ_DIR)\tsk
SEMOBJ_DIR     = $(OBJ_DIR)\sem
FLGOBJ_DIR     = $(OBJ_DIR)\flg
MBXOBJ_DIR     = $(OBJ_DIR)\mbx
MPFOBJ_DIR     = $(OBJ_DIR)\mpf
INHOBJ_DIR     = $(OBJ_DIR)\inh
ISROBJ_DIR     = $(OBJ_DIR)\isr
TIMOBJ_DIR     = $(OBJ_DIR)\tim

# %jp{インクルードパス追加}
INC_DIRS       = $(INC_DIRS) $(KERNEL_INC_DIR)


# object files
OBJS           = $(OBJS)								\
                 $(OBJS_DIR)\ent_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\idl_lop.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_sta.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_ext.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_ter.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_wai.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_wup.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_sus.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dsp_rsm.$(EXT_OBJ)			\
                 $(OBJS_DIR)\add_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\adf_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\adp_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rmv_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rmh_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\trm_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\nxt_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rot_que.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sig_toq.$(EXT_OBJ)			\
                 $(OBJS_DIR)\add_toq.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rmv_toq.$(EXT_OBJ)			\
                 $(OBJS_DIR)\cre_hep.$(EXT_OBJ)			\
                 $(OBJS_DIR)\alc_hep.$(EXT_OBJ)			\
                 $(OBJS_DIR)\fre_hep.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dpc_fre.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dpc_rcv.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dpc_snd.$(EXT_OBJ)			\
                 $(OBJS_DIR)\lev_svc.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sta_knl.$(EXT_OBJ)			\
                 $(OBJS_DIR)\get_tid.$(EXT_OBJ)			\
                 $(OBJS_DIR)\loc_cpu.$(EXT_OBJ)			\
                 $(OBJS_DIR)\unl_cpu.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sns_loc.$(EXT_OBJ)			\
                 $(OBJS_DIR)\ena_dsp.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dis_dsp.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sns_dsp.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sns_ctx.$(EXT_OBJ)			\
                 $(OBJS_DIR)\acre_tsk.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_tsk.$(EXT_OBJ)		\
                 $(OBJS_DIR)\act_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\ext_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\slp_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\wup_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\can_wup.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rel_wai.$(EXT_OBJ)			\
                 $(OBJS_DIR)\dly_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\ref_tsk.$(EXT_OBJ)			\
                 $(OBJS_DIR)\cre_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\acre_sem.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_sem.$(EXT_OBJ)		\
                 $(OBJS_DIR)\del_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sig_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\wai_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\pol_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\twai_sem.$(EXT_OBJ)		\
                 $(OBJS_DIR)\ref_sem.$(EXT_OBJ)			\
                 $(OBJS_DIR)\cre_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\acre_flg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_flg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\del_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\set_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\iset_flg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\clr_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\wai_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\pol_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\twai_flg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kchk_flg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\ref_flg.$(EXT_OBJ)			\
                 $(OBJS_DIR)\acre_mbx.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_mbx.$(EXT_OBJ)		\
                 $(OBJS_DIR)\snd_mbx.$(EXT_OBJ)			\
                 $(OBJS_DIR)\rcv_mbx.$(EXT_OBJ)			\
                 $(OBJS_DIR)\kadf_msg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kadp_msg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kadd_msq.$(EXT_OBJ)		\
                 $(OBJS_DIR)\krmf_msg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\krmp_msg.$(EXT_OBJ)		\
                 $(OBJS_DIR)\krmv_msq.$(EXT_OBJ)		\
                 $(OBJS_DIR)\acre_mpf.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_mpf.$(EXT_OBJ)		\
                 $(OBJS_DIR)\get_mpf.$(EXT_OBJ)			\
                 $(OBJS_DIR)\pget_mpf.$(EXT_OBJ)		\
                 $(OBJS_DIR)\rel_mpf.$(EXT_OBJ)			\
                 $(OBJS_DIR)\set_tim.$(EXT_OBJ)			\
                 $(OBJS_DIR)\get_tim.$(EXT_OBJ)			\
                 $(OBJS_DIR)\isig_tim.$(EXT_OBJ)		\
                 $(OBJS_DIR)\def_inh.$(EXT_OBJ)			\
                 $(OBJS_DIR)\sta_inh.$(EXT_OBJ)			\
                 $(OBJS_DIR)\exe_inh.$(EXT_OBJ)			\
                 $(OBJS_DIR)\end_inh.$(EXT_OBJ)			\
                 $(OBJS_DIR)\acre_isr.$(EXT_OBJ)		\
                 $(OBJS_DIR)\kcre_isr.$(EXT_OBJ)		\
                 $(OBJS_DIR)\exe_isr.$(EXT_OBJ)


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
                 $(KERNEL_INC_DIR)\core\opttyp.h		\
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


COMMON_HEADERS = $(ITRON_HEADERS) $(CFG_HEADERS) $(PARS_HEADERS) $(CORE_HEADERS) $(ARCH_HEADERS) $(TSKOBJ_HEADERS)



# end of file
