# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2011 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample


# %jp{ツール定義}%en{tools}
GCC_ARCH     ?= mips-elf-
CMD_CC       ?= $(GCC_ARCH)gcc
CMD_ASM      ?= $(GCC_ARCH)gcc
CMD_LINK     ?= $(GCC_ARCH)gcc
CMD_OBJCNV   ?= $(GCC_ARCH)objcopy


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = $(HOME)/hos-v4a
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/mips/jelly/gcc
APLFW_DIR         = $(TOP_DIR)/aplfw
APLFW_INC_DIR     = $(APLFW_DIR)
APLFW_BUILD_DIR   = $(APLFW_DIR)/build/mips/jelly/gcc


# %jp{カーネル設定}%en{set kernel option}
KERNEL_HOK_TSK = Yes
KERNEL_HOK_ISR = Yes


# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-jelly


# %jp{共通定義読込み}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{ライブラリ定義}
APLFW_LIB = $(APLFW_BUILD_DIR)/hosaplfw.a


# %jp{デバッグ版の定義変更}
ifeq ($(DEBUG),Yes)
TARGET := $(TARGET)dbg
APLFW_LIB = $(APLFW_BUILD_DIR)/hosaplfwdbg.a
endif


# %jp{メモリマップ}
ifeq ($(MEMMAP),rom)
# %jp{内蔵ROM}
TARGET       := $(TARGET)_rom
LINK_SCRIPT = rom.lds
else
# %jp{内蔵RAM}
LINK_SCRIPT = ram.lds
endif

# loader COM port
COMPORT ?= 1


# %jp{フラグ設定}
CFLAGS  = -march=mips1 -msoft-float -G 0
AFLAGS  = -march=mips1 -msoft-float -G 0
LNFLAGS = -march=mips1 -msoft-float -G 0 -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{出力ファイル名}
TARGET_EXE = $(TARGET).elf
TARGET_MOT = $(TARGET).mot
TARGET_HEX = $(TARGET).hex
TARGET_BIN = $(TARGET).bin


# %jp{実行ファイル生成用設定読込み}
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
CSRCS += ../kernel_cfg.c
CSRCS += ../main.c
CSRCS += ../boot.c
CSRCS += ../ostimer.c
CSRCS += memcpy.c
CSRCS += strlen.c


# %jp{ライブラリファイルの追加}
LIBS := $(APLFW_LIB) $(LIBS) -lc



# --------------------------------------
#  %jp{ルール}
# --------------------------------------

.PHONY : all
all: kernel_make make_subprj makeexe_all $(TARGET_EXE) $(TARGET_MOT) $(TARGET_HEX) $(TARGET_BIN)

.PHONY : run
run: $(TARGET_BIN)
	jelly_loader -c $(COMPORT) -r $(TARGET_BIN)


.PHONY : make_subprj
make_subprj:
	$(MAKE) -C $(APLFW_BUILD_DIR)

.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) ../kernel_cfg.c ../kernel_id.h

.PHONY : depend
depend: makeexe_depend

.PHONY : mostlyclean
mostlyclean: clean kernel_clean
	$(MAKE) -C $(APLFW_BUILD_DIR) clean

.PHONY : mostlydepend
mostlydepend: depend
	$(MAKE) -C $(APLFW_BUILD_DIR) depend


../kernel_cfg.c ../kernel_id.h: ../system.cfg
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


$(TARGET_EXE): $(LINK_SCRIPT)


# %jp{実行ファイル生成用ルール読込み}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{gcc用のルール定ルール込み}
include $(KERNEL_MAKINC_DIR)/gcc_r.inc



# --------------------------------------
#  %jp{依存関係}
# --------------------------------------

$(OBJS_DIR)/sample.obj: ../sample.c ../kernel_id.h


# end of file
