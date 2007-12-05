#!/usr/bin/sh

# %jp{リリース用パッケージのようなものを生成}


################################
# Japanese                     #
################################

# unix
# rm -fr jp-euc-unix
./dircpy.pl ../.. jp-euc-unix jp-euc-unix

# windows
# rm -fr jp-sjis-dos
./dircpy.pl ../.. jp-sjis-dos jp-sjis-dos

# cygwin
# rm -fr jp-sjis-unix
./dircpy.pl ../.. jp-sjis-unix jp-sjis-unix



################################
# English                      #
################################

# unix/cygwin
# rm -fr en-unix
./dircpy.pl ../.. en-euc-unix en-euc-unix

# windows
# rm -fr en-dos
./dircpy.pl ../.. en-euc-dos en-euc-dos



