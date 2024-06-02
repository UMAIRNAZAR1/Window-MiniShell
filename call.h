#ifndef CALL_COMMAND_H
#define CALL_COMMAND_H

#include <stdio.h>
#include <stdlib.h>

void call_command(const char* batchFile, const char* label) {
    if (batchFile == NULL || label == NULL) {
        printf("Error: Invalid batch file or label\n");
        return;
    }

    char command[256];
    snprintf(command, sizeof(command), "call \"%s\" :%s", batchFile, label);

    printf("Executing command: %s\n", command);
    int result = system(command);
    if (result == 0) {
        printf("Command executed successfully: %s\n", command);
    }
    else {
        printf("Failed to execute command: %s\n", command);
        printf("Exit code: %d\n", result);
    }
}

#endif
