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

