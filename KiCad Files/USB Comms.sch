EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "ESP32 DevBoard"
Date "2019-01-26"
Rev "1.3"
Comp "Air University Islamabad"
Comment1 "BEMTS-6B"
Comment2 "Usman Mehmood"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Interface_USB:CH340G U10
U 1 1 5C49ED4D
P 6350 3800
F 0 "U10" H 6389 4509 50  0000 L CNN
F 1 "CH340G" H 6389 4430 50  0000 L CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 6400 3250 50  0001 L CNN
F 3 "http://www.datasheet5.com/pdf-local-2195953" H 6000 4600 50  0001 C CNN
	1    6350 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3050 6350 3150
$Comp
L power:GND #PWR063
U 1 1 5C4AE9B0
P 6350 4400
F 0 "#PWR063" H 6350 4150 50  0001 C CNN
F 1 "GND" H 6355 4227 50  0000 C CNN
F 2 "" H 6350 4400 50  0001 C CNN
F 3 "" H 6350 4400 50  0001 C CNN
	1    6350 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C43
U 1 1 5C4E63C1
P 5450 3150
F 0 "C43" H 5542 3196 50  0000 L CNN
F 1 "100nF" H 5542 3105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5450 3150 50  0001 C CNN
F 3 "~" H 5450 3150 50  0001 C CNN
	1    5450 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR058
U 1 1 5C4F66CE
P 5450 3250
F 0 "#PWR058" H 5450 3000 50  0001 C CNN
F 1 "GND" H 5455 3077 50  0000 C CNN
F 2 "" H 5450 3250 50  0001 C CNN
F 3 "" H 5450 3250 50  0001 C CNN
	1    5450 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C44
U 1 1 5C4F6836
P 6100 3150
F 0 "C44" V 5871 3150 50  0000 C CNN
F 1 "10nF" V 5962 3150 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6100 3150 50  0001 C CNN
F 3 "~" H 6100 3150 50  0001 C CNN
	1    6100 3150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR056
U 1 1 5C4F68F9
P 5950 3200
F 0 "#PWR056" H 5950 2950 50  0001 C CNN
F 1 "GND" H 5955 3027 50  0000 C CNN
F 2 "" H 5950 3200 50  0001 C CNN
F 3 "" H 5950 3200 50  0001 C CNN
	1    5950 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3150 5950 3150
Wire Wire Line
	5950 3150 5950 3200
Wire Wire Line
	6200 3150 6250 3150
Wire Wire Line
	6250 3150 6250 3200
NoConn ~ 5950 3500
NoConn ~ 6750 4000
NoConn ~ 6750 3900
NoConn ~ 6750 3800
NoConn ~ 6750 3700
Text GLabel 5950 3700 0    50   Input ~ 0
D+
Text GLabel 5950 3800 0    50   Input ~ 0
D-
Wire Wire Line
	6750 3500 6850 3500
Wire Wire Line
	6750 3400 6800 3400
$Comp
L Device:R_Small_US R36
U 1 1 5CF801BF
P 6800 3150
F 0 "R36" H 6868 3150 50  0000 L CNN
F 1 "4.7K" H 6868 3105 50  0000 L TNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 6800 3150 50  0001 C CNN
F 3 "~" H 6800 3150 50  0001 C CNN
	1    6800 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3250 6800 3400
Connection ~ 6800 3400
Wire Wire Line
	6800 3400 6850 3400
$Comp
L power:+3.3V #PWR054
U 1 1 5C8F955A
P 6350 3050
F 0 "#PWR054" H 6350 2900 50  0001 C CNN
F 1 "+3.3V" H 6365 3223 50  0000 C CNN
F 2 "" H 6350 3050 50  0001 C CNN
F 3 "" H 6350 3050 50  0001 C CNN
	1    6350 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR055
U 1 1 5C8F95F0
P 6800 3050
F 0 "#PWR055" H 6800 2900 50  0001 C CNN
F 1 "+3.3V" H 6815 3223 50  0000 C CNN
F 2 "" H 6800 3050 50  0001 C CNN
F 3 "" H 6800 3050 50  0001 C CNN
	1    6800 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR053
U 1 1 5C8F9686
P 5450 3050
F 0 "#PWR053" H 5450 2900 50  0001 C CNN
F 1 "+3.3V" H 5465 3223 50  0000 C CNN
F 2 "" H 5450 3050 50  0001 C CNN
F 3 "" H 5450 3050 50  0001 C CNN
	1    5450 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3150 6250 3150
Connection ~ 6350 3150
Wire Wire Line
	6350 3150 6350 3200
Connection ~ 6250 3150
$Comp
L Transistor_FET:BSS138 Q1
U 1 1 5C9137B2
P 7800 3950
F 0 "Q1" H 8005 3996 50  0000 L CNN
F 1 "BSS138" H 8005 3905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8000 3875 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 7800 3950 50  0001 L CNN
	1    7800 3950
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BSS138 Q2
U 1 1 5C98AA01
P 7800 4400
F 0 "Q2" H 8005 4446 50  0000 L CNN
F 1 "BSS138" H 8005 4355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8000 4325 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 7800 4400 50  0001 L CNN
	1    7800 4400
	1    0    0    1   
$EndComp
Text GLabel 6750 4100 2    50   BiDi ~ 0
DTR
Text GLabel 6750 4200 2    50   BiDi ~ 0
RTS
Text GLabel 7500 3950 0    50   BiDi ~ 0
DTR
Text GLabel 7500 4400 0    50   BiDi ~ 0
RTS
Wire Wire Line
	7550 4200 7900 4200
Wire Wire Line
	7550 3950 7500 3950
Wire Wire Line
	7600 3950 7550 3950
Connection ~ 7550 3950
Wire Wire Line
	7550 3950 7550 4200
Wire Wire Line
	7500 4400 7600 4400
Wire Wire Line
	7600 4400 7600 4150
Wire Wire Line
	7600 4150 7900 4150
Connection ~ 7600 4400
Text HLabel 7900 4600 3    50   Output ~ 0
IO0
Text HLabel 7900 3750 1    50   Output ~ 0
EN
Text HLabel 6850 3400 2    50   Output ~ 0
RX
Text HLabel 6850 3500 2    50   Input ~ 0
TX
Wire Wire Line
	5950 4000 5800 4000
Wire Wire Line
	5950 4200 5800 4200
Wire Wire Line
	5800 4200 5800 4300
Wire Wire Line
	5800 4000 5800 3900
$Comp
L power:GND #PWR061
U 1 1 5C908D2A
P 5150 4100
F 0 "#PWR061" H 5150 3850 50  0001 C CNN
F 1 "GND" H 5155 3927 50  0000 C CNN
F 2 "" H 5150 4100 50  0001 C CNN
F 3 "" H 5150 4100 50  0001 C CNN
	1    5150 4100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR062
U 1 1 5C908CA2
P 5550 4100
F 0 "#PWR062" H 5550 3850 50  0001 C CNN
F 1 "GND" H 5555 3927 50  0000 C CNN
F 2 "" H 5550 4100 50  0001 C CNN
F 3 "" H 5550 4100 50  0001 C CNN
	1    5550 4100
	0    -1   -1   0   
$EndComp
$Comp
L Device:Crystal_GND24 Y1
U 1 1 5C575BDD
P 5350 4100
F 0 "Y1" V 5626 4297 50  0000 C CNN
F 1 "12MHz" V 5547 4297 50  0000 C CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 5350 4100 50  0001 C CNN
F 3 "~" H 5350 4100 50  0001 C CNN
	1    5350 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5350 3900 5350 3950
Wire Wire Line
	5800 3900 5350 3900
Connection ~ 5350 3900
Wire Wire Line
	5350 3850 5350 3900
Text GLabel 5350 3850 1    50   UnSpc ~ 0
O1
Wire Wire Line
	5350 4300 5350 4350
Wire Wire Line
	5800 4300 5350 4300
Connection ~ 5350 4300
Wire Wire Line
	5350 4250 5350 4300
Text GLabel 5350 4350 3    50   UnSpc ~ 0
O2
Text GLabel 5950 4550 1    50   UnSpc ~ 0
O2
Text GLabel 5550 4550 1    50   UnSpc ~ 0
O1
$Comp
L power:GND #PWR064
U 1 1 5C67ADA4
P 5550 4750
F 0 "#PWR064" H 5550 4500 50  0001 C CNN
F 1 "GND" H 5555 4577 50  0000 C CNN
F 2 "" H 5550 4750 50  0001 C CNN
F 3 "" H 5550 4750 50  0001 C CNN
	1    5550 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR065
U 1 1 5C67AD2C
P 5950 4750
F 0 "#PWR065" H 5950 4500 50  0001 C CNN
F 1 "GND" H 5955 4577 50  0000 C CNN
F 2 "" H 5950 4750 50  0001 C CNN
F 3 "" H 5950 4750 50  0001 C CNN
	1    5950 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C45
U 1 1 5C5B35D8
P 5550 4650
F 0 "C45" H 5642 4696 50  0000 L CNN
F 1 "22pF" H 5642 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5550 4650 50  0001 C CNN
F 3 "~" H 5550 4650 50  0001 C CNN
	1    5550 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C46
U 1 1 5C5B3556
P 5950 4650
F 0 "C46" H 6042 4696 50  0000 L CNN
F 1 "22pF" H 6042 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5950 4650 50  0001 C CNN
F 3 "~" H 5950 4650 50  0001 C CNN
	1    5950 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR052
U 1 1 5C8F971C
P 5000 3050
F 0 "#PWR052" H 5000 2900 50  0001 C CNN
F 1 "+3.3V" H 5015 3223 50  0000 C CNN
F 2 "" H 5000 3050 50  0001 C CNN
F 3 "" H 5000 3050 50  0001 C CNN
	1    5000 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR057
U 1 1 5C4F665E
P 5000 3250
F 0 "#PWR057" H 5000 3000 50  0001 C CNN
F 1 "GND" H 5005 3077 50  0000 C CNN
F 2 "" H 5000 3250 50  0001 C CNN
F 3 "" H 5000 3250 50  0001 C CNN
	1    5000 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP_Small C?
U 1 1 5DF9E1BC
P 5000 3150
AR Path="/5DDC70BE/5DF9E1BC" Ref="C?"  Part="1" 
AR Path="/5E10B1D0/5DF9E1BC" Ref="C42"  Part="1" 
F 0 "C42" H 5088 3196 50  0000 L CNN
F 1 "4.7uF" H 5088 3105 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3528-15_AVX-H" H 5000 3150 50  0001 C CNN
F 3 "~" H 5000 3150 50  0001 C CNN
	1    5000 3150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5E21DED0
P 5250 5950
F 0 "H1" H 5350 5996 50  0000 L CNN
F 1 "MH" H 5350 5905 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 5250 5950 50  0001 C CNN
F 3 "~" H 5250 5950 50  0001 C CNN
	1    5250 5950
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5E21EB13
P 5250 6150
F 0 "H2" H 5350 6196 50  0000 L CNN
F 1 "MH" H 5350 6105 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 5250 6150 50  0001 C CNN
F 3 "~" H 5250 6150 50  0001 C CNN
	1    5250 6150
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5E21F183
P 5250 6350
F 0 "H3" H 5350 6396 50  0000 L CNN
F 1 "MH" H 5350 6305 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 5250 6350 50  0001 C CNN
F 3 "~" H 5250 6350 50  0001 C CNN
	1    5250 6350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5E21F7BB
P 5250 6550
F 0 "H4" H 5350 6596 50  0000 L CNN
F 1 "MH" H 5350 6505 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_Pad_Via" H 5250 6550 50  0001 C CNN
F 3 "~" H 5250 6550 50  0001 C CNN
	1    5250 6550
	1    0    0    -1  
$EndComp
Connection ~ 3250 4100
Wire Wire Line
	3300 4100 3250 4100
Wire Wire Line
	3300 4050 3300 4100
Wire Wire Line
	3200 4100 3250 4100
Wire Wire Line
	3200 4050 3200 4100
Wire Wire Line
	4000 3400 4000 3450
$Comp
L Connector:USB_B_Mini J4
U 1 1 5C4CB04D
P 3300 3650
F 0 "J4" H 3355 4117 50  0000 C CNN
F 1 "USB_B_Mini" H 3355 4026 50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 3450 3600 50  0001 C CNN
F 3 "~" H 3450 3600 50  0001 C CNN
	1    3300 3650
	1    0    0    -1  
$EndComp
NoConn ~ 3600 3850
Text GLabel 4150 3750 2    50   Output ~ 0
D-
Text GLabel 4150 3650 2    50   Output ~ 0
D+
$Comp
L power:GND #PWR060
U 1 1 5C6E3001
P 3250 4100
F 0 "#PWR060" H 3250 3850 50  0001 C CNN
F 1 "GND" H 3255 3927 50  0000 C CNN
F 2 "" H 3250 4100 50  0001 C CNN
F 3 "" H 3250 4100 50  0001 C CNN
	1    3250 4100
	1    0    0    -1  
$EndComp
$Comp
L ESDA6V8AV5:ESDA6V8AV5 U11
U 1 1 5E34ED88
P 3650 3950
F 0 "U11" H 4230 3871 50  0000 L CNN
F 1 "ESDA6V8AV5" H 4230 3780 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-553" H 3650 4300 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Will-Semicon-ESDA6V8AV5_C268741.pdf" H 3650 4300 50  0001 C CNN
	1    3650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 3750 3700 3850
Wire Wire Line
	3600 3750 3700 3750
Wire Wire Line
	3800 3650 3800 3850
Wire Wire Line
	3600 3650 3800 3650
Wire Wire Line
	4000 3450 4000 3850
Connection ~ 4000 3450
Wire Wire Line
	3600 3450 4000 3450
Wire Wire Line
	4150 3650 3800 3650
Connection ~ 3800 3650
Wire Wire Line
	3700 3750 4150 3750
Connection ~ 3700 3750
NoConn ~ 4100 3850
$Comp
L power:GND #PWR066
U 1 1 5E358AE9
P 3900 4300
F 0 "#PWR066" H 3900 4050 50  0001 C CNN
F 1 "GND" H 3905 4127 50  0000 C CNN
F 2 "" H 3900 4300 50  0001 C CNN
F 3 "" H 3900 4300 50  0001 C CNN
	1    3900 4300
	1    0    0    -1  
$EndComp
$Comp
L power:VBUS #PWR?
U 1 1 5E89D26A
P 4000 3400
F 0 "#PWR?" H 4000 3250 50  0001 C CNN
F 1 "VBUS" H 4015 3573 50  0000 C CNN
F 2 "" H 4000 3400 50  0001 C CNN
F 3 "" H 4000 3400 50  0001 C CNN
	1    4000 3400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
