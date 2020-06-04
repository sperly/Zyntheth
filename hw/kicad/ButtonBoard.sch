EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L Device:Rotary_Encoder SW?
U 1 1 5F0991D8
P 7900 2850
AR Path="/5F0991D8" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0991D8" Ref="SW?"  Part="1" 
F 0 "SW?" H 8130 2896 50  0000 L CNN
F 1 "Rotary_Encoder" H 8130 2805 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 7750 3010 50  0001 C CNN
F 3 "~" H 7900 3110 50  0001 C CNN
	1    7900 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0991DE
P 6800 2500
AR Path="/5F0991DE" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0991DE" Ref="SW?"  Part="1" 
F 0 "SW?" H 6750 2750 50  0000 L CNN
F 1 "Rotary_Encoder" H 7030 2455 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 6650 2660 50  0001 C CNN
F 3 "~" H 6800 2760 50  0001 C CNN
	1    6800 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0991E4
P 7900 3400
AR Path="/5F0991E4" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0991E4" Ref="SW?"  Part="1" 
F 0 "SW?" H 8130 3446 50  0000 L CNN
F 1 "Rotary_Encoder" H 8130 3355 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 7750 3560 50  0001 C CNN
F 3 "~" H 7900 3660 50  0001 C CNN
	1    7900 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2400 5950 2700
Wire Wire Line
	5950 2700 5900 2700
Wire Wire Line
	6500 2600 6100 2600
Wire Wire Line
	6000 2600 6000 2800
Wire Wire Line
	6000 2800 5900 2800
Wire Wire Line
	6100 3000 5900 3000
Wire Wire Line
	7600 2950 7250 2950
Wire Wire Line
	7050 2950 7050 2800
Wire Wire Line
	6100 2800 6100 3000
$Comp
L Interface_Expansion:MCP23017_ML U?
U 1 1 5F0991F3
P 5200 3500
AR Path="/5F0991F3" Ref="U?"  Part="1" 
AR Path="/5F07C5F3/5F0991F3" Ref="U?"  Part="1" 
F 0 "U?" H 5200 4781 50  0000 C CNN
F 1 "MCP23017_ML" H 5200 4690 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_6x6mm_P0.65mm_EP4.25x4.25mm" H 5400 2500 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001952C.pdf" H 5400 2400 50  0001 L CNN
	1    5200 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3100 6150 3100
Wire Wire Line
	6150 3100 6150 2950
Wire Wire Line
	6150 2950 6250 2950
Wire Wire Line
	6200 3200 6200 3150
Wire Wire Line
	6200 3150 6350 3150
Wire Wire Line
	5900 3200 6200 3200
Wire Wire Line
	5900 3300 7400 3300
Wire Wire Line
	7600 3500 7500 3500
Wire Wire Line
	7050 3500 7050 3400
Wire Wire Line
	5900 3400 7050 3400
$Comp
L Device:R R?
U 1 1 5F099203
P 6350 2200
AR Path="/5F099203" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099203" Ref="R?"  Part="1" 
F 0 "R?" H 6420 2246 50  0000 L CNN
F 1 "R" H 6420 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6280 2200 50  0001 C CNN
F 3 "~" H 6350 2200 50  0001 C CNN
	1    6350 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099209
P 6250 2200
AR Path="/5F099209" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099209" Ref="R?"  Part="1" 
F 0 "R?" H 6320 2246 50  0000 L CNN
F 1 "R" H 6320 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6180 2200 50  0001 C CNN
F 3 "~" H 6250 2200 50  0001 C CNN
	1    6250 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F09920F
P 6450 4750
AR Path="/5F09920F" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F09920F" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6450 4500 50  0001 C CNN
F 1 "GND" H 6455 4577 50  0000 C CNN
F 2 "" H 6450 4750 50  0001 C CNN
F 3 "" H 6450 4750 50  0001 C CNN
	1    6450 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3050 6450 3050
Wire Wire Line
	6450 3050 6450 3650
Wire Wire Line
	6500 2500 6450 2500
Wire Wire Line
	6450 2500 6450 3050
Connection ~ 6450 3050
$Comp
L Device:R R?
U 1 1 5F09921A
P 6100 2200
AR Path="/5F09921A" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09921A" Ref="R?"  Part="1" 
F 0 "R?" H 6170 2246 50  0000 L CNN
F 1 "R" H 6170 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6030 2200 50  0001 C CNN
F 3 "~" H 6100 2200 50  0001 C CNN
	1    6100 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099220
P 6000 2200
AR Path="/5F099220" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099220" Ref="R?"  Part="1" 
F 0 "R?" H 6070 2246 50  0000 L CNN
F 1 "R" H 6070 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5930 2200 50  0001 C CNN
F 3 "~" H 6000 2200 50  0001 C CNN
	1    6000 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2350 6000 2400
Connection ~ 6000 2400
Wire Wire Line
	6000 2400 5950 2400
Wire Wire Line
	6100 2350 6100 2600
Connection ~ 6100 2600
Wire Wire Line
	6100 2600 6000 2600
Wire Wire Line
	7600 2750 7150 2750
Wire Wire Line
	6500 2400 6000 2400
$Comp
L Device:R R?
U 1 1 5F09922E
P 7500 2200
AR Path="/5F09922E" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09922E" Ref="R?"  Part="1" 
F 0 "R?" H 7570 2246 50  0000 L CNN
F 1 "R" H 7570 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7430 2200 50  0001 C CNN
F 3 "~" H 7500 2200 50  0001 C CNN
	1    7500 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099234
P 7400 2200
AR Path="/5F099234" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099234" Ref="R?"  Part="1" 
F 0 "R?" H 7470 2246 50  0000 L CNN
F 1 "R" H 7470 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7330 2200 50  0001 C CNN
F 3 "~" H 7400 2200 50  0001 C CNN
	1    7400 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F09923A
P 7250 2200
AR Path="/5F09923A" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09923A" Ref="R?"  Part="1" 
F 0 "R?" H 7320 2246 50  0000 L CNN
F 1 "R" H 7320 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7180 2200 50  0001 C CNN
F 3 "~" H 7250 2200 50  0001 C CNN
	1    7250 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099240
P 7150 2200
AR Path="/5F099240" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099240" Ref="R?"  Part="1" 
F 0 "R?" H 7220 2246 50  0000 L CNN
F 1 "R" H 7220 2155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7080 2200 50  0001 C CNN
F 3 "~" H 7150 2200 50  0001 C CNN
	1    7150 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 2350 7150 2750
Connection ~ 7150 2750
Wire Wire Line
	7250 2350 7250 2950
Connection ~ 7250 2950
Wire Wire Line
	7250 2950 7050 2950
Wire Wire Line
	7400 2350 7400 3300
Connection ~ 7400 3300
Wire Wire Line
	7400 3300 7600 3300
Wire Wire Line
	7500 2350 7500 3500
Connection ~ 7500 3500
Wire Wire Line
	7500 3500 7050 3500
Wire Wire Line
	6000 2050 6000 2000
Wire Wire Line
	6000 2000 6100 2000
Wire Wire Line
	7500 2000 7500 2050
Wire Wire Line
	7400 2050 7400 2000
Connection ~ 7400 2000
Wire Wire Line
	7400 2000 7500 2000
Wire Wire Line
	7250 2050 7250 2000
Connection ~ 7250 2000
Wire Wire Line
	7250 2000 7400 2000
Wire Wire Line
	7150 2050 7150 2000
Connection ~ 7150 2000
Wire Wire Line
	7150 2000 7250 2000
Wire Wire Line
	6350 2050 6350 2000
Connection ~ 6350 2000
Wire Wire Line
	6350 2000 7150 2000
Wire Wire Line
	6250 2050 6250 2000
Connection ~ 6250 2000
Wire Wire Line
	6250 2000 6350 2000
Wire Wire Line
	6100 2050 6100 2000
Connection ~ 6100 2000
Wire Wire Line
	6100 2000 6250 2000
$Comp
L power:GND #PWR?
U 1 1 5F099266
P 7550 4800
AR Path="/5F099266" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F099266" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 7550 4550 50  0001 C CNN
F 1 "GND" H 7555 4627 50  0000 C CNN
F 2 "" H 7550 4800 50  0001 C CNN
F 3 "" H 7550 4800 50  0001 C CNN
	1    7550 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2850 7550 2850
Wire Wire Line
	7550 2850 7550 3400
Wire Wire Line
	7600 3400 7550 3400
Connection ~ 7550 3400
Wire Wire Line
	7550 3400 7550 4000
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F099271
P 6800 3050
AR Path="/5F099271" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F099271" Ref="SW?"  Part="1" 
F 0 "SW?" H 7050 2900 50  0000 L CNN
F 1 "Rotary_Encoder" H 7030 3005 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 6650 3210 50  0001 C CNN
F 3 "~" H 6800 3310 50  0001 C CNN
	1    6800 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F099277
P 6000 1950
AR Path="/5F099277" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F099277" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6000 1800 50  0001 C CNN
F 1 "+3V3" H 6015 2123 50  0000 C CNN
F 2 "" H 6000 1950 50  0001 C CNN
F 3 "" H 6000 1950 50  0001 C CNN
	1    6000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1950 6000 2000
Connection ~ 6000 2000
$Comp
L Device:R R?
U 1 1 5F09927F
P 4400 2350
AR Path="/5F09927F" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09927F" Ref="R?"  Part="1" 
F 0 "R?" H 4470 2396 50  0000 L CNN
F 1 "R" H 4470 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4330 2350 50  0001 C CNN
F 3 "~" H 4400 2350 50  0001 C CNN
	1    4400 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099285
P 4300 2350
AR Path="/5F099285" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099285" Ref="R?"  Part="1" 
F 0 "R?" H 4370 2396 50  0000 L CNN
F 1 "R" H 4370 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4230 2350 50  0001 C CNN
F 3 "~" H 4300 2350 50  0001 C CNN
	1    4300 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F09928B
P 4450 4550
AR Path="/5F09928B" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09928B" Ref="R?"  Part="1" 
F 0 "R?" H 4520 4596 50  0000 L CNN
F 1 "R" H 4520 4505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4380 4550 50  0001 C CNN
F 3 "~" H 4450 4550 50  0001 C CNN
	1    4450 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099291
P 4350 4550
AR Path="/5F099291" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099291" Ref="R?"  Part="1" 
F 0 "R?" H 4420 4596 50  0000 L CNN
F 1 "R" H 4420 4505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4280 4550 50  0001 C CNN
F 3 "~" H 4350 4550 50  0001 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099297
P 4250 4550
AR Path="/5F099297" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099297" Ref="R?"  Part="1" 
F 0 "R?" H 4320 4596 50  0000 L CNN
F 1 "R" H 4320 4505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4180 4550 50  0001 C CNN
F 3 "~" H 4250 4550 50  0001 C CNN
	1    4250 4550
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F09929D
P 5200 2350
AR Path="/5F09929D" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F09929D" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5200 2200 50  0001 C CNN
F 1 "+3V3" H 5215 2523 50  0000 C CNN
F 2 "" H 5200 2350 50  0001 C CNN
F 3 "" H 5200 2350 50  0001 C CNN
	1    5200 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2350 5200 2400
$Comp
L power:GND #PWR?
U 1 1 5F0992A4
P 5200 4650
AR Path="/5F0992A4" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F0992A4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5200 4400 50  0001 C CNN
F 1 "GND" H 5205 4477 50  0000 C CNN
F 2 "" H 5200 4650 50  0001 C CNN
F 3 "" H 5200 4650 50  0001 C CNN
	1    5200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4600 5200 4650
$Comp
L power:GND #PWR?
U 1 1 5F0992AB
P 4450 4800
AR Path="/5F0992AB" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F0992AB" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4450 4550 50  0001 C CNN
F 1 "GND" H 4455 4627 50  0000 C CNN
F 2 "" H 4450 4800 50  0001 C CNN
F 3 "" H 4450 4800 50  0001 C CNN
	1    4450 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4700 4450 4750
Wire Wire Line
	4350 4700 4350 4750
Wire Wire Line
	4350 4750 4450 4750
Connection ~ 4450 4750
Wire Wire Line
	4450 4750 4450 4800
Wire Wire Line
	4250 4700 4250 4750
Wire Wire Line
	4250 4750 4350 4750
Connection ~ 4350 4750
Wire Wire Line
	4500 4300 4450 4300
Wire Wire Line
	4450 4300 4450 4400
Wire Wire Line
	4500 4200 4350 4200
Wire Wire Line
	4350 4200 4350 4400
Wire Wire Line
	4500 4100 4250 4100
Wire Wire Line
	4250 4100 4250 4400
$Comp
L Device:R R?
U 1 1 5F0992BF
P 4050 2350
AR Path="/5F0992BF" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F0992BF" Ref="R?"  Part="1" 
F 0 "R?" H 4120 2396 50  0000 L CNN
F 1 "R" H 4120 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3980 2350 50  0001 C CNN
F 3 "~" H 4050 2350 50  0001 C CNN
	1    4050 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3600 4500 3600
Wire Wire Line
	4050 2500 4050 3600
Wire Wire Line
	4500 2700 4300 2700
Wire Wire Line
	4500 2800 4400 2800
Wire Wire Line
	4400 2500 4400 2800
Wire Wire Line
	4300 2500 4300 2700
$Comp
L power:+3V3 #PWR?
U 1 1 5F0992CB
P 4050 2000
AR Path="/5F0992CB" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F0992CB" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4050 1850 50  0001 C CNN
F 1 "+3V3" H 4065 2173 50  0000 C CNN
F 2 "" H 4050 2000 50  0001 C CNN
F 3 "" H 4050 2000 50  0001 C CNN
	1    4050 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2000 4050 2150
Wire Wire Line
	4050 2150 4300 2150
Wire Wire Line
	4400 2150 4400 2200
Connection ~ 4050 2150
Wire Wire Line
	4050 2150 4050 2200
Wire Wire Line
	4300 2200 4300 2150
Connection ~ 4300 2150
Wire Wire Line
	4300 2150 4400 2150
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0992D9
P 6800 3650
AR Path="/5F0992D9" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0992D9" Ref="SW?"  Part="1" 
F 0 "SW?" H 7050 3500 50  0000 L CNN
F 1 "Rotary_Encoder" H 7030 3605 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 6650 3810 50  0001 C CNN
F 3 "~" H 6800 3910 50  0001 C CNN
	1    6800 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0992DF
P 6800 4200
AR Path="/5F0992DF" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0992DF" Ref="SW?"  Part="1" 
F 0 "SW?" H 7050 4050 50  0000 L CNN
F 1 "Rotary_Encoder" H 7030 4155 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 6650 4360 50  0001 C CNN
F 3 "~" H 6800 4460 50  0001 C CNN
	1    6800 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3550 6050 3550
Wire Wire Line
	5950 3550 5950 3600
Wire Wire Line
	5950 3600 5900 3600
Wire Wire Line
	6500 3650 6450 3650
Connection ~ 6450 3650
Wire Wire Line
	6450 3650 6450 4200
Wire Wire Line
	6500 3750 6400 3750
Wire Wire Line
	6400 3750 6400 3700
Wire Wire Line
	6400 3700 5950 3700
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0992EE
P 7900 4000
AR Path="/5F0992EE" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0992EE" Ref="SW?"  Part="1" 
F 0 "SW?" H 8130 4046 50  0000 L CNN
F 1 "Rotary_Encoder" H 8130 3955 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 7750 4160 50  0001 C CNN
F 3 "~" H 7900 4260 50  0001 C CNN
	1    7900 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder SW?
U 1 1 5F0992F4
P 7900 4550
AR Path="/5F0992F4" Ref="SW?"  Part="1" 
AR Path="/5F07C5F3/5F0992F4" Ref="SW?"  Part="1" 
F 0 "SW?" H 8130 4596 50  0000 L CNN
F 1 "Rotary_Encoder" H 8130 4505 50  0000 L CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC12E_Vertical_H20mm" H 7750 4710 50  0001 C CNN
F 3 "~" H 7900 4810 50  0001 C CNN
	1    7900 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3900 7350 3900
Wire Wire Line
	6350 3900 6350 3800
Wire Wire Line
	6350 3800 5900 3800
Wire Wire Line
	7450 4100 7450 3950
Wire Wire Line
	7450 3950 7250 3950
Wire Wire Line
	6300 3950 6300 3900
Wire Wire Line
	6300 3900 5900 3900
Wire Wire Line
	7450 4100 7600 4100
Wire Wire Line
	6500 4100 6300 4100
Wire Wire Line
	6250 4100 6250 4000
Wire Wire Line
	6250 4000 5900 4000
Wire Wire Line
	6500 4200 6450 4200
Connection ~ 6450 4200
Wire Wire Line
	6450 4200 6450 4750
Wire Wire Line
	6500 4300 6200 4300
Wire Wire Line
	6200 4300 6200 4100
Wire Wire Line
	6200 4100 5900 4100
Wire Wire Line
	6150 4450 6150 4200
Wire Wire Line
	6150 4200 5900 4200
Wire Wire Line
	6150 4450 7100 4450
Wire Wire Line
	7600 4650 7450 4650
Wire Wire Line
	7450 4650 7450 4500
Wire Wire Line
	7450 4500 7000 4500
Wire Wire Line
	6100 4500 6100 4300
Wire Wire Line
	6100 4300 5900 4300
$Comp
L Device:R R?
U 1 1 5F099313
P 5950 4700
AR Path="/5F099313" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099313" Ref="R?"  Part="1" 
F 0 "R?" H 6020 4746 50  0000 L CNN
F 1 "R" H 6020 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5880 4700 50  0001 C CNN
F 3 "~" H 5950 4700 50  0001 C CNN
	1    5950 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 4000 7550 4000
Connection ~ 7550 4000
Wire Wire Line
	7550 4000 7550 4550
Wire Wire Line
	7600 4550 7550 4550
Connection ~ 7550 4550
Wire Wire Line
	7550 4550 7550 4800
$Comp
L Device:R R?
U 1 1 5F09931F
P 7350 4750
AR Path="/5F09931F" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09931F" Ref="R?"  Part="1" 
F 0 "R?" H 7420 4796 50  0000 L CNN
F 1 "R" H 7420 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7280 4750 50  0001 C CNN
F 3 "~" H 7350 4750 50  0001 C CNN
	1    7350 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099325
P 7250 4750
AR Path="/5F099325" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099325" Ref="R?"  Part="1" 
F 0 "R?" H 7320 4796 50  0000 L CNN
F 1 "R" H 7320 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7180 4750 50  0001 C CNN
F 3 "~" H 7250 4750 50  0001 C CNN
	1    7250 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F09932B
P 7100 4750
AR Path="/5F09932B" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09932B" Ref="R?"  Part="1" 
F 0 "R?" H 7170 4796 50  0000 L CNN
F 1 "R" H 7170 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 7030 4750 50  0001 C CNN
F 3 "~" H 7100 4750 50  0001 C CNN
	1    7100 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099331
P 7000 4750
AR Path="/5F099331" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099331" Ref="R?"  Part="1" 
F 0 "R?" H 7070 4796 50  0000 L CNN
F 1 "R" H 7070 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6930 4750 50  0001 C CNN
F 3 "~" H 7000 4750 50  0001 C CNN
	1    7000 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4600 7350 3900
Connection ~ 7350 3900
Wire Wire Line
	7350 3900 6350 3900
Wire Wire Line
	7250 4600 7250 3950
Connection ~ 7250 3950
Wire Wire Line
	7250 3950 6300 3950
Wire Wire Line
	7100 4600 7100 4450
Connection ~ 7100 4450
Wire Wire Line
	7100 4450 7600 4450
Wire Wire Line
	7000 4600 7000 4500
Connection ~ 7000 4500
Wire Wire Line
	7000 4500 6100 4500
$Comp
L Device:R R?
U 1 1 5F099343
P 6050 4700
AR Path="/5F099343" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099343" Ref="R?"  Part="1" 
F 0 "R?" H 6120 4746 50  0000 L CNN
F 1 "R" H 6120 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5980 4700 50  0001 C CNN
F 3 "~" H 6050 4700 50  0001 C CNN
	1    6050 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F099349
P 6200 4700
AR Path="/5F099349" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F099349" Ref="R?"  Part="1" 
F 0 "R?" H 6270 4746 50  0000 L CNN
F 1 "R" H 6270 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6130 4700 50  0001 C CNN
F 3 "~" H 6200 4700 50  0001 C CNN
	1    6200 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F09934F
P 6300 4700
AR Path="/5F09934F" Ref="R?"  Part="1" 
AR Path="/5F07C5F3/5F09934F" Ref="R?"  Part="1" 
F 0 "R?" H 6370 4746 50  0000 L CNN
F 1 "R" H 6370 4655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6230 4700 50  0001 C CNN
F 3 "~" H 6300 4700 50  0001 C CNN
	1    6300 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 4550 6300 4100
Connection ~ 6300 4100
Wire Wire Line
	6300 4100 6250 4100
Wire Wire Line
	6200 4550 6200 4300
Connection ~ 6200 4300
Wire Wire Line
	6050 4550 6050 3550
Connection ~ 6050 3550
Wire Wire Line
	6050 3550 5950 3550
Connection ~ 5950 3700
Wire Wire Line
	5950 3700 5900 3700
Wire Wire Line
	5950 3700 5950 4550
Wire Wire Line
	6300 4850 6300 4900
Wire Wire Line
	6300 4900 6200 4900
Wire Wire Line
	5750 4900 5750 4750
Wire Wire Line
	6200 4850 6200 4900
Connection ~ 6200 4900
Wire Wire Line
	6200 4900 6050 4900
Wire Wire Line
	6050 4850 6050 4900
Connection ~ 6050 4900
Wire Wire Line
	6050 4900 5950 4900
Wire Wire Line
	5950 4850 5950 4900
Connection ~ 5950 4900
Wire Wire Line
	5950 4900 5750 4900
$Comp
L power:+3V3 #PWR?
U 1 1 5F09936C
P 5750 4750
AR Path="/5F09936C" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F09936C" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5750 4600 50  0001 C CNN
F 1 "+3V3" H 5765 4923 50  0000 C CNN
F 2 "" H 5750 4750 50  0001 C CNN
F 3 "" H 5750 4750 50  0001 C CNN
	1    5750 4750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F099372
P 6850 4750
AR Path="/5F099372" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F099372" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 6850 4600 50  0001 C CNN
F 1 "+3V3" H 6865 4923 50  0000 C CNN
F 2 "" H 6850 4750 50  0001 C CNN
F 3 "" H 6850 4750 50  0001 C CNN
	1    6850 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4900 7350 4950
Wire Wire Line
	7350 4950 7250 4950
Wire Wire Line
	6850 4950 6850 4750
Wire Wire Line
	7250 4900 7250 4950
Connection ~ 7250 4950
Wire Wire Line
	7250 4950 7100 4950
Wire Wire Line
	7100 4900 7100 4950
Connection ~ 7100 4950
Wire Wire Line
	7100 4950 7000 4950
Wire Wire Line
	7000 4900 7000 4950
Connection ~ 7000 4950
Wire Wire Line
	7000 4950 6850 4950
Wire Wire Line
	6050 2750 7150 2750
Wire Wire Line
	6100 2800 7050 2800
Wire Wire Line
	6050 2750 6050 2900
Wire Wire Line
	6050 2900 5900 2900
Wire Wire Line
	6250 2350 6250 2950
Connection ~ 6250 2950
Wire Wire Line
	6250 2950 6500 2950
Wire Wire Line
	6350 2350 6350 3150
Connection ~ 6350 3150
Wire Wire Line
	6350 3150 6500 3150
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5F09938E
P 3100 2700
AR Path="/5F09938E" Ref="J?"  Part="1" 
AR Path="/5F07C5F3/5F09938E" Ref="J?"  Part="1" 
F 0 "J?" H 2992 2985 50  0000 C CNN
F 1 "Conn_01x04_Female" H 2992 2894 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 3100 2700 50  0001 C CNN
F 3 "~" H 3100 2700 50  0001 C CNN
	1    3100 2700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 2700 3300 2700
Connection ~ 4300 2700
Wire Wire Line
	4400 2800 3300 2800
Connection ~ 4400 2800
$Comp
L power:+3V3 #PWR?
U 1 1 5F099398
P 3400 2400
AR Path="/5F099398" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F099398" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3400 2250 50  0001 C CNN
F 1 "+3V3" H 3415 2573 50  0000 C CNN
F 2 "" H 3400 2400 50  0001 C CNN
F 3 "" H 3400 2400 50  0001 C CNN
	1    3400 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F09939E
P 3400 3000
AR Path="/5F09939E" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F09939E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3400 2750 50  0001 C CNN
F 1 "GND" H 3405 2827 50  0000 C CNN
F 2 "" H 3400 3000 50  0001 C CNN
F 3 "" H 3400 3000 50  0001 C CNN
	1    3400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4600 5100 4650
Wire Wire Line
	5100 4650 5200 4650
Connection ~ 5200 4650
Wire Wire Line
	3300 2900 3400 2900
Wire Wire Line
	3400 2900 3400 3000
Wire Wire Line
	3400 2600 3300 2600
$Comp
L Device:CP C?
U 1 1 5F0993AA
P 3150 3950
AR Path="/5F0993AA" Ref="C?"  Part="1" 
AR Path="/5F07C5F3/5F0993AA" Ref="C?"  Part="1" 
F 0 "C?" H 3268 3996 50  0000 L CNN
F 1 "0.1µF" H 3268 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3188 3800 50  0001 C CNN
F 3 "~" H 3150 3950 50  0001 C CNN
	1    3150 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F0993B0
P 3500 3950
AR Path="/5F0993B0" Ref="C?"  Part="1" 
AR Path="/5F07C5F3/5F0993B0" Ref="C?"  Part="1" 
F 0 "C?" H 3615 3996 50  0000 L CNN
F 1 "10nF" H 3615 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3538 3800 50  0001 C CNN
F 3 "~" H 3500 3950 50  0001 C CNN
	1    3500 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2400 3400 2600
Wire Wire Line
	3150 3800 3150 3700
Wire Wire Line
	3150 3700 3500 3700
Wire Wire Line
	3500 3700 3500 3800
Wire Wire Line
	3500 4100 3500 4200
Wire Wire Line
	3500 4200 3150 4200
Wire Wire Line
	3150 4200 3150 4100
Wire Wire Line
	3150 4200 3150 4300
Connection ~ 3150 4200
Wire Wire Line
	3150 3700 3150 3600
Connection ~ 3150 3700
$Comp
L power:+3V3 #PWR?
U 1 1 5F0993C1
P 3150 3600
AR Path="/5F0993C1" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F0993C1" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3150 3450 50  0001 C CNN
F 1 "+3V3" H 3165 3773 50  0000 C CNN
F 2 "" H 3150 3600 50  0001 C CNN
F 3 "" H 3150 3600 50  0001 C CNN
	1    3150 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0993C7
P 3150 4300
AR Path="/5F0993C7" Ref="#PWR?"  Part="1" 
AR Path="/5F07C5F3/5F0993C7" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3150 4050 50  0001 C CNN
F 1 "GND" H 3155 4127 50  0000 C CNN
F 2 "" H 3150 4300 50  0001 C CNN
F 3 "" H 3150 4300 50  0001 C CNN
	1    3150 4300
	1    0    0    -1  
$EndComp
$EndSCHEMATC
