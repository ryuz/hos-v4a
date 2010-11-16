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
TARGET = libhosv4a


# %jp{アーキテクチャ定義}%en{architecture}
ARCH_NAME = lpc2000
ARCH_PROC = arm\arm_v4t
ARCH_IRC  = arm\lpc2000
ARCH_CC   = armcc


# %jp{ディレクトリ定義}%en{directories}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
INC_PROC_DIR      = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR       = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR      = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_CC_DIR   = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR       = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_CC_DIR    = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)
CFGRTR_DIR        = $(TOP_DIR)\cfgrtr\build\msc


# %jp{コンフィギュレータ定義}%en{kernel configurator}
CFGRTR = h4acfg-$(ARCH_NAME)


# %jp{カーネル指定}%en{kernel flag}
KERNEL = Yes


# %jp{共通定義読込み}%en{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)



# %jp{オプションフラグ}%en{option flags}
AFLAGS  = --cpu=ARM7TDMI --apcs=inter --thumb
CFLAGS  = --cpu=ARM7TDMI --apcs=inter --thumb
ARFLAGS = 



# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc




# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kcre_ctx.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kdis_int.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kena_int.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\krst_ctx.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kswi_ctx.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kwai_int.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kirq_hdr.s
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kfiq_hdr.s


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\val_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\kini_irc.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\kexe_irc.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\ena_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\dis_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\vclr_int.c


# %jp{オブジェクトファイルの追加}%en{object files}
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kirq_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kfiq_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kini_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kexe_irc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\vclr_int.$(EXT_OBJ)


# %jp{カーネル共通ソースの追加}%en{kernel common sources}
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: mkdir_objs srcobjcp makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)

# %jp{クリーン}%en{clean}
clean: makelib_clean
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean
	$(CMD_CD) $(MAKEDIR)

# %jp{依存関係更新}%en{make depend}
depend: makelib_depend

# %jp{ソース一括コピー}%en{source files copy}
.PHONY : srccpy
srccpy: makelib_srccpy


# %jp{ライブラリ生成用設定読込み}%en{rules for library}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jp{コンパイラ依存ルール}%en{rules of compiler dependence}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc


# %jp{コピー}%en{source files copy}
srcobjcp:
	$(CMD_CP) $(SRC_PROC_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(SRC_PROC_CC_DIR)\*.* $(OBJS_DIR)
	$(CMD_CP) $(SRC_IRC_DIR)\*.* $(OBJS_DIR)




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}{dependency list of kernel sources}
!include $(KERNEL_MAKINC_DIR)\knldep.inc


$(OBJS_DIR)\val_int.o	:	$(OBJS_DIR)\val_int.c
$(OBJS_DIR)\kini_irc.o	:	$(OBJS_DIR)\kini_irc.c
$(OBJS_DIR)\kexe_irc.o	:	$(OBJS_DIR)\kexe_irc.c
$(OBJS_DIR)\ena_int.o	:	$(OBJS_DIR)\ena_int.c
$(OBJS_DIR)\dis_int.o	:	$(OBJS_DIR)\dis_int.c
$(OBJS_DIR)\vclr_int.o	:	$(OBJS_DIR)\vclr_int.c
$(OBJS_DIR)\kcre_ctx.o	:	$(OBJS_DIR)\kcre_ctx.s
$(OBJS_DIR)\kdis_int.o	:	$(OBJS_DIR)\kdis_int.s
$(OBJS_DIR)\kena_int.o	:	$(OBJS_DIR)\kena_int.s
$(OBJS_DIR)\kirq_hdr.o	:	$(OBJS_DIR)\kirq_hdr.s
$(OBJS_DIR)\kfiq_hdr.o	:	$(OBJS_DIR)\kfiq_hdr.s
$(OBJS_DIR)\krst_ctx.o	:	$(OBJS_DIR)\krst_ctx.s
$(OBJS_DIR)\kswi_ctx.o	:	$(OBJS_DIR)\kswi_ctx.s
$(OBJS_DIR)\kwai_int.o	:	$(OBJS_DIR)\kwai_int.s



# end of file
