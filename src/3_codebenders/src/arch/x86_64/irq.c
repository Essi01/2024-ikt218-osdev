// irq.c

#include "irq.h"
#include "idt.h" // Assuming you have an IDT setup file
#include "keyboard.h"


// Handler prototypes might be implemented in assembly
// and then call these C functions
void irq_handler_0() {
    // Handle timer interrupt
}

void irq_handler_1() {
    // Handle keyboard interrupt
}

void initialize_irq_handlers() {
    // Assuming you have a function set_idt_entry to register handlers
    set_idt_entry(32, (unsigned long)irq0); // Remapped IRQ0
    set_idt_entry(33, (unsigned long)irq1); // Remapped IRQ1
    // Continue for other IRQs...
}

void initialize_irq_handlers() {
    // Register other IRQ handlers
    initialize_keyboard(); // This registers the keyboard handler for IRQ1
}