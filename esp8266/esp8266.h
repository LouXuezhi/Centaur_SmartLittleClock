#ifndef __My_esp8266_H__
#define __My_esp8266_H__
 
#include "main.h"
 
typedef uint16_t u16  ;
extern struct tm TimeStructure;
extern void esp8266_test(void);
extern void u2_printf(char* fmt);
extern uint8_t esp8266_send_cmd(char *cmd,char *ack,u16 waittime); 
extern uint8_t esp8266_ask_time(void);
extern uint8_t esp8266_start_trans(void);
 
#endif

