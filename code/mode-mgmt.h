typedef bool (*FunctionPtr)();

#define CLEAR_INPUT_BUFFER true
#define KEEP_INPUT_BUFFER false

#define MAX_MODES 20
int modeCount = 0;
int activeMode = 0;
FunctionPtr modeHandlers[MAX_MODES];

void registerMode(FunctionPtr func) {
  if (modeCount < MAX_MODES) {
    modeHandlers[modeCount] = func;
    modeCount++;
  } else {
    Serial.println("Function array is full!");
  }
}

bool runActiveMode() {
  if (modeCount == 0) {
    Serial.println("No functions registered!");
    return false;
  }
  if (activeMode >= modeCount) {
    activeMode = 0; // Reset to first mode if out of bounds
  }
  return modeHandlers[activeMode]();
}

bool setMode(char* inputBuffer) {
  int inputLen = strlen(inputBuffer);
  char hold[inputLen + 1];
  for(int i = 1; i < inputLen-1; i++) {
    hold[i - 1] = inputBuffer[i];
  }
  int mode = atoi(hold) - 1;
  if (mode >= 0 && mode < modeCount) {
    activeMode = mode;
    Serial.print("Mode set to ");
    Serial.println(activeMode + 1);
    return true;
  } else {
    Serial.println("Invalid mode number!");
    return false;
  }
}
