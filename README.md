# Hack Pack 001: Turret

This repo contains my copy of code from the [Crunchlabs Turret Hack Pack](https://www.crunchlabs.com/products/ir-turret). It assumes you have the Arduino CLI installed and the Arduino Nano board added to your board manager. To upload, make sure you have the right port set in `Makefile` and then run `make`. This will `compile` and `upload` your code.

# Purpose

The goal of this project is to update the original code to be simpler to extend and modify by standardizing input management and "mode" selection and creating a framework for how to add new modes that use this input management system.

# Running

When you turn your turret on, you will need to enter the password. Success will get you a head nod. 

After you unlock it you will be in `Direct Mode`. Later if you change mode and relock it, unlocking will bring you back to your last mode.

To change modes press `#` and then enter the mode number in and follow it with another `#`. So, to switch to mode 2, press `#2#`. To go lock it, press `*`.

# Supported Modes

1. **Direct Mode**: Basic control. Left moves Left. Right, Right. So on. `OK` will Fire. `6` will unload.
2. **Just Say No Mode**: Everything results in a head shake.
3. **Opposite Mode**: Basic mode, but in reverse.
4. **Roulette Mode**: Rotates in a circle and randomly fires.
5. **Program Mode**: Lets you record a sequence of commands and then play them back.
6. **Timer Mode**: Type in a number of minutes and hit `OK`. The turret will wait that many minutes and then fire.

# Adding a mode

## Step 1: Create your new mode in the `code/modes` folder

A mode is just a function that returns a `bool`. The return value impacts if the input buffer is kept or cleared. To make it easier to remember this we’ve provided a `CLEAR_INPUT_BUFFER` and `KEEP_INPUT_BUFFER` constant that you can return instead.

```c
bool handleJustSayNo() {
  shakeHeadNo();
  return CLEAR_INPUT_BUFFER;
}
```

## Step 2: Register your mode with `code/modes.h`

Now that you have your mode created you need to `include` it in the `code/modes.h` file. To do this first you add `#include “./modes/your-mode-name.h"` to the top of the file. And then you add `registerMode(handleYourMode)` to the `processModeRegistration` function. The order of the `registerMode` calls defines the mode number. 

# TODO

- [ ] Add "clock" mode where the turret turns with the time
