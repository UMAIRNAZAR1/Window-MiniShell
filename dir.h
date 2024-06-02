#ifndef DIR_H
#define DIR_H

#include <stdio.h>
#include <stdlib.h>

void execute_dir(const char* dirname) {
    if (dirname == NULL || dirname[0] == '\0') {
        printf("Error: Invalid directory name.\n");
        return;
    }

    char command[512];
    snprintf(command, sizeof(command), "dir \"%s\"", dirname);

    int status = system(command);
    if (status == -1) {
        printf("Error: Failed to execute system command.\n");
    }
    else if (status != 0) {
        printf("Error: Failed to list directory '%s'.\n", dirname);
    }
}

#endif
