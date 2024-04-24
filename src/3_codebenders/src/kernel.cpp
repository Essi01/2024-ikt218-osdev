extern "C"
{
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h" // For malloc and free
#include "memory.h" // Assuming it's part of your custom kernel headers
#include "stddef.h" // For size_t
#include "string.h"
#include "pit.h"

#include "vga.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "multiboot2.h"
#include "util.h"
#include "memutils.h"
#include "interrupts.h"
}


// Existing global operator delete overloads
void operator delete(void *ptr) noexcept
{
    free(ptr);
}

void operator delete[](void *ptr) noexcept
{
    free(ptr);
}

void *operator new[](size_t size)
{
    return malloc(size);
}

// Add sized-deallocation functions
void operator delete(void *ptr, size_t size) noexcept
{
    (void)size; // Size parameter is unused, added to match required signature
    free(ptr);
}

void operator delete[](void *ptr, size_t size) noexcept
{
    (void)size; // Size parameter is unused, added to match required signature
    free(ptr);
}

void kernel_print(const char *str);



extern "C" int kernel_main(void);
int kernel_main()
{

    int counter = 0;

    // Allocate some memory using the kernel memory manager
    // THIS IS PART OF THE ASSIGNMENT
    void *some_memory = malloc(12345);
    void *memory2 = malloc(54321);
    void *memory3 = malloc(13331);
    char *memory4 = new char[1000]();

  //  init_pit();
    asm volatile("sti"); // Enable interrupts globally

    
        while (true)
        {
            printf("[%d]: Sleeping with busy-waiting (HIGH CPU).\n", counter);
            sleep_busy(1000);
            printf("[%d]: Slept using busy-waiting.\n", counter++);

            printf("[%d]: Sleeping with interrupts (LOW CPU).\n", counter);
            sleep_interrupt(1000);
            printf("[%d]: Slept using interrupts.\n", counter++);
        };
    
    return 0;
}
