# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2008 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------
#  %jp{オプション解析}%en{analyze option}
# --------------------------------------

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}%en{debug mode}
TARGET := $(TARGET)dbg
C_DEFS += _DEBUG
A_DEFS += _DEBUG
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
else
ifeq ($(OPT_SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}%en{speed optimize}
AFLAGS += $(AFLAGS_OPT_SPEED)
CFLAGS += $(CFLAGS_OPT_SPEED)
else
ifeq ($(OPT_SIZE),Yes)
# %jp{サイズ優先適化指定があればサイズ優先}%en{size optimize}
AFLAGS += $(AFLAGS_OPT_SIZE)
CFLAGS += $(CFLAGS_OPT_SIZE)
else
# %jp{デフォルトで通常の最適化}%en{default}
AFLAGS += $(AFLAGS_OPT_NORMAL)
CFLAGS += $(CFLAGS_OPT_NORMAL)
endif
endif
endif



# --------------------------------------
#  %jp{カーネルライブラリの選択}%en{select kernel library}
# --------------------------------------

KERNEL_LIB_NAME ?= libhosv4a
KERNEL_MAKOPT   ?=

# %jp{デバッグ指定}%en{debug mode}
KERNEL_MAKOPT += DEBUG=$(KERNEL_DEBUG)
ifeq ($(KERNEL_DEBUG),Yes)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)dbg
endif


# %jp{エラーレベル指定}%en{error check level}
KERNEL_MAKOPT += ERRLEVEL=$(KERNEL_ERRLEVEL)
ifeq ($(KERNEL_ERRLEVEL),0)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)er0
endif
ifeq ($(KERNEL_ERRLEVEL),1)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)er1
endif
ifeq ($(KERNEL_ERRLEVEL),2)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)er2
endif
ifeq ($(KERNEL_ERRLEVEL),3)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)er3
endif
ifeq ($(KERNEL_ERRLEVEL),4)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)er4
endif


# %jp{カーネルフック指定}%en{kernel hook}
KERNEL_MAKOPT += HOK_TSK=$(KERNEL_HOK_TSK)
ifeq ($(KERNEL_HOK_TSK),Yes)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)tsk
endif
KERNEL_MAKOPT += HOK_INH=$(KERNEL_HOK_INH)
ifeq ($(KERNEL_HOK_INH),Yes)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)inh
endif
KERNEL_MAKOPT += HOK_ISR=$(KERNEL_HOK_ISR)
ifeq ($(KERNEL_HOK_ISR),Yes)
KERNEL_LIB_NAME := $(KERNEL_LIB_NAME)isr
endif

# %jp{カーネルライブラリ}%en{kernel library}
KERNEL_LIB = $(KERNEL_BUILD_DIR)/$(KERNEL_LIB_NAME).$(EXT_LIB)



# --------------------------------------
#  %jp{カーネル利用の設定}%en{add kernel setting}
# --------------------------------------

INC_DIRS += $(KERNEL_DIR)/include
LIBS     += $(KERNEL_LIB)



# --------------------------------------
#  %jp{各種設定}%en{other setting}
# --------------------------------------

# %jp{サーチパス設定}
VPATH = $(subst $(space),:,$(SRC_DIRS))


# %jp{オブジェクトファイル出力ディレクトリ}
OBJS_DIR = objs_$(TARGET)


# %jp{オブジェクトファイル}
OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(ASRCS)))))	\
       $(addprefix $(OBJS_DIR)/, $(addsuffix .$(EXT_OBJ), $(basename $(notdir $(CSRCS)))))



# end of file
