#!/usr/bin/perl

# %jp{ファイル種別設定}
@c_file      = ("\.c\$", "\.cpp\$", "\.h\$");
@binary_file = ("\.dsw\$", "\.dsp\$");
@ignore_file = ("\.o\$", "\.obj\$", "\.lib\$", "\.l\$", "\.exe\$", "\.elf\$");
@ignore_dir  = ("^CVS\$", "^Debug\$", "^Release\$", "^objs", "test");

# %jp{オプション設定}
$nkf_in     = "nkf -e ";
$nkf_out    = "nkf";
$lng_filter = "cat";
$c_filter   = "./c_filter.pl";

# %jp{オプション解析}
if ( $ARGV[2] =~ /jp-/ )
{
	$lng_filter = "./jp_filter.pl";
}
elsif ( $ARGV[2] =~ /en-/ )
{
	$lng_filter = "./en_filter.pl";
}

if ( $ARGV[2] =~ /-sjis-/ )
{
	$nkf_out .= " -j"
}
elsif ( $ARGV[2] =~ /-euc-/ )
{
	$nkf_out .= " -e"
}

if ( $ARGV[2] =~ /-dos/ )
{
	$nkf_out .= " -c"
}
elsif ( $ARGV[2] =~ /-unix/ )
{
	$nkf_out .= " -d"
}



# %jp{実行}
&search_dir($ARGV[0], $ARGV[1]);



# %jp{バイナリファイル}
sub copy_bin_file($$)
{
	my($src, $dst) = @_;
	print "copy binary file : " . $src . " -> " . $dst . "\n";
	system("cp $src $dst") || die $!;
}

# %jp{テキストファイル}
sub copy_txt_file($$)
{
	my($src, $dst) = @_;
	print "copy text file : " . $src . " -> " . $dst . "\n";
	print "$nkf_in $src | $lng_filter | $nkf_out > $dst \n";
	system("$nkf_in $src | $lng_filter | $nkf_out > $dst");
}

# %jp{C言語ファイル}
sub copy_c_file($$)
{
	my($src, $dst) = @_;
	print "copy C file : " . $src . " -> " . $dst . "\n";
	print "$nkf_in $src | $lng_filter | $c_filter | $nkf_out > $dst \n";
	system("$nkf_in $src | $lng_filter | $c_filter | $nkf_out > $dst");
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
		print "mkdir " . $outdir . "\n";
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
					print "ignore : " . $inpath . "\n";
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
					print "ignore : " . $inpath . "\n";
					next file_search;
				}
				
				# %jp{C言語ファイルチェック}
				elsif ( &check_name($fname, @b_file) )
				{
					&copy_c_file($inpath, $outpath);
				}
				
				# %jp{バイナリファイルチェック}
				elsif ( &check_name($fname, @bin_file) )
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

