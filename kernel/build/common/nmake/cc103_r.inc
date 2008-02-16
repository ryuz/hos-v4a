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
CFLAGS_INC = -I$(INC_DIRS: = -I)
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
CFLAGS_DEF = -D$(C_DEFS: = -D)
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
AFLAGS_DEF = -D$(A_DEFS: = -D)
!endif


# jp{リンクライブラリのオブジェクトの定義}%en{}
!ifdef LIBS
LIBS = $(LIBS:	= )
LIBS = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS = $(LIBS:  = )
LIBS = @$(LIBS)@
LIBS = $(LIBS:@ =)
LIBS = $(LIBS: @=)
LIBS = $(LIBS:@=)
LIBS_LINK = -l$(LIBS: = -l)
!endif


# %jp{基本オプション設定}{Options marged}
CFLAGS = $(CFLAGS) $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS = $(AFLAGS) $(AFLAGS_INC) $(AFLAGS_DEF)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
!ifdef TARGET_EXE
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(LIBS_LINK)
!endif


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
!ifdef TARGET_MOT
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) -S3 -o $(TARGET_MOT) $(TARGET_EXE)
!endif


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
!ifdef TARGET_HEX
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) -i -o $(TARGET_HEX) $(TARGET_EXE)
!endif


# %jp{ライブラリ生成}%en{Library}
!ifdef TARGET_LIB
$(TARGET_LIB): $(OBJS)
	-del $(TARGET_LIB)
	$(CMD_LIBR) $(TARGET_LIB) -c $(OBJS)
!endif


# %jp{Cコンパイル}%en{C Compile}
{$(OBJS_DIR)}.c{$(OBJS_DIR)}.ro :
	$(CMD_CC)  $(CFLAGS) $< -o $@


# %jp{アセンブル}%en{Assemble}
{$(OBJS_DIR)}.as{$(OBJS_DIR)}.ro :
	$(CMD_ASM) $(AFLAGS) $< -o $@


# end of file
