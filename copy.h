#ifndef COPY_H
#define COPY_H

#include <stdio.h>
#include <errno.h>

void execute_cp(const char* source, const char* dest) {
    FILE* source_file = fopen(source, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE* dest_file = fopen(dest, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        return;
    }
    int ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    printf("File copied successfully.\n");
}

#endif
