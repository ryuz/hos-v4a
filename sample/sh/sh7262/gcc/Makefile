# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2010 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}
TARGET ?= sample


# %jp{ツール定義}
GCC_ARCH   ?= sh-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= sh2a-fpu
ARCH_CC   ?= gcc


# %jp{ディレクトリ定義}
TOP_DIR           = ../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/sh/$(ARCH_NAME)/$(ARCH_CC)


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{リンカスクリプト}%en{linker script}
LINK_SCRIPT = rom.lds

# default ram
MEMMAP ?= ram

ifeq ($(MEMMAP),ram)
# %jp{RAM実行(モニタプログラム利用を想定)}
LINK_SCRIPT = ram.lds
TARGET     := $(TARGET)_ram
endif


# %jp{パス設定}%en{add source directories}
INC_DIRS += . ..
SRC_DIRS += . ..


# %jp{オプションフラグ}%en{option flags}
CFLAGS  = -m2
AFLAGS  = -m2
LNFLAGS = -m2 -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)
TARGETS    = $(TARGET_EXE) $(TARGET_MOT)


# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------


# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./vector.S
ASRCS += ./crt0.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ../kernel_cfg.c
CSRCS += ../main.c
CSRCS += ../sample.c
CSRCS += ../ostimer.c
CSRCS += ../sci1.c


# %jp{リンク制御対象制御}
#LINK_RENESASSCI = Yes



# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: kernel_make makeexe_all $(TARGETS)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGETS) $(OBJS) ../kernel_cfg.c ../kernel_id.h

# %jp{依存関係更新}%en{depend}
.PHONY : depend
depend: makeexe_depend


# %jp{カーネルごとクリーン}%en{mostlyclean}
.PHONY : mostlyclean
mostlyclean: clean kernel_clean


# %jp{コンフィギュレータ実行}%en{configurator}
../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

