
bool handleDirectMode() {
  switch (inputBuffer[0]) {
    case 'L':
      leftMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'R':
      rightMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'U':
      upMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'D':
      downMove(1);
      return CLEAN_INPUT_BUFFER;
    case 'K':
      fire();
      return CLEAN_INPUT_BUFFER;
    case '6':
      fireAll();
      return CLEAN_INPUT_BUFFER;
    default:
      return CLEAN_INPUT_BUFFER;
  }
}
