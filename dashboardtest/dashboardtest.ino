void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  

  // put your setup code here, to run once:

}

void loop() {
 int i=0;
 while(i<101)
 {
   Serial.print("3:");
   Serial.println(i);
   delay(100);
   Serial.print("4:");
   Serial.println(100-i);
   delay(100);
   Serial.print("6:");
   Serial.println(2*i);
   delay(100);
   Serial.print("5:");
   Serial.println((i%3)+1);

   delay(100);
   Serial.print("1:");
   Serial.println(i+5);

   delay(100);
   Serial.print("2:");
   Serial.println(3*i);

   delay(100);
   Serial.print("7:");
   Serial.println("hello");

   delay(100);

   

   i++;

 }



  // put your main code here, to run repeatedly:

}
