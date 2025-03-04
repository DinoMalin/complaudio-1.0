all:
	arduino-cli compile --fqbn arduino:mbed_nano:nano33ble sketch
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:mbed_nano:nano33ble sketch
