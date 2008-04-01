# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common include file for library file
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
# %jp{デバッグ指定があればデバッグ版作成}%en{debug version}
TARGET = $(TARGET)dbg
CFLAGS = $(CFLAGS) $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
AFLAGS = $(AFLAGS) $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
!if "$(KERNEL)" == "Yes"
C_DEFS = $(C_DEFS) _KERNEL_DEBUG
A_DEFS = $(A_DEFS) _KERNEL_DEBUG
!else
C_DEFS = $(C_DEFS) _DEBUG
A_DEFS = $(A_DEFS) _DEBUG
!endif
!else
!if "$(OPT_SPEED)" == "Yes"
# %jp{速度最適化指定があれば速度優先}%en{optimize speed}
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SPEED)
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SPEED)
!else
!if "$(OPT_SIZE)" == "Yes"
# %jp{サイズ優先適化指定があればサイズ優先}%en{optimize size}
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_SIZE)
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_SIZE)
!else
# %jp{デフォルトで通常の最適化}%en{optimize}
CFLAGS = $(CFLAGS) $(AFLAGS_OPT_NORMAL)
AFLAGS = $(AFLAGS) $(AFLAGS_OPT_NORMAL)
!endif
!endif
!endif


# %jp{エラーレベル指定}%en{error check level}
!if "$(ERRLEVEL)" != ""
!if $(ERRLEVEL) == 0
TARGET = $(TARGET)er0
C_DEFS = $(C_DEFS) _KERNEL_ERRLEVEL=0
!else if $(ERRLEVEL) == 1
TARGET = $(TARGET)er1
C_DEFS = $(C_DEFS) _KERNEL_ERRLEVEL=1
!else if $(ERRLEVEL) == 1
TARGET = $(TARGET)er2
C_DEFS = $(C_DEFS) _KERNEL_ERRLEVEL=2
!else if $(ERRLEVEL) == 1
TARGET = $(TARGET)er3
C_DEFS = $(C_DEFS) _KERNEL_ERRLEVEL=3
!else if $(ERRLEVEL) == 1
TARGET := $(TARGET)er4
C_DEFS = $(C_DEFS) _KERNEL_ERRLEVEL=4
!endif
!endif



# --------------------------------------
#  %jp{各種マクロ文字の正規化}%en{Regularization}
# --------------------------------------

OBJS = $(OBJS:	= )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS = @$(OBJS)@
OBJS = $(OBJS:@ =)
OBJS = $(OBJS: @=)
OBJS = $(OBJS:@=)



# --------------------------------------
#  %jp{ターゲット定義}%en{Target}
# --------------------------------------

# %jp{オブジェクトファイル出力ディレクトリ}
OBJS_DIR   = objs_$(TARGET)

# %jp{ターゲットライブラリファイル名}%en{Target}
TARGET_LIB = $(TARGET).$(EXT_LIB)



# end of file
