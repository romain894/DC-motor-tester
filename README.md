french below
# DC-motor-tester
Test a DC motor with an arduino nano. There is a rotary encoder and an oled screen to chose the parameters. There is a time counter and a revolutions counter in the program.

# How to
## Use the interface
At the boot, you just need to rotate the rotary encoder to see the menu. If you press the rotary encoder, the test starts with the default settings.

There is 2 test mode :
  - The default one is based the duration : the motor and the counter are activated during a defined time. At the end of the test, you can see how many rotations the motor has done.
  - The other one is based on the number of revolutions : the motor is activate until the number of revolutions set is reach.

The speed is a number (0-255) which matches to the PWM applied to the motor.

The dura setting matches to the duration of the test in seconds.

The revo setting matches to the number of revolutions wanted.

## Compile the code
In general cases, you just need to change the parameters.h and the pins.h files to adjust the programm to your needs.

A makefile is included to compile the code.

# Testeur de moteur DC
Test un moteur DC avec un arduino nano. Il y a un encodeur rotatif et un écran oled pour choisir les paramtres. Il y a un compteur pour le temps et le nombre de rotations dans le programme.

# Comment
## Utiliser l'interface
Au démarrage, il faut juste tourner l'encodeur rotatif pour voir le menu. Si vous appuyez sur l'encodeur rotatif, le test commence avec les paramètres par défaut.

Il y a 2 modes de test :
  - Celui par défaut est basé sur la durée : le moteur et le compteur sont activés pendant un temps définit. A la fin du test, vous pouvez voir combien de tours le moteur a effectué.
  - L'autre est bsé sur le nombre de révolutions : le moteur est activé jusqu'au moment où le nombre de révolutions réglé est atteint.

Le paramètre speed est un nombre (0-255) qui correspond au PWM appliqué au moteur.

Le paramètre dura permet de choisir la durée du test en secondes.

Le paramètre revo sert à régler le nombre de révolutions désirées.

## Compiler le code
En général, il suffit de modifier les fichiers paramters.h et pins.h pour ajuster le programme à vos besoins.

Un makefile est inclu pour compiler le code.
