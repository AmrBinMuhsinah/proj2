#include <stdio.h>
#include "instruction.h"

void decodeInstruction(Instruction *inst) {
    inst->J = inst->binary[0] - '0';
    inst->C = inst->binary[1] - '0';
    inst->D1 = inst->binary[2] - '0';
    inst->D0 = inst->binary[3] - '0';
    inst->Sreg = inst->binary[4] - '0';
    inst->S = inst->binary[5] - '0';
    inst->imm = inst->binary[6] - '0';
    inst->imm1 = inst->binary[7] - '0';
}

void executeInstruction(Instruction *inst, int *RA, int *RB, int *RO, int *pc, int *carry) {
    int immediate = (inst->imm << 1) | inst->imm1;

    if (inst->J == 1) {
        *pc = immediate; // Unconditional jump
    } else if (inst->C == 1 && *carry == 1) {
        *pc = immediate; // Conditional jump on carry
    } else {
        if (inst->D1 == 0 && inst->D0 == 0) {
            if (inst->Sreg == 1) *RA = immediate; // RA = imm
        } else if (inst->D1 == 0 && inst->D0 == 1) {
            if (inst->Sreg == 1) *RB = immediate; // RB = imm
            else ALU(*RA, *RB, inst->S, RB, carry); // RB = RA (+/-) RB
        } else if (inst->D1 == 1 && inst->D0 == 0) {
            *RO = *RA; // RO = RA
            printf("RO = %d\n", *RO);
        } else if (inst->D1 == 1 && inst->D0 == 1) {
            printf("No operation\n");
        }
    }
}

