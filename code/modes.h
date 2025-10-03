#include "./modes/direct.h"
#include "./modes/just-say-no.h"
#include "./modes/opposite.h"
#include "./modes/roulette.h"
#include "./modes/program.h"

void processModeRegistration() {
  registerMode(handleDirectMode); // Mode 1
  registerMode(handleJustNoMode); // Mode 2
  registerMode(handleOppositeMode); // Mode 3
  registerMode(handleRouletteMode); // Mode 4
  registerMode(handleProgramMode); // Mode 5
}
