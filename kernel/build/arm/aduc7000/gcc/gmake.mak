# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Analog Devices ADuC7000 series
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= libhosv4a

# %jp{アーキテクチャパス}
ARCH_PROC ?= arm/arm_v4t
ARCH_IRC  ?= arm/aduc7000
ARCH_CC   ?= gcc

# %jp{ツール定義}
GCC_ARCH ?= arm-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{ディレクトリ定義}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
OBJS_DIR          = objs_$(TARGET)


# %jp{カーネル指定}
KERNEL = Yes


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
AFLAGS  += -mcpu=arm7tdmi -mthumb-interwork
CFLAGS  += -mcpu=arm7tdmi -mthumb-interwork
ARFLAGS += 

# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
CFGRTR     = h4acfg-aduc7000


# C言語ファイルの追加
CSRCS += $(SRC_PROC_DIR)/val_int.c			\
         $(SRC_IRC_DIR)/kini_irc.c			\
         $(SRC_IRC_DIR)/kexe_irc.c			\
         $(SRC_IRC_DIR)/ena_int.c			\
         $(SRC_IRC_DIR)/dis_int.c


# アセンブラファイルの追加
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S		\
         $(SRC_PROC_CC_DIR)/kena_int.S		\
         $(SRC_PROC_CC_DIR)/kcre_ctx.S		\
         $(SRC_PROC_CC_DIR)/krst_ctx.S		\
         $(SRC_PROC_CC_DIR)/kswi_ctx.S		\
         $(SRC_PROC_CC_DIR)/kwai_int.S		\
         $(SRC_PROC_CC_DIR)/kund_hdr.S		\
         $(SRC_PROC_CC_DIR)/kswi_hdr.S		\
         $(SRC_PROC_CC_DIR)/kpre_hdr.S		\
         $(SRC_PROC_CC_DIR)/kabt_hdr.S		\
         $(SRC_PROC_CC_DIR)/kirq_hdr.S		\
         $(SRC_PROC_CC_DIR)/kfiq_hdr.S



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



# %jp{コンパイラ依存の設定読込み}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makelib.inc

# %jp{コンパイラ依存ルール定義読込み}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc

# %jp{カーネル依存関係読込み}
include $(KERNEL_MAKINC_DIR)/knldep.inc


# end of file
