/* USER CODE BEGIN Header */

/*This project is a test script for communication with the ADXL345 accelerometer sensor*/
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SAMPLE_TIME 20


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

uint8_t data_rec[6];

uint16_t x, y, z;

uint8_t chipid;


void adxl_write(uint8_t reg, uint8_t value){ //write data to specified register of peripheral device
	uint8_t data[2];
	data[0] = reg;
	data[1] = value;
	HAL_I2C_Master_Transmit(&hi2c1, hi2c1.Init.OwnAddress1, data, 2, 10); // (I2C_HandleTypeDef * hi2c, uint16_t DevAddress, uint8_t * pData, uint16_t Size, uint32_t Timeout)
}

//void adxl_read(uint8_t reg, uint8_t numberofbytes){
//	HAL_I2C_Mem_Read(&hi2c1, hi2c1.Init.OwnAddress1, reg, 1, &data_rec[0], numberofbytes, 100);
//}


void adxl_read_values (uint8_t reg)
{
	HAL_I2C_Mem_Read (&hi2c1, hi2c1.Init.OwnAddress1, reg, 1, (uint8_t *)data_rec, 6, 100);
}

void adxl_read_address (uint8_t reg)
{
	HAL_I2C_Mem_Read (&hi2c1, hi2c1.Init.OwnAddress1, reg, 1, &chipid, 1, 100);
}

void adxl_init(){

//	if (HAL_I2C_IsDeviceReady(&hi2c1, hi2c1.Init.OwnAddress1, 3, 1000) != HAL_OK){ //tries initialization for 3 times during 1s each
//		Error_Handler(); //peripheral not initialized
//	}
//	else{
		adxl_read_address(0x00); //data_rec[0] should be 0xE5

//		adxl_write(0x2d, 0); //reset all POWER_CTL bits
//		adxl_write(0x2d, 0x08); //writes 1000 (measure-bit set to 1)
//		adxl_write(0x31, 0x00); // +- 2g range

//	}

}

//void ADXL_Init(){ //initialization function
//	ADXL_OK = 0;
//	/*if (HAL_I2C_IsDeviceReady(&hi2c1, hi2c1.Init.OwnAddress1, 3, 1000) != HAL_OK){ //tries initialization for 3 times during 1s each
//		ADXL_OK = 0x01;
//		Error_Handler(); //peripheral not initialized
//	}
//	else{
//		ADXL_Read(0x00, 1);  //must read a fixed value of 0xE5
//		ADXL_OK = 0x02;
//		if (data_rec[0] != 0xE5){ //device not working properly
//			Error_Handler();
//		}
//		else{
//			//initial device configuration
//			ADXL_Write(0x2D, 0); //reset all POWER_CTL bits
//			ADXL_Write(0x2D, 0x08); //writes 1000 (measure-bit set to 1)
//			ADXL_Write(0X31, 0X00); // +- 2g range
//		}
//	}*/
//
//	ADXL_Read(0x00, 1);
//	ADXL_Write(0x2D, 0); //reset all POWER_CTL bits
//	ADXL_Write(0x2D, 0x08); //writes 1000 (measure-bit set to 1)
//	ADXL_Write(0X31, 0X00); // +- 2g range
//
//}
//
//void Read_Axis_Values(void){
//	ADXL_Read(0x32, 6); //read from registers 0x32 to 0x37
//
//	//raw values
//	x_raw = (data_rec[1]<<8) | data_rec[0]; //shifting of Most Significant Byte and concatenation with Least Significant Byte
//	y_raw = (data_rec[3]<<8) | data_rec[2];
//	z_raw = (data_rec[5]<<8) | data_rec[4];
//
//	//scaled values
//	x_reading = x_raw*0.0039; //multiplication by scale factor, readings in g
//	y_reading = x_raw*0.0039;
//	z_reading = x_raw*0.0039;
//}

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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  adxl_init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
//	adxl_read(0x32, 6);
//	x = (data_rec[1]<<8) | data_rec[0];
//	y = (data_rec[3]<<8) | data_rec[2];
//	z = (data_rec[5]<<8) | data_rec[4];

	HAL_Delay(10);

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

  /**Initializes the CPU, AHB and APB busses clocks 
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
  /**Initializes the CPU, AHB and APB busses clocks 
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
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 166;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

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
	int i = 0;
	for(i=0;i<3;i++){
		printf("debug");
	}
//  switch (ADXL_OK){
//	  case 0x01:
//		  HAL_I2C_DeInit(&hi2c1);//close i2c communication with ADXL (by disabling SCLK)
//		  //send via serial to display/memory card/bt that device could not be initialized
//		  break;
//	  case 0x02:
//		  HAL_I2C_DeInit(&hi2c1);//close i2c communication with ADXL (by disabling SCLK)
//		  //send via serial to display/memory card/bt that device is not working properly
//		  break;
//  }

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
