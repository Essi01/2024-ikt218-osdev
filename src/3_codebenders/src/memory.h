#ifndef MEMORY_H
#define MEMORY_H

#include "stdint.h"
#include "stddef.h"

// Declare the global variables but do not define them here
extern uint32_t physicalMemoryBitmap[];
extern uint32_t initial_page_dir[1024];

// Function prototypes
void initMemory(uint32_t memHigh, uint32_t physicalAllocStart);
void pmm_init(uint32_t memLow, uint32_t memHigh);
void invalidate(uint32_t vaddr);

#define KERNEL_START 0xC0000000
#define PAGE_FLAG_PRESENT (1 << 0)
#define PAGE_FLAG_WRITE (1 << 1)

typedef struct
{
    uint32_t status; // 0 for free, 1 for used
    uint32_t size;   // Size of the allocation
} alloc_t;

#endif /* MEMORY_H */
