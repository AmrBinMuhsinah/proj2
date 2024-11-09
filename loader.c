#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loader.h"

void load(char *buffer[], int *count) {
    FILE *file = fopen("output.bin", "r");
    if (file == NULL) {
        printf("Could not open output file!\n");
        exit(1);
    }

    char line[10];
    while (fgets(line, sizeof(line), file) && *count < 9) {
        line[strcspn(line, "\n")] = '\0';
        buffer[*count] = malloc(strlen(line) + 1);
        if (buffer[*count] != NULL) {
            strcpy(buffer[*count], line);
            (*count)++;
        }
    }

    fclose(file);
}

