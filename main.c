//******************************************************************************
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "discoveryf4utils.h"
//******************************************************************************

//******************************************************************************
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "croutine.h"
//******************************************************************************

void vLedBlinkBlue(void *pvParameters);
void vLedBlinkRed(void *pvParameters);
void vLedBlinkGreen(void *pvParameters);
void vLedBlinkOrange(void *pvParameters);

#define STACK_SIZE_MIN	130	/* usStackDepth	- the stack size DEFINED IN WORDS.*/


//******************************************************************************
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured,
	   this is done through SystemInit() function which is called from startup
	   file (startup_stm32f4xx.s) before to branch to application main.
	   To reconfigure the default setting of SystemInit() function, refer to
	   system_stm32f4xx.c file
	 */
	const signed char vLedBlinkBlueStr[] = {"Led Blink Task Blue"};
	const signed char vLedBlinkRedStr[] = {"Led Blink Task Red"};
	const signed char vLedBlinkGreenStr[] = {"Led Blink Task Green"};
	const signed char vLedBlinkOrangeStr[] = {"Led Blink Task Orange"};
	
	STM_EVAL_LEDInit(LED_BLUE);
	STM_EVAL_LEDInit(LED_GREEN);
	STM_EVAL_LEDInit(LED_ORANGE);
	STM_EVAL_LEDInit(LED_RED);
	
	xTaskCreate( vLedBlinkBlue, vLedBlinkBlueStr, STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vLedBlinkRed, vLedBlinkRedStr, STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vLedBlinkGreen, vLedBlinkGreenStr, STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vLedBlinkOrange, vLedBlinkOrangeStr, STACK_SIZE_MIN, NULL, tskIDLE_PRIORITY, NULL );
	
	vTaskStartScheduler();
}
//******************************************************************************

//******************************************************************************
void vLedBlinkBlue(void *pvParameters)
{
	for(;;)
	{
		STM_EVAL_LEDToggle(LED_BLUE);
		vTaskDelay( 500 / portTICK_RATE_MS );
	}
}


void vLedBlinkRed(void *pvParameters)
{
	for(;;)
	{
		STM_EVAL_LEDToggle(LED_RED);
		vTaskDelay( 456 / portTICK_RATE_MS );
	}
}

void vLedBlinkGreen(void *pvParameters)
{
	for(;;)
	{
		STM_EVAL_LEDToggle(LED_GREEN);
		vTaskDelay( 234 / portTICK_RATE_MS );
	}
}

void vLedBlinkOrange(void *pvParameters)
{
	for(;;)
	{
		STM_EVAL_LEDToggle(LED_ORANGE);
		vTaskDelay( 890 / portTICK_RATE_MS );
	}
}
//******************************************************************************

