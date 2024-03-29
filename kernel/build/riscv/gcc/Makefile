# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Philips LPC2000 family
#
# Copyright (C) 1998-2008 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a

RISCV_ARCH ?= riscv64

# %jp{ツール定義}%en{tools}
GCC_ARCH ?= $(RISCV_ARCH)-unknown-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= riscv
ARCH_PROC ?= riscv
ARCH_IRC  ?= riscv
ARCH_CC   ?= gcc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
INC_PROC_DIR      = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR       = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR      = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR   = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR       = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR    = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)
CFGRTR_DIR        = $(TOP_DIR)/cfgrtr/build/gcc


# %jp{コンフィギュレータ定義}%en{kernel configurator}
CFGRTR = h4acfg-$(ARCH_NAME)


# %jp{カーネル指定}%en{kernel flag}
KERNEL = Yes


# %jp{共通定義読込み}%en{common setting}
include $(KERNEL_MAKINC_DIR)/common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS += $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS += $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_CC_DIR) $(SRC_IRC_DIR) $(SRC_IRC_CC_DIR)


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = -mcmodel=medany
CFLAGS  = -mcmodel=medany
ARFLAGS =


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc

# %jp{オフセットファイル生成用設定読込み}%en{definitions for register offsets}
include $(KERNEL_MAKINC_DIR)/asmoffgcc_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/mhartid.S
ASRCS += $(SRC_IRC_CC_DIR)/clint_mip.S
ASRCS += $(SRC_IRC_CC_DIR)/clint_mie.S
# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_IRC_DIR)/kini_irc.c
CSRCS += $(SRC_IRC_DIR)/kexe_irc.c
CSRCS += $(SRC_IRC_DIR)/ena_int.c
CSRCS += $(SRC_IRC_DIR)/dis_int.c
CSRCS += $(SRC_IRC_DIR)/vclr_int.c
CSRCS += $(SRC_IRC_DIR)/clint_ini_irc.c
CSRCS += $(SRC_IRC_DIR)/clint_exe_irc.c
CSRCS += $(SRC_IRC_DIR)/clint_ena_int.c
CSRCS += $(SRC_IRC_DIR)/clint_dis_int.c
CSRCS += $(SRC_IRC_DIR)/clint_clr_int.c
CSRCS += $(SRC_IRC_DIR)/plic_ini_irc.c
CSRCS += $(SRC_IRC_DIR)/plic_exe_irc.c
CSRCS += $(SRC_IRC_DIR)/plic_ena_int.c
CSRCS += $(SRC_IRC_DIR)/plic_dis_int.c
CSRCS += $(SRC_IRC_DIR)/plic_get_imsk.c
CSRCS += $(SRC_IRC_DIR)/plic_chg_imsk.c
CSRCS += $(SRC_IRC_DIR)/plic_clr_int.c
CSRCS += $(SRC_IRC_DIR)/plic_cfg_int.c
# %jp{カーネル共通ソースの追加}%en{kernel common sources}
include $(KERNEL_MAKINC_DIR)/knlsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
.PHONY : all
all: makelib_all
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}%en{clean}
.PHONY : clean
clean: makelib_clean
	$(MAKE) -C $(CFGRTR_DIR) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(RM) -f *.lst
	$(RM) -f $(INC_PROC_DIR)/regoff.h

# %jp{クリーン}%en{clean}
.PHONY : distclean
distclean: makelib_distclean clean


# %jp{依存関係更新}%en{make depend}
.PHONY : depend
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
include $(KERNEL_MAKINC_DIR)/maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_r.inc




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}{dependency list of kernel sources}
include $(KERNEL_MAKINC_DIR)/knldep.inc

# %jp{依存関係ファイル生成前にオフセットファイルを生成}{Generate offset-file before dependency generation}
$(DEPEND_FILE) : $(INC_PROC_DIR)/regoff.h

# %jp{オフセットファイルの依存関係定義}{dependency of the processor register offset file}
$(INC_PROC_DIR)/regoff.h: $(SRC_PROC_DIR)/regoff.c $(SRC_PROC_DIR)
	-$(CMD_MKDIR) $(OBJS_DIR)
	$(call _bld_gmk_asmoff_create_depend,$@,$<)



# end of file
