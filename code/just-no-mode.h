int handleJustNoMode() {

  if (strcmp(inputBuffer, "*") == 0) {
    return PASSWORD_MODE;
  }

  if (strcmp(inputBuffer, "#") == 0) {
    return DIRECT_MODE;
  }

  shakeHeadNo();
  return -1;
}
