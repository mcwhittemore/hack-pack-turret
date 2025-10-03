#include "./modes/direct-mode.h"
#include "./modes/just-no-mode.h"
#include "./modes/oppisite-mode.h"

void processModeRegistration() {
  registerMode(handleDirectMode); // Mode 1
  registerMode(handleJustNoMode); // Mode 2
  registerMode(handleOppisiteMode); // Mode 3
}
