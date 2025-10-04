

unsigned long timmerStart;
int timmerDuration = 0;
bool timmerRunning = false;
int secondsPassed = 0;

bool handleTimmerMode() {
  if (inputBuffer[bufferIndex - 1] == 'K') {
    timmerDuration = atoi(inputBuffer) * 60;
    timmerStart = millis();
    timmerRunning = true;
    secondsPassed = 0;
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
