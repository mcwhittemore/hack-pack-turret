#include "./modes/direct.h"
#include "./modes/just-say-no.h"
#include "./modes/opposite.h"

void processModeRegistration() {
  registerMode(handleDirectMode); // Mode 1
  registerMode(handleJustNoMode); // Mode 2
  registerMode(handleOppositeMode); // Mode 3
}
