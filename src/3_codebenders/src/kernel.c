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
#include "memutils.h"
#include "stdlib.h"
#include "stddef.h"
#include "memutils.h"
#include "memory.h"
#include "pit.h"
#include "string.h"



extern uint32_t end;

void kmain(uint32_t magic, struct multiboot_info* bootInfo);

void kmain(uint32_t magic, struct multiboot_info* bootInfo) {

    print("Hello, World!\r\n");

    initIdt();  // Initialize the Interrupt Descriptor Table and remap the PIC
    print("IDT is done!\r\n");

    InitializeCustomGDT();  // Initialize the Global Descriptor Table
    print("GDT is done!\r\n");

    irq_install_handler(1, &keyboardHandler);
    print("Keyboard handler is done!\r\n");
    
    //init_scancode_to_ascii(); // Initialize the scancode to ASCII mapping
    //print("Scancode to ASCII mapping initialized.\r\n");


    // Initialize the kernel's memory manager using the end address of the kernel.
    init_kernel_memory(&end); // <------ THIS IS PART OF THE ASSIGNMENT

    // Initialize paging for memory management.
    init_paging(); // <------ THIS IS PART OF THE ASSIGNMENT
    //print("Paging is done!\r\n");

    // Print memory information.
    print_memory_layout(); // <------ THIS IS PART OF THE ASSIGNMENT
   // print("Memory layout is done!\r\n");

    // Initialize PIT
   // init_pit(); // <------ THIS IS PART OF THE ASSIGNMENT
   // print("PIT is done!\r\n");

    // Call the C++ main function of the kernel.
    return kernel_main();

    for(;;);

}