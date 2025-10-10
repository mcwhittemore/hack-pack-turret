#define BUFFER_LENGTH 32
char inputBuffer[BUFFER_LENGTH];
int bufferIndex = 0;

#define PASSCODE_LENGTH 4
#define CORRECT_PASSCODE "1986"
char passcode[PASSCODE_LENGTH + 1] = "";
bool passcodeEntered = false;

#include "./command-utils.h";
//
bool checkPasscode() {
  if (strlen(inputBuffer) != PASSCODE_LENGTH) {
    return KEEP_INPUT_BUFFER;
  }

  if (strcmp(inputBuffer, CORRECT_PASSCODE) == 0) {
    shakeHeadYes();
    passcodeEntered = true;
    return CLEAR_INPUT_BUFFER;
  } else {
    shakeHeadNo();
    passcodeEntered = false;
    return CLEAR_INPUT_BUFFER;
  }
}

void handleCommand(int command) {
  // this checks to see if the command is a repeat
  if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) &&
      !isCommandADirection(command)) {
    Serial.println("DEBOUNCING REPEATED NUMBER - IGNORING INPUT");
    return; // discarding the repeated numbers prevent you from accidentally
            // inputting a number twice
  }

  char toAdd = commandToCharacter(command);

  if (toAdd == '\0') {
    Serial.println("Unrecognized command, ignoring.");
    return; // Ignore unrecognized commands
  }

  bool added = addToInputBuffer(toAdd);
  if (!added) {
    Serial.println("Failed to add command to input buffer.");
    bufferIndex = 0;       // Reset buffer index
    inputBuffer[0] = '\0'; // Clear the input buffer
  }
}

void loopCommand() {
  bool modeResult = CLEAR_INPUT_BUFFER;
  if (!passcodeEntered) {
    modeResult = checkPasscode();
  } else if (inputBuffer[0] == '#') {
    if (bufferIndex > 1 && inputBuffer[bufferIndex - 1] == '#') {
      modeResult = setMode(inputBuffer);
    } else {
      modeResult = KEEP_INPUT_BUFFER;
    }
  } else if (inputBuffer[bufferIndex - 1] == '*') {
    modeResult = CLEAR_INPUT_BUFFER;
    passcodeEntered = false;
  } else {
    modeResult = runActiveMode();
  }

  if (modeResult == CLEAR_INPUT_BUFFER) {
    bufferIndex = 0;       // Reset buffer index
    inputBuffer[0] = '\0'; // Clear the input buffer
  }
}
