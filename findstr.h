#ifndef FINDSTR_H
#define FINDSTR_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void execute_findstr_command(const char* filename, const char* searchStr) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    char line[256];
    bool found = false;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, searchStr) != NULL) {
            printf("%s", line);
            found = true;
        }
    }

    if (!found) {
        printf("String '%s' not found in file '%s'\n", searchStr, filename);
    }

    fclose(file);
}

#endif
