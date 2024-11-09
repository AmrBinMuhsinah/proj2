#include <stdio.h>
#include <unistd.h>
#include "instruction.h"
#include "loader.h"
#include "alu.h"

void printInstruction(char *buffer[], int pc) {
    if (buffer[pc] != NULL) {
        printf("Instruction %d: %s\n", pc + 1, buffer[pc]);
    } else {
        printf("No instruction at PC=%d\n", pc);
    }
}

int main() {
    char *buffer[9] = {NULL};
    int count = 0;

    int RA = 0, RB = 0, RO = 0, carry = 0;
    int pc = 0;

    load(buffer, &count);

    while (pc < count) {
        printInstruction(buffer, pc);

        char *instruction = fetch(buffer, pc);
        if (instruction == NULL) {
            printf("Invalid fetch at PC=%d\n", pc);
            break;
        }

        Instruction inst;
        strncpy(inst.binary, instruction, 8);
        inst.binary[8] = '\0';

        decodeInstruction(&inst);
        executeInstruction(&inst, &RA, &RB, &RO, &pc, &carry);

        pc++; // Increment PC after instruction execution
        sleep(1); // Simulate execution delay
    }

    for (int j = 0; j < count; j++) {
        free(buffer[j]);
    }

    return 0;
}

