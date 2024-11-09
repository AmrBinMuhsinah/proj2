#include <stdio.h>
#include "alu.h"

void ALU(int RA, int RB, int op, int *Result, int *Carry) {
    if (op == 0) { // Addition
        int sum = RA + RB;
        *Result = sum & 0xF;  // Limit to 4 bits
        *Carry = (sum > 15) ? 1 : 0; // Set carry if overflow
    } else if (op == 1) { // Subtraction
        int diff = RA - RB;
        *Result = diff & 0xF; // Limit to 4 bits
        *Carry = (diff < 0) ? 1 : 0; // Set carry if underflow
    } else {
        printf("Invalid operation code.\n");
    }
}

