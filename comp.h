#ifndef COMP_COMMAND_H
#define COMP_COMMAND_H
#include <stdio.h>
#include <string.h>
void execute_comp_command(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "rb");
    FILE* fp2 = fopen(file2, "rb");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Unable to open files.\n");
        return;
    }
    int byte1, byte2;
    int position = 0;
    int differ = 0;
    do {
        byte1 = fgetc(fp1);
        byte2 = fgetc(fp2);
        if (byte1 != byte2) {
            printf("Files differ at position %d.\n", position);
            differ = 1;
            break;
        }
        position++;
    } while (byte1 != EOF && byte2 != EOF);

    if (!differ && byte1 == byte2) {
        printf("Files are identical.\n");
    }
    else if (!differ) {
        printf("Files have different lengths.\n");
    }

    fclose(fp1);
    fclose(fp2);
}

#endif
