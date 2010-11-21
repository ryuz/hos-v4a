# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for SH2
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}%en{target}
TARGET ?= libhosv4a


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_PROC ?= sh/sh2a-fpu
ARCH_IRC  ?= simple
ARCH_CC   ?= shc


# %jp{ディレクトリ定義}%en{directorys}
HOSV4A_DIR        = ../../../../..
KERNEL_DIR        = $(HOSV4A_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{カーネル指定}
KERNEL = Yes


# %jp{コンフィギュレータ定義}%en{Configurator}
CFGRTR_DIR = $(HOSV4A_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-sh2a-fpu


# %jp{共通定義読込み}%en{Common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャパス}%en{architecture path}
INC_PROC_DIR    = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR     = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR    = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR     = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR  = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)


# %jp{パス設定}%en{Source path}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{オプションフラグ}%en{compile options}
CFLAGS  += -CPu=sh2afpu
AFLAGS  += -CPu=sh2afpu
ARFLAGS += 


ifeq ($(FAST_VECTOR),Yes)
A_DEFS += _KERNEL_FAST_INTVEC="ON"
endif



# %jp{C言語ファイルの追加}
CSRCS += $(SRC_PROC_DIR)/val_int.c			\
         $(SRC_IRC_DIR)/ena_int.c			\
         $(SRC_IRC_DIR)/dis_int.c			\
         $(SRC_IRC_DIR)/clr_int.c			\
         $(SRC_IRC_DIR)/get_imsk.c			\
         $(SRC_IRC_DIR)/chg_imsk.c			\
         $(SRC_IRC_DIR)/chg_ilv.c			\
         $(SRC_IRC_DIR)/get_ilv.c

# %jp{アセンブラファイルの追加}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.src	\
         $(SRC_PROC_CC_DIR)/kena_int.src	\
         $(SRC_PROC_CC_DIR)/kwai_int.src	\
         $(SRC_PROC_CC_DIR)/kcre_ctx.src	\
         $(SRC_PROC_CC_DIR)/krst_ctx.src	\
         $(SRC_PROC_CC_DIR)/kswi_ctx.src	\
         $(SRC_PROC_CC_DIR)/kint_hdr.src	\
         $(SRC_PROC_CC_DIR)/kexc_hdr.src



# %jp{コンパイラ依存定義}%en{definitions of compiler dependence}
include $(KERNEL_MAKINC_DIR)/shc_d.inc


# %jp{カーネル共通ソースの追加}%en{definitions of kernel source files}
include $(KERNEL_MAKINC_DIR)/knlsrc.inc



# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}$en{clean}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst

# depend
.PHONY : depend
clean: makelib_clean

# source file copy
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules of library}
include $(KERNEL_MAKINC_DIR)/makelib.inc


# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
include $(KERNEL_MAKINC_DIR)/shc_r.inc


# %jp{カーネル依存関係読込み}%en{dependence}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file
