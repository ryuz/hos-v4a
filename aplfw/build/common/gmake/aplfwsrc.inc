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
SRC_DIRS += $(APLFW_DIR)/system/sysapi
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


SRC_DIRS += $(APLFW_DIR)/system/handle
CSRCS    += $(APLFW_DIR)/system/handle/handle_close.c				\
            $(APLFW_DIR)/system/handle/handleobj_create.c			\
            $(APLFW_DIR)/system/handle/handleobj_delete.c			\


SRC_DIRS += $(APLFW_DIR)/system/memory
CSRCS    += $(APLFW_DIR)/system/memory/memory.c						\


SRC_DIRS += $(APLFW_DIR)/system/process
CSRCS    += $(APLFW_DIR)/system/process/process.c					\
            $(APLFW_DIR)/system/process/procobj.c					\


SRC_DIRS += $(APLFW_DIR)/system/file
CSRCS    += $(APLFW_DIR)/system/file/file_initialize.c				\
            $(APLFW_DIR)/system/file/file_adddevice.c				\
            $(APLFW_DIR)/system/file/file_addvolume.c				\
            $(APLFW_DIR)/system/file/file_iocontrol.c				\
            $(APLFW_DIR)/system/file/file_open.c					\
            $(APLFW_DIR)/system/file/file_seek.c					\
            $(APLFW_DIR)/system/file/file_read.c					\
            $(APLFW_DIR)/system/file/file_write.c					\
            $(APLFW_DIR)/system/file/file_getchar.c					\
            $(APLFW_DIR)/system/file/file_getstring.c				\
            $(APLFW_DIR)/system/file/file_putchar.c					\
            $(APLFW_DIR)/system/file/file_putstring.c				\
            $(APLFW_DIR)/system/file/fileobj_create.c				\
            $(APLFW_DIR)/system/file/fileobj_delete.c				\
            $(APLFW_DIR)/system/file/volume_openfile.c				\
            $(APLFW_DIR)/system/file/volumeobj_create.c				\
            $(APLFW_DIR)/system/file/stdfile.c						\
            $(APLFW_DIR)/system/file/confile.c						\
            $(APLFW_DIR)/system/file/filefmt.c						\



SRC_DIRS += $(APLFW_DIR)/system/command
CSRCS    += $(APLFW_DIR)/system/command/command.c					\

SRC_DIRS += $(APLFW_DIR)/system/shell
CSRCS    += $(APLFW_DIR)/system/shell/shell.c						\


SRC_DIRS += $(APLFW_DIR)/library/container/mempol
CSRCS    += $(APLFW_DIR)/library/container/mempol/mempol.c			\


SRC_DIRS += $(APLFW_DIR)/library/container/stmbuf
CSRCS    += $(APLFW_DIR)/library/container/stmbuf/stmbuf.c			\


SRC_DIRS += $(APLFW_DIR)/library/container/list		
CSRCS    += $(APLFW_DIR)/library/container/list/list_create.c		\
            $(APLFW_DIR)/library/container/list/list_createex.c		\
            $(APLFW_DIR)/library/container/list/list_addtail.c		\
            $(APLFW_DIR)/library/container/list/list_getat.c		\
            $(APLFW_DIR)/library/container/list/list_getheadpos.c	\
            $(APLFW_DIR)/library/container/list/list_getnextpos.c	\
            $(APLFW_DIR)/library/container/list/list_getprevpos.c	\
            $(APLFW_DIR)/library/container/list/list_gettailpos.c	\
            $(APLFW_DIR)/library/container/list/list_remove.c		\


#
SRC_DIRS += $(APLFW_DIR)/library/container/assoc	
CSRCS    += $(APLFW_DIR)/library/container/assoc/assoc.c			\


#
SRC_DIRS += $(APLFW_DIR)/driver/serial/pc16550
CSRCS    += $(APLFW_DIR)/driver/serial/pc16550/pc16550hal.c			\
            $(APLFW_DIR)/driver/serial/pc16550/pc16550drv.c			\
            $(APLFW_DIR)/driver/serial/pc16550/pc16550file.c		\


#
SRC_DIRS += $(APLFW_DIR)/apl/hello
CSRCS    += $(APLFW_DIR)/apl/hello/hello.c							\

# memdump
SRC_DIRS += $(APLFW_DIR)/apl/memdump
CSRCS    += $(APLFW_DIR)/apl/memdump/memdump.c						\


SRC_DIRS += $(APLFW_DIR)/volume/dev
CSRCS    += $(APLFW_DIR)/volume/dev/devvol_create.c					\
            $(APLFW_DIR)/volume/dev/devvol_delete.c					\
            $(APLFW_DIR)/volume/dev/devvol_adddevice.c				\
            $(APLFW_DIR)/volume/dev/devvol_openfile.c				\


# FAT
SRC_DIRS += $(APLFW_DIR)/volume/fat
CSRCS    += $(APLFW_DIR)/volume/fat/fatvol_clusterread.c			\
            $(APLFW_DIR)/volume/fat/fatvol_clusterwrite.c			\
            $(APLFW_DIR)/volume/fat/fatvol_create.c					\
            $(APLFW_DIR)/volume/fat/fatvol_open.c					\
            $(APLFW_DIR)/volume/fat/fatvol_getclusterbuf.c			\
            $(APLFW_DIR)/volume/fat/fatvol_getnextcluster.c			\
            $(APLFW_DIR)/volume/fat/fatvol_relclusterbuf.c			\
            $(APLFW_DIR)/volume/fat/fatvol_setnextcluster.c			\
            $(APLFW_DIR)/volume/fat/fatvol_flushfat.c				\
            $(APLFW_DIR)/volume/fat/fatfile_create.c				\
            $(APLFW_DIR)/volume/fat/fatfile_read.c					\



# end of file
