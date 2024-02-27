// idt.c

#include "idt.h"

// Declare an array of IDT entries; initialized to zero
struct IDTEntry idt[IDT_ENTRIES];
struct IDTPointer idtp;

// Function to set an IDT entry
void idtSetEntry(int n, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[n].base_lo = base & 0xFFFF;
    idt[n].base_hi = (base >> 16) & 0xFFFF;
    idt[n].sel = sel;
    idt[n].always0 = 0;
    idt[n].flags = flags;
}

// Assembly function to load the new IDT
extern void idt_load();

void initializeIDT() {
    idtp.limit = (sizeof(struct IDTEntry) * IDT_ENTRIES) - 1;
    idtp.base = (uint32_t)&idt;

    // Populate the IDT here with idtSetEntry...
    // e.g., idtSetEntry(0, (uint32_t)isr0, 0x08, 0x8E);

    // Load the IDT
    idt_load();
}
