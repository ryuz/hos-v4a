# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample

# %jp{ツール定義}
GCC_ARCH   ?= mn10300-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy

# %jp{ディレクトリ}
OS_DIR            = ../../../../..
KERNEL_DIR        = $(OS_DIR)/kernel
KERNEL_CFGRTR_DIR = $(OS_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/mn103/mn103s/gcc
APLFW_DIR         = $(OS_DIR)/aplfw
APLFW_INC_DIR     = $(APLFW_DIR)
APLFW_BUILD_DIR   = $(APLFW_DIR)/build/mn103/mn103s/gcc
OBJS_DIR          = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-mn103s


# %jp{ライブラリ定義}
APLFW_LIB = $(APLFW_BUILD_DIR)/hosaplfw.a


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
APLFW_LIB = $(APLFW_BUILD_DIR)/hosaplfwdbg.a
endif


# %jp{メモリマップ}
LINK_SCRIPT = link.lds


# %jp{フラグ設定}
CFLAGS  =
AFLAGS  =
LNFLAGS = -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).elf
TARGET_MOT = $(TARGET).mot
TARGET_HEX = $(TARGET).hex

# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS += $(APLFW_INC_DIR)

# %jp{ソースディレクトリ}
SRC_DIRS += . ..


# %jp{アセンブラファイルの追加}
ASRCS += ./crt0.S


# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../boot.c			\
         ../ostimer.c

# %jp{ライブラリファイルの追加}
LIBS += $(APLFW_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: make_subprj makeexe_all $(TARGET_EXE) $(TARGET_MOT) $(TARGET_HEX)


.PHONY : make_subprj
make_subprj:
	$(MAKE) -C $(APLFW_BUILD_DIR)

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

.PHONY : depend
depend: makeexe_depend

.PHONY : mostlyclean
mostlyclean: clean
	$(MAKE) -C $(APLFW_BUILD_DIR) clean

.PHONY : mostlydepend
mostlydepend: depend
	$(MAKE) -C $(APLFW_BUILD_DIR) depend


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

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
