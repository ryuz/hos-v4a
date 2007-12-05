#!/usr/bin/perl

# %jp{ファイル種別設定}
@binary_file = ("\\.dsw\$", "\\.dsp\$");
@ignore_file = ("\\.o\$", "\\.obj\$", "\\.ro\$", "\\.lib\$", "\\.l\$", "\\.a\$",
                "\\.exe\$", "\\.abs\$", "\\.elf\$", "\\.x\$", "\\.mot\$", "\\.hex\$", "\\.mcp\$", "\\.tmp\$");
@ignore_dir  = ("^CVS\$", "^tools\$", "^test\$", "^Debug\$", "^Release\$", "^objs", "^tmp_");

# %jp{オプション設定}
$nkf_in     = "nkf -e ";
$nkf_out    = "nkf";
$lng_filter = "cat";
$c_filter   = "./c_filter.pl";

# %jp{オプション解析}
if ( $ARGV[2] =~ /jp/ )
{
	$lng_filter = "./jp_filter.pl";
}
elsif ( $ARGV[2] =~ /en/ )
{
	$lng_filter = "./en_filter.pl";
}

if ( $ARGV[2] =~ /sjis/ )
{
	$nkf_out .= " -s"
}
elsif ( $ARGV[2] =~ /euc/ )
{
	$nkf_out .= " -e"
}

if ( $ARGV[2] =~ /dos/ )
{
	$nkf_out .= " -c"
}
elsif ( $ARGV[2] =~ /unix/ )
{
	$nkf_out .= " -d"
}



# %jp{実行}
&search_dir($ARGV[0], $ARGV[1]);



# %jp{バイナリファイル}
sub copy_bin_file($$)
{
	my($src, $dst) = @_;
	print "[bin] " . $dst . "\n";
	$ret = system("cp $src $dst");
	if ( $ret != 0 )
	{
		print STDERR "Aborted. \n";
		exit($ret);
	}
}

# %jp{テキストファイル}
sub copy_txt_file($$)
{
	my($src, $dst) = @_;
	print "[text] " . $dst . "\n";
	$ret = system("$nkf_in $src | $lng_filter | $nkf_out > $dst");
	if ( $ret != 0 )
	{
		print STDERR "Aborted. \n";
		exit($ret);
	}
}

# %jp{C言語ファイル}
sub copy_c_file($$)
{
	my($src, $dst) = @_;
	print "[c-lng] " . $dst . "\n";
	$ret = system("$nkf_in $src | $lng_filter | $c_filter | $nkf_out > $dst");
	if ( $ret != 0 )
	{
		print STDERR "Aborted. \n";
		exit($ret);
	}
}


# %jp{ディレクトリを再帰処理}
sub search_dir($$)
{
	my($indir, $outdir) = @_;
	
	# %jp{ファイル一覧を得る}
	opendir(INDIR, $indir) || die $!;
	my(@files) = readdir(INDIR);
	closedir(INDIR);
	
	# %jp{出力先が無ければ掘る}
	unless ( -d $outdir )
	{
		print "[mkdir] " . $outdir . "\n";
		mkdir($outdir, 0755) || die $!;
	}
	
	# %jp{ファイルを再帰的に処理}
	file_search : foreach $fname ( @files )
	{
		if( $fname ne '.' && $fname ne '..' )
		{
			$inpath  = $indir  . "/" . $fname;
			$outpath = $outdir . "/" . $fname;
			
			if ( -d $inpath )	# %jp{ディレクトリなら}
			{
				# %jp{無視リストチェック}
				if ( &check_name($fname, @ignore_dir) )
				{
					print "[skip] " . $inpath . "\n";
					next file_search;
				}
				
				# %jp{再帰処理}
				&search_dir($inpath, $outpath);
			}
			else
			{
				# %jp{無視リストチェック}
				if ( &check_name($fname, @ignore_file) )
				{
					print "[skip] : " . $inpath . "\n";
					next file_search;
				}
				
				# %jp{バイナリファイルチェック}
				elsif ( &check_name($fname, @binary_file) )
				{
					&copy_bin_file($inpath, $outpath);
				}
				else
				{
					&copy_txt_file($inpath, $outpath);
				}
			}
		}
	}
}

# %jp{ファイル名チェック}
sub check_name($@)
{
	my($name, @list) = @_;
	foreach $check_name ( @list )
	{
		if ( $name =~ /$check_name/ )
		{
			return(1);
		}
	}
	return(0);
}

