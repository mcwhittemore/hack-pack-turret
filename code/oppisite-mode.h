
int handleOppisiteMode() {
  switch (inputBuffer[0]) {
    case 'R':
      leftMove(1);
      return -1;
    case 'L':
      rightMove(1);
      return -1;
    case 'D':
      upMove(1);
      return -1;
    case 'U':
      downMove(1);
      return -1;
    case 'K':
      rightMove(12);
      fire();
      return -1;
    case '1234567890':
      fireAll();
      return -1;
    case '*':
      return PASSWORD_MODE;
    case '#':
      return DIRECT_MODE;
    default:
      return -1;
  }
}
