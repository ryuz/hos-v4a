# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Win32 advanced mode
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
ARCH_NAME = win32
ARCH_PROC = win\win32
ARCH_IRC  = simple
ARCH_CC   = msc


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


# %jp{共通定義読込み}%jp{common setting}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{パス設定}%en{add source directories}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)


# %jp{オプションフラグ}%en{option flags}
AFLAGS  = 
CFLAGS  = 
ARFLAGS = 


# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kcre_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kdis_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kena_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kini_prc.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\krst_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\ksta_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kswi_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\kwai_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\val_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)\vsig_int.c


# %jp{オブジェクトファイル定義}
OBJS   = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\kini_prc.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\ksta_ctx.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS   = $(OBJS) $(OBJS_DIR)\vsig_int.$(EXT_OBJ)


# %jp{カーネル共通ソースの追加}%en{kernel common sources}
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc




# --------------------------------------
#  %jp{ルール定義}%en{rules}
# --------------------------------------

# %jp{ALL}%en{all}
all: mkdir_objs srcobjcp makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)
	$(CMD_CD) $(MAKEDIR)

# %jp{クリーン}%en{clean}
clean: makelib_clean
	-$(CMD_RM) *.lst
	-$(CMD_RM) $(OBJS_DIR)\*.*
	cd $(CFGRTR_DIR)
	$(MAKE) TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean

# %jp{ライブラリ生成用設定読込み}%en{rules for library}
!include $(KERNEL_MAKINC_DIR)\maklib_r.inc

# %jp{コンパイラ依存のルール定義読込み}%en{rules for compiler}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_r.inc


# %jp{コピー}%en{copy}
srcobjcp:
	$(CMD_CP) $(SRC_PROC_DIR)\*.c       $(OBJS_DIR)
	$(CMD_CP) $(SRC_IRC_DIR)\*.c        $(OBJS_DIR)



# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}%en{kernel dependency list}
!include $(KERNEL_MAKINC_DIR)\knldep.inc



# end of file
