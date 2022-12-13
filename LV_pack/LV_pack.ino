const int L0 = 9;
const int L1 = 10;
const int L2 = 11;
const int L3 = 12;
int vin[5] = {0};
int vval[5] = {0};

#define RT0 10000 // Ω
#define B 7500    // need to be recalibrated
#define VCC 5     // Supply voltage
#define R 10000   //
#define T0 298.5

const int rval[] = {5.1, 20, 33, 47, 68}; // voltage devider resistor values

float Mux1_State[10] = {0};

float RT, VR, ln, TX, VRT;

void setup()
{
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop()
{

  tempMUX();
  Voltageread();

  delay(100);
}

void Voltageread()
{
  vin[0] = analogRead(A0);
  vin[1] = analogRead(A1);
  vin[2] = analogRead(A2);
  vin[3] = analogRead(A4);
  vin[3] = analogRead(A4);

  for (int q = 0; q < 5; q++)
  {
    int vinval = map(vin[q], 0, 1023, 0, 5);

    vval[q] = vinval * ((rval[q] + 10) / 10);
  }

  Serial.println("------------------Series voltages-------------------");
  for (int j = 0; j < 4; j++)
  {
    if (j == 3)
    {
      Serial.println(vval[j]);
    }
    else
    {
      Serial.print(vval[j]);
      Serial.print(" ");
    }
  }
}

void tempMUX()
{
  for (int i = 0; i < 10; i++)
  {
    // MUX select pins
    digitalWrite(L0, HIGH && (i & B00000001));
    digitalWrite(L1, HIGH && (i & B00000010));
    digitalWrite(L2, HIGH && (i & B00000100));
    digitalWrite(L3, HIGH && (i & B00001000));

    VRT = analogRead(A0); // Acquisition analog value of VRT
    VRT = (5.00 / 1023.00) * VRT;
    VR = VCC - VRT;
    RT = VRT / (VR / R); // Resistance of RT
    ln = log(RT / RT0);
    TX = (1 / ((ln / B) + (1 / T0))); // Temperature from thermistor
    TX = TX - 273.15;
    Mux1_State[i] = TX;
  }
  Serial.println("------------------Cell tempretures------------------");

  for (int j = 0; j < 10; j++)
  {
    if (j == 9)
    {
      Serial.println(Mux1_State[j]);
    }

    else
    {
      Serial.print(Mux1_State[j]);
      Serial.print(" ");
    }
  }
}
