# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= sdcc
CMD_ASM    ?= sdcc
CMD_LIBR   ?= sdcclib
CMD_LINK   ?= sdcc
CMD_OBJCNV ?= sdcc

# %jp{拡張子定義}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= S
EXT_OBJ ?= o
EXT_LIB ?= lib
EXT_EXE ?= elf
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
CFLAGS_DBG ?= --debug

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE   ?= 
CFLAGS_OPT_NORMAL ?= 
CFLAGS_OPT_SIZE   ?= --opt-code-size
CFLAGS_OPT_SPEED  ?= --opt-code-speed


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
AFLAGS_DBG ?= --debug

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   ?=
AFLAGS_OPT_NORMAL ?=
AFLAGS_OPT_SIZE   ?=
AFLAGS_OPT_SPEED  ?=


# end of file
