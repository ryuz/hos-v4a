# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  
# 
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET ?= sample

# %jp{ディレクトリ}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)/build/arm/at91/armcc
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)/build/arm/arm_v4t/armcc
OBJS_DIR           = objs_$(TARGET)


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-at91


# %jp{ライブラリ定義}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.a


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfwdbg.a
endif


# %jp{カーネルフックの設定}
KERNEL_HOK_TSK = Yes
KERNEL_HOK_ISR = Yes


# %jp{フラグ設定}
CFLAGS  += --cpu=ARM7TDMI --apcs=inter --thumb
AFLAGS  += --cpu=ARM7TDMI --apcs=inter --thumb
LNFLAGS += --ro_base=0x20000000 --first=vectors.o\(Init\) --entry=0x20000000


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).axf
TARGET_MOT = $(TARGET).mot
TARGET_HEX = $(TARGET).hex


# %jp{実行ファイル生成用の設定読込み}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc

# %jp{armcc用の設定読込み}
include $(KERNEL_MAKINC_DIR)/armcc_d.inc


# %jp{インクルードディレクトリ}
INC_DIRS += $(HOSAPLFW_INC_DIR)

# %jp{ソースディレクトリ}
SRC_DIRS += . ..


# %jp{アセンブラファイルの追加}
ASRCS += ./vectors.s		\
         ./startup.s		\
         ./uish.s


# %jp{C言語ファイルの追加}
CSRCS += ../kernel_cfg.c	\
         ../main.c			\
         ../boot.c			\
         ../ostimer.c

# %jp{ライブラリファイルの追加}
LIBS += $(HOSAPLFW_LIB)



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: make_libs makeexe_all $(TARGET_EXE) $(TARGET_MOT) $(TARGET_HEX)

.PHONY : make_libs
make_libs:
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


../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h



# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{armcc用のルール定義読込み}
include $(KERNEL_MAKINC_DIR)/armcc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
