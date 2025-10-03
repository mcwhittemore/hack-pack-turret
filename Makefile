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
	clang-format -i code/*.h
	clang-format -i code/**/*.h

format-check: format
	git diff --exit-code
	
install:
	arduino-cli lib download Servo
	arduino-cli lib install Servo
	arduino-cli lib download IRremote
	arduino-cli lib install IRremote
