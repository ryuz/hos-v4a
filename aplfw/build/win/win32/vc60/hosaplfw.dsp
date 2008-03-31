# Microsoft Developer Studio Project File - Name="hosaplfw" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=hosaplfw - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "hosaplfw.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "hosaplfw.mak" CFG="hosaplfw - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "hosaplfw - Win32 Release" ("Win32 (x86) Static Library" 用)
!MESSAGE "hosaplfw - Win32 Debug" ("Win32 (x86) Static Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "hosaplfw - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../../../.." /I "../../../../../kernel/include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "hosaplfw - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../../../.." /I "../../../../../kernel/include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "hosaplfw - Win32 Release"
# Name "hosaplfw - Win32 Debug"
# Begin Group "library"

# PROP Default_Filter ""
# Begin Group "container"

# PROP Default_Filter ""
# Begin Group "mempol"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\mempol\mempol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\mempol\mempol.h
# End Source File
# End Group
# Begin Group "assoc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\assoc\assoc.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\assoc\assoc.h
# End Source File
# End Group
# Begin Group "list"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_addtail.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_createex.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_getat.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_getheadpos.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_getnextpos.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_getprevpos.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_gettailpos.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list_remove.c
# End Source File
# End Group
# Begin Group "memif"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\memif\memif.h
# End Source File
# End Group
# Begin Group "array"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\array\array.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\array\array_add.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\array\array_setsize.c
# End Source File
# End Group
# Begin Group "streambuf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_clear.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_getbuf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_recvbuf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_recvchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_recvdata.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_refdatasize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_reffreesize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_relbuf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_sendbuf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_sendchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\streambuf\streambuf_senddata.c
# End Source File
# End Group
# End Group
# Begin Group "algorithm"

# PROP Default_Filter ""
# Begin Group "stringformat"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_decimal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_format.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_formatstring.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_formatstringv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_formatv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_hexadecimal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_nibble.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\algorithm\stringformat\stringformat_string.c
# End Source File
# End Group
# End Group
# End Group
# Begin Group "driver"

# PROP Default_Filter ""
# Begin Group "serial"

# PROP Default_Filter ""
# Begin Group "renesus"

# PROP Default_Filter ""
# End Group
# Begin Group "winsock"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_flush.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_isr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_read.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_recv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_seek.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_send.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv_write.c
# End Source File
# End Group
# Begin Group "pc16550"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_flush.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_isr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_read.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_seek.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv_write.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_enableinterrupt.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_getinterruptstatus.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_getstatus.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_recvchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_sendchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_setspeed.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_setup.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal_stop.c
# End Source File
# End Group
# End Group
# Begin Group "ether"

# PROP Default_Filter ""
# Begin Group "ne2000"

# PROP Default_Filter ""
# End Group
# End Group
# Begin Group "console"

# PROP Default_Filter ""
# Begin Group "vt100"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_flush.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_getch.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_read.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_seek.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\console\vt100\vt100drv_write.c
# End Source File
# End Group
# End Group
# End Group
# Begin Group "system"

# PROP Default_Filter ""
# Begin Group "command"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\command\command.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\command\command.h
# End Source File
# End Group
# Begin Group "sysapi"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysapi.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysapi_initialize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysapi_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysctx_isisr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysevt_clear.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysevt_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysevt_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysevt_set.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysevt_wait.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\syshos_hook.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysint_clear.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysint_disable.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysint_enable.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysisr_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysisr_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysloc_lock.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysloc_unlock.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmem_alloc.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmem_free.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmem_getmemif.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmem_getsize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmem_realloc.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmtx_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmtx_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmtx_lock.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysmtx_unlock.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_getcurrenthandle.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_getparam.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_resume.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_suspend.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_terminate.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_cputimetonanosecond.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_cputimetosecond.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_getcputime.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_getsystemtime.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_signal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\systim_wait.c
# End Source File
# End Group
# Begin Group "file"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\file\console.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\console_getch.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_flush.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_read.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_seek.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\drvobj_write.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_adddevice.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_addvolume.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_getchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_getstring.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_getvolume.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_initialize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_printformat.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_printformatv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_putchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_putstring.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_read.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_readdir.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_removevolume.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_seek.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file_write.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\stdfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\stdio_printformat.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_endprocess.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_sendsignal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncdrv_startprocess.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\syncfile_setsignal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_adddevice.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_getdevice.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_iocontrol.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_open.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvol_removedevice.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\sysvolfile_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volume.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volume_shutdown.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_makedir.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_remove.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\volumeobj_shutdown.c
# End Source File
# End Group
# Begin Group "memory"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\memory\memory.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\memory\memory.h
# End Source File
# End Group
# Begin Group "handle"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\handle\handle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handle_close.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handleobj_local.h
# End Source File
# End Group
# Begin Group "process"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\process\process.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_constructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_destructor.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_entersystemmode.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_exit.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getcommandline.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getconsole.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getcurrentdir.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getcurrenthandle.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getexecutiontime.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getexitcode.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getparam.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getparentprocess.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getstderr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getstdin.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getstdout.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_getterminal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_issystemmode.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_leavesystemmode.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setconsole.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setcurrentdir.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setparam.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setstderr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setstdin.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setstdout.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_setterminal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process_waitexit.c
# End Source File
# End Group
# Begin Group "type"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\type\type.h
# End Source File
# End Group
# Begin Group "system_"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\system\system.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\system\system_getnextprocess.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\system\system_initialize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\system\system_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\system\system_process.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\system\system_requestproc.c
# End Source File
# End Group
# Begin Group "event"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\event\event.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\event\event_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\event\event_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\event\event_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\event\event_set.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\event\event_wait.c
# End Source File
# End Group
# End Group
# Begin Group "application"

# PROP Default_Filter ""
# Begin Group "example"

# PROP Default_Filter ""
# Begin Group "hello"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\application\example\hello\hello.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\example\hello\hello_main.c
# End Source File
# End Group
# End Group
# Begin Group "syscmd"

# PROP Default_Filter ""
# Begin Group "shell"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_create.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_curleft.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_curright.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_delete.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_executecommand.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_executescript.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_inputline.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_interactive.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_local.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_main.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_putchar.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\application\syscmd\shell\shell_replaceline.c
# End Source File
# End Group
# End Group
# End Group
# Begin Source File

SOURCE=..\..\..\..\hosaplfw.h
# End Source File
# End Target
# End Project
