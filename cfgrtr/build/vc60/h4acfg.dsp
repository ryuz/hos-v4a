# Microsoft Developer Studio Project File - Name="h4acfg" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=h4acfg - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "h4acfg.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "h4acfg.mak" CFG="h4acfg - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "h4acfg - Win32 Release" ("Win32 (x86) Console Application" 用)
!MESSAGE "h4acfg - Win32 Debug" ("Win32 (x86) Console Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "h4acfg - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../../include" /I "../../../kernel/include" /I "../../../kernel/include/arch/proc/win32" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "h4acfg - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../../include" /I "../../../kernel/include" /I "../../../kernel/include/arch/proc/win/win32" /I "../../../kernel/include/arch/irc/simple" /D "_CONSOLE" /D "WIN32" /D "_DEBUG" /D "_MBCS" /FR /YX /FD /D /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "h4acfg - Win32 Release"
# Name "h4acfg - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\source\analyze.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\apidef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\apiinc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\attini.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\attisr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\crealm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\crecyc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\credtq.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\creflg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\crembf.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\crembx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\crempf.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\cremtx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\cresem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\cretsk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\defercd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\defexc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\definh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\deftex.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\dpcque.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\h4acfg.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\idlstk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\intstk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\knlheap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\maxtmout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\maxtpri.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\parpack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\read.cpp
# End Source File
# Begin Source File

SOURCE=..\..\source\timtic.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\include\analyze.h
# End Source File
# Begin Source File

SOURCE=..\..\include\apidef.h
# End Source File
# Begin Source File

SOURCE=..\..\include\apiinc.h
# End Source File
# Begin Source File

SOURCE=..\..\include\attini.h
# End Source File
# Begin Source File

SOURCE=..\..\include\attisr.h
# End Source File
# Begin Source File

SOURCE=..\..\include\crealm.h
# End Source File
# Begin Source File

SOURCE=..\..\include\crecyc.h
# End Source File
# Begin Source File

SOURCE=..\..\include\credtq.h
# End Source File
# Begin Source File

SOURCE=..\..\include\creflg.h
# End Source File
# Begin Source File

SOURCE=..\..\include\crembf.h
# End Source File
# Begin Source File

SOURCE=..\..\include\crembx.h
# End Source File
# Begin Source File

SOURCE=..\..\include\crempf.h
# End Source File
# Begin Source File

SOURCE=..\..\include\cremtx.h
# End Source File
# Begin Source File

SOURCE=..\..\include\cresem.h
# End Source File
# Begin Source File

SOURCE=..\..\include\cretsk.h
# End Source File
# Begin Source File

SOURCE=..\..\include\defercd.h
# End Source File
# Begin Source File

SOURCE=..\..\include\defexc.h
# End Source File
# Begin Source File

SOURCE=..\..\include\definh.h
# End Source File
# Begin Source File

SOURCE=..\..\include\deftex.h
# End Source File
# Begin Source File

SOURCE=..\..\include\idlstk.h
# End Source File
# Begin Source File

SOURCE=..\..\include\intstk.h
# End Source File
# Begin Source File

SOURCE=..\..\include\knlheap.h
# End Source File
# Begin Source File

SOURCE=..\..\include\maxtmout.h
# End Source File
# Begin Source File

SOURCE=..\..\include\maxtpri.h
# End Source File
# Begin Source File

SOURCE=..\..\..\kernel\include\object\mpfobj.h
# End Source File
# Begin Source File

SOURCE=..\..\include\parpack.h
# End Source File
# Begin Source File

SOURCE=..\..\include\read.h
# End Source File
# Begin Source File

SOURCE=..\..\include\readcfg.h
# End Source File
# Begin Source File

SOURCE=..\..\include\timtic.h
# End Source File
# End Group
# End Target
# End Project
