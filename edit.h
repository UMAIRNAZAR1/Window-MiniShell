#ifndef EDIT_COMMAND_H
#define EDIT_COMMAND_H
#include <stdio.h>
#include <stdlib.h>
void edit_command(const char* filename) {
    FILE* file;
    char command[256];
    errno_t err;
    err = fopen_s(&file, filename, "r");
    if (err == 0) {
        fclose(file);
    }
    else {
        err = fopen_s(&file, filename, "w");
        if (err != 0) {
            printf("Error creating file %s\n", filename);
            return;
        }
        fclose(file);
    }
    sprintf_s(command, sizeof(command), "notepad.exe %s", filename);
    system(command);
}

#endif 
