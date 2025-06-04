/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "astra_ui_core.h"
#include "astra_ui_draw_driver.h"
#include "astra_ui_item.h"
#include "UserItem.h"
#include "stdbool.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8g2_gpio_and_delay_stm32(U8X8_UNUSED u8x8_t *u8x8, U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int, U8X8_UNUSED void *arg_ptr);
int16_t Hours=0;
int16_t Minutes=0;
int16_t Seconds=0;

char RxBuffer[2048]={0};
uint16_t Uart1_Rx_Cnt=0;
uint8_t aRxBuffer=0;
char my_order[15]={0};
char receive_flag=0;

bool Hour_Setting_Flag=false;
bool Minute_Setting_Flag=false;
bool Second_Setting_Flag=false;

char* week=NULL;
char* month=NULL;
char* date=NULL;
char* year=NULL;
char* whole=NULL;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_USART1_UART_Init();
  MX_I2C3_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);
  astra_ui_driver_init();
  astra_init_core();
  HAL_Delay(1000);
// ����������б���
astra_list_item_t *item1 = astra_new_list_item("Setting");
astra_list_item_t *item1_1 = astra_new_slider_item("Hours", &Hours, 1, 0, 23);
astra_list_item_t *item1_2 = astra_new_slider_item("Minutes", &Minutes, 1, 0, 59);
astra_list_item_t *item1_3 = astra_new_slider_item("Seconds", &Seconds, 1, 0, 59);
//astra_list_item_t *item1_1 =astra_new_list_item("BeiJing"); 
//astra_list_item_t *item1_2 = astra_new_list_item("Paris");
//astra_list_item_t *item1_3 =astra_new_list_item("New York");
//HAL_Delay(1000);
astra_list_item_t *item2 = astra_new_list_item("Clock System");
astra_list_item_t *item2_1 = astra_new_list_item("24");
astra_list_item_t *item2_2 =  astra_new_list_item("12");
//astra_list_item_t *item2_3 =  astra_new_list_item("24");
astra_list_item_t *item3 = astra_new_list_item("Count Down");
astra_list_item_t *item3_1 = astra_new_user_item("1 mins",UserItem_Init_2,UserItem_Loop_2,UserItem_Exit_2);
astra_list_item_t *item3_2 = astra_new_user_item("2 mins",UserItem_Init_3,UserItem_Loop_3,UserItem_Exit_3);
astra_list_item_t *item3_3 = astra_new_user_item("5 mins",UserItem_Init_4,UserItem_Loop_4,UserItem_Exit_4);
astra_list_item_t *item3_4 = astra_new_user_item("10 mins",UserItem_Init_5,UserItem_Loop_5,UserItem_Exit_5);
astra_list_item_t *item4 = astra_new_user_item("Clock",UserItem_Init_1,UserItem_Loop_1,UserItem_Exit_1);
astra_list_item_t *item5 = astra_new_user_item("Time Check",UserItem_Init_6,UserItem_Loop_6,UserItem_Exit_6);
astra_list_item_t *item6 = astra_new_user_item("Date",UserItem_Init_7,UserItem_Loop_7,UserItem_Exit_7);
//astra_list_item_t *item2 = astra_new_switch_item("Switch", &switch_value);
astra_push_item_to_list(astra_get_root_list(), item1);
astra_push_item_to_list(item1, item1_1);
astra_push_item_to_list(item1, item1_2);
astra_push_item_to_list(item1, item1_3);
astra_push_item_to_list(astra_get_root_list(), item2);

astra_push_item_to_list(item2, item2_1);
astra_push_item_to_list(item2, item2_2);
astra_push_item_to_list(astra_get_root_list(), item3);
astra_push_item_to_list(item3, item3_1);
astra_push_item_to_list(item3, item3_2);
astra_push_item_to_list(item3, item3_3);
astra_push_item_to_list(item3, item3_4);
astra_push_item_to_list(astra_get_root_list(), item5);
astra_push_item_to_list(astra_get_root_list(), item4);
astra_push_item_to_list(astra_get_root_list(), item6);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  oled_clear_buffer();
	  //in_astra();
		astra_ui_main_core();
		astra_ui_widget_core();
	  oled_send_buffer();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
 if (huart->Instance == USART1)
 {
	if(Uart1_Rx_Cnt >= 2043)  //溢出判断
	{
		Uart1_Rx_Cnt = 0;
		memset(RxBuffer,0x00,sizeof(RxBuffer));	        
	}
	else
	{
		static uint8_t Uart1_count=0;
		
		RxBuffer[Uart1_Rx_Cnt] = aRxBuffer;   //接收数据转存
		if(receive_flag==0)
		{
			if(RxBuffer[Uart1_Rx_Cnt-Uart1_count]=='<')
			{	
				Uart1_count++;
				if((RxBuffer[Uart1_Rx_Cnt]=='>')||Uart1_count>=14)
				{
					uint8_t My_i=0;
					for(int i=Uart1_Rx_Cnt-Uart1_count+1;i<Uart1_Rx_Cnt+1;i++)
						my_order[My_i++]=RxBuffer[i];
					receive_flag=1;
					Uart1_count=0;
				}
			}
		}
		Uart1_Rx_Cnt++;
	} 
 }
	
HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1) ;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
