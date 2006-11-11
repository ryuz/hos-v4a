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


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(RM) -f $(TARGET_LIB)
	$(ECHO) "-Input=$(subst $(space),$(comma),$(strip $(OBJS)))" > $(OBJS_DIR)/subcmd.txt
	$(ECHO) "-OUtput=$(TARGET_LIB)"                             >> $(OBJS_DIR)/subcmd.txt
	$(ECHO) "-FOrm=Library"                                     >> $(OBJS_DIR)/subcmd.txt
	$(LIBR) "-SU=$(OBJS_DIR)/subcmd.txt"


# %jp{Cコンパイル}
$(OBJS_DIR)/%.obj :: %.c
	$(CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)


# %jp{アセンブル}
$(OBJS_DIR)/%.obj :: %.src
	$(ASM) $(AFLAGS) $< -OB=$@



# end of file
