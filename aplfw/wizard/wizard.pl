#!/usr/bin/perl
# ----------------------------------------------------------------------------
#  Hyper Operating System  Application Framework
#   Application Wizard
#  
#  Copyright (C) 2006-2008 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------



use File::Basename;

# %jp{デフォルト設定}
$template_dir  = "";
$template_base = dirname($0);
$template_name = "";
$target_dir    = "";
$target_name   = "";
$objname_jp    = "";
$objname_en    = "";
$project_id    = "HOS";
$project_name  = "Hyper Operating System  Application Framework";
$copyright     = "Copyright (C) 2008 by Project HOS\n * http://sourceforge.jp/projects/hos/";

# %jp{置換元タグ}
$template_tag     = "Xxxx";
$project_id_tag   = "ZZZZ";
$project_name_tag = "\\\$PROJECT_NAME\\\$";
$objname_jp_tag   = "\\\$OBJNAME_JP\\\$";
$objname_en_tag   = "\\\$OBJNAME_EN\\\$";
$copyright_tag    = "\\\$COPYRIGHT\\\$";

# %jp{フィルタツール}
$jp_filter  = dirname($0) . "/../../tools/lng_cnv/jp_filter.pl";
$en_filter  = dirname($0) . "/../../tools/lng_cnv/en_filter.pl";
$exe_filter = "> ";


# %jp{コマンドライン解析}
for ( $i = 0; $i <= $#ARGV; $i++ )
{
	# 設定を表示
	if ( $ARGV[$i] eq "-v" )
	{
		$verbose = 1;
	}
	if ( $ARGV[$i] eq "-jp" )
	{
		$exe_filter = "| $jp_filter > ";
	}
	if ( $ARGV[$i] eq "-en" )
	{
		$exe_filter = "| $en_filter > ";
	}
	
	
	# 利用するテンプレートのパス
	elsif ( ($ARGV[$i] eq "-tmp") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$template_dir = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# 利用するテンプレートのベースディレクトリ
	elsif ( ($ARGV[$i] eq "-tmp_dir") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$template_base = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# 利用するテンプレートのディレクトリ
	elsif ( ($ARGV[$i] eq "-tmp_name") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$template_name = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# 出力ディレクトリ
	elsif ( ($ARGV[$i] eq "-dir") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$target_dir = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# ターゲット名
	elsif ( ($ARGV[$i] eq "-target") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$target_name = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# 日本語ブジェクト名
	elsif ( ($ARGV[$i] eq "-obj") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$objname_jp = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# 英語ブジェクト名
	elsif ( ($ARGV[$i] eq "-obj_en") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$objname_en = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# ブジェクトタグ名
	elsif ( ($ARGV[$i] eq "-prjid") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$project_id = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# ブジェクト名
	elsif ( ($ARGV[$i] eq "-prj") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$project_name = $ARGV[$i] if $#ARGV >= 0 ;
	}
	
	# コピーライト
	elsif ( ($ARGV[$i] eq "-copyright") && ($i + 1) <= $#ARGV )
	{
		$i++;
		$copyright = $ARGV[$i] if $#ARGV >= 0 ;
	}
}


# %jp{利用するテンプレート}
if ( $template_dir eq "" )
{
	# 一覧表示
	print "[" . $template_base . "]\n";
	opendir(INDIR, $template_base) or die;
	@files = readdir(INDIR);
	closedir(INDIR);
	foreach $file ( @files )
	{
		if (-d $template_base . "/" . $file )
		{
			if ( $file ne "." && $file ne ".." && $file ne "CVS" )
			{
				print "  " . $file . "\n";
			}
		}
	}
	
	while ( $template_name eq "" )
	{
		print "Template directory? : ";
		$template_name = <STDIN>;
		chomp($template_name);
	}
	$template_dir = $template_base . "/" . $template_name;
}

# 出力ディレクトリ
while ( $target_dir eq "" )
{
	print "Output directory? : ";
	$target_dir = <STDIN>;
	chomp($target_dir);
}

# ターゲット名
while ( $target_name eq "" )
{
	print "Target name?(ex. \"SampleCmd\" : ";
	$target_name = <STDIN>;
	chomp($target_name);
}

# 日本語ブジェクト名
if ( $objname_jp eq "" )
{
	print "Module name (Japanese)? : ";
	$objname_jp = <STDIN>;
	chomp($objname_jp);
}

# 英語ブジェクト名
if ( $objname_en eq "" )
{
	print "Module name (English)? : ";
	$objname_en = <STDIN>;
	chomp($objname_en);
}


# 設定を表示
if ( $verbose )
{
	print "template_dir  : " . $template_dir  . "\n";
	print "template_base : " . $template_base . "\n";
	print "template_name : " . $template_name . "\n";
	print "target_dir    : " . $target_dir    . "\n";
	print "target_name   : " . $target_name   . "\n";
	print "objname_jp    : " . $objname_jp    . "\n";
	print "objname_en    : " . $objname_en    . "\n";
	print "project_id    : " . $project_id    . "\n";
	print "project_name  : " . $project_name  . "\n";
	print "copyright     : " . $copyright     . "\n";
}



# %jp{定数作成}
$target_name_uc  = uc $target_name;
$target_name_lc  = lc $target_name;
$template_tag_uc = uc $template_tag;
$template_tag_lc = lc $template_tag;


# %jP{末尾に'/'を付ける}
if ( $template_dir !~ /\/$/ ) { $template_dir .= "\/"; }
if ( $target_dir   !~ /\/$/ ) { $target_dir   .= "\/"; }


# %jp{テンプレートディレクトリのファイル一覧を得る}
opendir(INDIR, $template_dir) or die;
@files = readdir(INDIR);
closedir(INDIR);


if (!-d $target_dir )
{
	mkdir $target_dir or die;
}


foreach $template_file ( @files )
{
	# ファイル名生成
	$target_file = $template_file;
	$target_file =~ s/$template_tag_lc/$target_name_lc/;
	
	# パス付与
	$template_file = $template_dir . $template_file;
	$target_file   = $target_dir . $target_file;
	
	if (!-d $template_file )
	{
		if ( $verbose )
		{
			print $template_file . " => " . $target_file . "\n";
		}
		
		open(IN, "$template_file") or die;
		open(OUT, $exe_filter . $target_file) or die;
		
		while ( $buf = <IN> )
		{
			# 置換
			$buf =~ s/$template_tag/$target_name/g;
			$buf =~ s/$template_tag_uc/$target_name_uc/g;
			$buf =~ s/$template_tag_lc/$target_name_lc/g;
			
			$buf =~ s/$project_id_tag/$project_id/g;
			$buf =~ s/$project_name_tag/$project_name/g;
			$buf =~ s/$objname_jp_tag/$objname_jp/g;
			$buf =~ s/$objname_en_tag/$objname_en/g;
			$buf =~ s/$copyright_tag/$copyright/g;
			
			print(OUT $buf);
		}
		
		close(IN);
		close(OUT);
	}
}



# end of file
