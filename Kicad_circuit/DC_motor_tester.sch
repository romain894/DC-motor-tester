EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_nano
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino_Nano A?
U 1 1 5C56FFD8
P 2050 2550
F 0 "A?" H 2050 2550 60  0000 C CNN
F 1 "Arduino_Nano" H 2050 2700 60  0000 C CNN
F 2 "" H 2050 2550 60  0000 C CNN
F 3 "" H 2050 2550 60  0000 C CNN
	1    2050 2550
	1    0    0    -1  
$EndComp
$Comp
L IRLZ44N Q?
U 1 1 5C570088
P 3700 2100
F 0 "Q?" H 3950 2175 50  0000 L CNN
F 1 "IRLZ44N" H 3950 2100 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 3950 2025 50  0001 L CIN
F 3 "" H 3700 2100 50  0001 L CNN
	1    3700 2100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C5700C5
P 4050 1800
F 0 "R?" V 4130 1800 50  0000 C CNN
F 1 "1.2 R" V 4050 1800 50  0000 C CNN
F 2 "" V 3980 1800 50  0001 C CNN
F 3 "" H 4050 1800 50  0001 C CNN
	1    4050 1800
	0    1    1    0   
$EndComp
$Comp
L Conn_01x02_Male J_motor_switch
U 1 1 5C570142
P 3350 2400
F 0 "J_motor_switch" H 3350 2500 50  0000 C CNN
F 1 "Conn_01x02_Male" H 3350 2200 50  0000 C CNN
F 2 "" H 3350 2400 50  0001 C CNN
F 3 "" H 3350 2400 50  0001 C CNN
	1    3350 2400
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x02_Male J_motor
U 1 1 5C570193
P 4650 1800
F 0 "J_motor" H 4650 1900 50  0000 C CNN
F 1 "Conn_01x02_Male" H 4650 1600 50  0000 C CNN
F 2 "" H 4650 1800 50  0001 C CNN
F 3 "" H 4650 1800 50  0001 C CNN
	1    4650 1800
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x04 J_Oled_screen
U 1 1 5C5701E0
P 3200 4100
F 0 "J_Oled_screen" H 3200 4300 50  0000 C CNN
F 1 "Conn_01x04" H 3200 3800 50  0000 C CNN
F 2 "" H 3200 4100 50  0001 C CNN
F 3 "" H 3200 4100 50  0001 C CNN
	1    3200 4100
	0    1    1    0   
$EndComp
$Comp
L Battery_Cell BT?
U 1 1 5C57026B
P 3200 3200
F 0 "BT?" H 3300 3300 50  0000 L CNN
F 1 "Battery_Cell" H 3300 3200 50  0000 L CNN
F 2 "" V 3200 3260 50  0001 C CNN
F 3 "" V 3200 3260 50  0001 C CNN
	1    3200 3200
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5C570345
P 1150 1850
F 0 "#PWR?" H 1150 1700 50  0001 C CNN
F 1 "+5V" H 1150 1990 50  0000 C CNN
F 2 "" H 1150 1850 50  0001 C CNN
F 3 "" H 1150 1850 50  0001 C CNN
	1    1150 1850
	1    0    0    -1  
$EndComp
$Comp
L D D?
U 1 1 5C5704EB
P 4350 2150
F 0 "D?" H 4350 2250 50  0000 C CNN
F 1 "D" H 4350 2050 50  0000 C CNN
F 2 "" H 4350 2150 50  0001 C CNN
F 3 "" H 4350 2150 50  0001 C CNN
	1    4350 2150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5C5707C1
P 1200 3600
F 0 "#PWR?" H 1200 3350 50  0001 C CNN
F 1 "GND" H 1200 3450 50  0000 C CNN
F 2 "" H 1200 3600 50  0001 C CNN
F 3 "" H 1200 3600 50  0001 C CNN
	1    1200 3600
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5C570BAC
P 4150 1550
F 0 "#PWR?" H 4150 1400 50  0001 C CNN
F 1 "+5V" H 4150 1690 50  0000 C CNN
F 2 "" H 4150 1550 50  0001 C CNN
F 3 "" H 4150 1550 50  0001 C CNN
	1    4150 1550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5C570E12
P 3150 2100
F 0 "R?" V 3230 2100 50  0000 C CNN
F 1 "1k" V 3150 2100 50  0000 C CNN
F 2 "" V 3080 2100 50  0001 C CNN
F 3 "" H 3150 2100 50  0001 C CNN
	1    3150 2100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5C571774
P 3000 2450
F 0 "#PWR?" H 3000 2200 50  0001 C CNN
F 1 "GND" H 3000 2300 50  0000 C CNN
F 2 "" H 3000 2450 50  0001 C CNN
F 3 "" H 3000 2450 50  0001 C CNN
	1    3000 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5C571A13
P 3650 3250
F 0 "#PWR?" H 3650 3000 50  0001 C CNN
F 1 "GND" H 3650 3100 50  0000 C CNN
F 2 "" H 3650 3250 50  0001 C CNN
F 3 "" H 3650 3250 50  0001 C CNN
	1    3650 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 3600 1200 3550
Wire Wire Line
	1200 3550 1400 3550
Wire Wire Line
	1150 1850 1150 1900
Wire Wire Line
	1150 1900 1400 1900
Wire Wire Line
	4150 1550 4150 1700
Wire Wire Line
	4150 1700 4450 1700
Wire Wire Line
	4200 1800 4450 1800
Wire Wire Line
	3900 1800 3800 1800
Wire Wire Line
	3800 1800 3800 1900
Wire Wire Line
	3800 2400 3800 2300
Wire Wire Line
	3500 2100 3300 2100
Wire Wire Line
	4350 2350 3800 2350
Connection ~ 3800 2350
Wire Wire Line
	3900 1950 3900 1850
Wire Wire Line
	3900 1850 3800 1850
Connection ~ 3800 1850
Wire Wire Line
	3900 1950 4350 1950
Wire Wire Line
	4350 1950 4350 2000
Wire Wire Line
	4350 2350 4350 2300
Wire Wire Line
	2750 2100 3000 2100
Wire Wire Line
	3150 2400 3000 2400
Wire Wire Line
	3000 2400 3000 2450
Wire Wire Line
	2750 3200 3000 3200
Wire Wire Line
	3300 3200 3650 3200
Wire Wire Line
	3650 3200 3650 3250
Wire Wire Line
	3300 3900 3300 3300
Wire Wire Line
	3300 3300 2750 3300
Wire Wire Line
	3200 3900 3200 3400
Wire Wire Line
	3200 3400 2750 3400
$Comp
L GND #PWR?
U 1 1 5C571C7C
P 2000 3850
F 0 "#PWR?" H 2000 3600 50  0001 C CNN
F 1 "GND" H 2000 3700 50  0000 C CNN
F 2 "" H 2000 3850 50  0001 C CNN
F 3 "" H 2000 3850 50  0001 C CNN
	1    2000 3850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5C571CA4
P 2150 3900
F 0 "#PWR?" H 2150 3750 50  0001 C CNN
F 1 "+5V" H 2150 4040 50  0000 C CNN
F 2 "" H 2150 3900 50  0001 C CNN
F 3 "" H 2150 3900 50  0001 C CNN
	1    2150 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	3000 3900 3000 3850
Wire Wire Line
	3000 3850 2150 3850
Wire Wire Line
	2150 3850 2150 3900
Wire Wire Line
	2000 3850 2000 3800
Wire Wire Line
	2000 3800 3100 3800
Wire Wire Line
	3100 3800 3100 3900
$Comp
L Rotary_Encoder_Switch SW?
U 1 1 5C571F88
P 3450 1450
F 0 "SW?" H 3450 1710 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 3450 1190 50  0000 C CNN
F 2 "" H 3350 1610 50  0001 C CNN
F 3 "" H 3450 1710 50  0001 C CNN
	1    3450 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2300 3150 2300
Wire Wire Line
	2750 1800 3150 1800
Wire Wire Line
	3150 1800 3150 1550
Wire Wire Line
	2750 1700 2850 1700
Wire Wire Line
	2850 1700 2850 1350
Wire Wire Line
	2850 1350 3150 1350
$Comp
L GND #PWR?
U 1 1 5C57254B
P 3000 1500
F 0 "#PWR?" H 3000 1250 50  0001 C CNN
F 1 "GND" H 3000 1350 50  0000 C CNN
F 2 "" H 3000 1500 50  0001 C CNN
F 3 "" H 3000 1500 50  0001 C CNN
	1    3000 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 1500 3000 1450
Wire Wire Line
	3000 1450 3150 1450
$Comp
L GND #PWR?
U 1 1 5C5725A8
P 3850 1550
F 0 "#PWR?" H 3850 1300 50  0001 C CNN
F 1 "GND" H 3850 1400 50  0000 C CNN
F 2 "" H 3850 1550 50  0001 C CNN
F 3 "" H 3850 1550 50  0001 C CNN
	1    3850 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1550 3850 1550
Wire Wire Line
	2750 2700 5000 2700
Wire Wire Line
	5000 2700 5000 1350
Wire Wire Line
	5000 1350 3750 1350
$Comp
L GND #PWR?
U 1 1 5C5726AE
P 3800 2400
F 0 "#PWR?" H 3800 2150 50  0001 C CNN
F 1 "GND" H 3800 2250 50  0000 C CNN
F 2 "" H 3800 2400 50  0001 C CNN
F 3 "" H 3800 2400 50  0001 C CNN
	1    3800 2400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
