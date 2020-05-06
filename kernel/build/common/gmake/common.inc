# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# %jp{特殊文字定義}%en{special characters}
comma:= ,
empty:=
space:= $(empty) $(empty)



# %jp{ツール定義}%en{Tools}
CMD_ECHO   ?= echo
CMD_CD     ?= cd
CMD_MKDIR  ?= mkdir -p
CMD_CP     ?= cp
CMD_MV     ?= mv
CMD_RM     ?= rm -f
CMD_DEPEND ?= gcc

ifeq ($(OS),Windows_NT)
CMD_MKDIR = cmd.exe /C unix_mkdir -p
CMD_RM    = cmd.exe /C unix_rm -f
endif


# end of file
