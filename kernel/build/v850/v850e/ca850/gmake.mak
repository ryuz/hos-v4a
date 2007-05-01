# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for ARM V4T (none IRC)
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
ARCH_PROC ?= v850/v850e
ARCH_IRC  ?= none
ARCH_CC   ?= ca850

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
AFLAGS  += -cnv850e
CFLAGS  += -cnv850e
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(HOSV4A_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-arm_v4t


# %jp{armcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc


# C言語ファイルの追加
CSRCS += 

# アセンブラファイルの追加
ASRCS += 


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
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc



# end of file