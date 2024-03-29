# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for i386 processor
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= i386-elf-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= i386
ARCH_PROC ?= ia32/i386
ARCH_IRC  ?= simple
ARCH_CC   ?= gcc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ../../../../..
KERNEL_DIR        = $(TOP_DIR)/kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)/build/common/gmake
INC_PROC_DIR      = $(KERNEL_DIR)/include/arch/proc/$(ARCH_PROC)
INC_IRC_DIR       = $(KERNEL_DIR)/include/arch/irc/$(ARCH_IRC)
SRC_PROC_DIR      = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)
SRC_PROC_CC_DIR   = $(KERNEL_DIR)/source/arch/proc/$(ARCH_PROC)/$(ARCH_CC)
SRC_IRC_DIR       = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)
SRC_IRC_CC_DIR    = $(KERNEL_DIR)/source/arch/irc/$(ARCH_IRC)/$(ARCH_CC)
CFGRTR_DIR        = $(TOP_DIR)/cfgrtr/build/$(ARCH_CC)
TOOLS_PROC_DIR    = $(KERNEL_DIR)/build/$(ARCH_PROC)/$(ARCH_CC)


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
AFLAGS  = -march=i386
CFLAGS  = -march=i386
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
ASRCS += $(SRC_PROC_CC_DIR)/ksta_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kexc_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/kint_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/koutpb.S
ASRCS += $(SRC_PROC_CC_DIR)/koutph.S
ASRCS += $(SRC_PROC_CC_DIR)/koutpw.S
ASRCS += $(SRC_PROC_CC_DIR)/kinpb.S
ASRCS += $(SRC_PROC_CC_DIR)/kinph.S
ASRCS += $(SRC_PROC_CC_DIR)/kinpw.S
ASRCS += $(SRC_PROC_CC_DIR)/klidt.S
ASRCS += $(SRC_PROC_CC_DIR)/kbld_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/ktrp_vec.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/val_int.c
CSRCS += $(SRC_PROC_DIR)/kini_prc.c

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
	$(RM) -f $(INC_PROC_DIR)/regoff.h $(SRC_PROC_CC_DIR)/ktrp_vec.S

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
$(DEPEND_FILE) : $(INC_PROC_DIR)/regoff.h $(SRC_PROC_CC_DIR)/ktrp_vec.S

# %jp{オフセットファイルの依存関係定義}{dependency of the processor register offset file}
$(INC_PROC_DIR)/regoff.h: $(SRC_PROC_DIR)/regoff.c $(SRC_PROC_DIR)
	-$(CMD_MKDIR) $(OBJS_DIR)
	$(call _bld_gmk_asmoff_create_depend,$@,$<)

# %jp{ベクタエントリファイルの依存関係定義}{dependency of the vector entry file}
$(SRC_PROC_CC_DIR)/ktrp_vec.S   : $(TOOLS_PROC_DIR)/gen-vec.py
	$(CMD_RM) -f $@
	$(TOOLS_PROC_DIR)/gen-vec.py ktrp_vec.S > $@

# end of file
