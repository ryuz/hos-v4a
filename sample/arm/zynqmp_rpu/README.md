# Xilinx ZynqMP サンプルプログラム

## 概要

Xilinx ZynqMP の RPU(Real-time Processing Unit) の 備える Cortex-R5 で動作するデモです。


## 動作環境

- ボード [Ultra96V2](https://japan.xilinx.com/products/boards-and-kits/1-vad4rl.html) (Xilinx ZynqMP)
- JTAGボード [AES-ACC-U96-JTAG](https://www.avnet.com/shop/japan/products/avnet-engineering-services/aes-acc-u96-jtag-3074457345636446168/) (UARTに必要)
- ビルド環境 [Debianブートイメージ](https://qiita.com/ikwzm/items/92221c5ea6abbd5e991c)


Ultra96V2 の APU(Cortex-A53) 上で動くLinux から、そのままビルドして実行可能です。


## 環境構築

まずサンプルを動かすまでに各種環境構築が必要です。Linux環境のほか、DeviceTree への Cortex-R5 の登録や gcc のインストールなどが必要となります。

下記記事などを参考にしてください。


- [Ultra96V2環境構築メモ](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_05_11_35_24.md)
- [Ultra96V2のDebianイメージで Cortex-R5 を認識させる](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_05_11_35_24.md)
- [HOS-V4a(ITRON仕様 RTOS)をUltra96V2(ZynqMP)のCortex-R5で動かす](https://github.com/ryuz/qrunch_blog/blob/master/entries/public/blog_2020_05_23_10_27_18.md)


## ビルド＆実行

```
$ git clone https://github.com/ryuz/hos-v4a.git
$ cd hos-v4a/sample/arm/zynqmp_rpu/gcc
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
