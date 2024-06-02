#ifndef SHUTDOWN_COMMAND_H
#define SHUTDOWN_COMMAND_H

#include <windows.h>
#include <stdio.h>

void execute_shutdown_command(const char* option) {
    if (option != NULL) {
        if (strcmp(option, "-s") == 0) {
           
            if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER | SHTDN_REASON_MINOR_OTHER)) {
                printf("Failed to shutdown the computer.\n");
            }
        }
        else if (strcmp(option, "-r") == 0) {
           
            if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER | SHTDN_REASON_MINOR_OTHER)) {
                printf("Failed to restart the computer.\n");
            }
        }
        else {
            printf("Invalid option for shutdown command.\n");
        }
    }
    else {
        printf("Usage: shutdown [-s | -r]\n");
    }
}

#endif 
