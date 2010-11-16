# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for ATMEL AT91 series
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = libhosv4a


# %jp{アーキテクチャ定義}
ARCH_PROC = arm\arm_v4t
ARCH_IRC  = arm\at91
ARCH_CC   = armcc


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
CFGRTR     = h4acfg-at91


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)



# %jp{オプションフラグ}
CFLAGS  = $(CFLAGS) --cpu=ARM7TDMI --apcs=inter --thumb
AFLAGS  = $(AFLAGS) --cpu=ARM7TDMI --apcs=inter --thumb
ARFLAGS = $(ARFLAGS)



# %jp{コンパイラ依存定義}%en{definitions of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/armcc_d.inc

# %jp{ライブラリ生成共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc



# %jp{オブジェクトファイル定義}
OBJS = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kini_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kexe_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\vclr_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kirq_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kfiq_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)



# %jp{ALL}%en{all}
all: mkdir_objs srcobjcp makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)


# %jp{クリーン}%en{clean}
clean: makelib_clean
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(CMD_CD) $(MAKEDIR)


# %jp{カーネル共通ソースの追加}%en{definitions of kernel source files}
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc

# %jp{ライブラリ生成用ルール読込み}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
!include $(KERNEL_MAKINC_DIR)/armcc_r.inc

# %jp{カーネル依存関係読込み}%en{dependence}
!include $(KERNEL_MAKINC_DIR)/knldep.inc



# %jp{コピー}%en{source files copy}
srcobjcp:
	$(CMD_CP) $(SRC_PROC_CC_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(SRC_IRC_DIR)\*.*     $(OBJS_DIR)

#	$(CMD_CP) $(SRC_PROC_DIR)\*.*    $(OBJS_DIR)


$(OBJS_DIR)\val_int.c: $(SRC_PROC_DIR)\val_int.c
	$(CMD_CP) $(SRC_PROC_DIR)\val_int.c $(OBJS_DIR)\


# %jp{依存関係}%en{dependence}
# $(OBJS_DIR)\val_int.o	:	$(OBJS_DIR)\val_int.c
$(OBJS_DIR)\kini_irc.o	:	$(OBJS_DIR)\kini_irc.c
$(OBJS_DIR)\kexe_irc.o	:	$(OBJS_DIR)\kexe_irc.c
$(OBJS_DIR)\ena_int.o	:	$(OBJS_DIR)\ena_int.c
$(OBJS_DIR)\dis_int.o	:	$(OBJS_DIR)\dis_int.c
$(OBJS_DIR)\vclr_int.o	:	$(OBJS_DIR)\vclr_int.c
$(OBJS_DIR)\kcre_ctx.o	:	$(OBJS_DIR)\kcre_ctx.s
$(OBJS_DIR)\kdis_int.o	:	$(OBJS_DIR)\kdis_int.s
$(OBJS_DIR)\kena_int.o	:	$(OBJS_DIR)\kena_int.s
$(OBJS_DIR)\kirq_hdr.o	:	$(OBJS_DIR)\kirq_hdr.s
$(OBJS_DIR)\kfiq_hdr.o	:	$(OBJS_DIR)\kfiq_hdr.s
$(OBJS_DIR)\krst_ctx.o	:	$(OBJS_DIR)\krst_ctx.s
$(OBJS_DIR)\kswi_ctx.o	:	$(OBJS_DIR)\kswi_ctx.s
$(OBJS_DIR)\kwai_int.o	:	$(OBJS_DIR)\kwai_int.s



# end of file
