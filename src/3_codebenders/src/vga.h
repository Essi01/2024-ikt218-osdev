#pragma once

#include "stdint.h"


#define COLOR8_BLACK 0
#define COLOR8_BLUE 1
#define COLOR8_GREEN 2
#define COLOR8_CYAN 3
#define COLOR8_RED 4
#define COLOR8_MAGENTA 5
#define COLOR8_BROWN 6
#define COLOR8_LIGHT_GREY 7
#define COLOR8_DARK_GREY 8
#define COLOR8_LIGHT_BLUE 9
#define COLOR8_LIGHT_GREEN 10
#define COLOR8_LIGHT_CYAN 11
#define COLOR8_LIGHT_RED 12
#define COLOR8_LIGHT_MAGENTA 13
#define COLOR8_LIGHT_BROWN 14
#define COLOR8_WHITE 15

#define width 80
#define height 25

void print(const char* s);
void print_char(char c);  // Declaration of print_char function 
void scrollUp();
void newLine();
void Reset(); 
void print_hex(uint32_t n);
void print_char(char c);
// simple printf function that only supports %s and %x format specifiers
void simple_printf(const char *format, ...);