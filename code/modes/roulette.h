int rouletteModeCheck = 0;
int rouletteDartsFired = 0;
bool rouletteRunning = false;

void runRoulette() {
  Serial.println("ENTERING ROULETTE MODE");
  // unsigned long startTime = millis();
  int dartsFired = 0;
  while (dartsFired <
         6) { // while we still have darts, stay within this while loop
    Serial.println("Darts fired: " + String(dartsFired));
    pitchServoVal = 110;
    pitchServo.write(pitchServoVal); // set PITCH servo to flat angle
    yawServo.write(145);             // set YAW to rotate slowly
    delay(400);                      // rotating for a moment
    yawServo.write(90);              // stop
    delay(400 * random(1, 4));       // wait for a random delay each time

    if (random(3) == 0) { // you have a 1 in six chance of being hit
      delay(700);
      if (random(2) == 0) { // 50% chance to either shake the head yes before
                            // firing or just fire
        shakeHeadYes();
        delay(150);
        fire(); // fire 1 dart
        delay(100);
        dartsFired++;
      } else {
        fire(); // fire 1 dart
        delay(50);
        dartsFired++;
      }
    } else {
      if (random(6) == 5) {
        delay(700);
        shakeHeadNo();
        delay(300);
      } else {
        delay(700);
      }
    }
  }
  yawServo.write(90);
}

bool handleRouletteMode() {
  if (inputBuffer[0] == 'K') {
    runRoulette();
  }
  return CLEAR_INPUT_BUFFER;
}
