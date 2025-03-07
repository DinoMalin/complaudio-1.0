
# ParanoIA-1.0

A cute complotist robot.

## Description

ParanoIA-1.0 is an a complotist bot. You can speak with him about all your complotist theories, and he will answer with even worst ones.

![image of the robot](https://raw.githubusercontent.com/DinoMalin/paranoia-1.0/refs/heads/master/cvB1UKQx.jpg)
## Electronic

Here is the electronic wiring. I use two arduinos because the lib i'm using doesn't allow me to put multiples lcd on this one. I use two LCD screen LCM 1602m which allows me to express the emotions of the robot and the complot gauge.

![schema of the electronic wiring](https://raw.githubusercontent.com/DinoMalin/paranoia-1.0/refs/heads/master/schema.jpg)
## Usage

### Building the robot
How can you make it work at home ?
If you're not on a crappy arch like me, modify the microphone and speaker in ai.py. There's a comment on how you can set your default microphone/speaker.

You must have an arduino uno that creates a /dev/ttyACM0 serial port, and one that creates a /dev/ttyUSB0.\
Begin by flashing the arduino attached to the serial /dev/ACM0.  This will be the face of the robot.
You can do this by typing ```make``` in a terminal.\
Then flash the /dev/ttyUSB0. That will be the complot gauge.
You can do this by typing ```make jauge``` in a terminal.

You should have your two lcds attached to one arduino each. Place them in the body of your robot.

### Modifying the Robot
You can enter a screen session to modify the emotions of the robot: ```screen /dev/ttyACM0 9600```. You can then type numbers between 1 and 5 to change the face of the robot.

You can do the same to modify the gauge: ```screen /dev/ttyACM0 9600```. The gauge has 9 levels: between 0 and 8.

### Talking to the Robot
To talk to the robot, use make env to create and enter a virtual environment (```source env/bin/activate``` if already created).\
Create a .env filled with your api keys.\
Launch ```python ai.py``` to talk to the robot. Don't forget to turn on your speaker !
## The complot skate

We have a skate. It's awesome.

![image of the skate](https://raw.githubusercontent.com/DinoMalin/paranoia-1.0/refs/heads/master/skate.jpg)