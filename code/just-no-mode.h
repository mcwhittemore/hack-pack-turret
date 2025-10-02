int handleJustNoMode() {

  if (strcmp(inputBuffer, "*") == 0) {
    return PASSWORD_MODE;
  }

  if (strcmp(inputBuffer, "#") == 0) {
    return OPPISITE_MODE;
  }

  shakeHeadNo();
  return -1;
}
