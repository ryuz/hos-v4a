# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .ro .c .as


# %jp{コマンド定義}%en{Tools}
!ifndef CMD_CC
CMD_CC   = cc103S
!endif
!ifndef CMD_ASM
CMD_ASM  = cc103S
!endif
!ifndef CMD_LIBR
CMD_LIBR = ar103S
!endif


# %jp{拡張子定義}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = as
EXT_OBJ = ro
EXT_LIB = l
EXT_EXE = x



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS = $(CFLAGS) -c -g

# %jp{インクルードパスオプションの定義}
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)

CFLAGS_INC = -I$(INC_DIRS: = -I)


# %jp{マクロ定義オプションの定義}
CFLAGS_DEF = 

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
AFLAGS = $(AFLAGS) -c

# %jp{インクルードパスオプションの定義}
AFLAGS_INC = 

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF = 

# %jp{デバッグオプションの定義}
AFLAGS_DBG = -g

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE   =
CFLAGS_OPT_NORMAL =
AFLAGS_OPT_SIZE   =
AFLAGS_OPT_SPEED  =


# end of file