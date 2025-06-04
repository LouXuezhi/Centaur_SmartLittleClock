#include "main.h"
#include "esp8266.h"
#include "string.h"
#include "usart.h"
#include "time.h"
#include <stdlib.h>
#include "RTC_User.h"
void u2_printf(char* fmt);
uint8_t esp8266_send_cmd(char *cmd,char *ack,u16 waittime); 
struct tm TimeStructure;
//extern char RxBuffer[256];
//extern uint8_t Uart1_Rx_Cnt;
//void esp8266_test(void)//测试
//{
//if(esp8266_send_cmd("AT","OK",50));
// 
//}
// 
uint8_t esp8266_send_cmd(char *cmd,char *ack,u16 waittime)//发送指令和检查接收
{
 
		u2_printf(cmd);


		while(waittime)	
		{
			HAL_Delay(10);
			if(strstr((const char*)RxBuffer,(const char*)ack)!=NULL) //输入on，LED0亮
			{
			
			Uart1_Rx_Cnt=0;
			//memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组	
			return 1;
 
			}
			waittime--;
		}
 

 
	return 0;
}
 
uint8_t esp8266_ask_time(void)
 {
	 uint16_t waittime=512;
	 u2_printf("AT+CIPSNTPTIME?");
	 	//u2_printf(RxBuffer);
	 if(waittime)		
	{
		while(--waittime)	
		{
			HAL_Delay(10);
			if(strstr((const char*)RxBuffer,"OK") )//输入on，LED0亮
			{
				if (strncmp(RxBuffer, "+CIPSNTPTIME:", 13) == 0)
				{
				// 跳过 "+CIPSNTPTIME:" 部分
					char* timeStr = RxBuffer + 13;

				// 使用 strtok 提取时间部分
					week=strtok(timeStr, " ");
					month=strtok(NULL, " ");
					date=strtok(NULL, " ");
//					char* token = strtok(timeStr, " "); // 跳过 "Sat"
//					token = strtok(NULL, " ");          // 跳过 "May"
//					token = strtok(NULL, " ");          // 跳过 "17"
					char* timePart = strtok(NULL, " "); // 提取 "09:33:37"
					//year=strtok(NULL, "\r");
					if (timePart != NULL)
					{
						// 分割时间部分
						char* H = strtok(timePart, ":");
						char* M = strtok(NULL, ":");
						char* S = strtok(NULL, ":");
						GetTime.Hours=atoi(H); 
						GetTime.Minutes=atoi(M);
						GetTime.Seconds=atoi(S);
						Reset_RTC_Time(&GetTime);
						Uart1_Rx_Cnt=0;
						memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组	
						return 1;
					}
//			wholetime=strtok(RxBuffer," ");
//			memset(wholetime,0x00,strlen(wholetime));
//			for(uint8_t i=0;i<2;i++)
//			{
//				wholetime=strtok(NULL," ");	
//				memset(wholetime,0x00,strlen(wholetime));
//			}
//			char* H=strtok(wholetime,":");
//			char* M=strtok(NULL,":");
//			char* S=strtok(NULL,":");
//			TimeStruct_Stm->Hours=atoi(H);
//			TimeStruct_Stm->Minutes=atoi(M);
//			TimeStruct_Stm->Seconds=atoi(S);
					}
						
 
				}
			}
	
	 	 
	}
	return 02;
}
uint8_t esp8266_start_trans(void)//ESP8266初始化
{
	
//	if(esp8266_send_cmd("AT+RST","ready",600)==0) return 02;//重启
////	//u2_printf(cmd);
////	HAL_Delay(1000);       
//	HAL_Delay(1000);
//	HAL_Delay(1000);
//	HAL_Delay(1000);
//	//HAL_Delay(1000);       
//	//HAL_Delay(1000);
//	//HAL_Delay(1000);
//	//HAL_Delay(1000);
	if(esp8266_send_cmd("AT+CWMODE=1","OK",800)==0) return 01 ;//设置为AP模式
//	
//	
	HAL_Delay(200);
	if(esp8266_send_cmd("AT+CWJAP=\"LOUXUEZHI\",\"12345678\"","OK",800)==0)
	{
		HAL_Delay(1000);
		HAL_Delay(1000);
		if(esp8266_send_cmd("AT+CWJAP=\"519\",\"51966666\"","OK",800)==0)//设置WiFi名称、密码，模式
			return 03;
	}
	HAL_Delay(1000);
	HAL_Delay(1000);
	if(esp8266_send_cmd("AT+CIPSNTPCFG=1,8,\"cn.pool.ntp.org\"","OK",800)==0)return 04;
	HAL_Delay(1000);
	if(esp8266_send_cmd("ATE0","OK",200)==0)return 05;
	HAL_Delay(1000);
	return 10;
	//esp8266_send_cmd("AT+CIPMUX=1","OK",20);//进入透传模式
	//esp8266_send_cmd("AT+CIPSERVER=1,8080","OK",200);//设置端口8080
	//esp8266_send_cmd("AT+CIPSEND","OK",50);//开始发送数据
}
 

//uint8_t esp8266_start_trans(void)//ESP8266初始化
//{
//	
//	esp8266_send_cmd("AT+RST","ready",2000);//重启
//	u2_printf(RxBuffer);
//	HAL_Delay(1000);       
//	HAL_Delay(1000);
//	HAL_Delay(1000);
//	HAL_Delay(1000);
//	//HAL_Delay(1000);       
//	//HAL_Delay(1000);
//	//HAL_Delay(1000);
//	HAL_Delay(1000);
//	esp8266_send_cmd("AT+CWMODE=1","OK",50);//设置为AP模式
//	//u2_printf(RxBuffer);
//	
//	esp8266_send_cmd("AT+CWJAP=\"519\",\"51966666\",1,4","OK",200);//设置WiFi名称、密码，模式
//	//u2_printf(RxBuffer);
//	esp8266_send_cmd("AT+CIPSNTPCFG=1,8,\"cn.pool.ntp.org\"","OK",200);
//	HAL_Delay(1000);
//	return 10;
//	//esp8266_send_cmd("AT+CIPMUX=1","OK",20);//进入透传模式
//	//esp8266_send_cmd("AT+CIPSERVER=1,8080","OK",200);//设置端口8080
//	//esp8266_send_cmd("AT+CIPSEND","OK",50);//开始发送数据
//}
 
uint8_t esp8266_quit_trans(void)//退出透传模式
{
	uint8_t result=1;
	u2_printf("+++");
	HAL_Delay(1000);					
	result=esp8266_send_cmd("AT","OK",20);
	return result;
 
}
 
 
void u2_printf(char* fmt)  
{  
 
	uint8_t num=0;
  char my_ch[50]={0};
	while(*fmt!=0)
	my_ch[num++]=*fmt++;
	
	my_ch[num++]='\r';
	my_ch[num++]='\n';
	
	HAL_UART_Transmit(&huart1, (uint8_t *)my_ch,num, 0xffff);
   while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);
 
}
 
