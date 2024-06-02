// cmd_command.h

#ifndef CMD_COMMAND_H
#define CMD_COMMAND_H

#include <stdio.h>
#include <stdlib.h>

void execute_cmd_command() {
    printf("Launching command prompt...\n");
    system("cmd");
}

#endif
