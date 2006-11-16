# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Include directories
INC_DIRS += $(APLFW_DIR)


# Source directories
SRC_DIRS += $(APLFW_DIR)/system/sysapi						\
            $(APLFW_DIR)/system/handle						\
            $(APLFW_DIR)/system/file						\
            $(APLFW_DIR)/system/memory						\
            $(APLFW_DIR)/system/process						\
            $(APLFW_DIR)/system/command						\
            $(APLFW_DIR)/system/shell						\
            $(APLFW_DIR)/library/container/mempol			\
            $(APLFW_DIR)/library/container/stmbuf			\
            $(APLFW_DIR)/library/container/list				\
            $(APLFW_DIR)/library/container/assoc			\
            $(APLFW_DIR)/apl/hello							\


# C source files
CSRCS    += $(APLFW_DIR)/system/sysapi/sysapi.c				\
            $(APLFW_DIR)/system/handle/handle.c				\
            $(APLFW_DIR)/system/handle/hdlobj.c				\
            $(APLFW_DIR)/system/file/file.c					\
            $(APLFW_DIR)/system/file/filefmt.c				\
            $(APLFW_DIR)/system/file/stdfile.c				\
            $(APLFW_DIR)/system/memory/memory.c				\
            $(APLFW_DIR)/system/process/process.c			\
            $(APLFW_DIR)/system/process/procobj.c			\
            $(APLFW_DIR)/system/command/command.c			\
            $(APLFW_DIR)/system/shell/shell.c				\
            $(APLFW_DIR)/library/container/mempol/mempol.c	\
            $(APLFW_DIR)/library/container/stmbuf/stmbuf.c	\
            $(APLFW_DIR)/library/container/list/list.c		\
            $(APLFW_DIR)/library/container/assoc/assoc.c	\
            $(APLFW_DIR)/apl/hello/hello.c					\


# end of file
