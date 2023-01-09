#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
struct can_frame IMDselfTestMsg;

#define LV_BMS_ADDR 0x01
#define Sensors_ADDR 0x02
#define IMD_info_ADDR 0x37


MCP2515 mcp2515(53);

void setup() {
 IMDselfTestMsg.can_id  = 0x22;
 IMDselfTestMsg.can_dlc = 5;
 IMDselfTestMsg.data[0] = 0x21;
 IMDselfTestMsg.data[1] = 1;
 IMDselfTestMsg.data[2] = 0;
 IMDselfTestMsg.data[3] = 0;
 IMDselfTestMsg.data[4] = 0;
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();




mcp2515.sendMessage(&IMDselfTestMsg);//IMD self test



}

void loop() {

  CAN();

}

void CAN()
 {
   if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) //polling for incoming signals
   {
    LV_BMS_CAN();
    Sensors_CAN();
    IMD_CAN();
    
    
   }
 }

void LV_BMS_CAN()
 {
 if (canMsg.can_id==LV_BMS_ADDR)
    {
      Serial.println("c:");
      for (int i = 0; i<6; i++)   // print the LV voltage then current data
      { 
      Serial.print(" ");
      Serial.print(canMsg.data[i]);
      }
     
      Serial.println("f:");
      for (int i = 6; i<16; i++)   // print the temp data
      { 
      Serial.print(" ");
      Serial.print(canMsg.data[i]);
      }
    
    }
 }
 
void Sensors_CAN()
 {
 if (canMsg.can_id==Sensors_ADDR)
    {
      Serial.println("3:");   // speed
      Serial.print(" ");
      Serial.print(canMsg.data[0]);
     
      Serial.println("a:") ;//wheel speeds
      for (int i = 1; i<5; i++)  
      { 
      Serial.print(" ");
      Serial.print(canMsg.data[i]);
      }

      Serial.println("b:") ;//accelaration x y z
      for (int i = 5; i<8; i++)  
      { 
      Serial.print(" ");
      Serial.print(canMsg.data[i]);
      }

      Serial.println("j:") ;//Motor temperature 
      for (int i = 8; i<10; i++)  
      { 
      Serial.print(" ");
      Serial.print(canMsg.data[i]);
      }

      Serial.println("3:");   // Eror code motor controller  
      Serial.print(" ");
      Serial.print(canMsg.data[0]);
    }
    }

void IMD_CAN()
{
  if (canMsg.can_id== IMD_info_ADDR)
  {
   

  }


 
}    




