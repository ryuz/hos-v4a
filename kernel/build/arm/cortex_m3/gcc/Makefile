# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Cortex-M3
#
# Copyright (C) 1998-2011 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{各種設定}%en{setting}
# --------------------------------------

# %jp{ターゲットライブラリ名}%en{target library name}
TARGET ?= libhosv4a


# %jp{ツール定義}%jp{tools}
GCC_ARCH ?= arm-none-eabi-
CMD_CC   ?= $(GCC_ARCH)gcc
CMD_ASM  ?= $(GCC_ARCH)gcc
CMD_LIBR ?= $(GCC_ARCH)ar


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME ?= cortex_m3
ARCH_PROC ?= arm/arm_v7m
ARCH_IRC  ?= none
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
AFLAGS  = -mcpu=cortex-m3 -mthumb
CFLAGS  = -mcpu=cortex-m3 -mthumb
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
include $(KERNEL_MAKINC_DIR)/$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
include $(KERNEL_MAKINC_DIR)/maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS += $(SRC_PROC_CC_DIR)/krst_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/knmi_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/khwf_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/kpnd_hdr.S
ASRCS += $(SRC_PROC_CC_DIR)/kdis_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kena_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kcre_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/krst_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kswi_ctx.S
ASRCS += $(SRC_PROC_CC_DIR)/kwai_int.S
ASRCS += $(SRC_PROC_CC_DIR)/kref_ctl.S

# %jp{C言語ファイルの追加}%en{C sources}
CSRCS += $(SRC_PROC_DIR)/ena_int.c
CSRCS += $(SRC_PROC_DIR)/dis_int.c
CSRCS += $(SRC_PROC_DIR)/vclr_int.c

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


$(OBJS_DIR)/val_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/kini_irc.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/kexe_irc.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/ena_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/dis_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)
$(OBJS_DIR)/vclr_int.$(EXT_OBJ)	:	$(COMMON_HEADERS)



# end of file
