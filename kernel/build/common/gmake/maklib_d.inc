# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2008 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{オプション解析}
# --------------------------------------

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}
TARGET := $(TARGET)dbg
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
ifeq ($(KERNEL),Yes)
C_DEFS += _KERNEL_DEBUG
A_DEFS += _KERNEL_DEBUG
else
C_DEFS += _DEBUG
A_DEFS += _DEBUG
endif
else
ifeq ($(OPT_SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}%en{optimize speed}
CFLAGS += $(CFLAGS_OPT_SPEED)
AFLAGS += $(AFLAGS_OPT_SPEED)
else
ifeq ($(OPT_SIZE),Yes)
# %jp{サイズ優先適化指定があればサイズ優先}%en{optimize size}
CFLAGS += $(CFLAGS_OPT_SIZE)
AFLAGS += $(AFLAGS_OPT_SIZE)
else
# %jp{デフォルトで通常の最適化}%en{optimize}
CFLAGS += $(CFLAGS_OPT_NORMAL)
AFLAGS += $(AFLAGS_OPT_NORMAL)
endif
endif
endif


# %jp{カーネルエラーレベル指定}%en{error check level}
ifeq ($(ERRLEVEL),0)
TARGET := $(TARGET)er0
C_DEFS += _KERNEL_ERRLEVEL=0
endif
ifeq ($(ERRLEVEL),1)
TARGET := $(TARGET)er1
C_DEFS += _KERNEL_ERRLEVEL=1
endif
ifeq ($(ERRLEVEL),2)
TARGET := $(TARGET)er2
C_DEFS += _KERNEL_ERRLEVEL=2
endif
ifeq ($(ERRLEVEL),3)
TARGET := $(TARGET)er3
C_DEFS += _KERNEL_ERRLEVEL=3
endif
ifeq ($(ERRLEVEL),4)
TARGET := $(TARGET)er4
C_DEFS += _KERNEL_ERRLEVEL=4
endif


# %jp{カーネルフック指定}%en{kernel hook}
ifeq ($(HOK_TSK),Yes)
TARGET := $(TARGET)tsk
C_DEFS += _KERNEL_HOK_TSK
endif
ifeq ($(HOK_INH),Yes)
TARGET := $(TARGET)inh
C_DEFS += _KERNEL_HOK_INH
endif
ifeq ($(HOK_ISR),Yes)
TARGET := $(TARGET)isr
C_DEFS += _KERNEL_HOK_ISR
endif




# --------------------------------------
#  %jp{各種設定}%en{target setting}
# --------------------------------------


# %jp{ターゲットライブラリファイル名}
TARGET_LIB = $(TARGET).$(EXT_LIB)


# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))


# %jp{オブジェクトファイル出力ディレクトリ}
OBJS_DIR = objs_$(TARGET)


# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(CSRCS)))))   \
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(ASRCS)))))





# end of file
