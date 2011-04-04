# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for sh2-sample
#
# Copyright (C) 1998-2006 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample


# %jp{ツール定義}%jp{tools}
GCC_ARCH   ?= sh-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)/build/sh/sh2/gcc
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)/build/sh/sh2/gcc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-sh2


# %jp{カーネルフックの設定}%en{kernel hook}
KERNEL_HOK_TSK = Yes
KERNEL_HOK_ISR = Yes


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{ライブラリ定義}%en{library}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)


# %jp{デバッグ版の定義変更}%en{Debug}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.$(EXT_LIB)
endif

# %jp{メモリマップ}%en{memory map}
ifeq ($(MEMMAP),ext)
# %jp{外部メモリ(モニタプログラム利用を想定)}
TARGET     := $(TARGET)ext
LINK_SCRIPT = link_ext.lds
else
# %jp{ROM実行}%en{rom}
LINK_SCRIPT = link_rom.lds
endif


# %jp{オプションフラグ}%en{option flags}
CFLAGS  = -m2
AFLAGS  = -m2
LNFLAGS = -m2 -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{出力ファイル名}%en{output file}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)

# %jp{パス設定}%en{add source directories}
INC_DIRS += $(HOSAPLFW_INC_DIR)
SRC_DIRS += . ..

# %jp{ライブラリの追加}
LIBS  += $(HOSAPLFW_LIB)



# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{gcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/gcc_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./vector.S
ASRCS += ./crt0.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ../kernel_cfg.c
CSRCS += ../main.c
CSRCS += ../boot.c
CSRCS += ../ostimer.c



# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

.PHONY : all
all: kernel_make make_subprj makeexe_all $(TARGET_EXE) $(TARGET_MOT)

.PHONY : make_subprj
make_subprj:
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR)

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

.PHONY : mostlyclean
mostlyclean: clean kernel_clean
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) clean

.PHONY : depend
depend: makeexe_depend

.PHONY : mostlydepend
mostlydepend: depend kernel_depend
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) depend

.PHONY : srccpy
srccpy: makeexe_srccpy
	$(MAKE) -C $(KERNEL_BUILD_DIR) srccpy
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) srccpy

../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h

$(KERNEL_CFGRTR) : kernel_make


# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc


# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(TARGET_EXE): $(LINK_SCRIPT)
$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

