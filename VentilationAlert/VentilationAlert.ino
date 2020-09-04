#include <M5StickC.h>
#include <Wire.h>
#include "Adafruit_SGP30.h"
#include "sound.h"

#define SPEAKER_PIN 26
#define GPIO_SPEAKER_PIN 26
#define GPIO_SPEAKER_SD_PIN 0
#define GPIO_SPEAKER_NC_PIN 36

const float play_speed_bias = 1.1f;
const uint32_t SAMPLE_DELAY = (uint32_t)(1000000.f / (16000.f * play_speed_bias));
Adafruit_SGP30 sgp;
int high_threshold = 1000;
int low_threshold = 700;
bool alert_flag = false;
bool alert_flag_tmp = false;
int sound_id = 0;

void setup() {
  M5.begin();  

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setRotation(1);

  pinMode(M5_LED, OUTPUT);
  digitalWrite(M5_LED, LOW);

  pinMode(GPIO_SPEAKER_PIN, OUTPUT);
  dacWrite(GPIO_SPEAKER_PIN, 0);

  pinMode(GPIO_SPEAKER_SD_PIN, OUTPUT);
  digitalWrite(GPIO_SPEAKER_SD_PIN, LOW);

  pinMode(GPIO_SPEAKER_NC_PIN, OUTPUT);
  digitalWrite(GPIO_SPEAKER_NC_PIN, LOW);

  if (!sgp.begin()){
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.println(" Sensor not found.");
    M5.Lcd.print(" Please connect the cable.");
    while (1);
  }


}

void loop() {
  M5.update();

  // checking sensor connection
  if (!sgp.IAQmeasure()) {
    Serial.println("Failed to measure.");
    return;
  }

  // serial print
  Serial.print("eCO2 ");
  Serial.print(sgp.eCO2);
  Serial.println(" ppm");

  // show lcd display
  showDisplay(sgp.eCO2);

  // alert detection
  if (sgp.eCO2 > high_threshold) {
    alert_flag = true;
    digitalWrite(M5_LED, LOW);
  }
  if (sgp.eCO2 < low_threshold) {
    alert_flag = false;
    digitalWrite(M5_LED, HIGH);
  }  
  if (alert_flag && !alert_flag_tmp) {
    for (int i = 0; i < 3; i++) {
      playSound(wav[sound_id], wav_len[sound_id]);
    }
  }

  // changing voice pattern
  if (M5.BtnA.wasPressed()) {
    sound_id++;
    if (sound_id > 2) {
      sound_id = 0;
    }
  }
  
  alert_flag_tmp = alert_flag;
  
  delay(100);
}

void showDisplay(int co2) {
  char str[8];
  itoa(co2, str, 10);
  
  M5.Lcd.setTextSize(1);

  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("CO2 %s ppm ", str);

  M5.Lcd.setCursor(10, 20);
  M5.Lcd.printf("sound : %s    ", sound_title[sound_id]);
}

void playSound(const unsigned char* ptr, uint32_t size) {
  uint64_t count = 0;
  digitalWrite(GPIO_SPEAKER_SD_PIN, HIGH);
  while (count < size) {
     dacWrite(GPIO_SPEAKER_PIN, ptr[count]);
     ets_delay_us(SAMPLE_DELAY);
     ++count;
  }
  digitalWrite(GPIO_SPEAKER_SD_PIN, LOW);
}
