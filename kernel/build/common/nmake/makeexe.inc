# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

!ifndef DEBUG
DEBUG = "No"
!endif

!ifndef OPT_SPEED
OPT_SPEED = "No"
!endif

!ifndef OPT_SIZE
OPT_SIZE = "No"
!endif

!ifndef KERNEL_DEBUG
KERNEL_DEBUG = "No"
!endif



!if $(DEBUG) == "Yes"
# %jp{デバッグ指定があればデバッグ版作成}
TARGET = $(TARGET)dbg
AFLAGS = $(AFLAGS) $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS = $(CFLAGS) $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
!else
!if $(OPT_SPEED) == "Yes"
# %jp{速度最適化指定があれば速度優先}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SPEED)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SPEED)
!else
!if $(OPT_SIZE) == "Yes"
# %jp{サイズ優先適化指定があればサイズ優先}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SIZE)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SIZE)
!else
# %jp{デフォルトで通常の最適化}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_NORMAL)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_NORMAL)
!endif
!endif
!endif


# --------------------------------------
#  %jp{各種マクロ文字の正規化}
# --------------------------------------

!ifdef OBJS
OBJS = $(OBJS:	= )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = @$(OBJS)@
OBJS = $(OBJS:@ =)
OBJS = $(OBJS: @=)
OBJS = $(OBJS:@=)
!endif

!ifdef LIBS
LIBS = $(LIBS:	= )
LIBS = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS = @$(LIBS)@
LIBS = $(LIBS:@ =)
LIBS = $(LIBS: @=)
LIBS = $(LIBS:@=)
!endif



# --------------------------------------
#  %jp{カーネルライブラリの選択}
# --------------------------------------

!ifndef OS_LIB
OS_LIB = libhosv4a
!endif


# %jp{デバッグ指定}
!if $(KERNEL_DEBUG) == "Yes"
OS_LIB = $(OS_LIB)dbg
!endif


# %jp{エラーレベル指定}
!ifdef KERNEL_ERRLEVEL
!if $(KERNEL_ERRLEVEL) == 0
OS_LIB = $(OS_LIB)er0
!elseif $(KERNEL_ERRLEVEL) == 1
OS_LIB = $(OS_LIB)er1
!elseif $(KERNEL_ERRLEVEL) == 2
OS_LIB = $(OS_LIB)er2
!elseif $(KERNEL_ERRLEVEL) == 3
OS_LIB = $(OS_LIB)er3
!elseif $(KERNEL_ERRLEVEL) == 4
OS_LIB = $(OS_LIB)er4
!endif
!endif



# --------------------------------------
#  %jp{カーネル利用の設定}
# --------------------------------------

INC_DIRS = $(INC_DIRS) $(KERNEL_DIR)\include
LIBS     = $(LIBS) $(KERNEL_BUILD_DIR)\$(OS_LIB).$(EXT_LIB)



# --------------------------------------
#  %jp{各種設定}
# --------------------------------------

# 基本オプション設定
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC) $(AFLAGS_DEF)


# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(EXT_LIB)


# --------------------------------------
#  %jp{ルール}
# --------------------------------------

# %jp{all処理}
makeexe_all: kernel_make mkdir_objs $(CSRCS) $(ASRCS)


# %jp{オブジェクト出力ディレクトリ作成}
mkdir_objs:
	-$(CMD_MKDIR) $(OBJS_DIR)


# %jp{クリーンナップ}
makeexe_clean:
	$(CMD_RM) $(TARGET_LIB) $(OBJS)


# %jp{カーネル生成}
kernel_make:
	$(CMD_CD) $(KERNEL_BUILD_DIR)
	$(MAKE) -f nmake.mak DEBUG=$(KERNEL_DEBUG) ERRLEVEL=$(KERNEL_ERRLEVEL)
	$(CMD_CD) $(MAKEDIR)


# %jp{カーネル生成}
kernel_clean:
	make -C $(KERNEL_BUILD_DIR) -f nmake.mak DEBUG=$(KERNEL_DEBUG) ERRLEVEL=$(KERNEL_ERRLEVEL) clean



# end of file
