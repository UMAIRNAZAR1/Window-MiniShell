#ifndef COLOR_COMMAND_H
#define COLOR_COMMAND_H

#include <stdio.h>
#include <windows.h>

void color_command(const char* attr) {
    int color_attr;
    sscanf(attr, "%x", &color_attr);
    if (color_attr >= 0 && color_attr <= 15) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color_attr);
    }
    else {
        printf("Invalid attribute: %s\n", attr);
    }
}

#endif
