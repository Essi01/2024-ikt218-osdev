// idt.h

#include "stdint.h"

#define IDT_ENTRIES 256

// Structure for an IDT entry
struct IDTEntry {
    uint16_t base_lo;    // The lower 16 bits of the address to jump to when this interrupt fires
    uint16_t sel;        // Kernel segment selector
    uint8_t always0;     // This must always be zero
    uint8_t flags;       // More flags
    uint16_t base_hi;    // The upper 16 bits of the address to jump to
} __attribute__((packed));

// Structure for the pointer to the IDT
struct IDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Function declarations
void initializeIDT(void);
