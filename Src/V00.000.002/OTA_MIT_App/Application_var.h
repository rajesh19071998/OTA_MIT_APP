#ifndef _APPLICATION_VARIABLES_H
#define _APPLICATION_VARIABLES_H

#include "PIN_CONFIG.h"
#include "Millis_Timer.h"

#include "google_sheet.h"

extern String Appl_mit_DATA;
extern int MIT_flag;
String MIT_Appl_cmd = "Appl CMD's\n";

#define DEBUG 1

#define _ON  1
#define _OFF 0


// Must start timer from 3 (0,1,2 was reserved )
#define SLEEP_TIMER1 3 // 5 sec timer














#endif //_APPLICATION_VARIABLES_H