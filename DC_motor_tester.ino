//By Romain THOMAS    (2019)    UTT

//battery.level()

#include "parameters.h"
#include "pins.h"
#include "logo.h"
#include <Encoder.h>
#include <Battery.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//1K of RAM is use by the screen for the buffer

#define MENU_ITEM_NB				4

//test_state :
#define TEST_EXITED					0 //display test results
#define TEST_IN_PROGRESS			1
#define TEST_IN_INITIALIZATION		2
#define TEST_FINISHED				3 //after TEST_FINISHED

//menu :
#define OK							0
#define SET_TEST_MODE				1
#define SET_SPEED					2
#define DURATION_OR_REVO			3

//selec_menu_or_value
#define MENU_SELEC					0
#define CHANGE_VALUE				1

//test_mode
#define DURATION_TEST_MODE			0
#define REVOLUTIONS_NB_TEST_MODE	1

#define MENU_0	"OK"
#define MENU_1	"Mode"	//Test mode
#define MENU_2	"Speed"	
#define MENU_3A	"Dura"	//Test duration
#define MENU_3B	"Revo"	//Test revolutions

void refreshScreen();
uint8_t test();
int getCurrent(); //get the current passing through the motor in mA

Encoder myEnc(ENCODER_A_PIN, ENCODER_B_PIN);
Battery battery(MIN_BATTERY, MAX_BATTERY, BATTERY_PIN);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

long oldPosition  = 0;
uint8_t menuPosition = 0;
uint8_t test_state = 0;//refer to defines
uint8_t menu = 0;// 0 : OK | 1 : set test mode | 2 : set speed | 3 : set test duration or revolutions nb 
uint8_t selec_menu_or_value = 0;//0 : selec menu | 1 : change value
int8_t buffer_selec_menu = 0;
int8_t buffer_change_value = 0;
uint8_t test_mode = DEFAULT_TEST_MODE;
uint8_t motor_speed = DEFAULT_SPEED;
uint8_t test_duration = DEFAULT_DURATION;
uint8_t test_revolutions_nb = DEFAULT_REVOLUTIONS;
uint8_t mem = HIGH;//memory for button
uint8_t e;//tmp var for button
uint8_t mem_counter = HIGH;
uint8_t motor_revo_counter = 0;
uint8_t effective_test_duration = 0;
long current_sum = 0;
long current_measures_nb = 0;
long t = millis();

void setup()
{
	Serial.begin(57600);
	
	battery.begin(5000, 1.0, &sigmoidal);

	 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    	Serial.println(F("SSD1306 allocation failed"));
    	for(;;); // Don't proceed, loop forever
	}
	
	// Clear the buffer
	display.clearDisplay();
	display.drawBitmap(
    0,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);

    display.setTextSize(1);             // Normal 1:1 pixel scale
	display.setTextColor(WHITE);        // Draw white text
	display.setCursor(80,0);
	display.println(F("DC motor"));
	display.setCursor(92,8);
	display.println(F("tester"));
	display.setCursor(98,16);
	display.println(F("V 1.0"));
	display.setCursor(80,24);
	display.println(F("Bat "));
	display.setCursor(104,24);
	display.println(battery.level());
	display.setCursor(122,24);
	display.println(F("%"));
	display.setCursor(104,47);
	display.println(F("2019"));
	display.setCursor(80,56);
	display.println(F("Romain T"));

	display.display();	//refresh the screen

	pinMode(MOTOR_PIN, OUTPUT);
	analogWrite(MOTOR_PIN, 0);
	pinMode(MOTOR_REV_COUNTER, INPUT_PULLUP);
	pinMode(SW_PIN, INPUT_PULLUP);

	//analogReference(INTERNAL);//set analog reference to 1.1V instead of the 5V default
	//disable because of the battery value are up to 4.2 V
}

void loop()
{
	Serial.println(battery.level());
	long newPosition = myEnc.read();
	if (newPosition != oldPosition) {
		Serial.println(newPosition);
		int8_t tmp = (int8_t)(newPosition - oldPosition);
	    if(selec_menu_or_value == MENU_SELEC){
	        buffer_selec_menu += tmp;
	        menu = (uint8_t)((int8_t)menu + buffer_selec_menu/4)%MENU_ITEM_NB;
	        buffer_selec_menu = buffer_selec_menu%4;
	        Serial.print(buffer_selec_menu);
	        Serial.print("\tmenu :");
	        Serial.println(menu);
	    }
	    else{//CHANGE_VALUE
	    	buffer_change_value += tmp;
	    	if(menu == SET_SPEED){
	    	    motor_speed = (uint8_t)(((int)motor_speed + (int)buffer_change_value/4)%256);
	    	}
	    	else if(menu == DURATION_OR_REVO){
	    		if(test_mode == DURATION_TEST_MODE){
	    		    test_duration = (uint8_t)(((int)test_duration + (int)buffer_change_value/4)%256);
	    		}
	    		else{
	    			test_revolutions_nb = (uint8_t)(((int)test_revolutions_nb + (int)buffer_change_value/4)%256);
	    		}
	    	}
	    	buffer_change_value = buffer_change_value%4;
	    }
    	oldPosition = newPosition;
    	refreshScreen();
	}

	e = digitalRead(SW_PIN);
	if((e == LOW) && (mem == HIGH)){
		Serial.print("switch trig ");
	    
		selec_menu_or_value = 1 - selec_menu_or_value;
		if(menu == 0){//if no test running when menu OK is selected
		    if((test_state == TEST_EXITED)){
		    	test_state = TEST_IN_INITIALIZATION;//initialize the test		        
		    }
		    else{
		    	test_state = TEST_EXITED;
		    	analogWrite(MOTOR_PIN, 0);
		    }
		}
		
		long tmp = myEnc.read()%4;
		buffer_change_value = (uint8_t)tmp;
		buffer_selec_menu = (uint8_t)tmp;
		if(selec_menu_or_value == MENU_SELEC){
		    Serial.println("Set to menu selec");
		}
		else{
			Serial.println("Set to change value");
		}

		refreshScreen();
	}
	mem = e;

	if(selec_menu_or_value == CHANGE_VALUE){
	    switch (menu) {
	        case OK:
	          selec_menu_or_value = test();
	          break;
	        case SET_TEST_MODE:
	          test_mode = 1 - test_mode;
	          selec_menu_or_value = MENU_SELEC;
	          break;
	        case SET_SPEED:
	          
	          break;
	        case DURATION_OR_REVO:
	          
	          break;
	    }
	    refreshScreen();
	}

	e = digitalRead(MOTOR_REV_COUNTER);
	if((e == LOW) && (mem_counter == HIGH)){
		Serial.println("motor rev counter switch trig");
		if(test_state == TEST_IN_PROGRESS){
		    motor_revo_counter++;
		}
	}
	mem_counter = e;
}

void refreshScreen()
{
	display.clearDisplay();

	if(test_state == TEST_EXITED){
		display.setTextSize(1);
		display.setCursor(104,0);
		display.println(battery.level());
		display.setCursor(122,0);
		display.println(F("%"));

		display.setTextSize(2);

		if(menu == OK){
		    display.setTextColor(BLACK, WHITE);
		}
		else{
			display.setTextColor(WHITE, BLACK);
		}
		display.setCursor(0,0);
		display.println(F(MENU_0));

		if(menu == SET_TEST_MODE){
		    display.setTextColor(BLACK, WHITE);
		}
		else{
			display.setTextColor(WHITE, BLACK);
		}
		display.setCursor(0,16);
		display.println(F(MENU_1));

		if((menu == SET_SPEED) && (selec_menu_or_value == MENU_SELEC)){
		    display.setTextColor(BLACK, WHITE);
		}
		else{
			display.setTextColor(WHITE, BLACK);
		}
		display.setCursor(0,32);
		display.println(F(MENU_2));
		if((menu == SET_SPEED) && (selec_menu_or_value == CHANGE_VALUE)){
		    display.setTextColor(BLACK, WHITE);
		}
		else{
			display.setTextColor(WHITE, BLACK);
		}
		display.setCursor(91,32);
		display.println(motor_speed);

		if((menu == DURATION_OR_REVO) && (selec_menu_or_value == MENU_SELEC)){
		    display.setTextColor(BLACK, WHITE);
		}
		else{
			display.setTextColor(WHITE, BLACK);
		}
		display.setCursor(0,48);
	    if(test_mode == DURATION_TEST_MODE){
			display.println(F(MENU_3A));
			if((menu == DURATION_OR_REVO) && (selec_menu_or_value == CHANGE_VALUE)){
		    display.setTextColor(BLACK, WHITE);
			}
			else{
				display.setTextColor(WHITE, BLACK);
			}
			display.setCursor(91,48);
			display.println(test_duration);
	    }
	    else{
	    	display.println(F(MENU_3B));
	    	if((menu == DURATION_OR_REVO) && (selec_menu_or_value == CHANGE_VALUE)){
		    display.setTextColor(BLACK, WHITE);
			}
			else{
				display.setTextColor(WHITE, BLACK);
			}
	    	display.setCursor(91,48);
			display.println(test_revolutions_nb);
	    }
	}
	else{
		display.setTextSize(2);
	    if(test_state == TEST_IN_PROGRESS){
	        display.setTextColor(WHITE, BLACK);
			display.setCursor(0,0);
			display.println(F("Test in"));
			display.setCursor(0,16);
			display.println(F("progress"));
			display.setCursor(0,32);
			display.println(F("I="));
			display.setCursor(24,32);
			display.println(getCurrent());
			current_sum += (long)getCurrent();
			current_measures_nb++;
			display.setCursor(60,32);
			display.println(F("mA"));
			display.setCursor(0,48);
			display.println(F("["));
			display.setCursor(108,48);
			display.println(F("]"));
			int count;
			if(test_mode == DURATION_TEST_MODE){
			    count = (int)((millis() - t)*8/(((long)test_duration)*1000));
			}
			else{//REVOLUTIONS_NB_TEST_MODE
				count = ((int)motor_revo_counter)*8/((int)test_revolutions_nb);
			}
			for (int i = 0; i < count; ++i)
			{
				display.setCursor(12+i*12,48);
				display.println(F("="));
			}
	    }
	    else if(test_state == TEST_FINISHED){
	        display.setTextColor(WHITE, BLACK);
	        display.setCursor(0,0);
			display.println(F("Test fini-"));
			display.setCursor(0,16);
			display.println(F("shed I="));
			display.setCursor(84,16);
			display.println(current_sum/current_measures_nb);
			display.setCursor(0,32);
			display.println(F("mA"));
			display.setCursor(36,32);
			display.println(motor_revo_counter);
			display.setCursor(72,32);
			display.println(F("revo"));
			display.setCursor(0,48);
			display.println(F("in"));
			display.setCursor(36,48);
			display.println(effective_test_duration);
			display.setCursor(72,48);
			display.println(F("s"));
	    }
	}

	

	display.display();
}

uint8_t test()
{
	uint8_t res;
	if(test_state == TEST_FINISHED){
	    res = CHANGE_VALUE;
	}
	else if(test_state == TEST_IN_INITIALIZATION){
	    t = millis();
	    motor_revo_counter = 0;
	    analogWrite(MOTOR_PIN, motor_speed);
	    res = CHANGE_VALUE;
	    test_state = TEST_IN_PROGRESS;
	}
	else if(test_state == TEST_IN_PROGRESS){
		if(test_mode == DURATION_TEST_MODE){
		    if(millis() > t + ((long)test_duration)*1000){
			    analogWrite(MOTOR_PIN, 0);
				test_state = TEST_FINISHED;
				effective_test_duration = test_duration;
				Serial.println("time finished");
			}
		}
		else{//REVOLUTIONS_NB_TEST_MODE
			if(motor_revo_counter >= test_revolutions_nb){
			    analogWrite(MOTOR_PIN, 0);
				test_state = TEST_FINISHED;
				effective_test_duration = (uint8_t)((millis() - t)/1000);
				Serial.println("revolutions nb target reached");
			}
		}
		
		res = CHANGE_VALUE;
	}
	else{//TEST_EXITED
		res = MENU_SELEC;
		analogWrite(MOTOR_PIN, 0);
	}

	return res;
}

int getCurrent()
{
	return map(analogRead(CURRENT_MES_R_PIN), 0, 1023, 0, 4167);
	//R = 1.2 Ohms
	//U=RI ==> I=U/R
	//Umax = 5V ==> 1023
	//Imax = 5/1.2*1000 = 4167 mA
}