#ifndef MORE_COMMAND_H
#define MORE_COMMAND_H
#include "more.h"
#include <stdio.h>
#define size 20 

void execute_more(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    int line_count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
        if (ch == '\n') {
            line_count++;
            if (line_count >= size) {
                printf("-- More --");
                getchar();
                line_count = 0;
                printf("\r               \r");
            }
        }
    }  fclose(file);
}

#endif
