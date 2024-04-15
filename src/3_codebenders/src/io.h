#ifndef IO_H
#define IO_H

#include "stdint.h"

// Writes a byte to the specified port
void outb(uint16_t port, uint8_t val);

// Reads a byte from the specified port
uint8_t inb(uint16_t port);

#endif // IO_H
