#ifndef _UART_H
#define _UART_H

#define UART0_BASE      0x3F201000  // UART0 base address

// UART Register Offsets (from UART0_BASE)
#define UART0_DR        (UART0_BASE + 0x00)  // Data Register
#define UART0_FR        (UART0_BASE + 0x18)  // Flag Register
#define UART0_IBRD      (UART0_BASE + 0x24)  // Integer Baud Rate Divisor
#define UART0_FBRD      (UART0_BASE + 0x28)  // Fractional Baud Rate Divisor
#define UART0_LCRH      (UART0_BASE + 0x2C)  // Line Control Register
#define UART0_CR        (UART0_BASE + 0x30)  // Control Register
#define UART0_IMSC      (UART0_BASE + 0x38)  // Interrupt Mask Set/Clear Register
#define UART0_ICR       (UART0_BASE + 0x44)  // Interrupt Clear Register

void uart_init(unsigned int baud_rate);
char uart_recv(void);
void uart_send(char c);
void uart_send_string(char* str);

#endif  /* _UART_H */
