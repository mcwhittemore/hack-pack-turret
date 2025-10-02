
int handleDirectMode() {
  switch (inputBuffer[0]) {
    case 'L':
      leftMove(1);
      return -1;
    case 'R':
      rightMove(1);
      return -1;
    case 'U':
      upMove(1);
      return -1;
    case 'D':
      downMove(1);
      return -1;
    case 'K':
      fire();
      return -1;
    case '6':
      fireAll();
      return -1;
    case '*':
      return PASSWORD_MODE;
    case '#':
      return JUST_NO_MODE;
    default:
      return -1;
  }
}
