FQBN=arduino:avr:nano
PORT=/dev/cu.usbserial-110

all: compile upload

compile:
	arduino-cli compile --fqbn $(FQBN) code

upload:
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) code

log:
	arduino-cli monitor -p $(PORT) --fqbn $(FQBN)

format:
	find . -type f \( -name "*.ino" -o -name "*.h" \) -exec clang-format -i {} \;

format-check: format
	git diff --exit-code
	
install:
	arduino-cli lib download Servo
	arduino-cli lib install Servo
	arduino-cli lib download IRremote
	arduino-cli lib install IRremote
