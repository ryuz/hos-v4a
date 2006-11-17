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


# %jp{ツール定義}%en{Tools}
CMD_CC   ?= armcc
CMD_ASM  ?= armasm
CMD_LIBR ?= armar
CMD_LINK ?= armlink


# %jp{拡張子定義}
C_EXT   ?= c
CPP_EXT ?= cpp
ASM_EXT ?= s
OBJ_EXT ?= o
LIB_EXT ?= l
EXE_EXT ?= axf
ASC_EXT ?= mot
BIN_EXT ?= bin


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
CFLAGS_OPT_NONE  = -O0
CFLAGS_OPT_SIZE  = -O3 -Ospace
CFLAGS_OPT_SPEED = -O3 -Otime


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


# end of file
