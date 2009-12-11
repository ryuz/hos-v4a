# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= gcc
CMD_ASM    ?= gcc
CMD_LIBR   ?= ar
CMD_LINK   ?= gcc
CMD_OBJCNV ?= objcopy


# %jp{拡張子定義}%en{file extensions}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= S
EXT_OBJ ?= o
EXT_LIB ?= a
EXT_EXE ?= out
EXT_MOT ?= mot
EXT_HEX ?= hex
EXT_BIN ?= bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
CFLAGS += -Wall -g


# %jp{デバッグオプションの定義}%en{debug options}
CFLAGS_DBG ?=


# %jp{最適化オプションの定義}%en{optimize options}
CFLAGS_OPT_NONE   ?= -O0
CFLAGS_OPT_SIZE   ?= -Os
CFLAGS_OPT_SPEED  ?= -O3
CFLAGS_OPT_NORMAL ?= -O2



# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}%en{common options}
AFLAGS +=


# %jp{デバッグオプションの定義}%en{debug options}
AFLAGS_DBG ?= -g


# %jp{最適化オプションの定義}%en{optimize options}
AFLAGS_OPT_NONE   ?=
AFLAGS_OPT_NORMAL ?=
AFLAGS_OPT_SIZE   ?=
AFLAGS_OPT_SPEED  ?=



# end of file
