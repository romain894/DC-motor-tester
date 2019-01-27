#ifndef PARAMETERS_H
#define PARAMETERS_H

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

//Default settings for motor test :
#define DEFAULT_TEST_MODE	0	//duration test mode : 0 | revolutions nb test mode : 1
#define DEFAULT_SPEED		255 //pwm : 0 - 255
#define DEFAULT_DURATION	10	//duration in seconds : 0 - 255
#define DEFAULT_REVOLUTIONS	10	//revolutions number goal for the motor : 0 - 255

#endif