#include "utils.h"
#include "peripherals/uart.h"
#include "peripherals/gpio.h"

void uart_send(char c) 
{
  while (get32(UARTFR) & 0x20) {	// wait if TX full
  } 

  put32(UARTDR, c);					// when empty, send next char
}

//sending string 
void uart_send_string(char *str) 
{
  for (int i = 0; str[i] != '\0'; i++) 
  {
    uart_send((char)str[i]);
  }
}

char uart_recv(void) 
{
  while (get32(UARTFR) & 0x10) { // wait if RX empty
  }      

  return (get32(UARTDR) & 0xFF); // get recived char
}

void uart_init(void) 
{
  unsigned int selector;
  selector = get32(GPFSEL1);
  selector &= ~(7 << 12);		// clean gpio14
  selector |= 4 << 12;			// set alt0 for gpio14
  selector &= ~(7 << 15);		// clean gpio15
  selector |= 4 << 15;			// set alt0 for gpio15

  put32(GPFSEL1, selector);
  put32(GPPUD, 0);
  delay(150);
  put32(GPPUDCLK0, (1 << 14) | (1 << 15));
  delay(150);
  put32(GPPUDCLK0, 0);
  put32(UARTCR, 0);						// disable TX and RX to start setup
  put32(UARTIBRD, 26);					// set baud rate to 115200 with clock 48Mhz
  put32(UARTFBRD, 3);					// set baud rate decimal precision
  put32(UARTLCRLCRH, 0x60);				// set 8 bit word length
  put32(UARTCR, 0x301);					// renable TX and RX
}