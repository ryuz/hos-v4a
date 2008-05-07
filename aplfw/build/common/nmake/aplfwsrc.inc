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
!ifndef LINK_SYSTEM
LINK_SYSTEM           = Yes
!endif
!ifndef LINK_SYSAPI
LINK_SYSAPI           = Yes
!endif
!ifndef LINK_HANDLE
LINK_HANDLE           = Yes
!endif
!ifndef LINK_MEMORY
LINK_MEMORY           = Yes
!endif
!ifndef LINK_TIME
LINK_TIME             = Yes
!endif
!ifndef LINK_PROCESS
LINK_PROCESS          = Yes
!endif
!ifndef LINK_EVENT
LINK_EVENT            = Yes
!endif
!ifndef LINK_FILE
LINK_FILE             = Yes
!endif
!ifndef LINK_COMMAND
LINK_COMMAND          = Yes
!endif

# Librarys
!ifndef LINK_MEMPOL
LINK_MEMPOL           = Yes
!endif
!ifndef LINK_ASSOC
LINK_ASSOC            = Yes
!endif
!ifndef LINK_LIST
LINK_LIST             = Yes
!endif
!ifndef LINK_STREAMBUF
LINK_STREAMBUF        = Yes
!endif
!ifndef LINK_PACKETBUF
LINK_PACKETBUF        = Yes
!endif
!ifndef LINK_IPCHECKSUM
LINK_IPCHECKSUM       = Yes
!endif
!ifndef LINK_CRC16
LINK_CRC16            = Yes
!endif
!ifndef LINK_STRINGFORMAT
LINK_STRINGFORMAT     = Yes
!endif

# Device Drivers
!ifndef LINK_VT100
LINK_VT100            = Yes
!endif
!ifndef LINK_TCPIP
LINK_TCPIP            = Yes
!endif
!ifndef LINK_IPETHER
LINK_IPETHER          = Yes
!endif
!ifndef LINK_NE2000
LINK_NE2000           = No
!endif
!ifndef LINK_LAN9000
LINK_LAN9000          = No
!endif
!ifndef LINK_LAN9118
LINK_LAN9118          = No
!endif
!ifndef LINK_PC16550
LINK_PC16550          = Yes
!endif
!ifndef LINK_AT91USART
LINK_AT91USART        = No
!endif
!ifndef LINK_RENESASSCI
LINK_RENESASSCI       = No
!endif
!ifndef LINK_MX1UART
LINK_MX1UART          = No
!endif
!ifndef LINK_MN103SC
LINK_MN103SC          = No
!endif
!ifndef LINK_WINSOCK
LINK_WINSOCK          = No
!endif
!ifndef LINK_FATVOL
LINK_FATVOL           = Yes
!endif

# Applications
!ifndef LINK_SHELL
LINK_SHELL            = Yes
!endif
!ifndef LINK_PROCESSLIST
LINK_PROCESSLIST      = Yes
!endif
!ifndef LINK_COMMANDLIST
LINK_COMMANDLIST      = Yes
!endif
!ifndef LINK_MEMDUMP
LINK_MEMDUMP          = Yes
!endif
!ifndef LINK_MEMWRITE
LINK_MEMWRITE         = Yes
!endif
!ifndef LINK_MEMTEST
LINK_MEMTEST          = Yes
!endif
!ifndef LINK_KEYTEST
LINK_KEYTEST          = Yes
!endif
!ifndef LINK_TIMECMD
LINK_TIMECMD          = Yes
!endif
!ifndef LINK_FILELIST
LINK_FILELIST         = Yes
!endif
!ifndef LINK_FILECAT
LINK_FILECAT          = Yes
!endif
!ifndef LINK_FILECOPY
LINK_FILECOPY         = Yes
!endif
!ifndef LINK_FILEDUMP
LINK_FILEDUMP         = Yes
!endif
!ifndef LINK_FATMOUNT
LINK_FATMOUNT         = Yes
!endif
!ifndef LINK_FLASHCMD
LINK_FLASHCMD         = Yes
!endif
!ifndef LINK_ETHERSNOOP
LINK_ETHERSNOOP       = Yes
!endif
!ifndef LINK_HELLO
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
!if "$(LINK_SYSTEM)" == "Yes"
SYSTEM_DIR = $(HOSAPLFW_DIR)\system\system
HEADERS = $(HEADERS) $(OBJS_DIR)\system.h
HEADERS = $(HEADERS) $(OBJS_DIR)\system_local.h
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_requestproc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_requestproc.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_process.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_process.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSTEM_DIR)\system_getnextprocess.c
OBJS  = $(OBJS)  $(OBJS_DIR)\system_getnextprocess.$(EXT_OBJ)
!endif


# System API
!if "$(LINK_SYSAPI)" == "Yes"
SYSAPI_DIR = $(HOSAPLFW_DIR)\system\sysapi
HEADERS = $(HEADERS) $(OBJS_DIR)\sysapi.h
HEADERS = $(HEADERS) $(OBJS_DIR)\sysapi_local.h
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysapi_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysapi_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysctx_isisr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysctx_isisr.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_allociomem.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_allociomem.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysmem_freeiomem.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysmem_freeiomem.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_terminate.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_terminate.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_suspend.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_suspend.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_resume.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_resume.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_getparam.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_getparam.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\sysprc_getcurrenthandle.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysprc_getcurrenthandle.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_signal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_signal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_wait.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_getsystemtime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_getsystemtime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_getcputime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_getcputime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_cputimetosecond.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_cputimetosecond.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\systim_cputimetonanosecond.c
OBJS  = $(OBJS)  $(OBJS_DIR)\systim_cputimetonanosecond.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SYSAPI_DIR)\syshos_hook.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syshos_hook.$(EXT_OBJ)
!endif


# Handle Object
!if "$(LINK_HANDLE)" == "Yes"
HANDLE_DIR = $(HOSAPLFW_DIR)\system\handle
HEADERS = $(HEADERS) $(OBJS_DIR)\handle.h
HEADERS = $(HEADERS) $(OBJS_DIR)\handleobj.h
HEADERS = $(HEADERS) $(OBJS_DIR)\handleobj_local.h
CSRCS = $(CSRCS) $(HANDLE_DIR)\handle_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handle_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(HANDLE_DIR)\handleobj_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\handleobj_destructor.$(EXT_OBJ)
!endif


# Memory
!if "$(LINK_MEMORY)" == "Yes"
MEMORY_DIR = $(HOSAPLFW_DIR)\system\memory
HEADERS = $(HEADERS) $(OBJS_DIR)\memory.h
CSRCS = $(CSRCS) $(MEMORY_DIR)\memory.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memory.$(EXT_OBJ)
!endif


# Time
!if "$(LINK_TIME)" == "Yes"
TIME_DIR = $(HOSAPLFW_DIR)\system\time
HEADERS = $(HEADERS) $(OBJS_DIR)\time.h
CSRCS = $(CSRCS) $(TIME_DIR)\time_getsystemtime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\time_getsystemtime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TIME_DIR)\time_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\time_wait.$(EXT_OBJ)
!endif


# Process
!if "$(LINK_PROCESS)" == "Yes"
PROCESS_DIR = $(HOSAPLFW_DIR)\system\process
HEADERS = $(HEADERS) $(OBJS_DIR)\process.h
HEADERS = $(HEADERS) $(OBJS_DIR)\process_local.h
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getcurrenthandle.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getcurrenthandle.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_exit.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_exit.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_waitexit.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_waitexit.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getexitcode.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getexitcode.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getparam.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getparam.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setparam.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setparam.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_entersystemmode.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_entersystemmode.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_leavesystemmode.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_leavesystemmode.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_issystemmode.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_issystemmode.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setcurrentdir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setcurrentdir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getcurrentdir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getcurrentdir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getparentprocess.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getparentprocess.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getexecutiontime.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getexecutiontime.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getcommandline.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getcommandline.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setterminal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setterminal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getterminal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getterminal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setconsole.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setconsole.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getconsole.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getconsole.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setstdin.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setstdin.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getstdin.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getstdin.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setstdout.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setstdout.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getstdout.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getstdout.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_setstderr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_setstderr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PROCESS_DIR)\process_getstderr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\process_getstderr.$(EXT_OBJ)
!endif


# Event
!if "$(LINK_EVENT)" == "Yes"
EVENT_DIR = $(HOSAPLFW_DIR)\system\event
HEADERS = $(HEADERS) $(OBJS_DIR)\event.h
HEADERS = $(HEADERS) $(OBJS_DIR)\event_local.h
CSRCS = $(CSRCS) $(EVENT_DIR)\event_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_set.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_set.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_clear.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_clear.$(EXT_OBJ)
CSRCS = $(CSRCS) $(EVENT_DIR)\event_wait.c
OBJS  = $(OBJS)  $(OBJS_DIR)\event_wait.$(EXT_OBJ)
!endif


# File
!if "$(LINK_FILE)" == "Yes"
FILE_DIR = $(HOSAPLFW_DIR)\system\file
HEADERS = $(HEADERS) $(OBJS_DIR)\console.h
HEADERS = $(HEADERS) $(OBJS_DIR)\drvobj.h
HEADERS = $(HEADERS) $(OBJS_DIR)\drvobj_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\file.h
HEADERS = $(HEADERS) $(OBJS_DIR)\fileobj.h
HEADERS = $(HEADERS) $(OBJS_DIR)\fileobj_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\file_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\stdfile.h
HEADERS = $(HEADERS) $(OBJS_DIR)\syncdrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\syncdrv_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\syncfile.h
HEADERS = $(HEADERS) $(OBJS_DIR)\syncfile_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\sysvol.h
HEADERS = $(HEADERS) $(OBJS_DIR)\sysvolfile.h
HEADERS = $(HEADERS) $(OBJS_DIR)\sysvolfile_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\sysvol_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\volume.h
HEADERS = $(HEADERS) $(OBJS_DIR)\volumeobj.h
HEADERS = $(HEADERS) $(OBJS_DIR)\volumeobj_local.h
CSRCS = $(CSRCS) $(FILE_DIR)\console_getch.c
OBJS  = $(OBJS)  $(OBJS_DIR)\console_getch.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\drvobj_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\drvobj_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\fileobj_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fileobj_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_adddevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_adddevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_addvolume.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_addvolume.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_removevolume.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_removevolume.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_getvolume.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_getvolume.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_getchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_getchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_getstring.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_getstring.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_initialize.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_initialize.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_putchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_putchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_putstring.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_putstring.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_readdir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_readdir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_printformat.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_printformat.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\file_printformatv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\file_printformatv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\stdio_printformat.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stdio_printformat.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_endprocess.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_endprocess.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_sendsignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_sendsignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncdrv_startprocess.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncdrv_startprocess.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncfile_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncfile_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncfile_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncfile_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncfile_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncfile_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncfile_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncfile_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\syncfile_setsignal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\syncfile_setsignal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvolfile_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvolfile_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvolfile_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvolfile_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvolfile_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvolfile_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvolfile_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvolfile_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_adddevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_adddevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_removedevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_removedevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\sysvol_getdevice.c
OBJS  = $(OBJS)  $(OBJS_DIR)\sysvol_getdevice.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volume_shutdown.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volume_shutdown.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_shutdown.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_shutdown.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_makedir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_makedir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FILE_DIR)\volumeobj_remove.c
OBJS  = $(OBJS)  $(OBJS_DIR)\volumeobj_remove.$(EXT_OBJ)
!endif


# Command
!if "$(LINK_COMMAND)" == "Yes"
COMMAND_DIR = $(HOSAPLFW_DIR)\system\command
HEADERS = $(HEADERS) $(OBJS_DIR)\command.h
CSRCS = $(CSRCS) $(COMMAND_DIR)\command.c
OBJS  = $(OBJS)  $(OBJS_DIR)\command.$(EXT_OBJ)
!endif



# --------------------------------------------------
#  Librarys
# --------------------------------------------------

# Memory Pool
!if "$(LINK_MEMPOL)" == "Yes"
MEMPOL_DIR = $(HOSAPLFW_DIR)\library\container\mempol
HEADERS = $(HEADERS) $(OBJS_DIR)\mempol.h
CSRCS = $(CSRCS) $(MEMPOL_DIR)\mempol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mempol.$(EXT_OBJ)
!endif


# Association Array
!if "$(LINK_ASSOC)" == "Yes"
ASSOC_DIR = $(HOSAPLFW_DIR)\library\container\assoc
HEADERS = $(HEADERS) $(OBJS_DIR)\assoc.h
CSRCS = $(CSRCS) $(ASSOC_DIR)\assoc.c
OBJS  = $(OBJS)  $(OBJS_DIR)\assoc.$(EXT_OBJ)
!endif


# List
!if "$(LINK_LIST)" == "Yes"
LIST_DIR = $(HOSAPLFW_DIR)\library\container\list
HEADERS = $(HEADERS) $(OBJS_DIR)\list.h
HEADERS = $(HEADERS) $(OBJS_DIR)\list_local.h
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
!endif


# Stream Buffer
!if "$(LINK_STREAMBUF)" == "Yes"
STREAMBUF_DIR = $(HOSAPLFW_DIR)\library\container\streambuf
HEADERS = $(HEADERS) $(OBJS_DIR)\streambuf.h
HEADERS = $(HEADERS) $(OBJS_DIR)\streambuf_local.h
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
!endif


# Packet Buffer
!if "$(LINK_PACKETBUF)" == "Yes"
PACKETBUF_DIR = $(HOSAPLFW_DIR)\library\container\packetbuf
HEADERS = $(HEADERS) $(OBJS_DIR)\packetbuf.h
HEADERS = $(HEADERS) $(OBJS_DIR)\packetbuf_local.h
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
!endif


# IP check-sum
!if "$(LINK_IPCHECKSUM)" == "Yes"
IPCHECKSUM_DIR = $(HOSAPLFW_DIR)\library\algorithm\ipchecksum
HEADERS = $(HEADERS) $(OBJS_DIR)\ipchecksum.h
HEADERS = $(HEADERS) $(OBJS_DIR)\ipchecksum_local.h
CSRCS = $(CSRCS) $(IPCHECKSUM_DIR)\ipchecksum_getdigest.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipchecksum_getdigest.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPCHECKSUM_DIR)\ipchecksum_update.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipchecksum_update.$(EXT_OBJ)
!endif


# 16bit CRC
!if "$(LINK_CRC16)" == "Yes"
CRC16_DIR = $(HOSAPLFW_DIR)\library\algorithm\crc16
HEADERS = $(HEADERS) $(OBJS_DIR)\crc16.h
HEADERS = $(HEADERS) $(OBJS_DIR)\crc16_local.h
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_getdigest.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_getdigest.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_update.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_update.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_reset.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_reset.$(EXT_OBJ)
CSRCS = $(CSRCS) $(CRC16_DIR)\crc16_table.c
OBJS  = $(OBJS)  $(OBJS_DIR)\crc16_table.$(EXT_OBJ)
!endif


# String Format
!if "$(LINK_STRINGFORMAT)" == "Yes"
STRINGFORMAT_DIR = $(HOSAPLFW_DIR)\library\algorithm\stringformat
HEADERS = $(HEADERS) $(OBJS_DIR)\stringformat.h
HEADERS = $(HEADERS) $(OBJS_DIR)\stringformat_local.h
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_formatstring.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_formatstring.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_formatstringv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_formatstringv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_format.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_format.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_formatv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_formatv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_string.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_string.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_decimal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_decimal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_hexadecimal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_hexadecimal.$(EXT_OBJ)
CSRCS = $(CSRCS) $(STRINGFORMAT_DIR)\stringformat_nibble.c
OBJS  = $(OBJS)  $(OBJS_DIR)\stringformat_nibble.$(EXT_OBJ)
!endif



# --------------------------------------------------
#  Device Drivers
# --------------------------------------------------

# VT100
!if "$(LINK_VT100)" == "Yes"
VT100_DIR = $(HOSAPLFW_DIR)\driver\console\vt100
HEADERS = $(HEADERS) $(OBJS_DIR)\vt100drv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\vt100drv_local.h
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(VT100_DIR)\vt100drv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\vt100drv_destructor.$(EXT_OBJ)
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
!endif


# TCP/IP
!if "$(LINK_TCPIP)" == "Yes"
TCPIP_DIR = $(HOSAPLFW_DIR)\driver\tcpip\tcpip
HEADERS = $(HEADERS) $(OBJS_DIR)\tcpip.h
HEADERS = $(HEADERS) $(OBJS_DIR)\tcpip_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\tcpipfile.h
HEADERS = $(HEADERS) $(OBJS_DIR)\tcpipfile_local.h
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpip_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpip_close.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpipfile_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpipfile_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpipfile_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpipfile_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpipfile_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpipfile_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(TCPIP_DIR)\tcpipfile_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\tcpipfile_destructor.$(EXT_OBJ)
!endif


# IpEther
!if "$(LINK_IPETHER)" == "Yes"
IPETHER_DIR = $(HOSAPLFW_DIR)\driver\tcpip\ipether
HEADERS = $(HEADERS) $(OBJS_DIR)\ipether.h
HEADERS = $(HEADERS) $(OBJS_DIR)\ipether_local.h
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(IPETHER_DIR)\ipether_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ipether_close.$(EXT_OBJ)
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
!endif


# NE2000
!if "$(LINK_NE2000)" == "Yes"
NE2000_DIR = $(HOSAPLFW_DIR)\driver\ether\ne2000
HEADERS = $(HEADERS) $(OBJS_DIR)\ne2000drv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\ne2000hal.h
CSRCS = $(CSRCS) $(NE2000_DIR)\ne2000drv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ne2000drv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(NE2000_DIR)\ne2000hal.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ne2000hal.$(EXT_OBJ)
!endif


# LAN91C111
!if "$(LINK_LAN9000)" == "Yes"
LAN9000_DIR = $(HOSAPLFW_DIR)\driver\ether\lan9000
HEADERS = $(HEADERS) $(OBJS_DIR)\lan9000drv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\lan9000drv_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\lan9000hal.h
HEADERS = $(HEADERS) $(OBJS_DIR)\lan9000hal_local.h
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(LAN9000_DIR)\lan9000drv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\lan9000drv_destructor.$(EXT_OBJ)
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
!endif


# LAN91C111
!if "$(LINK_LAN9118)" == "Yes"
LAN9118_DIR = $(HOSAPLFW_DIR)\driver\ether\lan9118
HEADERS = $(HEADERS) $(OBJS_DIR)\lan9118drv.h
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
!endif


# 16550A
!if "$(LINK_PC16550)" == "Yes"
PC16550_DIR = $(HOSAPLFW_DIR)\driver\serial\pc16550
HEADERS = $(HEADERS) $(OBJS_DIR)\pc16550drv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\pc16550drv_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\pc16550hal.h
HEADERS = $(HEADERS) $(OBJS_DIR)\pc16550hal_local.h
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(PC16550_DIR)\pc16550drv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\pc16550drv_destructor.$(EXT_OBJ)
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
!endif


# Atmel AT91 USART
!if "$(LINK_AT91USART)" == "Yes"
AT91USART_DIR = $(HOSAPLFW_DIR)\driver\serial\at91
HEADERS = $(HEADERS) $(OBJS_DIR)\at91usartdrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\at91usartdrv_local.h
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(AT91USART_DIR)\at91usartdrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\at91usartdrv_destructor.$(EXT_OBJ)
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
!endif


# Renesas SCI
!if "$(LINK_RENESASSCI)" == "Yes"
RENESASSCI_DIR = $(HOSAPLFW_DIR)\driver\serial\renesas
HEADERS = $(HEADERS) $(OBJS_DIR)\scidrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\scidrv_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\scihal.h
HEADERS = $(HEADERS) $(OBJS_DIR)\scihal_local.h
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_destructor.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_isrrxerr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_isrrxerr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_isrrx.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_isrrx.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_isrtx.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_isrtx.$(EXT_OBJ)
CSRCS = $(CSRCS) $(RENESASSCI_DIR)\scidrv_isrtxend.c
OBJS  = $(OBJS)  $(OBJS_DIR)\scidrv_isrtxend.$(EXT_OBJ)
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
!endif


# Freescale MX1 UART
!if "$(LINK_MX1UART)" == "Yes"
MX1UART_DIR = $(HOSAPLFW_DIR)\driver\serial\mx1
HEADERS = $(HEADERS) $(OBJS_DIR)\mx1uartdrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\mx1uartdrv_local.h
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MX1UART_DIR)\mx1uartdrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mx1uartdrv_destructor.$(EXT_OBJ)
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
!endif


# Panasonic MN103 SC
!if "$(LINK_MN103SC)" == "Yes"
MN103SC_DIR = $(HOSAPLFW_DIR)\driver\serial\mn103
HEADERS = $(HEADERS) $(OBJS_DIR)\mn103scdrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\mn103scdrv_local.h
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_write.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_isrtx.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_isrtx.$(EXT_OBJ)
CSRCS = $(CSRCS) $(MN103SC_DIR)\mn103scdrv_isrrx.c
OBJS  = $(OBJS)  $(OBJS_DIR)\mn103scdrv_isrrx.$(EXT_OBJ)
!endif


# WinSock
!if "$(LINK_WINSOCK)" == "Yes"
WINSOCK_DIR = $(HOSAPLFW_DIR)\driver\serial\winsock
HEADERS = $(HEADERS) $(OBJS_DIR)\winsockdrv.h
HEADERS = $(HEADERS) $(OBJS_DIR)\winsockdrv_local.h
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_close.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_close.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_destructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_flush.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_flush.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_iocontrol.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_iocontrol.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_isr.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_isr.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_open.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_open.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_read.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_read.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_recv.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_recv.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_seek.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_seek.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_send.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_send.$(EXT_OBJ)
CSRCS = $(CSRCS) $(WINSOCK_DIR)\winsockdrv_write.c
OBJS  = $(OBJS)  $(OBJS_DIR)\winsockdrv_write.$(EXT_OBJ)
!endif


# FAT volume
!if "$(LINK_FATVOL)" == "Yes"
FATVOL_DIR = $(HOSAPLFW_DIR)\driver\volume\fat
HEADERS = $(HEADERS) $(OBJS_DIR)\fatvol.h
HEADERS = $(HEADERS) $(OBJS_DIR)\fatvol_local.h
HEADERS = $(HEADERS) $(OBJS_DIR)\fatfile.h
HEADERS = $(HEADERS) $(OBJS_DIR)\fatfile_local.h
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_destructor.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_shutdown.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_shutdown.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_makedir.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_makedir.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_remove.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_remove.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_clusterread.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_clusterread.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatvol_clusterwrite.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatvol_clusterwrite.$(EXT_OBJ)
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
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatfile_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatfile_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatfile_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatfile_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatfile_constructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatfile_constructor.$(EXT_OBJ)
CSRCS = $(CSRCS) $(FATVOL_DIR)\fatfile_destructor.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatfile_destructor.$(EXT_OBJ)
!endif



# --------------------------------------------------
#  Applications
# --------------------------------------------------

# Shell
!if "$(LINK_SHELL)" == "Yes"
SHELL_DIR = $(HOSAPLFW_DIR)\application\syscmd\shell
HEADERS = $(HEADERS) $(OBJS_DIR)\shell.h
HEADERS = $(HEADERS) $(OBJS_DIR)\shell_local.h
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_main.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_create.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_create.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_delete.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_delete.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_executecommand.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_executecommand.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_executescript.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_executescript.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_inputline.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_inputline.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_interactive.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_interactive.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_putchar.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_putchar.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_curright.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_curright.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_curleft.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_curleft.$(EXT_OBJ)
CSRCS = $(CSRCS) $(SHELL_DIR)\shell_replaceline.c
OBJS  = $(OBJS)  $(OBJS_DIR)\shell_replaceline.$(EXT_OBJ)
!endif


# Process List
!if "$(LINK_PROCESSLIST)" == "Yes"
PROCESSLIST_DIR = $(HOSAPLFW_DIR)\application\syscmd\processlist
HEADERS = $(HEADERS) $(OBJS_DIR)\processlist.h
CSRCS = $(CSRCS) $(PROCESSLIST_DIR)\processlist_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\processlist_main.$(EXT_OBJ)
!endif


# Command List
!if "$(LINK_COMMANDLIST)" == "Yes"
COMMANDLIST_DIR = $(HOSAPLFW_DIR)\application\syscmd\commandlist
HEADERS = $(HEADERS) $(OBJS_DIR)\commandlist.h
CSRCS = $(CSRCS) $(COMMANDLIST_DIR)\commandlist_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\commandlist_main.$(EXT_OBJ)
!endif


# Memory Dump
!if "$(LINK_MEMDUMP)" == "Yes"
MEMDUMP_DIR = $(HOSAPLFW_DIR)\application\utility\memdump
HEADERS = $(HEADERS) $(OBJS_DIR)\memdump.h
CSRCS = $(CSRCS) $(MEMDUMP_DIR)\memdump_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memdump_main.$(EXT_OBJ)
!endif


# Memory Write
!if "$(LINK_MEMWRITE)" == "Yes"
MEMWRITE_DIR = $(HOSAPLFW_DIR)\application\utility\memwrite
HEADERS = $(HEADERS) $(OBJS_DIR)\memwrite.h
CSRCS = $(CSRCS) $(MEMWRITE_DIR)\memwrite_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memwrite_main.$(EXT_OBJ)
!endif


# Memory Test
!if "$(LINK_MEMTEST)" == "Yes"
MEMTEST_DIR = $(HOSAPLFW_DIR)\application\utility\memtest
HEADERS = $(HEADERS) $(OBJS_DIR)\memtest.h
CSRCS = $(CSRCS) $(MEMTEST_DIR)\memtest_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\memtest_main.$(EXT_OBJ)
!endif


# Key Test
!if "$(LINK_KEYTEST)" == "Yes"
KEYTEST_DIR = $(HOSAPLFW_DIR)\application\utility\keytest
HEADERS = $(HEADERS) $(OBJS_DIR)\keytest.h
CSRCS = $(CSRCS) $(KEYTEST_DIR)\keytest_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\keytest_main.$(EXT_OBJ)
!endif


# Time Command
!if "$(LINK_TIMECMD)" == "Yes"
TIMECMD_DIR = $(HOSAPLFW_DIR)\application\utility\timecmd
HEADERS = $(HEADERS) $(OBJS_DIR)\timecmd.h
CSRCS = $(CSRCS) $(TIMECMD_DIR)\timecmd_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\timecmd_main.$(EXT_OBJ)
!endif


# File List
!if "$(LINK_FILELIST)" == "Yes"
FILELIST_DIR = $(HOSAPLFW_DIR)\application\filecmd\filelist
HEADERS = $(HEADERS) $(OBJS_DIR)\filelist.h
CSRCS = $(CSRCS) $(FILELIST_DIR)\filelist_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filelist_main.$(EXT_OBJ)
!endif


# File Cat
!if "$(LINK_FILECAT)" == "Yes"
FILECAT_DIR = $(HOSAPLFW_DIR)\application\filecmd\filecat
HEADERS = $(HEADERS) $(OBJS_DIR)\filecat.h
CSRCS = $(CSRCS) $(FILECAT_DIR)\filecat_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filecat_main.$(EXT_OBJ)
!endif


# File Copy
!if "$(LINK_FILECOPY)" == "Yes"
FILECOPY_DIR = $(HOSAPLFW_DIR)\application\filecmd\filecopy
HEADERS = $(HEADERS) $(OBJS_DIR)\filecopy.h
CSRCS = $(CSRCS) $(FILECOPY_DIR)\filecopy_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filecopy_main.$(EXT_OBJ)
!endif


# File Dump
!if "$(LINK_FILEDUMP)" == "Yes"
FILEDUMP_DIR = $(HOSAPLFW_DIR)\application\filecmd\filedump
HEADERS = $(HEADERS) $(OBJS_DIR)\filedump.h
CSRCS = $(CSRCS) $(FILEDUMP_DIR)\filedump_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\filedump_main.$(EXT_OBJ)
!endif


# FAT mount
!if "$(LINK_FATMOUNT)" == "Yes"
FATMOUNT_DIR = $(HOSAPLFW_DIR)\application\fatcmd\fatmount
HEADERS = $(HEADERS) $(OBJS_DIR)\fatmount.h
CSRCS = $(CSRCS) $(FATMOUNT_DIR)\fatmount_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\fatmount_main.$(EXT_OBJ)
!endif


# Flash Command
!if "$(LINK_FLASHCMD)" == "Yes"
FLASHCMD_DIR = $(HOSAPLFW_DIR)\application\flashcmd\norflashcmd
HEADERS = $(HEADERS) $(OBJS_DIR)\norflashcmd.h
CSRCS = $(CSRCS) $(FLASHCMD_DIR)\norflashcmd_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\norflashcmd_main.$(EXT_OBJ)
!endif


# Ether Snoopt
!if "$(LINK_ETHERSNOOP)" == "Yes"
ETHERSNOOP_DIR = $(HOSAPLFW_DIR)\application\netcmd\ethersnoop
HEADERS = $(HEADERS) $(OBJS_DIR)\ethersnoop.h
CSRCS = $(CSRCS) $(ETHERSNOOP_DIR)\ethersnoop_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\ethersnoop_main.$(EXT_OBJ)
!endif


# Hello World
!if "$(LINK_HELLO)" == "Yes"
HELLO_DIR = $(HOSAPLFW_DIR)\application\example\hello
HEADERS = $(HEADERS) $(OBJS_DIR)\hello.h
CSRCS = $(CSRCS) $(HELLO_DIR)\hello_main.c
OBJS  = $(OBJS)  $(OBJS_DIR)\hello_main.$(EXT_OBJ)
!endif


# end of file
