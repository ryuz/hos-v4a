# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for PC/AT
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

#KERNEL_DEBUG ?= Yes
#DEBUG        ?= Yes
#NO_VGA ?= Yes

# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample


# %jp{ツール定義}%en{tools}
GCC_ARCH    ?= i386-elf-
CMD_CC      ?= $(GCC_ARCH)gcc
CMD_ASM     ?= $(GCC_ARCH)gcc
CMD_LINK    ?= $(GCC_ARCH)gcc
CMD_OBJCNV  ?= $(GCC_ARCH)objcopy
CMD_OBJDUMP ?= $(GCC_ARCH)objdump
CMD_BOCHS   ?= bochs
CMD_QEMU    ?= qemu-system-i386

# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= pcat
ARCH_CC   ?= gcc

ARCH_PROC ?= ia32/i386


# %jp{ディレクトリ定義}
TOP_DIR             = ../../../..
KERNEL_DIR          = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR   = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR   = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR    = $(KERNEL_DIR)/build/ia32/pcat/gcc

INC_PROC_DIR        = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)

APLFW_STRFMT_DIR    = $(TOP_DIR)/aplfw/library/algorithm/stringformat

# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)

# %jp{共通定義読込み}%jp{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{リンカスクリプト}%en{linker script}
LINK_SCRIPT = link.lds


# %jp{パス設定}%en{add source directories}
INC_DIRS += . .. $(INC_PROC_DIR)
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

# %jp{QEMUのオプション}
QEMU_COMMON_OPTS ?= -boot a \
	-drive file=$(TARGET_IMG),format=raw,if=floppy,media=disk,readonly=off,index=0 \
	-serial mon:stdio

# %jp{QEMUのVGAコンソール使用有無}
ifeq ($(NO_VGA),Yes)
QEMU_NOGRAPHIC =  -nographic
else
QEMU_NOGRAPHIC =
endif

# %jp{QEMUとGDBを使用したリモートデバッグ}
QEMU_DBG_OPT =  -gdb tcp::1234 -S



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./crt0.S


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ../main.c
CSRCS += ../kernel_cfg.c
CSRCS += ../sample.c
CSRCS += ../ostimer.c
CSRCS += ../console.c
CSRCS += ../exception.c

# debug
SRC_DIRS += $(APLFW_STRFMT_DIR)
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_decimal.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_format.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_formatstring.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_formatstringv.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_formatv.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_hexadecimal.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_nibble.c
CSRCS += $(APLFW_STRFMT_DIR)/stringformat_string.c



# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: kernel_make makeexe_all ipl.bin $(TARGET_BIN) $(TARGET_HEX) $(TARGET_MOT) $(TARGET).img
	$(CMD_OBJDUMP) -SD $(TARGET_EXE) > $(TARGET)_disas.txt

# %jp{クリーン}%en{clean}
clean: makeexe_clean
	rm -f $(TARGET_BIN) $(TARGET_HEX) $(TARGET_MOT) $(TARGET).img $(OBJS) ../kernel_cfg.c ../kernel_id.h

# %jp{依存関係更新}%en{depend}
depend: makeexe_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makeexe_srccpy

# %jp{カーネルごとクリーン}%en{mostlyclean}
.PHONY : mostlyclean
mostlyclean: clean kernel_clean

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

# %jP{Bochsによる実行}%en{Run a program with Bochs}
.PHONY : bochs
bochs: $(TARGET_IMG)
	$(CMD_BOCHS) "floppya: 1_44=$(TARGET_IMG), status=inserted" "boot: a"

# %jP{QEmuによる実行}%en{Run a program with QEmu}
.PHONY : qemu
qemu: $(TARGET_IMG)
	$(CMD_QEMU) $(QEMU_COMMON_OPTS) $(QEMU_NOGRAPHIC)

# %jP{QEmuとGDBによるデバッグ実行}%en{Debug a program with QEmu and GDB}
.PHONY : qemu-debug
qemu-debug: $(TARGET_IMG)
	$(CMD_QEMU) $(QEMU_COMMON_OPTS) $(QEMU_NOGRAPHIC) $(QEMU_DBG_OPT)

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
