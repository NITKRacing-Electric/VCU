## RPi - on start-up - https://gist.github.com/rampfox/085bf3ffb9ff51e114bf7afdf3ced71b
## reboot switch - option using button
## Nodered on boot
## Fullscreen dashboard
custom zoom
## Web browser on start

# VCU

- CAN - test codes for sending decoding can messages between two arduinos

- APPS_V1 - code for checking apps implausibility and brake input (shutting motor down not included)

- Current Pedal travel = 1.5V 
-- Test performed from 10.81V to 9.31V 

## DASHBOARD (Data types)
1: (Accelerator) -integer\
2: (Brake) -integer\
3: (Speed) -integer\
4: (SOC) -float\
5: (Modes) - Integer {1:Acceleration, 2:Endurance, 3:Test}\
6: (Temperature of the hottest cell) - float\
7: [ FAULTS ] //array of faults

## Meta data for data - serial port
### DASHBOARD
1: (Accelerator)\
2: (Brake)\
3: (Speed)\
4: (SOC)\
5: Mode - 1acceleration, 2 endurance or 3 test\
6: (Temperature of the hottest cell)\
7: [ FAULTS ] //array of faults  


### DAQ
a: 4 wheel speed sensor values seperated by spaces\
b: Accelerometer\
c: LV Voltage and current seperated by space\
d: HV Cell Broadcast\
TEMP MODULE e: HV Temperature "String" with meta data of cell number(mux) and data temperature seperated by spaces\
#### f1: LV Temperatures1 "String" with meta data of cell number(mux) and data temperature seperated by spaces 8
#### f2: LV Temperatures2 "String" with meta data of cell number(mux) and data temperature seperated by spaces 2+1
g: Fault codes seperated by spaces or passed as an array\
h: BMS data "String" with meta data(if required) and data\
i: Motor Controller split current seperated by space\
j: IMD status code\
k1:BMS status 1 0x6B0(Pack current,Voltage,SOC,relay state,Checksum)\
k2:BMS status 2 0x6B1(Pack DCL,CCL,Average Current,Checksum)\
k3:BMS status 3 0x6B2(DTC flag#1,DTC flag#2,High voltage Cell ID,Pack Health,Low Voltage Cell ID,Checksum)\

#### l:HV Pack Voltage
#### m:HV Pack Current

#### n:LV Pack Voltage
#### o:LV Pack Current
