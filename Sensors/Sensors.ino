#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);


const int X = A0;
const int Y = A1;
const int Z = A2;
const int Relay_out = A3;
const int MEGA_In = A4;
//const int LV_Current_In = A5;
const int NTC1 = A6;
const int NTC2 = A7;

const int RTDS_out = 3;
const int RED2 = 4;
const int RED1 = 5;
const int RL = 6;
const int RR = 7;
const int FL = 8;
const int FR = 9;


// initialize minimum and maximum Raw Ranges for each axis
int RawMin = 0;
int RawMax = 1023;

// Take multiple samples to reduce noise
const int sampleSize = 10;

void setup()
{
    Serial.begin(9600);
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCCR1B |= (1 << CS12) | (1 << CS10);  


  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);
  pinMode(Relay_out, OUTPUT);
  pinMode(MEGA_In, INPUT);
  //pinMode(LV_Current_In, INPUT);
  pinMode(NTC1, INPUT);
  pinMode(NTC2, INPUT);

  pinMode(RTDS_out, OUTPUT);
  pinMode(RED2, INPUT);
  pinMode(RED1, INPUT);
  pinMode(RL, INPUT);
  pinMode(RR, INPUT);
  pinMode(FL, INPUT);
  pinMode(FR, INPUT);


}

void loop()
{ 

   routine();
   Accelaration();

   

    delay(100);
}

void Accelaration ()
{
    // Read raw values
    int xRaw = ReadAxis(X) * (5/3.3);
    int yRaw = ReadAxis(Y) * (5/3.3);
    int zRaw = ReadAxis(Z) * (5/3.3);

    // Convert raw values to 'milli-Gs"
    long xScaled = map(xRaw, RawMin, RawMax, 0, 6000);
    long yScaled = map(yRaw, RawMin, RawMax, 0, 6000);
    long zScaled = map(zRaw, RawMin, RawMax, 0, 6000);

    // re-scale to fractional Gs
    float xAccel = xScaled / 1000.0;
    float yAccel = yScaled / 1000.0;
    float zAccel = zScaled / 1000.0;
}

// Take samples and return the average
int ReadAxis(int axisPin)
{
    long reading = 0;
    analogRead(axisPin);
    delay(1);
    for (int i = 0; i < sampleSize; i++)
    {
        reading += analogRead(axisPin);
    }
    return reading / sampleSize;
}

void routine()
{ 
  TCNT1 = 0;
  while(TCNT1<12500)
  {
   
  }

}