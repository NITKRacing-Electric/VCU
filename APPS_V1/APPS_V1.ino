#include<Wire.h>
const int APPS1 = A0;
const int APPS2 = A1;
const int brake = A2;
int val1 = 0;
int val2 = 0;
int var1=0;
int var2=0;
int motorout = 0;
#define ADDR1 0x60
#define ADDR2 0x62


void setup() {
  Serial.begin(9600);
  Serial.println("Vehicle Starting .....");
  TCCR1B=0; 
  TCCR1A=0;
  TCCR1B=bit(CS12); //timer init
}

void loop() {

    val1 = analogRead(APPS1); 
    val2 = analogRead(APPS2);

    if( val1<103 || val1>920 || val2<103 || val2>920){                // 0.5 - 4.5 range check
        Serial.print("sensor failure (outside acceptable range)");
        //DAC1(0);
        //DAC2(0);
    }

    else if(brake>204){                                              // brake check
        Serial.print("Brake pedal is being pressed");
        //DAC1(0);
        //DAC2(0);
    }

    else if(abs(val1-val2) > 103 ){                                  // implausibility check
        TCNT1=0;
        while(TCNT1<=6250) {
            var1 = analogRead(APPS1); 
            var2 = analogRead(APPS2);
            if(abs(val1-val2) < 103 ){
                break;
            }
        }
    }

    if(abs(val1-val2) >103){                                    
        Serial.print(" APPS implausibility failure : ");
        Serial.print(((abs(val1-val2)) / 1024 )*100);
        //DAC1(0);
        //DAC2(0); 
        } 


    else {                                                          // output code

        motorout = (val1+val2)*2;
        DAC1(motorout);
        DAC2(motorout);
        Serial.print("pedal position = ");
        Serial.print(map(motorout, 410, 4069 - 410, 0, 100));
        Serial.print("%");
    }
    delay(25);
}
  
  
void DAC1(int output){                                                // Motor controller 1 output
    Wire.beginTransmission(ADDR1);
    Wire.write(64);                     // cmd to update the DAC
    Wire.write(output >> 4);        // the 8 most significant bits…
    Wire.write((output & 15) << 4); // the 4 least significant bits…
    Wire.endTransmission();
}
  
void DAC2(int output){                                                // Motor controller 2 output
    Wire.beginTransmission(ADDR2);
    Wire.write(64);                     // cmd to update the DAC
    Wire.write(output >> 4);        // the 8 most significant bits…
    Wire.write((output & 15) << 4); // the 4 least significant bits…
    Wire.endTransmission();
}
    
