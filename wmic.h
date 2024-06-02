#ifndef WMIC_H
#define WMIC_H

#include <stdio.h>
#include <stdlib.h>

void execute_wmic_disk_status() {
    char command[] = "wmic diskdrive get status";
    int status = system(command);
    if (status == 0) {
        printf("Retrieved disk drive status successfully.\n");
    }
    else {
        printf("Failed to retrieve disk drive status.\n");
    }
}

void execute_wmic_cpu_name() {
    char command[] = "wmic cpu get name";
    int status = system(command);
    if (status == 0) {
        printf("Retrieved CPU name successfully.\n");
    }
    else {
        printf("Failed to retrieve CPU name.\n");
    }
}

void execute_ver() {
    system("ver");
}

#endif
