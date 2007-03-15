# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{ツール定義}%en{Tools}
CMD_CC     ?= armcc
CMD_ASM    ?= armasm
CMD_LIBR   ?= armar
CMD_LINK   ?= armlink
CMD_OBJCNV ?= fromelf
CMD_DEPEND ?= gcc

# %jp{拡張子定義}
EXT_C   ?= c
EXT_CPP ?= cpp
EXT_ASM ?= s
EXT_OBJ ?= o
EXT_LIB ?= a
EXT_EXE ?= axf
EXT_ASC ?= mot
EXT_BIN ?= bin


# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS += -c --apcs /interwork

# %jp{インクルードパスオプションの定義}
CFLAGS_INC = $(patsubst %,-I%,$(INC_DIRS))

# %jp{マクロ定義オプションの定義}
CFLAGS_DEF = 

# %jp{デバッグオプションの定義}
CFLAGS_DBG = -g

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE   = -O0
CFLAGS_OPT_SIZE   = -O3 -Ospace
CFLAGS_OPT_SPEED  = -O3 -Otime
CFLAGS_OPT_NORMAL = -O3


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS += --apcs /interwork

# %jp{インクルードパスオプションの定義}
AFLAGS_INC = 

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF = 

# %jp{デバッグオプションの定義}
AFLAGS_DBG = -g

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =


# ----------------------------------
#  makedepend
# ----------------------------------

# %jp{オプションの設定}
DEPFLAGS += -MM $(patsubst %,-I%,$(INC_DIRS))


# end of file
