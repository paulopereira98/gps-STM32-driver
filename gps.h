/*
	GPS NMEA driver for stm32 and FreeRTOS.
	Copyright (C) 2019  Paulo Pereira	(EEIC-UMinho)
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @file gps.h
 * @brief GPS NMEA driver for stm32 and FreeRTOS.
 */

#ifndef _GPS_H_
#define _GPS_H_

#include "stdint.h"

#define GPS_UART_HANDLER  huart2

//maximum delay before availability is set to unavailable
#define GPS_AVAILABLE_TIMEOUT  60 //seconds

enum gps_return 
{
	GPS_FAIL = 0,
	GPS_SUCESS
};

typedef struct
{
	float	latitude;
	float	longitude;
}gps_t;


void	gps_init(void);
uint8_t gps_valid(gps_t);
uint8_t gps_available(void);
gps_t 	gps_read(void);
void	gps_CallBack(void);
void	vGps_taskFunction(void const * argument);


#endif
