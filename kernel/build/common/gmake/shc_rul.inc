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



# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_RM) -f $(TARGET_EXE)
	$(CMD_ECHO) "-rom D=R"                                            > $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-list $(TARGET).map"                                >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-SHow SY,R,X"                                       >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-Input=$(subst $(space),$(comma),$(strip $(OBJS)))" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-LIB=$(subst $(space),$(comma),$(strip $(LIBS)))"   >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-start=VECTTBL/$(SECTION_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(SECTION_ROM),B,R,S/$(SECTION_RAM)" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-output=$(TARGET_EXE)"                              >> $(OBJS_DIR)/linksub.txt
	$(CMD_LINK) -SU=$(OBJS_DIR)/linksub.txt


# %jp{ASCII形式ファイル生成}%en{ASCII file}
$(TARGET_ASC): $(TARGET_EXE)
	$(CMD_ECHO) "-input=$(TARGET_EXE)"     > $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-form stype"             >> $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-output $(TARGET_ASC)"   >> $(OBJS_DIR)/ascsub.txt
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
