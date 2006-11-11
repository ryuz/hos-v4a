

ifeq ($(DEBUG),Yes)
# %jp{デバッグ指定があればデバッグ版作成}
TARGET := $(TARGET)_dbg
AFLAGS += $(AFLAGS_DBG) $(AFLAGS_OPT_NONE)
CFLAGS += $(CFLAGS_DBG) $(CFLAGS_OPT_NONE)
else
ifeq ($(SPEED),Yes)
# %jp{速度最適化指定があれば速度優先}
AFLAGS += $(AFLAGS_OPT_SPEED)
CFLAGS += $(AFLAGS_OPT_SPEED)
else
# %jp{デフォルトでサイズ優先}
AFLAGS += $(AFLAGS_OPT_SIZE)
CFLAGS += $(AFLAGS_OPT_SIZE)
endif
endif

# %jp{エラーレベル指定}
ifeq ($(ERRLEVEL),0)
TARGET := $(TARGET)_er0
C_DEF  += _KERNEL_ERRLEVEL=0
endif
ifeq ($(ERRLEVEL),1)
TARGET := $(TARGET)_er1
C_DEF  += _KERNEL_ERRLEVEL=1
endif
ifeq ($(ERRLEVEL),2)
TARGET := $(TARGET)_er2
C_DEF  += _KERNEL_ERRLEVEL=2
endif
ifeq ($(ERRLEVEL),3)
TARGET := $(TARGET)_er3
C_DEF  += _KERNEL_ERRLEVEL=3
endif
ifeq ($(ERRLEVEL),4)
TARGET := $(TARGET)_er4
C_DEF  += _KERNEL_ERRLEVEL=4
endif


# 基本オプション設定
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)


