Language : jp | [en](./README_en.md)
# [Ventilation Alert] M5StickC_SGP30
M5StickCとSGP30を使って作るCO2換気アラートデバイスの作り方を紹介します。
  
<strong>注意) 使用するセンサーSGP30はガスセンサーで、空気の汚れなどを示すVOC値を測定し、そこから等価二酸化炭素濃度（eCO2）を計算して出力するものであるため、正確なCO2濃度を計測できるものではありません。温度や湿度によっても影響される上、アルコールなどにも反応するため、あくまでも目安として使用してください。より正確に測定できるCO2センサーを用いた作り方も今後紹介する予定です。</strong> 


# 作り方（How to make）

## [作り方動画も公開しています](https://panasonic.co.jp/design/flf/assets/img/works/dio/ventilation_alert.mp4)

## 1 準備

### 必要なパーツを用意

<img width="600px" src="../docs/images/all_parts.jpg">

|     | 部品名                | 画像 |  販売リンク（例）                                                   | 備考 |
|:----:|:---------------------|:---:|:----------------------------------------------------------------|:----|
|  1  | M5StickC              | <img width="100px" src="../docs/images/m5stickc.jpg">|[マルツオンライン](https://www.marutsu.co.jp/pc/i/1526331/), [SwitchScience](https://www.switch-science.com/catalog/5517/), [Digi-Key](https://www.digikey.com/product-detail/en/m5stack-technology-co-ltd/K016-C/2221-K016-C-ND/10492141) | |
|  2  | USB Cable Type C | <img width="100px" src="../docs/images/usb_cable.jpg">|| M5StickCに付属 |
|  3  | M5StickC Speaker Hat  | <img width="100px" src="../docs/images/speaker_hat.jpg">|[マルツオンライン](https://www.marutsu.co.jp/pc/i/1556456/), [SwitchScience](https://www.switch-science.com/catalog/5754/), [Digi-Key](https://www.digikey.com/product-detail/en/m5stack-technology-co-ltd/U055/2221-U055-ND/11200926)    ||
|  4  | GROVE - VOC AND ECO2 GAS SENSOR (SGP30) | <img width="100px" src="../docs/images/sgp30.jpg">|[マルツオンライン](https://www.marutsu.co.jp/pc/i/31309791/), [Digi-Key](https://www.digikey.com/products/en?mpart=101020512)||
|  5  | GROVE Cable | <img width="100px" src="../docs/images/grove_cable.jpg">||GROVE - VOC AND ECO2 GAS SENSOR (SGP30)に付属|

#### 必要な道具
- 両面テープ

## 2 電子部品の接続

### 2.1 SGP30 と GROVE Cableを接続する
<img width="300px" src="../docs/images/2.1.jpg">

### 2.2 M5StickC と GROVE Cableを接続する
<img width="300px" src="../docs/images/2.2.jpg">

### 2.3 SGP30 に両面テープを貼り、表面を剥がす
<img width="300px" src="../docs/images/2.3_1.jpg">
<img width="300px" src="../docs/images/2.3_2.jpg">

### 2.4 SGP30 を M5StickC に貼り付ける
<img width="300px" src="../docs/images/2.4.jpg">

### 2.5 M5StickC に M5StickC Speaker Hat を接続する
<img width="300px" src="../docs/images/2.5.jpg">

### 2.6 M5StickC に USB Cableを接続する
<img width="300px" src="../docs/images/2.6.jpg">

### 2.7 完成
<img width="300px" src="../docs/images/2.7.jpg">

## 3 プログラムの書き込み

### 3.1 M5Burnerのインストール、起動
[M5Burner](https://m5stack.com/pages/download)をダウンロードし、続けてインストール、起動してください。  
<https://m5stack.com/pages/download>    

※ Macの場合は必ずアプリケーションフォルダにM5Burnerをインストールしてください。

<img width="800px" src="../docs/images/3.1_1.png">


### 3.2 M5StickCをPCに接続する
※ Windowsの場合、ドライバのインストールが必要な場合があります。  
M5StickCを認識しない場合は下記リンクからドライバをインストールしてください。
<https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/drivers/CP210x_VCP_Windows.zip>  
※ Macはドライバのインストール不要です。  
<img width="500px" src="../docs/images/3.2.png">

### 3.3 プログラムのバイナリファイルをダウンロード
プログラムのバイナリファイル[VentilationAlert.zip](https://github.com/panasonic-corporation/do-it-ourselves/releases/download/v1.0.0/VentilationAlert.zip)をダウンロードし、解凍せずに適当なフォルダに保存してください。  

### 3.4 バイナリファイル読み込み
先ほどダウンロードしたVentilationAlert.zipをM5Burnerで読み込みます。  
右上の＋ボタンを押して、ウィンドウを開きます。  
<img width="800px" src="../docs/images/3.4_1.png">  

出てきたウィンドウからVentilationAlert.zipを選んでM5Burnerに読み込んでください。
<img width="800px" src="../docs/images/3.4_2.png">

### 3.5 書き込み設定
正常に読み込めたら左のリストにVentilationAlertの項目が追加されるので選択します。  
また、上部の"COM"の設定を、Windowsの場合"COM-\*"に、Macの場合は"/dev/usbserial-******"に変更してください。  
<img width="800px" src="../docs/images/3.5.png">

### 3.6 書き込み
右上の"Burn"ボタンをクリックしてプログラムを書き込んでください。  
(書き込み中にスピーカーからノイズ音が発生することがありますが、問題ありません。)  

右下のウィンドウに"Staying in bootloader."もしくは"Hard resetting vir RTS pin..."と表示されたら書き込み完了です。

※ もし間違えて"Erase"を選択してしまった場合は、UIFlowやLovyanLauncherなどをBurnしたあと
再度VentilationAlertをBurnしてください。

<img width="800px" src="../docs/images/3.6.png">

### 3.7 M5StickCの再起動
書き込みが完了したらM5StickCを再起動します。


（書き込み完了後に自動的に再起動されたらこのステップは不要です。）  


M5マーク側面のプッシュスイッチを6秒長押しして電源をOFFにしてください。  
その後数秒待ってから、同じプッシュスイッチを2秒長押しして電源をONにしてください。   
<img width="300px" src="../docs/images/3.7_.jpg">

### 3.8 動作確認
電源を入れるとM5StickCのディスプレイにCO2の計測結果が表示されます。  
センサーに息を吹きかけ、1000ppmを超えると音が鳴り、M5StickC本体のLEDが赤く光ることを確認してください。  
<img width="300px" src="../docs/images/3.8_1.jpg">  
<img width="300px" src="../docs/images/3.8_2.jpg">

## 4. 筐体（ボディー）の製作

筐体は皆さんのアイディアで自由に作ってみましょう！ハッシュタグ #dio_product でTwitterやInstagramなどでどんどんシェアしてください。

<img width="400px" src="../docs/images/body_idea.png">


サンプルとして、トイレットペーパーの芯を使って簡単に作れる4つのテンプレートを用意しています。

| ファイル名 | 画像 | 難易度 |
|-------|-------|-------|
| [bird.pdf](../docs/data/bird.pdf) | <img width="150px" src="../docs/images/bird.jpg"> | Medium |
| [flower.pdf](../docs/data/flower.pdf) | <img width="150px" src="../docs/images/flower.jpg"> | Easy |
| [plant.pdf](../docs/data/plant.pdf) | <img width="150px" src="../docs/images/plant.jpg"> | Easy |
| [spring.pdf](../docs/data/spring.pdf) | <img width="150px" src="../docs/images/spring.jpg"> | Easy |

ここではサンプルとして、birdの作り方を紹介します。

### 4.1
上の表からpdfをダウンロードし、A4の紙に等倍で印刷してください。

<img width="300px" src="../docs/images/4.1.jpg">

### 4.2
外側の実線に沿ってハサミで切り取ります。

<img width="300px" src="../docs/images/4.2.jpg">

### 4.3
点線に沿って折り目をつけます。

<img width="300px" src="../docs/images/4.3.jpg">

### 4.4
裏面をのり付けし、トイレットペーパーの芯を包むようにして貼り付けます。

<img width="300px" src="../docs/images/4.4_1.jpg">
<img width="300px" src="../docs/images/4.4_2.jpg">

### 4.5
Cの部分の表面にのり付けし、反対側の端同士を貼り付けて筒状にします。

<img width="300px" src="../docs/images/4.5.jpg">

### 4.6
上下の飛び出た部分を内側に折り込んで貼り付けます。

<img width="300px" src="../docs/images/4.6.jpg">

### 4.7
D、Eの部分をハサミで切り取り、Dの部分は捨てずに残しておいてください。

<img width="300px" src="../docs/images/4.7.jpg">

### 4.8
カッターでFの線に沿って切込みを入れます。

<img width="300px" src="../docs/images/4.8.jpg">

### 4.9
Dの両端部をFに差し込み、くちばしを作ったら完成です。デバイスを中に入れてみましょう。

<img width="300px" src="../docs/images/4.9_1.jpg"><br>
<img width="300px" src="../docs/images/4.9_2.jpg">


# 使い方(How to use)

1. 電源を入れる

    USB TypeCケーブルをUSBの電源コネクタに接続すればプログラムが自動で起動します。

    <img width="300px" src="../docs/images/howtouse_2.jpg">

2. アラート音を選択する

    M5StickCの「M5」と書かれているプッシュスイッチを押すと、アラート時に再生される音が変わります。

    | 表示名 | 再生される音 |
    |-------|-------|
    |Twitter|鳥のさえずり|
    |Electric|電子音|
    |Charmela|チャルメラ|

3. 設置する

    室内のCO2濃度を正しく計測するため、人の息が直接かからない場所に設置してください。
    M5StickCに小さいバッテリーが内蔵されているので、フル充電状態から電源を繋がなくても数十分は稼働しますが、常に稼働させるために壁コンセントから直接USBに接続して常に電源が供給されている状態にしておきましょう。

    <img width="300px" src="../docs/images/howtouse_3.jpg">

4. 使ってみる

    アラートが出たら窓を開けたり換気扇を回して換気を行いましょう。

    アラートが連続して再生されないよう、CO2濃度が1,000ppmを超えた後、一度700ppmを下回らない限り再びスピーカーから音が再生されることはありません。 (LEDは700ppmを下回るまで光り続けます。)

# 【クリエイター向け】 ソフトウェアの改善、修正
DIOプロジェクトではユーザ自身がレシピを修正したり、アップグレードさせることができます。
あなたのクリエイティブ力でDIO PRODUCTをアップデートさせていきましょう。
コードの修正や改善案など、PullRequestやIssueへの投稿をお待ちしています。

### パッケージ化の方法
M5Burnerから焼き込むためのzipファイルを生成する方法を記載します。

#### 1. バイナリファイル生成
ArduinoIDEからバイナリファイルを出力します。  
<img height="200px" src="../docs/images/5.1.1.png">

#### 2. ファイル配置
生成されたバイナリファイルをbuild/firmware以下に配置し、ファイル名を"firmware_0x10000.bin"に変更してください。

#### 3. ファイル圧縮
build内のfirmwareフォルダとm5burner.jsonをまとめてzipで圧縮し、ファイル名をVentilationAlert.zipとします。
```
# コマンド例
$ zip -r VentilationAlert.zip firmware m5burner.json
```

### 音声データについて
音声データはwavの符号なし8bitデータに変換し、16進数の配列を変数として持たせます。
例としてffmpegを利用した変換コマンドとxxdで16進数の配列を出力するコマンド例を示します。

#### 符号なし8bit変換（ffmpeg）
```
# コマンド例
$ ffmpeg -i input.wav -vn -ac 1 -ar 16000 -acodec pcm_u8 -f wav output.wav
```

#### 16進数配列を出力（xxd）
```
# コマンド例
$ xxd -i output.wav > sample_data
```

# FAQ

## M5Burnerが起動できない

- Macで下のような警告が出てきた場合は[「開発元が未確認のMacアプリケーションを開く」](https://support.apple.com/ja-jp/guide/mac-help/mh40616/mac)をお試しください。  
<img width="500px" src="../docs/images/3.1_2.png">

## VentilationAlert.zipがM5Burnerで読み込めない

- VentilationAlert.zipは解凍せずにそのまま読み込んでください。

- Macでは必ずアプリケーションフォルダにM5Burnerをインストールしてください。

