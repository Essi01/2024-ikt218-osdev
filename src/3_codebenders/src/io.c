// io.h
#ifndef IO_H
#define IO_H

unsigned char inb(unsigned short port);
void outb(unsigned short port, unsigned char data);

#endif // IO_H

// io.c
#include "io.h"

unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ volatile ("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__ volatile ("out %%al, %%dx" : : "a" (data), "d" (port));
}
