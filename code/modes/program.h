
bool runAction(char action, int times) {
  if (times == 0) {
    times = 1; // Default to 1 if no number is provided
  }

  for(int i=0; i<times; i++) {
    switch(action) {
      case 'L':
        leftMove(1);
        break;
      case 'R':
        rightMove(1);
        break;
      case 'U':
        upMove(1);
        break;
      case 'D':
        downMove(1);
        break;
      case 'K':
        fire();
        break;
      default:
        return false;
    }
  }
  return true;
}

void runProgram() {
  char holder[bufferIndex + 1];
  int pos = 0;
  for(int i=0; i<bufferIndex; i++) {
    if (runAction(inputBuffer[i], atoi(holder))) {
        pos = 0;
        holder[0] = '\0';
    } else {
      holder[pos] = inputBuffer[i];
      holder[pos+1] = '\0';
      pos++;
    }
  }
}

bool handleProgramMode() {
  if (inputBuffer[bufferIndex-1] == '#') {
    runProgram();
    return CLEAR_INPUT_BUFFER;
  }
  return KEEP_INPUT_BUFFER;
}


