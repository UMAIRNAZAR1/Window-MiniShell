#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <stdio.h>
#include <Windows.h>

void execute_cd(const char* path) {
    if (SetCurrentDirectoryA(path)) {
        printf("Changed directory to: %s\n", path);
    }
    else {
        printf("Failed to change directory to: %s\n", path);
    }
}

#endif
