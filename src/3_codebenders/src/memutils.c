#include "memory.h" // Include the header file that defines the functions

#include "stdint.h" // Include the standard integer types
#include "stddef.h" // Include the standard size types
#include "memutils.h" // Include the header file that defines the functions

// Function to copy memory from source to destination
void *kmemcpy(void *dest, const void *src, size_t count)
{
    char *dst8 = (char *)dest;
    const char *src8 = (const char *)src;

    while (count--)
    {
        *dst8++ = *src8++;
    }

    return dest;
}

// Function to set a block of memory with a 16-bit value
void *memset16(void *ptr, uint16_t value, size_t num)
{
    uint16_t *p = (uint16_t *)ptr;
    while (num--)
    {
        *p++ = value;
    }
    return ptr;
}

// Function to set a block of memory with a byte value
void *kmemset(void *ptr, int value, size_t num)
{
    unsigned char *p = (unsigned char *)ptr;
    while (num--)
    {
        *p++ = (unsigned char)value;
    }
    return ptr;
}
