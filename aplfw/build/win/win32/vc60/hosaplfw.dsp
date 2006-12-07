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
# Begin Group "stmbuf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\library\container\stmbuf\stmbuf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\stmbuf\stmbuf.h
# End Source File
# End Group
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

SOURCE=..\..\..\..\library\container\list\list.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\library\container\list\list.h
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
# End Group
# End Group
# End Group
# Begin Group "driver"

# PROP Default_Filter ""
# Begin Group "serial"

# PROP Default_Filter ""
# Begin Group "renesus"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scidrv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scidrv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scifile.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scifile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scihal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\renesas\scihal.h
# End Source File
# End Group
# Begin Group "winsock"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockdrv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockfile.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\winsock\winsockfile.h
# End Source File
# End Group
# Begin Group "pc16550"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550drv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550file.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550file.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\serial\pc16550\pc16550hal.h
# End Source File
# End Group
# End Group
# Begin Group "ether"

# PROP Default_Filter ""
# Begin Group "ne2000"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\driver\ether\ne2000\ne2000drv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\ether\ne2000\ne2000drv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\ether\ne2000\ne2000hal.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\driver\ether\ne2000\ne2000hal.h
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

SOURCE=..\..\..\..\system\sysapi\sysapi_local.h
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

SOURCE=..\..\..\..\system\sysapi\sysprc_exit.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_getcurrenthandle.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\sysprc_start.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\system_initialize.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\system_lock.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\sysapi\system_unlock.c
# End Source File
# End Group
# Begin Group "file"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\file\confile.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\confile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\file.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\filefmt.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\fileobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\stdfile.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\file\stdfile.h
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

SOURCE=..\..\..\..\system\handle\handle.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\handle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\hdlobj.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\handle\hdlobj.h
# End Source File
# End Group
# Begin Group "shell"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\shell\shell.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\shell\shell.h
# End Source File
# End Group
# Begin Group "process"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\process\process.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\process.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\procobj.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\system\process\procobj.h
# End Source File
# End Group
# Begin Group "type"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\system\type\type.h
# End Source File
# End Group
# End Group
# Begin Group "apl"

# PROP Default_Filter ""
# Begin Group "hello"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\apl\hello\hello.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\apl\hello\hello.h
# End Source File
# End Group
# Begin Group "memdump"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\apl\memdump\memdump.c
# End Source File
# End Group
# End Group
# End Target
# End Project
