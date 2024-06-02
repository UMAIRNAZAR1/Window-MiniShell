#ifndef LINES_WORDS_H
#define LINES_WORDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_wc(const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char buffer[256];
    int lines = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lines++;
    }

    fclose(file);
    printf("Number of lines in %s: %d\n", filename, lines);
}

#endif
