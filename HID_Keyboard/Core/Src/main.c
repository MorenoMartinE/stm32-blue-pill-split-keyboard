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
#include "usb_hid_keys.h"

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
	//Esta estructura es para manejar mas facilmente los pines
  	typedef struct {
		uint32_t Pin,
		uint32_t GPIO_Port
	} stm32GPIO;
	//Estructura del reporte que se envia por protocolo HID a la computadora
  	typedef struct {
	    uint8_t MODIFIER;
      	uint8_t RESERVED;
      	uint8_t KEYCODE01;
      	uint8_t KEYCODE02;
      	uint8_t KEYCODE03;
      	uint8_t KEYCODE04;
      	uint8_t KEYCODE05;
      	uint8_t KEYCODE06;
	} keyboardReportsDes;

	//Inicializacion de la esttructura con los pins de las filas
	stm32GPIO GPIORows[] = {
		{R1_Pin, R1_GPIO_Port},
		{R2_Pin, R2_GPIO_Port},
		{R3_Pin, R3_GPIO_Port},
		{R4_Pin, R4_GPIO_Port}
	};

	//Inicializacion de la esttructura con los pins de las columnas
	stm32GPIO GPIOCols[] = {
		{C1_Pin, C1_GPIO_Port},
		{C2_Pin, C2_GPIO_Port},
		{C3_Pin, C3_GPIO_Port},
		{C4_Pin, C4_GPIO_Port},
		{C5_Pin, C5_GPIO_Port},
		{C6_Pin, C6_GPIO_Port},
		{C7_Pin, C7_GPIO_Port},
		{C8_Pin, C8_GPIO_Port},
		{C9_Pin, C9_GPIO_Port},
		{C10_Pin, C10_GPIO_Port}
	}

	//Inicializacion de la estructura con los pins repetidos para las estructuras de control
	stm32GPIO GPIOControl[] = {
		{C8_Pin, C8_GPIO_Port},
		{C5_Pin, C5_GPIO_Port},
		{C7_Pin, C7_GPIO_Port}
	}

	uint8_t keyMatrix[][][] = {
		{
			{
				{USB_HID_KEYS.Q},{USB_HID_KEYS.K1},{USB_HID_KEYS.F1}
			},
			{
				{USB_HID_KEYS.W},{USB_HID_KEYS.K2},{USB_HID_KEYS.F2}
			},
			{
				{USB_HID_KEYS.E},{USB_HID_KEYS.K3},{USB_HID_KEYS.K3}
			},
			{
				{USB_HID_KEYS.R},{USB_HID_KEYS.K4},{USB_HID_KEYS.F4}
			},
			{
				{USB_HID_KEYS.T},{USB_HID_KEYS.K5},{0x00}
			},
			{
				{USB_HID_KEYS.Y},{USB_HID_KEYS.K6},{0x00}
			},
			{
				{USB_HID_KEYS.U},{USB_HID_KEYS.K7},{0x00}
			},
			{
				{USB_HID_KEYS.I},{USB_HID_KEYS.K8},{0x00}
			},
			{
				{USB_HID_KEYS.O},{USB_HID_KEYS.K9},{0x00}
			},
			{
				{USB_HID_KEYS.P},{USB_HID_KEYS.K0},{USB_HID_KEYS.PRINT}
			}
		},
		{
			{
				{USB_HID_KEYS.A},{USB_HID_KEYS.ESC},{USB_HID_KEYS.F5}
			},
			{
				{USB_HID_KEYS.S},{0x00},{USB_HID_KEYSN.F6}
			},
			{
				{USB_HID_KEYS.D},{0x00},{USB_HID_KEYS.F7}
			},
			{
				{USB_HID_KEYS.F},{0x00},{USB_HID_KEYS.F8}
			},
			{
				{USB_HID_KEYS.G},{0x00},{0x00}
			},
			{
				{USB_HID_KEYS.H},{USB_HID_KEYS.LCORCH},{USB_HID_KEYS.FIZ}
			},
			{
				{USB_HID_KEYS.J},{USB_HID_KEYS.RCORCH},{USB_HID_KEYS.FAB}
			},
			{
				{USB_HID_KEYS.K},{USB_HID_KEYS.BSLASH},{USB_HID_KEYS.FAR}
			},
			{
				{USB_HID_KEYS.L},{USB_HID_KEYS.GUION},{USB_HID_KEYS.FDE}
			},
			{
				{USB_HID_KEYS.PYCOMA},{USB_HID_KEYS.IGUAL},{USB_HID_KEYS.BLOCKM}
			}
		},
		{
			{
				{USB_HID_KEYS.Z},{USB_HID_KEYS.PUP},{USB_HID_KEYS.F9}
			},
			{
				{USB_HID_KEYS.Z},{USB_HID_KEYS.PDN},{USB_HID_KEYS.F10}
			},
			{
				{USB_HID_KEYS.C},{USB_HID_KEYS.HOME},{USB_HID_KEYS.F11}
			},
			{
				{USB_HID_KEYS.V},{USB_HID_KEYS.END},{USB_HID_KEYS.F12}
			},
			{
				{USB_HID_KEYS.B},{0x00},{0x00}
			},
			{
				{USB_HID_KEYS.ENTER},{USB_HID_KEYS.ENTER},{USB_HID_KEYS.ENTER}
			},
			{
				{USB_HID_KEYS.N},{USB_HID_KEYS.APPMENU},{0x00}
			},
			{
				{USB_HID_KEYS.M},{USB_HID_KEYS.BCOMILL},{0x00}
			},
			{
				{USB_HID_KEYS.COMA},{USB_HID_KEYS.COMILLA},{0x00}
			},
			{
				{USB_HID_KEYS.PUNTO},{USB_HID_KEYS.TAB},{0x00}
			}
		},
		{
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{USB_HID_KEYS.SPACE},{USB_HID_KEYS.SPACE},{USB_HID_KEYS.SPACE}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{0x00},{0x00},{0x00}
			},
			{
				{USB_HID_KEYS.SLASH},{BACKS},{DELETE}
			}
		},
		{
			{
				{
					USB_HID_KEYS.SHIFT
				},
				{
					USB_HID_KEYS.SHIFT
				},
				{
					USB_HID_KEYS.SHIFT
				}
			},
			{
				{
					USB_HID_KEYS.CTRL
				},
				{
					USB_HID_KEYS.CTRL
				},
				{
					USB_HID_KEYS.CTRL
				}
			},
			{
				{
					USB_HID_KEYS.ALT
				},
				{
					USB_HID_KEYS.GUI
				},
				{
					USB_HID_KEYS.ALT
				}
			},
		}
	}

	//Inicializacion de la estructura para el reporte HID
	keyboardReportsDes HIDKeyboard = {0,0,0,0,0,0,0,0};

	//Short que se utiliza para definir en que capa del teclado estamos parados
	short control = 0;
	
	//While loop que se ejecuta durante todo el funcionamiento del equipo
	while (1)
	{
		//Este es el puntero que utilizo para cargar los codigos dentro de la estructura de reporte de manera secuencial
		//solo se usa ara los KEYCODE*, los primeros dos bytes se manejan de manera distinta.
		uint8_t *ptr_key = &HIDKeyboard.KEYCODE01;

		//Coloco los pines en la posicion de inicio
		for(int i = 0 ; i < 4; i++)
		{
			if(i == 3)
			{
				HAL_GPIO_WritePin(GPIORows[i].GPIO_Port, GPIORows[i].Pin, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(GPIORows[i].GPIO_Port, GPIORows[i].Pin, GPIO_PIN_SET);
			}
		}

		//Defino la capa donde se esta trabajando segun los dos botones internos que no modifican directametne
		//el reporte de teclad (fnL y fnR)
		if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
			control = USB_HID_KEYS.C1;
		}

		if (!(HAL_GPIO_ReadPin(C9_GPIO_Port, C9_Pin))){
			control = USB_HID_KEYS.C2;
		}

		//Compruebo que botones estan siendo pulsados paca configurar los modificadores y las capas de teclado
		for(int i = 0; i < 3; i++)
		{
			if(!(HAL_GPIO_ReadPin(GPIOControls[i].GPIO_Port, GPIOControls[i].Pin)))
			{
				HIDKeyboard.MODIFIER = keyMatrix[4][i][control] + HIDKeyboard.MODIFIER;
			}
		}



		//for que recorre las filas
		for(int i = 0; i < 4; i++)
		{
			//Este segundo loop anidado se encarga de apagar la corriente de todos los pines que no se tengan que
			//leer durante este ciclo.
			for(int j = 0; j < 4; j++)
			{
				if(i == j)
				{
					HAL_GPIO_WritePin(GPIORows[i].GPIO_Port, GPIORows[i].Pin, GPIO_PIN_RESET);
				}
				else
				{
					HAL_GPIO_WritePin(GPIORows[i].GPIO_Port, R4_Pin, GPIO_PIN_SET);
				}
			}

			//Ahora se realiza un segundo loop que se encarga de recorrer cada una de las columnas,
			//este se corre 10 veces por cada fila. Aparte, si se carga un byte dentro de la estructura
			//de reporte, mueve el puntero adelante hasta llegar al ultimo espacio de memoria, en ese caso
			//vuelve al principio
			for(int h = 0; h < 10; h++)
			{
				if(!(HAL_GPIO_ReadPin(GPIOCols[h].GPIO_Port, GPIOCols[h].Pin)))
				{
					*ptr_key = keyMatrix[i][h][control];

					if(keyMatrix[i][h][control] != 0x00)
					{
						if(ptr_key != &HIDKeyboard.KEYCODE06)
						{
							ptr_key++;
						}
						else
						{
							ptr_key = &HIDKeyboard.KEYCODE01;
						}
					}
				}
			}
		}

		//Envio el reporte por USB
		USBD_HID_SendReport(&hUsbDeviceFS,&HIDKeyboard,sizeof(HIDKeyboard));
		//Espero para que no se pisen los reportes dentro del cable
		HAL_Delay(25);
		//Limpio todas las variabes necesarias antes de que vuelva a arrancar el loop
		//principal de la aplicacion.
		HIDKeyboard = {0,0,0,0,0,0,0,0};
		control = 0;

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
