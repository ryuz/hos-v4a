# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#    common depend file for GNU make
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# Include directories
INC_DIRS += $(APLFW_DIR)



# --------------------------------------------------
#  Systems
# --------------------------------------------------

SYSTEM_DIR     = $(APLFW_DIR)/system/system
SRC_DIRS      += $(SYSTEM_DIR)
CSRCS         += $(SYSTEM_DIR)/system_initialize.c					\
                 $(SYSTEM_DIR)/system_boot.c


# System API
SYSAPI_DIR     = $(APLFW_DIR)/system/sysapi
SRC_DIRS      += $(SYSAPI_DIR)
CSRCS         += $(SYSAPI_DIR)/sysapi_initialize.c					\
                 $(SYSAPI_DIR)/sysloc_lock.c						\
                 $(SYSAPI_DIR)/sysloc_unlock.c						\
                 $(SYSAPI_DIR)/sysevt_clear.c						\
                 $(SYSAPI_DIR)/sysevt_create.c						\
                 $(SYSAPI_DIR)/sysevt_delete.c						\
                 $(SYSAPI_DIR)/sysevt_set.c							\
                 $(SYSAPI_DIR)/sysevt_wait.c						\
                 $(SYSAPI_DIR)/sysint_clear.c						\
                 $(SYSAPI_DIR)/sysint_disable.c						\
                 $(SYSAPI_DIR)/sysint_enable.c						\
                 $(SYSAPI_DIR)/sysisr_create.c						\
                 $(SYSAPI_DIR)/sysisr_delete.c						\
                 $(SYSAPI_DIR)/sysmem_alloc.c						\
                 $(SYSAPI_DIR)/sysmem_free.c						\
                 $(SYSAPI_DIR)/sysmem_getmemif.c					\
                 $(SYSAPI_DIR)/sysmem_getsize.c						\
                 $(SYSAPI_DIR)/sysmem_realloc.c						\
                 $(SYSAPI_DIR)/sysmtx_create.c						\
                 $(SYSAPI_DIR)/sysmtx_delete.c						\
                 $(SYSAPI_DIR)/sysmtx_lock.c						\
                 $(SYSAPI_DIR)/sysmtx_unlock.c						\
                 $(SYSAPI_DIR)/sysprc_create.c						\
                 $(SYSAPI_DIR)/sysprc_delete.c						\
                 $(SYSAPI_DIR)/sysprc_exit.c						\
                 $(SYSAPI_DIR)/sysprc_getcurrenthandle.c			\
                 $(SYSAPI_DIR)/sysprc_start.c						\
                 $(SYSAPI_DIR)/systim_wait.c


# Handle Object
HANDLE_DIR     = $(APLFW_DIR)/system/handle
SRC_DIRS      += $(HANDLE_DIR)
CSRCS         += $(HANDLE_DIR)/handle_close.c						\
                 $(HANDLE_DIR)/handleobj_create.c					\
                 $(HANDLE_DIR)/handleobj_delete.c


# Memory
MEMORY_DIR     = $(APLFW_DIR)/system/memory
SRC_DIRS      += $(MEMORY_DIR)
CSRCS         += $(MEMORY_DIR)/memory.c


# Process
PROCESS_DIR    = $(APLFW_DIR)/system/process
SRC_DIRS      += $(PROCESS_DIR)
CSRCS         += $(PROCESS_DIR)/process.c							\
                 $(PROCESS_DIR)/procobj.c


# File
FILE_DIR       = $(APLFW_DIR)/system/file
SRC_DIRS      += $(FILE_DIR)
CSRCS         += $(FILE_DIR)/file_initialize.c						\
                 $(FILE_DIR)/file_open.c							\
                 $(FILE_DIR)/file_iocontrol.c						\
                 $(FILE_DIR)/file_seek.c							\
                 $(FILE_DIR)/file_read.c							\
                 $(FILE_DIR)/file_write.c							\
                 $(FILE_DIR)/file_getchar.c							\
                 $(FILE_DIR)/file_getstring.c						\
                 $(FILE_DIR)/file_putchar.c							\
                 $(FILE_DIR)/file_putstring.c						\
                 $(FILE_DIR)/file_adddevice.c						\
                 $(FILE_DIR)/file_addvolume.c						\
                 $(FILE_DIR)/filefmt.c								\
                 $(FILE_DIR)/fileobj_create.c						\
                 $(FILE_DIR)/fileobj_delete.c						\
                 $(FILE_DIR)/stdfile.c								\
                 $(FILE_DIR)/console_getch.c						\
                 $(FILE_DIR)/drvobj_create.c						\
                 $(FILE_DIR)/drvobj_delete.c						\
                 $(FILE_DIR)/chrdrv_create.c						\
                 $(FILE_DIR)/chrfile_create.c						\
                 $(FILE_DIR)/volume_openfile.c						\
                 $(FILE_DIR)/volumeobj_create.c


# Command
COMMAND_DIR    = $(APLFW_DIR)/system/command
SRC_DIRS      += $(COMMAND_DIR)
CSRCS         += $(COMMAND_DIR)/command.c


# Shell
SHELL_DIR      = $(APLFW_DIR)/system/shell
SRC_DIRS      += $(SHELL_DIR)
CSRCS         += $(SHELL_DIR)/shell.c




# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
MEMPOL_DIR     = $(APLFW_DIR)/library/container/mempol
SRC_DIRS      += $(MEMPOL_DIR)
CSRCS         += $(MEMPOL_DIR)/mempol.c	


# Stream Buffer
STMBUF_DIR     = $(APLFW_DIR)/library/container/stmbuf
SRC_DIRS      += $(STMBUF_DIR)
CSRCS         += $(STMBUF_DIR)/stmbuf.c


# Association Array
ASSOC_DIR      = $(APLFW_DIR)/library/container/assoc
SRC_DIRS      += $(ASSOC_DIR)
CSRCS         += $(ASSOC_DIR)/assoc.c

# List
LIST_DIR       = $(APLFW_DIR)/library/container/list
SRC_DIRS      += $(LIST_DIR)
CSRCS         += $(LIST_DIR)/list_create.c							\
                 $(LIST_DIR)/list_createex.c						\
                 $(LIST_DIR)/list_addtail.c							\
                 $(LIST_DIR)/list_getat.c							\
                 $(LIST_DIR)/list_getheadpos.c						\
                 $(LIST_DIR)/list_getnextpos.c						\
                 $(LIST_DIR)/list_getprevpos.c						\
                 $(LIST_DIR)/list_gettailpos.c						\
                 $(LIST_DIR)/list_remove.c



# --------------------------------------------------
#  Volumes
# --------------------------------------------------

# Device Volume
DEVVOL_DIR     = $(APLFW_DIR)/volume/dev
SRC_DIRS      += $(DEVVOL_DIR)
CSRCS         += $(DEVVOL_DIR)/devvol_create.c						\
                 $(DEVVOL_DIR)/devvol_delete.c						\
                 $(DEVVOL_DIR)/devvol_adddevice.c					\
                 $(DEVVOL_DIR)/devvol_openfile.c


# FAT Device
#SRC_DIRS += $(APLFW_DIR)/volume/fat
#CSRCS    += $(APLFW_DIR)/volume/fat/fatvol_clusterread.c			\
#            $(APLFW_DIR)/volume/fat/fatvol_clusterwrite.c			\
#            $(APLFW_DIR)/volume/fat/fatvol_create.c				\
#            $(APLFW_DIR)/volume/fat/fatvol_open.c					\
#            $(APLFW_DIR)/volume/fat/fatvol_getclusterbuf.c			\
#            $(APLFW_DIR)/volume/fat/fatvol_getnextcluster.c		\
#            $(APLFW_DIR)/volume/fat/fatvol_relclusterbuf.c			\
#            $(APLFW_DIR)/volume/fat/fatvol_setnextcluster.c		\
#            $(APLFW_DIR)/volume/fat/fatvol_flushfat.c				\
#            $(APLFW_DIR)/volume/fat/fatfile_create.c				\
#            $(APLFW_DIR)/volume/fat/fatfile_read.c					\




# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------


# VT100
VT100_DIR      = $(APLFW_DIR)/driver/console/vt100
SRC_DIRS      += $(VT100_DIR)
CSRCS         += $(VT100_DIR)/vt100drv_create.c						\
                 $(VT100_DIR)/vt100drv_delete.c						\
                 $(VT100_DIR)/vt100drv_open.c						\
                 $(VT100_DIR)/vt100drv_close.c						\
                 $(VT100_DIR)/vt100drv_iocontrol.c					\
                 $(VT100_DIR)/vt100drv_seek.c						\
                 $(VT100_DIR)/vt100drv_read.c						\
                 $(VT100_DIR)/vt100drv_write.c						\
                 $(VT100_DIR)/vt100drv_flush.c						\
                 $(VT100_DIR)/vt100drv_getch.c


# PC16550
PC16550_DIR    = $(APLFW_DIR)/driver/serial/pc16550
SRC_DIRS      += $(PC16550_DIR)
CSRCS         += $(PC16550_DIR)/pc16550drv_create.c					\
                 $(PC16550_DIR)/pc16550drv_delete.c					\
                 $(PC16550_DIR)/pc16550drv_open.c					\
                 $(PC16550_DIR)/pc16550drv_close.c					\
                 $(PC16550_DIR)/pc16550drv_iocontrol.c				\
                 $(PC16550_DIR)/pc16550drv_seek.c					\
                 $(PC16550_DIR)/pc16550drv_read.c					\
                 $(PC16550_DIR)/pc16550drv_write.c					\
                 $(PC16550_DIR)/pc16550drv_flush.c					\
                 $(PC16550_DIR)/pc16550drv_isr.c					\
                 $(PC16550_DIR)/pc16550hal_create.c					\
                 $(PC16550_DIR)/pc16550hal_delete.c					\
                 $(PC16550_DIR)/pc16550hal_setup.c					\
                 $(PC16550_DIR)/pc16550hal_stop.c					\
                 $(PC16550_DIR)/pc16550hal_setspeed.c				\
                 $(PC16550_DIR)/pc16550hal_recvchar.c				\
                 $(PC16550_DIR)/pc16550hal_sendchar.c				\
                 $(PC16550_DIR)/pc16550hal_enableinterrupt.c		\
                 $(PC16550_DIR)/pc16550hal_getinterruptstatus.c		\
                 $(PC16550_DIR)/pc16550hal_getstatus.c




# --------------------------------------------------
#  Applications
# --------------------------------------------------


# Hello World
SRC_DIRS      += $(APLFW_DIR)/apl/hello
CSRCS         += $(APLFW_DIR)/apl/hello/hello.c


# Memory Dump
MEMDUMP_DIR    = $(APLFW_DIR)/apl/util/memdump
SRC_DIRS      += $(MEMDUMP_DIR)
CSRCS         += $(MEMDUMP_DIR)/memdump_main.c

# Memory Write
MEMWRITE_DIR   = $(APLFW_DIR)/apl/util/memwrite
SRC_DIRS      += $(MEMWRITE_DIR)
CSRCS         += $(MEMWRITE_DIR)/memwrite_main.c

# Memory Test
MEMTEST_DIR    = $(APLFW_DIR)/apl/util/memtest
SRC_DIRS      += $(MEMTEST_DIR)
CSRCS         += $(MEMTEST_DIR)/memtest_main.c

# Key Test
KEYTEST_DIR    = $(APLFW_DIR)/apl/util/keytest
SRC_DIRS      += $(KEYTEST_DIR)
CSRCS         += $(KEYTEST_DIR)/keytest_main.c


# end of file
