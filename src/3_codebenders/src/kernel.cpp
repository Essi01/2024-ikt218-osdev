// Kernal.cpp file
// Displays "Hello World!" at the top-left of the screen.
extern "C" void kernel_main() {
    const char* startMessage = "Hello World!";
    volatile char* VideoMemory = (volatile char*)0xb8000; 
    unsigned int i = 0, j = 0;

    // cleaning screen
    while (i < 80 * 25 * 2) {
        VideoMemory[i] = ' '; 
        VideoMemory[i + 1] = 0x19; 
        i += 2;
    }

    i = 0;

    // Write the start massage
    while (startMessage[j] != '\0') {
        VideoMemory[i] = startMessage[j];
        VideoMemory[i + 1] = 0x0C; // Color of text
        j++;
        i += 2;
    }
}