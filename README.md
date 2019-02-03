# DC-motor-tester
Test a DC motor with an arduino nano. There is a rotary encoder and an oled screen to chose the parameters. There is a time counter and a revolutions counter in the program.

# How to
## Use the interface
At the boot, you just need to rotate the rotary encoder to see the menu. If you press the rotary encoder, the test starts with the default settings.

There is 2 test mode :
  - The default one is based the duration : the motor and the counter are activated during a defined time. At the end of the test, you can see how many rotation the motor has done.
  - The other one is based on the number of revolutions : the motor is activate until the number of revolutions set is reach.

The speed is a number (0-255) which matches to the PWM applied to the motor.

The dura setting matches to the duration of the test in seconds.

The revo setting matches to the number of revolutions wanted.

## Compile the code
In general cases, you just need to change the parameters.h and the pins.h files to adjust to your needs.

A makefile is included to compile the code.
