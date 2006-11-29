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
SRC_DIRS += $(APLFW_DIR)/system/sysapi								\
            $(APLFW_DIR)/system/handle								\
            $(APLFW_DIR)/system/file								\
            $(APLFW_DIR)/system/memory								\
            $(APLFW_DIR)/system/process								\
            $(APLFW_DIR)/system/command								\
            $(APLFW_DIR)/system/shell								\
            $(APLFW_DIR)/library/container/mempol					\
            $(APLFW_DIR)/library/container/stmbuf					\
            $(APLFW_DIR)/library/container/list						\
            $(APLFW_DIR)/library/container/assoc					\
            $(APLFW_DIR)/driver/serial/pc16550						\
            $(APLFW_DIR)/apl/hello									\
            $(APLFW_DIR)/apl/memdump								\


# C source files
CSRCS    += $(APLFW_DIR)/system/sysapi/sysevt_clear.c				\
            $(APLFW_DIR)/system/sysapi/sysevt_create.c				\
            $(APLFW_DIR)/system/sysapi/sysevt_delete.c				\
            $(APLFW_DIR)/system/sysapi/sysevt_set.c					\
            $(APLFW_DIR)/system/sysapi/sysevt_wait.c				\
            $(APLFW_DIR)/system/sysapi/sysint_clear.c				\
            $(APLFW_DIR)/system/sysapi/sysint_disable.c				\
            $(APLFW_DIR)/system/sysapi/sysint_enable.c				\
            $(APLFW_DIR)/system/sysapi/sysisr_create.c				\
            $(APLFW_DIR)/system/sysapi/sysisr_delete.c				\
            $(APLFW_DIR)/system/sysapi/sysmem_alloc.c				\
            $(APLFW_DIR)/system/sysapi/sysmem_free.c				\
            $(APLFW_DIR)/system/sysapi/sysmem_getmemif.c			\
            $(APLFW_DIR)/system/sysapi/sysmem_getsize.c				\
            $(APLFW_DIR)/system/sysapi/sysmem_realloc.c				\
            $(APLFW_DIR)/system/sysapi/sysmtx_create.c				\
            $(APLFW_DIR)/system/sysapi/sysmtx_delete.c				\
            $(APLFW_DIR)/system/sysapi/sysmtx_lock.c				\
            $(APLFW_DIR)/system/sysapi/sysmtx_unlock.c				\
            $(APLFW_DIR)/system/sysapi/sysprc_create.c				\
            $(APLFW_DIR)/system/sysapi/sysprc_delete.c				\
            $(APLFW_DIR)/system/sysapi/sysprc_exit.c				\
            $(APLFW_DIR)/system/sysapi/sysprc_getcurrenthandle.c	\
            $(APLFW_DIR)/system/sysapi/sysprc_start.c				\
            $(APLFW_DIR)/system/sysapi/system_initialize.c			\
            $(APLFW_DIR)/system/sysapi/system_lock.c				\
            $(APLFW_DIR)/system/sysapi/system_unlock.c				\
            $(APLFW_DIR)/system/sysapi/systim_wait.c				\
            $(APLFW_DIR)/system/handle/handle.c						\
            $(APLFW_DIR)/system/handle/hdlobj.c						\
            $(APLFW_DIR)/system/file/file.c							\
            $(APLFW_DIR)/system/file/filefmt.c						\
            $(APLFW_DIR)/system/file/stdfile.c						\
            $(APLFW_DIR)/system/file/confile.c						\
            $(APLFW_DIR)/system/memory/memory.c						\
            $(APLFW_DIR)/system/process/process.c					\
            $(APLFW_DIR)/system/process/procobj.c					\
            $(APLFW_DIR)/system/command/command.c					\
            $(APLFW_DIR)/system/shell/shell.c						\
            $(APLFW_DIR)/library/container/mempol/mempol.c			\
            $(APLFW_DIR)/library/container/stmbuf/stmbuf.c			\
            $(APLFW_DIR)/library/container/list/list.c				\
            $(APLFW_DIR)/library/container/assoc/assoc.c			\
            $(APLFW_DIR)/driver/serial/pc16550/pc16550hal.c			\
            $(APLFW_DIR)/driver/serial/pc16550/pc16550drv.c			\
            $(APLFW_DIR)/driver/serial/pc16550/pc16550file.c		\
            $(APLFW_DIR)/apl/hello/hello.c							\
            $(APLFW_DIR)/apl/memdump/memdump.c						\


# end of file
