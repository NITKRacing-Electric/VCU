int L0 = 9;
int L1 = 10;
int L2 = 11;
int U0 = 3;
int U1 = 5;
int U2 = 6;

const byte inputs[] = {A0, A1, A2, A3, A4};

#define RT0 10000 // Ω
#define B 7500    // need to be recalibrated
#define VCC 5     // Supply voltage
#define R 10000   //
#define T0 298.5

float RT, VR, ln, TX, VRT;
float Tmax = 0; // max cell voltage
float T;

void setup()
{
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(U0, OUTPUT);
  pinMode(U1, OUTPUT);
  pinMode(U2, OUTPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
}

void loop()
{
  Tmax = 0;
  for (int k = 0; k < 5; k++)
  {
    Serial.print("******* SEGMENT ");
    Serial.print(k);
    Serial.println(" *******");
    Serial.println();


    for (int q = 0; q < 6; q++)
    {
      digitalWrite(U0, HIGH && (q & B00000001));
      digitalWrite(U1, HIGH && (q & B00000010));
      digitalWrite(U2, HIGH && (q & B00000100));
      Serial.print("section ");
      Serial.print(q);
      Serial.print(" >>>");
     
      //        this is for 8 temperatures
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(L0, HIGH && (i & B00000001));
        digitalWrite(L1, HIGH && (i & B00000010));
        digitalWrite(L2, HIGH && (i & B00000100));
        delay(10);

        VRT = analogRead(inputs[k]);         //Acquisition analog value of VRT
        //VRT = random(0, 1023);
        Serial.print("    ");
        Serial.print(i);
        Serial.print(":");

        if (VRT < 100)
        {
          Serial.print("LOW");
        }
        else if (VRT > 700)
        {
          Serial.print("HIGH");
        }
        else
        {
          VRT = (5.00 / 1023.00) * VRT;
          // 0.4887 4.887

          VR = VCC - VRT;

          RT = VRT / (VR / R);
          // Resistance of RT

          ln = log(RT / RT0);

          TX = (1 / ((ln / B) + (1 / T0))); // Temperature from thermistor

          TX = TX - 273.15;
          T = TX;
          Serial.print(int(T));
         
        }

        if (Tmax < T)
        {
          Tmax = T;
        }
      }
      Serial.println();

    }
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
  }


  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.print("Max temperaure : "); 
  Serial.println(int(Tmax));
  delay(100000);
}