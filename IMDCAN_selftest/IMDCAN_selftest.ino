#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;//sent message 1
struct can_frame canMsg2;//sent message 2
struct can_frame canMsg3;//recieved messages 
MCP2515 mcp2515(53);

void setup() {
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();
  
  Serial.begin(115200);
  delay(5000);
  Serial.println("start");
  canMsg1.can_id  = 0x22;
  canMsg1.can_dlc = 5;
  canMsg1.data[0] = 0x21;
  canMsg1.data[1] = 1;
  canMsg1.data[2] = 0;
  canMsg1.data[3] = 0;
  canMsg1.data[4] = 0;
   mcp2515.sendMessage(&canMsg1);//Message one sending
  Serial.print(canMsg1.can_id, HEX); // print ID
  Serial.print("  "); 
  Serial.print(canMsg1.can_dlc); // print DLC
  Serial.print("  ");
  for (int i = 0; i<canMsg1.can_dlc; i++)   // print the data
      { 
      Serial.print(canMsg1.data[i],HEX);
      Serial.print(" ");
      }
  Serial.println("Message sent");

  // put your setup code here, to run once:

}

void loop() {
   //Serial.println("start");

   if (mcp2515.readMessage(&canMsg3) == MCP2515::ERROR_OK) //polling for incoming signals
   {
    Serial.print(canMsg3.can_id, HEX); // print ID
    Serial.print("  "); 
    Serial.print(canMsg3.can_dlc); // print DLC
    Serial.print("  ");
    
    for (int i = 0; i<canMsg3.can_dlc; i++)   // print the data
      { 
      Serial.print(canMsg3.data[i],HEX);
      Serial.print(" ");
      }
    Serial.println();      
   } 
  
}
