# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------

# KERNEL_DEBUG ?= Yes
# DEBUG        ?= Yes

# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲット名}%en{target name}
TARGET ?= sample

RISCV_ARCH ?= riscv64

# %jp{ツール定義}%en{tools}
GCC_ARCH    ?= $(RISCV_ARCH)-unknown-elf-
CMD_CC      ?= $(GCC_ARCH)gcc
CMD_ASM     ?= $(GCC_ARCH)gcc
CMD_LINK    ?= $(GCC_ARCH)gcc
CMD_OBJCNV  ?= $(GCC_ARCH)objcopy
CMD_OBJDUMP ?= $(GCC_ARCH)objdump

# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= riscv
ARCH_CC   ?= gcc
EXT_EXE   ?= elf

ARCH_IRC  ?= riscv

# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_CFGRTR_DIR = $(TOP_DIR)/cfgrtr/build/gcc
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
KERNEL_BUILD_DIR  = $(KERNEL_DIR)/build/riscv/gcc

INC_IRC_DIR       = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)

# %jp{コンフィギュレータ定義}
KERNEL_CFGRTR = $(KERNEL_CFGRTR_DIR)/h4acfg-$(ARCH_NAME)


# %jp{共通定義読込み}%jp{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{リンカスクリプト}%en{linker script}
LINK_SCRIPT = ram.lds




# %jp{パス設定}%en{add source directories}
INC_DIRS += . .. $(INC_IRC_DIR)
SRC_DIRS += . ..


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = -mcmodel=medany
CFLAGS  = -mcmodel=medany
LNFLAGS = -mcmodel=medany -nostartfiles -Wl,-Map,$(TARGET).map,-T$(LINK_SCRIPT)


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{実行ファイル生成用設定読込み}%en{definitions for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_d.inc


# %jp{出力ファイル名}%en{output files}
TARGET_EXE = $(TARGET).$(EXT_EXE)
TARGET_MOT = $(TARGET).$(EXT_MOT)
TARGET_HEX = $(TARGET).$(EXT_HEX)
TARGET_BIN = $(TARGET).$(EXT_BIN)



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += ./crt0.S
ASRCS += ./time.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += ../main.c
CSRCS += ../kernel_cfg.c
CSRCS += ../sample.c
CSRCS += ../uart.c
CSRCS += ../ostimer.c



# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: kernel_make makeexe_all $(TARGET_EXE)
	$(CMD_OBJDUMP) -S $(TARGET_EXE) > $(TARGET)_disas.txt

.PHONY : run
run: $(TARGET_EXE)
	qemu-system-$(RISCV_ARCH) -bios none -machine virt -m 32M -nographic -serial mon:stdio  -kernel $(TARGET_EXE)

.PHONY : run-debug
run-debug: $(TARGET_EXE)
	qemu-system-$(RISCV_ARCH) -bios none -machine virt -m 32M -nographic -serial mon:stdio -S -gdb tcp::1234 -kernel $(TARGET_EXE)

run-asm: $(TARGET_EXE)
	qemu-system-$(RISCV_ARCH) -bios none -machine virt -m 32M -nographic -serial mon:stdio  -d in_asm -kernel $(TARGET_EXE)
# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makeexe_clean
	$(RM) -f $(TARGET_EXE) $(TARGET_EXE) $(OBJS) sample.bin 	\
	$(TARGET_MOT) $(TARGET_HEX) $(TARGET_BIN) $(TARGET)_disas.txt 	\
	$(TARGET).map							\
	../kernel_cfg.c ../kernel_id.h ../system.i
	$(RM) -f objs_$(TARGET)/*.o
	if [ -d objs_$(TARGET) ]; then					\
		rmdir objs_$(TARGET);					\
	fi;

# %jp{distクリーン}%en{distclean}
.PHONY : _makelib_clean
_makelib_clean:
	$(MAKE) -C $(KERNEL_BUILD_DIR) makelib_distclean

# %jp{distクリーン}%en{distclean}
.PHONY : distclean
distclean: mostlyclean _makelib_clean clean


# %jp{依存関係更新}%en{depend}
.PHONY : depend
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

# %jp{実行ファイル生成用設定読込み}%en{rules for exection file}
include $(KERNEL_MAKINC_DIR)/makexe_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

$(TARGET_EXE): $(LINK_SCRIPT)

$(OBJS_DIR)/sample.$(EXT_OBJ) : ../kernel_id.h



# end of file
