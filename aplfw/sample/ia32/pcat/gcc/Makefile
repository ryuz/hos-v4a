# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for PC/AT
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample


# %jp{ツール定義}%en{tools}
GCC_ARCH   ?= i386-elf-
CMD_CC     ?= $(GCC_ARCH)gcc
CMD_ASM    ?= $(GCC_ARCH)gcc
CMD_LINK   ?= $(GCC_ARCH)gcc
CMD_OBJCNV ?= $(GCC_ARCH)objcopy


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= pcat
ARCH_CC   ?= gcc


# %jp{ディレクトリ定義}
TOP_DIR            = ../../../../..
KERNEL_DIR         = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR  = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR  = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR   = $(KERNEL_DIR)/build/ia32/pcat/gcc
HOSAPLFW_DIR       = $(TOP_DIR)/aplfw
HOSAPLFW_INC_DIR   = $(HOSAPLFW_DIR)
HOSAPLFW_BUILD_DIR = $(HOSAPLFW_DIR)/build/ia32/i386/gcc

# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{ライブラリ定義}%en{libraries}
HOSAPLFW_LIB = $(HOSAPLFW_BUILD_DIR)/hosaplfw.$(EXT_LIB)


# %jp{リンカスクリプト}%en{linker script}
LINK_SCRIPT = link.lds


# %jp{パス設定}%en{add source directories}
INC_DIRS += . .. $(HOSAPLFW_INC_DIR)
SRC_DIRS += . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = -march=i386
CFLAGS  = -march=i386
LNFLAGS = -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)
TARGET_HEX = $(TARGET).$(EXT_HEX)
TARGET_BIN = $(TARGET).$(EXT_BIN)
TARGET_IMG = $(TARGET).img



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./crt0.S


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ../main.c
CSRCS += ../kernel_cfg.c
CSRCS += ../boot.c
CSRCS += ../ostimer.c


# %jp{ライブラリの追加}%en{libraries}
LIBS := $(HOSAPLFW_LIB) $(LIBS)




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: make_subprject kernel_make makeexe_all ipl.bin $(TARGET_BIN) $(TARGET_HEX) $(TARGET_MOT) $(TARGET).img

# %jp{サブプロジェクトメイク}%en{make subproject}
.PHONY : make_subprject
make_subprject:
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makeexe_clean
	rm -f $(TARGET_BIN) $(TARGET_HEX) $(TARGET_MOT) $(TARGET).img $(OBJS) ../kernel_cfg.c ../kernel_id.h

# %jp{サブプロジェクトを含めたクリーン}%en{mostlyclean}
.PHONY : mostlyclean
mostlyclean: clean kernel_clean
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) clean

# %jp{依存関係更新}%en{depend}
.PHONY : depend
depend: makeexe_depend

# %jp{サブプロジェクトを含めた依存関係更新}%en{mostlydepend}
.PHONY : mostlydepend
mostlydepend: depend kernel_depend
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) depend

# %jp{ソース一括コピー}%en{source files copy }
.PHONY : srccpy
srccpy: makeexe_srccpy

# %jp{サブプロジェクトを含めたソース一括コピー}%en{mostly source files copy}
.PHONY : mostlysrccpy
mostlysrccpy: srccpy srccpy
	$(MAKE) -C $(KERNEL_BUILD_DIR) srccpy
	$(MAKE) -C $(HOSAPLFW_BUILD_DIR) srccpy

# %jp{コンフィギュレータ実行}%en{configurator}
../kernel_cfg.c ../kernel_id.h: ../system.cfg $(KERNEL_CFGRTR)
	cpp -E ../system.cfg ../system.i
	$(KERNEL_CFGRTR) ../system.i -c ../kernel_cfg.c -i ../kernel_id.h


# %jp{IPL部の生成}
ipl.bin: $(OBJS_DIR)/ipl.o
	$(GCC_ARCH)ld -Ttext=0x0000 $(OBJS_DIR)/ipl.o -o ipl.out
	$(CMD_OBJCNV) -O binary ipl.out ipl.bin

# %jP{フロッピーディスクイメージ生成}%en{FD image}
$(TARGET).img: ipl.bin $(TARGET_BIN)
	./fd_img.pl $(TARGET).img ipl.bin $(TARGET_BIN)

.PHONY : bochs
bochs: $(TARGET).img
	bochs "floppya: 1_44=$(TARGET).img, status=inserted" "boot: a"


# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(TARGET_EXE): $(LINK_SCRIPT)
$(OBJS_DIR)/sample.$(EXT_OBJ): ../sample.c ../kernel_id.h


# end of file

