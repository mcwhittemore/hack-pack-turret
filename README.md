# Hack Pack 001: Turret

This repo contains my copy of code from the [Crunchlabs Turret Hack Pack](https://www.crunchlabs.com/products/ir-turret). It assumes you have the Arduino CLI installed and the Arduino Nano board added to your board manager. To upload, make sure you have the right port set in `Makefile` and then run `make`. This will `compile` and `upload` your code.

## Purpose

The main purpose of this repo is to help me break down the code to make it easier to read and modify. Any updates pushed here are for my own reference and may not be up to date with the offical code. The entry file is `code/code.ino`. The core processing of the commands from the remote are in `code/commands.h`.

## Functionality

1. **Movement Control**: The turret can rotate left and right, and it can also move up and down. It can also spin the barrel, which will make it shoot.
2. **Password Lock**: The turret is locked with a password. You need to enter the correct password to unlock it and use its features.
