bool handleJustNoMode() {
  if (bufferIndex > 0) {
    shakeHeadNo();
  }
  return CLEAR_INPUT_BUFFER;
}
