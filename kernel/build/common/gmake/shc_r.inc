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
CFLAGS_INC = -I=$(subst $(space),$(comma),$(strip $(INC_DIRS)))
endif


# %jp{C言語マクロ定義オプションの定義}%en{C-compiler define macros}
ifneq ($(C_DEFS),)
CFLAGS_DEF = -DEF=$(subst $(space),$(comma),$(strip $(C_DEFS)))
endif


# %jp{アセンブリ言語インクルードパスオプションの定義}%en{Assembler include path}
ifneq ($(INC_DIRS),)
AFLAGS_INC = -I=$(subst $(space),$(comma),$(strip $(INC_DIRS)))
endif


# %jp{アセンブリ言語マクロ定義オプションの定義}%en{Assembler define macros}
ifneq ($(A_DEFS),)
AFLAGS_DEF = -DEF=$(subst $(space),$(comma),$(strip $(A_DEFS)))
endif


# %jp{オプション統合}{Options marged}
CFLAGS += $(CFLAGS_INC) $(CFLAGS_DEF)
AFLAGS += $(AFLAGS_INC)



# --------------------------------------
#  %jpルール定義}%en{Rules}
# --------------------------------------

# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_RM) -f $(TARGET_EXE)
	$(CMD_ECHO) "-rom D=R"                                            > $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-list $(TARGET).map"                                >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-SHow SY,R,X"                                       >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-Input=$(subst $(space),$(comma),$(strip $(OBJS)))" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-LIB=$(subst $(space),$(comma),$(strip $(LIBS)))"   >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-start=VECTTBL/$(SECTION_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(SECTION_RO),B,R,S/$(SECTION_RW)" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-output=$(TARGET_EXE)"                              >> $(OBJS_DIR)/linksub.txt
	$(CMD_LINK) -SU=$(OBJS_DIR)/linksub.txt


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_ECHO) "-input=$(TARGET_EXE)"     > $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-form stype"             >> $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-output $(TARGET_MOT)"   >> $(OBJS_DIR)/ascsub.txt
	$(CMD_OBJCNV) -SU=$(OBJS_DIR)/ascsub.txt


# %jp{ライブラリ生成}%en{Library}
$(TARGET_LIB): $(OBJS)
	$(CMD_RM) -f $(TARGET_LIB)
	$(CMD_ECHO) "-input=$(subst $(space),$(comma),$(strip $(OBJS)))" > $(OBJS_DIR)/librsub.txt
	$(CMD_ECHO) "-output=$(TARGET_LIB)"                             >> $(OBJS_DIR)/librsub.txt
	$(CMD_ECHO) "-form=Library"                                     >> $(OBJS_DIR)/librsub.txt
	$(CMD_LIBR) -SU=$(OBJS_DIR)/librsub.txt


# %jp{Cコンパイル}%en{C Compile}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_C)
	$(CMD_CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)


# %jp{アセンブル}%en{Assemble}
$(OBJS_DIR)/%.$(EXT_OBJ) :: %.$(EXT_ASM)
	$(CMD_ASM) $(AFLAGS) $< -OB=$@


# end of file
