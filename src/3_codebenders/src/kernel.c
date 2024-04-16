#include "vga.h"
#include "stdint.h"
#include "gdt.h"
#include "idt.h"
#include "keyboard.h"
#include "interrupts.h"
#include "io.h"
#include "stdio.h"
#include "timer.h"
#include "multiboot2.h"
#include "memory.h" 

// Buffer to store scancodes
#define BUFFER_SIZE 256
unsigned char buffer[BUFFER_SIZE];
int buffer_index = 0;

unsigned char scancode_to_ascii[256];

void init_scancode_to_ascii() {
    scancode_to_ascii[0x1E] = 'a';
    scancode_to_ascii[0x1F] = 's';
    // Add the rest of the scancodes here...
}
// ISR handlers
//void isr20_handler(void) {
//    print("Interrupt 0x20 triggered\n");
//}
void isr21_handler(void) {
    unsigned char scancode = inb(0x60);  // Read the scancode from the keyboard

    // Store the scancode in the buffer
    if (buffer_index < BUFFER_SIZE) {
        buffer[buffer_index++] = scancode;
    } else {
        // Handle buffer overflow
        // For example, you can clear the buffer or increase its size
    }

    // Translate the scancode to ASCII using the lookup table
    unsigned char ascii = scancode_to_ascii[scancode];

    // Print the ASCII character to the screen
    char str[2] = {ascii, '\0'};
    print(str);

    // Send EOI to the PIC
    outb(0x20, 0x20);  // Command to send EOI to the PIC
}



void isr22_handler(void) {
    print("Interrupt 0x22 triggered\n");
}

// Setup IDT
void setup_idt() {
    
    // Set all possible interrupts to the default handler first
    for (int i = 0; i < 256; i++) {
        setIdtGate(i, (unsigned long)default_handler, 0x08, 0x8E);
    }

    // setIdtGate(0x20, (unsigned long)isr20_handler, 0x08, 0x8E);
    // setIdtGate(0x21, (unsigned long)isr21_handler, 0x08, 0x8E);
    setIdtGate(0x21, (uint32_t)isr21_handler, 0x08, 0x8E);
    setIdtGate(0x22, (unsigned long)isr22_handler, 0x08, 0x8E);
}

// Trigger interrupts
void trigger_interrupts() {
    asm volatile("int $0x20");  // Trigger interrupt 0x20
    asm volatile("int $0x21");  // Trigger interrupt 0x21
    asm volatile("int $0x22");  // Trigger interrupt 0x22

    
}





void kmain(uint32_t magic, struct multiboot_info* bootInfo);

void kmain(uint32_t magic, struct multiboot_info* bootInfo){
    initializeGDT();
    print("GDT is done!\r\n");
    initIdt();

    init_scancode_to_ascii();

    initTimer();
    initKeyboard();
    print("IDT, Timer and Keyboard initialized!\r\n");

    uint32_t mod1 = *(uint32_t*)(bootInfo->mods_addr + 4);
    uint32_t physicalAllocStart = (mod1 + 0xFFF) & ~0xFFF;

    initMemory(bootInfo->mem_upper * 1024, physicalAllocStart);
    print("Memory allocation done!");

    //asm volatile ("sti");

    for(;;);
}