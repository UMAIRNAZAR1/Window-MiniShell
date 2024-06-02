#ifndef AT_COMMAND_H
#define AT_COMMAND_H

#include <stdio.h>

void at_command(const char* time, const char* command) {
    FILE* task_file = fopen("scheduled_task.bat", "w");

    if (task_file != NULL) {
        fprintf(task_file, "@echo off\n");
        fprintf(task_file, "%s\n", command);
        fclose(task_file);

        printf("Success: Task scheduled successfully at %s\n", time);
    }
    else {
        printf("Error: Unable to create scheduled task\n");
    }
}

#endif
