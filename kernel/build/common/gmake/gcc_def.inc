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

# %jp{拡張子定義}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= S
EXT_OBJ ?= o
EXT_LIB ?= a
EXT_EXE ?= elf
EXT_ASC ?= mot
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
CFLAGS_OPT_NONE   ?= -O0
CFLAGS_OPT_NORMAL ?= -O2
CFLAGS_OPT_SIZE   ?= -Os
CFLAGS_OPT_SPEED  ?= -O3


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS +=

# %jp{インクルードパスオプションの定義}
AFLAGS_INC ?= $(patsubst %,-I%,$(INC_DIRS))

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
