# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{コマンド定義}%en{Tools}
CMD_CC     ?= cc103S
CMD_ASM    ?= as103S
CMD_LIBR   ?= ar103S
CMD_LINK   ?= cc103S
CMD_OBJCNV ?= xcv103


# %jp{拡張子定義}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= as
EXT_OBJ ?= ro
EXT_LIB ?= l
EXT_EXE ?= x
EXT_MOT ?= mot
EXT_HEX ?= hex
EXT_BIN ?= bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
CFLAGS += -c -g


# %jp{デバッグオプションの定義}%en{debug options}
CFLAGS_DBG =


# %jp{最適化オプションの定義}%en{optimize options}
CFLAGS_OPT_NONE   = 
CFLAGS_OPT_NORMAL = -O
CFLAGS_OPT_SIZE   = -Os
CFLAGS_OPT_SPEED  = -Ot


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS += -g


# %jp{デバッグオプションの定義}
AFLAGS_DBG = -g


# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   =
AFLAGS_OPT_NORMAL =
AFLAGS_OPT_SIZE   =
AFLAGS_OPT_SPEED  =



# end of file
