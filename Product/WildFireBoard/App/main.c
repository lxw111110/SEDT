/**
  ******************************************************************************
  * @file    main.c 
  * @author L
  * @date    2019-12-28
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------ */
#include "stm32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t uwTimingDelay;
TaskHandle_t xHandle = NULL;

/* Private function prototypes -----------------------------------------------*/
void vTaskCode(void *param);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    static uint8_t ucParameterToPass;

    xTaskCreate(vTaskCode, "Main", 0x400, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle);
    configASSERT(xHandle);

    vTaskStartScheduler();
    while(1) {
        ;
    }
}

void vTaskCode(void *param)
{
    uwTimingDelay++;
    // Use the handle to delete the task.
    if(xHandle != NULL && uwTimingDelay != 0) {
        vTaskDelete(xHandle);
    }
    return;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

