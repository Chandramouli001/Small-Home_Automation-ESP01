me

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_CLOUD

#include <ESP8266WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "SSID 2"
#define REMOTEXY_WIFI_PASSWORD "244466666"
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
#define REMOTEXY_CLOUD_PORT 6376
#define REMOTEXY_CLOUD_TOKEN "1b64f2a08c451d851ff12ed528f522cd"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 134 bytes
  { 255,4,0,0,0,127,0,19,0,0,0,82,111,111,109,32,49,0,31,1,
  106,200,1,1,4,0,10,9,26,39,39,48,4,26,31,76,73,71,72,84,
  32,79,78,0,31,76,73,71,72,84,32,79,70,70,0,10,59,27,39,39,
  48,4,26,31,70,65,78,32,79,78,0,31,70,65,78,32,79,70,70,0,
  10,10,80,39,39,48,4,26,31,66,85,76,66,32,79,78,0,31,66,85,
  76,66,32,79,70,70,0,10,59,82,39,39,48,4,26,31,80,76,85,71,
  32,79,78,0,31,80,76,85,71,32,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t pushSwitch_01; // =1 if state is ON, else =0
  uint8_t pushSwitch_02; // =1 if state is ON, else =0
  uint8_t pushSwitch_03; // =1 if state is ON, else =0
  uint8_t pushSwitch_04; // =1 if state is ON, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_PUSHSWITCH_01 1 // TX
#define PIN_PUSHSWITCH_02 2 // GPIO 2
#define PIN_PUSHSWITCH_03 3 // RX
#define PIN_PUSHSWITCH_04 0 // GPIO 0


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_PUSHSWITCH_01, OUTPUT);
  pinMode (PIN_PUSHSWITCH_02, OUTPUT);
  pinMode (PIN_PUSHSWITCH_03, OUTPUT);
  pinMode (PIN_PUSHSWITCH_04, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_PUSHSWITCH_01, (RemoteXY.pushSwitch_01==1)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_02, (RemoteXY.pushSwitch_02==1)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_03, (RemoteXY.pushSwitch_03==1)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_04, (RemoteXY.pushSwitch_04==1)?LOW:HIGH);
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
