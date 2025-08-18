#ifndef _APPLICATION_FUNCTIONS_H
#define _APPLICATION_FUNCTIONS_H

#include "Application_var.h"

// This file related Header files , Macros , variables , structures must be declared in  "Application_var.h" file

void Application_Setup()
{
 
  //pinMode(GREEN_LED, INPUT_PULLUP);

  //auto_lock_flag = EEPROM.read(auto_lock_addr);

  Timer[SLEEP_TIMER1].delayMillis = 5000; // 5 sec
  

     /*
  EEPROM.write(head_light_addr, 0);
  EEPROM.write(auto_lock_addr, 0);
  EEPROM.write(auto_sleep_addr, 0);
  EEPROM.commit();
  delay(100);
  */

} //Application_Setup









void All_sleep()
{
  if(Timer[SLEEP_TIMER1].active == 0)
    Timer_activate(SLEEP_TIMER1);

  Appl_mit_DATA = "Sleep Activated in 5 sec...!";

}

void Timer_timeout_check()
{

  if(Timer[SLEEP_TIMER1].timeout == 1) // 5 sec timer
  {
  
    Timer_deactivate(SLEEP_TIMER1);
    delay(1000);
    Serial.println("SLEEP Timer 1 Expired! Going to Sleep...!");
    ESP.deepSleep(0); 
  } 


  

}



void Update_IP_On_Google_Sheet()
{
  static int OneCall = 0; // it will execute one time in RST or power cycle
  if(OneCall == 0)
  {
     // String string_temperature =  String(tem); //float to string

     // String string_humidity =  String(hum, DEC); // int to string

    // String G_Data = "Action=AddESP&ESPName=" + BOARD_NAME + "&ESPNum=" + BOARD_NUMBER + "&ESPIP=" + WiFi.localIP().toString();
     String G_Data = "Action=AddESP&ESPName=" + BOARD_NAME + "&ESPNum=" + BOARD_NUMBER + "&ESPIP=" + MY_IP;
    sendDataToGoogleSheet(G_Data);
    OneCall = 1;
  }

}



void Application_loop()
{
  // keep watching the push button:
  
  Timer_timeout_check();
  Timer_loop(); // Millis_Timer.h

  Update_IP_On_Google_Sheet(); // only one time

}

void mit_app_requist_process(String request) // refer MIT_APP.h
{

  if  ( request.indexOf("Sleep") > 0 ) { MIT_flag = 2; if(DEBUG) Serial.println(request); All_sleep(); }

}



















#endif //_APPLICATION_FUNCTIONS_H
