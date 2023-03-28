/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "RGB juli"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 18 bytes
  {  255,4,0,0,0,71,0,16,24,5,6,0,3,22,57,57,0,26,26,2,
  1,20,88,22,11,0,22,23,15,15,79,78,0,79,70,70,0,131,1,5,
  5,53,11,1,23,7,76,117,122,32,100,101,32,74,117,108,105,32,58,51,
  0,129,0,54,99,8,2,0,26,115,109,112,32,118,49,46,48,0};
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

const int freq = 5000;
const int ledchannel  = 0;
const int ledchannel2 = 1;
const int ledchannel3 = 2;
const int ledchannel4 = 3;

const int resolution  = 8;
const int ledpin  = 12;
const int ledpin2 = 13;
const int ledpin3 = 14;
const int ledpin4 = 4;
void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  ledcSetup(ledchannel,freq,resolution);
  ledcSetup(ledchannel2,freq,resolution);
  ledcSetup(ledchannel3,freq,resolution);
  ledcSetup(ledchannel4,freq,resolution);


  ledcAttachPin(ledpin,ledchannel);
  ledcAttachPin(ledpin2,ledchannel2);
  ledcAttachPin(ledpin3,ledchannel3);
  ledcAttachPin(ledpin4,ledchannel4);

}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
  if(RemoteXY.switch_1==1){
    ledcWrite(ledchannel4, 0);
    ledcWrite(ledchannel3, RemoteXY.rgb_1_r);
    ledcWrite(ledchannel , RemoteXY.rgb_1_g);
    ledcWrite(ledchannel2, RemoteXY.rgb_1_b);
  }else{
    ledcWrite(ledchannel3, 0);
    ledcWrite(ledchannel , 0);
    ledcWrite(ledchannel2, 0);
    ledcWrite(ledchannel4, 255);
  };

  
  Serial.print(RemoteXY.rgb_1_r);
  Serial.print(" ");
  Serial.print(RemoteXY.rgb_1_g);
  Serial.print(" ");
  Serial.print(RemoteXY.rgb_1_b); 
  Serial.println(" ");
}
