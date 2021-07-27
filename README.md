# gps-STM32-driver
GPS NMEA driver for stm32 and FreeRTOS.

&nbsp;
&nbsp;
&nbsp;

### [Open Documentation](https://paulopereira98.github.io/gps-STM32-driver/gps_8h.html)
&nbsp;
### How to use:


##### Set the uart handler where the gps module is connected:
```c
/* gps.h */
//Replace the uart handler with the one you are using
#define GPS_UART_HANDLER  huart2
```

##### Declare the gps task and create it in the MX_FREERTOS_Init() definition:
```c
/* freertos.c */
#include "gps.h" //include gps module
/* ... */ 

//Declare extern task
extern void vGps_taskFunction(void const * argument);
/* ... */

void MX_FREERTOS_Init(void) {
  /* ... */

  /* Create the thread(s) */
  /* ... */

  /* definition and creation of taskGps */
  osThreadDef(taskGps, vGps_taskFunction, osPriorityNormal, 0, 1024);
  taskGpsHandle = osThreadCreate(osThread(taskGps), NULL);
 
  /* ... */
}
```

##### Add the gps_CallBack() function to the usart callback:
```c
/* usart.c */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
  /* ... */
  if (huart->Instance == GPS_UART_HANDLER.Instance)
  {
    gps_CallBack(); 
  }
  /* ... */
}
```





##### Usage:
```c

/* Include gps module */
#include "gps.h"

/* Call init function at startup */
gps_init(void);

gps_t myGPS;

while(1)
{
  if( gps_available() )
  {
    myGPS = gps_read(); 
    printf("Latitude: %.2f  Longitude %.2f \r\n", myGPS.latitude, myGPS.longitude);
  }
  
  osDelay(5000);
}



```

