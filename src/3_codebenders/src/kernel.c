#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "keyboard.h"
#include "interrupts.h"
#include "io.h"
#include "stdio.h"

// ISR handlers
void isr20_handler(void) {
    print("Interrupt 0x20 triggered\n");
}
void isr21_handler(void) {
    print("Interrupt 0x21 triggered\n");
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

// Kernel main function
void kmain(void) {
    Reset(); 
    print("VGA Reset complete.\r\n");

    

     print("Entering kmain...\r\n");
     initializeGDT(); // Initialize Global Descriptor Table
     print("GDT is initialized.\r\n");
    
     initIdt();       // Initialize the IDT with defaults
     setup_idt();     // Set up specific interrupt gates
     print("IDT setup complete.\r\n");
    
     // trigger_interrupts(); // Trigger interrupts
    
     initKeyboard();

while (1) { /* Loop indefinitely to prevent the kernel from doing anything else */ 
}

}
//void kmain(void) {
//    uint16_t *vga = (uint16_t*) 0xB8000;
//    *vga = 0x2F41; // 'A' with bright green background and white foreground
//    while (1) {}
//}