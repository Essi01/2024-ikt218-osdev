// interrupts.h
#ifndef INTERRUPTS_H
#define INTERRUPTS_H



void isr21_handler(void);  // Declaration for the keyboard ISR handler
void irq_install_handler(int irq, void (*handler)(struct InterruptRegisters *));



#endif // INTERRUPTS_H
