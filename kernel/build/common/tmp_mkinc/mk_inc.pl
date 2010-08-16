#! /usr/bin/perl


# sources
@sources =
(
	[
		"Dispatcher",				# comment
		"\$(COMMON_HEADERS)",		# depend
		"\$(KERNEL_CORE_DIR)/dsp",	# path
		"DSP_DIR",					# def_dir
		"ent_tsk.c",
		"idl_lop.c",
		"dsp_tsk.c",
		"dsp_sta.c",
		"dsp_ext.c",
		"dsp_ter.c",
		"dsp_wai.c",
		"dsp_wup.c",
		"dsp_sus.c",
		"dsp_rsm.c",
	],
	[
		"Task-queue",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/que",
		"QUE_DIR",
		"add_que.c",
		"adf_que.c",
		"adp_que.c",
		"rmv_que.c",
		"rmh_que.c",
		"trm_que.c",
		"nxt_que.c",
		"rot_que.c",
	],
	[
		"Ready-queue",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/rdq",
		"RDQ_DIR",
		"cre_rdq.c",
		"del_rdq.c",
		"add_rdq.c",
		"rmv_rdq.c",
		"rmh_rdq.c",
		"ref_rdq.c",
	],
	[
		"Time management",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/tim",
		"TIM_DIR",
		"sig_tim.c",
	],
	[
		"Timeout-queue",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/toq",
		"TOQ_DIR",
		"sig_toq.c",
		"add_toq.c",
		"rmv_toq.c",
	],
	[
		"Timer-queue",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/tmq",
		"TMQ_DIR",
		"sig_tmq.c",
		"add_tmq.c",
		"rmv_tmq.c",
	],
	[
		"Memory-heap",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/hep",
		"HEP_DIR",
		"cre_hep.c",
		"alc_hep.c",
		"fre_hep.c",
	],
	[
		"Deferrable procedure call",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/dpc",
		"DPC_DIR",
		"ini_dpc.c",
		"req_dpc.c",
		"exe_dpc.c",
	],
	[
		"Asyncronous data-queue",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_CORE_DIR)/adtq",
		"ADTQ_DIR",
		"frcv_adq.c",
		"fsnd_adq.c",
		"rcv_adq.c",
		"reff_adq.c",
		"refs_adq.c",
		"snd_adq.c",
	],
	[
		"System",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/sys",
		"SYSOBJ_DIR",
		"sta_knl.c",
		"get_tid.c",
		"loc_cpu.c",
		"unl_cpu.c",
		"sns_loc.c",
		"ena_dsp.c",
		"dis_dsp.c",
		"sns_dsp.c",
		"sns_ctx.c",
	],
	[
		"Tasks",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/tsk",
		"TSKOBJ_DIR",
		"cre_tsk.c",
		"acre_tsk.c",
		"kcre_tsk.c",
		"del_tsk.c",
		"act_tsk.c",
		"iact_tsk.c",
		"can_act.c",
		"ext_tsk.c",
		"exd_tsk.c",
		"ter_tsk.c",
		"chg_pri.c",
		"kchg_pri.c",
		"get_pri.c",
		"ref_tsk.c",
		"ref_tst.c",
		"slp_tsk.c",
		"wup_tsk.c",
		"iwup_tsk.c",
		"can_wup.c",
		"rel_wai.c",
		"irel_wai.c",
		"sus_tsk.c",
		"rsm_tsk.c",
		"frsm_tsk.c",
		"dly_tsk.c",
		"def_tex.c",
		"ras_tex.c",
		"ena_tex.c",
		"kexe_tex.c",
		"tcb2id.c",
	],
	[
		"Semaphores",
		"\$(COMMON_HEADERS) \$(SEMOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/sem",
		"SEMOBJ_DIR",
		"cre_sem.c",
		"acre_sem.c",
		"kcre_sem.c",
		"del_sem.c",
		"sig_sem.c",
		"isig_sem.c",
		"wai_sem.c",
		"pol_sem.c",
		"twai_sem.c",
		"ref_sem.c",
	],
	[
		"Event-flags",
		"\$(COMMON_HEADERS) \$(FLGOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/flg",
		"FLGOBJ_DIR",
		"cre_flg.c",
		"acre_flg.c",
		"kcre_flg.c",
		"del_flg.c",
		"set_flg.c",
		"iset_flg.c",
		"clr_flg.c",
		"wai_flg.c",
		"pol_flg.c",
		"twai_flg.c",
		"kchk_flg.c",
		"ref_flg.c",
	],
	[
		"Data queues",
		"\$(COMMON_HEADERS) \$(DTQOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/dtq",
		"DTQOBJ_DIR",
		"cre_dtq.c",
		"acre_dtq.c",
		"kcre_dtq.c",
		"del_dtq.c",
		"snd_dtq.c",
		"fsnd_dtq.c",
		"rcv_dtq.c",
		"prcv_dtq.c",
		"trcv_dtq.c",
	],
	[
		"Mailboxes",
		"\$(COMMON_HEADERS) \$(MBXOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/mbx",
		"MBXOBJ_DIR",
		"acre_mbx.c",
		"kcre_mbx.c",
		"snd_mbx.c",
		"rcv_mbx.c",
		"kadf_msg.c",
		"kadp_msg.c",
		"kadd_msq.c",
		"krmf_msg.c",
		"krmp_msg.c",
		"krmv_msq.c",
	],
	[
		"Mutexes",
		"\$(COMMON_HEADERS) \$(MTXOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/mtx",
		"MTXOBJ_DIR",
		"cre_mtx.c",
		"acre_mtx.c",
		"kcre_mtx.c",
		"del_mtx.c",
		"loc_mtx.c",
		"ploc_mtx.c",
		"tloc_mtx.c",
		"unl_mtx.c",
		"kadd_mtx.c",
		"krmv_mtx.c",
	],
	[
		"Fixed-sized Memory Pools",
		"\$(COMMON_HEADERS) \$(MPFOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/mpf",
		"MPFOBJ_DIR",
		"acre_mpf.c",
		"kcre_mpf.c",
		"get_mpf.c",
		"pget_mpf.c",
		"rel_mpf.c",
	],
	[
		"System Time Management",
		"\$(COMMON_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/tim",
		"TIMOBJ_DIR",
		"set_tim.c",
		"get_tim.c",
		"isig_tim.c",
	],
	[
		"Cyclic Handlers",
		"\$(COMMON_HEADERS) \$(CYCOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/cyc",
		"CYCOBJ_DIR",
		"cre_cyc.c",
		"acre_cyc.c",
		"kcre_cyc.c",
		"del_cyc.c",
		"sta_cyc.c",
		"stp_cyc.c",
		"ref_cyc.c",
		"kcyc_hdr.c",
	],
	[
		"Interrupt handlers",
		"\$(COMMON_HEADERS) \$(INHOBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/inh",
		"INHOBJ_DIR",
		"def_inh.c",
		"sta_inh.c",
		"exe_inh.c",
		"end_inh.c",
	],
	[
		"Interrupt Service Routines",
		"\$(COMMON_HEADERS) \$(ISROBJ_HEADERS)",
		"\$(KERNEL_OBJ_DIR)/isr",
		"ISROBJ_DIR",
		"acre_isr.c",
		"kcre_isr.c",
		"del_isr.c",
		"exe_isr.c",
	],
);

# header
$headers = <<END_OF_HEADERS;
# Header files
ITRON_HEADERS  = \$(KERNEL_INC_DIR)/itron.h				\\
                 \$(KERNEL_INC_DIR)/kernel.h

CFG_HEADERS    = \$(KERNEL_INC_DIR)/parser/parssys.h		\\
                 \$(KERNEL_INC_DIR)/parser/parsknl.h		\\
                 \$(KERNEL_INC_DIR)/parser/parserr.h		\\
                 \$(KERNEL_INC_DIR)/parser/parshok.h

PARS_HEADERS   = \$(KERNEL_INC_DIR)/config/cfgsys.h		\\
                 \$(KERNEL_INC_DIR)/config/cfgknl.h		\\
                 \$(KERNEL_INC_DIR)/config/cfgerr.h		\\
                 \$(KERNEL_INC_DIR)/config/cfghok.h

CORE_HEADERS   = \$(KERNEL_INC_DIR)/core/adtq.h			\\
                 \$(KERNEL_INC_DIR)/core/basetyp.h		\\
                 \$(KERNEL_INC_DIR)/core/chkptr.h		\\
                 \$(KERNEL_INC_DIR)/core/cmpl.h			\\
                 \$(KERNEL_INC_DIR)/core/core.h			\\
                 \$(KERNEL_INC_DIR)/core/dsp.h			\\
                 \$(KERNEL_INC_DIR)/core/hep.h			\\
                 \$(KERNEL_INC_DIR)/core/objhdl.h		\\
                 \$(KERNEL_INC_DIR)/core/objid.h			\\
                 \$(KERNEL_INC_DIR)/core/que.h			\\
                 \$(KERNEL_INC_DIR)/core/rdq.h			\\
                 \$(KERNEL_INC_DIR)/core/sys.h			\\
                 \$(KERNEL_INC_DIR)/core/tmq.h			\\
                 \$(KERNEL_INC_DIR)/core/toq.h			\\
                 \$(KERNEL_INC_DIR)/core/dpc.h

ARCH_HEADERS   = \$(INC_PROC_DIR)/proc.h					\\
                 \$(INC_PROC_DIR)/procatr.h				\\
                 \$(INC_IRC_DIR)/irc.h					\\
                 \$(INC_IRC_DIR)/ircatr.h

TSKOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/tskobj.h

SEMOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/semobj.h

FLGOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/flgobj.h

DTQOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/dtqobj.h

MBXOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/mbxobj.h

MTXOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/mtxobj.h

MPFOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/mpfobj.h

CYCOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/cycobj.h

INHOBJ_HEADERS = \$(KERNEL_INC_DIR)/object/inhobj.h

ISROBJ_HEADERS = \$(KERNEL_INC_DIR)/object/isrobj.h

COMMON_HEADERS = \$(ITRON_HEADERS)		\\
                 \$(CFG_HEADERS)			\\
                 \$(PARS_HEADERS)		\\
                 \$(CORE_HEADERS)		\\
                 \$(ARCH_HEADERS)		\\
                 \$(TSKOBJ_HEADERS)		\\
END_OF_HEADERS




# --------------------------------------------------
#  gmake source
# --------------------------------------------------

open(OUT, "> ../gmake/knlsrc.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance\n");
print(OUT "#    common include file for GNU make\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# Directories\n");
print(OUT "KERNEL_SRC_DIR  = \$(KERNEL_DIR)/source\n");
print(OUT "KERNEL_INC_DIR  = \$(KERNEL_DIR)/include\n");
print(OUT "KERNEL_CORE_DIR = \$(KERNEL_SRC_DIR)/core\n");
print(OUT "KERNEL_OBJ_DIR  = \$(KERNEL_SRC_DIR)/object\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# Kernel include directorys\n");
print(OUT "INC_DIRS += \$(KERNEL_INC_DIR)\n");
print(OUT "\n");
print(OUT "\n");

print(OUT $headers);
print(OUT "\n");

foreach $s ( @sources )
{
	@list = @{$s};
	$comment = shift(@list);
	$depend  = shift(@list);
	$path    = shift(@list);
	$def_dir = shift(@list);
	
	print(OUT "\n\n");
	print(OUT "# $comment\n");
	print(OUT "$def_dir = $path\n");
	print(OUT "SRC_DIRS += \$($def_dir)\n");
	foreach $file ( @list )
	{
		print(OUT "CSRCS += \$($def_dir)/$file\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);



# --------------------------------------------------
#  gmake depend
# --------------------------------------------------

open(OUT, "> ../gmake/knldep.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance\n");
print(OUT "#    common depend file for GNU make\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
foreach $s ( @sources )
{
	@list = @{$s};
	$comment = shift(@list);
	$depend  = shift(@list);
	$path    = shift(@list);
	$def_dir = shift(@list);
	
	print(OUT "\n");
	foreach $file ( @list )
	{
		$objfile = $file;
		$objfile =~ s/\.c/\./;
		print(OUT "\$(OBJS_DIR)/$objfile\$(EXT_OBJ):\t\$($def_dir)/$file\t$depend\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);




# --------------------------------------------------
#  nmake source
# --------------------------------------------------

open(OUT, "> ../nmake/knlsrc.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance\n");
print(OUT "#    common include file for nmake\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# Directories\n");
print(OUT "KERNEL_SRC_DIR  = \$(KERNEL_DIR)\\source\n");
print(OUT "KERNEL_INC_DIR  = \$(KERNEL_DIR)\\include\n");
print(OUT "KERNEL_CORE_DIR = \$(KERNEL_SRC_DIR)\\core\n");
print(OUT "KERNEL_OBJ_DIR  = \$(KERNEL_SRC_DIR)\\object\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# Kernel include directorys\n");
print(OUT "INC_DIRS = \$(INC_DIRS) \$(KERNEL_INC_DIR)\n");
print(OUT "\n");
print(OUT "\n");

$tmp = $headers;
$tmp =~ s/\//\\/g;
print(OUT $tmp);
print(OUT "\n");

foreach $s ( @sources )
{
	@list = @{$s};
	$comment = shift(@list);
	$depend  = shift(@list);
	$path    = shift(@list);
	$def_dir = shift(@list);
	
	$path =~ s/\//\\/g;
	
	print(OUT "\n\n");
	print(OUT "# $comment\n");
	print(OUT "$def_dir = $path\n");
	foreach $file ( @list )
	{
		print(OUT "CSRCS = \$(CSRCS) \$($def_dir)\\$file\n");
	}
	foreach $file ( @list )
	{
		$file =~ s/\.c//g;
		print(OUT "OBJS = \$(OBJS) \$(OBJS_DIR)\\$file\.\$(EXT_OBJ)\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);



# --------------------------------------------------
#  nmake depend
# --------------------------------------------------

open(OUT, "> ../nmake/knldep.inc");

print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "#  Hyper Operating System V4 Advance\n");
print(OUT "#    common depend file for nmake\n");
print(OUT "#\n");
print(OUT "#  Copyright (C) 1998-2007 by Project HOS\n");
print(OUT "#  http://sourceforge.jp/projects/hos/\n");
print(OUT "# ----------------------------------------------------------------------------\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# ----------------------------------\n");
print(OUT "#  source copy\n");
print(OUT "# ----------------------------------\n");
print(OUT "\n");
print(OUT "makelib_srcobjcp:\n\n");

foreach $s ( @sources )
{
	@list = @{$s};
	$comment = shift(@list);
	$depend  = shift(@list);
	$path    = shift(@list);
	$def_dir = shift(@list);
	
	$path =~ s/\//\\/g;
	
	print(OUT "\n");
	foreach $file ( @list )
	{
		print(OUT "\$(OBJS_DIR)\\$file : \$($def_dir)\\$file\n");
		print(OUT "\t\$(CMD_CP) \$($def_dir)\\$file \$(OBJS_DIR)\\\n");
		print(OUT "\n");
	}
}

print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# ----------------------------------\n");
print(OUT "#  depend\n");
print(OUT "# ----------------------------------\n");

foreach $s ( @sources )
{
	@list = @{$s};
	$comment = shift(@list);
	$depend  = shift(@list);
	$path    = shift(@list);
	$def_dir = shift(@list);
	
	$path =~ s/\//\\/g;
	
	print(OUT "\n");
	foreach $file ( @list )
	{
		$objfile =~ s/\.c//g;
		print(OUT "\$(OBJS_DIR)\\$objfile.\$(EXT_OBJ):\t\$(OBJS_DIR)\\$file\t$depend\n");
	}
}


print(OUT "\n");
print(OUT "\n");
print(OUT "\n");
print(OUT "# end of file\n");

close(OUT);

