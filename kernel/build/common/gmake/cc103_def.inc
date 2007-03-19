# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)


# %jp{コマンド定義}%en{Tools}
CMD_CC   ?= cc103S
CMD_ASM  ?= cc103S
CMD_LIBR ?= ar103S

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

# %jp{共通オプションの設定}
CFLAGS += -c -g

# %jp{インクルードパスオプションの定義}
CFLAGS_INC = $(patsubst %,-I%,$(INC_DIRS))

# %jp{マクロ定義オプションの定義}
CFLAGS_DEF = $(patsubst %,-D%,$(C_DEFS))

# %jp{デバッグオプションの定義}
CFLAGS_DBG = -g

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE   = -OP=0
CFLAGS_OPT_NORMAL = -O
CFLAGS_OPT_SIZE   = -Os
CFLAGS_OPT_SPEED  = -Ot


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS += -c -g

# %jp{インクルードパスオプションの定義}
AFLAGS_INC = $(patsubst %,-I%,$(INC_DIRS))

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF = $(patsubst %,-D%,$(C_DEFS))

# %jp{デバッグオプションの定義}
AFLAGS_DBG = -g

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   =
CFLAGS_OPT_NORMAL =
AFLAGS_OPT_SIZE   =
AFLAGS_OPT_SPEED  =


# end of file
