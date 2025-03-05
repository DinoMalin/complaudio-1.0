all: compile upload

compile:
	arduino-cli compile --fqbn arduino:mbed_nano:nano33ble sketch

upload:
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:mbed_nano:nano33ble sketch

listen:
	bash listen.sh

env:
	bash --rcfile env.sh

