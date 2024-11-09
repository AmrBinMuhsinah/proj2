#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm2bin.h"

void printBinary(int num, FILE *output) {
    for (int i = 2; i >= 0; i--) {
        fprintf(output, "%d", (num >> i) & 1);  
    }
}

void asm2bin(char *line, FILE *output) {
    char s[50];
    strcpy(s, line);

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';

    if (strcmp(s, "RA=RA+RB") == 0) {
        fprintf(output, "00000000\n");
    } else if (strcmp(s, "RB=RA+RB") == 0) {
        fprintf(output, "00010000\n");
    } else if (strcmp(s, "RA=RA-RB") == 0) {
        fprintf(output, "00000100\n");
    } else if (strcmp(s, "RB=RA-RB") == 0) {
        fprintf(output, "00010100\n");
    } else if (strcmp(s, "RO=RA") == 0) {
        fprintf(output, "00100000\n");
    } else if (strncmp(s, "RA=", 3) == 0 || strncmp(s, "RB=", 3) == 0) {
        char reg = s[1];
        int imm = atoi(s + 3);

        if (imm >= 0 && imm <= 7) {
            if (reg == 'A') {  // for RA
                fprintf(output, "00001");
                printBinary(imm, output);  
                fprintf(output, "\n");
            } else if (reg == 'B') {  // for RB
                fprintf(output, "00011");
                printBinary(imm, output);  
                fprintf(output, "\n");
            }
        } else {
            printf("ERROR: Enter number from 0-7 here\n");
        }
    } else if (strncmp(s, "JC=", 3) == 0 || strncmp(s, "J=", 2) == 0) {
        int imm;
        if (s[0] == 'J' && s[1] == 'C') {
            imm = atoi(s + 3);
            if (imm >= 0 && imm <= 7) {
                fprintf(output, "01110");
                printBinary(imm, output);  
                fprintf(output, "\n");
            } else {
		    printf("%d",imm);
                printf("ERROR: Enter number from 0-7 h\n");
            }
        } else if (s[0] == 'J' && s[1] == '=') {
            imm = atoi(s + 2);
            if (imm >= 0 && imm <= 7) {
                fprintf(output, "10110");
                printBinary(imm, output);  
                fprintf(output, "\n");
            } else {
                printf("ERROR: Enter number from 0-7 a\n");
            }
        }
    }
}

