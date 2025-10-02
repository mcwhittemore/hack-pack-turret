# Hack Pack 001: Turret

This repo contains my copy of code from the [Crunchlabs Turret Hack Pack](https://www.crunchlabs.com/products/ir-turret). It assumes you have the Arduino CLI installed and the Arduino Nano board added to your board manager. To upload, make sure you have the right port set in `Makefile` and then run `make`. This will `compile` and `upload` your code.

# Purpose

The goal of this project is to update the original code to be simpler to extend and modify by standardizing input management and "mode" selection and creating a framework for how to add new modes that use this input management system.

# Adding a mode

## Step 1: Register new mode with `./code/mode-defs.h`

You need to add both a `#define` for your mode like `#define JUST_SAY_NO_MODE 1`. All the modes must be in order and the first mode must be 1. You also need to define the name of your mode "handler" like `int handleJustSayNo();`.

## Step 2: Implement logic in new `code/*-mode.h` file

Create a new file and fill out your mode "handler" function here. For our "just say no" mode, we create `just-say-no-mode.h` and implement the logic there.

```c
int handleJustSayNo() {
  shakeHeadNo();
  return -1;
}
```

Note: The name of the function here does not matter. It can be whatever you want. It must match across all 3 steps though.

## Step 3: Register your mode in `./code/commands.h`

You need to add both an `#include` for your new mode file and an if block to the mode handler list.

```c
#include "./just-say-no-mode.h"

// ...

if (mode == PASSWORD_MODE) {
    modeResult = handlePasswordMode();
} else if (mode == DIRECT_MODE) {
    modeResult = handleDirectMode();
} else if (mode == JUST_SAY_NO_MODE) {
    modeResult = handleJustSayNo();
}
```

# TODO

- [ ] Add roulette mode from original code
- [ ] Add "program" mode so users can record their own IR sequences and then run them
- [ ] Add "clock" mode where the turret turns with the time
- [ ] Improve mode return values to be more extensible
