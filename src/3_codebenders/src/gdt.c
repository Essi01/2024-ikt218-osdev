// gdt.c file
#include "gdt.h"

#define GDT_SIZE 5

struct GDTEntry gdt[GDT_SIZE];

struct GDTPointer gp;

void initializeGDT() {
    
    gp.Limit = (sizeof(struct GDTEntry) * GDT_SIZE) - 1;
    gp.Base = (uint32_t)&gdt;

  
    setGDTEntry(0, 0, 0, 0, 0);
  
    setGDTEntry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
  
    setGDTEntry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
   
    setGDTEntry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
   
    setGDTEntry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

    GDTFlush((uint32_t)&gp);
}

void setGDTEntry(int Index, uint32_t Base, uint32_t Limit, uint8_t Access, uint8_t Granularity) {
    gdt[Index].BaseLow = (Base & 0xFFFF);
    gdt[Index].BaseMiddle = (Base >> 16) & 0xFF;
    gdt[Index].BaseHigh = (Base >> 24) & 0xFF;
    gdt[Index].LimitLow = (Limit & 0xFFFF);
    gdt[Index].Granularity = ((Limit >> 16) & 0x0F);
    gdt[Index].Granularity |= (Granularity & 0xF0);
    gdt[Index].Access = Access;
}

extern void GDTFlush(uint32_t GDTPointer){

    asm volatile("lgdt (%0)" : : "r" (GDTPointer));
    asm volatile("mov $0x10, %ax");
    asm volatile("mov %ax, %ds");
    asm volatile("mov %ax, %es");
    asm volatile("mov %ax, %fs");
    asm volatile("mov %ax, %gs");
    asm volatile("mov %ax, %ss");
    asm volatile("ljmp $0x08, $next");
    asm volatile("next:");
}