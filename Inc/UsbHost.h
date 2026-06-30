/*
 * UsbHost.h
 *
 * Created: 10/21/2023 10:31:28 PM
 *  Author: Renan
 */ 


#ifndef USBHOST_H_
#define USBHOST_H_

#include <stdint.h>
#include <string.h>


#define USB_PID_SETUP   0x2D
#define USB_PID_DATA0   0xC3
#define USB_PID_DATA1   0x4B
#define USB_PID_IN      0x69
#define USB_PID_OUT     0xE1
#define USB_PID_ACK     0xD2

#define USB_UPDATE_TIME_TRIGGER 10

typedef struct
{
    uint8_t data[12];
} USBPacket;

typedef struct
{
    uint32_t pid      : 8;
    uint32_t addr     : 7;
    uint32_t endpoint : 4;
    uint32_t crc5     : 5;
} USBToken;

extern uint8_t usbconnected;
extern uint8_t usbdata[];
extern volatile uint8_t usbdatalen;

extern void USB_SendTokenPacket(uint8_t size, USBToken *data);
extern void USB_SendBytes(uint8_t size, uint8_t *data);
extern uint8_t USB_ReceiveBytes(uint8_t *data);
extern uint8_t USB_ReceiveBytesAck(uint8_t *data);
extern uint8_t USB_AppendCRC5(USBToken *token);

extern void fUSB_Delay_1us();
extern void fUSB_Delay_10ms();
extern void fUsb_setMode_Reset();
extern void fUsb_setMode_Input();
extern void fUsb_setMode_Output();

void USB_reset();
void USB_keep_alive();
void USB_Update();

void JoyUSB_init();
void joyUSB_read();

uint8_t USB_PacketIn(uint8_t pos_len, uint8_t *ptrOut);
int USB_PacketOut(uint8_t size, uint8_t *data);
int USB_PacketSetup(uint8_t size, uint8_t *data);
void USB_setTokenAddr(uint8_t addr);
void USB_setTokenEndpoint(uint8_t endpoint);

#endif /* USBHOST_H_ */
