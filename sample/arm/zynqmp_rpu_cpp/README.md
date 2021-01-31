# Xilinx ZynqMP サンプルプログラム (C++ 版)

## 概要

ITRON に関しては ANSI C 全盛期に仕様定義された RealTime-OS であり、特に HOS はコンパイラ独自の記述は極力 C言語 ソース内から排除して C89 に準拠したCコンパイラと、それで不足する部分のアセンブラプログラムがあれば利用できるという方針で開発しておりました。

一方で、20年の時を経て、C99 や Embedded-C++ などの試みもなされた中で、現在では C++17 が一般的に利用可能なレベルに達しており、C++言語上でかなりモダンなプログラミングスタイルを取る事が可能になってきました。

依然として小さなメモリの中で、厳しいリアルタイム保証を求めらる組み込み分野においては、メモリの動的確保や言語側のスレッド機能などは利用できない場合が多々あります。

一方で、最新のC++の持つ inline, template, constexpr などを駆使したメタプログラミングなどは、組み込みにおいても性能を損なうことなく、保守性／堅牢性／可読性などを向上させることに大いに役立ってくれます。

本サンプルでは、限定的に記述されたものであれば C++ ソースコードがビルド＆リンク可能背ある事のみ示しております。実際には記述してしまうとリンクが通らなくなる記述も多々ありますが、それでも組み込み用に限定してC++を活用することは可能と考えます。

基本的に extern "C" 宣言だけしてしまえば、*.cpp のファイルは *.c のファイルと相互呼び出しが可能です。



## 動作環境

- ボード [Ultra96V2](https://japan.xilinx.com/products/boards-and-kits/1-vad4rl.html) (Xilinx ZynqMP)
- JTAGボード [AES-ACC-U96-JTAG](https://www.avnet.com/shop/japan/products/avnet-engineering-services/aes-acc-u96-jtag-3074457345636446168/) (UARTに必要)
- ビルド環境 [Debianブートイメージ](https://qiita.com/ikwzm/items/92221c5ea6abbd5e991c)


Ultra96V2 の APU(Cortex-A53) 上で動くLinux から、そのままビルドして実行可能です。


## 環境構築

まずC言語のサンプルが動く環境が必要です。
下記記事などを参考にしてください。

- [Ultra96V2環境構築メモ](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_05_11_35_24.md)
- [Ultra96V2のDebianイメージで Cortex-R5 を認識させる](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_05_11_35_24.md)
- [HOS-V4a(ITRON仕様 RTOS)をUltra96V2(ZynqMP)のCortex-R5で動かす](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_23_10_27_18.md)


## ビルド＆実行

```
$ git clone https://github.com/ryuz/hos-v4a.git
$ cd hos-v4a/sample/arm/zynqmp_rpu_cpp/gcc
$ make
$ make run
```

これで JTAGボードの UART にいろいろと出力されます。
Linux側は UART が使えなくなるのでご注意ください。

## 停止方法


以下のコマンドで停止します。

```
$ make stop
```


## C++化の為にやったこと(参考)

### グローバル初期化対応

C言語の場合もリンクするライブラリ次第で、main 関数が呼ばれる前に初期化などが必要な場合があり、不要な場合もあるのでその辺りはユーザーお任せにしていたのですが、C++ の場合言語上明らかに静的変数のコンストラクタ実行が必要となります。

gcc の場合、.ctors と .dtors の 存在は知っていたのですが、調べると .init_array と .fini_array いうものもあるようです。

そこで リンカスクリプトを下記のようにしたうえで、crt0.S の main 関数呼び出し前後での呼び出しを挿入しています。


```
.tors :
{
    . = ALIGN(4);
    ___ctors = . ;
    *(.init_array);
    *(.ctors)
    ___ctors_end = . ;
    ___dtors = . ;
    *(.fini_array);
    *(.dtors)
    ___dtors_end = . ;
} > ro
```

当然ながらこの位置ですと、OS起動前ですので、コンストラクタでOSの呼び出しはできません。もしそのような事が必要な場合は、vsta_knl 後に呼び出されるように何らかの工夫をする必要があります。

### コンパイルオプション対応

例外処理やRTTI(実行時型情報)は強力な仕組みではあるのですが、動的なメモリ確保が必要なため、組み込みでは共存がなかなか難しいです。

gcc においては -fno-exceptions -fno-non-call-exceptions -fno-rtti などのオプションで利用しないように指示できるようです。

また、組み込みにおいてはそもそも main 関数は終了せずに無限ループに入る場合がほとんどかと思います。
そのような場合では -fno-use-cxa-atexit などが役に立つようです。

また、実際には newlib などの活用時には使えませんが、 -nostdinc -nostdlib などのオプションも組み込みでは有意義なケースもありそうです。

