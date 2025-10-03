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
  case hashtag:
    return '#';
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
