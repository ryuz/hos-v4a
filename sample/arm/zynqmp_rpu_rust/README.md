# サンプルプログラム (Rust 版)

## 概要

組み込みシステムプログラミングができる言語として、最近 Rust が聞かれるようになってきたのでサンプルを作ってみました。
基本的に unsafe を許容すれば C言語と Rust の相互呼び出しは大きな障害はないため、Rust の利用可能性を示す為、Cargo でのビルドと、部分的なRustでの記述を試みています。

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


## Rust の準備

[こちら](https://tomo-wait-for-it-yuki.hatenablog.com/entry/2018/11/17/152359)を参考にさせて頂いて、下記の準備を行っています。

```
$ rustup default beta
$ rustup target add armv7r-none-eabi
$ cargo install cargo-binutils
$ rustup component add llvm-tools-preview
```

## ビルド＆実行

```
$ git clone https://github.com/ryuz/hos-v4a.git
$ cd hos-v4a/sample/arm/zynqmp_rpu_rust
$ cargo build
$ ./run.sh
```

これで JTAGボードの UART にいろいろと出力されます。
Linux側は UART が使えなくなるのでご注意ください。

## 停止方法


以下のコマンドで停止します。

```
$ ./stop.sh
```

