// gdt.h file
#include "libc/stdint.h"

// Defiend struct for GDT entrreis
struct GDTEntry {
    uint16_t LimitLow;          
    uint16_t BaseLow;           
    uint8_t BaseMiddle;         
    uint8_t Access;              
    uint8_t Granularity;         
    uint8_t BaseHigh;           
} __attribute__((packed)); 


// Defien struct, GDT pointer
struct GDTPointer {
    uint16_t Limit;      
    uint32_t Base;       
} __attribute__((packed));


// Types for fucntions 
void initializeGDT(void); 
void setGDTEntry(int Index, uint32_t Base, uint32_t Limit, uint8_t Access, uint8_t Granularity); 
extern void GDTFlush(uint32_t GDTPointer);