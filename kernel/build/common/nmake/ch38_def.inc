# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .obj .c .src

# %jp{ツール定義}%en{Tools}
!ifndef CMD_CC
CMD_CC   = ch38
!endif
!ifndef CMD_ASM
CMD_ASM  = asm38
!endif
!ifndef CMD_LIBR
CMD_LIBR = optlnk
!endif

# %jp{拡張子定義}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = src
EXT_OBJ = obj
EXT_LIB = lib
EXT_EXE = abs
EXT_ASC = mot
EXT_BIN = bin


# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS = $(CFLAGS) -NOLOGO -NOList

# %jp{インクルードパスオプションの定義}
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)


CFLAGS_INC = -I=$(INC_DIRS: =,)

# %jp{マクロ定義オプションの定義}
CFLAGS_DEF = 

# %jp{デバッグオプションの定義}
CFLAGS_DBG = -DEBug

# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE  = -OP=0
CFLAGS_OPT_SIZE  = -OP=1
CFLAGS_OPT_SPEED = -OP=1


# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS = $(AFLAGS) -NOLOGO

# %jp{インクルードパスオプションの定義}
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
AFLAGS_INC = -I=$(INC_DIRS: =,)

# %jp{マクロ定義オプションの定義}
AFLAGS_DEF = 

# %jp{デバッグオプションの定義}
AFLAGS_DBG = -DEBug

# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =


# end of file
