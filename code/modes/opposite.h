
int handleOppositeMode() {
  switch (inputBuffer[0]) {
    case 'R':
      leftMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'L':
      rightMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'D':
      upMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'U':
      downMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'K':
      rightMove(12);
      fire();
      return CLEAN_INPUT_BUFFER;
    case '1234567890':
      fireAll();
      return CLEAN_INPUT_BUFFER;
    default:
      return CLEAN_INPUT_BUFFER;
  }
}
