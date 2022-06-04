/*
 * MQTT.h
 *
 *  Created on: Apr 27, 2022
 *      Author: MahmoudH
 */

#ifndef INC_MQTT_H_
#define INC_MQTT_H_

#include "STD_TYPES.h"
#include "UART_interace.h"
#include "string.h"
#include "stdint.h"

void MQTT_Connect(uint8_t* clientID);
void MQTT_Subscribe(uint8_t* topic);
void MQTT_Publish(uint8_t* topic, uint8_t* msg, uint8_t QoS);

#endif /* INC_MQTT_H_ */
