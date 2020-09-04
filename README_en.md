Language : [jp](./README.md) | en
# D+IO Project

### [Find out more about the D+IO Project here](https://panasonic.net/design/flf/works/dio/)

<a href="https://panasonic.net/design/flf/works/dio/"><img width="500px" src="https://panasonic.co.jp/design/flf/assets/img/works/dio/dio_icon.jpg"></a>

## Ventilation Alert Device

<img width="500px" src="https://panasonic.co.jp/design/flf/assets/img/works/dio/dio_ventilation_alert.jpg">

The CO2 ventilation alert device monitors the indoor CO2 concentration, and a sound and light alert is activated when the CO2 concentration exceeds a certain level to encourage ventilation.

With the growing concern for the spread of the new coronavirus, avoiding the Three Cs (closed spaces with poor ventilation, crowded places with many people nearby, and close-contact settings) is recommended.

​For this reason, persistent ventilation in everyday life is encouraged. However, some might feel unsure about the criteria for ventilation frequency or the adequacy of the amount of ventilation in crowded places such as restaurants, schools, and offices.

With this device, it might be possible to reduce the risk of virus infection a little bit by monitoring the indoor CO2 concentration to prevent it from exceeding the generally defined concentration for a good indoor environment, and ensuring optimum timing for ventilation.

## How to make it

| Project Name | MCU | Sensor | Note |
|--------|--------|--------|--------|
|[M5StickC_SGP30](./M5StickC_SGP30)| M5StickC | SGP30 | Caution: The device does not measure accurate CO2 concentration since the SGP30 sensor used for the device is a gas sensor for measuring the VOC value that indicates air quality, and the equivalent carbon dioxide concentration (eCO2) is calculated based on this value. The value may be affected by temperature and humidity, and senses also alcohol and other factors, and the device is for reference purposes only. <br><br>※ A recipe for a device with a more accurate CO2 sensor will be coming in the future.|
