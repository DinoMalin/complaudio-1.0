all: compile upload

compile:
	arduino-cli compile --fqbn arduino:avr:uno sketch

upload:
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno sketch

listen:
	bash listen.sh

env:
	bash --rcfile env.sh

jauge: compile-jauge upload_jauge

compile-jauge:
	arduino-cli compile --fqbn arduino:avr:uno jauge

upload_jauge:
	arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno jauge

