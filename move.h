

#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_move_command(const char* source, const char* destination) {
    char command[256];
    snprintf(command, sizeof(command), "move \"%s\" \"%s\"", source, destination);
    int status = system(command);

    if (status == 0) {
        printf("Files moved successfully.\n");
    }
    else {
        printf("Failed to move files.\n");
    }
}

#endif
