.global add
.global subtract
.global multiply
.global divide
.global modulus

add:
    ADD r0, r0, r1
    BX lr

subtract:
    SUB r0, r0, r1
    BX lr

multiply:
    MUL r0, r0, r1
    BX lr

divide:
    CMP r1, #0       // Check if divisor is 0
    BEQ division_by_zero // Handle division by zero
    MOV r2, #0       // Clear the remainder register
    MOV r3, r0       // Move dividend to r3
divide_loop:
    CMP r3, r1       // Compare dividend with divisor
    BLT end_divide    // If dividend < divisor, end the loop
    SUB r3, r3, r1   // Subtract divisor from dividend
    ADD r2, r2, #1   // Increment quotient
    B divide_loop     // Repeat the loop
end_divide:
    MOV r0, r2       // Move quotient to r0
    BX lr

division_by_zero:
    MOV r0, #0       // Return 0 for division by zero (or handle as needed)
    BX lr

modulus:
    MOV r3, r0       // Move dividend to r3
    CMP r1, #0       // Check if divisor is 0
    BEQ return_zero   // Handle division by zero
modulus_loop:
    CMP r3, r1       // Compare dividend with divisor
    BLT return_remainder // If dividend < divisor, return remainder
    SUB r3, r3, r1   // Subtract divisor from dividend
    B modulus_loop    // Repeat the loop
return_remainder:
    MOV r0, r3       // Move remainder to r0
    BX lr
return_zero:
    MOV r0, #0       // Return 0 for modulus when divisor is 0
    BX lr

