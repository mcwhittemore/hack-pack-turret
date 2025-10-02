#define BUFFER_LENGTH 32
char inputBuffer[BUFFER_LENGTH]; // Buffer to store incoming IR command as a string
int bufferIndex = 0; // Current index in the input buffer

bool addToInputBuffer(char c) {
    if (bufferIndex < BUFFER_LENGTH - 1) { // Leave space for null terminator
        inputBuffer[bufferIndex++] = c;
        inputBuffer[bufferIndex] = '\0'; // Null-terminate the string
        Serial.print("Input Buffer: ");
        Serial.println(inputBuffer);
        return true;
    } else {
        Serial.println("Input buffer full, cannot add more characters.");
        return false;
    }
}

char commandToCharacter(int command) {
    switch (command) {
        case up:
          return 'U';
        case down:
          return 'D';
        case left:
          return 'L';
        case right:
          return 'R';
        case ok:
          return 'K';
        case star:
          return '*';
        case cmd1:
          return '1';
        case cmd2:
          return '2';
        case cmd3:
          return '3';
        case cmd4:
          return '4';
        case cmd5:
          return '5';
        case cmd6:
          return '6';
        case cmd7:
          return '7';
        case cmd8:
          return '8';
        case cmd9:
          return '9';
        case cmd0:
          return '0';
        default:
          return '\0'; // Return null character for unrecognized commands
    }
}

bool isCommandADirection(int command) {
  switch (command) {
    case up:
    case down:
    case left:
    case right:
      return true;
    default:
      return false;
  }
}

void handleCommand(int command) {
    // this checks to see if the command is a repeat
    if((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) && !isCommandADirection(command)) { 
      Serial.println("DEBOUNCING REPEATED NUMBER - IGNORING INPUT");
      return; //discarding the repeated numbers prevent you from accidentally inputting a number twice
    }

    char toAdd = commandToCharacter(command);
    bool added = addToInputBuffer(toAdd);
    if (!added) {
        Serial.println("Failed to add command to input buffer.");
        shakeHeadNo();
        bufferIndex = 0; // Reset buffer index
        inputBuffer[0] = '\0'; // Clear the input buffer
        return;
    }

    int modeResult = 0;
    if (mode == PASSWORD_MODE) {
        modeResult = handlePasswordMode();
    } else if (mode == DIRECT_MODE) {
        modeResult = handleDirectMode();
    } else {
        Serial.println("Unknown mode, cannot handle command.");
        shakeHeadNo();
        mode = PASSWORD_MODE; // Reset to a known mode
    }

    if (modeResult == -1) {
        Serial.println("Complete. Resetting buffer.");
        bufferIndex = 0; // Reset buffer index
        inputBuffer[0] = '\0'; // Clear the input buffer
    } else if (modeResult >= 1) {
        Serial.println("Switching to next mode.");
        bufferIndex = 0; // Reset buffer index
        inputBuffer[0] = '\0'; // Clear the input buffer
        mode = modeResult; // Switch to the new mode if applicable
    } else {
        Serial.println("Awaiting more input...");
    }
}

