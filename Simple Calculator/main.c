#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h""
#include "KeyPad.h"
#include "LCD.h"


void LCDTask(void *pvParameters);
void KeyPadTask(void *pvParameters);

xSemaphoreHandle xBinarySemaphore ;
portBASE_TYPE xMutex;

uint8 data = 0;
uint8 dataop[4] = {0};

int main(){
	vSemaphoreCreateBinary(xBinarySemaphore);
	xTaskCreate( KeyPadTask, "KeyPad", 240, NULL, 1, NULL );
	xTaskCreate( LCDTask, "LCD", 240, NULL, 1, NULL );
	
	
	vTaskStartScheduler();
	for (;;);
}

void LCDTask(void *pvParameters){
	LCD_Init();
	int index = 0;
	LCD_Cmd(CLEAR_DISPLAY);
	uint8 prevData = 0;
	int sum = 0;
	for( ;; ){
		if((data != prevData) && (data != 0)){
			LCD_Char(data);
			prevData = data;
			dataop[index++] = data;
			if(data == 'D'){
				LCD_Clear();
				index = 0;
			}
			if(data == '='){
				switch(dataop[1]){
					case '+':
						sum = (dataop[0] - '0') + (dataop[2] - '0');
						break;
					case '-':
						sum = (dataop[0] - '0') - (dataop[2] - '0');
						break;
					default:
						sum = 0;
						break;
					
				}
				
				LCD_Write_Int(sum);
				index = 0;
				LCD_GoToString(0,0, " ");
			}
		}
	}
}

void KeyPadTask(void *pvParameters){
	keypadInit();
	for( ;; ){
		xSemaphoreTake(xBinarySemaphore , portMAX_DELAY);
		data = keypadGetKey();
		xSemaphoreGive( xBinarySemaphore );
	}
}