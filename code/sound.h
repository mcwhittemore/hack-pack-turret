#include "./sounds/hello.h"

#define SOUND_PIN A0

#define SOUND_C 261
#define SOUND_CS 277
#define SOUND_D 294
#define SOUND_DS 311
#define SOUND_E 329
#define SOUND_F 349
#define SOUND_FS 370
#define SOUND_G 392
#define SOUND_GS 415
#define SOUND_A 440
#define SOUND_AS 466
#define SOUND_B 494

#define SOUND_EN 250
#define SOUND_QN 500
#define SOUND_HN 1000
#define SOUND_WN 2000

void setupSound() { pinMode(SOUND_PIN, INPUT); }

void beep(int frequency, int duration) {
  tone(SOUND_PIN, frequency, duration);
  delay(duration);
}

void playSound(int *soundArray, int size) {
  Serial.print("Playing Sound with Length of: ");
  Serial.println(size);
  for (int i = 0; i < size - 2; i += 2) {
    beep(soundArray[i], soundArray[i + 1]);
  }
}

#define PLAY_SOUND(arr) playSound(arr, sizeof(arr) / sizeof(arr[0]))
