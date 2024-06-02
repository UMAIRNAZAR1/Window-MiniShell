

#ifndef MSG_COMMAND_H
#define MSG_COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void send_message(const char* username, const char* message) {
    char command[256];
    snprintf(command, sizeof(command), "msg %s %s", username, message);
    system(command);
}

#endif

