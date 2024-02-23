#include "stdint.h"

// Defiend struct for GDT entrreis
struct GDTEntry {
    uint16_t limit_low;          
    uint16_t base_low;           
    uint8_t base_middle;         
    uint8_t access;              
    uint8_t granularity;         
    uint8_t base_high;           
} __attribute__((packed)); 


// Defien struct, GDT pointer
struct GDTPointer {
    uint16_t limit;      
    uint32_t base;       
} __attribute__((packed));


// Types for fucntions 
void initializeGDT(void); 
void setGDTEntry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity); 
extern void GDTFlush(uint32_t GDTPointer)