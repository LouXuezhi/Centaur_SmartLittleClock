#include "stm32l4xx.h"                  // Device header
#include "rtc.h"
#include "gpio.h"
#include "RTC_User.h"
#include <stdbool.h>
#include <stdio.h>
#include "string.h"
#include "main.h"
//#define GPIO_PIN_RESET OFFPIN
//#define GPIO_PIN_SET ONPIN
RTC_DateTypeDef GetDate;  //获取日期结构体

RTC_TimeTypeDef  GetTime;   //获取时间结构体

uint8_t bias;
void Refresh_RTC_Struct(void)
{
	HAL_RTC_GetTime(&hrtc, &GetTime, RTC_FORMAT_BIN);
      /* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &GetDate, RTC_FORMAT_BIN);
}

void Reset_RTC_Time(RTC_TimeTypeDef* GetTime)
{
	HAL_RTC_SetTime(&hrtc,GetTime,RTC_FORMAT_BIN);
}
 
void Reset_RTC_Date(RTC_DateTypeDef* GetDate)
{
	HAL_RTC_SetDate(&hrtc,GetDate,RTC_FORMAT_BIN);
}

uint8_t Get_RTC_Sec(void)
{
	uint8_t Sec;
	Sec=GetTime.Seconds;
	return Sec;
}

uint8_t Get_RTC_Min(void)
{
	uint8_t Min;
	Min=GetTime.Minutes;
	return Min;
}

uint8_t Get_RTC_Hour(uint8_t Bias)
{
	uint8_t Hour;
	Hour=GetTime.Hours+Bias;
	return Hour;
}

uint8_t Get_RTC_Min_0 (void)
{
	return (Get_RTC_Min()%10);
}

uint8_t Get_RTC_Min_1 (void)
{
	return (Get_RTC_Min()/10);
}


uint8_t Get_RTC_Hour_0 (uint8_t Bias)
{
	return (Get_RTC_Hour(Bias)%10);
}

uint8_t Get_RTC_Hour_1 (uint8_t Bias)
{
	return (Get_RTC_Hour(Bias)/10);
}

void Refresh_Clock(uint8_t h1,uint8_t h0,uint8_t m1,uint8_t m0)
{
	uint8_t time[4]={h1,h0,m1,m0};
	for (uint8_t n=0;n<4;n++)
	{
		if(n==1)
		{
					HAL_GPIO_WritePin(GPIOCSH,GPIOCSH_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOCSM,GPIOCSM_PIN,GPIO_PIN_RESET);
		}
		else if (n==3)
		{
					HAL_GPIO_WritePin(GPIOCSH,GPIOCSH_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOCSM,GPIOCSM_PIN,GPIO_PIN_SET);
		}
		switch (time[n])
		{
			case 0:
				if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			
			break;
			case 1:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 2:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 3:
								if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 4:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 5:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_SET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_SET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 6:
								if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 7:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 8:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_SET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_SET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;
			case 9:
							if(n==1||n==3)
				{
//					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_SET);
				}else if(n==2||n==4)
				{
					HAL_GPIO_WritePin(GPIOA0,GPIOA0_PIN,GPIO_PIN_SET);
					HAL_GPIO_WritePin(GPIOB0,GPIOB0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOC0,GPIOC0_PIN,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOD0,GPIOD0_PIN,GPIO_PIN_SET);
//					HAL_GPIO_WritePin(GPIOA1,GPIOA1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOB1,GPIOB1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOC1,GPIOC1_PIN,GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(GPIOD1,GPIOD1_PIN,GPIO_PIN_RESET);
				}
			break;		
		}
	}
	
}

void Clock_Init(void)
{
	
	Reset_RTC_Time(&GetTime);
	Reset_RTC_Date(&GetDate);
	
}

void Clock_Core(void)
{
	Refresh_RTC_Struct();
	Refresh_Clock(Get_RTC_Hour_1(bias),Get_RTC_Hour_0(bias),Get_RTC_Min_1(),Get_RTC_Min_0());
}

uint8_t BCDtoDEC(uint8_t bcd)
{
	return(bcd-(bcd>>4)*6);
}

uint8_t DECtoBCD(uint8_t dec)
{
	return(dec+(dec/10)*6);
}

RTC_AlarmTypeDef sAlarm;
 
bool SecondTick;
void SET_alarm(void)
{
  sAlarm.AlarmTime.Hours = 0x0;
  sAlarm.AlarmTime.Minutes = 0x0;
  sAlarm.AlarmTime.Seconds = GetTime.Seconds+1;
  sAlarm.AlarmTime.SubSeconds = 0x0;
  sAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY|RTC_ALARMMASK_HOURS
                              |RTC_ALARMMASK_MINUTES;
  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
  sAlarm.AlarmDateWeekDay = 0x1;
  sAlarm.Alarm = RTC_ALARM_A;
  if(sAlarm.AlarmTime.Seconds==60)sAlarm.AlarmTime.Seconds=0;
  HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN);//这里要注意，我们选择的是十进制
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
	Refresh_RTC_Struct();
	 SET_alarm();
	SecondTick=!SecondTick;
}
uint8_t MonthToInt(char* Month)
{
	if(strncmp(Month,"Jan",3)==0)
	{
		return 1;
	}
	if(strncmp(Month,"Feb",3)==0)
	{
		return 2;
	}
	if(strncmp(Month,"Mar",3)==0)
	{
		return 3;
	}
	if(strncmp(Month,"Apr",3)==0)
	{
		return 4;
	}
	if(strncmp(Month,"May",3)==0)
	{
		return 5;
	}
	if(strncmp(Month,"Jun",3)==0)
	{
		return 6;
	}
	if(strncmp(Month,"Jul",3)==0)
	{
		return 7;
	}
	if(strncmp(Month,"Aug",3)==0)
	{
		return 8;
	}
	if(strncmp(Month,"Sep",3)==0)
	{
		return 9;
	}
	if(strncmp(Month,"Oct",3)==0)
	{
		return 10;
	}
	if(strncmp(Month,"Nov",3)==0)
	{
		return 11;
	}
	if(strncmp(Month,"Dec",3)==0)
	{
		return 12;
	}
	else return 0;
}
