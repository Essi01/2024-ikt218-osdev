#ifndef IO_H
#define IO_H

#include "stdint.h"

unsigned char inb(uint16_t port);
void outb(uint16_t port, unsigned char data);

#endif // IO_H

