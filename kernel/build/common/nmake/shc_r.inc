# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------




# --------------------------------------
#  %jp{オプション展開}%en{options}
# --------------------------------------

# %jp{C言語インクルードパスオプションの定義}%en{C-compiler include path}
!ifdef INC_DIRS
INC_DIRS = $(INC_DIRS:	= )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = $(INC_DIRS:  = )
INC_DIRS = @$(INC_DIRS)@
INC_DIRS = $(INC_DIRS:@ =)
INC_DIRS = $(INC_DIRS: @=)
INC_DIRS = $(INC_DIRS:@=)

CFLAGS_INC = -I=$(INC_DIRS: =,)
!endif


# %jp{C言語マクロ定義オプションの定義}%en{C-compiler define macros}
!ifdef C_DEFS
C_DEFS = $(C_DEFS:	= )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = $(C_DEFS:  = )
C_DEFS = @$(C_DEFS)@
C_DEFS = $(C_DEFS:@ =)
C_DEFS = $(C_DEFS: @=)
C_DEFS = $(C_DEFS:@=)

CFLAGS_DEF = -DEF=$(C_DEFS: =,)
!endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
!ifdef INC_DIRS
AFLAGS_INC = -I=$(INC_DIRS: =,)
!endif


# %jp{アセンブリ言語マクロ定義オプションの定義}%en{Assembler define macros}
!ifdef A_DEFS
A_DEFS = $(A_DEFS:	= )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = $(A_DEFS:  = )
A_DEFS = @$(A_DEFS)@
A_DEFS = $(A_DEFS:@ =)
A_DEFS = $(A_DEFS: @=)
A_DEFS = $(A_DEFS:@=)

AFLAGS_DEF = -DEF=$(A_DEFS: =,)
!endif


!ifdef OBJS
OBJS = $(OBJS:	= )
OBJS  = $(OBJS:  = )
OBJS = $(OBJS:  = )
OBJS  = $(OBJS:  = )
OBJS = @$(OBJS)@
OBJS  = $(OBJS:@ =)
OBJS  = $(OBJS: @=)
OBJS  = $(OBJS:@=)
!endif


# %jp{オプション統合}{Options marged}
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC)


!ifdef LIBS
LIBS = $(LIBS:	= )
LIBS  = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS  = $(LIBS:  = )
LIBS = @$(LIBS)@
LIBS  = $(LIBS:@ =)
LIBS  = $(LIBS: @=)
LIBS  = $(LIBS:@=)
!endif


# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
!ifdef TARGET_EXE
$(TARGET_EXE): $(OBJS) $(LIBS)
	-$(CMD_RM) $(TARGET_EXE)
	$(CMD_LINK) -SU=<<
-rom D=R
-list $(TARGET).map
-SHow SY,R,X
-Input=$(OBJS: =,)
-LIB=$(LIBS: =,)
-start=VECTTBL/$(SECTION_VECT),P,C,C$$BSEC,C$$DSEC,D/$(SECTION_RO),B,R,S/$(SECTION_RW)
-output=$(TARGET_EXE)
<<
!endif


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
!ifdef TARGET_MOT
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) -SU=<<
-input=$(TARGET_EXE)
-form stype
-output $(TARGET_MOT)
<<
!endif


# %jp{ライブラリ生成}%en{Library}
!ifdef TARGET_LIB
$(TARGET_LIB): $(OBJS)
	-$(CMD_RM) $(TARGET_LIB)
	$(CMD_LIBR) -SUbcommand=<<
-Input=$(OBJS: =,)
-OUtput=$(TARGET_LIB)
-FOrm=Library
<<
!endif


# %jp{Cコンパイル}%en{C Compile}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.obj :
	$(CMD_CC) $(CFLAGS) $< -OB=$@


# %jp{アセンブル}%en{Assemble}
{$(OBJS_DIR)}.src{$(OBJS_DIR)}.obj :
	$(CMD_ASM) $(AFLAGS) $< -OB=$@



# end of file
