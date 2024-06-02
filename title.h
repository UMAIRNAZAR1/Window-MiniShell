#ifndef TITLE_COMMAND_H
#define TITLE_COMMAND_H

#include <stdio.h>

#include "title.h"
#include <stdlib.h>

void execute_title_command(const char* title) {
    char command[100];
    sprintf(command, "title %s", title);
    system(command);
}


#endif
