# HOS-V4 Advance -μITRON4.0仕様 RealTime-OS (作者local版)

## お知らせ

表題の通り、このリポジトリは作者のローカル版です。
が、これをきっかけに TAKEHARU KATO 氏がすごい勢いで RISC-V 移植を進めておられます。

RISC-V 方面の方は TAKEHARU KATO 氏のリポジトリである https://github.com/takeharukato/hos-v4a からの clone をお勧めいたします。

こちらでは、主に Xilinx ZynqMP を追いかけております。

## 概要

### ITRONとは

ITRON とは 1980年代に発足した 国産OSである TRON プロジェクトの一環で組み込み向けRealTime-OS として仕様策定されたオープンなAPI仕様です。

HOS-V4a が実装を目指しているのはこのうち [μITRON4.0仕様](http://www.ertl.jp/ITRON/SPEC/mitron4-j.html) と言われるものであり、下記の仕様書が公開されております。

- [μITRON4.0仕様（Ver. 4.02.00; 日本語版）](http://www.ertl.jp/ITRON/SPEC/FILE/mitron-402j.pdf)
- [μITRON4.0仕様（Ver. 4.00.00; 英語版）](http://www.ertl.jp/ITRON/SPEC/FILE/mitron-400e.pdf)

国産ですので日本語の情報も多く、オープンな仕様という事で公開された実装例も複数あり、組み込みOSの勉強などにも適しています。

その特徴の１つとして、静的API というものがありタスク／セマフォと言ったOSオブジェクトを実行時ではなく起動前にあらかじめ生成しておくという機能があります。この機能により、あらかじめOSオブジェクトが生成済みのイメージをROM化することもでき、オブジェクトの動的生成／削除のような組み込みで避けたい要因を排除した開発が可能になっています。

昨今の組み込み低レイヤー開発においても、動的生成／削除などを排しつつジェネリクスなどのモダンな機能は活用するという開発スタイルができてきておりますので、現在においても使い方次第で活用の幅はまだまだ広く残っているのではないかと思います。



### HOS とは

HOS(Hyper Operating System) は当初 μITRON3.0 仕様OS として、1998年頃から Z80 用や H8用などに開発したものが発端となっております。

当時の開発物は[作者ホームページ](http://ryuz.my.coocan.jp/legacy/hos/index.html) にあります。

その後、本プロジェクトのソースコードは [Sorseforge(現在はOSDN)](https://ja.osdn.net/projects/hos/) に移行して、グループ開発体制に移行しており多くの方の協力を得て開発を進めておりました。

現時点ではいくつかの派生含めた実装トライアルとして

- HOS-80
- HOS-H8
- HOS-V4
- HOS-V4t (Tiny版)
- HOS-V4a (Advance版)

などいくつかが存在していますが、作者の本業の忙しさやFPGAなど多方面への注力、他のITRON実装や、ITRON以外の RealTimeOS の充実化などあって、ほぼ休眠状態になっております(関係者の皆様申し訳ありません)。

作者の興味もCPU単独リソースのスケジューリングによるリアルタイム保証から、FPGAなど用いた並列リソースでのリアルタイム保証に移っていたのですが、昨今、FPGA 内にマイコンが入るようになってきて、再び部分的な利用価値があるのではないかと考えた一部復刻に動いている次第です。

一方で、オープンソースの開発の形態も、当時が cvs ベースの開発環境などをグループ開発用に作るぐらいしかなかったのに対して、現在では github などで各自で fork を作って pull request を活用するような、より誰でも簡単かつオープンな形で開発できるようになってきております。

従いまして、OSDN での開発本家は本家としてそのまま置いておいて、HOS-V4a を作者個人のgithub に fork して、主に Xilinx の Zynq 向けなどに、破壊的な改造含めていろいろやってみようというのが本リポジトリの趣旨になります。

プロセッサやOSの機能が肥大化する中で、低レイヤ―を気軽に楽しむのに、再び何かの役に立てば幸いに思います。
