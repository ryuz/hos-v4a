# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


.SUFFIXES :
.SUFFIXES : .obj .c .asm


# %jp{ツール定義}%en{Tools}
!ifndef CMD_CC
CMD_CC   = cl
!endif
!ifndef CMD_ASM
CMD_ASM  = masm
!endif
!ifndef CMD_LIBR
CMD_LIBR = lib
!endif
!ifndef CMD_LINK
CMD_LINK = cl
!endif


# %jp{拡張子定義}
EXT_C   = c
EXT_CPP = cpp
EXT_ASM = asm
EXT_OBJ = obj
EXT_LIB = lib
EXT_EXE = exe
EXT_MOT = mot
EXT_HEX = hex
EXT_BIN = bin



# ----------------------------------
#  C-compiler
# ----------------------------------

# %jp{共通オプションの設定}
CFLAGS = $(CFLAGS) /c


# %jp{インクルードパスオプションの定義}
!ifdef INC_DIRS
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)
CFLAGS_INC = /I$(INC_DIRS: = /I)
!endif


# %jp{マクロ定義オプションの定義}
!ifdef C_DEFS
C_DEFS = $(C_DEFS:	= )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = @$(C_DEFS)@
C_DEFS = $(C_DEFS:@ =)
C_DEFS = $(C_DEFS: @=)
C_DEFS = $(C_DEFS:@=)
CFLAGS_DEF = /D$(C_DEFS: = /D)
!endif


# %jp{デバッグオプションの定義}
CFLAGS_DBG = /Yd


# %jp{最適化オプションの定義}
CFLAGS_OPT_NONE  = /Od
CFLAGS_OPT_SIZE  = /O1
CFLAGS_OPT_SPEED = /O2



# ----------------------------------
#  Assembler
# ----------------------------------

# %jp{共通オプションの設定}
AFLAGS = $(AFLAGS)


# %jp{インクルードパスオプションの定義}
!ifdef INC_DIRS
AFLAGS_INC = -I=$(INC_DIRS: =,)
!endif


# %jp{マクロ定義オプションの定義}
!ifdef A_DEFS
A_DEFS = $(A_DEFS:	= )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = @$(A_DEFS)@
A_DEFS = $(A_DEFS:@ =)
A_DEFS = $(A_DEFS: @=)
A_DEFS = $(A_DEFS:@=)
AFLAGS_DEF = /D$(A_DEFS: = /D)
!endif


# %jp{デバッグオプションの定義}
AFLAGS_DBG = -Yd


# %jp{最適化オプションの定義}
AFLAGS_OPT_NONE  =
AFLAGS_OPT_SIZE  =
AFLAGS_OPT_SPEED =



# end of file
