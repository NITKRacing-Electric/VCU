#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;//sent message 1
struct can_frame canMsg2;//sent message 2
struct can_frame canMsg3;//recieved messages 
MCP2515 mcp2515(10);


void setup() {
  TCCR1B=0;
  TCCR1A=0;
  TCCR1B=bit(CS12);//timer for reception and transmission delay
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 4;
  canMsg1.data[0] = 50;
  canMsg1.data[1] = 100;
  canMsg1.data[2] = 150;
  canMsg1.data[3] = 200;
 

  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 6;
  canMsg2.data[0] = 10;
  canMsg2.data[1] = 20;
  canMsg2.data[2] = 30;
  canMsg2.data[3] = 40;
  canMsg2.data[4] = 50;
  canMsg2.data[5] = 60;
  
   mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS);
  mcp2515.setNormalMode();
  Serial.begin(115200);
  Serial.println("------- CAN Transreciver ----------");
  Serial.println("ID  DLC   status/Data");
  
  
}

void loop() {
  mcp2515.sendMessage(&canMsg1);//Message one sending
  Serial.print(canMsg1.can_id, HEX); // print ID
  Serial.print("  "); 
  Serial.print(canMsg1.can_dlc); // print DLC
  Serial.print("  ");
  Serial.println("Messages sent");
  
  mcp2515.sendMessage(&canMsg2);//Message two sending
  Serial.print(canMsg2.can_id, HEX); // print ID
  Serial.print("  "); 
  Serial.print(canMsg2.can_dlc); // print DLC
  Serial.print("  ");
  Serial.println("Messages sent");

  TCNT1=0;
  while(TCNT1<=12500)//200ms delay between transmissions(62500 counts=1 second)
  {
   if (mcp2515.readMessage(&canMsg3) == MCP2515::ERROR_OK) //polling for incoming signals
   {
    Serial.print(canMsg3.can_id, HEX); // print ID
    Serial.print("  "); 
    Serial.print(canMsg3.can_dlc); // print DLC
    Serial.print("  ");
    
    for (int i = 0; i<canMsg3.can_dlc; i++)   // print the data
      { 
      Serial.print(canMsg3.data[i]);
      Serial.print(" ");
      }
    Serial.println();      
   } 
  }
  
}
