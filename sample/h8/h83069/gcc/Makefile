# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# %jp{ターゲット名}
TARGET ?= sample


# %jp{ツール定義}
GCC_ARCH   ?= h8300-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy


# %jp{ディレクトリ定義}
OS_DIR            = ../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/h8/h8300ha/gcc
OBJS_DIR          = objs_$(TARGET)

# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


ifeq ($(MEMMAP),ram)
# %jp{RAM実行(モニタプログラム利用を想定)}
TARGET := $(TARGET)_ram
LINKER_SCRIPT ?= link_ram.lds
C_DEFS        += _RAM
else
# %jp{ROM焼きする場合}
LINKER_SCRIPT ?= link_rom.lds
C_DEFS        += 
endif


# %jp{フラグ設定}
CFLAGS  = -mh
AFLAGS  = -mh
LNFLAGS = -mh -nostartfiles -T$(LINKER_SCRIPT) -Wl,-Map,$(TARGET).map


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-h8300ha

# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)


# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc


# --------------------------------------
#  %jp{ファイル設定}
# --------------------------------------

# %jp{ソースディレクトリ}
SRC_DIRS += . ..

# %jp{アセンブラファイルの追加}
ASRCS += ./vector.S			\
         ./crt0.S

# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
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
all: makeexe_all $(TARGET_EXE) $(TARGET_MOT)


.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_MOT) $(OBJS) ../kernel_cfg.c ../kernel_id.h


.PHONY : mostlyclean
mostlyclean: clean clean_kernel


../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{gcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc


# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

