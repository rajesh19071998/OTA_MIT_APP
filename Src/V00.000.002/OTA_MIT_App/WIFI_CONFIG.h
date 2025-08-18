#ifndef _WIFI_CONFIG_H
#define _WIFI_CONFIG_H

#ifndef _EEPROM_H
  #define _EEPROM_H
  #include <EEPROM.h> 
#endif //_EEPROM_H


String BOARD_NUMBER = "100";
String BOARD_NAME = "RAJESH_BASIC_ESP";

String Global_IP = "";

String STATIC_IP = "";
String GATEWAY_IP = "";

/*
String STATIC_IP = "192.168.31.230";
String GATEWAY_IP = "192.168.31.1";
*/

String  AP_NameChar = "RAJESH_BASIC_ESP" ;
String WiFiPassword = "123456789";

String     ssid = "RajeshJioFiber";
String password = "Rajesh@1998";
/*
String     ssid = "Rajesh iPhone";
String password = "123456789";
*/



#endif //_WIFI_CONFIG_H
