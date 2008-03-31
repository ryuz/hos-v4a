# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Win32 advanced mode
#
# Copyright (C) 1998-2007 by Project HOS
# http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ターゲット名}
TARGET = libhosv4a


# %jp{アーキテクチャ定義}
ARCH_PROC = win\win32
ARCH_IRC  = simple
ARCH_CC   = msc


# %jp{ディレクトリ定義}
TOP_DIR           = ..\..\..\..\..
KERNEL_DIR        = $(TOP_DIR)\kernel
KERNEL_MAKINC_DIR = $(KERNEL_DIR)\build\common\nmake
OBJS_DIR          = objs_$(TARGET)


# %jp{カーネル指定}
KERNEL = Yes


# %jp{共通定義読込み}
!include $(KERNEL_MAKINC_DIR)\common.inc


# %jp{アーキテクチャパス}
INC_PROC_DIR     = $(KERNEL_DIR)\include\arch\proc\$(ARCH_PROC)
INC_IRC_DIR      = $(KERNEL_DIR)\include\arch\irc\$(ARCH_IRC)
SRC_PROC_DIR     = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)
SRC_PROC_ASM_DIR = $(KERNEL_DIR)\source\arch\proc\$(ARCH_PROC)\$(ARCH_CC)
SRC_IRC_DIR      = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)
SRC_IRC_ASM_DIR  = $(KERNEL_DIR)\source\arch\irc\$(ARCH_IRC)\$(ARCH_CC)


# %jp{パス設定}
INC_DIRS = $(INC_DIRS) $(INC_PROC_DIR) $(INC_IRC_DIR)
SRC_DIRS = $(SRC_DIRS) $(SRC_PROC_DIR) $(SRC_PROC_DIR) $(SRC_PROC_ASM_DIR) $(SRC_IRC_DIR) $(SRC_IRC_ASM_DIR)


# %jp{オプションフラグ}
CFLAGS = $(CFLAGS)
AFLAGS = $(AFLAGS)
LFLAGS = 


# %jp{コンフィギュレータ定義}
CFGRTR_DIR = $(TOP_DIR)\cfgrtr\build\msc
CFGRTR     = h4acfg-win32



# %jp{アセンブリ言語ファイルの追加}

# %jp{C言語ファイルの追加}
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/vsig_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/val_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kcre_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kdis_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kena_int.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kini_prc.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/krst_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/ksta_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kswi_ctx.c
CSRCS = $(CSRCS) $(SRC_PROC_DIR)/kwai_int.c

# %jp{オブジェクトファイルの追加}
OBJS = $(OBJS) $(OBJS_DIR)\vsig_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\vsig_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kini_prc.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ksta_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)



# %jp{ALL}
all: mkdir_objs srcobjcp makelib_all
	$(CMD_CD) $(CFGRTR_DIR)
	$(MAKE) /F nmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC)


# %jp{クリーン}
clean: makelib_clean
	-$(CMD_RM) *.lst
	-$(CMD_RM) $(OBJS_DIR)\*.*
	cd $(CFGRTR_DIR)
	$(MAKE) /F nmake.mak TARGET=$(CFGRTR) ARCH_PROC=$(ARCH_PROC) ARCH_IRC=$(ARCH_IRC) clean


# %jp{MS-C用の設定読込み}
!include $(KERNEL_MAKINC_DIR)\msc_d.inc

# カーネル共通ソースの追加
!include $(KERNEL_MAKINC_DIR)\knlsrc.inc

# %jp{ライブラリ生成用設定読込み}
!include $(KERNEL_MAKINC_DIR)\makelib.inc

# %jp{MS-C用のルール定義読込み}
!include $(KERNEL_MAKINC_DIR)\msc_r.inc

# %jp{カーネル依存関係読込み}
!include $(KERNEL_MAKINC_DIR)\knldep.inc


# %jp{コピー}
srcobjcp:
	$(CMD_CP) $(SRC_PROC_DIR)\*.c       $(OBJS_DIR)
	$(CMD_CP) $(SRC_IRC_DIR)\*.c        $(OBJS_DIR)


# %jp{依存関係}
$(OBJS_DIR)\ctxctl.obj : $(OBJS_DIR)\ctxctl.c


# end of file
