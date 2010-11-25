# ----------------------------------------------------------------------------
# Hyper Operating System V4 Advance
#  makefile for Renesas SH2
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
ARCH_NAME = sh2a-fpu
ARCH_PROC = sh\sh2-fpu
ARCH_IRC  = simple
ARCH_CC   = shc


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
AFLAGS  = $(AFLAGS) -CPu=sh2
CFLAGS  = $(CFLAGS) -CPu=sh2
ARFLAGS = $(ARFLAGS)



!if "$(FAST_VECTOR)" == "Yes"
A_DEFS = $(A_DEFS) _KERNEL_FAST_INTVEC="ON"
!endif



# %jp{コンパイラ依存の設定読込み}%en{compiler dependent definitions}
!include $(KERNEL_MAKINC_DIR)\$(ARCH_CC)_d.inc

# %jp{ライブラリ生成用設定読込み}%en{definitions for library}
!include $(KERNEL_MAKINC_DIR)\maklib_d.inc



# --------------------------------------
#  %jp{ソースファイル}%en{source files}
# --------------------------------------

# %jp{アセンブラファイルの追加}%en{assembry sources}
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kena_int.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kdis_int.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kwai_int.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kcre_ctx.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\krst_ctx.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kswi_ctx.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\kint_hdr.src
ASRCS = $(ASRCS) $(SRC_PROC_CC_DIR)\vect_dmy.src


# %jp{C言語ファイルの追加}%en{C sources}
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\val_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\ena_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\dis_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\clr_int.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\chg_imsk.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\get_imsk.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\chg_ilv.c
CSRCS = $(CSRCS) $(SRC_IRC_DIR)\get_ilv.c


# %jp{オブジェクトファイルの追加}%en{object files}
OBJS = $(OBJS) $(OBJS_DIR)\kena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kdis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kwai_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kcre_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\krst_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kswi_ctx.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\kint_hdr.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\vect_dmy.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\val_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\ena_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\dis_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\clr_int.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\chg_imsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_imsk.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\chg_ilv.$(EXT_OBJ)
OBJS = $(OBJS) $(OBJS_DIR)\get_ilv.$(EXT_OBJ)



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
	-$(CMD_RM) *.lst
	-$(CMD_RM) $(OBJS_DIR)\*.*
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


$(OBJS_DIR)\val_int.c : $(SRC_PROC_DIR)\val_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\ena_int.c : $(SRC_IRC_DIR)\ena_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\dis_int.c : $(SRC_IRC_DIR)\dis_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\clr_int.c : $(SRC_IRC_DIR)\clr_int.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\chg_imsk.c : $(SRC_IRC_DIR)\chg_imsk.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\get_imsk.c : $(SRC_IRC_DIR)\get_imsk.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\chg_ilv.c : $(SRC_IRC_DIR)\chg_ilv.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\get_ilv.c : $(SRC_IRC_DIR)\get_ilv.c
	$(CMD_CP) $? $@

$(OBJS_DIR)\kena_int.src : $(SRC_PROC_CC_DIR)\kena_int.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\kdis_int.src : $(SRC_PROC_CC_DIR)\kdis_int.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\kwai_int.src : $(SRC_PROC_CC_DIR)\kwai_int.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\kcre_ctx.src : $(SRC_PROC_CC_DIR)\kcre_ctx.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\krst_ctx.src : $(SRC_PROC_CC_DIR)\krst_ctx.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\kswi_ctx.src : $(SRC_PROC_CC_DIR)\kswi_ctx.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\kint_hdr.src : $(SRC_PROC_CC_DIR)\kint_hdr.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_dmy.src : $(SRC_PROC_CC_DIR)\vect_dmy.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_004.src: $(SRC_PROC_CC_DIR)\vect_004.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_005.src: $(SRC_PROC_CC_DIR)\vect_005.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_006.src: $(SRC_PROC_CC_DIR)\vect_006.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_007.src: $(SRC_PROC_CC_DIR)\vect_007.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_008.src: $(SRC_PROC_CC_DIR)\vect_008.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_009.src: $(SRC_PROC_CC_DIR)\vect_009.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_010.src: $(SRC_PROC_CC_DIR)\vect_010.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_011.src: $(SRC_PROC_CC_DIR)\vect_011.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_012.src: $(SRC_PROC_CC_DIR)\vect_012.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_013.src: $(SRC_PROC_CC_DIR)\vect_013.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_014.src: $(SRC_PROC_CC_DIR)\vect_014.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_015.src: $(SRC_PROC_CC_DIR)\vect_015.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_016.src: $(SRC_PROC_CC_DIR)\vect_016.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_017.src: $(SRC_PROC_CC_DIR)\vect_017.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_018.src: $(SRC_PROC_CC_DIR)\vect_018.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_019.src: $(SRC_PROC_CC_DIR)\vect_019.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_020.src: $(SRC_PROC_CC_DIR)\vect_020.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_021.src: $(SRC_PROC_CC_DIR)\vect_021.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_022.src: $(SRC_PROC_CC_DIR)\vect_022.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_023.src: $(SRC_PROC_CC_DIR)\vect_023.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_024.src: $(SRC_PROC_CC_DIR)\vect_024.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_025.src: $(SRC_PROC_CC_DIR)\vect_025.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_026.src: $(SRC_PROC_CC_DIR)\vect_026.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_027.src: $(SRC_PROC_CC_DIR)\vect_027.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_028.src: $(SRC_PROC_CC_DIR)\vect_028.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_029.src: $(SRC_PROC_CC_DIR)\vect_029.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_030.src: $(SRC_PROC_CC_DIR)\vect_030.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_031.src: $(SRC_PROC_CC_DIR)\vect_031.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_032.src: $(SRC_PROC_CC_DIR)\vect_032.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_033.src: $(SRC_PROC_CC_DIR)\vect_033.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_034.src: $(SRC_PROC_CC_DIR)\vect_034.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_035.src: $(SRC_PROC_CC_DIR)\vect_035.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_036.src: $(SRC_PROC_CC_DIR)\vect_036.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_037.src: $(SRC_PROC_CC_DIR)\vect_037.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_038.src: $(SRC_PROC_CC_DIR)\vect_038.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_039.src: $(SRC_PROC_CC_DIR)\vect_039.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_040.src: $(SRC_PROC_CC_DIR)\vect_040.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_041.src: $(SRC_PROC_CC_DIR)\vect_041.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_042.src: $(SRC_PROC_CC_DIR)\vect_042.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_043.src: $(SRC_PROC_CC_DIR)\vect_043.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_044.src: $(SRC_PROC_CC_DIR)\vect_044.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_045.src: $(SRC_PROC_CC_DIR)\vect_045.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_046.src: $(SRC_PROC_CC_DIR)\vect_046.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_047.src: $(SRC_PROC_CC_DIR)\vect_047.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_048.src: $(SRC_PROC_CC_DIR)\vect_048.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_049.src: $(SRC_PROC_CC_DIR)\vect_049.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_050.src: $(SRC_PROC_CC_DIR)\vect_050.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_051.src: $(SRC_PROC_CC_DIR)\vect_051.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_052.src: $(SRC_PROC_CC_DIR)\vect_052.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_053.src: $(SRC_PROC_CC_DIR)\vect_053.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_054.src: $(SRC_PROC_CC_DIR)\vect_054.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_055.src: $(SRC_PROC_CC_DIR)\vect_055.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_056.src: $(SRC_PROC_CC_DIR)\vect_056.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_057.src: $(SRC_PROC_CC_DIR)\vect_057.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_058.src: $(SRC_PROC_CC_DIR)\vect_058.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_059.src: $(SRC_PROC_CC_DIR)\vect_059.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_060.src: $(SRC_PROC_CC_DIR)\vect_060.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_061.src: $(SRC_PROC_CC_DIR)\vect_061.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_062.src: $(SRC_PROC_CC_DIR)\vect_062.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_063.src: $(SRC_PROC_CC_DIR)\vect_063.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_064.src: $(SRC_PROC_CC_DIR)\vect_064.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_065.src: $(SRC_PROC_CC_DIR)\vect_065.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_066.src: $(SRC_PROC_CC_DIR)\vect_066.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_067.src: $(SRC_PROC_CC_DIR)\vect_067.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_068.src: $(SRC_PROC_CC_DIR)\vect_068.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_069.src: $(SRC_PROC_CC_DIR)\vect_069.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_070.src: $(SRC_PROC_CC_DIR)\vect_070.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_071.src: $(SRC_PROC_CC_DIR)\vect_071.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_072.src: $(SRC_PROC_CC_DIR)\vect_072.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_073.src: $(SRC_PROC_CC_DIR)\vect_073.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_074.src: $(SRC_PROC_CC_DIR)\vect_074.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_075.src: $(SRC_PROC_CC_DIR)\vect_075.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_076.src: $(SRC_PROC_CC_DIR)\vect_076.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_077.src: $(SRC_PROC_CC_DIR)\vect_077.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_078.src: $(SRC_PROC_CC_DIR)\vect_078.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_079.src: $(SRC_PROC_CC_DIR)\vect_079.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_080.src: $(SRC_PROC_CC_DIR)\vect_080.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_081.src: $(SRC_PROC_CC_DIR)\vect_081.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_082.src: $(SRC_PROC_CC_DIR)\vect_082.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_083.src: $(SRC_PROC_CC_DIR)\vect_083.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_084.src: $(SRC_PROC_CC_DIR)\vect_084.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_085.src: $(SRC_PROC_CC_DIR)\vect_085.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_086.src: $(SRC_PROC_CC_DIR)\vect_086.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_087.src: $(SRC_PROC_CC_DIR)\vect_087.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_088.src: $(SRC_PROC_CC_DIR)\vect_088.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_089.src: $(SRC_PROC_CC_DIR)\vect_089.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_090.src: $(SRC_PROC_CC_DIR)\vect_090.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_091.src: $(SRC_PROC_CC_DIR)\vect_091.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_092.src: $(SRC_PROC_CC_DIR)\vect_092.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_093.src: $(SRC_PROC_CC_DIR)\vect_093.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_094.src: $(SRC_PROC_CC_DIR)\vect_094.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_095.src: $(SRC_PROC_CC_DIR)\vect_095.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_096.src: $(SRC_PROC_CC_DIR)\vect_096.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_097.src: $(SRC_PROC_CC_DIR)\vect_097.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_098.src: $(SRC_PROC_CC_DIR)\vect_098.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_099.src: $(SRC_PROC_CC_DIR)\vect_099.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_100.src: $(SRC_PROC_CC_DIR)\vect_100.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_101.src: $(SRC_PROC_CC_DIR)\vect_101.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_102.src: $(SRC_PROC_CC_DIR)\vect_102.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_103.src: $(SRC_PROC_CC_DIR)\vect_103.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_104.src: $(SRC_PROC_CC_DIR)\vect_104.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_105.src: $(SRC_PROC_CC_DIR)\vect_105.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_106.src: $(SRC_PROC_CC_DIR)\vect_106.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_107.src: $(SRC_PROC_CC_DIR)\vect_107.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_108.src: $(SRC_PROC_CC_DIR)\vect_108.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_109.src: $(SRC_PROC_CC_DIR)\vect_109.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_110.src: $(SRC_PROC_CC_DIR)\vect_110.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_111.src: $(SRC_PROC_CC_DIR)\vect_111.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_112.src: $(SRC_PROC_CC_DIR)\vect_112.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_113.src: $(SRC_PROC_CC_DIR)\vect_113.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_114.src: $(SRC_PROC_CC_DIR)\vect_114.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_115.src: $(SRC_PROC_CC_DIR)\vect_115.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_116.src: $(SRC_PROC_CC_DIR)\vect_116.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_117.src: $(SRC_PROC_CC_DIR)\vect_117.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_118.src: $(SRC_PROC_CC_DIR)\vect_118.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_119.src: $(SRC_PROC_CC_DIR)\vect_119.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_120.src: $(SRC_PROC_CC_DIR)\vect_120.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_121.src: $(SRC_PROC_CC_DIR)\vect_121.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_122.src: $(SRC_PROC_CC_DIR)\vect_122.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_123.src: $(SRC_PROC_CC_DIR)\vect_123.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_124.src: $(SRC_PROC_CC_DIR)\vect_124.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_125.src: $(SRC_PROC_CC_DIR)\vect_125.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_126.src: $(SRC_PROC_CC_DIR)\vect_126.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_127.src: $(SRC_PROC_CC_DIR)\vect_127.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_128.src: $(SRC_PROC_CC_DIR)\vect_128.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_129.src: $(SRC_PROC_CC_DIR)\vect_129.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_130.src: $(SRC_PROC_CC_DIR)\vect_130.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_131.src: $(SRC_PROC_CC_DIR)\vect_131.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_132.src: $(SRC_PROC_CC_DIR)\vect_132.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_133.src: $(SRC_PROC_CC_DIR)\vect_133.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_134.src: $(SRC_PROC_CC_DIR)\vect_134.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_135.src: $(SRC_PROC_CC_DIR)\vect_135.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_136.src: $(SRC_PROC_CC_DIR)\vect_136.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_137.src: $(SRC_PROC_CC_DIR)\vect_137.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_138.src: $(SRC_PROC_CC_DIR)\vect_138.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_139.src: $(SRC_PROC_CC_DIR)\vect_139.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_140.src: $(SRC_PROC_CC_DIR)\vect_140.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_141.src: $(SRC_PROC_CC_DIR)\vect_141.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_142.src: $(SRC_PROC_CC_DIR)\vect_142.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_143.src: $(SRC_PROC_CC_DIR)\vect_143.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_144.src: $(SRC_PROC_CC_DIR)\vect_144.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_145.src: $(SRC_PROC_CC_DIR)\vect_145.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_146.src: $(SRC_PROC_CC_DIR)\vect_146.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_147.src: $(SRC_PROC_CC_DIR)\vect_147.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_148.src: $(SRC_PROC_CC_DIR)\vect_148.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_149.src: $(SRC_PROC_CC_DIR)\vect_149.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_150.src: $(SRC_PROC_CC_DIR)\vect_150.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_151.src: $(SRC_PROC_CC_DIR)\vect_151.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_152.src: $(SRC_PROC_CC_DIR)\vect_152.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_153.src: $(SRC_PROC_CC_DIR)\vect_153.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_154.src: $(SRC_PROC_CC_DIR)\vect_154.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_155.src: $(SRC_PROC_CC_DIR)\vect_155.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_156.src: $(SRC_PROC_CC_DIR)\vect_156.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_157.src: $(SRC_PROC_CC_DIR)\vect_157.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_158.src: $(SRC_PROC_CC_DIR)\vect_158.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_159.src: $(SRC_PROC_CC_DIR)\vect_159.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_160.src: $(SRC_PROC_CC_DIR)\vect_160.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_161.src: $(SRC_PROC_CC_DIR)\vect_161.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_162.src: $(SRC_PROC_CC_DIR)\vect_162.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_163.src: $(SRC_PROC_CC_DIR)\vect_163.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_164.src: $(SRC_PROC_CC_DIR)\vect_164.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_165.src: $(SRC_PROC_CC_DIR)\vect_165.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_166.src: $(SRC_PROC_CC_DIR)\vect_166.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_167.src: $(SRC_PROC_CC_DIR)\vect_167.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_168.src: $(SRC_PROC_CC_DIR)\vect_168.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_169.src: $(SRC_PROC_CC_DIR)\vect_169.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_170.src: $(SRC_PROC_CC_DIR)\vect_170.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_171.src: $(SRC_PROC_CC_DIR)\vect_171.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_172.src: $(SRC_PROC_CC_DIR)\vect_172.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_173.src: $(SRC_PROC_CC_DIR)\vect_173.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_174.src: $(SRC_PROC_CC_DIR)\vect_174.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_175.src: $(SRC_PROC_CC_DIR)\vect_175.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_176.src: $(SRC_PROC_CC_DIR)\vect_176.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_177.src: $(SRC_PROC_CC_DIR)\vect_177.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_178.src: $(SRC_PROC_CC_DIR)\vect_178.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_179.src: $(SRC_PROC_CC_DIR)\vect_179.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_180.src: $(SRC_PROC_CC_DIR)\vect_180.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_181.src: $(SRC_PROC_CC_DIR)\vect_181.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_182.src: $(SRC_PROC_CC_DIR)\vect_182.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_183.src: $(SRC_PROC_CC_DIR)\vect_183.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_184.src: $(SRC_PROC_CC_DIR)\vect_184.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_185.src: $(SRC_PROC_CC_DIR)\vect_185.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_186.src: $(SRC_PROC_CC_DIR)\vect_186.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_187.src: $(SRC_PROC_CC_DIR)\vect_187.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_188.src: $(SRC_PROC_CC_DIR)\vect_188.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_189.src: $(SRC_PROC_CC_DIR)\vect_189.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_190.src: $(SRC_PROC_CC_DIR)\vect_190.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_191.src: $(SRC_PROC_CC_DIR)\vect_191.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_192.src: $(SRC_PROC_CC_DIR)\vect_192.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_193.src: $(SRC_PROC_CC_DIR)\vect_193.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_194.src: $(SRC_PROC_CC_DIR)\vect_194.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_195.src: $(SRC_PROC_CC_DIR)\vect_195.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_196.src: $(SRC_PROC_CC_DIR)\vect_196.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_197.src: $(SRC_PROC_CC_DIR)\vect_197.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_198.src: $(SRC_PROC_CC_DIR)\vect_198.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_199.src: $(SRC_PROC_CC_DIR)\vect_199.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_200.src: $(SRC_PROC_CC_DIR)\vect_200.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_201.src: $(SRC_PROC_CC_DIR)\vect_201.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_202.src: $(SRC_PROC_CC_DIR)\vect_202.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_203.src: $(SRC_PROC_CC_DIR)\vect_203.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_204.src: $(SRC_PROC_CC_DIR)\vect_204.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_205.src: $(SRC_PROC_CC_DIR)\vect_205.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_206.src: $(SRC_PROC_CC_DIR)\vect_206.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_207.src: $(SRC_PROC_CC_DIR)\vect_207.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_208.src: $(SRC_PROC_CC_DIR)\vect_208.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_209.src: $(SRC_PROC_CC_DIR)\vect_209.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_210.src: $(SRC_PROC_CC_DIR)\vect_210.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_211.src: $(SRC_PROC_CC_DIR)\vect_211.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_212.src: $(SRC_PROC_CC_DIR)\vect_212.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_213.src: $(SRC_PROC_CC_DIR)\vect_213.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_214.src: $(SRC_PROC_CC_DIR)\vect_214.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_215.src: $(SRC_PROC_CC_DIR)\vect_215.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_216.src: $(SRC_PROC_CC_DIR)\vect_216.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_217.src: $(SRC_PROC_CC_DIR)\vect_217.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_218.src: $(SRC_PROC_CC_DIR)\vect_218.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_219.src: $(SRC_PROC_CC_DIR)\vect_219.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_220.src: $(SRC_PROC_CC_DIR)\vect_220.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_221.src: $(SRC_PROC_CC_DIR)\vect_221.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_222.src: $(SRC_PROC_CC_DIR)\vect_222.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_223.src: $(SRC_PROC_CC_DIR)\vect_223.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_224.src: $(SRC_PROC_CC_DIR)\vect_224.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_225.src: $(SRC_PROC_CC_DIR)\vect_225.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_226.src: $(SRC_PROC_CC_DIR)\vect_226.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_227.src: $(SRC_PROC_CC_DIR)\vect_227.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_228.src: $(SRC_PROC_CC_DIR)\vect_228.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_229.src: $(SRC_PROC_CC_DIR)\vect_229.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_230.src: $(SRC_PROC_CC_DIR)\vect_230.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_231.src: $(SRC_PROC_CC_DIR)\vect_231.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_232.src: $(SRC_PROC_CC_DIR)\vect_232.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_233.src: $(SRC_PROC_CC_DIR)\vect_233.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_234.src: $(SRC_PROC_CC_DIR)\vect_234.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_235.src: $(SRC_PROC_CC_DIR)\vect_235.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_236.src: $(SRC_PROC_CC_DIR)\vect_236.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_237.src: $(SRC_PROC_CC_DIR)\vect_237.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_238.src: $(SRC_PROC_CC_DIR)\vect_238.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_239.src: $(SRC_PROC_CC_DIR)\vect_239.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_240.src: $(SRC_PROC_CC_DIR)\vect_240.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_241.src: $(SRC_PROC_CC_DIR)\vect_241.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_242.src: $(SRC_PROC_CC_DIR)\vect_242.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_243.src: $(SRC_PROC_CC_DIR)\vect_243.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_244.src: $(SRC_PROC_CC_DIR)\vect_244.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_245.src: $(SRC_PROC_CC_DIR)\vect_245.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_246.src: $(SRC_PROC_CC_DIR)\vect_246.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_247.src: $(SRC_PROC_CC_DIR)\vect_247.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_248.src: $(SRC_PROC_CC_DIR)\vect_248.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_249.src: $(SRC_PROC_CC_DIR)\vect_249.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_250.src: $(SRC_PROC_CC_DIR)\vect_250.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_251.src: $(SRC_PROC_CC_DIR)\vect_251.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_252.src: $(SRC_PROC_CC_DIR)\vect_252.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_253.src: $(SRC_PROC_CC_DIR)\vect_253.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_254.src: $(SRC_PROC_CC_DIR)\vect_254.src
	$(CMD_CP) $? $@

$(OBJS_DIR)\vect_255.src: $(SRC_PROC_CC_DIR)\vect_255.src
	$(CMD_CP) $? $@




# --------------------------------------
#  %jp{依存関係}%en{dependency}
# --------------------------------------

# %jp{カーネル依存関係読込み}{dependency list of kernel sources}
!include $(KERNEL_MAKINC_DIR)\knldep.inc


# %jp{依存関係}%en{dependence}
$(OBJS_DIR)\val_int.$(EXT_OBJ) : $(OBJS_DIR)\val_int.c
$(OBJS_DIR)\val_imsk.$(EXT_OBJ): $(OBJS_DIR)\val_imsk.c
$(OBJS_DIR)\chg_imsk.$(EXT_OBJ): $(OBJS_DIR)\chg_imsk.c
$(OBJS_DIR)\get_imsk.$(EXT_OBJ): $(OBJS_DIR)\get_imsk.c
$(OBJS_DIR)\ena_int.$(EXT_OBJ) : $(OBJS_DIR)\ena_int.c
$(OBJS_DIR)\dis_int.$(EXT_OBJ) : $(OBJS_DIR)\dis_int.c
$(OBJS_DIR)\clr_int.$(EXT_OBJ) : $(OBJS_DIR)\clr_int.c
$(OBJS_DIR)\chg_ilv.$(EXT_OBJ) : $(OBJS_DIR)\chg_ilv.c
$(OBJS_DIR)\get_ilv.$(EXT_OBJ) : $(OBJS_DIR)\get_ilv.c
$(OBJS_DIR)\kena_int.$(EXT_OBJ): $(OBJS_DIR)\kena_int.src
$(OBJS_DIR)\kdis_int.$(EXT_OBJ): $(OBJS_DIR)\kdis_int.src
$(OBJS_DIR)\kwai_int.$(EXT_OBJ): $(OBJS_DIR)\kwai_int.src
$(OBJS_DIR)\kcre_ctx.$(EXT_OBJ): $(OBJS_DIR)\kcre_ctx.src
$(OBJS_DIR)\krst_ctx.$(EXT_OBJ): $(OBJS_DIR)\krst_ctx.src
$(OBJS_DIR)\kswi_ctx.$(EXT_OBJ): $(OBJS_DIR)\kswi_ctx.src
$(OBJS_DIR)\kint_hdr.$(EXT_OBJ): $(OBJS_DIR)\kint_hdr.src
$(OBJS_DIR)\vect_dmy.$(EXT_OBJ): $(OBJS_DIR)\vect_dmy.src
$(OBJS_DIR)\vect_004.$(EXT_OBJ): $(OBJS_DIR)\vect_004.src
$(OBJS_DIR)\vect_005.$(EXT_OBJ): $(OBJS_DIR)\vect_005.src
$(OBJS_DIR)\vect_006.$(EXT_OBJ): $(OBJS_DIR)\vect_006.src
$(OBJS_DIR)\vect_007.$(EXT_OBJ): $(OBJS_DIR)\vect_007.src
$(OBJS_DIR)\vect_008.$(EXT_OBJ): $(OBJS_DIR)\vect_008.src
$(OBJS_DIR)\vect_009.$(EXT_OBJ): $(OBJS_DIR)\vect_009.src
$(OBJS_DIR)\vect_010.$(EXT_OBJ): $(OBJS_DIR)\vect_010.src
$(OBJS_DIR)\vect_011.$(EXT_OBJ): $(OBJS_DIR)\vect_011.src
$(OBJS_DIR)\vect_012.$(EXT_OBJ): $(OBJS_DIR)\vect_012.src
$(OBJS_DIR)\vect_013.$(EXT_OBJ): $(OBJS_DIR)\vect_013.src
$(OBJS_DIR)\vect_014.$(EXT_OBJ): $(OBJS_DIR)\vect_014.src
$(OBJS_DIR)\vect_015.$(EXT_OBJ): $(OBJS_DIR)\vect_015.src
$(OBJS_DIR)\vect_016.$(EXT_OBJ): $(OBJS_DIR)\vect_016.src
$(OBJS_DIR)\vect_017.$(EXT_OBJ): $(OBJS_DIR)\vect_017.src
$(OBJS_DIR)\vect_018.$(EXT_OBJ): $(OBJS_DIR)\vect_018.src
$(OBJS_DIR)\vect_019.$(EXT_OBJ): $(OBJS_DIR)\vect_019.src
$(OBJS_DIR)\vect_020.$(EXT_OBJ): $(OBJS_DIR)\vect_020.src
$(OBJS_DIR)\vect_021.$(EXT_OBJ): $(OBJS_DIR)\vect_021.src
$(OBJS_DIR)\vect_022.$(EXT_OBJ): $(OBJS_DIR)\vect_022.src
$(OBJS_DIR)\vect_023.$(EXT_OBJ): $(OBJS_DIR)\vect_023.src
$(OBJS_DIR)\vect_024.$(EXT_OBJ): $(OBJS_DIR)\vect_024.src
$(OBJS_DIR)\vect_025.$(EXT_OBJ): $(OBJS_DIR)\vect_025.src
$(OBJS_DIR)\vect_026.$(EXT_OBJ): $(OBJS_DIR)\vect_026.src
$(OBJS_DIR)\vect_027.$(EXT_OBJ): $(OBJS_DIR)\vect_027.src
$(OBJS_DIR)\vect_028.$(EXT_OBJ): $(OBJS_DIR)\vect_028.src
$(OBJS_DIR)\vect_029.$(EXT_OBJ): $(OBJS_DIR)\vect_029.src
$(OBJS_DIR)\vect_030.$(EXT_OBJ): $(OBJS_DIR)\vect_030.src
$(OBJS_DIR)\vect_031.$(EXT_OBJ): $(OBJS_DIR)\vect_031.src
$(OBJS_DIR)\vect_032.$(EXT_OBJ): $(OBJS_DIR)\vect_032.src
$(OBJS_DIR)\vect_033.$(EXT_OBJ): $(OBJS_DIR)\vect_033.src
$(OBJS_DIR)\vect_034.$(EXT_OBJ): $(OBJS_DIR)\vect_034.src
$(OBJS_DIR)\vect_035.$(EXT_OBJ): $(OBJS_DIR)\vect_035.src
$(OBJS_DIR)\vect_036.$(EXT_OBJ): $(OBJS_DIR)\vect_036.src
$(OBJS_DIR)\vect_037.$(EXT_OBJ): $(OBJS_DIR)\vect_037.src
$(OBJS_DIR)\vect_038.$(EXT_OBJ): $(OBJS_DIR)\vect_038.src
$(OBJS_DIR)\vect_039.$(EXT_OBJ): $(OBJS_DIR)\vect_039.src
$(OBJS_DIR)\vect_040.$(EXT_OBJ): $(OBJS_DIR)\vect_040.src
$(OBJS_DIR)\vect_041.$(EXT_OBJ): $(OBJS_DIR)\vect_041.src
$(OBJS_DIR)\vect_042.$(EXT_OBJ): $(OBJS_DIR)\vect_042.src
$(OBJS_DIR)\vect_043.$(EXT_OBJ): $(OBJS_DIR)\vect_043.src
$(OBJS_DIR)\vect_044.$(EXT_OBJ): $(OBJS_DIR)\vect_044.src
$(OBJS_DIR)\vect_045.$(EXT_OBJ): $(OBJS_DIR)\vect_045.src
$(OBJS_DIR)\vect_046.$(EXT_OBJ): $(OBJS_DIR)\vect_046.src
$(OBJS_DIR)\vect_047.$(EXT_OBJ): $(OBJS_DIR)\vect_047.src
$(OBJS_DIR)\vect_048.$(EXT_OBJ): $(OBJS_DIR)\vect_048.src
$(OBJS_DIR)\vect_049.$(EXT_OBJ): $(OBJS_DIR)\vect_049.src
$(OBJS_DIR)\vect_050.$(EXT_OBJ): $(OBJS_DIR)\vect_050.src
$(OBJS_DIR)\vect_051.$(EXT_OBJ): $(OBJS_DIR)\vect_051.src
$(OBJS_DIR)\vect_052.$(EXT_OBJ): $(OBJS_DIR)\vect_052.src
$(OBJS_DIR)\vect_053.$(EXT_OBJ): $(OBJS_DIR)\vect_053.src
$(OBJS_DIR)\vect_054.$(EXT_OBJ): $(OBJS_DIR)\vect_054.src
$(OBJS_DIR)\vect_055.$(EXT_OBJ): $(OBJS_DIR)\vect_055.src
$(OBJS_DIR)\vect_056.$(EXT_OBJ): $(OBJS_DIR)\vect_056.src
$(OBJS_DIR)\vect_057.$(EXT_OBJ): $(OBJS_DIR)\vect_057.src
$(OBJS_DIR)\vect_058.$(EXT_OBJ): $(OBJS_DIR)\vect_058.src
$(OBJS_DIR)\vect_059.$(EXT_OBJ): $(OBJS_DIR)\vect_059.src
$(OBJS_DIR)\vect_060.$(EXT_OBJ): $(OBJS_DIR)\vect_060.src
$(OBJS_DIR)\vect_061.$(EXT_OBJ): $(OBJS_DIR)\vect_061.src
$(OBJS_DIR)\vect_062.$(EXT_OBJ): $(OBJS_DIR)\vect_062.src
$(OBJS_DIR)\vect_063.$(EXT_OBJ): $(OBJS_DIR)\vect_063.src
$(OBJS_DIR)\vect_064.$(EXT_OBJ): $(OBJS_DIR)\vect_064.src
$(OBJS_DIR)\vect_065.$(EXT_OBJ): $(OBJS_DIR)\vect_065.src
$(OBJS_DIR)\vect_066.$(EXT_OBJ): $(OBJS_DIR)\vect_066.src
$(OBJS_DIR)\vect_067.$(EXT_OBJ): $(OBJS_DIR)\vect_067.src
$(OBJS_DIR)\vect_068.$(EXT_OBJ): $(OBJS_DIR)\vect_068.src
$(OBJS_DIR)\vect_069.$(EXT_OBJ): $(OBJS_DIR)\vect_069.src
$(OBJS_DIR)\vect_070.$(EXT_OBJ): $(OBJS_DIR)\vect_070.src
$(OBJS_DIR)\vect_071.$(EXT_OBJ): $(OBJS_DIR)\vect_071.src
$(OBJS_DIR)\vect_072.$(EXT_OBJ): $(OBJS_DIR)\vect_072.src
$(OBJS_DIR)\vect_073.$(EXT_OBJ): $(OBJS_DIR)\vect_073.src
$(OBJS_DIR)\vect_074.$(EXT_OBJ): $(OBJS_DIR)\vect_074.src
$(OBJS_DIR)\vect_075.$(EXT_OBJ): $(OBJS_DIR)\vect_075.src
$(OBJS_DIR)\vect_076.$(EXT_OBJ): $(OBJS_DIR)\vect_076.src
$(OBJS_DIR)\vect_077.$(EXT_OBJ): $(OBJS_DIR)\vect_077.src
$(OBJS_DIR)\vect_078.$(EXT_OBJ): $(OBJS_DIR)\vect_078.src
$(OBJS_DIR)\vect_079.$(EXT_OBJ): $(OBJS_DIR)\vect_079.src
$(OBJS_DIR)\vect_080.$(EXT_OBJ): $(OBJS_DIR)\vect_080.src
$(OBJS_DIR)\vect_081.$(EXT_OBJ): $(OBJS_DIR)\vect_081.src
$(OBJS_DIR)\vect_082.$(EXT_OBJ): $(OBJS_DIR)\vect_082.src
$(OBJS_DIR)\vect_083.$(EXT_OBJ): $(OBJS_DIR)\vect_083.src
$(OBJS_DIR)\vect_084.$(EXT_OBJ): $(OBJS_DIR)\vect_084.src
$(OBJS_DIR)\vect_085.$(EXT_OBJ): $(OBJS_DIR)\vect_085.src
$(OBJS_DIR)\vect_086.$(EXT_OBJ): $(OBJS_DIR)\vect_086.src
$(OBJS_DIR)\vect_087.$(EXT_OBJ): $(OBJS_DIR)\vect_087.src
$(OBJS_DIR)\vect_088.$(EXT_OBJ): $(OBJS_DIR)\vect_088.src
$(OBJS_DIR)\vect_089.$(EXT_OBJ): $(OBJS_DIR)\vect_089.src
$(OBJS_DIR)\vect_090.$(EXT_OBJ): $(OBJS_DIR)\vect_090.src
$(OBJS_DIR)\vect_091.$(EXT_OBJ): $(OBJS_DIR)\vect_091.src
$(OBJS_DIR)\vect_092.$(EXT_OBJ): $(OBJS_DIR)\vect_092.src
$(OBJS_DIR)\vect_093.$(EXT_OBJ): $(OBJS_DIR)\vect_093.src
$(OBJS_DIR)\vect_094.$(EXT_OBJ): $(OBJS_DIR)\vect_094.src
$(OBJS_DIR)\vect_095.$(EXT_OBJ): $(OBJS_DIR)\vect_095.src
$(OBJS_DIR)\vect_096.$(EXT_OBJ): $(OBJS_DIR)\vect_096.src
$(OBJS_DIR)\vect_097.$(EXT_OBJ): $(OBJS_DIR)\vect_097.src
$(OBJS_DIR)\vect_098.$(EXT_OBJ): $(OBJS_DIR)\vect_098.src
$(OBJS_DIR)\vect_099.$(EXT_OBJ): $(OBJS_DIR)\vect_099.src
$(OBJS_DIR)\vect_100.$(EXT_OBJ): $(OBJS_DIR)\vect_100.src
$(OBJS_DIR)\vect_101.$(EXT_OBJ): $(OBJS_DIR)\vect_101.src
$(OBJS_DIR)\vect_102.$(EXT_OBJ): $(OBJS_DIR)\vect_102.src
$(OBJS_DIR)\vect_103.$(EXT_OBJ): $(OBJS_DIR)\vect_103.src
$(OBJS_DIR)\vect_104.$(EXT_OBJ): $(OBJS_DIR)\vect_104.src
$(OBJS_DIR)\vect_105.$(EXT_OBJ): $(OBJS_DIR)\vect_105.src
$(OBJS_DIR)\vect_106.$(EXT_OBJ): $(OBJS_DIR)\vect_106.src
$(OBJS_DIR)\vect_107.$(EXT_OBJ): $(OBJS_DIR)\vect_107.src
$(OBJS_DIR)\vect_108.$(EXT_OBJ): $(OBJS_DIR)\vect_108.src
$(OBJS_DIR)\vect_109.$(EXT_OBJ): $(OBJS_DIR)\vect_109.src
$(OBJS_DIR)\vect_110.$(EXT_OBJ): $(OBJS_DIR)\vect_110.src
$(OBJS_DIR)\vect_111.$(EXT_OBJ): $(OBJS_DIR)\vect_111.src
$(OBJS_DIR)\vect_112.$(EXT_OBJ): $(OBJS_DIR)\vect_112.src
$(OBJS_DIR)\vect_113.$(EXT_OBJ): $(OBJS_DIR)\vect_113.src
$(OBJS_DIR)\vect_114.$(EXT_OBJ): $(OBJS_DIR)\vect_114.src
$(OBJS_DIR)\vect_115.$(EXT_OBJ): $(OBJS_DIR)\vect_115.src
$(OBJS_DIR)\vect_116.$(EXT_OBJ): $(OBJS_DIR)\vect_116.src
$(OBJS_DIR)\vect_117.$(EXT_OBJ): $(OBJS_DIR)\vect_117.src
$(OBJS_DIR)\vect_118.$(EXT_OBJ): $(OBJS_DIR)\vect_118.src
$(OBJS_DIR)\vect_119.$(EXT_OBJ): $(OBJS_DIR)\vect_119.src
$(OBJS_DIR)\vect_120.$(EXT_OBJ): $(OBJS_DIR)\vect_120.src
$(OBJS_DIR)\vect_121.$(EXT_OBJ): $(OBJS_DIR)\vect_121.src
$(OBJS_DIR)\vect_122.$(EXT_OBJ): $(OBJS_DIR)\vect_122.src
$(OBJS_DIR)\vect_123.$(EXT_OBJ): $(OBJS_DIR)\vect_123.src
$(OBJS_DIR)\vect_124.$(EXT_OBJ): $(OBJS_DIR)\vect_124.src
$(OBJS_DIR)\vect_125.$(EXT_OBJ): $(OBJS_DIR)\vect_125.src
$(OBJS_DIR)\vect_126.$(EXT_OBJ): $(OBJS_DIR)\vect_126.src
$(OBJS_DIR)\vect_127.$(EXT_OBJ): $(OBJS_DIR)\vect_127.src
$(OBJS_DIR)\vect_128.$(EXT_OBJ): $(OBJS_DIR)\vect_128.src
$(OBJS_DIR)\vect_129.$(EXT_OBJ): $(OBJS_DIR)\vect_129.src
$(OBJS_DIR)\vect_130.$(EXT_OBJ): $(OBJS_DIR)\vect_130.src
$(OBJS_DIR)\vect_131.$(EXT_OBJ): $(OBJS_DIR)\vect_131.src
$(OBJS_DIR)\vect_132.$(EXT_OBJ): $(OBJS_DIR)\vect_132.src
$(OBJS_DIR)\vect_133.$(EXT_OBJ): $(OBJS_DIR)\vect_133.src
$(OBJS_DIR)\vect_134.$(EXT_OBJ): $(OBJS_DIR)\vect_134.src
$(OBJS_DIR)\vect_135.$(EXT_OBJ): $(OBJS_DIR)\vect_135.src
$(OBJS_DIR)\vect_136.$(EXT_OBJ): $(OBJS_DIR)\vect_136.src
$(OBJS_DIR)\vect_137.$(EXT_OBJ): $(OBJS_DIR)\vect_137.src
$(OBJS_DIR)\vect_138.$(EXT_OBJ): $(OBJS_DIR)\vect_138.src
$(OBJS_DIR)\vect_139.$(EXT_OBJ): $(OBJS_DIR)\vect_139.src
$(OBJS_DIR)\vect_140.$(EXT_OBJ): $(OBJS_DIR)\vect_140.src
$(OBJS_DIR)\vect_141.$(EXT_OBJ): $(OBJS_DIR)\vect_141.src
$(OBJS_DIR)\vect_142.$(EXT_OBJ): $(OBJS_DIR)\vect_142.src
$(OBJS_DIR)\vect_143.$(EXT_OBJ): $(OBJS_DIR)\vect_143.src
$(OBJS_DIR)\vect_144.$(EXT_OBJ): $(OBJS_DIR)\vect_144.src
$(OBJS_DIR)\vect_145.$(EXT_OBJ): $(OBJS_DIR)\vect_145.src
$(OBJS_DIR)\vect_146.$(EXT_OBJ): $(OBJS_DIR)\vect_146.src
$(OBJS_DIR)\vect_147.$(EXT_OBJ): $(OBJS_DIR)\vect_147.src
$(OBJS_DIR)\vect_148.$(EXT_OBJ): $(OBJS_DIR)\vect_148.src
$(OBJS_DIR)\vect_149.$(EXT_OBJ): $(OBJS_DIR)\vect_149.src
$(OBJS_DIR)\vect_150.$(EXT_OBJ): $(OBJS_DIR)\vect_150.src
$(OBJS_DIR)\vect_151.$(EXT_OBJ): $(OBJS_DIR)\vect_151.src
$(OBJS_DIR)\vect_152.$(EXT_OBJ): $(OBJS_DIR)\vect_152.src
$(OBJS_DIR)\vect_153.$(EXT_OBJ): $(OBJS_DIR)\vect_153.src
$(OBJS_DIR)\vect_154.$(EXT_OBJ): $(OBJS_DIR)\vect_154.src
$(OBJS_DIR)\vect_155.$(EXT_OBJ): $(OBJS_DIR)\vect_155.src
$(OBJS_DIR)\vect_156.$(EXT_OBJ): $(OBJS_DIR)\vect_156.src
$(OBJS_DIR)\vect_157.$(EXT_OBJ): $(OBJS_DIR)\vect_157.src
$(OBJS_DIR)\vect_158.$(EXT_OBJ): $(OBJS_DIR)\vect_158.src
$(OBJS_DIR)\vect_159.$(EXT_OBJ): $(OBJS_DIR)\vect_159.src
$(OBJS_DIR)\vect_160.$(EXT_OBJ): $(OBJS_DIR)\vect_160.src
$(OBJS_DIR)\vect_161.$(EXT_OBJ): $(OBJS_DIR)\vect_161.src
$(OBJS_DIR)\vect_162.$(EXT_OBJ): $(OBJS_DIR)\vect_162.src
$(OBJS_DIR)\vect_163.$(EXT_OBJ): $(OBJS_DIR)\vect_163.src
$(OBJS_DIR)\vect_164.$(EXT_OBJ): $(OBJS_DIR)\vect_164.src
$(OBJS_DIR)\vect_165.$(EXT_OBJ): $(OBJS_DIR)\vect_165.src
$(OBJS_DIR)\vect_166.$(EXT_OBJ): $(OBJS_DIR)\vect_166.src
$(OBJS_DIR)\vect_167.$(EXT_OBJ): $(OBJS_DIR)\vect_167.src
$(OBJS_DIR)\vect_168.$(EXT_OBJ): $(OBJS_DIR)\vect_168.src
$(OBJS_DIR)\vect_169.$(EXT_OBJ): $(OBJS_DIR)\vect_169.src
$(OBJS_DIR)\vect_170.$(EXT_OBJ): $(OBJS_DIR)\vect_170.src
$(OBJS_DIR)\vect_171.$(EXT_OBJ): $(OBJS_DIR)\vect_171.src
$(OBJS_DIR)\vect_172.$(EXT_OBJ): $(OBJS_DIR)\vect_172.src
$(OBJS_DIR)\vect_173.$(EXT_OBJ): $(OBJS_DIR)\vect_173.src
$(OBJS_DIR)\vect_174.$(EXT_OBJ): $(OBJS_DIR)\vect_174.src
$(OBJS_DIR)\vect_175.$(EXT_OBJ): $(OBJS_DIR)\vect_175.src
$(OBJS_DIR)\vect_176.$(EXT_OBJ): $(OBJS_DIR)\vect_176.src
$(OBJS_DIR)\vect_177.$(EXT_OBJ): $(OBJS_DIR)\vect_177.src
$(OBJS_DIR)\vect_178.$(EXT_OBJ): $(OBJS_DIR)\vect_178.src
$(OBJS_DIR)\vect_179.$(EXT_OBJ): $(OBJS_DIR)\vect_179.src
$(OBJS_DIR)\vect_180.$(EXT_OBJ): $(OBJS_DIR)\vect_180.src
$(OBJS_DIR)\vect_181.$(EXT_OBJ): $(OBJS_DIR)\vect_181.src
$(OBJS_DIR)\vect_182.$(EXT_OBJ): $(OBJS_DIR)\vect_182.src
$(OBJS_DIR)\vect_183.$(EXT_OBJ): $(OBJS_DIR)\vect_183.src
$(OBJS_DIR)\vect_184.$(EXT_OBJ): $(OBJS_DIR)\vect_184.src
$(OBJS_DIR)\vect_185.$(EXT_OBJ): $(OBJS_DIR)\vect_185.src
$(OBJS_DIR)\vect_186.$(EXT_OBJ): $(OBJS_DIR)\vect_186.src
$(OBJS_DIR)\vect_187.$(EXT_OBJ): $(OBJS_DIR)\vect_187.src
$(OBJS_DIR)\vect_188.$(EXT_OBJ): $(OBJS_DIR)\vect_188.src
$(OBJS_DIR)\vect_189.$(EXT_OBJ): $(OBJS_DIR)\vect_189.src
$(OBJS_DIR)\vect_190.$(EXT_OBJ): $(OBJS_DIR)\vect_190.src
$(OBJS_DIR)\vect_191.$(EXT_OBJ): $(OBJS_DIR)\vect_191.src
$(OBJS_DIR)\vect_192.$(EXT_OBJ): $(OBJS_DIR)\vect_192.src
$(OBJS_DIR)\vect_193.$(EXT_OBJ): $(OBJS_DIR)\vect_193.src
$(OBJS_DIR)\vect_194.$(EXT_OBJ): $(OBJS_DIR)\vect_194.src
$(OBJS_DIR)\vect_195.$(EXT_OBJ): $(OBJS_DIR)\vect_195.src
$(OBJS_DIR)\vect_196.$(EXT_OBJ): $(OBJS_DIR)\vect_196.src
$(OBJS_DIR)\vect_197.$(EXT_OBJ): $(OBJS_DIR)\vect_197.src
$(OBJS_DIR)\vect_198.$(EXT_OBJ): $(OBJS_DIR)\vect_198.src
$(OBJS_DIR)\vect_199.$(EXT_OBJ): $(OBJS_DIR)\vect_199.src
$(OBJS_DIR)\vect_200.$(EXT_OBJ): $(OBJS_DIR)\vect_200.src
$(OBJS_DIR)\vect_201.$(EXT_OBJ): $(OBJS_DIR)\vect_201.src
$(OBJS_DIR)\vect_202.$(EXT_OBJ): $(OBJS_DIR)\vect_202.src
$(OBJS_DIR)\vect_203.$(EXT_OBJ): $(OBJS_DIR)\vect_203.src
$(OBJS_DIR)\vect_204.$(EXT_OBJ): $(OBJS_DIR)\vect_204.src
$(OBJS_DIR)\vect_205.$(EXT_OBJ): $(OBJS_DIR)\vect_205.src
$(OBJS_DIR)\vect_206.$(EXT_OBJ): $(OBJS_DIR)\vect_206.src
$(OBJS_DIR)\vect_207.$(EXT_OBJ): $(OBJS_DIR)\vect_207.src
$(OBJS_DIR)\vect_208.$(EXT_OBJ): $(OBJS_DIR)\vect_208.src
$(OBJS_DIR)\vect_209.$(EXT_OBJ): $(OBJS_DIR)\vect_209.src
$(OBJS_DIR)\vect_210.$(EXT_OBJ): $(OBJS_DIR)\vect_210.src
$(OBJS_DIR)\vect_211.$(EXT_OBJ): $(OBJS_DIR)\vect_211.src
$(OBJS_DIR)\vect_212.$(EXT_OBJ): $(OBJS_DIR)\vect_212.src
$(OBJS_DIR)\vect_213.$(EXT_OBJ): $(OBJS_DIR)\vect_213.src
$(OBJS_DIR)\vect_214.$(EXT_OBJ): $(OBJS_DIR)\vect_214.src
$(OBJS_DIR)\vect_215.$(EXT_OBJ): $(OBJS_DIR)\vect_215.src
$(OBJS_DIR)\vect_216.$(EXT_OBJ): $(OBJS_DIR)\vect_216.src
$(OBJS_DIR)\vect_217.$(EXT_OBJ): $(OBJS_DIR)\vect_217.src
$(OBJS_DIR)\vect_218.$(EXT_OBJ): $(OBJS_DIR)\vect_218.src
$(OBJS_DIR)\vect_219.$(EXT_OBJ): $(OBJS_DIR)\vect_219.src
$(OBJS_DIR)\vect_220.$(EXT_OBJ): $(OBJS_DIR)\vect_220.src
$(OBJS_DIR)\vect_221.$(EXT_OBJ): $(OBJS_DIR)\vect_221.src
$(OBJS_DIR)\vect_222.$(EXT_OBJ): $(OBJS_DIR)\vect_222.src
$(OBJS_DIR)\vect_223.$(EXT_OBJ): $(OBJS_DIR)\vect_223.src
$(OBJS_DIR)\vect_224.$(EXT_OBJ): $(OBJS_DIR)\vect_224.src
$(OBJS_DIR)\vect_225.$(EXT_OBJ): $(OBJS_DIR)\vect_225.src
$(OBJS_DIR)\vect_226.$(EXT_OBJ): $(OBJS_DIR)\vect_226.src
$(OBJS_DIR)\vect_227.$(EXT_OBJ): $(OBJS_DIR)\vect_227.src
$(OBJS_DIR)\vect_228.$(EXT_OBJ): $(OBJS_DIR)\vect_228.src
$(OBJS_DIR)\vect_229.$(EXT_OBJ): $(OBJS_DIR)\vect_229.src
$(OBJS_DIR)\vect_230.$(EXT_OBJ): $(OBJS_DIR)\vect_230.src
$(OBJS_DIR)\vect_231.$(EXT_OBJ): $(OBJS_DIR)\vect_231.src
$(OBJS_DIR)\vect_232.$(EXT_OBJ): $(OBJS_DIR)\vect_232.src
$(OBJS_DIR)\vect_233.$(EXT_OBJ): $(OBJS_DIR)\vect_233.src
$(OBJS_DIR)\vect_234.$(EXT_OBJ): $(OBJS_DIR)\vect_234.src
$(OBJS_DIR)\vect_235.$(EXT_OBJ): $(OBJS_DIR)\vect_235.src
$(OBJS_DIR)\vect_236.$(EXT_OBJ): $(OBJS_DIR)\vect_236.src
$(OBJS_DIR)\vect_237.$(EXT_OBJ): $(OBJS_DIR)\vect_237.src
$(OBJS_DIR)\vect_238.$(EXT_OBJ): $(OBJS_DIR)\vect_238.src
$(OBJS_DIR)\vect_239.$(EXT_OBJ): $(OBJS_DIR)\vect_239.src
$(OBJS_DIR)\vect_240.$(EXT_OBJ): $(OBJS_DIR)\vect_240.src
$(OBJS_DIR)\vect_241.$(EXT_OBJ): $(OBJS_DIR)\vect_241.src
$(OBJS_DIR)\vect_242.$(EXT_OBJ): $(OBJS_DIR)\vect_242.src
$(OBJS_DIR)\vect_243.$(EXT_OBJ): $(OBJS_DIR)\vect_243.src
$(OBJS_DIR)\vect_244.$(EXT_OBJ): $(OBJS_DIR)\vect_244.src
$(OBJS_DIR)\vect_245.$(EXT_OBJ): $(OBJS_DIR)\vect_245.src
$(OBJS_DIR)\vect_246.$(EXT_OBJ): $(OBJS_DIR)\vect_246.src
$(OBJS_DIR)\vect_247.$(EXT_OBJ): $(OBJS_DIR)\vect_247.src
$(OBJS_DIR)\vect_248.$(EXT_OBJ): $(OBJS_DIR)\vect_248.src
$(OBJS_DIR)\vect_249.$(EXT_OBJ): $(OBJS_DIR)\vect_249.src
$(OBJS_DIR)\vect_250.$(EXT_OBJ): $(OBJS_DIR)\vect_250.src
$(OBJS_DIR)\vect_251.$(EXT_OBJ): $(OBJS_DIR)\vect_251.src
$(OBJS_DIR)\vect_252.$(EXT_OBJ): $(OBJS_DIR)\vect_252.src
$(OBJS_DIR)\vect_253.$(EXT_OBJ): $(OBJS_DIR)\vect_253.src
$(OBJS_DIR)\vect_254.$(EXT_OBJ): $(OBJS_DIR)\vect_254.src
$(OBJS_DIR)\vect_255.$(EXT_OBJ): $(OBJS_DIR)\vect_255.src



# end of file
