int rouletteModeCheck = 0;
int rouletteDartsFired = 0;
bool rouletteRunning = false;

void runRoulette() {

  Serial.println("Darts fired: " + String(rouletteDartsFired));
  pitchServo.write(110);     // set PITCH servo to flat angle
  yawServo.write(145);       // set YAW to rotate slowly
  delay(400);                // rotating for a moment
  yawServo.write(90);        // stop
  delay(400 * random(1, 4)); // wait for a random delay each time

  if (random(3) == 0) { // you have a 1 in six chance of being hit
    delay(700);
    if (random(2) == 0) { // 50% chance to either shake the head yes before
                          // firing or just fire
      shakeHeadYes();
      delay(150);
      fire(); // fire 1 dart
      delay(100);
      rouletteDartsFired++;
    } else {
      fire(); // fire 1 dart
      delay(50);
      rouletteDartsFired++;
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

  if (rouletteDartsFired >= 6) {
    yawServo.write(90);
    rouletteRunning = false;
  }
}

bool handleRouletteMode() {
  if (modeCheck != rouletteModeCheck) {
    Serial.println("Setting up roulette mode");
    rouletteDartsFired = 0;
    rouletteRunning = false;
    rouletteModeCheck = modeCheck;
  }

  if (inputBuffer[0] == 'K') {
    rouletteDartsFired = 0;
    rouletteRunning = true;
  }

  if (rouletteRunning) {
    runRoulette();
  }

  return CLEAR_INPUT_BUFFER;
}
