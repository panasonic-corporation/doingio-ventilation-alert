#include <M5Atom.h>
#include <driver/i2s.h>
#include "Adafruit_SGP30.h"
#include "sound.h"

#define CONFIG_I2S_BCK_PIN      19
#define CONFIG_I2S_LRCK_PIN     33
#define CONFIG_I2S_DATA_PIN     22
#define CONFIG_I2S_DATA_IN_PIN  23

#define SPEAKER_I2S_NUMBER      I2S_NUM_0

#define SDA 26
#define SCL 32

Adafruit_SGP30 sgp;
int high_threshold = 1000;
int low_threshold = 800;
bool alert_flag = false;
bool alert_flag_tmp = false;
const unsigned char *wavList[] = {wav1, wav2, wav3};
const size_t wavSize[] = {sizeof(wav1), sizeof(wav2), sizeof(wav3)};
int sound_id = 0;

void initSpeaker() {
  esp_err_t err = ESP_OK;
  i2s_driver_uninstall(SPEAKER_I2S_NUMBER);
  i2s_config_t i2s_config = {
    .mode                 = (i2s_mode_t)(I2S_MODE_MASTER),
    .sample_rate          = 16000 ,
    .bits_per_sample      = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format       = I2S_CHANNEL_FMT_ALL_RIGHT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags     = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count        = 6,
    .dma_buf_len          = 60,
    .use_apll             = false,
    .tx_desc_auto_clear   = true,
    .fixed_mclk           = 0
  };

  i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX);

  err += i2s_driver_install(SPEAKER_I2S_NUMBER, &i2s_config, 0, NULL);

  i2s_pin_config_t tx_pin_config = {
    .bck_io_num           = CONFIG_I2S_BCK_PIN,
    .ws_io_num            = CONFIG_I2S_LRCK_PIN,
    .data_out_num         = CONFIG_I2S_DATA_PIN,
    .data_in_num          = CONFIG_I2S_DATA_IN_PIN,
  };
  err += i2s_set_pin(SPEAKER_I2S_NUMBER, &tx_pin_config);
  err += i2s_set_clk(SPEAKER_I2S_NUMBER, 44100, I2S_BITS_PER_SAMPLE_16BIT, I2S_CHANNEL_MONO);

  i2s_zero_dma_buffer(SPEAKER_I2S_NUMBER);
}

void playWav(int idx) {
  size_t bytes_written;
  i2s_write(SPEAKER_I2S_NUMBER, wavList[idx], wavSize[idx], &bytes_written, portMAX_DELAY);
  i2s_zero_dma_buffer(SPEAKER_I2S_NUMBER);
}

void setup() {
  M5.begin(true, false, true);
  delay(50);

  Wire.begin(SDA, SCL);
  if(!sgp.begin(&Wire)){
    Serial.println("Sensor not found");
    M5.dis.drawpix(0, 0x00ff00);
    while(1);
  }
  M5.dis.drawpix(0, 0xff0000);
  Serial.println();
  //SPIFFS.begin();
 
  Serial.printf("MP3 playback begins...\n");
  initSpeaker();
}
 
void loop()
{
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

  // show indicator
  if (sgp.eCO2 < 600) {
    M5.dis.drawpix(0, 0xff0000);
  } else if (sgp.eCO2 < low_threshold) {
    M5.dis.drawpix(0, 0xffff00);
  } else if (sgp.eCO2 < high_threshold) {
    M5.dis.drawpix(0, 0x00ff00);
  }
  
  // check threshold
  if (sgp.eCO2 > high_threshold) {
    alert_flag = true;
    //M5.dis.drawpix(0, 0x00ff00);
  }
  if (sgp.eCO2 < low_threshold) {
    alert_flag = false;
    //M5.dis.drawpix(0, 0xff0000);
  }

  // play sound
  if (alert_flag && !alert_flag_tmp) {
    for (int i = 0; i < 3; i++) {
      playWav(sound_id);
    }
  }


  // for test
  if (M5.Btn.wasPressed()) {
    sound_id++;
    if (sound_id > 2) {
      sound_id = 0;
    }
    playWav(sound_id);
  }
  
  alert_flag_tmp = alert_flag;
  delay(100);
}
