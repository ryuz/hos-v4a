# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for LPC2214
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# ターゲット名
TARGET ?= libhosv4a


# ディレクトリ定義
HOSV4A_DIR        = ../../../../..
KERNEL_DIR        = $(HOSV4A_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{アーキテクチャ定義}
ARCH_PROC ?= arm/arm_v4t
ARCH_IRC  ?= none
ARCH_CC   ?= armcc

# %jp{アーキテクチャパス}
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
AFLAGS  += --cpu ARM7TDMI-S --apcs /interwork --thumb
CFLAGS  += --cpu ARM7TDMI-S --apcs /interwork
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(HOSV4A_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-lpc2214


# %jp{armccc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/armcc_def.inc



# C言語ファイルの追加
CSRCS += $(SRC_PROC_DIR)/val_int.c


# アセンブラファイルの追加
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.s		\
         $(SRC_PROC_CC_DIR)/kdis_int.s		\
         $(SRC_PROC_CC_DIR)/kena_int.s		\
         $(SRC_PROC_CC_DIR)/kirq_hdr.s		\
         $(SRC_PROC_CC_DIR)/krst_ctx.s		\
         $(SRC_PROC_CC_DIR)/kswi_ctx.s		\
         $(SRC_PROC_CC_DIR)/kwai_int.s



# カーネル共通ソースの追加
include $(KERNEL_MAKINC_DIR)/knlsrc.inc



# %jp{ALL}
.PHONY : all
all: makelib_all
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}
.PHONY : clean
clean: makelib_clean
	make -C $(CFGRTR_DIR) -f gmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst


# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc

# %jp{armcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/armcc_rul.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file
