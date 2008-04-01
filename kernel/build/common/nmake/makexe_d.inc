# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for execution file
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

!ifndef DEBUG
DEBUG = No
!endif

!ifndef OPT_SPEED
OPT_SPEED = No
!endif

!ifndef OPT_SIZE
OPT_SIZE = No
!endif

!ifndef KERNEL_DEBUG
KERNEL_DEBUG = No
!endif


!if "$(DEBUG)" == "Yes"
# %jp{デバッグ指定があればデバッグ版作成}
TARGET = $(TARGET)dbg
AFLAGS = $(AFLAGS) $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS = $(CFLAGS) $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
!else
!if "$(OPT_SPEED)" == "Yes"
# %jp{速度最適化指定があれば速度優先}
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SPEED)
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SPEED)
!else
!if "$(OPT_SIZE)" == "Yes"
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
#  %jp{ターゲット定義}%en{Target}
# --------------------------------------

# %jp{オブジェクトファイル出力ディレクトリ}
OBJS_DIR   = objs_$(TARGET)

# %jp{ターゲット実行ファイル名}
TARGET_EXE = $(TARGET).$(EXT_EXE)



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

!ifndef KERNEL_LIB_NAME
KERNEL_LIB_NAME = libhosv4a
!endif


# %jp{デバッグ指定}
!if "$(KERNEL_DEBUG)" == "Yes"
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)dbg
!endif


# %jp{エラーレベル指定}
!ifdef KERNEL_ERRLEVEL
!if $(KERNEL_ERRLEVEL) == 0
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)er0
!elseif $(KERNEL_ERRLEVEL) == 1
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)er1
!elseif $(KERNEL_ERRLEVEL) == 2
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)er2
!elseif $(KERNEL_ERRLEVEL) == 3
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)er3
!elseif $(KERNEL_ERRLEVEL) == 4
KERNEL_LIB_NAME = $(KERNEL_LIB_NAME)er4
!endif
!endif

# kernel library
KERNEL_LIB = $(KERNEL_BUILD_DIR)\$(KERNEL_LIB_NAME).$(EXT_LIB)


# --------------------------------------
#  %jp{カーネル利用の設定}
# --------------------------------------

INC_DIRS = $(INC_DIRS) $(KERNEL_DIR)\include
LIBS     = $(LIBS) $(KERNEL_LIB)



# end of file
