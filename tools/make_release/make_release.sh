#!/bin/sh

REL_DIR=hos-v4a

cd ../..
git checkout-index -a -f --prefix=tools/make_release/${REL_DIR}/
cd tools/make_release

find hos-v4a -name "tmp_*" -type d -exec rm -fr {} \;
rm ${REL_DIR}/.gitignore
rm -fr ${REL_DIR}/test
rm -fr ${REL_DIR}/tools

# for Windows (SJIS)
find hos-v4a -type f -name "*"          | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.dsw"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.dsp"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.sln"      | xargs nkf -w8 -Lw --overwrite
find hos-v4a -type f -name "*.vcxproj*" | xargs nkf -w8 -Lw --overwrite
zip -r hos-v4a-win-sjis.zip ./${REL_DIR}

# for Windows (UTF-8)
find hos-v4a -type f -name "*"          | xargs nkf -w8 -Lw --overwrite
find hos-v4a -type f -name "*.dsw"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.dsp"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.sln"      | xargs nkf -w8 -Lw --overwrite
find hos-v4a -type f -name "*.vcxproj*" | xargs nkf -w8 -Lw --overwrite
zip -r hos-v4a-win-utf8.zip ./${REL_DIR}

# for UNIX (EUC)
find hos-v4a -type f -name "*"          | xargs nkf -e  -Lu --overwrite
find hos-v4a -type f -name "*.dsw"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.dsp"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.sln"      | xargs nkf -w8 -Lw --overwrite
find hos-v4a -type f -name "*.vcxproj*" | xargs nkf -w8 -Lw --overwrite
tar zcvf hos-v4a-unix-euc.tgz ./${REL_DIR}

# for UNIX (UTF-8)
find hos-v4a -type f -name "*"          | xargs nkf -w  -Lu --overwrite
find hos-v4a -type f -name "*.dsw"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.dsp"      | xargs nkf -s  -Lw --overwrite
find hos-v4a -type f -name "*.sln"      | xargs nkf -w8 -Lw --overwrite
find hos-v4a -type f -name "*.vcxproj*" | xargs nkf -w8 -Lw --overwrite
tar zcvf hos-v4a-unix-utf8.tgz ./${REL_DIR}


