#include "astra_ui_core.h"
#include "astra_ui_draw_driver.h"
#include "astra_ui_item.h"
#include "esp8266.h"
#include <stdio.h>
#include "RTC_User.h"
#include "GIFAnimation.h"
#include "u8g2.h"
#include "main.h"
#define STEP 60
#define ORIGIN 500
#define DURATION 60
uint32_t time_start = 0;
//uint8_t time_start2=0;
bool if24timesys=true;
void UserItem_Init_1(void)
{
	time_start = get_ticks();
}

void UserItem_Exit_1(void)
{
//	for (uint8_t i = 0; i < astra_selector.selected_item->parent->child_num; i++)
//	astra_selector.selected_item->parent->child_list_item[i]->y_list_item = 0;
//	astra_selector.selected_index = 0;
//	astra_selector.selected_item = astra_selector.selected_item->parent->child_list_item[0];
}

void UserItem_Loop_1(void)
{
//	for (int i = 0; i < 42; i++) {
//    
//      u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[i]);
// // ÑÓÊ±1Ãë
//  }
	uint32_t _time = get_ticks();
if(_time-time_start>(ORIGIN +0*STEP)&&_time-time_start<(ORIGIN +0*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[1]);
if(_time-time_start>(ORIGIN +1*STEP)&&_time-time_start<(ORIGIN +1*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[2]);
if(_time-time_start>(ORIGIN +2*STEP)&&_time-time_start<(ORIGIN +2*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[3]);
if(_time-time_start>(ORIGIN +3*STEP)&&_time-time_start<(ORIGIN +3*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[4]);
if(_time-time_start>(ORIGIN +4*STEP)&&_time-time_start<(ORIGIN +4*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[5]);
if(_time-time_start>(ORIGIN +5*STEP)&&_time-time_start<(ORIGIN +5*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[6]);
if(_time-time_start>(ORIGIN +6*STEP)&&_time-time_start<(ORIGIN +6*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[7]);
if(_time-time_start>(ORIGIN +7*STEP)&&_time-time_start<(ORIGIN +7*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[8]);
if(_time-time_start>(ORIGIN +8*STEP)&&_time-time_start<(ORIGIN +8*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[9]);
if(_time-time_start>(ORIGIN +9*STEP)&&_time-time_start<(ORIGIN +9*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[10]);
if(_time-time_start>(ORIGIN +10*STEP)&&_time-time_start<(ORIGIN +10*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[11]);
if(_time-time_start>(ORIGIN +11*STEP)&&_time-time_start<(ORIGIN +11*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[12]);
if(_time-time_start>(ORIGIN +12*STEP)&&_time-time_start<(ORIGIN +12*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[13]);
if(_time-time_start>(ORIGIN +12*STEP)&&_time-time_start<(ORIGIN +13*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[14]);
if(_time-time_start>(ORIGIN +14*STEP)&&_time-time_start<(ORIGIN +14*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[15]);
if(_time-time_start>(ORIGIN +15*STEP)&&_time-time_start<(ORIGIN +15*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[16]);
if(_time-time_start>(ORIGIN +16*STEP)&&_time-time_start<(ORIGIN +16*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[17]);
if(_time-time_start>(ORIGIN +17*STEP)&&_time-time_start<(ORIGIN +17*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[18]);
if(_time-time_start>(ORIGIN +18*STEP)&&_time-time_start<(ORIGIN +18*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[19]);
if(_time-time_start>(ORIGIN +19*STEP)&&_time-time_start<(ORIGIN +19*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[20]);
if(_time-time_start>(ORIGIN +20*STEP)&&_time-time_start<(ORIGIN +20*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[21]);
if(_time-time_start>(ORIGIN +21*STEP)&&_time-time_start<(ORIGIN +21*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[22]);
if(_time-time_start>(ORIGIN +22*STEP)&&_time-time_start<(ORIGIN +22*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[23]);
if(_time-time_start>(ORIGIN +23*STEP)&&_time-time_start<(ORIGIN +23*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[24]);
if(_time-time_start>(ORIGIN +24*STEP)&&_time-time_start<(ORIGIN +24*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[25]);
if(_time-time_start>(ORIGIN +25*STEP)&&_time-time_start<(ORIGIN +25*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[26]);
if(_time-time_start>(ORIGIN +26*STEP)&&_time-time_start<(ORIGIN +26*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[27]);
if(_time-time_start>(ORIGIN +27*STEP)&&_time-time_start<(ORIGIN +27*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[28]);
if(_time-time_start>(ORIGIN +28*STEP)&&_time-time_start<(ORIGIN +28*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[29]);
if(_time-time_start>(ORIGIN +29*STEP)&&_time-time_start<(ORIGIN +29*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[30]);
if(_time-time_start>(ORIGIN +30*STEP)&&_time-time_start<(ORIGIN +30*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[31]);
if(_time-time_start>(ORIGIN +31*STEP)&&_time-time_start<(ORIGIN +31*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[32]);
if(_time-time_start>(ORIGIN +32*STEP)&&_time-time_start<(ORIGIN +32*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[33]);
if(_time-time_start>(ORIGIN +33*STEP)&&_time-time_start<(ORIGIN +33*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[34]);
if(_time-time_start>(ORIGIN +34*STEP)&&_time-time_start<(ORIGIN +34*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[35]);
if(_time-time_start>(ORIGIN +35*STEP)&&_time-time_start<(ORIGIN +35*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[36]);
if(_time-time_start>(ORIGIN +36*STEP)&&_time-time_start<(ORIGIN +36*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[37]);
if(_time-time_start>(ORIGIN +37*STEP)&&_time-time_start<(ORIGIN +37*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[38]);
if(_time-time_start>(ORIGIN +38*STEP)&&_time-time_start<(ORIGIN +38*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[39]);
if(_time-time_start>(ORIGIN +39*STEP)&&_time-time_start<(ORIGIN +39*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[40]);
if(_time-time_start>(ORIGIN +40*STEP)&&_time-time_start<(ORIGIN +40*STEP+DURATION))u8g2_DrawXBMP(&u8g2,0, 0, 127, 63, epd_bitmap_allArray[41]);

	char Hours_Now[10]={0};
	char Minutes_Now[10]={0};
	char Seconds_Now[10]={0};
	Refresh_RTC_Struct();
	uint8_t HourDemanded=Get_RTC_Hour(0);
	uint8_t MinuteDemanded=Get_RTC_Min();
	uint8_t SecondDemanded=Get_RTC_Sec();

	if(_time-time_start>(ORIGIN +40*STEP+DURATION))
	{	
		if(!if24timesys)
		{
			if(HourDemanded>12)
			{
				HourDemanded-=12;
				oled_set_font( u8g2_font_5x7_tr);
				oled_draw_str(60,58, "PM");
			}else
			{
				oled_set_font( u8g2_font_5x7_tr);
			oled_draw_str(60,58, "AM");
			}
			
		}
		sprintf (Hours_Now,"%02d ",HourDemanded);
		sprintf (Minutes_Now,"%02d",MinuteDemanded);
		sprintf (Seconds_Now,"%d",SecondDemanded);
		oled_set_font( u8g2_font_logisoso42_tn);
		oled_draw_str(2,53, Hours_Now);
		if(_time%2000<1000&&0<_time%2000)
		{
			oled_set_font( u8g2_font_logisoso50_tn);
			oled_draw_str(56,53, ":");
		}
		oled_set_font( u8g2_font_logisoso42_tn);
		oled_draw_str(72,53, Minutes_Now);

	}
	//PrintVarFormat(&u8g2,63,31,u8g2_font_sirclivethebold_tr,);
}
static int count_time=-1;
bool Last_tick;
/*********************************************************************

CountDown Function Group 60 S

************************************************************************/

void UserItem_Init_2(void)
{
	Last_tick=SecondTick;
	count_time=-1;
	//time_start2 = Get_RTC_Sec();
}
void UserItem_Exit_2(void)
{
	count_time=-1;
}

void UserItem_Loop_2(void)
{
	//Refresh_RTC_Struct();
	

	
	if (count_time>=60)
			{
				oled_set_font(u8g2_font_logisoso46_tf);
				oled_draw_str(0,53,"DONE");
				return;
			}

	if(SecondTick==!Last_tick&&count_time==-1)
	{
		count_time++;
		Last_tick=SecondTick;
		return;
	}
	else
		{
			if(SecondTick==!Last_tick&&count_time!=-1)
				{
					count_time++;
					Last_tick=SecondTick;	
				}
			if(count_time!=-1)
				{	
					char showstr[10]={0};
					sprintf (showstr,"%02d ",60-count_time);
					oled_set_font( u8g2_font_logisoso50_tn);
					oled_draw_str(56,53,showstr);	
				}
	
		}	
}
/*********************************************************************

CountDown Function Group 120 S

************************************************************************/
void UserItem_Init_3(void)
{
	Last_tick=SecondTick;
	count_time=-1;
	//time_start2 = Get_RTC_Sec();
}
void UserItem_Exit_3(void)
{
	count_time=-1;
}

void UserItem_Loop_3(void)
{
	//Refresh_RTC_Struct();
	

	
	if (count_time>=120)
			{
				oled_set_font(u8g2_font_logisoso46_tf);
				oled_draw_str(0,53,"DONE");
				return;
			}

	if(SecondTick==!Last_tick&&count_time==-1)
	{
		count_time++;
		Last_tick=SecondTick;
		return;
	}
	else
		{
			if(SecondTick==!Last_tick&&count_time!=-1)
				{
					count_time++;
					Last_tick=SecondTick;	
				}
			if(count_time!=-1)
				{	
					char showstr[10]={0};
					sprintf (showstr,"%03d ",120-count_time);
					oled_set_font( u8g2_font_logisoso50_tn);
					oled_draw_str(28,53,showstr);	
				}
	
		}	
}

/*********************************************************************

CountDown Function Group 300 S

************************************************************************/
void UserItem_Init_4(void)
{
	Last_tick=SecondTick;
	count_time=-1;
	//time_start2 = Get_RTC_Sec();
}
void UserItem_Exit_4(void)
{
	count_time=-1;
}

void UserItem_Loop_4(void)
{
	//Refresh_RTC_Struct();
	

	
	if (count_time>=300)
			{
				oled_set_font(u8g2_font_logisoso46_tf);
				oled_draw_str(0,53,"DONE");
				return;
			}

	if(SecondTick==!Last_tick&&count_time==-1)
	{
		count_time++;
		Last_tick=SecondTick;
		return;
	}
	else
		{
			if(SecondTick==!Last_tick&&count_time!=-1)
				{
					count_time++;
					Last_tick=SecondTick;	
				}
			if(count_time!=-1)
				{	
					char showstr[10]={0};
					sprintf (showstr,"%03d ",300-count_time);
					oled_set_font( u8g2_font_logisoso50_tn);
					oled_draw_str(28,53,showstr);	
				}
	
		}	
}
/*********************************************************************

CountDown Function Group 600 S

************************************************************************/
void UserItem_Init_5(void)
{
	Last_tick=SecondTick;
	count_time=-1;
	//time_start2 = Get_RTC_Sec();
}
void UserItem_Exit_5(void)
{
	count_time=-1;
}

void UserItem_Loop_5(void)
{
	//Refresh_RTC_Struct();
	

	
	if (count_time>=600)
			{
				oled_set_font(u8g2_font_logisoso46_tf);
				oled_draw_str(0,53,"DONE");
				return;
			}

	if(SecondTick==!Last_tick&&count_time==-1)
	{
		count_time++;
		Last_tick=SecondTick;
		return;
	}
	else
		{
			if(SecondTick==!Last_tick&&count_time!=-1)
				{
					count_time++;
					Last_tick=SecondTick;	
				}
			if(count_time!=-1)
				{	
					char showstr[10]={0};
					sprintf (showstr,"%03d ",600-count_time);
					oled_set_font( u8g2_font_logisoso50_tn);
					oled_draw_str(28,53,showstr);	
				}
	
		}	
}



/*********************************************************************

ESP Function

************************************************************************/
uint8_t ErrorCode1=0;
uint8_t Times=0;
uint8_t ErrorCode2=0;
void UserItem_Init_6(void)
{
	//ErrorCode1=esp8266_start_trans();
	time_start = get_ticks();
	//time_start2 = Get_RTC_Sec();
}
void UserItem_Exit_6(void)
{
	 ErrorCode1=0;
	ErrorCode2=0;
	Times=0;
}

void UserItem_Loop_6(void)
{
	//Refresh_RTC_Struct();
	//static uint8_t Times;
	if(Times==0) 
	{
		ErrorCode1=esp8266_start_trans();
			
		HAL_Delay(1000);       
		HAL_Delay(1000);
		ErrorCode2=esp8266_ask_time();

	}
	Times=1;
	//ErrorCode1=esp8266_start_trans();
	uint32_t _time = get_ticks();
	oled_set_font(u8g2_font_wqy12_t_chinese1);
	switch (ErrorCode1)
	{
		case 01:
			oled_draw_str(5,10,"Error:01,AP");	
		break;
		case 02:
			oled_draw_str(5,10,"Error:02,RST");	
		break;
		case 03:
			oled_draw_str(5,10,"Error:03,Code");
		break;
		case 04:
			oled_draw_str(5,10,"Error:04,WebSite");
		break;
		case 05:
			oled_draw_str(5,10,"Error:05,Echo");
		break;
		case 10:
			oled_draw_str(5,10,"Init Successfully");
		break;
	}
	//static uint8_t ErrorCode2;
	if ((_time-time_start)%1000==0)
	{
		ErrorCode2=esp8266_ask_time();
		
	}
		if(ErrorCode2==2)
			oled_draw_str(5,25,"Error:asktime");
		if(ErrorCode2==1)
			oled_draw_str(5,25,"AskTime Successfully");
}

/*********************************************************************

show date

************************************************************************/
void UserItem_Init_7(void)
{

}

void UserItem_Exit_7(void)
{
	oled_set_font(u8g2_font_wqy12_t_chinese1);
}

void UserItem_Loop_7(void)
{

	oled_set_font( u8g2_font_crox5t_tf);

	oled_draw_str(2,35,week1);
	oled_draw_str(52,35,month1);
	oled_draw_str(95,35,date1);
	oled_set_font(u8g2_font_crox2t_tn);
	oled_draw_str(53,58,year1);
//	oled_draw_str(5,35,"Sat");
//	oled_draw_str(50,35,"Jun");
//	oled_draw_str(95,35,"4");
	//oled_draw_str(45,40,year1);
	
}