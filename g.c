#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "cd_command.h"
#include "copy.h"

int main() {
    char input[256];
    printf("Custom Shell\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

        // Parse the command and arguments
        char* token = strtok(input, " ");
        char* arg1 = strtok(NULL, " ");
        char* arg2 = strtok(NULL, " ");

        if (token == NULL) {
            printf("Please enter a command.\n");
            continue;
        }

        if (strcmp(token, "exit") == 0) {
            break; // Exit the loop and terminate the program
        }
        else if (strncmp(token, "cd", 2) == 0) {
            const char* path = (arg1 != NULL) ? arg1 : ""; // Handle no argument case
            execute_cd(path); // Change directory
        }
        else if (strcmp(token, "copy") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: copy <source> <destination>\n");
                continue;
            }
            execute_cp(arg1, arg2); // Copy file
        }
        else {
            printf("'%s' is not recognized as a valid command.\n", token);
        }
    }

    return 0;
}
