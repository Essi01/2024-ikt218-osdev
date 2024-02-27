; Assembly file (idt_load.asm)

global idt_load
section .text
idt_load:
    lidt [esp+4] ; Load the IDT pointer structure
    ret
