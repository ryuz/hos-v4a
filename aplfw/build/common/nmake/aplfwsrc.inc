# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance  Application Framework
#    common include file for nmake
#
#  Copyright (C) 1998-2007 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



# --------------------------------------------------
#  Default setting
# --------------------------------------------------

# System
!ifndef SYSTEM
LINK_SYSTEM           = Yes
!endif
!ifndef SYSAPI
LINK_SYSAPI           = Yes
!endif
!ifndef HANDLE
LINK_HANDLE           = Yes
!endif
!ifndef MEMORY
LINK_MEMORY           = Yes
!endif
!ifndef TIME
LINK_TIME             = Yes
!endif
!ifndef PROCESS
LINK_PROCESS          = Yes
!endif
!ifndef EVENT
LINK_EVENT            = Yes
!endif
!ifndef FILE
LINK_FILE             = Yes
!endif
!ifndef COMMAND
LINK_COMMAND          = Yes
!endif
!ifndef SHELL
LINK_SHELL            = Yes
!endif

# Librarys
!ifndef MEMPOL
LINK_MEMPOL           = Yes
!endif
!ifndef ASSOC
LINK_ASSOC            = Yes
!endif
!ifndef LIST
LINK_LIST             = Yes
!endif
!ifndef STREAMBUF
LINK_STREAMBUF        = Yes
!endif
!ifndef PACKETBUF
LINK_PACKETBUF        = Yes
!endif
!ifndef IPCHECKSUM
LINK_IPCHECKSUM       = Yes
!endif
!ifndef CRC16
LINK_CRC16            = Yes
!endif

# Device Drivers
!ifndef VT100
LINK_VT100            = Yes
!endif
!ifndef TCPIP
LINK_TCPIP            = Yes
!endif
!ifndef IPETHER
LINK_IPETHER          = Yes
!endif
!ifndef NE2000
LINK_NE2000           = Yes
!endif
!ifndef LAN9000
LINK_LAN9000          = Yes
!endif
!ifndef LAN9118
LINK_LAN9118          = Yes
!endif
!ifndef PC16550
LINK_PC16550          = Yes
!endif
!ifndef AT91USART
LINK_AT91USART        = No
!endif
!ifndef RENESASSCI
LINK_RENESASSCI       = No
!endif
!ifndef MX1UART
LINK_MX1UART          = No
!endif
!ifndef WINSOCK
LINK_WINSOCK          = No
!endif
!ifndef FATVOL
LINK_FATVOL           = Yes
!endif

# Applications
!ifndef MEMDUMP
LINK_MEMDUMP          = Yes
!endif
!ifndef MEMWRITE
LINK_MEMWRITE         = Yes
!endif
!ifndef MEMTEST
LINK_MEMTEST          = Yes
!endif
!ifndef KEYTEST
LINK_KEYTEST          = Yes
!endif
!ifndef TIMECMD
LINK_TIMECMD          = Yes
!endif
!ifndef FILELIST
LINK_FILELIST         = Yes
!endif
!ifndef FILECAT
LINK_FILECAT          = Yes
!endif
!ifndef FILECOPY
LINK_FILECOPY         = Yes
!endif
!ifndef FILEDUMP
LINK_FILEDUMP         = Yes
!endif
!ifndef ETHERSNOOP
LINK_ETHERSNOOP       = Yes
!endif
!ifndef HELLO
LINK_HELLO            = Yes
!endif



# --------------------------------------------------
#  Include
# --------------------------------------------------

# Include directories
INC_DIRS = $(INC_DIRS) $(HOSAPLFW_DIR)



# --------------------------------------------------
#  System
# --------------------------------------------------

# System
SYSTEM_DIR = $(HOSAPLFW_DIR)\system\system
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_boot.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_boot.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_requestproc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_requestproc.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_process.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_process.$(EXT_OBJ)


# System API
SYSAPI_DIR = $(HOSAPLFW_DIR)\system\sysapi
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysapi_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysapi_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysloc_lock.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysloc_lock.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysloc_unlock.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysloc_unlock.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysevt_clear.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysevt_clear.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysevt_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysevt_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysevt_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysevt_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysevt_set.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysevt_set.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysevt_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysevt_wait.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysint_clear.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysint_clear.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysint_disable.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysint_disable.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysint_enable.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysint_enable.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysisr_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysisr_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysisr_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysisr_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_alloc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_alloc.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_free.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_free.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_getmemif.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_getmemif.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_getsize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_getsize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_realloc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_realloc.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmtx_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmtx_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmtx_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmtx_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmtx_lock.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmtx_lock.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmtx_unlock.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmtx_unlock.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_exit.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_exit.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_getcurrenthandle.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_getcurrenthandle.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_start.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_start.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_getsystemtime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_getsystemtime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_wait.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysctx_isisr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysctx_isisr.$(EXT_OBJ)


# Handle Object
HANDLE_DIR = $(HOSAPLFW_DIR)\system\handle
CSRCS = $(CSRCS) $(HANDLE_DIR)\handle_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handle_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_delete.$(EXT_OBJ)


# Memory
MEMORY_DIR = $(HOSAPLFW_DIR)\system\memory
CSRCS = $(CSRCS) $(MEMORY_DIR)\memory.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memory.$(EXT_OBJ)


# Time
TIME_DIR = $(HOSAPLFW_DIR)\system\time
CSRCS = $(CSRCS) $(TIME_DIR)\time_getsystemtime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\time_getsystemtime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TIME_DIR)\time_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\time_wait.$(EXT_OBJ)


# Process
PROCESS_DIR = $(HOSAPLFW_DIR)\system\process
CSRCS = $(CSRCS) $(PROCESS_DIR)\process.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\procobj.c
OBJS  = $(OBJS)  $(OBJS_DIR)\procobj.$(EXT_OBJ)


# Event
EVENT_DIR = $(HOSAPLFW_DIR)\system\event
CSRCS = $(CSRCS) $(EVENT_DIR)\event_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_set.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_set.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_wait.$(EXT_OBJ)


# File
FILE_DIR = $(HOSAPLFW_DIR)\system\file
CSRCS = $(CSRCS) $(FILE_DIR)\file_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_readdir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_readdir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_getchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_getchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_getstring.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_getstring.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_putchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_putchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_putstring.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_putstring.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_adddevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_adddevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_addvolume.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_addvolume.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_makedir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_makedir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_remove.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_remove.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_setreadsignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_setreadsignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_setwritesignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_setwritesignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_waitreadsignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_waitreadsignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrdrv_waitwritesignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrdrv_waitwritesignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrfile_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrfile_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\chrfile_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\chrfile_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_adddevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_adddevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\console_getch.c
OBJS  = $(OBJS)  $(OBJS_DIR)\console_getch.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\filefmt.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filefmt.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\stdfile.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stdfile.$(EXT_OBJ)


# Command
COMMAND_DIR = $(HOSAPLFW_DIR)\system\command
CSRCS = $(CSRCS) $(COMMAND_DIR)\command.c
OBJS  = $(OBJS)  $(OBJS_DIR)\command.$(EXT_OBJ)


# Shell
SHELL_DIR = $(HOSAPLFW_DIR)\system\shell
CSRCS = $(CSRCS) $(SHELL_DIR)\shell.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell.$(EXT_OBJ)



# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
MEMPOL_DIR = $(HOSAPLFW_DIR)\library\container\mempol
CSRCS = $(CSRCS) $(MEMPOL_DIR)\mempol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mempol.$(EXT_OBJ)


# Association Array
ASSOC_DIR = $(HOSAPLFW_DIR)\library\container\assoc
CSRCS = $(CSRCS) $(ASSOC_DIR)\assoc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\assoc.$(EXT_OBJ)


# List
LIST_DIR = $(HOSAPLFW_DIR)\library\container\list
CSRCS = $(CSRCS) $(LIST_DIR)\list_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_createex.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_createex.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_addtail.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_addtail.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_getat.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_getat.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_getheadpos.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_getheadpos.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_getnextpos.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_getnextpos.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_getprevpos.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_getprevpos.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_gettailpos.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_gettailpos.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LIST_DIR)\list_remove.c
OBJS  = $(OBJS)  $(OBJS_DIR)\list_remove.$(EXT_OBJ)


# Stream Buffer
STREAMBUF_DIR = $(HOSAPLFW_DIR)\library\container\streambuf
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_getbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_getbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_sendbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_sendbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_senddata.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_senddata.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_sendchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_sendchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_recvbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_recvbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_relbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_relbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_recvdata.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_recvdata.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_recvchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_recvchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_clear.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_clear.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_refdatasize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_refdatasize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STREAMBUF_DIR)\streambuf_reffreesize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\streambuf_reffreesize.$(EXT_OBJ)


# Packet Buffer
PACKETBUF_DIR = $(HOSAPLFW_DIR)\library\container\packetbuf
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_getbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_getbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_sendbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_sendbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_senddata.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_senddata.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_recvbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_recvbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_relbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_relbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_recvdata.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_recvdata.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PACKETBUF_DIR)\packetbuf_clear.c
OBJS  = $(OBJS)  $(OBJS_DIR)\packetbuf_clear.$(EXT_OBJ)


# IP check-sum
IPCHECKSUM_DIR = $(HOSAPLFW_DIR)\library\algorithm\ipchecksum
CSRCS = $(CSRCS) $(IPCHECKSUM_DIR)\ipchecksum_getdigest.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipchecksum_getdigest.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPCHECKSUM_DIR)\ipchecksum_update.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipchecksum_update.$(EXT_OBJ)


# 16bit CRC
CRC16_DIR = $(HOSAPLFW_DIR)\library\algorithm\crc16
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_getdigest.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_getdigest.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_update.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_update.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_reset.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_reset.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_table.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_table.$(EXT_OBJ)



# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------

# VT100
VT100_DIR = $(HOSAPLFW_DIR)\driver\console\vt100
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_getch.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_getch.$(EXT_OBJ)


# TCP/IP
TCPIP_DIR = $(HOSAPLFW_DIR)\driver\tcpip\tcpip
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_clese.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_clese.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_recv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_recv.$(EXT_OBJ)


# IpEther
IPETHER_DIR = $(HOSAPLFW_DIR)\driver\tcpip\ipether
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_clese.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_clese.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_recv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_recv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_getmacaddr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_getmacaddr.$(EXT_OBJ)


# NE2000
NE2000_DIR = $(HOSAPLFW_DIR)\driver\ether\ne2000
CSRCS = $(CSRCS) $(NE2000_DIR)\ne2000drv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ne2000drv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(NE2000_DIR)\ne2000hal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ne2000hal.$(EXT_OBJ)


# LAN91C111
LAN9000_DIR = $(HOSAPLFW_DIR)\driver\ether\lan9000
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_isr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_getinterruptstatus.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_getinterruptstatus.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_getphysicaladdr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_getphysicaladdr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_mii.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_mii.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_phyregread.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_phyregread.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_phyregwrite.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_phyregwrite.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_recv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_recv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_send.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_send.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_setinterruptmask.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_setinterruptmask.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_setup.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_setup.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000hal_stop.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000hal_stop.$(EXT_OBJ)


# LAN91C111
LAN9118_DIR = $(HOSAPLFW_DIR)\driver\ether\lan9118
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9118_DIR)\lan9118drv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9118drv_isr.$(EXT_OBJ)


# 16550A
PC16550_DIR = $(HOSAPLFW_DIR)\driver\serial\pc16550
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_isr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_setup.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_setup.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_stop.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_stop.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_setspeed.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_setspeed.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_recvchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_recvchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_sendchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_sendchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_enableinterrupt.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_enableinterrupt.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_getinterruptstatus.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_getinterruptstatus.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550hal_getstatus.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550hal_getstatus.$(EXT_OBJ)


# Atmel AT91 USART
AT91USART_DIR = $(HOSAPLFW_DIR)\driver\serial\at91
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_isr.$(EXT_OBJ)


# Renesas SCI
RENESASSCI_DIR = $(HOSAPLFW_DIR)\driver\serial\renesas
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_isr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_enableinterrupt.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_enableinterrupt.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_recvchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_recvchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_sendchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_sendchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_setspeed.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_setspeed.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_setup.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_setup.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scihal_stop.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scihal_stop.$(EXT_OBJ)


# Freescale MX1 UART
MX1UART_DIR = $(HOSAPLFW_DIR)\driver\serial\mx1
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_isr.$(EXT_OBJ)


# WinSock
WINSOCK_DIR = $(HOSAPLFW_DIR)\driver\serial\winsock
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv.$(EXT_OBJ)


# FAT volume
FATVOL_DIR = $(HOSAPLFW_DIR)\driver\volume\fat
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_makedir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_makedir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_remove.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_remove.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_clusterread.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_clusterread.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_clusterwrite.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_clusterwrite.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_filecreate.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_filecreate.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_filedelete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_filedelete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_flushclusterbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_flushclusterbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_flushfat.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_flushfat.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_getclusterbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_getclusterbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_relclusterbuf.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_relclusterbuf.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_getnewcluster.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_getnewcluster.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_getnextcluster.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_getnextcluster.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_setnextcluster.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_setnextcluster.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_syncfilesize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_syncfilesize.$(EXT_OBJ)



# --------------------------------------------------
#  Applications
# --------------------------------------------------

# Memory Dump
MEMDUMP_DIR = $(HOSAPLFW_DIR)\application\utility\memdump
CSRCS = $(CSRCS) $(MEMDUMP_DIR)\memdump_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memdump_main.$(EXT_OBJ)


# Memory Write
MEMWRITE_DIR = $(HOSAPLFW_DIR)\application\utility\memwrite
CSRCS = $(CSRCS) $(MEMWRITE_DIR)\memwrite_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memwrite_main.$(EXT_OBJ)


# Memory Test
MEMTEST_DIR = $(HOSAPLFW_DIR)\application\utility\memtest
CSRCS = $(CSRCS) $(MEMTEST_DIR)\memtest_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memtest_main.$(EXT_OBJ)


# Key Test
KEYTEST_DIR = $(HOSAPLFW_DIR)\application\utility\keytest
CSRCS = $(CSRCS) $(KEYTEST_DIR)\keytest_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\keytest_main.$(EXT_OBJ)


# Time Command
TIMECMD_DIR = $(HOSAPLFW_DIR)\application\utility\timecmd
CSRCS = $(CSRCS) $(TIMECMD_DIR)\timecmd_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\timecmd_main.$(EXT_OBJ)


# File List
FILELIST_DIR = $(HOSAPLFW_DIR)\application\filecmd\filelist
CSRCS = $(CSRCS) $(FILELIST_DIR)\filelist_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filelist_main.$(EXT_OBJ)


# File Cat
FILECAT_DIR = $(HOSAPLFW_DIR)\application\filecmd\filecat
CSRCS = $(CSRCS) $(FILECAT_DIR)\filecat_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filecat_main.$(EXT_OBJ)


# File Copy
FILECOPY_DIR = $(HOSAPLFW_DIR)\application\filecmd\filecopy
CSRCS = $(CSRCS) $(FILECOPY_DIR)\filecopy_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filecopy_main.$(EXT_OBJ)


# File Dump
FILEDUMP_DIR = $(HOSAPLFW_DIR)\application\filecmd\filedump
CSRCS = $(CSRCS) $(FILEDUMP_DIR)\filedump_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filedump_main.$(EXT_OBJ)


# Ether Snoopt
ETHERSNOOP_DIR = $(HOSAPLFW_DIR)\application\netcmd\ethersnoop
CSRCS = $(CSRCS) $(ETHERSNOOP_DIR)\ethersnoop_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ethersnoop_main.$(EXT_OBJ)


# Hello World
HELLO_DIR = $(HOSAPLFW_DIR)\application\example\hello
CSRCS = $(CSRCS) $(HELLO_DIR)\hello.c
OBJS  = $(OBJS)  $(OBJS_DIR)\hello.$(EXT_OBJ)


# end of file
