#ifndef TALENT_DISPLAY_H
#define TALENT_DISPLAY_H

#include <stdio.h>
#include <windows.h>

void execute_talent_display() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    printf("Processor Architecture: %d\n", sysInfo.wProcessorArchitecture);
    printf("Number of Processors: %d\n", sysInfo.dwNumberOfProcessors);
    printf("Page Size: %d bytes\n", sysInfo.dwPageSize);
    printf("Minimum Application Address: %p\n", sysInfo.lpMinimumApplicationAddress);
    printf("Maximum Application Address: %p\n", sysInfo.lpMaximumApplicationAddress);
    printf("Active Processor Mask: %lu\n", sysInfo.dwActiveProcessorMask);
    printf("Complete\n");
    system("systeminfo");
}

#endif 
