/*
 * MQTT.c
 *
 *  Created on: Apr 27, 2022
 *      Author: MahmoudH
 */

#include "MQTT.h"
/*
Assumptions:
1) Packet Rem Len <= 127  = 0111 1111 in one byte
2) QoS 0,1 in pub packets
 */

u8 packet[150] = {0};
u8 packetInd = 0;

u16 packetID = 1;


void MQTT_Connect(u8* clientID){
	u8 remLen = (12 +  strlen(clientID));
	packetInd = 0;
	packet[packetInd++] = 0x10;
	packet[packetInd++] = remLen;
	packet[packetInd++] = 0x00;
	packet[packetInd++] = 0x04;

	strcpy(packet+packetInd,"MQTT");
	packetInd += strlen("MQTT");

	packet[packetInd++] = 0x04;
	packet[packetInd++] = 0x02;
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0xFF;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(clientID);
	strcpy(packet+packetInd,clientID);
	packetInd +=  strlen(clientID);
	// send packet to UART
	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
	MUART_u8SendData(6, packet, packetInd);
}
void MQTT_Subscribe(u8* topic){
	u8 remLen = 5 + strlen(topic);
	packetInd = 0;
	packet[packetInd++] = 0x82;
	packet[packetInd++] = remLen;

	packet[packetInd++] = packetID>>8;
	packet[packetInd++] = packetID;
	packetID++;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = (u8) strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += (u8) strlen(topic);

	packet[packetInd++] = 0x01;
	// send packet to UART
	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
	MUART_u8SendData(6, packet, packetInd);
}
void MQTT_Publish(u8* topic, u8* msg, u8 QoS){
	u8 remLen = 2 + strlen(topic) + strlen(msg);
	packetInd = 0;

	if(QoS == 1){
		packet[packetInd++] = 0x32;
		remLen += 2;
	}else{
		packet[packetInd++] = 0x30;
	}

	packet[packetInd++] = remLen;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	if(QoS > 0){
		packet[packetInd++] = packetID>>8;
		packet[packetInd++] = packetID;
		packetID++;
	}
	strcpy(packet+packetInd,msg);
	packetInd += strlen(msg);
	// send packet to UART
	//HAL_UART_Transmit(&huart6, packet, packetInd, packetInd*2);
	MUART_u8SendData(6, packet, packetInd);
}
