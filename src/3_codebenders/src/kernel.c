#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "stdio.h"
#include "keyboard.h"
#include "multiboot2.h"
#include "util.h"
#include "memory.h"

void kmain(uint32_t magic, struct multiboot_info* bootInfo);

void kmain(uint32_t magic, struct multiboot_info* bootInfo) {

    
    initIdt();  // Initialize the Interrupt Descriptor Table and remap the PIC
    print("IDT is done!\r\n");

    InitializeCustomGDT();  // Initialize the Global Descriptor Table
    print("GDT is done!\r\n");

    
    initTimer();  // Initialize the system timer
    print("Timer is done!\r\n");
    
    //init_scancode_to_ascii(); // Initialize the scancode to ASCII mapping
    //print("Scancode to ASCII mapping initialized.\r\n");

    initKeyboard();  // Initialize keyboard handling
    print("Keyboard is done!\r\n");

    // Initialize memory allocation
    
    
    // Assuming memory initialization needs the module start address aligned
    uint32_t mod1 = *(uint32_t*)(bootInfo->mods_addr + 4);
    uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~0xFFF;
    
    initMemory(bootInfo->mem_upper * 1024, physicalAllocStart);
    print("Memory allocation done!\r\n");

    for(;;);

}