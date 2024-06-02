#ifndef TYPE_COMMAND_H
#define TYPE_COMMAND_H

#include <stdio.h>

void execute_type_command(const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) {
        printf("Error opening file %s\n", filename);
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

#endif
