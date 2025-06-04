#ifndef __RTC_USER_H__
#define __RTC_USER_H__

#define GPIOA0 GPIOA
#define GPIOB0 GPIOB
#define GPIOC0 GPIOB
#define GPIOD0 GPIOA
#define GPIOA1 GPIOA
#define GPIOB1 GPIOA
#define GPIOC1 GPIOA
#define GPIOD1 GPIOA
#define GPIOA0_PIN GPIO_PIN_7
#define GPIOB0_PIN GPIO_PIN_0
#define GPIOC0_PIN GPIO_PIN_1
#define GPIOD0_PIN GPIO_PIN_8
#define GPIOA1_PIN GPIO_PIN_3
#define GPIOB1_PIN GPIO_PIN_4
#define GPIOC1_PIN GPIO_PIN_5
#define GPIOD1_PIN GPIO_PIN_6
#define GPIOCSH GPIOB
#define GPIOCSM GPIOB
#define GPIOCSH_PIN GPIO_PIN_5
#define GPIOCSM_PIN GPIO_PIN_4
#include <stdio.h>
#include <stdbool.h>
extern RTC_DateTypeDef GetDate;
extern RTC_TimeTypeDef  GetTime;
extern uint8_t bias;

void Refresh_RTC_Struct(void);
void Reset_RTC_Time(RTC_TimeTypeDef* GetTime);
void Reset_RTC_Date(RTC_DateTypeDef* GetDate);

uint8_t Get_RTC_Sec(void);
uint8_t Get_RTC_Min(void);
uint8_t Get_RTC_Hour(uint8_t Bias);

uint8_t Get_RTC_Min_0 (void);
uint8_t Get_RTC_Min_1 (void);
uint8_t Get_RTC_Hour_0 (uint8_t Bias);
uint8_t Get_RTC_Hour_1 (uint8_t Bias);

void Refresh_Clock(uint8_t h1,uint8_t h0,uint8_t m1,uint8_t m0);
void Clock_Init(void);
void Clock_Core(void);

uint8_t BCDtoDEC(uint8_t bcd);
uint8_t DECtoBCD(uint8_t dec);

extern bool SecondTick;
void SET_alarm(void);

#endif
