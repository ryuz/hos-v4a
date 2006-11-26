# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# %jp{ターゲット名}
TARGET ?= sample

# %jp{ツール定義}
GCC_SYS    ?= elf
CMD_CC     ?= h8300-$(GCC_SYS)-gcc
CMD_ASM    ?= h8300-$(GCC_SYS)-gcc
CMD_LINK   ?= h8300-$(GCC_SYS)-gcc
CMD_OBJCNV ?= h8300-$(GCC_SYS)-objcopy


# %jp{ディレクトリ定義}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/h8/h8300ha/gcc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


ifeq ($(RAM),Yes)
# %jp{RAM実行(モニタプログラム利用を想定)}
TARGET := $(TARGET)_ram
LINKER_SCRIPT ?= link_ram.x
C_DEFS        += _RAM
else
# %jp{ROM焼きする場合}
LINKER_SCRIPT ?= link_rom.x
C_DEFS        += 
endif


# %jp{フラグ設定}
CFLAGS  = -mh
AFLAGS  = -mh
LNFLAGS = -mh -nostartfiles -T$(LINKER_SCRIPT) -Wl,-Map,sample.map


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-h8300ha

# 出力ファイル名
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_ASC = $(TARGET).$(EXT_ASC)


# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_def.inc

# ソースディレクトリ
SRC_DIRS += . ..

# アセンブラファイルの追加
ASRCS += ./crt0.S

# %jp{C言語ファイルの追加}
CSRCS += ./vector.c			\
         ../kernel_cfg.c	\
         ../main.c			\
         ../sample.c		\
         ../ostimer.c		\
         ../sci1.c

# %jp{ライブラリの追加}
LIBS  +=


# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: makeexe_all $(TARGET_EXE) $(TARGET_ASC)

clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_ASC) $(OBJS) ../kernel_cfg.c ../kernel_id.h

../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h

mostlyclean: clean clean_kernel



# %jp{ライブラリ生成用設定読込み}
include $(KERNEL_MAKINC_DIR)/makeexe.inc

# %jp{shc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_rul.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

