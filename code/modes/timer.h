

unsigned long timerStart;
int timerDuration = 0;
bool timerRunning = false;
int timerSecondsPassed = 0;
int timerModeCheck = 0;

bool handleTimerMode() {

  if (modeCheck != timerModeCheck) {
    Serial.println("Setting up timer mode");
    timerRunning = false;
    timerModeCheck = modeCheck;
  }

  if (inputBuffer[bufferIndex - 1] == 'K') {
    timerDuration = atoi(inputBuffer) * 60;
    timerStart = millis();
    timerRunning = true;
    timerSecondsPassed = 0;
    Serial.print("Timer started for ");
    Serial.print(timerDuration);
    Serial.println(" seconds.");
    return CLEAR_INPUT_BUFFER;
  }

  if (timerRunning && (millis() - timerStart >= 1000)) {
    beep(SOUND_C, SOUND_EN);
    timerStart += 1000;
    timerSecondsPassed++;
    if (timerSecondsPassed % 10 == 0) {
      shakeHeadYes();
    }
  }

  if (timerRunning && (timerSecondsPassed >= timerDuration)) {
    timerRunning = false;
    fireAll();
  }

  return KEEP_INPUT_BUFFER;
}
