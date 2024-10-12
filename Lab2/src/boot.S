#include "mm.h"

.section ".text.boot"

.globl _start
_start:
    mrs    x0, mpidr_el1        
    and    x0, x0, #0xFF        // Check processor ID
    cbz    x0, master           // Hang for all non-primary CPUs
    b      proc_hang

proc_hang: 
    b      proc_hang

master:
    // EL3 to EL2 transition
    ldr    x0, =SCTLR_VALUE_MMU_DISABLED
    msr    sctlr_el1, x0        

    ldr    x0, =SCR_VALUE_EL2    // Configure Secure Configuration Register for EL2
    msr    scr_el3, x0

    ldr    x0, =SPSR_VALUE_EL2   // Configure SPSR for EL2 transition
    msr    spsr_el3, x0

    adr    x0, el2_entry         // Set the target address for EL2
    msr    elr_el3, x0

    eret                        // Return from exception, switch to EL2

el2_entry:
    // Configure HCR_EL2 for EL2 to EL1 transition
    ldr    x0, =HCR_VALUE
    msr    hcr_el2, x0

    // Configure SPSR_EL2 for switching to EL1
    ldr    x0, =SPSR_VALUE_EL1   
    msr    spsr_el2, x0

    // Set the address for EL1 entry
    adr    x0, el1_entry
    msr    elr_el2, x0

    eret                        // Return from exception, switch to EL1

el1_entry:
    // Zero out the .bss section
    adr    x0, bss_begin
    adr    x1, bss_end
    sub    x1, x1, x0
    bl     memzero

    // Set up the stack pointer
    mov    sp, #LOW_MEMORY
    // Jump to the kernel main function
    bl     kernel_main
    // Hang here if returning from kernel_main
    b      proc_hang
