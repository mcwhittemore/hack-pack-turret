
#define SOUND_PIN 2

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

#define SOUND_TN 62
#define SOUND_SN 125
#define SOUND_EN 250
#define SOUND_QN 500
#define SOUND_HN 1000
#define SOUND_WN 2000

#include "./sounds/start.h"
#include "./sounds/mode_change.h"
#include "./sounds/password.h"

// Software-based tone implementation to avoid conflicts with:
// - IRremote (uses Timer2)
// - Servo library (uses Timer1)
// This is less efficient but avoids timer conflicts

void customTone(uint8_t pin, unsigned int frequency, unsigned long duration) {
  if (frequency == 0)
    return;

  // Calculate half-period in microseconds
  unsigned long halfPeriod = 500000UL / frequency;
  unsigned long cycles = ((unsigned long)frequency * duration) / 1000;

  pinMode(pin, OUTPUT);

  for (unsigned long i = 0; i < cycles; i++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW);
    delayMicroseconds(halfPeriod);
  }
}

void setupSound() {
  pinMode(SOUND_PIN, OUTPUT);
  digitalWrite(SOUND_PIN, LOW);
}

void beep(int frequency, int duration) {
  customTone(SOUND_PIN, frequency, duration);
}

void playSound(int *soundArray, int size) {
  Serial.print("Playing Sound with Length of: ");
  Serial.println(size);
  for (int i = 0; i < size; i += 2) {
    beep(soundArray[i], soundArray[i + 1]);
  }
}

#define PLAY_SOUND(arr) playSound(arr, sizeof(arr) / sizeof(arr[0]))
