# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= ca850
CMD_ASM    ?= as850
CMD_LIBR   ?= ar850
CMD_LINK   ?= ld850
CMD_OBJCNV ?= hx850

# %jp{拡張子定義}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= s
EXT_OBJ ?= o
EXT_LIB ?= a
EXT_EXE ?= out
EXT_MOT ?= mot
EXT_HEX ?= hex
EXT_BIN ?= bin


# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS +=

# %jp{インクルードパスオプションの定義}
CFLAGS_INC ?= $(patsubst %,-I%,$(INC_DIRS))

# %jp{マクロ定義オプションの定義}
CFLAGS_DEF ?= $(patsubst %,-D%,$(C_DEFS))

# %jp{デバッグオプションの定義}
CFLAGS_DBG ?= -g

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE   ?= -Od
CFLAGS_OPT_NORMAL ?= -O
CFLAGS_OPT_SIZE   ?= -Os
CFLAGS_OPT_SPEED  ?= -Ot


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS +=

# %jp{インクルードパスオプションの定義}
AFLAGS_INC ?= 

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF ?= 

# %jp{デバッグオプションの定義}
AFLAGS_DBG ?= -g

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   ?=
AFLAGS_OPT_NORMAL ?=
AFLAGS_OPT_SIZE   ?=
AFLAGS_OPT_SPEED  ?=


# end of file
