#ifndef	_P_UART_H
#define	_P_UART_H
#include "peripherals/base.h"

//for easy reading
#define UARTBASE (0x201000 + PBASE)

//define needed UART registers
#define UARTIBRD		(UARTBASE+0x24)
#define UARTDR			(UARTBASE+0x0)
#define UARTFBRD		(UARTBASE+0x28)
#define UARTFR			(UARTBASE+0x18)
#define UARTLCRLCRH 	(UARTBASE+0x2C)
#define UARTCR			(UARTBASE+0x30)

#endif  /*_P_UART_H */