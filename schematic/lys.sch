EESchema Schematic File Version 2
LIBS:74xgxx
LIBS:74xx
LIBS:ac-dc
LIBS:adc-dac
LIBS:analog_switches
LIBS:atmel
LIBS:audio
LIBS:brooktre
LIBS:cmos4000
LIBS:cmos_ieee
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:dc-dc
LIBS:device
LIBS:digital-audio
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:linear
LIBS:logo
LIBS:memory
LIBS:microchip
LIBS:microchip1
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microcontrollers
LIBS:motorola
LIBS:msp430
LIBS:nxp_armmcu
LIBS:opto
LIBS:philips
LIBS:power
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:regul
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:siliconi
LIBS:special
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:texas
LIBS:transf
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:xilinx
LIBS:tsop
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Lyt controller"
Date "14 mar 2015"
Rev ""
Comp "Telebørken"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA168A-P IC1
U 1 1 54EA1791
P 2800 4550
F 0 "IC1" H 2050 5800 40  0000 L BNN
F 1 "ATMEGA168A-P" H 3200 3150 40  0000 L BNN
F 2 "DIL28" H 2800 4550 30  0000 C CIN
F 3 "~" H 2800 4550 60  0000 C CNN
	1    2800 4550
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q2
U 1 1 54EA1D92
P 5700 5950
F 0 "Q2" H 5710 6120 60  0000 R CNN
F 1 "IRLZ34N" H 5710 5800 60  0000 R CNN
F 2 "~" H 5700 5950 60  0000 C CNN
F 3 "~" H 5700 5950 60  0000 C CNN
	1    5700 5950
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 54EA1DE2
P 4650 4350
F 0 "X1" H 4650 4500 60  0000 C CNN
F 1 "20MHz" H 4650 4200 60  0000 C CNN
F 2 "~" H 4650 4350 60  0000 C CNN
F 3 "~" H 4650 4350 60  0000 C CNN
	1    4650 4350
	0    -1   -1   0   
$EndComp
$Comp
L C C5
U 1 1 54EA1E33
P 4950 4050
F 0 "C5" H 4950 4150 40  0000 L CNN
F 1 "22pF" H 4956 3965 40  0000 L CNN
F 2 "~" H 4988 3900 30  0000 C CNN
F 3 "~" H 4950 4050 60  0000 C CNN
	1    4950 4050
	0    -1   -1   0   
$EndComp
$Comp
L C C6
U 1 1 54EA1E42
P 4950 4650
F 0 "C6" H 4950 4750 40  0000 L CNN
F 1 "22pF" H 4956 4565 40  0000 L CNN
F 2 "~" H 4988 4500 30  0000 C CNN
F 3 "~" H 4950 4650 60  0000 C CNN
	1    4950 4650
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 54EA224B
P 5000 5950
F 0 "R2" V 5080 5950 40  0000 C CNN
F 1 "100" V 5007 5951 40  0000 C CNN
F 2 "~" V 4930 5950 30  0000 C CNN
F 3 "~" H 5000 5950 30  0000 C CNN
	1    5000 5950
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR3
U 1 1 54EA233C
P 1750 3200
F 0 "#PWR3" H 1750 3290 20  0001 C CNN
F 1 "+5V" H 1750 3290 30  0000 C CNN
F 2 "" H 1750 3200 60  0000 C CNN
F 3 "" H 1750 3200 60  0000 C CNN
	1    1750 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 54EA2357
P 1750 6100
F 0 "#PWR4" H 1750 6100 30  0001 C CNN
F 1 "GND" H 1750 6030 30  0001 C CNN
F 2 "" H 1750 6100 60  0000 C CNN
F 3 "" H 1750 6100 60  0000 C CNN
	1    1750 6100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 54EA2366
P 5800 6250
F 0 "#PWR11" H 5800 6250 30  0001 C CNN
F 1 "GND" H 5800 6180 30  0001 C CNN
F 2 "" H 5800 6250 60  0000 C CNN
F 3 "" H 5800 6250 60  0000 C CNN
	1    5800 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR9
U 1 1 54EA2375
P 5250 4450
F 0 "#PWR9" H 5250 4450 30  0001 C CNN
F 1 "GND" H 5250 4380 30  0001 C CNN
F 2 "" H 5250 4450 60  0000 C CNN
F 3 "" H 5250 4450 60  0000 C CNN
	1    5250 4450
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q1
U 1 1 54EA2444
P 5700 5150
F 0 "Q1" H 5710 5320 60  0000 R CNN
F 1 "IRLZ34N" H 5710 5000 60  0000 R CNN
F 2 "~" H 5700 5150 60  0000 C CNN
F 3 "~" H 5700 5150 60  0000 C CNN
	1    5700 5150
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 54EA244A
P 5000 5150
F 0 "R1" V 5080 5150 40  0000 C CNN
F 1 "100" V 5007 5151 40  0000 C CNN
F 2 "~" V 4930 5150 30  0000 C CNN
F 3 "~" H 5000 5150 30  0000 C CNN
	1    5000 5150
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR10
U 1 1 54EA2450
P 5800 5450
F 0 "#PWR10" H 5800 5450 30  0001 C CNN
F 1 "GND" H 5800 5380 30  0001 C CNN
F 2 "" H 5800 5450 60  0000 C CNN
F 3 "" H 5800 5450 60  0000 C CNN
	1    5800 5450
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q3
U 1 1 54EA2458
P 5700 6750
F 0 "Q3" H 5710 6920 60  0000 R CNN
F 1 "IRLZ34N" H 5710 6600 60  0000 R CNN
F 2 "~" H 5700 6750 60  0000 C CNN
F 3 "~" H 5700 6750 60  0000 C CNN
	1    5700 6750
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 54EA245E
P 5000 6750
F 0 "R3" V 5080 6750 40  0000 C CNN
F 1 "100" V 5007 6751 40  0000 C CNN
F 2 "~" V 4930 6750 30  0000 C CNN
F 3 "~" H 5000 6750 30  0000 C CNN
	1    5000 6750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR12
U 1 1 54EA2464
P 5800 7050
F 0 "#PWR12" H 5800 7050 30  0001 C CNN
F 1 "GND" H 5800 6980 30  0001 C CNN
F 2 "" H 5800 7050 60  0000 C CNN
F 3 "" H 5800 7050 60  0000 C CNN
	1    5800 7050
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR15
U 1 1 54EA2BDC
P 6600 5300
F 0 "#PWR15" H 6600 5250 20  0001 C CNN
F 1 "+12V" H 6600 5400 30  0000 C CNN
F 2 "" H 6600 5300 60  0000 C CNN
F 3 "" H 6600 5300 60  0000 C CNN
	1    6600 5300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR16
U 1 1 54EA2BEB
P 6600 6000
F 0 "#PWR16" H 6600 6000 30  0001 C CNN
F 1 "GND" H 6600 5930 30  0001 C CNN
F 2 "" H 6600 6000 60  0000 C CNN
F 3 "" H 6600 6000 60  0000 C CNN
	1    6600 6000
	1    0    0    -1  
$EndComp
Text Label 5800 5650 0    60   ~ 0
Green
Text Label 5800 6450 0    60   ~ 0
Blue
Text Label 5800 4850 0    60   ~ 0
Red
$Comp
L 7805 U1
U 1 1 54EA2D48
P 2400 1550
F 0 "U1" H 2550 1354 60  0000 C CNN
F 1 "7805" H 2400 1750 60  0000 C CNN
F 2 "~" H 2400 1550 60  0000 C CNN
F 3 "~" H 2400 1550 60  0000 C CNN
	1    2400 1550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 54EA2D57
P 1900 1800
F 0 "C2" H 1900 1900 40  0000 L CNN
F 1 "100nF" H 1906 1715 40  0000 L CNN
F 2 "~" H 1938 1650 30  0000 C CNN
F 3 "~" H 1900 1800 60  0000 C CNN
	1    1900 1800
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 54EA2D66
P 2900 1800
F 0 "C3" H 2900 1900 40  0000 L CNN
F 1 "100nF" H 2906 1715 40  0000 L CNN
F 2 "~" H 2938 1650 30  0000 C CNN
F 3 "~" H 2900 1800 60  0000 C CNN
	1    2900 1800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C1
U 1 1 54EA2D75
P 1450 1800
F 0 "C1" H 1500 1900 50  0000 L CNN
F 1 "4,7µF" H 1500 1700 50  0000 L CNN
F 2 "~" H 1450 1800 60  0000 C CNN
F 3 "~" H 1450 1800 60  0000 C CNN
	1    1450 1800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C4
U 1 1 54EA2D84
P 3350 1800
F 0 "C4" H 3400 1900 50  0000 L CNN
F 1 "4,7µF" H 3400 1700 50  0000 L CNN
F 2 "~" H 3350 1800 60  0000 C CNN
F 3 "~" H 3350 1800 60  0000 C CNN
	1    3350 1800
	1    0    0    -1  
$EndComp
$Comp
L DIODE D1
U 1 1 54EA2F6F
P 2400 1050
F 0 "D1" H 2400 1150 40  0000 C CNN
F 1 "1N4001" H 2400 950 40  0000 C CNN
F 2 "~" H 2400 1050 60  0000 C CNN
F 3 "~" H 2400 1050 60  0000 C CNN
	1    2400 1050
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR2
U 1 1 54EA3019
P 2400 2300
F 0 "#PWR2" H 2400 2300 30  0001 C CNN
F 1 "GND" H 2400 2230 30  0001 C CNN
F 2 "" H 2400 2300 60  0000 C CNN
F 3 "" H 2400 2300 60  0000 C CNN
	1    2400 2300
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR1
U 1 1 54EA3097
P 1450 1350
F 0 "#PWR1" H 1450 1300 20  0001 C CNN
F 1 "+12V" H 1450 1450 30  0000 C CNN
F 2 "" H 1450 1350 60  0000 C CNN
F 3 "" H 1450 1350 60  0000 C CNN
	1    1450 1350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR5
U 1 1 54EA30FC
P 3350 1350
F 0 "#PWR5" H 3350 1440 20  0001 C CNN
F 1 "+5V" H 3350 1440 30  0000 C CNN
F 2 "" H 3350 1350 60  0000 C CNN
F 3 "" H 3350 1350 60  0000 C CNN
	1    3350 1350
	1    0    0    -1  
$EndComp
$Comp
L TSOP1738 IC2
U 1 1 54EA317C
P 5100 2450
F 0 "IC2" H 5100 2056 60  0000 C CNN
F 1 "TSOP31238" H 5100 2844 60  0000 C CNN
F 2 "" H 5100 2450 60  0000 C CNN
F 3 "" H 5100 2450 60  0000 C CNN
	1    5100 2450
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR7
U 1 1 54EA318B
P 4650 2600
F 0 "#PWR7" H 4650 2690 20  0001 C CNN
F 1 "+5V" H 4650 2690 30  0000 C CNN
F 2 "" H 4650 2600 60  0000 C CNN
F 3 "" H 4650 2600 60  0000 C CNN
	1    4650 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 54EA319A
P 4650 2350
F 0 "#PWR6" H 4650 2350 30  0001 C CNN
F 1 "GND" H 4650 2280 30  0001 C CNN
F 2 "" H 4650 2350 60  0000 C CNN
F 3 "" H 4650 2350 60  0000 C CNN
	1    4650 2350
	1    0    0    -1  
$EndComp
$Comp
L AVR-ISP-10 CON1
U 1 1 54EA337A
P 6000 3650
F 0 "CON1" H 5830 3980 50  0000 C CNN
F 1 "AVR-ISP-10" H 5660 3320 50  0000 L BNN
F 2 "AVR-ISP-10" V 5250 3700 50  0001 C CNN
F 3 "~" H 6000 3650 60  0000 C CNN
	1    6000 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR14
U 1 1 54EA3A56
P 6400 4000
F 0 "#PWR14" H 6400 4000 30  0001 C CNN
F 1 "GND" H 6400 3930 30  0001 C CNN
F 2 "" H 6400 4000 60  0000 C CNN
F 3 "" H 6400 4000 60  0000 C CNN
	1    6400 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 54EA3B2A
P 5200 3650
F 0 "#PWR8" H 5200 3650 30  0001 C CNN
F 1 "GND" H 5200 3580 30  0001 C CNN
F 2 "" H 5200 3650 60  0000 C CNN
F 3 "" H 5200 3650 60  0000 C CNN
	1    5200 3650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR13
U 1 1 54EA3B93
P 6400 3300
F 0 "#PWR13" H 6400 3390 20  0001 C CNN
F 1 "+5V" H 6400 3390 30  0000 C CNN
F 2 "" H 6400 3300 60  0000 C CNN
F 3 "" H 6400 3300 60  0000 C CNN
	1    6400 3300
	1    0    0    -1  
$EndComp
$Comp
L CONN_5 P1
U 1 1 54EA42C5
P 7200 5650
F 0 "P1" V 7150 5650 50  0000 C CNN
F 1 "LED STRIP" V 7250 5650 50  0000 C CNN
F 2 "~" H 7200 5650 60  0000 C CNN
F 3 "~" H 7200 5650 60  0000 C CNN
	1    7200 5650
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 54EA51D4
P 3450 6650
F 0 "K1" V 3400 6650 50  0000 C CNN
F 1 "UART" V 3500 6650 40  0000 C CNN
F 2 "~" H 3450 6650 60  0000 C CNN
F 3 "~" H 3450 6650 60  0000 C CNN
	1    3450 6650
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 54EA65A6
P 7950 3100
F 0 "D2" H 7950 3200 50  0000 C CNN
F 1 "LED" H 7950 3000 50  0000 C CNN
F 2 "~" H 7950 3100 60  0000 C CNN
F 3 "~" H 7950 3100 60  0000 C CNN
	1    7950 3100
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 54EA65B5
P 7950 3400
F 0 "D3" H 7950 3500 50  0000 C CNN
F 1 "LED" H 7950 3300 50  0000 C CNN
F 2 "~" H 7950 3400 60  0000 C CNN
F 3 "~" H 7950 3400 60  0000 C CNN
	1    7950 3400
	1    0    0    -1  
$EndComp
$Comp
L LED D4
U 1 1 54EA65C4
P 7950 3700
F 0 "D4" H 7950 3800 50  0000 C CNN
F 1 "LED" H 7950 3600 50  0000 C CNN
F 2 "~" H 7950 3700 60  0000 C CNN
F 3 "~" H 7950 3700 60  0000 C CNN
	1    7950 3700
	1    0    0    -1  
$EndComp
$Comp
L CONN_4 P2
U 1 1 54EA65D3
P 9800 3350
F 0 "P2" V 9750 3350 50  0000 C CNN
F 1 "CONTROLLER" V 9850 3350 50  0000 C CNN
F 2 "~" H 9800 3350 60  0000 C CNN
F 3 "~" H 9800 3350 60  0000 C CNN
	1    9800 3350
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 54EA672E
P 8550 3100
F 0 "R4" V 8630 3100 40  0000 C CNN
F 1 "R" V 8557 3101 40  0000 C CNN
F 2 "~" V 8480 3100 30  0000 C CNN
F 3 "~" H 8550 3100 30  0000 C CNN
	1    8550 3100
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 54EA673D
P 8550 3400
F 0 "R5" V 8630 3400 40  0000 C CNN
F 1 "R" V 8557 3401 40  0000 C CNN
F 2 "~" V 8480 3400 30  0000 C CNN
F 3 "~" H 8550 3400 30  0000 C CNN
	1    8550 3400
	0    -1   -1   0   
$EndComp
$Comp
L R R6
U 1 1 54EA674C
P 8550 3700
F 0 "R6" V 8630 3700 40  0000 C CNN
F 1 "R" V 8557 3701 40  0000 C CNN
F 2 "~" V 8480 3700 30  0000 C CNN
F 3 "~" H 8550 3700 30  0000 C CNN
	1    8550 3700
	0    -1   -1   0   
$EndComp
Text Label 9200 3200 0    60   ~ 0
+12V
Text Label 9300 3500 0    60   ~ 0
Red
Text Label 9200 3400 0    60   ~ 0
Green
Text Label 9250 3300 0    60   ~ 0
Blue
$Comp
L GND #PWR?
U 1 1 54EA6CDD
P 3000 6900
F 0 "#PWR?" H 3000 6900 30  0001 C CNN
F 1 "GND" H 3000 6830 30  0001 C CNN
F 2 "" H 3000 6900 60  0000 C CNN
F 3 "" H 3000 6900 60  0000 C CNN
	1    3000 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 3450 1750 3450
Wire Wire Line
	1750 3750 1900 3750
Wire Wire Line
	4350 4650 4750 4650
Wire Wire Line
	3800 4050 4750 4050
Connection ~ 4650 4050
Connection ~ 4650 4650
Wire Wire Line
	5150 4050 5150 4650
Connection ~ 5150 4350
Wire Wire Line
	1750 3200 1750 4050
Connection ~ 1750 3750
Wire Wire Line
	1750 4050 1900 4050
Connection ~ 1750 3450
Wire Wire Line
	1900 5650 1750 5650
Wire Wire Line
	1750 5650 1750 6100
Wire Wire Line
	1750 5750 1900 5750
Connection ~ 1750 5750
Wire Wire Line
	5250 5950 5500 5950
Wire Wire Line
	5800 6150 5800 6250
Wire Wire Line
	5250 5150 5500 5150
Wire Wire Line
	5800 5350 5800 5450
Wire Wire Line
	5250 6750 5500 6750
Wire Wire Line
	5800 6950 5800 7050
Wire Wire Line
	6600 5450 6800 5450
Wire Wire Line
	6600 5850 6800 5850
Wire Wire Line
	5800 4950 5800 4850
Wire Wire Line
	5800 4850 6150 4850
Wire Wire Line
	6150 4850 6150 5750
Wire Wire Line
	6150 5750 6800 5750
Wire Wire Line
	5800 5750 5800 5650
Wire Wire Line
	5800 5650 6800 5650
Wire Wire Line
	5800 6550 5800 6450
Wire Wire Line
	5800 6450 6350 6450
Wire Wire Line
	6350 6450 6350 5550
Wire Wire Line
	6350 5550 6800 5550
Wire Wire Line
	1450 1350 1450 1600
Wire Wire Line
	1450 1500 2000 1500
Wire Wire Line
	1900 1050 1900 1600
Connection ~ 1900 1500
Wire Wire Line
	2800 1500 3350 1500
Wire Wire Line
	3350 1350 3350 1600
Wire Wire Line
	2900 1050 2900 1600
Connection ~ 2900 1500
Wire Wire Line
	2400 1800 2400 2300
Wire Wire Line
	1450 2100 3350 2100
Wire Wire Line
	1450 2100 1450 2000
Wire Wire Line
	1900 2000 1900 2100
Connection ~ 1900 2100
Wire Wire Line
	2900 2100 2900 2000
Connection ~ 2400 2100
Wire Wire Line
	3350 2100 3350 2000
Connection ~ 2900 2100
Wire Wire Line
	2200 1050 1900 1050
Wire Wire Line
	2900 1050 2600 1050
Connection ~ 1450 1500
Connection ~ 3350 1500
Wire Wire Line
	6050 3550 6400 3550
Wire Wire Line
	6400 3550 6400 4000
Wire Wire Line
	6400 3650 6050 3650
Wire Wire Line
	6400 3750 6050 3750
Connection ~ 6400 3650
Wire Wire Line
	6400 3850 6050 3850
Connection ~ 6400 3750
Wire Wire Line
	4350 4650 4350 4150
Wire Wire Line
	4350 4150 3800 4150
Wire Wire Line
	3800 3850 5800 3850
Wire Wire Line
	3800 3950 4450 3950
Wire Wire Line
	4450 3950 4450 3750
Wire Wire Line
	4450 3750 5800 3750
Wire Wire Line
	3800 3750 4250 3750
Wire Wire Line
	4250 3750 4250 3450
Wire Wire Line
	4250 3450 5800 3450
Wire Wire Line
	5800 3650 5400 3650
Wire Wire Line
	5400 3650 5400 4900
Wire Wire Line
	5400 4900 3800 4900
Connection ~ 6400 3850
Wire Wire Line
	3800 4600 4250 4600
Wire Wire Line
	4250 4600 4250 5150
Wire Wire Line
	4250 5150 4750 5150
Wire Wire Line
	3800 4400 4200 4400
Wire Wire Line
	4200 5950 4750 5950
Wire Wire Line
	4200 4400 4200 5950
Wire Wire Line
	3800 4500 4150 4500
Wire Wire Line
	4150 4500 4150 6750
Wire Wire Line
	4150 6750 4750 6750
Wire Wire Line
	4800 2250 4650 2250
Wire Wire Line
	4650 2250 4650 2350
Wire Wire Line
	4650 2600 4650 2650
Wire Wire Line
	4650 2650 4800 2650
Wire Wire Line
	6050 3450 6400 3450
Wire Wire Line
	6400 3450 6400 3300
Wire Wire Line
	5200 3650 5200 3550
Wire Wire Line
	5200 3550 5800 3550
Wire Wire Line
	5150 4350 5250 4350
Wire Wire Line
	5250 4350 5250 4450
Wire Wire Line
	6600 6000 6600 5850
Wire Wire Line
	6600 5300 6600 5450
Wire Wire Line
	8150 3100 8300 3100
Wire Wire Line
	8150 3400 8300 3400
Wire Wire Line
	8150 3700 8300 3700
Wire Wire Line
	7750 3100 7650 3100
Wire Wire Line
	7650 2850 7650 3700
Wire Wire Line
	7650 3700 7750 3700
Wire Wire Line
	7750 3400 7650 3400
Connection ~ 7650 3400
Wire Wire Line
	8800 3700 9200 3700
Wire Wire Line
	9450 3400 8800 3400
Wire Wire Line
	9450 3500 9200 3500
Wire Wire Line
	9200 3500 9200 3700
Wire Wire Line
	9450 3300 9100 3300
Wire Wire Line
	9100 3300 9100 3100
Wire Wire Line
	9100 3100 8800 3100
Wire Wire Line
	7650 2850 9200 2850
Wire Wire Line
	9200 2850 9200 3200
Wire Wire Line
	9200 3200 9450 3200
Connection ~ 7650 3100
Wire Wire Line
	3000 6900 3000 6750
Wire Wire Line
	3000 6750 3100 6750
Wire Wire Line
	3800 5050 3950 5050
Wire Wire Line
	3950 5050 3950 6400
Wire Wire Line
	3950 6400 3000 6400
Wire Wire Line
	3000 6400 3000 6550
Wire Wire Line
	3000 6550 3100 6550
Wire Wire Line
	3800 5150 3900 5150
Wire Wire Line
	3900 5150 3900 6350
Wire Wire Line
	3900 6350 2950 6350
Wire Wire Line
	2950 6350 2950 6650
Wire Wire Line
	2950 6650 3100 6650
Wire Wire Line
	4800 2450 4050 2450
Wire Wire Line
	4050 2450 4050 5750
Wire Wire Line
	4050 5750 3800 5750
$EndSCHEMATC
