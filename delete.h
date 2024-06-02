#ifndef DELETE_H
#define DELETE_H

#include <stdio.h>
#include <stdlib.h>

void execute_del(const char* filename) {
    char confirm;
    printf("Are you sure you want to delete file '%s'? (y/n): ", filename);
    scanf_s(" %c", &confirm, 1);

    if (confirm == 'y' || confirm == 'Y') {
        char command[256];
        sprintf_s(command, sizeof(command), "del \"%s\"", filename);
        int status = system(command);
        if (status == 0) {
            printf("File '%s' deleted successfully.\n", filename);
        }
        else {
            printf("Failed to delete file '%s'.\n", filename);
        }
    }
    else {
        printf("Deletion cancelled.\n");
    }
}

#endif
