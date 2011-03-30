# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# %jp{ターゲット名}
TARGET ?= sample

# %jp{ツール定義}
GCC_ARCH   ?= arm-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy


# %jp{ディレクトリ定義}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/arm/aduc7000/gcc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc

# デバッグ版のターゲット名変更
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
endif

# リンカスクリプト
LINK_SCRIPT = link.lds


# %jp{フラグ設定}
CFLAGS  = -mcpu=arm7tdmi -mthumb-interwork
AFLAGS  = -mcpu=arm7tdmi -mthumb-interwork
LNFLAGS = -mcpu=arm7tdmi -mthumb-interwork -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-aduc7000

# 出力ファイル名
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)
TARGET_HEX = $(TARGET).$(EXT_HEX)


# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# ソースディレクトリ
SRC_DIRS += . ..

# アセンブラファイルの追加
ASRCS += ./vectors.S		\
         ./crt0.S

# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c		\
         ../uart.c



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_MOT) $(TARGET_HEX)

clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{gcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

