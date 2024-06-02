#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <windows.h>

void execute_tasklist() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    printf("Talent display information:\n");
    printf("===================================\n");
    printf("  OEM ID: %u\n", sysInfo.dwOemId);
    printf("  Number of processors: %u\n", sysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", sysInfo.dwPageSize);
    printf("  Processor type: %u\n", sysInfo.dwProcessorType);
    printf("  Minimum application address: %p\n", sysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %p\n", sysInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n", sysInfo.dwActiveProcessorMask);
   /* int status = system("tasklist");
    if (status == 0) {
        printf("Tasklist command executed successfully.\n");
    }
    else {
        printf("Error executing tasklist command.\n");
    }*/
}

#endif
