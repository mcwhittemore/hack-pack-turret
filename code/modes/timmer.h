

unsigned long timmerStart;
int timmerDuration = 0;
bool timmerRunning = false;
int secondsPassed = 0;
int timmerModeCheck = 0;

bool handleTimmerMode() {

  if (modeCheck != timmerModeCheck) {
    Serial.println("Setting up timmer mode");
    timmerRunning = false;
    timmerModeCheck = modeCheck;
  }

  if (inputBuffer[bufferIndex - 1] == 'K') {
    timmerDuration = atoi(inputBuffer) * 60;
    timmerStart = millis();
    timmerRunning = true;
    secondsPassed = 0;
    Serial.print("Timmer started for ");
    Serial.print(timmerDuration);
    Serial.println(" seconds.");
    return CLEAR_INPUT_BUFFER;
  }

  if (timmerRunning && (millis() - timmerStart >= 1000)) {
    timmerStart += 1000;
    secondsPassed++;
    if (secondsPassed % 10 == 0) {
      shakeHeadYes();
    }
  }

  if (timmerRunning && (secondsPassed >= timmerDuration)) {
    timmerRunning = false;
    fireAll();
  }

  return KEEP_INPUT_BUFFER;
}
