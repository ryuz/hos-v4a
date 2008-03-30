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
ifneq ($(INC_DIRS),)
CFLAGS_INC = $(patsubst %,-I%,$(INC_DIRS))
endif

# %jp{C言語マクロ定義オプションの定義}%en{C-compiler define macros}
ifneq ($(C_DEFS),)
CFLAGS_DEF = $(patsubst %,-D%,$(C_DEFS))
endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
ifneq ($(INC_DIRS),)
AFLAGS_INC =
endif

# %jp{アセンブリ言語マクロ定義オプションの定義}%en{Assembler define macros}
ifneq ($(A_DEFS),)
AFLAGS_DEF = $(patsubst %,-D %,$(A_DEFS))
endif


# %jp{オプション統合}{Options marged}
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(AFLAGS_INC) $(AFLAGS_DEF)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_LINK) $(LNFLAGS) -o $(TARGET_EXE) $(OBJS) $(patsubst %,-l%,$(LIBS))


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_OBJCNV) -S3 -o $(TARGET_MOT) $(TARGET_EXE)


# %jp{インテルHEX形式ファイル生成}%en{Intel HEX format file}
$(TARGET_HEX): $(TARGET_EXE)
	$(CMD_OBJCNV) -i -o $(TARGET_HEX) $(TARGET_EXE)


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_RM) -f $(TARGET_LIB)
	$(CMD_LIBR) $(TARGET_LIB) -c $(OBJS)


# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	echo $(CFLAGS_INC)
	echo $(CFLAGS_DEF)
	$(CMD_CC)  $(CFLAGS) $< -o $@


# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) $< -o $@



# end of file
