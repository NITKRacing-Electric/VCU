# VCU
- CAN - test codes for sending decoding can messages between two arduinos

- APPS_V1 - code for checking apps implausibility and brake input (shutting motor down not included)

- Current Pedal travel = 1.5V 
-- Test performed from 10.81V to 9.31V 

## DASHBOARD (Data types)
1: (Accelerator) -integer RF\
2: (Brake) -integer RF\
3: (Speed) -integer RF might not be added\ 
4: (SOC) -float RF\
5: (Modes) - Integer {1:Acceleration, 2:Endurance, 3:Test}\
6: (Temperature of the hottest cell) - float\
7: [ FAULTS ] //array of faults

## Metadata for data - serial port
### DASHBOARD
1: (Accelerator)\
2: (Brake)\
3: (Speed)\
4: (SOC) - HV \
5: (SOC 2) - LV
6: Mode - 1acceleration, 2 endurance or 3 test\
7: (Temperature of the hottest cell)\
8: [ FAULTS ] //array of faults 4 FAULTS 

### DAQ - RF TRANSMISSION - CAN ADDRESSES AND meta-data
a: 2-speed sensor value -> 2025 4-wheel speed sensor values separated by spaces\
b: Accelerometer and brake\
c: LV Voltage and current separated by space\
d: HV Cell Broadcast\
TEMP MODULE e: HV Temperature "String" with metadata of cell number(mux) and data temperature separated by spaces\
#### f1: LV Temperatures1 "String" with metadata of cell number(mux) and data temperature separated by spaces 8
#### f2: LV Temperatures2 "String" with metadata of cell number(mux) and data temperature separated by spaces 2+1
g: Fault codes separated by spaces or passed as an array\
h: BMS data "String" with metadata(if required) and data\
i: Motor Controller split current separated by space\
j: IMD status code\
k1:BMS status 1 0x6B0(Pack current,Voltage,SOC,relay state,Checksum)\
k2:BMS status 2 0x6B1(Pack DCL,CCL,Average Current,Checksum)\
k3:BMS status 3 0x6B2(DTC flag#1,DTC flag#2,High voltage Cell ID,Pack Health,Low Voltage Cell ID,Checksum)\
HV SOC
LV SOC
#### l: HV Pack Voltage
#### m: HV Pack Current

#### n: LV Pack Voltage
#### o: LV Pack Current

Added script file start_chromium.sh in root
dont delete - https://smarthomepursuits.com/open-website-on-startup-with-raspberry-pi-os/
