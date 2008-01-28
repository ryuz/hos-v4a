# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Panasonic MN103S series
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a


# %jp{アーキテクチャ}
ARCH_PROC ?= mn103/mn1030
ARCH_IRC  ?= mn103/mn103s
ARCH_CC   ?= cc103


# %jp{ディレクトリ定義}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス定義}
INC_PROC_DIR    = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR     = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR    = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR     = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR  = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)

# %jp{パス設定}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)

# %jp{オプションフラグ}
CFLAGS  += 
AFLAGS  += 
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-mn103s


# アセンブラファイルの追加
ASRCS += $(SRC_PROC_CC_DIR)/kini_prc.as		\
         $(SRC_PROC_CC_DIR)/kdis_int.as		\
         $(SRC_PROC_CC_DIR)/kena_int.as		\
         $(SRC_PROC_CC_DIR)/kwai_int.as		\
         $(SRC_PROC_CC_DIR)/kcre_ctx.as		\
         $(SRC_PROC_CC_DIR)/krst_ctx.as		\
         $(SRC_PROC_CC_DIR)/ksta_ctx.as		\
         $(SRC_PROC_CC_DIR)/kswi_ctx.as		\
         $(SRC_PROC_CC_DIR)/kint_hdr.as



# C言語ファイルの追加
CSRCS += $(SRC_PROC_DIR)/val_int.c			\
         $(SRC_IRC_DIR)/ini_irc.c			\
         $(SRC_IRC_DIR)/exe_irc.c			\
         $(SRC_IRC_DIR)/ena_int.c			\
         $(SRC_IRC_DIR)/dis_int.c			\
         $(SRC_IRC_DIR)/clr_int.c			\
         $(SRC_IRC_DIR)/chg_ilv.c			\
         $(SRC_IRC_DIR)/get_ilv.c


# カーネル共通ソースの追加
include $(KERNEL_MAKINC_DIR)/knlsrc.inc


# %jp{ALL}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst

# depend
.PHONY : depend
depend: makelib_depend

# srccpy
.PHONY : srccpy
srccpy: makelib_srccpy



# %jp{cc103S用の設定読込み}
include $(KERNEL_MAKINC_DIR)/cc103_d.inc

# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc


# %jp{cc103S用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/cc103_r.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc


# end of file
