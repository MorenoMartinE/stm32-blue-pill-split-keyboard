/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"
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
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  typedef struct {
	    uint8_t MODIFIER;
      	uint8_t RESERVED;
      	uint8_t KEYCODE01;
      	uint8_t KEYCODE02;
      	uint8_t KEYCODE03;
      	uint8_t KEYCODE04;
      	uint8_t KEYCODE05;
      } keyboardReportsDes;

      keyboardReportsDes HIDKeyboard = {0,0,0,0,0,0,0};

      short control = 0;
      /* Infinite loop */
      /* USER CODE BEGIN WHILE */
      while (1)
      {
    	  uint8_t *ptr_key = &HIDKeyboard.KEYCODE01;
    	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
    	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);

    	    control = 0;
    	    HIDKeyboard.MODIFIER = 0X00;
      		if (!(HAL_GPIO_ReadPin(C7_GPIO_Port, C7_Pin))){
    			HIDKeyboard.MODIFIER = 0X02;
      		}

      		if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
      			control = 1;
      		}

      		if (!(HAL_GPIO_ReadPin(C5_GPIO_Port, C5_Pin))){
      			HIDKeyboard.MODIFIER = HIDKeyboard.MODIFIER + 0X01;
    		}

      		if (!(HAL_GPIO_ReadPin(C6_GPIO_Port, C6_Pin))){
      			HIDKeyboard.MODIFIER = HIDKeyboard.MODIFIER + 0X04;
      		}

      		if (!(HAL_GPIO_ReadPin(C8_GPIO_Port, C8_Pin))){
      			control = 4;
      		}

      		if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)) && !(HAL_GPIO_ReadPin(C6_GPIO_Port, C6_Pin))){
      			HIDKeyboard.MODIFIER = 0X08;
			}

    	  	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
    	  	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

				if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X14;
						break;
					case 1:
						*ptr_key = 0X1E;
						break;
					case 4:
						*ptr_key = 0x3A;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

				if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0x1A;
							break;
						case 1:
							*ptr_key = 0X1F;
							break;
						case 4:
							*ptr_key = 0x3B;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

				if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X08;
							break;
						case 1:
							*ptr_key = 0X20;
							break;
						case 4:
							*ptr_key = 0x3C;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}


				if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X15;
							break;
						case 1:
							*ptr_key = 0X21;
							break;
						case 4:
							*ptr_key = 0x3D;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

			   if (!(HAL_GPIO_ReadPin(C5_GPIO_Port, C5_Pin))){
					switch(control){

						case 0:
							*ptr_key = 0X17;
							break;
						case 1:
							*ptr_key = 0X22;
							break;
					 }
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
			   }

			   if (!(HAL_GPIO_ReadPin(C6_GPIO_Port, C6_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X1C;
							break;
						case 1:
							*ptr_key = 0X23;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

			   if (!(HAL_GPIO_ReadPin(C7_GPIO_Port, C7_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X18;
							break;
						case 1:
							*ptr_key = 0X24;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

			   if (!(HAL_GPIO_ReadPin(C8_GPIO_Port, C8_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X0C;
							break;
						case 1:
							*ptr_key = 0X25;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

			   if (!(HAL_GPIO_ReadPin(C9_GPIO_Port, C9_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X12;
							break;
						case 1:
							*ptr_key = 0X26;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

			   if (!(HAL_GPIO_ReadPin(C10_GPIO_Port, C10_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X13;
							break;
						case 1:
							*ptr_key = 0X27;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
			   }

    	  	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
    	  	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

				if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X04;
							break;
						case 1:
							*ptr_key = 0X29;
							break;
						case 4:
							*ptr_key = 0x3E;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X16;
						break;
					case 4:
						*ptr_key = 0x3F;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X07;
						break;
					case 4:
						*ptr_key = 0x40;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X09;
						break;
					case 4:
						*ptr_key = 0x41;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C5_GPIO_Port, C5_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X0A;
						break;
					case 4:
						*ptr_key = 0x42;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C6_GPIO_Port, C6_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X0B;
							break;
						case 1:
							*ptr_key = 0X2F;
							break;
						case 4:
							*ptr_key = 0X50;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C7_GPIO_Port, C7_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X0D;
							break;
						case 1:
							*ptr_key = 0X30;
							break;
						case 4:
							*ptr_key = 0X51;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C8_GPIO_Port, C8_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X0E;
							break;
						case 1:
							*ptr_key = 0X31;
							break;
						case 4:
							*ptr_key = 0X52;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C9_GPIO_Port, C9_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X0F;
							break;
						case 1:
							*ptr_key = 0X2D;
							break;
						case 4:
							*ptr_key = 0X4F;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C10_GPIO_Port, C10_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X33;
							break;
						case 1:
							*ptr_key = 0X2E;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

    	  	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
    	  	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

			    if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X1D;
						break;
					case 4:
						*ptr_key = 0x43;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X1B;
						break;
					case 4:
						*ptr_key = 0x44;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
					switch(control){
					case 0:
						*ptr_key = 0X06;
						break;
					case 4:
						*ptr_key = 0x45;
						break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
					*ptr_key = 0X19;
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C5_GPIO_Port, C5_Pin))){
					*ptr_key = 0X05;
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C6_GPIO_Port, C6_Pin))){
					*ptr_key = 0X28;
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C7_GPIO_Port, C7_Pin))){
					*ptr_key = 0X11;
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}
				if (!(HAL_GPIO_ReadPin(C8_GPIO_Port, C8_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X10;
							break;
						case 1:
							*ptr_key = 0X32;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

				if (!(HAL_GPIO_ReadPin(C9_GPIO_Port, C9_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X36;
							break;
						case 1:
							*ptr_key = 0X34;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

				if (!(HAL_GPIO_ReadPin(C10_GPIO_Port, C10_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X37;
							break;
						case 1:
							*ptr_key = 0X2B;
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

    	  	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
    	  	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);


				if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
					*ptr_key = 0X2C;
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

				if (!(HAL_GPIO_ReadPin(C10_GPIO_Port, C10_Pin))){
					switch(control){
						case 0:
							*ptr_key = 0X38;
							break;
						case 1:
							if(HIDKeyboard.MODIFIER == 0x02){
								*ptr_key = 0X3F;
							}else{
								*ptr_key = 0X2A;
							}
							break;
					}
					if(ptr_key != &HIDKeyboard.KEYCODE05)
					{
						ptr_key++;
					}else{
						ptr_key = &HIDKeyboard.KEYCODE01;
					}
				}

		USBD_HID_SendReport(&hUsbDeviceFS,&HIDKeyboard,sizeof(HIDKeyboard));
		HAL_Delay(25);
		HIDKeyboard.KEYCODE01 = 0x00;
		HIDKeyboard.KEYCODE02 = 0x00;
		HIDKeyboard.KEYCODE03 = 0x00;
		HIDKeyboard.KEYCODE04 = 0x00;
		HIDKeyboard.KEYCODE05 = 0x00;

      /* USER CODE END 3 */

    /* USER CODE END 3 */
    }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R4_Pin|R3_Pin|R2_Pin|R1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : C4_Pin C3_Pin C7_Pin C10_Pin
                           C2_Pin C1_Pin */
  GPIO_InitStruct.Pin = C4_Pin|C3_Pin|C7_Pin|C10_Pin
                          |C2_Pin|C1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : R4_Pin R3_Pin R2_Pin R1_Pin */
  GPIO_InitStruct.Pin = R4_Pin|R3_Pin|R2_Pin|R1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : C9_Pin C8_Pin C6_Pin C5_Pin */
  GPIO_InitStruct.Pin = C9_Pin|C8_Pin|C6_Pin|C5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
