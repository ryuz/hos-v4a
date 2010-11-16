# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Panasonic MN103S series
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = libhosv4a


# %jp{アーキテクチャパス}
ARCH_PROC = mn103\mn1030
ARCH_IRC  = mn103\mn103s
ARCH_CC   = cc103


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake


# %jp{カーネル指定}
KERNEL = Yes


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス}
INC_PROC_DIR    = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR     = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR    = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_CC_DIR = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR     = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_CC_DIR  = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)


# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
CFGRTR     = h4acfg-mn103s


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)



# %jp{オプションフラグ}
CFLAGS = 
AFLAGS = 
LFLAGS = 



# %jp{コンパイラ依存定義}%en{definitions of compiler dependence}
!include $(KERNEL_MAKINC_DIR)\cc103_d.inc

# %jp{ライブラリ生成共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc



# %jp{オブジェクトファイル定義}
OBJS = $(OBJS) $(OBJS_DIR)\kini_prc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ksta_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kint_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ini_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\exe_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\clr_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\chg_ilv.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_ilv.$(EXT_OBJ)


# %jp{ALL}%en{all}
all: mkdir_objs makelib_all
	cd $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)


# %jp{クリーン}%en{clean}
clean: makelib_clean
	-$(CMD_RM) /Q *.lst
	-$(CMD_RM) /Q $(OBJS_DIR)\*.*
	cd $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean


# %jp{カーネル共通ソースの追加}%en{definitions of kernel source files}
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc

# %jp{ライブラリ生成用ルール読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
!include $(KERNEL_MAKINC_DIR)\cc103_r.inc

# %jp{カーネル依存関係読込み}%en{dependence}
!include $(KERNEL_MAKINC_DIR)\knldep.inc



# %jp{コピー}%en{source files copy}
$(OBJS_DIR)\kini_prc.as	:	$(SRC_PROC_CC_DIR)\kini_prc.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kdis_int.as	:	$(SRC_PROC_CC_DIR)\kdis_int.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kena_int.as	:	$(SRC_PROC_CC_DIR)\kena_int.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kwai_int.as	:	$(SRC_PROC_CC_DIR)\kwai_int.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kcre_ctx.as	:	$(SRC_PROC_CC_DIR)\kcre_ctx.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\krst_ctx.as	:	$(SRC_PROC_CC_DIR)\krst_ctx.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\ksta_ctx.as	:	$(SRC_PROC_CC_DIR)\ksta_ctx.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kswi_ctx.as	:	$(SRC_PROC_CC_DIR)\kswi_ctx.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\kint_hdr.as	:	$(SRC_PROC_CC_DIR)\kint_hdr.as
	$(CMD_CP) $? $@

$(OBJS_DIR)\val_int.c	:	$(SRC_PROC_DIR)\val_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\ini_irc.c	:	$(SRC_IRC_DIR)\ini_irc.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\exe_irc.c	:	$(SRC_IRC_DIR)\exe_irc.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\ena_int.c	:	$(SRC_IRC_DIR)\ena_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\dis_int.c	:	$(SRC_IRC_DIR)\dis_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\clr_int.c	:	$(SRC_IRC_DIR)\clr_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\chg_ilv.c	:	$(SRC_IRC_DIR)\chg_ilv.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\get_ilv.c	:	$(SRC_IRC_DIR)\get_ilv.c
	$(CMD_CP) $? $@


# %jp{依存関係}%en{dependency}
$(OBJS_DIR)\kini_prc.ro		:	$(OBJS_DIR)\kini_prc.as	
$(OBJS_DIR)\kdis_int.ro		:	$(OBJS_DIR)\kdis_int.as	
$(OBJS_DIR)\kena_int.ro		:	$(OBJS_DIR)\kena_int.as	
$(OBJS_DIR)\kwai_int.ro		:	$(OBJS_DIR)\kwai_int.as	
$(OBJS_DIR)\kcre_ctx.ro		:	$(OBJS_DIR)\kcre_ctx.as	
$(OBJS_DIR)\krst_ctx.ro		:	$(OBJS_DIR)\krst_ctx.as	
$(OBJS_DIR)\ksta_ctx.ro		:	$(OBJS_DIR)\ksta_ctx.as	
$(OBJS_DIR)\kswi_ctx.ro		:	$(OBJS_DIR)\kswi_ctx.as	
$(OBJS_DIR)\kint_hdr.ro		:	$(OBJS_DIR)\kint_hdr.as
$(OBJS_DIR)\val_int.ro		:	$(OBJS_DIR)\val_int.c
$(OBJS_DIR)\ini_irc.ro		:	$(OBJS_DIR)\ini_irc.c
$(OBJS_DIR)\exe_irc.ro		:	$(OBJS_DIR)\exe_irc.c
$(OBJS_DIR)\ena_int.ro		:	$(OBJS_DIR)\ena_int.c
$(OBJS_DIR)\dis_int.ro		:	$(OBJS_DIR)\dis_int.c
$(OBJS_DIR)\clr_int.ro		:	$(OBJS_DIR)\clr_int.c
$(OBJS_DIR)\chg_ilv.ro		:	$(OBJS_DIR)\chg_ilv.c
$(OBJS_DIR)\get_ilv.ro		:	$(OBJS_DIR)\get_ilv.c


# end of file
