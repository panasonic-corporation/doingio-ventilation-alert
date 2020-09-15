Language : jp | [en](./README_en.md)
# D+IO Project

### [D+IO プロジェクト詳細](https://panasonic.co.jp/design/flf/works/dio/)

<a href="https://panasonic.co.jp/design/flf/works/doing_io/"><img width="500px" src="https://panasonic.co.jp/design/flf/assets/img/works/doing_io/doing_io_icon.jpg"></a>

## Ventilation Alert (CO2換気アラートデバイス)

<img width="500px" src="https://panasonic.co.jp/design/flf/assets/img/works/doing_io/doing_io_ventilation_alert.jpg">

CO2換気アラートデバイスは、室内のCO2濃度を計測し、一定の二酸化炭素濃度を超えると音と光でアラートを出し、換気を促すデバイスです。

新型コロナウイルスの感染拡大が懸念されているなか、​3密（密集、密閉、密接）を避けることが求められています。

​そのため日常生活においては、こまめな換気が奨励されています。 しかし、飲食店や学校、会社のオフィスなど、人が密集する場所ではどんな基準で換気のタイミングが判断されているのか、換気対策として適切な量の換気が行われているか、不安に思われる方もいるかも知れません。

一般的に良好な室内環境として定められているCO2濃度、その値を超えないように、このデバイスで適切な換気のタイミングを逃さないことで少しでもウイルスの感染リスクを軽減できないかと考えました。

## 作り方
使用するMCUとセンサーの組み合わせごとにプロジェクトを分けています。

| Project Name | MCU | Sensor | 補足 |
|--------|--------|--------|--------|
|[CO2換気アラートデバイスの作り方 \[M5StickC_SGP30\]](https://github.com/panasonic-corporation/doingio-ventilation-alert-docs)| M5StickC | SGP30 | 注意) 使用するセンサーSGP30はガスセンサーで、空気の汚れなどを示すVOC値を測定し、そこから等価二酸化炭素濃度（eCO2）を計算して出力するものであるため、正確なCO2濃度を計測できるものではありません。温度や湿度によっても影響される上、アルコールなどにも反応するため、あくまでも目安として使用してください。<br><br> ※ より正確に測定できるCO2センサーを用いた作り方も今後紹介する予定です。|
