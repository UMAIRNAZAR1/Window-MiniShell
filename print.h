#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stdlib.h>

void execute_print(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

#endif 
