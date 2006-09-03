# Microsoft Developer Studio Project File - Name="hosv4a" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=hosv4a - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "hosv4a.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "hosv4a.mak" CFG="hosv4a - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "hosv4a - Win32 Release" ("Win32 (x86) Static Library" 用)
!MESSAGE "hosv4a - Win32 Debug" ("Win32 (x86) Static Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "hosv4a - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /I "..\..\..\..\include" /I "..\..\..\..\include\arch\proc\win32" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "hosv4a - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\include" /I "..\..\..\..\include\arch\proc\win\win32" /I "..\..\..\..\include\arch\irc\none" /I "../../kernel/include" /D "_LIB" /D "WIN32" /D "_DEBUG" /D "_MBCS" /FD /D /GZ /c
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

# Name "hosv4a - Win32 Release"
# Name "hosv4a - Win32 Debug"
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "object_inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\object\dtqobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\flgobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\inhobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\isrobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\mbxobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\mpfobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\semobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\timobj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\object\tskobj.h
# End Source File
# End Group
# Begin Group "core_inc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\core\basetyp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\cmpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\core.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\dsp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\hep.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\objhdl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\objid.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\opttyp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\que.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\rdq.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\sys.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\tmq.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\core\toq.h
# End Source File
# End Group
# Begin Group "arch_inc"

# PROP Default_Filter ""
# Begin Group "arch_inc_proc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\arch\proc\win\win32\proc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\arch\proc\win\win32\procatr.h
# End Source File
# End Group
# Begin Group "arch_inc_irc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\arch\irc\none\irc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\arch\irc\none\ircatr.h
# End Source File
# End Group
# End Group
# Begin Group "config"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\config\cfgerr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\config\cfghok.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\config\cfgknl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\config\cfgsys.h
# End Source File
# End Group
# Begin Group "parser"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\include\parser\parserr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\parser\parshok.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\parser\parsknl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\parser\parssys.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\..\include\itron.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\include\kernel.h
# End Source File
# End Group
# Begin Group "source"

# PROP Default_Filter ""
# Begin Group "core"

# PROP Default_Filter ""
# Begin Group "dsp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\core\dsp\dsp_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\dsp\ent_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\dsp\idl_lop.c
# End Source File
# End Group
# Begin Group "que"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\core\que\add_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\adf_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\adp_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\nxt_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\rmh_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\rmv_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\rot_que.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\que\trm_que.c
# End Source File
# End Group
# Begin Group "rdq"

# PROP Default_Filter ""
# End Group
# Begin Group "hep"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\core\hep\alc_hep.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\hep\cre_hep.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\hep\fre_hep.c
# End Source File
# End Group
# Begin Group "toq"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\core\toq\add_toq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\toq\rmv_toq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\toq\sig_toq.c
# End Source File
# End Group
# Begin Group "tmq"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\core\tmq\add_tmq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\tmq\rmv_tmq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\core\tmq\sig_tmq.c
# End Source File
# End Group
# End Group
# Begin Group "object"

# PROP Default_Filter ""
# Begin Group "tsk"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\acre_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\act_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\can_wup.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\cre_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\dly_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\ext_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\kcre_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\ref_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\rel_wai.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\slp_tsk.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tsk\wup_tsk.c
# End Source File
# End Group
# Begin Group "sys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\dis_dsp.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\ena_dsp.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\get_tid.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\loc_cpu.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\sns_ctx.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\sns_dsp.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\sns_loc.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\sta_knl.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sys\unl_cpu.c
# End Source File
# End Group
# Begin Group "sem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\acre_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\cre_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\del_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\kcre_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\pol_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\ref_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\sig_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\twai_sem.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\sem\wai_sem.c
# End Source File
# End Group
# Begin Group "isr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\isr\acre_isr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\isr\exe_isr.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\isr\kcre_isr.c
# End Source File
# End Group
# Begin Group "flg"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\acre_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\clr_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\cre_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\del_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\kchk_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\kcre_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\pol_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\ref_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\set_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\twai_flg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\flg\wai_flg.c
# End Source File
# End Group
# Begin Group "inh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\inh\def_inh.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\inh\end_inh.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\inh\exe_inh.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\inh\sta_inh.c
# End Source File
# End Group
# Begin Group "tim"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\tim\get_tim.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tim\isig_tim.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\tim\set_tim.c
# End Source File
# End Group
# Begin Group "mbx"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\acre_mbx.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\kadd_msq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\kadf_msg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\kadp_msg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\kcre_mbx.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\krmf_msg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\krmp_msg.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\krmv_msq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\rcv_mbx.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mbx\snd_mbx.c
# End Source File
# End Group
# Begin Group "mpf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\mpf\acre_mpf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mpf\get_mpf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mpf\kcre_mpf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mpf\pget_mpf.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\mpf\rel_mpf.c
# End Source File
# End Group
# Begin Group "dtq"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\object\dtq\fsnd_dtq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\dtq\kcre_dtq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\dtq\rcv_dtq.c
# End Source File
# Begin Source File

SOURCE=..\..\..\..\source\object\dtq\snd_dtq.c
# End Source File
# End Group
# End Group
# Begin Group "arch"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\..\source\arch\proc\win\win32\ctxctl.c
# End Source File
# End Group
# End Group
# End Target
# End Project
