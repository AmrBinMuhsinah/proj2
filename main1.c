#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "instruction.h"
#include "loader.h"

int main() {
    char *buffer[9] = {NULL};
    int count = 0;

    load(buffer, &count);

    int pc = 0;

    while (pc < count) {
        print_instruction(buffer, pc);
        decoder(buffer, pc);
        pc++;
        sleep(1);
    }

    for (int j = 0; j < count; j++) {
        free(buffer[j]);
    }

    return 0;
}

