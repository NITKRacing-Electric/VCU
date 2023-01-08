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
d: HV Voltage and current seperated by space\
e: HV Temperature "String" with meta data of cell number(mux) and data temperature seperated by spaces\
f: LV Temperature "String" with meta data of cell number(mux) and data temperature seperated by spaces\
g: Fault codes seperated by spaces or passed as an array\
h: BMS data "String" with meta data(if required) and data\
i: Motor Controller split current seperated by space
